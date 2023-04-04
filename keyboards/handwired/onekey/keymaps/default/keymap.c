// Copyright 2020 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_A)
};


const pointing_device_config_t pointing_device_configs[POINTING_DEVICE_COUNT] = {
    {.driver = &cirque_driver_i2c_default, .config = &cirque_config_i2c_default},
    {.driver = &pmw3360_driver_spi_default, .config = &pmw3360_config_spi_default, .throttle = 1, .rotation = ROTATE_0, .invert = INVERT_X}
};
