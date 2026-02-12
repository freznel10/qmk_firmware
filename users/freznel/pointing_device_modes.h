// Copyright 2026 Freznel B. Sta. Ana (@freznel10)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

#ifndef POINTING_DEFAULT_DIVISOR
#    define POINTING_DEFAULT_DIVISOR 64
#endif

#define PM_LEFT_DEVICE  0
#define PM_RIGHT_DEVICE 1

enum pointing_mode_direction {
    PD_UP = 0,
    PD_DOWN,
    PD_LEFT,
    PD_RIGHT,
};

enum pointing_mode_ids {
    PM_NONE = 0,
    PM_PRECISION,
    PM_DRAG,
    PM_CARET,
    PM_HISTORY,
    PM_VOL,
    PM_SAFE_RANGE,
    PM_BROW = PM_SAFE_RANGE,
    PM_RGB_MODE_VAL,
    PM_RGB_HUE_SAT,
    PM_RGB_SPEED,
    PM_WINDOW,
    PM_SWITCHER,
    PM_APP_2,
    PM_CUR_ACCEL,
    PM_BROWSER_CONTROL,
    PM_WIN_POS,
};

typedef struct {
    uint8_t id;
    int16_t x;
    int16_t y;
    uint8_t divisor;
} pointing_mode_t;

#define POINTING_MODE_LAYOUT(up, left, right, down) { (up), (left), (right), (down) }

#define QK_PM_MOMENTARY     0x7D00
#define QK_PM_MOMENTARY_MAX 0x7D0F
#define QK_PM_TOGGLE        0x7D10
#define QK_PM_TOGGLE_MAX    0x7D1F
#define QK_PM_CYCLE_DEVICES 0x7D20

#define PM_MO(mode) ((QK_PM_MOMENTARY) | ((mode)&0x0F))
#define PM_TG(mode) ((QK_PM_TOGGLE) | ((mode)&0x0F))

#define IS_QK_PM_MOMENTARY(code) ((code) >= QK_PM_MOMENTARY && (code) <= QK_PM_MOMENTARY_MAX)
#define IS_QK_PM_TOGGLE(code) ((code) >= QK_PM_TOGGLE && (code) <= QK_PM_TOGGLE_MAX)
#define GET_QK_PM_MODE(code) ((code)&0x0F)

extern const uint16_t pointing_device_mode_maps[][4];

uint8_t get_pointing_mode_id(void);
uint8_t get_toggled_pointing_mode_id(void);
void set_pointing_mode_id(uint8_t mode_id);
void toggle_pointing_mode_id(uint8_t mode_id);

uint8_t get_pointing_mode_device(void);
void set_pointing_mode_device(uint8_t device);
void pointing_mode_switch_hands(void);

void set_pointing_mode(pointing_mode_t pointing_mode);
pointing_mode_t get_pointing_mode(void);

uint8_t current_pointing_mode_divisor(void);
mouse_xy_report_t apply_divisor_xy(int16_t value);
int16_t multiply_divisor_xy(mouse_xy_report_t value);

void pointing_tap_codes(uint16_t up, uint16_t down, uint16_t left, uint16_t right);

bool pointing_mode_key_momentary(uint8_t mode_id, keyrecord_t *record);
bool pointing_mode_key_toggle(uint8_t mode_id, keyrecord_t *record);
report_mouse_t pointing_device_modes_task(report_mouse_t mouse_report);

uint8_t get_pointing_mode_divisor_user(uint8_t mode_id, uint8_t direction);
bool process_pointing_mode_user(pointing_mode_t pointing_mode, report_mouse_t *mouse_report);
