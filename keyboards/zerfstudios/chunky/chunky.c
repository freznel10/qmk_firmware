/*
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Publicw License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "chunky.h"
#include "split_common/transactions.h"
#include "string.h"
#include "split_common/split_util.h"
#include "freznel.h"
#include <hal.h>
#include "ui/ui.h"
#include "color.h"
#include "adps9660.h"
#include "spi_master.h"
#include "i2c_master.h"

#include <qp.h>
#include <qp_lvgl.h>

#ifdef QUANTUM_PAINTER_ENABLE
painter_device_t qp_display;
__attribute__((weak)) void draw_ui_user(void) {}
#endif //QUANTUM_PAINTER_ENABLE

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif  // CONSOLE_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#    ifndef CHUNKY_MINIMUM_DEFAULT_DPI
#        define CHUNKY_MINIMUM_DEFAULT_DPI 400
#    endif  // CHUNKY_MINIMUM_DEFAULT_DPI

#    ifndef CHUNKY_DEFAULT_DPI_CONFIG_STEP
#        define CHUNKY_DEFAULT_DPI_CONFIG_STEP 200
#    endif  // CHUNKY_DEFAULT_DPI_CONFIG_STEP

#    ifndef CHUNKY_MINIMUM_SNIPING_DPI
#        define CHUNKY_MINIMUM_SNIPING_DPI 200
#    endif  // CHUNKY_MINIMUM_SNIPER_MODE_DPI

#    ifndef CHUNKY_SNIPING_DPI_CONFIG_STEP
#        define CHUNKY_SNIPING_DPI_CONFIG_STEP 100
#    endif  // CHUNKY_SNIPING_DPI_CONFIG_STEP

// Fixed DPI for drag-scroll.
#    ifndef CHUNKY_DRAGSCROLL_DPI
#        define CHUNKY_DRAGSCROLL_DPI 100
#    endif  // CHUNKY_DRAGSCROLL_DPI

#    ifndef CHUNKY_DRAGSCROLL_BUFFER_SIZE
#        define CHUNKY_DRAGSCROLL_BUFFER_SIZE 1
#    endif  // !CHUNKY_DRAGSCROLL_BUFFER_SIZE

#    ifndef CHUNKY_POINTER_ACCELERATION_FACTOR
#        define CHUNKY_POINTER_ACCELERATION_FACTOR 24
#    endif  // !CHUNKY_POINTER_ACCELERATION_FACTOR
#    endif

typedef union {
    uint16_t raw;
    struct {
        uint8_t     pointer_default_dpi     : 4;  // 16 steps available.
        uint8_t     pointer_sniping_dpi     : 2;  // 4 steps available.
        bool        is_dragscroll_enabled   : 1;
        bool        is_sniping_enabled      : 1;
    } __attribute__((packed));
} chunky_config_t;

static chunky_config_t g_chunky_config = {0};

extern user_runtime_config_t user_state;

/**
 * \brief Set the value of `config` from EEPROM.
 *
 * Note that `is_dragscroll_enabled` and `is_sniping_enabled` are purposefully
 * ignored since we do not want to persist this state to memory.  In practice,
 * this state is always written to maximize write-performances.  Therefore, we
 * explicitly set them to `false` in this function.
 */
static void read_chunky_config_from_eeprom(chunky_config_t* config) {
    config->raw                   = eeconfig_read_kb() & 0xff;
    config->is_dragscroll_enabled = false;
    config->is_sniping_enabled    = false;
}

/**
 * \brief Save the value of `config` to eeprom.
 *
 * Note that all values are written verbatim, including whether drag-scroll
 * and/or sniper mode are enabled.  `read_chunky_config_from_eeprom(…)`
 * resets these 2 values to `false` since it does not make sense to persist
 * these across reboots of the board.
 */
static void write_chunky_config_to_eeprom(chunky_config_t* config) { eeconfig_update_kb(config->raw); }

/** \brief Return the current value of the pointer's default DPI. */
static uint16_t get_pointer_default_dpi(chunky_config_t* config) { return (uint16_t)config->pointer_default_dpi * CHUNKY_DEFAULT_DPI_CONFIG_STEP + CHUNKY_MINIMUM_DEFAULT_DPI; }

