/* Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2020-2022 Christopher Courtney, aka Drashna Jael're <drashna@live.com> (@drashna)
 * Copyright 2021-2022 Sadek Baroudi <sadekbaroudi@gmail.com> <@sadekbaroudi>
 * Copyright 2022 Freznel B. Sta. Ana <freznel@gmail.com> (@freznel10)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
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

#include "emblem.h"
#include "string.h"
#include <hal.h>
#include "analog.h"
#include "spi_master.h"
#include "ui/ui.h"

#include <qp.h>
#include <qp_lvgl.h>

#ifdef QUANTUM_PAINTER_ENABLE
painter_device_t qp_display;
extern painter_device_t surface;
kb_runtime_config kb_state;
__attribute__((weak)) void draw_ui_user(void) {}
__attribute__((weak)) void ui_init(void) {}
#endif

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif  // CONSOLE_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#    ifndef EMBLEM_MINIMUM_DEFAULT_DPI
#        define EMBLEM_MINIMUM_DEFAULT_DPI 400
#    endif  // EMBLEM_MINIMUM_DEFAULT_DPI

#    ifndef EMBLEM_DEFAULT_DPI_CONFIG_STEP
#        define EMBLEM_DEFAULT_DPI_CONFIG_STEP 200
#    endif  // EMBLEM_DEFAULT_DPI_CONFIG_STEP

#    ifndef EMBLEM_MINIMUM_SNIPING_DPI
#        define EMBLEM_MINIMUM_SNIPING_DPI 200
#    endif  // EMBLEM_MINIMUM_SNIPER_MODE_DPI

#    ifndef EMBLEM_SNIPING_DPI_CONFIG_STEP
#        define EMBLEM_SNIPING_DPI_CONFIG_STEP 100
#    endif  // EMBLEM_SNIPING_DPI_CONFIG_STEP

// Fixed DPI for drag-scroll.
#    ifndef EMBLEM_DRAGSCROLL_DPI
#        define EMBLEM_DRAGSCROLL_DPI 400
#    endif  // EMBLEM_DRAGSCROLL_DPI

#    ifndef EMBLEM_DRAGSCROLL_BUFFER_SIZE
#        define EMBLEM_DRAGSCROLL_BUFFER_SIZE 1
#    endif  // !EMBLEM_DRAGSCROLL_BUFFER_SIZE

#    ifndef EMBLEM_POINTER_ACCELERATION_FACTOR
#        define EMBLEM_POINTER_ACCELERATION_FACTOR 24
#    endif  // !EMBLEM_POINTER_ACCELERATION_FACTOR

typedef union {
    uint8_t raw;
    struct {
        uint8_t pointer_default_dpi : 4;  // 16 steps available.
        uint8_t pointer_sniping_dpi : 2;  // 4 steps available.
        bool    is_dragscroll_enabled : 1;
        bool    is_sniping_enabled : 1;
    } __attribute__((packed));
} emblem_config_t;

static emblem_config_t g_emblem_config = {0};

/**
 * \brief Set the value of `config` from EEPROM.
 *
 * Note that `is_dragscroll_enabled` and `is_sniping_enabled` are purposefully
 * ignored since we do not want to persist this state to memory.  In practice,
 * this state is always written to maximize write-performances.  Therefore, we
 * explicitly set them to `false` in this function.
 */
static void read_emblem_config_from_eeprom(emblem_config_t* config) {
    config->raw                   = eeconfig_read_kb() & 0xff;
    config->is_dragscroll_enabled = false;
    config->is_sniping_enabled    = false;
}

/**
 * \brief Save the value of `config` to eeprom.
 *
 * Note that all values are written verbatim, including whether drag-scroll
 * and/or sniper mode are enabled.  `read_emblem_config_from_eeprom(…)`
 * resets these 2 values to `false` since it does not make sense to persist
 * these across reboots of the board.
 */
static void write_emblem_config_to_eeprom(emblem_config_t* config) { eeconfig_update_kb(config->raw); }

/** \brief Return the current value of the pointer's default DPI. */
static uint16_t get_pointer_default_dpi(emblem_config_t* config) { return (uint16_t)config->pointer_default_dpi * EMBLEM_DEFAULT_DPI_CONFIG_STEP + EMBLEM_MINIMUM_DEFAULT_DPI; }

/** \brief Return the current value of the pointer's sniper-mode DPI. */
static uint16_t get_pointer_sniping_dpi(emblem_config_t* config) { return (uint16_t)config->pointer_sniping_dpi * EMBLEM_SNIPING_DPI_CONFIG_STEP + EMBLEM_MINIMUM_SNIPING_DPI; }

