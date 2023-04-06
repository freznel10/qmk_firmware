// Copyright 2020 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "pmw3360.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_A)
};


#define BASE_ENCODERS {ENCODER_CCW_CW(KC_A, KC_B)}
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0]= BASE_ENCODERS
};

void keyboard_post_init_user(void) {
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard=true;
    debug_mouse =true;

}


const pointing_device_spi_config_t pmw3360_config_spi_default_right = {.cs =  PMW33XX_CS_PIN, .mode = 3, .divisor = PMW33XX_SPI_DIVISOR};

const pointing_device_config_t pointing_device_configs[POINTING_DEVICE_COUNT] = {
    // {.driver = &pmw3360_driver_spi_default, .config = &pmw3360_config_spi_default_left, .throttle = 1, .invert = INVERT_X},
    {.driver = &pmw3360_driver_spi_default, .config = &pmw3360_config_spi_default_right, .throttle = 1, .invert = INVERT_X}
};