/** \brief Return the current value of the pointer's sniper-mode DPI. */
static uint16_t get_pointer_sniping_dpi(chunky_config_t* config) { return (uint16_t)config->pointer_sniping_dpi * CHUNKY_SNIPING_DPI_CONFIG_STEP + CHUNKY_MINIMUM_SNIPING_DPI; }

/** \brief Set the appropriate DPI for the input config. */
static void maybe_update_pointing_device_cpi(chunky_config_t* config) {
    if (is_keyboard_master()) {
        if (user_state.split_pointing_mode == PM_DRAG) {
            pointing_device_set_cpi_on_side(true, CHUNKY_DRAGSCROLL_DPI);
            pointing_device_set_cpi_on_side(false, CHUNKY_DRAGSCROLL_DPI);
        } else if (user_state.split_pointing_mode == PM_PRECISION) {
            pointing_device_set_cpi_on_side(true, get_pointer_sniping_dpi(config));
            pointing_device_set_cpi_on_side(false, get_pointer_sniping_dpi(config));
            dprintf("testing");
        } else {
            pointing_device_set_cpi_on_side(true, get_pointer_default_dpi(config));
            pointing_device_set_cpi_on_side(false, get_pointer_default_dpi(config));
        }
    }
}


/**
 * \brief Update the pointer's default DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to CHUNKY_DEFAULT_DPI_CONFIG_STEP.
 */
static void step_pointer_default_dpi(chunky_config_t* config, bool forward) {
    config->pointer_default_dpi += forward ? 1 : -1;
    maybe_update_pointing_device_cpi(config);
}

/**
 * \brief Update the pointer's sniper-mode DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to CHUNKY_SNIPING_DPI_CONFIG_STEP.
 */
static void step_pointer_sniping_dpi(chunky_config_t* config, bool forward) {
    config->pointer_sniping_dpi += forward ? 1 : -1;
    maybe_update_pointing_device_cpi(config);
}

uint16_t chunky_get_pointer_default_dpi(void) { return get_pointer_default_dpi(&g_chunky_config); }

uint16_t chunky_get_pointer_sniping_dpi(void) { return get_pointer_sniping_dpi(&g_chunky_config); }

void chunky_cycle_pointer_default_dpi_noeeprom(bool forward) { step_pointer_default_dpi(&g_chunky_config, forward); }

void chunky_cycle_pointer_default_dpi(bool forward) {
    step_pointer_default_dpi(&g_chunky_config, forward);
    write_chunky_config_to_eeprom(&g_chunky_config);
}

void chunky_cycle_pointer_sniping_dpi_noeeprom(bool forward) { step_pointer_sniping_dpi(&g_chunky_config, forward); }

void chunky_cycle_pointer_sniping_dpi(bool forward) {
    step_pointer_sniping_dpi(&g_chunky_config, forward);
    write_chunky_config_to_eeprom(&g_chunky_config);
}

bool chunky_get_pointer_sniping_enabled(void) { return g_chunky_config.is_sniping_enabled; }

void chunky_set_pointer_sniping_enabled(bool enable) {
    g_chunky_config.is_sniping_enabled = enable;
    maybe_update_pointing_device_cpi(&g_chunky_config);
}

bool chunky_get_pointer_dragscroll_enabled(void) { return g_chunky_config.is_dragscroll_enabled; }

void chunky_set_pointer_dragscroll_enabled(bool enable) {
    g_chunky_config.is_dragscroll_enabled = enable;
    maybe_update_pointing_device_cpi(&g_chunky_config);
}

void pointing_device_init_kb(void) {
    set_auto_mouse_layer(
        _MOUSE);
    set_auto_mouse_enable(true);
    maybe_update_pointing_device_cpi(&g_chunky_config);
}

#    ifdef TAPPING_TERM_PER_KEY
#        define TAP_CHECK get_tapping_term(KC_BTN1, NULL)
#    else
#        ifndef TAPPING_TERM
#            define TAPPING_TERM 240
#        endif
#        define TAP_CHECK TAPPING_TERM
#    endif

