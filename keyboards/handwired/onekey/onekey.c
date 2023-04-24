// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

void keyboard_post_init_kb(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
    keyboard_post_init_user();
}
const pointing_device_config_t pointing_device_configs[POINTING_DEVICE_COUNT] = {
    {.driver = &pmw3360_driver_spi_default, .config = &pmw3360_config_spi_default_left, .throttle = 1, .invert = INVERT_X},
    // {.driver = &pmw3360_driver_spi_default, .config = &pmw3360_config_spi_default_right, .throttle = 1, .invert = INVERT_X},
    {.driver = &ps2_trackpoint_driver_ps2_default, .config = &ps2_trackpoint_config_ps2_default, .throttle = 10,}

};
