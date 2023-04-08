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
#include "adps9660.h"

#define DQT QK_DEBUG_TOGGLE

#define DYN_000 DYN_MACRO_KEY00
#define DYN_001 DYN_MACRO_KEY01

#define DRG_TCK DRAG_TRACKS
#define PLC_VIA PLACE_VIA
#define TCK_WTH TRACK_WIDTH
#define VIA_WTH VIA_WIDTH
#define TCK_PRE TRACK_POSTURE
#define TCK_CME TRACK_CORNER_MODE

static bool     MIDI_ARM = false;
extern MidiDevice midi_device;

enum custom_keycodes {
    ST_MACRO_0 = NEW_SAFE_RANGE,
    ST_MACRO_1,
    ST_MACRO_2,
    ST_MACRO_3,
    ST_MACRO_4,
    ST_MACRO_5,
    MIDI_CH_ARM,
};

// clang-format off

#define LAYOUT_4x6_wrapper(...) LAYOUT_4x6(__VA_ARGS__)
#define LAYOUT_4x6_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A,\
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
) \
    LAYOUT_4x6_wrapper( \
    KC_MINUS,               ________________NUMBER_LEFT________________,                                                    ________________NUMBER_RIGHT_______________,                KC_EQUAL,\
    CTLGRVE,        K01,        K02,        K03,        K04,        K05,                                                    K06,        K07,        K08,        K09,        K0A,        BSP_KEY, \
    OS_LSFT,        LGUI_T(K11),LALT_T(K12),LCTL_T(K13),LSFT_T(K14),K15,                                                    K16,        RSFT_T(K17),RCTL_T(K18),RALT_T(K19),RGUI_T(K1A),RALT_T(K1B), \
    LALT_T(KC_DEL), LCTL_T(K21),K22,        K23,        K24,        K25,                                                    K26,        K27,        K28,        K29,        RCTL_T(K2A),KC_BSLS, \
                                PM_TG(0),   TAB_RSE,    SPC_LSH,    ENT_LWR,    KC_BTN1,                        KC_BTN1,    ESC_LWR,    BSP_KEY,    DEL_RSE,    PMR_CYD, \
                                LVGL_BTN,   PM_TG(2),   PM_TG(3),   KC_BTN3,    KC_BTN2,                        KC_BTN2,    PM_TG(3),   PM_TG(2),   PM_TG(3),   PM_TG(1), \
                                DPI_RMOD,   KC_PGDN,    KC_PGUP,    DPI_MOD,    KC_MUTE,                        RGB_TOG1,   KC_RGB_T,   KC_PGDN,    KC_PGUP,    DPI_MOD,\
    RGB_RMOD,       RGB_MOD,    RGB_SAD,   RGB_SAI,   KC_A,      KC_RGB_T,      KC_F7,      KC_F8,      KC_9,   KC_F10,     KC_F11,     KC_F12,     KC_F13,     KC_F14,     KC_F15,     KC_F16\
    )

