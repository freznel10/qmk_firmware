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
#include "drivers/haptic/drv2605l.h"
#endif

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
    KC_MINUS,  ________________NUMBER_LEFT________________,                                                                  ________________NUMBER_RIGHT_______________, KC_EQUAL,\
    CTLGRVE,        K01,         K02,          K03,           K04,          K05,                                            K06,     K07,     K08,     K09,     K0A,   BSP_KEY, \
    OSM(MOD_LSFT),  LGUI_T(K11), LALT_T(K12),  LCTL_T(K13),   LSFT_T(K14),  K15,                                            K16,     RSFT_T(K17),     RCTL_T(K18),     RALT_T(K19),     RGUI_T(K1A),     RALT_T(K1B), \
    LALT_T(KC_DEL), LCTL_T(K21), K22,          K23,           K24,          K25,        ST_MACRO_5,          ALT_TAB,       K26,     K27,     K28,     K29, RCTL_T(K2A), KC_BSLS, \
                                                            TAB_RSE,        SPC_LSH,    ENT_LWR,            ESC_LWR,        BSP_KEY,    DEL_RSE,\
                                                                            QK_PM_CYCLE_DEVICES,    PM_TG(0),            PM_TG(PM_VOL), PM_TG(PM_CARET),\
                                                            DPI_RMOD,      AM_TOGGLE,   DPI_MOD,            RGB_RMOD,       KC_RGB_T,    RGB_MOD,\
                                                            KC_TRNS,       KC_TRNS,                                       KC_TRNS,   KC_TRNS\
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
        _______,        KC_E,       PM_MO(14),  TCK_PRE,    TCK_CME,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
        _______,        S(KC_M),    TCK_WTH,    KC_BTN2,    VIA_WTH,     PM_MO(6),                                            ST_MACRO_6,    KC_ESC,     KC_WH_U,    KC_WH_D,    S(KC_M),    _______,
        _______,        PM_MO(14),  ROTATE,     KC_BTN1,    KC_BTN3,    KB_MO_WINDOW,                                             KB_MO_WINDOW,  KC_BTN2,    KC_BTN1,    KC_BTN3,    PM_MO(14),    _______,
        KC_DEL,        KC_BTN1,    ROUTE,      TD_DRGS,    DRG_TCK,     PLC_VIA,        _______,                             _______,    PM_MO(6),    BK_TAB,     TD_DRGR,    NX_TAB,     KC_BTN1,    KC_BTN2,
                                                                        _______,    _______,    _______,    _______,    _______,    _______,
                                                                                    KC_BTN1,    KC_BTN2,    KC_BTN2,    KC_BTN1,
                                                                        _______,    _______,    _______,    _______,    _______,    _______,
                                                                        _______,    _______,                            _______,    _______
    ),

    [_LOWER] = LAYOUT_4x6_wrapper(
        UC(0x30C4),         _________________FUNC_LEFT_________________,                                                _________________FUNC_RIGHT________________,     KC_F11,
        KC_CAPS,        _________________LOWER_L1__________________,                                                    _________________LOWER_R1_ALT______________,    _______,
        _______,        _________________LOWER_L2__________________,                                                    _________________LOWER_R2_ALT______________,    KC_PIPE,
        _______,        _________________LOWER_L3__________________,    _______,                            _______,    _________________LOWER_R3__________________,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                                        _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                        _______,    _______,                            _______,    _______
    ),
    [_RAISE] = LAYOUT_4x6_wrapper(
        KC_F12,         _________________FUNCA_LEFT________________,                                                    _________________FUNC_RIGHT________________,    KC_F11,
        KC_CAPS,        _________________RAISE_L1__________________,                                                    _________________EXTEND_R1_________________,    _______,
        _______,        _________________RAISE_L2__________________,                                                    _________________EXTEND_R2_________________,    KC_WWW_BACK,
        _______,        _________________RAISE_L3__________________,    _______,                            _______,    _________________EXTEND_R3_________________,    KC_WWW_FORWARD,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                                        _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                            _______,    _______,                            _______,    _______
    ),
    [_ADJUST] = LAYOUT_4x6_wrapper(
        QK_BOOT,        _________________FUNC_LEFT_________________,                                                    _________________FUNC_RIGHT________________,    QK_BOOT,
        EE_CLR,         _________________ADJUST_L1_________________,                                                    _________________ADJUST_R1_________________,    EE_CLR,
        KEYLOCK,        _________________ADJUST_L2_________________,                                                    _________________ADJUST_R2_________________,    TG_MODS,
        UC_CLUE,         _________________ADJUST_L3_________________,    AML_TOG,                            SNP_TOG,    _________________ADJUST_R3_________________,    KC_MPLY,
                                                            SH_TT,      DPI_MOD,    DPI_RMOD,   DRGSCRL,        DQT,    _______,
                                                                        _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                            _______,    _______,                            _______,    _______
    ),
    [_KEYPAD] = LAYOUT_4x6_wrapper(
        QK_MAKE,        _________________UNICO_L1__________________,                                                    _________________UNICO_R1__________________,    KC_WIDE,
        EE_CLR,         ________________NUMPAD1_LEFT_______________,                                                    _________________ADJUST_R1_________________,   UC_TABL,
        KC_NUM_LOCK,    ________________NUMPAD2_LEFT_______________,                                                    _________________ADJUST_R2_________________,    UC_SHRG,
        UC(0x1dfc),     ________________NUMPAD3_LEFT_______________,    LVGL_ENCODER_BUTTON,       LVGL_ENCODER_BUTTON, _________________ADJUST_R3_________________,    KC_MPLY,
                                                            KC_BSPC,    DPI_MOD,    DPI_RMOD,   DRGSCRL,        DQT,    _______,
                                                                        _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                            _______,    _______,                            _______,    _______
    ),
    [_GAMEPAD] = LAYOUT_4x6_wrapper(
        QK_MAKE,        ________________NUMBER_LEFT________________,                                                     _________________FUNC_RIGHT________________,    QK_BOOT,
        KC_CAPS,        _________________GAMING_L1_________________,                                                     _________________ADJUST_R1_________________,    EE_CLR,
        KC_RSFT,        _________________GAMING_L2_________________,                                                     _________________ADJUST_R2_________________,   KC_BTN3,
        KC_RCTL,        _________________GAMING_L3_________________,    KC_N,               LVGL_ENCODER_BUTTON,  KC_J,    KC_F,     KC_WH_D,    KC_WH_U,     KC_BTN1,    KC_BTN2,
                                                            KC_TAB,    KC_SPACE,    KC_LALT,   DRGSCRL,    KC_BTN3,    KC_BTN2,
                                                                           KC_M,    KC_ENTER,  KC_BTN2,    KC_BTN1,
                                                            _______,    AM_TOGGLE,    _______,    _______,    _______,    _______,
                                                            _______,    _______,                            _______,    _______
    )
};

