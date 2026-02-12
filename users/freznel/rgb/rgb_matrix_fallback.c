// Copyright 2026 Freznel B. Sta. Ana (@freznel10)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE

#    if !defined(RGB_MATRIX_LED_COUNT) && defined(DRIVER_LED_TOTAL)
#        define RGB_MATRIX_LED_COUNT DRIVER_LED_TOTAL
#    endif

#    if defined(RGB_MATRIX_LED_COUNT) && defined(MATRIX_ROWS) && defined(MATRIX_COLS)
__attribute__((weak)) led_config_t g_led_config = {{
    [0 ... MATRIX_ROWS - 1] = {[0 ... MATRIX_COLS - 1] = NO_LED}
}, {
    [0 ... RGB_MATRIX_LED_COUNT - 1] = {0, 0}
}, {
    [0 ... RGB_MATRIX_LED_COUNT - 1] = LED_FLAG_ALL
}};
#    endif

#endif
