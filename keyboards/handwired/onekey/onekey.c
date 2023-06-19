// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "azoteq_iqs5xx.h"
#include "quantum.h"
#include "pointing_device.h"

void keyboard_post_init_kb(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
    keyboard_post_init_user();

#define AZOTEQ_IQS5XX_ADDRESS 0x74
#define AZOTEQ_IQS5XX_TIMEOUT_MS 10

}
const pointing_device_i2c_config_t azoteq_iqs5xx_i2c_config_custom = {.address = AZOTEQ_IQS5XX_ADDRESS, .timeout = AZOTEQ_IQS5XX_TIMEOUT_MS};

const pointing_device_config_t pointing_device_configs[POINTING_DEVICE_COUNT] = {
    {.driver = &azoteq_iqs5xx_driver_default, .config = &azoteq_iqs5xx_i2c_config_custom}
    // {.driver = &pmw3360_driver_spi_default, .config = &pmw3360_config_spi_default_right, .throttle = 1, .invert = INVERT_X},
    // {.driver = &ps2_trackpoint_driver_ps2_default, .config = &ps2_trackpoint_config_ps2_default, .throttle = 10,}
};
