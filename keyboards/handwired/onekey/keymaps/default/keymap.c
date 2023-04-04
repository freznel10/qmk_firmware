// Copyright 2020 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

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