/** \brief Set the appropriate DPI for the input config. */
static void maybe_update_pointing_device_cpi(emblem_config_t* config) {
    if (config->is_dragscroll_enabled) {
        pointing_device_set_cpi(EMBLEM_DRAGSCROLL_DPI);
    } else if (config->is_sniping_enabled) {
        pointing_device_set_cpi(get_pointer_sniping_dpi(config));
    } else {
        pointing_device_set_cpi(get_pointer_default_dpi(config));
    }
}

/**
 * \brief Update the pointer's default DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to EMBLEM_DEFAULT_DPI_CONFIG_STEP.
 */
static void step_pointer_default_dpi(emblem_config_t* config, bool forward) {
    config->pointer_default_dpi += forward ? 1 : -1;
    maybe_update_pointing_device_cpi(config);
}

/**
 * \brief Update the pointer's sniper-mode DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to EMBLEM_SNIPING_DPI_CONFIG_STEP.
 */
static void step_pointer_sniping_dpi(emblem_config_t* config, bool forward) {
    config->pointer_sniping_dpi += forward ? 1 : -1;
    maybe_update_pointing_device_cpi(config);
}

uint16_t emblem_get_pointer_default_dpi(void) { return get_pointer_default_dpi(&g_emblem_config); }

uint16_t emblem_get_pointer_sniping_dpi(void) { return get_pointer_sniping_dpi(&g_emblem_config); }

void emblem_cycle_pointer_default_dpi_noeeprom(bool forward) { step_pointer_default_dpi(&g_emblem_config, forward); }

void emblem_cycle_pointer_default_dpi(bool forward) {
    step_pointer_default_dpi(&g_emblem_config, forward);
    write_emblem_config_to_eeprom(&g_emblem_config);
}

void emblem_cycle_pointer_sniping_dpi_noeeprom(bool forward) { step_pointer_sniping_dpi(&g_emblem_config, forward); }

void emblem_cycle_pointer_sniping_dpi(bool forward) {
    step_pointer_sniping_dpi(&g_emblem_config, forward);
    write_emblem_config_to_eeprom(&g_emblem_config);
}

bool emblem_get_pointer_sniping_enabled(void) { return g_emblem_config.is_sniping_enabled; }

void emblem_set_pointer_sniping_enabled(bool enable) {
    g_emblem_config.is_sniping_enabled = enable;
    maybe_update_pointing_device_cpi(&g_emblem_config);
}

bool emblem_get_pointer_dragscroll_enabled(void) { return g_emblem_config.is_dragscroll_enabled; }

void emblem_set_pointer_dragscroll_enabled(bool enable) {
    g_emblem_config.is_dragscroll_enabled = enable;
    maybe_update_pointing_device_cpi(&g_emblem_config);
}

void pointing_device_init_kb(void) { maybe_update_pointing_device_cpi(&g_emblem_config); }

#    ifndef CONSTRAIN_HID
#        define CONSTRAIN_HID(value) ((value) < XY_REPORT_MIN ? XY_REPORT_MIN : ((value) > XY_REPORT_MAX ? XY_REPORT_MAX : (value)))
#    endif // !CONSTRAIN_HID

/**
 * \brief Add optional acceleration effect.
 *
 * If `EMBLEM_ENABLE_POINTER_ACCELERATION` is defined, add a simple and naive
 * acceleration effect to the provided value.  Return the value unchanged
 * otherwise.
 */
#    ifndef DISPLACEMENT_WITH_ACCELERATION
#        ifdef EMBLEM_POINTER_ACCELERATION_ENABLE
#            define DISPLACEMENT_WITH_ACCELERATION(d) (CONSTRAIN_HID(d > 0 ? d * d / EMBLEM_POINTER_ACCELERATION_FACTOR + d : -d * d / EMBLEM_POINTER_ACCELERATION_FACTOR + d))
#        else  // !EMBLEM_POINTER_ACCELERATION_ENABLE
#            define DISPLACEMENT_WITH_ACCELERATION(d) (d)
#        endif  // EMBLEM_POINTER_ACCELERATION_ENABLE
#    endif      // !DISPLACEMENT_WITH_ACCELERATION

/**
 * \brief Augment the pointing device behavior.
 *
 * Implement the emblem-specific features for pointing devices:
 *   - Drag-scroll
 *   - Sniping
 *   - Acceleration
 */

