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
#include "pointing_device.h"
// #include "select_word.h"
#include "print.h"
#include <math.h>
#include <stdio.h>
#include "./users/freznel/split/transport_sync.h"
#include "spi_master.h"
#include "autocorrect_data.h"
// #include "qp_gc9a01.h"


#include  "g/keymap_combo.h"
#include <hal.h>
#ifdef HAPTIC_ENABLE
//#include "keyboards/zerf9/mx_track/haptic_utils.h"
#include "drivers/haptic/drv2605l.h"
#endif


#define DRAGSCROLL_PADDING 6
#define DQT QK_DEBUG_TOGGLE
#define ALT_DEL LALT_T(KC_DEL)
#define ________________UNICODE_MODE_______________ KC_WIDE,KC_AUSSIE,KC_SCRIPT,KC_ZALGO,KC_NOMODE

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
#define KC_POSR S(KC_P)
#define KC_INTR C(S(KC_COMMA))
#define DYN_000 DYN_MACRO_KEY00
#define DYN_001 DYN_MACRO_KEY01



enum custom_keycodes {
  ST_MACRO_0 = NEW_SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5
};


// clang-format off

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_MINUS,                           ________________NUMBER_LEFT________________,           KB_MO_WINDOW,                                                                    LO_RES_DOWN,                                            ________________NUMBER_RIGHT_______________,            KC_EQUAL, \
    DYN_000,           K01,            K02,            K03,            K04,        K05,        SELWORD,                                                                         LO_RES_UP,        K06,            K07,                K08,                K09,                K0A,            KC_BSPC, \
    DYN_001,   LGUI_T(K11),    LALT_T(K12),    LCTL_T(K13),    LSFT_T(K14),        K15,        PM_MO(11),                                                                       RGB_TOG1,        K16,    RSFT_T(K17),        RCTL_T(K18),        RALT_T(K19),        RGUI_T(K1A),        RALT_T(K1B), \
    ALT_DEL,    LCTL_T(K21),            K22,            K23,            K24,        K25,        KC_NUHS,        TD_DRGS,                        KC_BTN1,                        ALT_TAB,        C_R,            K26,                K27,                K28,                K29,         RCTL_T(K2A),   KC_BSLS, \
                                                                     KC_INS,        TAB_RSE,    SPC_LSH,        ENT_LWR,        KC_BTN2,        TD_DRGS,       KC_BTN2,         ESC_LWR,        BSP_KEY,    DEL_RSE,           SELWORD, \
                                       PB_1,          PB_2,            PB_3,            PB_4,    KC_MUTE,                                                                             PB_5,       PB_6,          PB_7,  PB_8,  KC_MUTE  \
)

