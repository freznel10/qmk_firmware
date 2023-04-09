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

#define TRACKBALL_DPI_OPTIONS {100, 200, 300, 400, 512, 800, 1024, 1600, 2048, 3200, 6400}

#define DEBOUNCE 5
#define COMBO_VARIABLE_LEN
#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_ONLY_FROM_LAYER 1
#define TAPPING_TERM 240

#define DEBUG_MATRIX_SCAN_RATE
//#define QUANTUM_PAINTER_DEBUG

#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 2047

#define VIAL_KEYBOARD_UID {0xB3, 0x9D, 0x81, 0xE4, 0xF4, 0x30, 0xD8, 0x7E}

#define VIAL_UNLOCK_COMBO_ROWS {0, 6}
#define VIAL_UNLOCK_COMBO_COLS {0, 0}
