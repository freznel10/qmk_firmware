// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2022 Freznel B. Sta. Ana  (@freznel10) <freznel@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later


#include "pointing.h"
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif

static uint16_t mouse_debounce_timer = 0;
bool            is_drag_mom = false, scrolling_mode = false, is_media = false, enable_acceleration = false;

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

// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     mouse_xy_report_t x = mouse_report.x, y = mouse_report.y;
//     mouse_report.x = 0;
//     mouse_report.y = 0;

//     if (x != 0 && y != 0 && (timer_elapsed(mouse_debounce_timer) > TAP_CHECK)) {
// #ifdef OLED_ENABLE
//         oled_timer_reset();
// #endif
//         if (enable_acceleration) {
//             x = (mouse_xy_report_t)(x > 0 ? x * x / 16 + x : -x * x / 16 + x);
//             y = (mouse_xy_report_t)(y > 0 ? y * y / 16 + y : -y * y / 16 + y);
//         }
//         mouse_report.x = x;
//         mouse_report.y = y;
//     }
//     return pointing_device_task_keymap(mouse_report);
// }

bool process_record_pointing(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_ACCEL:
            enable_acceleration = record->event.pressed;
            break;
#ifdef HAPTIC_ENABLE
        case TD_DRGS:
            DRV_pulse(medium_click1);
            break;
        case KC_BTN1:
            DRV_pulse(medium_click1);
            break;
#endif
        default:
            mouse_debounce_timer = timer_read();
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
        case BK_TAB:
        case NX_TAB:
        case TD_PMD1:
        return true;
    }
    return false;
}
#endif