#    if defined(POINTING_DEVICE_ENABLE) && !defined(NO_CHUNKY_KEYCODES)
/** \brief Whether SHIFT mod is enabled. */
static bool has_shift_mod(void) {
#        ifdef NO_ACTION_ONESHOT
    return mod_config(get_mods()) & MOD_MASK_SHIFT;
#        else
    return mod_config(get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
#        endif  // NO_ACTION_ONESHOT
}
#    endif  // POINTING_DEVICE_ENABLE && !NO_CHUNKY_KEYCODES


static int8_t rotations = 0;
bool lvgl_encoder = false;
static lv_group_t *g;
static uint32_t act_key = 0;

#ifdef AUDIO_ENABLE
float pm_song[][2] = SONG(VIOLIN_SOUND);
#endif

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case POINTER_DEFAULT_DPI_FORWARD:
            if (record->event.pressed) {
                // Step backward if shifted, forward otherwise.
                chunky_cycle_pointer_default_dpi(/* for/ward= */ !has_shift_mod());
            }
            break;
        case POINTER_DEFAULT_DPI_REVERSE:
            if (record->event.pressed) {
                // Step forward if shifted, backward otherwise.
                chunky_cycle_pointer_default_dpi(/* forward= */ has_shift_mod());
            }
            break;
        case POINTER_SNIPING_DPI_FORWARD:
            if (record->event.pressed) {
                // Step backward if shifted, forward otherwise.
                chunky_cycle_pointer_sniping_dpi(/* forward= */ !has_shift_mod());
            }
            break;
        case POINTER_SNIPING_DPI_REVERSE:
            if (record->event.pressed) {
                // Step forward if shifted, backward otherwise.
                chunky_cycle_pointer_sniping_dpi(/* forward= */ has_shift_mod());
            }
            break;
        case SNIPING_MODE:
            chunky_set_pointer_sniping_enabled(record->event.pressed);
            break;
        case SNIPING_MODE_TOGGLE:
            if (record->event.pressed) {
                chunky_set_pointer_sniping_enabled(!chunky_get_pointer_sniping_enabled());
            }
            break;
        case DRAGSCROLL_MODE:
            chunky_set_pointer_dragscroll_enabled(record->event.pressed);
            break;
        case DRAGSCROLL_MODE_TOGGLE:
            if (record->event.pressed) {
                chunky_set_pointer_dragscroll_enabled(!chunky_get_pointer_dragscroll_enabled());
            }
            break;
        case RGB_TOG1:
            if (record->event.pressed) {
                rgb_matrix_increase_flags();
            }
            return false;
        case PM_SWITCH:
            if (record->event.pressed) {
                // pointing_mode_switch_hands();
#ifdef AUDIO_ENABLE
                PLAY_SONG(pm_song);
#endif
            }
        break;
        case LVGL_CLOCKWISE:
            if (record->event.pressed) {
                rotations++;
                dprintf("Rotations: %d\n", rotations);
            }
            break;
        case LVGL_COUNTER_CLOCKWISE:
            if (record->event.pressed) {
                rotations--;
                dprintf("Rotations: %d\n", rotations);
            }
            break;
        case LVGL_ENCODER_BUTTON: {
            if (record->event.pressed) {
                lvgl_encoder = true;
            } else {
                lvgl_encoder = false;
            }
        }
        case LVGL_CONTROL_NEXT: {
            if (record->event.pressed) {
                act_key = 1;
            } else {
                act_key = 0;
            }
            break;
        }
        case LVGL_CONTROL_PREV: {
            if (record->event.pressed) {
                act_key = 2;
            } else {
                act_key = 0;
            }
            break;
        }
        case LVGL_CONTROL_LEFT: {
            if (record->event.pressed) {
                act_key = 3;
            } else {
                act_key = 0;
            }
            break;
        }
        case LVGL_CONTROL_RIGHT: {
            if (record->event.pressed) {
                act_key = 4;
            } else {
                act_key = 0;
            }
            break;
        }
        case LVGL_CONTROL_ENTER: {
            if (record->event.pressed) {
                act_key = 5;
            } else {
                act_key = 0;
            }
            break;
         }

        case SWITCH_1: {
        }
        break;
        case SWITCH_2: {
        }
        break;
        case SWITCH_3: {
        }
        break;
        case SWITCH_4: {
        }
        break;
        case SWITCH_5: {
        }
        break;
        case SWITCH_6: {
        }
        break;
    }
    return true;

}