#    ifdef TAPPING_TERM_PER_KEY
#        define TAP_CHECK get_tapping_term(KC_BTN1, NULL)
#    else
#        ifndef TAPPING_TERM
#            define TAPPING_TERM 240
#        endif
#        define TAP_CHECK TAPPING_TERM
#    endif

static void pointing_device_task_emblem(report_mouse_t* mouse_report) {
    static int16_t scroll_buffer_x        = 0;
    static int16_t scroll_buffer_y        = 0;
    if (g_emblem_config.is_dragscroll_enabled) {
#    ifdef EMBLEM_DRAGSCROLL_REVERSE_X
        scroll_buffer_x -= mouse_report->x;
#    else
        scroll_buffer_x += mouse_report->x;
#    endif  // EMBLEM_DRAGSCROLL_REVERSE_X
#    ifdef EMBLEM_DRAGSCROLL_REVERSE_Y
        scroll_buffer_y -= mouse_report->y;
#    else
        scroll_buffer_y += mouse_report->y;
#    endif  // EMBLEM_DRAGSCROLL_REVERSE_Y
        mouse_report->x = 0;
        mouse_report->y = 0;
        if (abs(scroll_buffer_x) > EMBLEM_DRAGSCROLL_BUFFER_SIZE) {
            mouse_report->h = scroll_buffer_x > 0 ? 1 : -1;
            scroll_buffer_x = 0;
        }
        if (abs(scroll_buffer_y) > EMBLEM_DRAGSCROLL_BUFFER_SIZE) {
            mouse_report->v = scroll_buffer_y > 0 ? 1 : -1;
            scroll_buffer_y = 0;
        }
    } else if (!g_emblem_config.is_sniping_enabled) {
        mouse_report->x = DISPLACEMENT_WITH_ACCELERATION(mouse_report->x);
        mouse_report->y = DISPLACEMENT_WITH_ACCELERATION(mouse_report->y);
    }
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    pointing_device_task_emblem(&mouse_report);
    mouse_report = pointing_device_task_user(mouse_report);

    return mouse_report;
}

#    if defined(POINTING_DEVICE_ENABLE) && !defined(NO_EMBLEM_KEYCODES)
/** \brief Whether SHIFT mod is enabled. */
static bool has_shift_mod(void) {
#        ifdef NO_ACTION_ONESHOT
    return mod_config(get_mods()) & MOD_MASK_SHIFT;
#        else
    return mod_config(get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
#        endif  // NO_ACTION_ONESHOT
}
#    endif  // POINTING_DEVICE_ENABLE && !NO_EMBLEM_KEYCODES

/**
 * \brief Outputs the emblem configuration to console.
 *
 * Prints the in-memory configuration structure to console, for debugging.
 * Includes:
 *   - raw value
 *   - drag-scroll: on/off
 *   - sniping: on/off
 *   - default DPI: internal table index/actual DPI
 *   - sniping DPI: internal table index/actual DPI
 */
// void debug_emblem_config_to_console(emblem_config_t* config) {
// #    ifdef CONSOLE_ENABLE
//     dprintf("(emblem) process_record_kb: config = {\n"
//             "\traw = 0x%04X,\n"
//             "\t{\n"
//             "\t\tis_dragscroll_enabled=%b\n"
//             "\t\tis_sniping_enabled=%b\n"
//             "\t\tdefault_dpi=0x%02X (%ld)\n"
//             "\t\tsniping_dpi=0x%01X (%ld)\n"
//             "\t}\n"
//             "}\n",
//             config->raw, config->is_dragscroll_enabled, config->is_sniping_enabled, config->pointer_default_dpi, get_pointer_default_dpi(config), config->pointer_sniping_dpi, get_pointer_sniping_dpi(config));
// #    endif  // CONSOLE_ENABLE
// }


static int8_t rotations = 0;
bool lvgl_encoder = false;
static lv_group_t *g;
static uint32_t act_key = 0;

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        return false;
        // debug_emblem_config_to_console(&g_emblem_config);
    }
