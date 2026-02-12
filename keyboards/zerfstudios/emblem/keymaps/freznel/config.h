/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2021 Freznel B. Sta. Ana (freznel@gmail.com) (@freznel10)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef POINTING_DEVICE_DRIVER_PMW3360
#    define TRACKBALL_DPI_OPTIONS {100, 200, 300, 400, 512, 800, 1024, 1600, 2048, 3200, 6400}
#endif

#define DEBOUNCE 10
#define COMBO_VARIABLE_LEN
#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_ONLY_FROM_LAYER 1
#define TAPPING_TERM 240

// #define OLED_DISPLAY_128X128

#ifdef OLED_DRIVER_SH1107
#    undef OLED_DISPLAY_128X64
#endif

#define DEBUG_MATRIX_SCAN_RATE
//#define QUANTUM_PAINTER_DEBUG

