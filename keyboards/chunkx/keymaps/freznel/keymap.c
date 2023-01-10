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

#include "freznel.h"
#include "autocorrect_data.h"
#include <math.h>
#include <stdio.h>
#include "ctype.h"
#include "color.h"
#include <qp.h>
#ifdef OS_DETECTION_ENABLE
#include "os_detection.h"
#endif
#include  "g/keymap_combo.h"

#    include "pointing_device_modes.h"
#include "pointing_device.h"
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif

#include "spi_master.h"

#define DRAGSCROLL_PADDING 6
#define DQT QK_DEBUG_TOGGLE
#define KC_CTUP C(KC_PGUP)
#define KC_CTDN C(KC_PGDN)
#define KC_ADEL LALT_T(KC_DEL)
#define KC_SBT3 S(KC_BTN3)
#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

enum custom_keycodes {
  ST_MACRO_0 = NEW_SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
};

// clang-format off

#define LAYOUT_chunkx_wrapper(...) LAYOUT_chunkx(__VA_ARGS__)
#define LAYOUT_chunkx_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_chunkx_wrapper( \
    KC_MINUS,  ________________NUMBER_LEFT________________,                        KC_BTN3,                                KC_BTN3,     ________________NUMBER_RIGHT_______________, KC_EQUAL, \
    KC_RGB_T,         K01,         K02,          K03,         K04,        K05,     KC_BTN2,                                KC_BTN2,     K06,     K07,     K08,     K09,     K0A,     EE_CLR, \
    RGB_TOG1, LGUI_T(K11), LALT_T(K12),  LCTL_T(K13), LSFT_T(K14),        K15,     KC_BTN1,                                KC_BTN1,     K16,     RSFT_T(K17),     RCTL_T(K18),     RALT_T(K19),     RGUI_T(K1A),     RALT_T(K1B), \
    LALT_T(KC_DEL), LCTL_T(K21),  K22,          K23,          K24,        K25,     TD_DRGS,       C_R,        SELWORD,     ALT_TAB,     K26,     K27,     K28,     K29, RCTL_T(K2A), KC_BSLS, \
    QK_RBT,  KC_HOME,        KC_END,      KC_PAGE_DOWN,   KC_PGUP,           TAB_RSE, SPC_LSH,   ENT_LWR,        ESC_LWR,    BSP_RSH,     DEL_RSE, KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, QK_RBT, \
                                                                        QK_RBT,   QK_RBT, QK_RBT, QK_RBT,   QK_RBT, QK_RBT\
)
#define LAYOUT_base_wrapper(...) LAYOUT_chunkx_base(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT_LAYER_1] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_DEFAULT_LAYER_2] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),
    [_DEFAULT_LAYER_3] = LAYOUT_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_DEFAULT_LAYER_4] = LAYOUT_base_wrapper(
        _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
        _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
        _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
    ),

    [_MOUSE] = LAYOUT_chunkx(
        _______,    _______,    _______,    _______,     _______,   _______,    _______,                                _______,    KC_WH_U, _______,    _______, _______, _______, _______,
        _______, C(S(KC_L)),    KC_WH_D,    KC_WH_U,      KC_ESC,   _______,    _______,                                _______,    KC_WH_U, KC_WH_D, S(KC_BTN3), KC_WH_U, _______, _______,
        _______,    S(KC_P),    KC_BTN2,    KC_BTN1,     KC_BTN3,   KC_BTN4,    _______,                                _______,    KC_WH_D, KC_LEFT, KC_BTN2,    KC_BTN1, KC_BTN3, _______,
        _______,    _______,    _______,    _______,     _______,   _______,    _______,    _______,       _______,     _______,    KC_BTN7, KC_BTN4, KC_BTN5, KC_BTN8, _______, _______,
        _______,    _______,    _______,    _______,     _______,   _______,    _______,    _______,       _______,     _______,    _______, _______, _______, _______, _______, _______,
                                                                    _______,    _______,    _______,       _______,     _______,    _______
    ),
    [_MEDIA] = LAYOUT_chunkx(
        _______,    _______,    _______,    _______,     _______,   _______,    _______,                                _______,    KC_WH_U, _______,    _______, _______, _______, _______,
        _______, C(S(KC_L)),    KC_WH_D,    KC_WH_U,      KC_ESC,   _______,    _______,                                _______,    KC_WH_U, KC_WH_D, S(KC_BTN3), KC_WH_U, _______, _______,
        _______,    S(KC_P),    KC_BTN2,    KC_BTN1,     KC_BTN3,   KC_BTN4,    _______,                                _______,    KC_WH_D, KC_LEFT, KC_BTN2,    KC_BTN1, KC_BTN3, _______,
        _______,    _______,    _______,    _______,     _______,   _______,    _______,    _______,       _______,     _______,    KC_BTN7, KC_BTN4, KC_BTN5, KC_BTN8, _______, _______,
        _______,    _______,    _______,    _______,     _______,   _______,    _______,    _______,       _______,     _______,    _______, _______, _______, _______, _______, _______,
                                                                    _______,    _______,    _______,       _______,     _______,    _______
    ),
    [_LOWER] = LAYOUT_chunkx_wrapper(
       KC_F12,  _________________FUNC_LEFT_________________, _______,                       _______, _________________FUNC_RIGHT________________, KC_F11,
       KC_CAPS, _________________LOWER_L1__________________, _______,                       _______, _________________LOWER_R1__________________, _______,
       _______, _________________LOWER_L2__________________, _______,                       _______, _________________LOWER_R2__________________, KC_PIPE,
       _______, _________________LOWER_L3__________________, _______, _______,     _______, _______, _________________LOWER_R3__________________, _______,
       _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  _______, _______,
                                                    _______, _______, _______,     _______, _______, _______

    ),
    [_RAISE] = LAYOUT_chunkx_wrapper(
       KC_F12,  _________________FUNC_LEFT_________________, _______,                       _______, _________________FUNC_RIGHT________________, KC_F11,
       _______, _________________RAISE_L1__________________, _______,                       _______, _________________RAISE_R1__________________, _______,
       _______, _________________RAISE_L2__________________, _______,                       _______, _________________RAISE_R2__________________, KC_BSLS,
       _______, _________________RAISE_L3__________________, _______, _______,     _______, _______, _________________RAISE_R3__________________, _______,
       _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  _______, _______,
                                                    _______, _______, _______,     _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_chunkx_wrapper(
       QK_MAKE, _________________FUNC_LEFT_________________, _______,                                _______, _________________FUNC_RIGHT________________, QK_BOOT,
       EE_CLR,  _________________ADJUST_L1_________________, _______,                                _______, _________________ADJUST_R1_________________, QK_RBT,
       KEYLOCK, _________________ADJUST_L2_________________, _______,                                _______, _________________ADJUST_R2_________________, TG_MODS,
       UC_MOD,  _________________ADJUST_L3_________________, DPI_MOD, DPI_RMOD,             DRGSCRL, DQT,     _________________ADJUST_R3_________________, KC_MPLY,
       _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,  _______, _______,
                                                    _______, _______, _______,              _______, _______, _______
    ),
    [_KEYPAD] = LAYOUT_chunkx_wrapper(
       QK_MAKE, KC_WIDE,KC_AUSSIE,KC_SCRIPT,KC_ZALGO,KC_NOMODE, _______,                             _______, _________________FUNCA_RIGHT_______________, QK_MAKE,
       VRSN,    ________________NUMPAD1_LEFT_______________ , KC_NUM,                               _______, _________________ADJUST_R1_________________, QK_RBT,
       KEYLOCK, ________________NUMPAD2_LEFT_______________,  KC_BSPC,                               _______, _________________ADJUST_R2_________________, SH_TG,
       UC_MOD,  ________________NUMPAD3_LEFT_______________ , SNIPING, SNP_TOG,             DRGSCRL,  _______, _________________ADJUST_R3_________________, KC_MPLY,
       _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,  _______, _______,
                                               _______, _______, _______,              _______, _______, _______
    ),
    [_GAMEPAD] = LAYOUT_chunkx_wrapper(
       QK_MAKE, KC_WIDE,KC_AUSSIE,KC_SCRIPT,KC_ZALGO,KC_NOMODE, _______,                             _______, _________________FUNCA_RIGHT_______________, QK_MAKE,
       VRSN,    ________________NUMPAD1_LEFT_______________ , KC_NUM,                               _______, _________________ADJUST_R1_________________, QK_RBT,
       KEYLOCK, ________________NUMPAD2_LEFT_______________,  KC_BSPC,                               _______, _________________ADJUST_R2_________________, SH_TG,
       UC_MOD,  ________________NUMPAD3_LEFT_______________ , SNIPING, SNP_TOG,             DRGSCRL,  _______, _________________ADJUST_R3_________________, KC_MPLY,
       _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,  _______, _______,
                                               _______, _______, _______,              _______, _______, _______
    ),

};
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_2)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LCTL(SS_TAP(X_V)));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_BTN1) SS_TAP(X_END) SS_DELAY(100) SS_LCTL(SS_LSFT (SS_TAP(X_LEFT) SS_TAP(X_LEFT))) SS_DELAY(100) SS_LCTL("c"));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_DOWN))));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_UP))));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Y));

    }
    break;
    return false;
  }
  return true;
}



void matrix_init_custom(void) {
    // SPI Matrix
    setPinOutput(SPI_MATRIX_CHIP_SELECT_PIN);
    writePinHigh(SPI_MATRIX_CHIP_SELECT_PIN);
    spi_init();

}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    static matrix_row_t temp_matrix[MATRIX_ROWS] = {0};

    // Read from SPI the matrix
    spi_start(SPI_MATRIX_CHIP_SELECT_PIN, false, 0, SPI_MATRIX_DIVISOR);
    spi_receive((uint8_t*)temp_matrix, MATRIX_SHIFT_REGISTER_COUNT * sizeof(matrix_row_t));
    spi_stop();

    // Read from the encoder pushbutton
    // temp_matrix[5] = readPin(ENCODER_PUSHBUTTON_PIN) ? 1 : 0;

    // Check if we've changed, return the last-read data
    bool changed = memcmp(current_matrix, temp_matrix, sizeof(temp_matrix)) != 0;
    if (changed) {
        memcpy(current_matrix, temp_matrix, sizeof(temp_matrix));
    }
    return changed;
}

