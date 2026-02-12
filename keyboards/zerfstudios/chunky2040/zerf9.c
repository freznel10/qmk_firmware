/* Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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

#include "zerf9.h"
#include "split_common/transactions.h"
#include "string.h"
#include "split_common/split_util.h"
#include "freznel.h"
#include <hal.h>
//#include "serial.h"
// __attribute__((weak)) void ui_init(void) {}
// __attribute__((weak)) void ui_task(void) {}

#ifdef QUANTUM_PAINTER_ENABLE
// #include "qp_ssd1351.h"
// painter_device_t ssd1351;
kb_runtime_config kb_state;
__attribute__((weak)) void draw_ui_user(void) {}
#endif

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif  // CONSOLE_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#    ifndef CHARYBDIS_MINIMUM_DEFAULT_DPI
#        define CHARYBDIS_MINIMUM_DEFAULT_DPI 400
#    endif  // CHARYBDIS_MINIMUM_DEFAULT_DPI

#    ifndef CHARYBDIS_DEFAULT_DPI_CONFIG_STEP
#        define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 200
#    endif  // CHARYBDIS_DEFAULT_DPI_CONFIG_STEP

#    ifndef CHARYBDIS_MINIMUM_SNIPING_DPI
#        define CHARYBDIS_MINIMUM_SNIPING_DPI 200
#    endif  // CHARYBDIS_MINIMUM_SNIPER_MODE_DPI

#    ifndef CHARYBDIS_SNIPING_DPI_CONFIG_STEP
#        define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100
#    endif  // CHARYBDIS_SNIPING_DPI_CONFIG_STEP

// Fixed DPI for drag-scroll.
#    ifndef CHARYBDIS_DRAGSCROLL_DPI
#        define CHARYBDIS_DRAGSCROLL_DPI 100
#    endif  // CHARYBDIS_DRAGSCROLL_DPI

#    ifndef CHARYBDIS_DRAGSCROLL_BUFFER_SIZE
#        define CHARYBDIS_DRAGSCROLL_BUFFER_SIZE 1
#    endif  // !CHARYBDIS_DRAGSCROLL_BUFFER_SIZE

#    ifndef CHARYBDIS_POINTER_ACCELERATION_FACTOR
#        define CHARYBDIS_POINTER_ACCELERATION_FACTOR 24
#    endif  // !CHARYBDIS_POINTER_ACCELERATION_FACTOR

typedef union {
    uint8_t raw;
    struct {
        uint8_t pointer_default_dpi : 4;  // 16 steps available.
        uint8_t pointer_sniping_dpi : 2;  // 4 steps available.
        bool    is_dragscroll_enabled : 1;
        bool    is_sniping_enabled : 1;
        bool    is_auto_mouse_enabled : 1;
    } __attribute__((packed));
} charybdis_config_t;

static charybdis_config_t g_charybdis_config = {0};



/**
 * \brief Set the value of `config` from EEPROM.
 *
 * Note that `is_dragscroll_enabled` and `is_sniping_enabled` are purposefully
 * ignored since we do not want to persist this state to memory.  In practice,
 * this state is always written to maximize write-performances.  Therefore, we
 * explicitly set them to `false` in this function.
 */
static void read_charybdis_config_from_eeprom(charybdis_config_t* config) {
    config->raw                   = eeconfig_read_kb() & 0xff;
    config->is_dragscroll_enabled = false;
    config->is_sniping_enabled    = false;
    config->is_auto_mouse_enabled    = false;
}

/**
 * \brief Save the value of `config` to eeprom.
 *
 * Note that all values are written verbatim, including whether drag-scroll
 * and/or sniper mode are enabled.  `read_charybdis_config_from_eeprom(…)`
 * resets these 2 values to `false` since it does not make sense to persist
 * these across reboots of the board.
 */
static void write_charybdis_config_to_eeprom(charybdis_config_t* config) { eeconfig_update_kb(config->raw); }

/** \brief Return the current value of the pointer's default DPI. */
static uint16_t get_pointer_default_dpi(charybdis_config_t* config) { return (uint16_t)config->pointer_default_dpi * CHARYBDIS_DEFAULT_DPI_CONFIG_STEP + CHARYBDIS_MINIMUM_DEFAULT_DPI; }

