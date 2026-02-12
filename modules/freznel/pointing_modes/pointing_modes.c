// Copyright 2026 Freznel B. Sta. Ana (@freznel10)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdlib.h>

#include "../../../users/freznel/pointing_device_modes.h"

ASSERT_COMMUNITY_MODULES_MIN_API_VERSION(1, 1, 0);

#ifndef POINTING_MODE_DEFAULT
#    define POINTING_MODE_DEFAULT PM_NONE
#endif

#ifndef POINTING_DEFAULT_DIVISOR
#    define POINTING_DEFAULT_DIVISOR 64
#endif

typedef struct {
    uint8_t active_mode_id;
    uint8_t toggled_mode_id;
    uint8_t mode_device;
    int16_t x;
    int16_t y;
    uint8_t divisor;
} pointing_mode_runtime_t;

static pointing_mode_runtime_t g_pm = {
    .active_mode_id  = POINTING_MODE_DEFAULT,
    .toggled_mode_id = POINTING_MODE_DEFAULT,
    .mode_device     = PM_RIGHT_DEVICE,
    .x               = 0,
    .y               = 0,
    .divisor         = POINTING_DEFAULT_DIVISOR,
};

__attribute__((weak)) uint8_t get_pointing_mode_divisor_user(uint8_t mode_id, uint8_t direction) {
    return 0;
}

__attribute__((weak)) bool process_pointing_mode_user(pointing_mode_t pointing_mode, report_mouse_t *mouse_report) {
    return true;
}

__attribute__((weak)) const uint16_t pointing_device_mode_maps[][4] = {
    [0] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
    [1] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
    [2] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
    [3] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
    [4] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
    [5] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
    [6] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
    [7] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
    [8] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
    [9] = POINTING_MODE_LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO),
};

uint8_t get_pointing_mode_id(void) {
    return g_pm.active_mode_id;
}

uint8_t get_toggled_pointing_mode_id(void) {
    return g_pm.toggled_mode_id;
}

void set_pointing_mode_id(uint8_t mode_id) {
    g_pm.active_mode_id = mode_id;
}

void toggle_pointing_mode_id(uint8_t mode_id) {
    if (mode_id == PM_NONE) {
        g_pm.toggled_mode_id = PM_NONE;
        g_pm.active_mode_id  = PM_NONE;
        return;
    }

    if (g_pm.active_mode_id == mode_id) {
        g_pm.active_mode_id = PM_NONE;
        if (g_pm.toggled_mode_id == mode_id) {
            g_pm.toggled_mode_id = PM_NONE;
        }
        return;
    }

    g_pm.active_mode_id  = mode_id;
    g_pm.toggled_mode_id = mode_id;
}

uint8_t get_pointing_mode_device(void) {
    return g_pm.mode_device;
}

void set_pointing_mode_device(uint8_t device) {
    g_pm.mode_device = device ? PM_RIGHT_DEVICE : PM_LEFT_DEVICE;
}

void pointing_mode_switch_hands(void) {
    g_pm.mode_device = (g_pm.mode_device == PM_LEFT_DEVICE) ? PM_RIGHT_DEVICE : PM_LEFT_DEVICE;
}

void set_pointing_mode(pointing_mode_t pointing_mode) {
    g_pm.active_mode_id = pointing_mode.id;
    g_pm.x              = pointing_mode.x;
    g_pm.y              = pointing_mode.y;
    g_pm.divisor        = pointing_mode.divisor ? pointing_mode.divisor : POINTING_DEFAULT_DIVISOR;
}

pointing_mode_t get_pointing_mode(void) {
    return (pointing_mode_t){
        .id      = g_pm.active_mode_id,
        .x       = g_pm.x,
        .y       = g_pm.y,
        .divisor = g_pm.divisor ? g_pm.divisor : POINTING_DEFAULT_DIVISOR,
    };
}

uint8_t current_pointing_mode_divisor(void) {
    return g_pm.divisor ? g_pm.divisor : POINTING_DEFAULT_DIVISOR;
}

mouse_xy_report_t apply_divisor_xy(int16_t value) {
    const uint8_t divisor = current_pointing_mode_divisor();
    return (mouse_xy_report_t)(value / (int16_t)divisor);
}

int16_t multiply_divisor_xy(mouse_xy_report_t value) {
    const uint8_t divisor = current_pointing_mode_divisor();
    return (int16_t)value * (int16_t)divisor;
}