bool auto_mouse_activation(report_mouse_t mouse_report) {
    return mouse_report.x != 0 || mouse_report.y != 0 || mouse_report.h != 0 || mouse_report.v != 0 || mouse_report.buttons || (get_toggled_pointing_mode_id() == 3);
}

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

#define BASE_ENCODERS { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_DEFAULT_LAYER_1] = BASE_ENCODERS,
    [_DEFAULT_LAYER_2] = BASE_ENCODERS,
    [_DEFAULT_LAYER_3] = BASE_ENCODERS,
    [_DEFAULT_LAYER_4] = BASE_ENCODERS,
    [_MOUSE] = BASE_ENCODERS,
    [_GAMEPAD]         = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(ENC_ALT_TAB_REV, ENC_ALT_TAB) },
    [_MEDIA]           = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_RAISE]           = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(KC_WH_L, KC_WH_R)  },
    [_LOWER]           = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAI, RGB_SAD)  },
    [_ADJUST]          = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_SPI, RGB_SPD) },
    [_KEYPAD]          = { ENCODER_CCW_CW(LVGL_CLOCKWISE, LVGL_COUNTER_CLOCKWISE), ENCODER_CCW_CW(LVGL_CLOCKWISE, LVGL_COUNTER_CLOCKWISE) }
};
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
// // #ifdef CONSOLE_ENABLE
// //     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// // #endif
//     debug_keyboard = true;
//     debug_mouse = true;

//   return true;
// }

// void keyboard_post_init_keymap(void) {
//     pointing_device_set_cpi_on_side(true, 100); //Set cpi on left side to a low value for slower scrolling.
//     pointing_device_set_cpi_on_side(false, 8000); //Set cpi on right side to a reasonable value for mousing.
// }


// void keyboard_post_init_keymap(void) {
//     //debug_enable = true;
//     // debug_matrix = true;
//     //debug_keyboard=true;
// }

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
        case _GAMEPAD:
#ifdef HAPTIC_ENABLE
            drv2605l_pulse(pulsing_sharp);
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

bool is_keyboard_left(void) {
    static enum { UNKNOWN, LEFT, RIGHT } side = UNKNOWN;

    if (side == UNKNOWN) {
#if defined(SPLIT_HAND_PIN)
        // Test pin SPLIT_HAND_PIN for High/Low, if low it's right hand
#    ifdef SPLIT_HAND_PIN_LOW_IS_LEFT
        side = !readPin(SPLIT_HAND_PIN) ? LEFT : RIGHT;
#    else
        side = readPin(SPLIT_HAND_PIN) ? LEFT : RIGHT;
#    endif
#elif defined(SPLIT_HAND_MATRIX_GRID)
#    ifdef SPLIT_HAND_MATRIX_GRID_LOW_IS_RIGHT
        side = peek_matrix_intersection(SPLIT_HAND_MATRIX_GRID) ? LEFT : RIGHT;
#    else
        side = !peek_matrix_intersection(SPLIT_HAND_MATRIX_GRID) ? LEFT : RIGHT;
#    endif
#elif defined(EE_HANDS)
        side = eeconfig_read_handedness() ? LEFT : RIGHT;P
#elif defined(MASTER_RIGHT)
        side = !is_keyboard_master() ? LEFT : RIGHT;
#endif
    }

    return (side == LEFT);
}

