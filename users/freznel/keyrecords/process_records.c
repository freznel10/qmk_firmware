// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "freznel.h"
#include "version.h"

#ifdef CUSTOM_DYNAMIC_MACROS_ENABLE
#    include "keyrecords/dynamic_macros.h"
#endif

#ifdef HAPTIC_ENABLE
#    include "drivers/haptic/drv2605l.h"
#    define USER_HAPTIC_PULSE() drv2605l_pulse(DRV2605L_EFFECT_MEDIUM_CLICK_1_100)
#else
#    define USER_HAPTIC_PULSE() ((void)0)
#endif

#include "select_word.h"
#include "pointing_device_auto_mouse.h"

#if defined(RGB_TOG)
#    define USER_RGB_TOGGLE_KEYCODE RGB_TOG
#elif defined(UG_TOGG)
#    define USER_RGB_TOGGLE_KEYCODE UG_TOGG
#elif defined(QK_UNDERGLOW_TOGGLE)
#    define USER_RGB_TOGGLE_KEYCODE QK_UNDERGLOW_TOGGLE
#endif



uint16_t copy_paste_timer;
bool   host_driver_disabled = false;
bool  is_caret = false;
bool auto_mouse_tg_off = false;


/**
 * @brief Keycode handler for keymaps
 *
 * This handles the keycodes at the keymap level, useful for keyboard specific customization
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) bool process_record_painter(uint16_t keycode, keyrecord_t *record) {
    return true;
}


#ifndef SUPER_TAB_TIMEOUT
#   define SUPER_TAB_TIMEOUT 500
#endif
#ifndef SUPER_CTRL_TAB_TIMEOUT
#   define SUPER_CTRL_TAB_TIMEOUT 750
#endif

bool is_super_tab_active = false;
bool is_super_ctrl_tab_active = false;
// Note that super tab and super control tab share the same timer! Shouldn't matter, but in case there are issues, note this.
uint16_t super_tab_timer = 0;

void press_super_tab(bool shift) {
    if (shift) {
        register_code(KC_LSFT);
    } else {
        unregister_code(KC_LSFT);
    }
    if (!is_super_tab_active) {
        is_super_tab_active = true;
#ifdef MAC_PREFERRED
        register_code(KC_LGUI);
#else
        register_code(KC_LALT);
#endif
    }

    super_tab_timer = timer_read();
    tap_code(KC_TAB);
}

void unregister_super_tab(void) {
    if (is_super_tab_active) {
        if (timer_elapsed(super_tab_timer) > SUPER_TAB_TIMEOUT) {
#ifdef FP_MAC_PREFERRED
            unregister_code(KC_LGUI);
#else
            unregister_code(KC_LALT);
#endif
            is_super_tab_active = false;

            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_code(KC_LSFT);
            }
        }
    }
}

void press_super_ctrl_tab(bool shift) {
    if (shift) {
        register_code(KC_LSFT);
    } else {
        unregister_code(KC_LSFT);
    }
    if (!is_super_ctrl_tab_active) {
        is_super_ctrl_tab_active = true;
        register_code(KC_LCTL);
    }

    super_tab_timer = timer_read();
    tap_code(KC_TAB);
}

void unregister_super_ctrl_tab(void) {
    if (is_super_ctrl_tab_active) {
        if (timer_elapsed(super_tab_timer) > SUPER_CTRL_TAB_TIMEOUT) {
            unregister_code(KC_LCTL);
            is_super_ctrl_tab_active = false;

            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_code(KC_LSFT);
            }
        }
    }
}

/**
 * @brief Main user keycode handler
 *
 * This handles all of the keycodes for the user, including calling feature handlers.
 *
 * @param keycode Keycode from matrix
 * @param record keyrecord_t data structure
 * @return true Continue processing keycode and send to host
 * @return false Stop process keycode and do not send to host
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef KEYLOGGER_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %b, time: %5u, int: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);	    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %1d, time: %5u, int: %1d, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif // KEYLOGGER_ENABLE	#endif // KEYLOGGER_ENABLE
#if defined(OLED_ENABLE) && defined(CUSTOM_OLED_DRIVER)
    process_record_user_oled(keycode, record);
#endif // OLED
    if(!process_select_word(keycode, record, SELWORD)) { return false; }

    if (!(process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
#ifdef CUSTOM_RGB_MATRIX
          && process_record_user_rgb_matrix(keycode, record)
#endif
#ifdef CUSTOM_RGBLIGHT
          && process_record_user_rgb_light(keycode, record)
#endif
#ifdef CUSTOM_UNICODE_ENABLE
          && process_record_unicode(keycode, record)
#endif
#if defined(CUSTOM_POINTING_DEVICE)
          && process_record_pointing(keycode, record)
#endif
#ifdef SUPER_ALT_TAB_ENABLE
        && process_record_super_alt_tab(keycode, record)
#endif
#ifdef CUSTOM_DYNAMIC_MACROS_ENABLE
          && process_record_dynamic_macro(keycode, record)
#endif
          && true)) {
        return false;
    }

    switch (keycode) {
        case FIRST_DEFAULT_LAYER_KEYCODE ... LAST_DEFAULT_LAYER_KEYCODE:
            if (record->event.pressed) {
                uint8_t mods = mod_config(get_mods() | get_oneshot_mods());
                if (!mods) {
                    set_single_persistent_default_layer(keycode - FIRST_DEFAULT_LAYER_KEYCODE);
#if LAST_DEFAULT_LAYER_KEYCODE > (FIRST_DEFAULT_LAYER_KEYCODE + 3)
                } else if (mods & MOD_MASK_SHIFT) {
                    set_single_persistent_default_layer(keycode - FIRST_DEFAULT_LAYER_KEYCODE + 4);
#    if LAST_DEFAULT_LAYER_KEYCODE > (FIRST_DEFAULT_LAYER_KEYCODE + 7)

                } else if (mods & MOD_MASK_CTRL) {
                    set_single_persistent_default_layer(keycode - FIRST_DEFAULT_LAYER_KEYCODE + 8);
#    endif
#endif
                }
            }
            break;

        case VRSN: // Prints firmware version
            if (record->event.pressed) {
                send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
            }
            break;

//         case KC_DIABLO_CLEAR:  // reset all Diablo timers, disabling them
// #ifdef TAP_DANCE_ENABLE
//             if (record->event.pressed) {
//                 for (uint8_t index = 0; index < 4; index++) {
//                     diablo_timer[index].key_interval = 0;
//                 }
//             }
// #endif  // TAP_DANCE_ENABLE
//             break;

        case KC_CCCV: // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) { // Hold, copy
                    tap_code16(LCTL(KC_C));
                } else { // Tap, paste
                    tap_code16(LCTL(KC_V));
                }
            }
            break;
        case KC_RGB_T: // This allows me to use underglow as layer indication, or as normal
#if defined(CUSTOM_RGBLIGHT) || defined(CUSTOM_RGB_MATRIX)
            if (record->event.pressed) {
                userspace_config.rgb_layer_change ^= 1;
                dprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                eeconfig_update_user(userspace_config.raw);
                if (userspace_config.rgb_layer_change) {
#    if defined(CUSTOM_RGB_MATRIX)
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW | LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR | LED_FLAG_MODIFIER);
#        if defined(CUSTOM_RGBLIGHT)
                    rgblight_enable_noeeprom();
#        endif
#    endif
                    layer_state_set(layer_state); // This is needed to immediately set the layer color (looks better)
#    if defined(CUSTOM_RGB_MATRIX)
                } else {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
#        if defined(CUSTOM_RGBLIGHT)
                    rgblight_disable_noeeprom();
#        endif
#    endif
                }
            }
#endif // CUSTOM_RGBLIGHT
            break;

#if defined(CUSTOM_RGBLIGHT) || defined(CUSTOM_RGB_MATRIX)
#    ifdef USER_RGB_TOGGLE_KEYCODE
        case USER_RGB_TOGGLE_KEYCODE:
            // Split keyboards need to trigger on key-up for edge-case issue
#    ifndef SPLIT_KEYBOARD
            if (record->event.pressed) {
#    else
            if (!record->event.pressed) {
#    endif
#    if defined(CUSTOM_RGBLIGHT) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                rgblight_toggle();
#    endif
#    if defined(CUSTOM_RGB_MATRIX) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                rgb_matrix_toggle();
#    endif
            }
            return false;
            break;
#    endif
#    ifdef RGB_MODE_FORWARD
        case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT:
#    endif
#    ifdef UG_NEXT
        case UG_NEXT:
        case UG_PREV:
        case UG_HUEU:
        case UG_HUED:
        case UG_SATU:
        case UG_SATD:
        case UG_VALU:
        case UG_VALD:
        case UG_SPDU:
        case UG_SPDD:
#    endif
            if (record->event.pressed) {
                bool is_eeprom_updated = false;
#    if defined(CUSTOM_RGBLIGHT) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                // Disable layer indication when manually changing RGB modes.
                if (userspace_config.rgb_layer_change) {
                    userspace_config.rgb_layer_change = false;
                    dprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                    is_eeprom_updated = true;
                }
#    endif
#    if defined(CUSTOM_RGB_MATRIX) && defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
                if (userspace_config.rgb_matrix_idle_anim) {
                    userspace_config.rgb_matrix_idle_anim = false;
                    dprintf("RGB Matrix Idle Animation [EEPROM]: %u\n", userspace_config.rgb_matrix_idle_anim);
                    is_eeprom_updated = true;
                }
#    endif
                if (is_eeprom_updated) {
                    eeconfig_update_user(userspace_config.raw);
                }
            }
            break;
#endif
        case KEYLOCK: {
            static host_driver_t *host_driver = 0;
            if (record->event.pressed) {
                if (host_get_driver()) {
                    host_driver = host_get_driver();
                    clear_keyboard();
                    host_set_driver(0);
                    host_driver_disabled = true;
                } else {
                    host_set_driver(host_driver);
                    host_driver_disabled = false;
                }
            }
            break;
        }
        case CARET:
            if (record->event.pressed) {
                is_caret ^= 1;
            }
            break;
        case NX_TAB:
            if (record->event.pressed) {
                tap_code16(C(KC_TAB));
                USER_HAPTIC_PULSE();
            }
            break;
        case BK_TAB:
            if (record->event.pressed) {
                tap_code16(S(C(KC_TAB)));
                USER_HAPTIC_PULSE();
            }
            break;
        case RAISE_TOGGLE:
            if (record->event.pressed) {
                layer_invert(_RAISE);
            }
        break;
        case BSPC_LSFT_CLEAR:
            if (record->event.pressed) {
                tap_code16(KC_END);
                tap_code16(C(KC_LEFT));
                tap_code_delay(KC_BSPC, 5);
            }
        break;
        case BACKLU:
            if (record->event.pressed) {
                tap_code16(C(S(KC_LEFT)));
                tap_code16(KC_BSPC);
            }
        break;
        case UNDO:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_Z));
            }
        break;
        case REDO:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_Y));
            }
        break;
        case ENTER:
        if (record->event.pressed) {
                tap_code16(KC_ENTER);
            }
        break;
        case CUT:
            if (record->event.pressed) {
                tap_code16(C(KC_X));
            }
        break;
        case COPY:
            if (record->event.pressed) {
                tap_code16(C(KC_C));
            }
        break;
        case PASTE:
            if (record->event.pressed) {
                tap_code16(C(KC_V));
            }
        break;
        case KEYPAD:
            if (record->event.pressed) {
                layer_invert(_KEYPAD);
            }
            break;
        case LOWER_TOGGLE:
            if (record->event.pressed) {
                layer_invert(_LOWER);
            }
        break;
        case GAMEPAD_TOGGLE:
            if (record->event.pressed) {
                layer_invert(_GAMEPAD);
            }
        break;
        case LPAREN:
            if (record->event.pressed) {
                tap_code16(KC_LPRN);
            }
        break;
        case RPAREN:
            if (record->event.pressed) {
                tap_code16(KC_RPRN);
            }
        break;
        case WBACK:
            if (record->event.pressed) {
                tap_code16(KC_WBAK);
            }
        break;
        case WFWD:
        if (record->event.pressed) {
                tap_code16(KC_WFWD);
            }
        break;
        case NEXTSEN:
            if (record->event.pressed) {
            SEND_STRING(". ");
            add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
            }
        break;
        case NEGATIVEPASTE:
            if (record->event.pressed) {
            SEND_STRING("-");
            tap_code16(C(KC_V));
            }
        break;
        case AM_TOGGLE:
            if(record->event.pressed) { // key down
                auto_mouse_layer_off(); // disable target layer if needed
                set_auto_mouse_enable((AUTO_MOUSE_ENABLED) ^ 1);
                auto_mouse_tg_off = !get_auto_mouse_enable();
            }
            break;
        case ALTTABF:
            if (record->event.pressed) {
                press_super_tab (false);
            }
            break;
        case ALTTABB:
            if (record->event.pressed) {
                press_super_tab (true);
            }
            break;
        case CTLTABF:
            if (record->event.pressed) {
                press_super_ctrl_tab (false);
            }
            break;
        case CTLTABB:
            if (record->event.pressed) {
                press_super_ctrl_tab (true);
            }
            break;
    }
    return true;
}

__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_record_keymap(keycode, record);
}