void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}

void eeconfig_init_kb(void) {
    g_chunky_config.raw = 0;
    write_chunky_config_to_eeprom(&g_chunky_config);
    maybe_update_pointing_device_cpi(&g_chunky_config);
    eeconfig_init_user();
}

void matrix_init_kb(void) {
    read_chunky_config_from_eeprom(&g_chunky_config);
    matrix_init_user();
}

void gpio_init(uint gpio);

void keyboard_pre_init_kb(void) {
    // Ensures that GP26 through GP29 are initialized as digital inputs (as
    // opposed to analog inputs).  These GPIOs are shared with A0 through A3,
    // respectively.  On RP2040-B2 and later, the digital inputs are disabled by
    // default (see RP2040-E6).
    gpio_init(GP26);
    gpio_init(GP27);
    gpio_init(GP28);
    gpio_init(GP29);
    keyboard_pre_init_user();
}

// void matrix_power_up(void) { pointing_device_task(); }

void chunky_config_sync_handler(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(g_chunky_config)) {
        memcpy(&g_chunky_config, initiator2target_buffer, sizeof(g_chunky_config));
    }
}

// LVGL Encoder Control
lv_indev_t * indev_encoder;
lv_indev_t * indev_keypad;

void encoder_read_2(lv_indev_drv_t *drv, lv_indev_data_t *data) {
    data->enc_diff = rotations;
    rotations = 0;
    if (lvgl_encoder) {
        data->state = LV_INDEV_STATE_PRESSED;
        dprintf("pressed");
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}
// LVGL Encoder Control

/*Will be called by the library to read the mouse*/
void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data){
    static uint32_t last_key = 0;
    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PRESSED;
        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key) {
        case 1:
            act_key = LV_KEY_NEXT;
            break;
        case 2:
            act_key = LV_KEY_PREV;
            break;
        case 3:
            act_key = LV_KEY_LEFT;
            break;
        case 4:
            act_key = LV_KEY_RIGHT;
            break;
        case 5:
            act_key = LV_KEY_ENTER;
            break;
        }
        last_key = act_key;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
    data->key = last_key;
}

void keyboard_post_init_kb(void) {
    maybe_update_pointing_device_cpi(&g_chunky_config);
    transaction_register_rpc(RPC_ID_KB_CONFIG_SYNC, chunky_config_sync_handler);

   // Reset the initial shared data value between master and slave
    memset(&g_chunky_config, 0, sizeof(g_chunky_config));
    wait_ms(50);
        if (is_keyboard_left()) {
            qp_display = qp_gc9a01_make_spi_device(240, 240, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 8, 0);
            qp_init(qp_display, QP_ROTATION_270);
            qp_rect(qp_display, 0, 0, 240, 240, 0, 0, 0, true);
        } else {
            qp_display = qp_gc9a01_make_spi_device(240, 240, DISPLAY_CS_PIN_RIGHT, DISPLAY_DC_PIN_RIGHT, DISPLAY_RST_PIN_RIGHT, 8, 0);
            qp_init(qp_display, QP_ROTATION_90);
            qp_rect(qp_display, 0, 0, 240, 240, 0, 0, 0, true);
        }
    qp_lvgl_attach(qp_display);

    // Register Encoder and create default group
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = encoder_read_2;
    lv_indev_drv_register(&indev_drv);

    g = lv_group_create();
    lv_group_set_default(g);
    lv_indev_t *cur_drv = NULL;
    for (;;) {
        cur_drv = lv_indev_get_next(cur_drv);
        if (!cur_drv) {
            break;
        }
        if (cur_drv->driver->type == LV_INDEV_TYPE_KEYPAD) {
            lv_indev_set_group(cur_drv, g);
        }
        if (cur_drv->driver->type == LV_INDEV_TYPE_ENCODER) {
            lv_indev_set_group(cur_drv, g);
        }
    }
    keyboard_post_init_user();
    ui_init();

}

