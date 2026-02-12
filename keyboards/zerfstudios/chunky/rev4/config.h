// Copyright 2022 freznel10 (@freznel10)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define POINTING_MODES_NUM_DEVICES 2
    #ifdef POINTING_DEVICE_DRIVER_PMW3360
        #define PMW33XX_LIFTOFF_DISTANCE 0x03
        #define POINTING_DEVICE_INVERT_X
        #define POINTING_DEVICE_INVERT_X_RIGHT
        #define PMW33XX_CS_PIN GP14
    #endif //POINTING_DEVICE_DRIVER_PMW3360
#define MOUSE_SCROLL_EXTENDED_REPORT
// #define MOUSE_SCROLL_HIRES_ENABLE

// Trackpoint configuration (commented as reference during trackball migration):
// #define PS2_PIO_USE_PIO1
// #define PS2_MOUSE_X_MULTIPLIER 2
// #define PS2_MOUSE_Y_MULTIPLIER 2
// #define PS2_MOUSE_ENABLE_SCROLLING
// #define PS2_MOUSE_INIT_DELAY 1000
// #define PS2_MOUSE_ROTATE 90
// #define PS2_MOUSE_USE_REMOTE_MODE
