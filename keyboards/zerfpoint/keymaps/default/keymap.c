/* Copyright 2022 Freznel B. Sta. Ana (@freznel10) <freznel@gmail.com>
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


#include QMK_KEYBOARD_H

enum keyboard_layers {
    _BL, // Base Layer
    _ML, // Base Layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_default(QK_BOOT, KC_MRWD, KC_MPLY, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN2, KC_BTN2, KC_BTN1, KC_BTN1, KC_BTN3),
    [_ML] = LAYOUT_default(KC_MFFD, KC_MRWD, KC_MPLY, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_BTN3)
};

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse = false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  return true;
}

// static uint16_t mh_auto_buttons_timer;
// extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

// void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
//   if (mh_auto_buttons_timer) {
//     mh_auto_buttons_timer = timer_read();
//   } else {
//     if (!tp_buttons) {
//       layer_on(_ML);
//       mh_auto_buttons_timer = timer_read();
//   #if defined CONSOLE_ENABLE
//       print("mh_auto_buttons: on\n");
//   #endif
//     }
//   }
// }

// void matrix_scan_user(void) {
//   if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > 750)) {
//     if (!tp_buttons) {
//       layer_off(_ML);
//       mh_auto_buttons_timer = 0;
//   #if defined CONSOLE_ENABLE
//       print("mh_auto_buttons: off\n");
//   #endif
//     }
//   }
// }
