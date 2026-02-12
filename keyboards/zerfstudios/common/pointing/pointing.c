// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2022 Freznel B. Sta. Ana  (@freznel10) <freznel@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later


#include "pointing.h"
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/drv2605l.h"
#endif
#include "pointing_device_modes.h"

// static uint16_t mouse_debounce_timer = 0;
bool            enable_acceleration = false;
static bool     APP_ALT, APP_WIN;


#ifdef TAPPING_TERM_PER_KEY
#    define TAP_CHECK get_tapping_term(KC_BTN1, NULL)
#else
#    ifndef TAPPING_TERM
#        define TAPPING_TERM 200
#    endif
#    define TAP_CHECK TAPPING_TERM
#endif

__attribute__((weak)) void pointing_device_init_keymap(void) {}

void pointing_device_init_user(void) {
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
#endif
    pointing_device_init_keymap();
}

__attribute__((weak)) report_mouse_t pointing_device_task_keymap(report_mouse_t mouse_report) {
    return mouse_report;
}

//Pointing Device Modes
const uint16_t pointing_device_mode_maps[][4] = {
    // PM_BROW
    [0] = POINTING_MODE_LAYOUT(
                C(S(KC_PGUP)),
        C(S(KC_TAB)),       C(KC_TAB),
                C(S(KC_PGDN))
    ),
    // PM_RGB_MODE_VAL
    [1] = POINTING_MODE_LAYOUT(
                RGB_VAI,
        RGB_RMOD,        RGB_MOD,
                RGB_VAD
    ),
    // PM_RGB_HUE_SAT
    [2] = POINTING_MODE_LAYOUT(
                RGB_SAI,
        RGB_HUD,        RGB_HUI,
                RGB_SAD
    ),
    // PM_RGB_SPEED
    [3] = POINTING_MODE_LAYOUT(
                KC_NO,
        RGB_SPD,        RGB_SPI,
                KC_NO
    ),
    // PM_WINDOW
    [4] = POINTING_MODE_LAYOUT(
                G(KC_UP),
        G(KC_LEFT),      G(KC_RIGHT),
                G(KC_DOWN)
    ),
    // PM_SWITCHER : PM 11
    [5] = POINTING_MODE_LAYOUT(
                G(KC_UP),
        G(KC_LEFT),      G(KC_RIGHT),
                G(KC_DOWN)
    ),
    // ALT_TAB: PM 12
    [6] = POINTING_MODE_LAYOUT(
                KC_NO,
        KC_NO,        KC_NO,
                KC_NO
    ),
    // ACCEL: PM 13
    [7] = POINTING_MODE_LAYOUT(
                KC_NO,
        KC_NO,        KC_NO,
                KC_NO
    ),
    // Browser Control: PM14
    [8] = POINTING_MODE_LAYOUT(
                KC_NO,
        KC_WBAK,        KC_WFWD,
                KC_NO
    ),
    //Windows Positioning: PM15
    [9] = POINTING_MODE_LAYOUT(
                KC_NO,
        KC_NO,        KC_NO,
                KC_NO
    )
};

uint8_t get_pointing_mode_divisor_user(uint8_t mode_id, uint8_t direction) {
    switch(mode_id) {
        case PM_BROW:
            // half speed for vertical axis
            return direction < PD_LEFT ? 128 : 64;
        case PM_RGB_MODE_VAL:
            // half speed for horizontal axis
            return direction < PD_LEFT ? 64 : 128;
        case PM_RGB_HUE_SAT:
            // example of unique divisor for each mode (not actually recommended for this mode (64 would be a good divisor here))
            switch(direction) {
                case PD_DOWN:
                    return 32;
                case PD_UP:
                    return 64;
                case PD_LEFT:
                    return 16;
                case PD_RIGHT:
                    return 128;
            }
        case PM_RGB_SPEED:
            return 64; // could skip adding this if default if POINTING_DEFAULT_DIVISOR is 64
        case PM_WINDOW:
            return 128;
        case PM_SWITCHER:
            return 64;
        case PM_CUR_ACCEL:
            return 8;
        case PM_APP_2:
            return 64;
        case PM_BROWSER_CONTROL:
            return 64;
        case PM_WIN_POS:
            return 128; // could skip adding this if default if POINTING_DEFAULT_DIVISOR is 64
    }

    return 0; // returning 0 to let processing of divisors continue
}


#define CONSTRAIN_XY(amt) ((amt) < XY_REPORT_MIN ? XY_REPORT_MIN : ((amt) > XY_REPORT_MAX ? XY_REPORT_MAX : (amt)))