#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)
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

    [_MOUSE] = LAYOUT(
        _______, KC_E, KC_WH_D, KC_WH_U, _______, _______, _______,                                                 _______, _______, _______, _______, _______, _______, _______,
        _______, S(KC_M), KC_WH_D, KC_WH_U, KC_ESC, PM_MO(4), _______,                                              _______, PM_MO(4), KC_ESC, KC_WH_U,  KC_WH_D, S(KC_M), _______,
        _______, KC_POSR, KC_BTN2, KC_BTN1, KC_BTN3, KB_MO_WINDOW, _______,                                              _______, KB_MO_WINDOW, KC_BTN2, KC_BTN1, KC_BTN3, KC_POSR, _______,
        _______, PM_MO(14), TD_PMD1, TD_DRGS, NX_TAB, PM_MO(6), _______, _______,          _______,          _______, _______, PM_MO(6), TD_PMD1, TD_DRGS, NX_TAB, KC_INTR, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______


    ),
    [_MEDIA] = LAYOUT(
        _______, KC_E, KC_WH_D, KC_WH_U, _______, _______, _______,                                                 _______, _______, _______, _______, _______, _______, _______,
        _______, S(KC_M), KC_WH_D, KC_WH_U,  KC_ESC, _______, _______,                                              _______, _______, KC_ESC, KC_WH_U,  KC_WH_D, S(KC_M), _______,
        _______, KC_POSR, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______,                                              _______, _______, KC_BTN2, KC_BTN1, KC_BTN3, KC_POSR, _______,
        _______, KC_INTR, _______, TD_DRGS, _______, _______, _______, _______,          _______,          _______, _______, _______, _______, TD_DRGS, _______, KC_INTR, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______


    ),
    [_LOWER] = LAYOUT_wrapper(
        KC_F12,  _________________FUNC_LEFT_________________, _______,                                              _______, _________________FUNC_RIGHT________________, KC_F11,
        KC_CAPS, _________________LOWER_L1__________________, _______,                                              _______, _________________LOWER_R2_ALT______________, _______,
        _______, _________________LOWER_L2__________________, _______,                                              _______, _________________LOWER_R1_ALT______________, KC_PIPE,
        _______, _________________LOWER_L3__________________, DRG_TOG, _______,          _______,          _______, _______, _________________LOWER_R3__________________, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______

    ),
    [_RAISE] = LAYOUT_wrapper(
       QK_BOOT,  _________________FUNC_LEFT_________________, _______,                                             _______, _________________FUNC_RIGHT________________, KC_F11,
       _______, _________________RAISE_L1__________________, _______,                                              _______, _________________RAISE_R1__________________, _______,
       _______, _________________RAISE_L2__________________, _______,                                              _______, _________________RAISE_R2__________________, KC_BSLS,
       _______, _________________RAISE_L3__________________, SNP_TOG, _______,          _______,          _______, _______, _________________RAISE_R3__________________, _______,
                                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                           _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______


    ),
    [_ADJUST] = LAYOUT_wrapper(
       QK_BOOT, _________________FUNC_LEFT_________________, _______,                                               _______, _________________FUNC_RIGHT________________, QK_RBT,
       EE_CLR,  _________________ADJUST_L1_________________, _______,                                               _______, _________________ADJUST_R1_________________, KC_EQUAL,
       KEYLOCK, _________________ADJUST_L2_________________, _______,                                               _______, _________________ADJUST_R2_________________, TG_MODS,
       AC_TOGG, _________________ADJUST_L3_________________,TG(_GAMEPAD), AML_TOG,          AML_TOG,           AML_TOG, DRGSCRL, _________________ADJUST_R3_________________, KC_MPLY,
                                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                           _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
    ),
    [_KEYPAD] = LAYOUT_wrapper(
       QK_MAKE, _________________UNICO_L1__________________, _______,                                               _______, _________________UNICO_R1__________________, QK_MAKE,
       KC_NUM,  ________________NUMPAD1_LEFT_______________, _______,                                               _______, _________________ADJUST_R1_________________, KC_EQUAL,
       KC_BSPC, ________________NUMPAD2_LEFT_______________, _______,                                               _______, _________________ADJUST_R2_________________, SH_TG,
       UC_CLUE, ________________NUMPAD3_LEFT_______________, KC_SCRL, AML_TOG,          AML_TOG,          AML_TOG, DRGSCRL, ________________NUMPAD3_RIGHT______________, KC_MPLY,
                                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                           _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
    ),
    [_GAMEPAD] = LAYOUT_wrapper(
       QK_GESC, ________________NUMBER_LEFT________________, KC_F1,                                            _______, ________________NUMBER_RIGHT_______________, QK_MAKE,
       KC_CAPS, _________________GAMING_L1_________________, KC_T,                                            _______, ______________COLEMAK_MOD_DH_R1____________, KC_EQUAL,
       KC_RSFT, _________________GAMING_L2_________________, KC_G,                                             _______, ______________COLEMAK_MOD_DH_R1____________, SH_TG,
       KC_RCTL, _________________GAMING_L2_________________, KC_B, TG(_GAMEPAD),        KC_BTN1,    AML_TOG, DRGSCRL, ______________COLEMAK_MOD_DH_R1____________, KC_MPLY,
                                           KC_LALT, KC_TAB, KC_SPACE, KC_ENTER, _______, KC_BTN2, _______, _______, _______, _______, _______,
                                           _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______
    )
};


#define BASE_ENCODERS { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }o
#define BASE_ENCODERS_EMBLEM { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(LVGL_COUNTER_CLOCKWISE, LVGL_CLOCKWISE), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
#ifdef ENCODER_MAP_ENABLE
#    if defined(KEYBOARD_zerfstudios_emblem)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_DEFAULT_LAYER_1] = BASE_ENCODERS_EMBLEM,
    [_DEFAULT_LAYER_2] = BASE_ENCODERS_EMBLEM,
    [_DEFAULT_LAYER_3] = BASE_ENCODERS_EMBLEM,
    [_DEFAULT_LAYER_4] = BASE_ENCODERS_EMBLEM,
    [_MOUSE] = BASE_ENCODERS_EMBLEM,
    [_MEDIA] = BASE_ENCODERS_EMBLEM,
    [_GAMEPAD]         = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [_KEYPAD]          = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [_RAISE]           = { ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(RGB_VAD, RGB_VAI)  },
    [_LOWER]           = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_ADJUST]          = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
};
#    elif defined(KEYBOARD_zerf9_mx_track)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_DEFAULT_LAYER_1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_D, KC_WH_U)},
    [_DEFAULT_LAYER_2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_D, KC_WH_U)},
    [_DEFAULT_LAYER_3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_D, KC_WH_U)},
    [_DEFAULT_LAYER_4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_D, KC_WH_U)},
    [_GAMEPAD]         = { ENCODER_CCW_CW(_______, _______ ),
    ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(_______, _______) },
    [_DIABLO]          = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(_______, _______)  },
    [_KEYPAD]          = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_MEDIA]           = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_RAISE]           = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_SPD, RGB_SPI), ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_LOWER]           = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_ADJUST]          = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif
// clang-format on
#else

deferred_token encoder_token  = INVALID_DEFERRED_TOKEN;
static int8_t  last_direction = -1;

static uint32_t encoder_callback(uint32_t trigger_time, void *cb_arg) {
    unregister_code(last_direction ? KC_WH_D : KC_WH_U);
    last_direction = -1;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
#    ifdef SWAP_HANDS_ENABLE
    if (swap_hands) {
        index ^= 1;
    }
#    endif
    if (index == 0) {
        tap_code_delay(clockwise ? KC_VOLD : KC_VOLU, 5);
    } else if (index == 1) {
        if (last_direction != clockwise || encoder_token == INVALID_DEFERRED_TOKEN) {
            uint8_t keycode = clockwise ? KC_WH_D : KC_WH_U;
            last_direction  = clockwise;
            if (encoder_token != INVALID_DEFERRED_TOKEN) {
                if (cancel_deferred_exec(encoder_token)) {
                    encoder_token = INVALID_DEFERRED_TOKEN;
                }
                unregister_code(clockwise ? KC_WH_U : KC_WH_D);
            }
            register_code(keycode);
            encoder_token = defer_exec(MOUSEKEY_WHEEL_DELAY + MOUSEKEY_WHEEL_INTERVAL, encoder_callback, NULL);
        } else {
            extend_deferred_exec(encoder_token, MOUSEKEY_WHEEL_INTERVAL);
        }
    }
    return false;
}
#endif
// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
//   return true;
// }




int max(int num1, int num2) { return (num1 > num2 ) ? num1 : num2; }
int min(int num1, int num2) { return (num1 > num2 ) ? num2 : num1; }
int8_t sign(int x) { return (x > 0) - (x < 0); }

uint8_t	carret_threshold = 1;
uint16_t cursor_multiplier = 5;
uint8_t	scroll_threshold = 1;
int16_t cur_factor;
int8_t last_v = 0;

// void matrix_scan_keymap(void) {
//         if (timer_elapsed(mouse_timer) > 650 && layer_state_is(_MOUSE) && !mouse_keycode_tracker && !tap_toggling) {
//             layer_off(_MOUSE);
//         }
//     if (tap_toggling) {
//         if (!layer_state_is(_MOUSE)) {
//             layer_on(_MOUSE);
//         }
//     }
// }

// report_mouse_t pointing_device_task_keymap(report_mouse_t mouse_report)  {
//     void tap_tb(uint8_t keycode0, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3) {
//         if(abs(mouse_report.x) + abs(mouse_report.y) >= cur_factor){
//             if(abs(mouse_report.x) > abs(mouse_report.y)) {
//                 if(mouse_report.x > 0) {
//                     for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
//                         tap_code(keycode0);
//                         mouse_report.x = max(mouse_report.x - cur_factor, 0);
//                     }
//                     mouse_report.y = 0;
//                 } else {
//                     for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
//                         tap_code(keycode1);
//                         mouse_report.x = min(mouse_report.x + cur_factor, 0);
//                     }
//                     mouse_report.y = 0;
//                 }
//             } else {
//                 if(mouse_report.y > 0) {
//                     for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
//                         tap_code(keycode2);
//                         mouse_report.y = max(mouse_report.y - cur_factor, 0);
//                         }
//                     mouse_report.x = 0;
//                 } else {
//                     for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
//                         tap_code(keycode3);
//                         mouse_report.y = min(mouse_report.y + cur_factor, 0);
//                     }
//                     mouse_report.x = 0;
//                 }
//             }
//         }
//     }
//     void tap_media(uint8_t keycode0, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3) {
//         if(abs(mouse_report.x) + abs(mouse_report.y) >= cur_factor){
//             if(abs(mouse_report.x) > abs(mouse_report.y)) {
//                 if(mouse_report.x > 0) {
//                     for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
//                         tap_code(keycode0);
//                         mouse_report.x = max(mouse_report.x - cur_factor, 0);
//                     }
//                     mouse_report.y = 0;
//                 } else {
//                     for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
//                         tap_code(keycode1);
//                         mouse_report.x = min(mouse_report.x + cur_factor, 0);
//                     }
//                     mouse_report.y = 0;
//                 }
//             } else {
//                 if(mouse_report.y > 0) {
//                     for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
//                         tap_code(keycode2);
//                         mouse_report.y = max(mouse_report.y - cur_factor, 0);
//                         }
//                     mouse_report.x = 0;
//                 } else {
//                     for (int8_t i = 0; i <= (abs(mouse_report.x) + abs(mouse_report.y)) / cur_factor; i++) {
//                         tap_code(keycode3);
//                         mouse_report.y = min(mouse_report.y + cur_factor, 0);
//                     }
//                     mouse_report.x = 0;
//                 }
//             }
//         }
//     }
//     if (scrolling_mode) {
//         mouse_report.h = mouse_report.x == 0 ? 0 : mouse_report.x > 0 ? 1 : -1;
//         mouse_report.v = mouse_report.y == 0 ? 0 : mouse_report.y > 0 ? 1 : -1;
//         mouse_report.x = 0;
//         mouse_report.y = 0;
//     }
//     if (is_caret) {
//         cur_factor = carret_threshold;
//         tap_tb(KC_RIGHT, KC_LEFT, KC_DOWN, KC_UP );