#    ifndef NO_EMBLEM_KEYCODES
    switch (keycode) {
        case POINTER_DEFAULT_DPI_FORWARD:
            if (record->event.pressed) {
                // Step backward if shifted, forward otherwise.
                emblem_cycle_pointer_default_dpi(/* forward= */ !has_shift_mod());
            }
            break;
        case POINTER_DEFAULT_DPI_REVERSE:
            if (record->event.pressed) {
                // Step forward if shifted, backward otherwise.
                emblem_cycle_pointer_default_dpi(/* forward= */ has_shift_mod());
            }
            break;
        case POINTER_SNIPING_DPI_FORWARD:
            if (record->event.pressed) {
                // Step backward if shifted, forward otherwise.
                emblem_cycle_pointer_sniping_dpi(/* forward= */ !has_shift_mod());
            }
            break;
        case POINTER_SNIPING_DPI_REVERSE:
            if (record->event.pressed) {
                // Step forward if shifted, backward otherwise.
                emblem_cycle_pointer_sniping_dpi(/* forward= */ has_shift_mod());
            }
            break;
        case SNIPING_MODE:
            emblem_set_pointer_sniping_enabled(record->event.pressed);
            break;
        case SNIPING_MODE_TOGGLE:
            if (record->event.pressed) {
                emblem_set_pointer_sniping_enabled(!emblem_get_pointer_sniping_enabled());
            }
            break;
        case AUTO_MOUSE_LAYER_TOGGLE:
            if (record->event.pressed) {
                auto_mouse_layer_off();
                set_auto_mouse_enable((AUTO_MOUSE_ENABLED) ^ 1);
            }
            break;
        case DRAGSCROLL_MODE:
            emblem_set_pointer_dragscroll_enabled(record->event.pressed);
            break;
        case DRAGSCROLL_MODE_TOGGLE:
            if (record->event.pressed) {
                emblem_set_pointer_dragscroll_enabled(!emblem_get_pointer_dragscroll_enabled());
            }
            break;
        case RGB_TOG1:
            if (record->event.pressed) {
                rgb_matrix_increase_flags();
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
        case LO_RES_DOWN: {
            if (record->event.pressed) {
                // set_hires_scroll_multiplier(HIRES_BOTH, 1);
            }
            break;
        }
        case LO_RES_UP: {
            if (record->event.pressed) {
                // set_hires_scroll_multiplier(HIRES_BOTH, 120);
            }
            break;
        }
    }
#    endif  // !NO_EMBLEM_KEYCODES
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

#ifdef QUANTUM_PAINTER_ENABLE
void kb_state_update(void) {
        // Turn off the LCD if there's been no matrix activity
        kb_state.lcd_power = (last_input_activity_elapsed() < 30000) ? 1 : 0;
}
#endif

void eeconfig_init_kb(void) {
    g_emblem_config.raw = 0;
    write_emblem_config_to_eeprom(&g_emblem_config);
    maybe_update_pointing_device_cpi(&g_emblem_config);
    eeconfig_init_user();
}

void matrix_power_up(void) { pointing_device_task(); }

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
    setPinOutput(LCD_POWER_ENABLE_PIN);
    writePinHigh(LCD_POWER_ENABLE_PIN);
    qp_display = qp_gc9a01_make_spi_device(240, 240, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 8, 0);
    qp_init(qp_display, SCREEN_ORIENTATION);
    qp_rect(qp_display, 0, 0, 239, 239, 0, 255, 255, true);
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
    wait_ms(50);

    ui_init();
    keyboard_post_init_user();
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

void housekeeping_task_kb(void) {
    #ifdef QUANTUM_PAINTER_ENABLE
    // setPinOutput(GP15);
    // writePinHigh(GP15);
    kb_state_update();
    if (kb_state.lcd_power) {
#ifdef BACKLIGHT_ENABLE
        backlight_level_noeeprom(3);
#endif
        rgb_matrix_enable_noeeprom();
    } else {
#ifdef BACKLIGHT_ENABLE
        backlight_level_noeeprom(0);
#endif
        rgb_matrix_disable_noeeprom();
    }
    static bool lcd_on = false;
    if (lcd_on != (bool)kb_state.lcd_power) {
        lcd_on = (bool)kb_state.lcd_power;
        qp_power(qp_display, lcd_on);
    }
    // if (kb_state.lcd_power) {
    // qp_power(qp_display, true);
    // draw_ui_user();
    // }
     lvgl_event_triggers();
#endif //QUANTUM_PAINTER_ENABLE
}

#endif  // POINTING_DEVICE_ENABLE

__attribute__((weak)) void matrix_init_sub_kb(void) {}
void                       matrix_init_kb(void) {
#ifdef POINTING_DEVICE_ENABLE
    read_emblem_config_from_eeprom(&g_emblem_config);
#endif  // POINTING_DEVICE_ENABLE
    matrix_init_sub_kb();
    matrix_init_user();
}

__attribute__((weak)) void matrix_scan_sub_kb(void) {}
void                       matrix_scan_kb(void) {
    matrix_scan_sub_kb();
    matrix_scan_user();
}
