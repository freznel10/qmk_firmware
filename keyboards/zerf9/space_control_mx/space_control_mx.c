/*

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

#include "space_control_mx.h"

// void keyboard_pre_init_sub(void) { setPinInputHigh(A0); }

// void matrix_scan_sub_kb(void) {
//     if (!readPin(A0)) {
//         reset_keyboard();
//     }
// }

// void bootmagic_lite(void) {
//     // We need multiple scans because debouncing can't be turned off.
//     matrix_scan();
// #if defined(DEBOUNCE) && DEBOUNCE > 0
//     wait_ms(DEBOUNCE * 2);
// #else
//     wait_ms(30);
// #endif
//     matrix_scan();

//     uint8_t row = BOOTMAGIC_LITE_ROW;
//     uint8_t col = BOOTMAGIC_LITE_COLUMN;

// #if defined(SPLIT_KEYBOARD) && defined(BOOTMAGIC_LITE_ROW_RIGHT) && defined(BOOTMAGIC_LITE_COLUMN_RIGHT)
//     if (!is_keyboard_left()) {
//         row = BOOTMAGIC_LITE_ROW_RIGHT;
//         col = BOOTMAGIC_LITE_COLUMN_RIGHT;
//     }
// #endif

//     if (matrix_get_row(row) & (1 << col) || !readPin(A0)) {
//         eeconfig_disable();
//         bootloader_jump();
//     }
// }


#ifdef USB_VBUS_PIN
bool usb_vbus_state(void) {
    setPinInputLow(USB_VBUS_PIN);
    wait_us(5);
    return readPin(USB_VBUS_PIN);
}
#endif

#ifdef RGB_MATRIX_ENABLE

#define XX NO_LED

led_config_t g_led_config = { {
// Key Matrix to LED Index
  // Left Hand
  { 0, 1, 2, 3, 4, 5, 6, XX },
  { 13, 12, 11, 10, 9, 8, 7, XX },
  { 14, 15, 16, 17, 18, 19, 20, XX},
  { 28, 27, 26, 25, 24, 23, 22, 21},
  { 29, 30, 31, 32, XX, 33, 34, 35},
  // Right Hand
  { 47, 48, 49, 50, 51, 52, 53, XX},
  { 60, 59, 58, 57, 56, 55, 54, XX},
  { 61, 62, 63, 64, 65, 66, 67, XX},
  { 75, 74, 73, 72, 71, 70, 69, 68 },
  { 76, 77, 78, 79, XX, 80, 81, 82},
}, {
  // LED Index to Physical Position
  // Left Hand
{15,16}, {30,16}, {45,16}, {60,16}, {75,16}, {90,16}, {105,16}, {150,16}, {165,16}, {180,16}, {195,16}, {210,16}, {225,16}, {240,16}, {15,32}, {30,32}, {45,32}, {60,32}, {75,32}, {90,32}, {105,32}, {120,32}, {150,32}, {165,32}, {180,32}, {195,32}, {210,32}, {225,32}, {240,32}, {15,48}, {30,48}, {45,48}, {60,48}, {75,48}, {105,48}, {120,48}, {135,48}, {150,48}, {165,48}, {180,48}, {195,48}, {210,48}, {225,48}, {240,48}, {45,64}, {60,64}, {75,64}, {90,64}, {105,64}, {120,64}, {135,64}, {150,64}, {165,64}, {180,64}, {195,64}, {210,64}, {225,64}, {240,64}, {15,80}, {45,80}, {60,80}, {75,80}, {90,80}, {105,80}, {120,80}, {135,80}, {150,80}, {165,80}, {180,80}, {195,80}, {210,80}, {240,80}, {15,16}, {30,16}, {45,16}, {60,16}, {75,16}, {90,16}, {105,16}, {150,16}, {165,16}, {180,16}, {195,16}, {210,16}, {225,16}, {240,16}, {15,32}, {30,32}, {45,32}, {60,32}, {75,32}, {90,32}, {105,32}, {120,32},
}, {
  // LED Index to Flag
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
} };
#endif


#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    // Left
    {{7,5},{6,5},{5,5},{4,5},{3,5},{2,5},{1,5},{0,5}},
    {{7,5},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6}},
    {{7,5},{6,5},{5,7},{4,7},{3,7},{2,7},{1,7},{0,7}},
    {{7,5},{6,5},{5,8},{4,8},{3,8},{2,8},{1,8},{0,8}},
    {{7,5},{6,5},{5,9},{4,9},{3,9},{2,9},{1,9},{0,9}},
    // Right
    {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0}},
    {{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1}},
    {{0,2},{1,2},{2,2},{3,2},{4,2},{5,2},{6,2},{7,2}},
    {{0,3},{1,3},{2,3},{3,3},{4,3},{5,3},{6,3},{7,3}},
    {{0,4},{1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{7,4}},
    }
#endif