#define LAYOUT_base_wrapper(...) LAYOUT_4x6_base(__VA_ARGS__)
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

    [_MOUSE] = LAYOUT_4x6(
        _______,    KC_E,       PM_MO(14),  TCK_PRE,    TCK_CME,    _______,                                                        _______,    TCK_CME,    TCK_PRE,    PM_MO(14),  KC_E,       _______,
        _______,    S(KC_M),    TCK_WTH,    KC_BTN2,    VIA_WTH,    PM_MO(6),                                                       PM_MO(6),   VIA_WTH,    KC_BTN2,    TCK_WTH,    S(KC_M),    _______,
        _______,    PM_MO(14),  ROTATE,     KC_BTN1,    KC_BTN3,    KB_MO_WINDOW,                                                   _______,    KC_BTN3,    KC_BTN1,    ROTATE,     PM_MO(14),  _______,
        KC_DEL,     KC_BTN1,    ROUTE,      TD_DRGS,    DRG_TCK,    PLC_VIA,                                                        _______,    _______,    _______,    TD_DRGR,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_LOWER] = LAYOUT_4x6_wrapper(
        _______,                _________________FUNC_LEFT_________________,                                                        _________________FUNC_RIGHT________________,    _______,
        _______,                _________________LOWER_L1__________________,                                                        _________________LOWER_R1_ALT______________,    _______,
        _______,                _________________LOWER_L2__________________,                                                        _________________LOWER_R2_ALT______________,    _______,
        _______,                _________________LOWER_L2__________________,                                                        _________________LOWER_R3__________________,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_RAISE] = LAYOUT_4x6_wrapper(
        _______,                _________________FUNC_LEFT_________________,                                                        _________________FUNC_RIGHT________________,    _______,
        KC_CAPS,                _________________RAISE_L1__________________,                                                        _________________RAISE_R1__________________,    _______,
        _______,                _________________RAISE_L2__________________,                                                        _________________RAISE_R2__________________,    _______,
        _______,                _________________RAISE_L2__________________,                                                        _________________RAISE_R3__________________,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_ADJUST] = LAYOUT_4x6_wrapper(
        QK_BOOT,                _________________UNICO_L1__________________,                                                        _________________UNICO_R1__________________,    QK_BOOT,
        EE_CLR,                 _________________ADJUST_L1_________________,                                                        _________________ADJUST_R1_________________,    EE_CLR,
        KEYLOCK,                _________________ADJUST_L2_________________,                                                        _________________ADJUST_R2_________________,    TG_MODS,
        DQT,                    _________________ADJUST_L2_________________,                                                        _________________ADJUST_R3_________________,    AM_TOGGLE,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_KEYPAD] = LAYOUT_4x6_wrapper(
        _______,                _________________FUNC_LEFT_________________,                                                        _________________FUNC_RIGHT________________,    _______,
        _______,                ________________NUMPAD1_LEFT_______________,                                                        _________________ADJUST_R1_________________,    _______,
        _______,                ________________NUMPAD2_LEFT_______________,                                                        _________________ADJUST_R2_________________,    _______,
        _______,                ________________NUMPAD3_LEFT_______________,                                                        _________________ADJUST_R3_________________,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_GAMEPAD] = LAYOUT_4x6_wrapper(
        _______,                _________________FUNC_LEFT_________________,                                                        _________________FUNC_RIGHT________________,    _______,
        _______,                _________________GAMING_L1_________________,                                                        _________________ADJUST_R1_________________,    _______,
        _______,                _________________GAMING_L2_________________,                                                        _________________ADJUST_R2_________________,    _______,
        _______,                _________________GAMING_L3_________________,                                                        _________________ADJUST_R3_________________,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),


};

// bool auto_mouse_activation(report_mouse_t mouse_report) {
//     return mouse_report.x != 0 || mouse_report.y != 0 || mouse_report.h != 0 || mouse_report.v != 0 || mouse_report.buttons || (get_toggled_pointing_mode_id() == 3);
// }


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
    process_record_painter(keycode, record);
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
            // SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));
            SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_TAP(X_DOWN)
            SS_UP(X_LSFT)
            SS_DELAY(50)
            SS_TAP(X_DEL));
        }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_BTN1) SS_DELAY(50)  SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(50) SS_TAP(X_DEL));
    }
    break;
    case MIDI_CH_ARM:
    if (record->event.pressed) {
        if (!MIDI_ARM) {
            MIDI_ARM = true;
            midi_send_cc(&midi_device, 10, 82, 127);
            dprintf("on");
        } else {
            MIDI_ARM = false;
            midi_send_cc(&midi_device, 10, 82, 0);
            dprintf("off");
        }
    }
    break;
  }
  return true;
}

#define BASE_ENCODERS { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_DEFAULT_LAYER_1] = BASE_ENCODERS,
    [_DEFAULT_LAYER_2] = BASE_ENCODERS,
    [_DEFAULT_LAYER_3] = BASE_ENCODERS,
    [_DEFAULT_LAYER_4] = BASE_ENCODERS,
    [_MOUSE] = BASE_ENCODERS,
    [_GAMEPAD]         = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(ENC_ALT_TAB_REV, ENC_ALT_TAB), ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(ENC_ALT_TAB_REV, ENC_ALT_TAB), },
    [_MEDIA]           = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_RAISE]           = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [_LOWER]           = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_ADJUST]          = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_SPI, RGB_SPD), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_SPI, RGB_SPD) },
    [_KEYPAD]          = { ENCODER_CCW_CW(LVGL_CLOCKWISE, LVGL_COUNTER_CLOCKWISE), ENCODER_CCW_CW(LVGL_CLOCKWISE, LVGL_COUNTER_CLOCKWISE), ENCODER_CCW_CW(LVGL_CLOCKWISE, LVGL_COUNTER_CLOCKWISE), ENCODER_CCW_CW(LVGL_CLOCKWISE, LVGL_COUNTER_CLOCKWISE) }
};


// #define BASE_ENCODERS {ENCODER_CCW_CW(KC_A, KC_B), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) }
// #ifdef ENCODER_MAP_ENABLE
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [_DEFAULT_LAYER_1] = BASE_ENCODERS,
//     [_DEFAULT_LAYER_2] = BASE_ENCODERS,
//     [_DEFAULT_LAYER_3] = BASE_ENCODERS,
//     [_DEFAULT_LAYER_4] = BASE_ENCODERS,
//     [_MOUSE] = BASE_ENCODERS,
//     [_GAMEPAD]         = BASE_ENCODERS,
//     [_MEDIA]           = BASE_ENCODERS,
//     [_RAISE]           = BASE_ENCODERS,
//     [_LOWER]           = BASE_ENCODERS,
//     [_ADJUST]          = BASE_ENCODERS,
//     [_KEYPAD]          = BASE_ENCODERS
// };

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