/** \brief Return the current value of the pointer's sniper-mode DPI. */
static uint16_t get_pointer_sniping_dpi(charybdis_config_t* config) { return (uint16_t)config->pointer_sniping_dpi * CHARYBDIS_SNIPING_DPI_CONFIG_STEP + CHARYBDIS_MINIMUM_SNIPING_DPI; }

/** \brief Set the appropriate DPI for the input config. */
static void maybe_update_pointing_device_cpi(charybdis_config_t* config) {
    if (config->is_dragscroll_enabled) {
        pointing_device_set_cpi_on_side(true, CHARYBDIS_DRAGSCROLL_DPI);
    } else if (config->is_sniping_enabled) {
        pointing_device_set_cpi_on_side(true,get_pointer_sniping_dpi(config));
        pointing_device_set_cpi_on_side(false,get_pointer_sniping_dpi(config));
    } else {
        pointing_device_set_cpi_on_side(true, get_pointer_default_dpi(config));
        pointing_device_set_cpi_on_side(false, get_pointer_default_dpi(config));
    }
}

/**
 * \brief Update the pointer's default DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to CHARYBDIS_DEFAULT_DPI_CONFIG_STEP.
 */
static void step_pointer_default_dpi(charybdis_config_t* config, bool forward) {
    config->pointer_default_dpi += forward ? 1 : -1;
    maybe_update_pointing_device_cpi(config);
}

/**
 * \brief Update the pointer's sniper-mode DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to CHARYBDIS_SNIPING_DPI_CONFIG_STEP.
 */
static void step_pointer_sniping_dpi(charybdis_config_t* config, bool forward) {
    config->pointer_sniping_dpi += forward ? 1 : -1;
    maybe_update_pointing_device_cpi(config);
}

uint16_t charybdis_get_pointer_default_dpi(void) { return get_pointer_default_dpi(&g_charybdis_config); }

uint16_t charybdis_get_pointer_sniping_dpi(void) { return get_pointer_sniping_dpi(&g_charybdis_config); }

void charybdis_cycle_pointer_default_dpi_noeeprom(bool forward) { step_pointer_default_dpi(&g_charybdis_config, forward); }

void charybdis_cycle_pointer_default_dpi(bool forward) {
    step_pointer_default_dpi(&g_charybdis_config, forward);
    write_charybdis_config_to_eeprom(&g_charybdis_config);
}

void charybdis_cycle_pointer_sniping_dpi_noeeprom(bool forward) { step_pointer_sniping_dpi(&g_charybdis_config, forward); }

void charybdis_cycle_pointer_sniping_dpi(bool forward) {
    step_pointer_sniping_dpi(&g_charybdis_config, forward);
    write_charybdis_config_to_eeprom(&g_charybdis_config);
}

bool charybdis_get_pointer_sniping_enabled(void) { return g_charybdis_config.is_sniping_enabled; }

void charybdis_set_pointer_sniping_enabled(bool enable) {
    g_charybdis_config.is_sniping_enabled = enable;
    maybe_update_pointing_device_cpi(&g_charybdis_config);
}

bool charybdis_get_pointer_dragscroll_enabled(void) { return g_charybdis_config.is_dragscroll_enabled; }

void charybdis_set_pointer_dragscroll_enabled(bool enable) {
    g_charybdis_config.is_dragscroll_enabled = enable;
    maybe_update_pointing_device_cpi(&g_charybdis_config);
}

bool charybdis_get_auto_mouse_enabled(void) { return g_charybdis_config.is_auto_mouse_enabled; }

void charybdis_set_auto_mouse_enabled(bool enable) {
    g_charybdis_config.is_auto_mouse_enabled = enable;
    maybe_update_pointing_device_cpi(&g_charybdis_config);
}

void pointing_device_init_kb(void) { maybe_update_pointing_device_cpi(&g_charybdis_config); }

#    ifndef CONSTRAIN_HID
#        define CONSTRAIN_HID(value) ((value) < XY_REPORT_MIN ? XY_REPORT_MIN : ((value) > XY_REPORT_MAX ? XY_REPORT_MAX : (value)))
#    endif // !CONSTRAIN_HID