//     }
//         if (is_media) {
//         cur_factor = carret_threshold;
//         tap_media(KC_RIGHT, KC_LEFT, KC_DOWN, KC_UP );
//     }

//     if (is_drag_mom) {
//         cur_factor = scroll_threshold;
//         if(abs(mouse_report.x) + abs(mouse_report.y) >= cur_factor) {
//             if(abs(mouse_report.x) > abs(mouse_report.y)) {
//                 mouse_report.h = sign(mouse_report.x) * (abs(mouse_report.x) + abs(mouse_report.y)) / 2;
//             } else {
//                 mouse_report.v = sign(mouse_report.y) * (abs(mouse_report.x) + abs(mouse_report.y)) / 2; //* (sign(mouse_report.y)>0 ? 5 : 1) + (sign(mouse_report.y)==sign(last_v) ? last_v / 8 : 0);
//             }
//             last_v = mouse_report.v;
//             mouse_report.x = 0;
//             mouse_report.y = 0;
//         } else {
//             mouse_report.v = 0;
//             mouse_report.h = 0;
//         }
//     }
//     return mouse_report;
// }

// void keyboard_post_init_keymap(void) {
//     pointing_device_set_cpi_on_side(true, 100); //Set cpi on left side to a low value for slower scrolling.
//     pointing_device_set_cpi_on_side(false, 8000); //Set cpi on right side to a reasonable value for mousing.
// }


// void keyboard_post_init_keymap(void) {
//     //debug_enable = true;
//     //debug_matrix = true;
//     //debug_keyboard=true;
// }

// #ifdef OLED_ENABLE
// oled_rotation_t oled_init_keymap(oled_rotation_t rotation) { return OLED_ROTATION_180; }


layer_state_t layer_state_set_keymap(layer_state_t state) {
    if (get_toggled_pointing_mode_id() != get_pointing_mode_id()) {
        set_pointing_mode_id(get_toggled_pointing_mode_id());
    }
    switch (get_highest_layer(state)) {
        case _LOWER:
#ifdef HAPTIC_ENABLE
            drv2605l_pulse(soft_bump);
#endif
            set_pointing_mode_id(PM_VOL);
            break;
        case _RAISE:
#ifdef HAPTIC_ENABLE
            drv2605l_pulse(transition_rampup_short_sharp1_50);
#endif
            set_pointing_mode_id(PM_CARET);
            break;
        case _ADJUST:
#ifdef HAPTIC_ENABLE
            drv2605l_pulse(lg_dblclick_str);
#endif
            break;
        case _KEYPAD:
#ifdef HAPTIC_ENABLE
            drv2605l_pulse(transition_rampup_short_sharp1_50);
#endif
            set_pointing_mode_id(6);
            break;
        case _MOUSE:
#ifdef HAPTIC_ENABLE
            drv2605l_pulse(sharp_click);
#endif
            break;
        case _MEDIA:
#ifdef HAPTIC_ENABLE
            drv2605l_pulse(pulsing_sharp);
#endif
            break;
    }
    return state;
}

// #include "emblem_ui.c"

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
    process_record_painter(keycode, record);
    // if(!process_select_word(keycode, record, SELWORD)) { return false; }
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
    case KC_C:
    if (record->event.pressed) {
        drv2605l_pulse(pulsing_sharp);
    }
    break;
    return false;
  }
  return true;
}

void matrix_io_delay(void) {
    __asm__ volatile("nop\nnop\nnop\n");
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    for (int32_t i = 0; i < 40; i++) {
        __asm__ volatile("nop" ::: "memory");
    }
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