// void keyboard_post_init_keymap(void) {
//     pointing_device_set_cpi_on_side(true, 100); //Set cpi on left side to a low value for slower scrolling.
//     pointing_device_set_cpi_on_side(false, 8000); //Set cpi on right side to a reasonable value for mousing.
// }
uint8_t prox_threshold;

void keyboard_post_init_keymap(void) {
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard=true;
    // wait_ms(100);
    // adps9660_init();
    // wait_ms(100);
    // prox_threshold = 0;
    // for (int i = 0; i < 10; ++i) {
    //     uint8_t prox;
    //     adps9660_proximity(&prox);
    //     dprintf("initial %d\n", prox);
    //     if (prox > prox_threshold) {
	//         prox_threshold = prox;
    //     }
    //     wait_ms(20);
    // }
    // prox_threshold += 2;
    // dprintf("Threshold: %d\n", prox_threshold);
}

// #ifdef QUANTUM_PAINTER_ENABLE
// #include <qp.h>
// // #include <qp_st7735.h>
// //#include "graphics/matrix.qgf.c"
// #include "graphics/zerfstudios1.qgf.c"
// //#include "graphics/test-anim.qgf.c"
// #include "graphics/thintel.qff.c"
// #include "graphics/iosevka11.qff.c"
// #include "graphics/lock-caps-ON.qgf.c"i
// #include "graphics/lock-scrl-ON.qgf.c"
// #include "graphics/cg_on.qgf.c"
// #include "graphics/cg_off.qgf.c"
// #include "graphics/lock-num-ON.qgf.c"
// #include "graphics/lock-caps-OFF.qgf.c"
// #include "graphics/lock-scrl-OFF.qgf.c"
// #include "graphics/lock-num-OFF.qgf.c"
// #include "ui/fonts/futurabold.qff.c"
// #endif



// #ifdef QUANTUM_PAINTER_ENABLE
// extern painter_device_t qp_display;

// //painter_image_handle_t ters1;
// // static painter_image_handle_t zerfstudios1;
// static painter_font_handle_t futurabold;

//static deferred_token matrix_anim;
// static painter_image_handle_t lock_caps_on;
// static painter_image_handle_t lock_caps_off;
// static painter_image_handle_t lock_num_on;
// static painter_image_handle_t lock_num_off;
// static painter_image_handle_t lock_scrl_on;
// static painter_image_handle_t lock_scrl_off;
// static painter_image_handle_t cg_on;
// static painter_image_handle_t cg_off;


// void init_and_clear(painter_device_t device, painter_rotation_t rotation) {
//     uint16_t width;
//     uint16_t height;
//     qp_get_geometry(device, &width, &height, NULL, NULL, NULL);

//     qp_init(device, rotation);
//     qp_clear(device);
//     qp_rect(device, 0, 0, width, height, 0, 0, 0, true);
// }

layer_state_t layer_state_set_keymap(layer_state_t state) {
    adps9660_wake();
    switch (get_highest_layer(state)) {
        case _LOWER:
#ifdef HAPTIC_ENABLE
            DRV_pulse(soft_bump);
#endif
            set_pointing_mode_id(PM_VOL);
            break;
        case _RAISE:
#ifdef HAPTIC_ENABLE
            DRV_pulse(transition_rampup_short_sharp1_50);
#endif
            set_pointing_mode_id(PM_CARET);
            break;
        case _ADJUST:
#ifdef HAPTIC_ENABLE
            DRV_pulse(lg_dblclick_str);
#endif
            break;
        case _KEYPAD:
#ifdef HAPTIC_ENABLE
            DRV_pulse(transition_rampup_short_sharp1_50);
#endif
            set_pointing_mode_id(6);
            break;
        case _MOUSE:
#ifdef HAPTIC_ENABLE
            DRV_pulse(sharp_click);
#endif
            break;
        case _MEDIA:
#ifdef HAPTIC_ENABLE
            DRV_pulse(pulsing_sharp);
#endif
            break;
        case _GAMEPAD:
#ifdef HAPTIC_ENABLE
            DRV_pulse(pulsing_sharp);
#endif
            break;
        default:
        if (get_toggled_pointing_mode_id() != get_pointing_mode_id()) {
        set_pointing_mode_id(get_toggled_pointing_mode_id());
         }
        break;
    }
    return state;
}

// #include "combos.c"

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