/**
 * \brief Add optional acceleration effect.
 *
 * If `CHARYBDIS_ENABLE_POINTER_ACCELERATION` is defined, add a simple and naive
 * acceleration effect to the provided value.  Return the value unchanged
 * otherwise.
 *

 */
#    ifndef DISPLACEMENT_WITH_ACCELERATION
#        ifdef CHARYBDIS_POINTER_ACCELERATION_ENABLE
#            define DISPLACEMENT_WITH_ACCELERATION(d) (CONSTRAIN_HID(d > 0 ? d * d / CHARYBDIS_POINTER_ACCELERATION_FACTOR + d : -d * d / CHARYBDIS_POINTER_ACCELERATION_FACTOR + d))
#        else  // !CHARYBDIS_POINTER_ACCELERATION_ENABLE
#            define DISPLACEMENT_WITH_ACCELERATION(d) (d)
#        endif  // CHARYBDIS_POINTER_ACCELERATION_ENABLE
#    endif      // !DISPLACEMENT_WITH_ACCELERATION

/**
 * \brief Augment the pointing device behavior.
 *
 * Implement the Charybdis-specific features for pointing devices:
 *   - Drag-scroll
 *   - Sniping
 *   - Acceleration
 *    -Auto mouse layer
 */

#    ifdef TAPPING_TERM_PER_KEY
#        define TAP_CHECK get_tapping_term(KC_BTN1, NULL)
#    else
#        ifndef TAPPING_TERM
#            define TAPPING_TERM 240
#        endif
#        define TAP_CHECK TAPPING_TERM
#    endif


static void pointing_device_task_charybdis(report_mouse_t* left_report, report_mouse_t* right_report) {
    static int16_t scroll_buffer_x        = 0;
    static int16_t scroll_buffer_y        = 0;
    if (g_charybdis_config.is_dragscroll_enabled) {
#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_X
        scroll_buffer_x -= left_report->x;
#    else
        scroll_buffer_x += left_report->x;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_X
#    ifdef CHARYBDIS_DRAGSCROLL_REVERSE_Y
        scroll_buffer_y -= left_report->y;
#    else
        scroll_buffer_y += left_report->y;
#    endif  // CHARYBDIS_DRAGSCROLL_REVERSE_Y
        left_report->x = 0;
        left_report->y = 0;
        if (abs(scroll_buffer_x) > CHARYBDIS_DRAGSCROLL_BUFFER_SIZE) {
            left_report->h = scroll_buffer_x > 0 ? 1 : -1;
            scroll_buffer_x = 0;
        }
        if (abs(scroll_buffer_y) > CHARYBDIS_DRAGSCROLL_BUFFER_SIZE) {
            left_report->v = scroll_buffer_y > 0 ? 1 : -1;
            scroll_buffer_y = 0;
        }
    } else if (!g_charybdis_config.is_sniping_enabled) {
        left_report->x = DISPLACEMENT_WITH_ACCELERATION(left_report->x);
        left_report->y = DISPLACEMENT_WITH_ACCELERATION(left_report->y);
    }
}


report_mouse_t pointing_device_task_combined_kb (report_mouse_t left_report, report_mouse_t right_report) {
    pointing_device_task_charybdis(&left_report, &right_report);
    return pointing_device_task_combined_user(left_report, right_report);


}

#    if defined(POINTING_DEVICE_ENABLE) && !defined(NO_CHARYBDIS_KEYCODES)
/** \brief Whether SHIFT mod is enabled. */
static bool has_shift_mod(void) {
#        ifdef NO_ACTION_ONESHOT
    return mod_config(get_mods()) & MOD_MASK_SHIFT;
#        else
    return mod_config(get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
#        endif  // NO_ACTION_ONESHOT
}
#    endif  // POINTING_DEVICE_ENABLE && !NO_CHARYBDIS_KEYCODES

/**
 * \brief Outputs the Charybdis configuration to console.
 *
 * Prints the in-memory configuration structure to console, for debugging.
 * Includes:
 *   - raw value
 *   - drag-scroll: on/off
 *   - sniping: on/off
 *   - default DPI: internal table index/actual DPI
 *   - sniping DPI: internal table index/actual DPI
 */
// void debug_charybdis_config_to_console(charybdis_config_t* config) {
// #    ifdef CONSOLE_ENABLE
//     dprintf("(charybdis) process_record_kb: config = {\n"
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

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        return false;
        // debug_charybdis_config_to_console(&g_charybdis_config);
    }