static uint8_t divisor_for_mode(uint8_t mode_id, uint8_t direction) {
    uint8_t divisor = get_pointing_mode_divisor_user(mode_id, direction);
    if (!divisor) {
        divisor = POINTING_DEFAULT_DIVISOR;
    }
    return divisor;
}

void pointing_tap_codes(uint16_t up, uint16_t down, uint16_t left, uint16_t right) {
    if (abs(g_pm.x) >= current_pointing_mode_divisor()) {
        if (g_pm.x > 0 && right != KC_NO) {
            tap_code16(right);
            g_pm.x -= multiply_divisor_xy(apply_divisor_xy(g_pm.x));
        } else if (g_pm.x < 0 && left != KC_NO) {
            tap_code16(left);
            g_pm.x -= multiply_divisor_xy(apply_divisor_xy(g_pm.x));
        }
    }

    if (abs(g_pm.y) >= current_pointing_mode_divisor()) {
        if (g_pm.y > 0 && down != KC_NO) {
            tap_code16(down);
            g_pm.y -= multiply_divisor_xy(apply_divisor_xy(g_pm.y));
        } else if (g_pm.y < 0 && up != KC_NO) {
            tap_code16(up);
            g_pm.y -= multiply_divisor_xy(apply_divisor_xy(g_pm.y));
        }
    }
}

bool pointing_mode_key_momentary(uint8_t mode_id, keyrecord_t *record) {
    if (record->event.pressed) {
        set_pointing_mode_id(mode_id);
    } else {
        set_pointing_mode_id(get_toggled_pointing_mode_id());
    }
    return false;
}

bool pointing_mode_key_toggle(uint8_t mode_id, keyrecord_t *record) {
    if (record->event.pressed) {
        toggle_pointing_mode_id(mode_id);
    }
    return false;
}

report_mouse_t pointing_device_modes_task(report_mouse_t mouse_report) {
    const uint8_t mode_id = get_pointing_mode_id();

    if (mode_id == PM_NONE || mode_id < PM_SAFE_RANGE || mode_id > PM_WIN_POS) {
        return mouse_report;
    }

    g_pm.x = mouse_report.x;
    g_pm.y = mouse_report.y;

    if (abs(g_pm.x) >= abs(g_pm.y)) {
        g_pm.divisor = divisor_for_mode(mode_id, g_pm.x >= 0 ? PD_RIGHT : PD_LEFT);
    } else {
        g_pm.divisor = divisor_for_mode(mode_id, g_pm.y >= 0 ? PD_DOWN : PD_UP);
    }

    pointing_mode_t pointing_mode = {
        .id      = mode_id,
        .x       = g_pm.x,
        .y       = g_pm.y,
        .divisor = g_pm.divisor,
    };

    if (!process_pointing_mode_user(pointing_mode, &mouse_report)) {
        return mouse_report;
    }

    const uint16_t *mode_map = pointing_device_mode_maps[mode_id - PM_SAFE_RANGE];
    pointing_tap_codes(mode_map[0], mode_map[3], mode_map[1], mode_map[2]);

    mouse_report.x = 0;
    mouse_report.y = 0;
    return mouse_report;
}

void pointing_device_init_pointing_modes(void) {
    pointing_device_init_pointing_modes_kb();

    g_pm.active_mode_id  = POINTING_MODE_DEFAULT;
    g_pm.toggled_mode_id = POINTING_MODE_DEFAULT;
    g_pm.mode_device     = PM_RIGHT_DEVICE;
    g_pm.x               = 0;
    g_pm.y               = 0;
    g_pm.divisor         = POINTING_DEFAULT_DIVISOR;
}

report_mouse_t pointing_device_task_pointing_modes(report_mouse_t mouse_report) {
    mouse_report = pointing_device_task_pointing_modes_kb(mouse_report);
    return pointing_device_modes_task(mouse_report);
}

bool process_record_pointing_modes(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_pointing_modes_kb(keycode, record)) {
        return false;
    }

    if (IS_QK_PM_MOMENTARY(keycode)) {
        return pointing_mode_key_momentary(GET_QK_PM_MODE(keycode), record);
    }

    if (IS_QK_PM_TOGGLE(keycode)) {
        return pointing_mode_key_toggle(GET_QK_PM_MODE(keycode), record);
    }

    if (keycode == QK_PM_CYCLE_DEVICES && record->event.pressed) {
        pointing_mode_switch_hands();
        return false;
    }

    return true;
}