bool process_pointing_mode_user(pointing_mode_t pointing_mode, report_mouse_t* mouse_report) {
    switch(pointing_mode.id){
        /** Manipulate browser tabs (win/linux) (switch to left tab, move tab left, move tab right, switch to right tab)
         *  Note that this mode could be put in a mode map but is here as an example of going past the bottom support 10 modes
         *  without overwriting any built in modes
         */
        // Manipulating pointing_mode & mouse_report (cursor speed boost mode example)
        case PM_CUR_ACCEL:
            // reset mouse_report note tha mouse_report is a pointer in this function's context
            *mouse_report = pointing_device_get_report();
#ifdef POINTING_DEVICE_INVERT_H
            // add linear boost to cursor x speed
            mouse_report->x = CONSTRAIN_XY(mouse_report->x - pointing_mode.x / pointing_mode.divisor);
#else
            mouse_report->x = CONSTRAIN_XY(mouse_report->x + pointing_mode.x / pointing_mode.divisor);
#endif
            // collect residuals
            pointing_mode.x = 0;
            // add linear boost to cursor y speed
#ifdef POINTING_DEVICE_INVERT_V
            mouse_report->y = CONSTRAIN_XY(mouse_report->y - pointing_mode.y / pointing_mode.divisor);
#else
            mouse_report->y = CONSTRAIN_XY(mouse_report->y + pointing_mode.y / pointing_mode.divisor);
#endif
            // collect residuals
            pointing_mode.y = 0;
            // update pointing_mode with residual stored x & y
            set_pointing_mode(pointing_mode);
            // NOTE: mouse_report does not need to be set or sent here as it will be carried forward
            return false; // stop pointing mode processing

        // Alternative method for app scrolling that only toggles ALT key when there is movement and holds until key release
        case PM_APP_2:
            // activate alt key if greater/equal to divisor and set flag
            if((abs(pointing_mode.x)) >= pointing_mode.divisor && !APP_ALT) {
                register_code(KC_LALT);
                APP_ALT = true;
            }
            pointing_tap_codes(S(KC_TAB), KC_NO, KC_NO, KC_TAB);
            return false;
        case PM_WIN_POS:
            if((abs(pointing_mode.x)) >= pointing_mode.divisor && !APP_WIN) {
                register_code(KC_LGUI);
                APP_WIN = true;
            }
            pointing_tap_codes(KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT);
            return false;
    }
    return true;
}


bool process_record_pointing(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_ACCEL:
            enable_acceleration = record->event.pressed;
            break;
#ifdef HAPTIC_ENABLE
        case TD_DRGS:
            drv2605l_pulse(medium_click1);
            break;
        case KC_BTN1:
            drv2605l_pulse(medium_click1);
            break;
#endif
        case KB_MO_APP:
        // toggle Alt key off on key release and reset flag
            if(!record->event.pressed && APP_ALT) {
                unregister_code(KC_LALT);
                APP_ALT = false;
            }
            pointing_mode_key_momentary(PM_APP_2, record);
        break;
        case KB_TG_ACCEL:
            pointing_mode_key_toggle(PM_CUR_ACCEL, record);
        break; // continue key record processing
        case KB_MO_WINDOW:
            if(!record->event.pressed && APP_WIN) {
                unregister_code(KC_LGUI);
                APP_WIN = false;
            }
            pointing_mode_key_momentary(PM_WIN_POS, record);
        break;
        case PM_SWITCH:
            if (record->event.pressed) {
                pointing_mode_switch_hands();
            }
        break;
        default:
        break;


    }
    return true;
}

#if defined(POINTING_DEVICE_AUTO_MOUSE_ENABLE)
bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
#    if defined(KEYBOARD_ploopy)
        case DPI_CONFIG:
#    elif (defined(KEYBOARD_bastardkb_charybdis) || defined(KEYBOARD_handwired_tractyl_manuform)) && !defined(NO_CHARYBDIS_KEYCODES)
        case SAFE_RANGE ...(CHARYBDIS_SAFE_RANGE - 1):
#    elif (defined(KEYBOARD_bastardkb_dilemma) && !defined(NO_DILEMMA_KEYCODES))
        case SAFE_RANGE ...(DILEMMA_SAFE_RANGE - 1):
// #    elif (defined(KEYBOARD_emblem) && !defined(NO_EMBLEM_KEYCODES))
//         case SAFE_RANGE ...(EMBLEM_SAFE_RANGE - 1):
#    endif
        case KC_ACCEL:
        case TD_DRGS:
        case TD_DRGR:
        case BK_TAB:
        case NX_TAB:
        case TD_PMD1:
        case ST_MACRO_6:
        case KB_MO_WINDOW:
        case KB_MO_APP:
        return true;
    }
    return false;
}
#endif