#    ifndef NO_CHARYBDIS_KEYCODES
    switch (keycode) {
        case POINTER_DEFAULT_DPI_FORWARD:
            if (record->event.pressed) {
                // Step backward if shifted, forward otherwise.
                charybdis_cycle_pointer_default_dpi(/* forward= */ !has_shift_mod());
            }
            break;
        case POINTER_DEFAULT_DPI_REVERSE:
            if (record->event.pressed) {
                // Step forward if shifted, backward otherwise.
                charybdis_cycle_pointer_default_dpi(/* forward= */ has_shift_mod());
            }
            break;
        case POINTER_SNIPING_DPI_FORWARD:
            if (record->event.pressed) {
                // Step backward if shifted, forward otherwise.
                charybdis_cycle_pointer_sniping_dpi(/* forward= */ !has_shift_mod());
            }
            break;
        case POINTER_SNIPING_DPI_REVERSE:
            if (record->event.pressed) {
                // Step forward if shifted, backward otherwise.
                charybdis_cycle_pointer_sniping_dpi(/* forward= */ has_shift_mod());
            }
            break;
        case SNIPING_MODE:
            charybdis_set_pointer_sniping_enabled(record->event.pressed);
            break;
        case SNIPING_MODE_TOGGLE:
            if (record->event.pressed) {
                charybdis_set_pointer_sniping_enabled(!charybdis_get_pointer_sniping_enabled());
            }
            break;
        case AUTO_MOUSE_LAYER_TOGGLE:
            if (record->event.pressed) {
                charybdis_set_auto_mouse_enabled(!charybdis_get_auto_mouse_enabled());
            }
            break;
        case DRAGSCROLL_MODE:
            charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
            break;
        case DRAGSCROLL_MODE_TOGGLE:
            if (record->event.pressed) {
                charybdis_set_pointer_dragscroll_enabled(!charybdis_get_pointer_dragscroll_enabled());
            }
            break;
        case RGB_TOG1:
        if (record->event.pressed) {
                rgb_matrix_increase_flags();
            }
            return false;
                case DRAG_MOM:
            if (record->event.pressed) {
                is_drag_mom ^= 1;
            }
            break;
        case DRAG_SCROLL:{
                scrolling_mode ^= 1;
            }
            break;

    }
#    endif  // !NO_CHARYBDIS_KEYCODES
#    ifndef MOUSEKEY_ENABLE
    // Simulate mouse keys if full support is not enabled (reduces firmware size
    // while maintaining support for mouse keys).
    if (IS_MOUSEKEY_BUTTON(keycode)) {
        report_mouse_t mouse_report = pointing_device_get_report();
        mouse_report.buttons        = pointing_device_handle_buttons(mouse_report.buttons, record->event.pressed, keycode - KC_MS_BTN1);
        pointing_device_set_report(mouse_report);
        pointing_device_send();
    }
#    endif  // !MOUSEKEY_ENABLE
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
    if (is_keyboard_master()) {
        // Modify allowed current limits
        // Turn off the LCD if there's been no matrix activity
        kb_state.lcd_power = (last_input_activity_elapsed() < 30000) ? 1 : 0;
    }
}
#endif

#ifdef QUANTUM_PAINTER_ENABLE
void kb_state_sync_slave(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(kb_runtime_config)) {
        memcpy(&kb_state, initiator2target_buffer, sizeof(kb_runtime_config));
    }
}
#endif


void eeconfig_init_kb(void) {
    g_charybdis_config.raw = 0;
    write_charybdis_config_to_eeprom(&g_charybdis_config);
    maybe_update_pointing_device_cpi(&g_charybdis_config);
    eeconfig_init_user();
}

void matrix_init_kb(void) {
    read_charybdis_config_from_eeprom(&g_charybdis_config);
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

void charybdis_config_sync_handler(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(g_charybdis_config)) {
        memcpy(&g_charybdis_config, initiator2target_buffer, sizeof(g_charybdis_config));
    }
}