#define ALT_TAB_DELAY 1000

void housekeeping_task_kb(void) {
    unregister_super_tab();
    unregister_super_ctrl_tab();
    if (is_keyboard_master()) {
        // Keep track of the last state, so that we can tell if we need to propagate to slave
        // static chunky_config_t last_chunky_config = {0};
        // static uint32_t           last_sync             = 0;
        // bool                      needs_sync            = false;

        // // Check if the state values are different
        // if (memcmp(&g_chunky_config, &last_chunky_config, sizeof(g_chunky_config))) {
        //     needs_sync = true;
        //     memcpy(&last_chunky_config, &g_chunky_config, sizeof(g_chunky_config));
        // }
        // // Send to slave every 500ms regardless of state change
        // if (timer_elapsed32(last_sync) > 500 ) {
        //     needs_sync = true;
        // }

        // // Perform the sync if requested
        // if (needs_sync) {
        //     if (transaction_rpc_send(RPC_ID_KB_CONFIG_SYNC, sizeof(g_chunky_config), &g_chunky_config)) {
        //         last_sync = timer_read32();
        //     }
        // }
    }
    bool peripherals_on = last_matrix_activity_elapsed() < LCD_ACTIVITY_TIMEOUT;
    if (peripherals_on) {
#ifdef BACKLIGHT_ENABLE
        backlight_level_noeeprom(3);
#endif
        rgb_matrix_enable_noeeprom();
        lvgl_event_triggers();
    } else {
#ifdef BACKLIGHT_ENABLE
        backlight_level_noeeprom(0);
#endif
        rgb_matrix_disable_noeeprom();
    }
}

// __attribute__((weak)) void matrix_init_sub_kb(void) {}
// void                       matrix_init_kb(void) {
// #ifdef POINTING_DEVICE_ENABLE
//     read_chunky_config_from_eeprom(&g_chunky_config);
// #endif  // POINTING_DEVICE_ENABLE
//     matrix_init_sub_kb();
//     matrix_init_user();
// }

// __attribute__((weak)) void matrix_scan_sub_kb(void) {}
// void                       matrix_scan_kb(void) {
//     matrix_scan_sub_kb();
//     matrix_scan_user();
// }

// const cirque_init_config_t cirque_init_config_default = {
//     .position_mode  = CIRQUE_PINNACLE_ABSOLUTE_MODE,
//     .attenuation    = attenuate_2x,
//     .default_scale  = 1024,
//     .scroll_enable  = true,
//     .ranges         = &cirque_ranges_position_default,
//     .curved_overlay = true,
//     .taps           = CIRQUE_SINGLE_TAP,
//     .diameter_mm    = 40,
// };

/*  */

void matrix_io_delay(void) {
    __asm__ volatile("nop\nnop\nnop\n");
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    for (int32_t i = 0; i < 40; i++) {
        __asm__ volatile("nop" ::: "memory");
    }
}

void matrix_init_custom(void) {
    // SPI Matrix
    setPinOutput(SPI_MATRIX_CHIP_SELECT_PIN);
    writePinHigh(SPI_MATRIX_CHIP_SELECT_PIN);
    spi_init();

}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    static matrix_row_t temp_matrix[MATRIX_ROWS] = {0};

    // Read from SPI the matrix
    spi_start(SPI_MATRIX_CHIP_SELECT_PIN, false, 0, SPI_MATRIX_DIVISOR);
    spi_receive((uint8_t*)temp_matrix, MATRIX_SHIFT_REGISTER_COUNT * sizeof(matrix_row_t));
    spi_stop();

    // Read from the encoder pushbutton
    // temp_matrix[5] = readPin(ENCODER_PUSHBUTTON_PIN) ? 1 : 0;

    // Check if we've changed, return the last-read data
    bool changed = memcmp(current_matrix, temp_matrix, sizeof(temp_matrix)) != 0;
    if (changed) {
        memcpy(current_matrix, temp_matrix, sizeof(temp_matrix));
    }
    return changed;
}