void keyboard_post_init_kb(void) {
    transaction_register_rpc(RPC_ID_KB_CONFIG_SYNC, charybdis_config_sync_handler);
    #ifdef QUANTUM_PAINTER_ENABLE
    transaction_register_rpc(RPC_ID_SYNC_STATE_KB, kb_state_sync_slave);
        // Reset the initial shared data value between master and slave
    memset(&kb_state, 0, sizeof(kb_state));
    #endif
    wait_ms(50);

    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
#ifdef QUANTUM_PAINTER_ENABLE
     kb_state_update();
#endif
    if (is_keyboard_master()) {
        // Keep track of the last state, so that we can tell if we need to propagate to slave
        static charybdis_config_t last_charybdis_config = {0};
        static uint32_t           last_sync             = 0;
        bool                      needs_sync            = false;

        // Check if the state values are different
        if (memcmp(&g_charybdis_config, &last_charybdis_config, sizeof(g_charybdis_config))) {
            needs_sync = true;
            memcpy(&last_charybdis_config, &g_charybdis_config, sizeof(g_charybdis_config));
        }
        // Send to slave every 500ms regardless of state change
        if (timer_elapsed32(last_sync) > 500) {
            needs_sync = true;
        }

        // Perform the sync if requested
        if (needs_sync) {
            if (transaction_rpc_send(RPC_ID_KB_CONFIG_SYNC, sizeof(g_charybdis_config), &g_charybdis_config)) {
                last_sync = timer_read32();
            }
        }
        #ifdef QUANTUM_PAINTER_ENABLE
        static kb_runtime_config last_kb_state;
        // Check if the state values are different
        if (memcmp(&kb_state, &last_kb_state, sizeof(kb_runtime_config))) {
            needs_sync = true;
            memcpy(&last_kb_state, &kb_state, sizeof(kb_runtime_config));
        }

        // Perform the sync if requested
        if (needs_sync) {
            if (transaction_rpc_send(RPC_ID_SYNC_STATE_KB, sizeof(kb_runtime_config), &kb_state)) {
                last_sync = timer_read32();
            }
        }
        #endif
    }
    #ifdef QUANTUM_PAINTER_ENABLE
    static bool lcd_on = false;
    if (lcd_on != (bool)kb_state.lcd_power) {
        lcd_on = (bool)kb_state.lcd_power;
        qp_power(ssd1351, lcd_on);
    }
    if (kb_state.lcd_power) {
    draw_ui_user();
    }
    #endif
    #ifdef WFI_ENABLE
    if (last_input_activity_elapsed() > 3000) {
        //
        const pin_t col_pins[] = MATRIX_COL_PINS;
        const pin_t row_pins[] = MATRIX_ROW_PINS;


        // Set up row/col pins and attach callback
        for (int i = 0; i < sizeof(col_pins) / sizeof(pin_t); ++i) {
            setPinOutput(col_pins[i]);
            writePinLow(col_pins[i]);
        }
        for (int i = 0; i < sizeof(row_pins) / sizeof(pin_t); ++i) {
            setPinInputHigh(row_pins[i]);
            palEnableLineEvent(row_pins[i], PAL_EVENT_MODE_BOTH_EDGES);
        }

        // Wait for an interrupt
        __WFI();

        // Now that the interrupt has woken us up, reset all the row/col pins back to defaults
        for (int i = 0; i < sizeof(row_pins) / sizeof(pin_t); ++i) {
            palDisableLineEvent(row_pins[i]);
            setPinInputHigh(row_pins[i]);
        }
        for (int i = 0; i < sizeof(col_pins) / sizeof(pin_t); ++i) {
            writePinHigh(col_pins[i]);
            setPinInputHigh(col_pins[i]);
        }
    }
    #endif

    // no need for user function, is called already
}

#endif  // POINTING_DEVICE_ENABLE

// __attribute__((weak)) void matrix_init_sub_kb(void) {}
// void                       matrix_init_kb(void) {
// #ifdef POINTING_DEVICE_ENABLE
//     read_charybdis_config_from_eeprom(&g_charybdis_config);
// #endif  // POINTING_DEVICE_ENABLE
//     matrix_init_sub_kb();
//     matrix_init_user();
// }

// __attribute__((weak)) void matrix_scan_sub_kb(void) {}
// void                       matrix_scan_kb(void) {
//     matrix_scan_sub_kb();
//     matrix_scan_user();
// }
