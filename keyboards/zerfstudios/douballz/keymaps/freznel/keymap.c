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

#    include "pointing_device_modes.h"
#include "pointing_device.h"
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif

#define DRAGSCROLL_PADDING 6
#define DQT QK_DEBUG_TOGGLE

#define DYN_000 DYN_MACRO_KEY00
#define DYN_001 DYN_MACRO_KEY01

// static bool SWT_ALT;

enum keymap_pointing_device_modes {
    PM_BROW = PM_SAFE_RANGE, // BROWSER TAB Manipulation            [mode id 6]
    PM_RGB_MODE_VAL,         // RGB Control for mode and Brightness [mode id 7]
    PM_RGB_HUE_SAT,          // RGB Control for HUE and Saturation  [mode id 8]
    PM_RGB_SPEED,            // RGB Control for Speed               [mode id 9]
    PM_WINDOW,             // Window Control                        [mode id 10]
    PM_SWITCHER,             // RGB Control for Speed                    [mode id 11]
    PM_WIP2,             // RGB Control for Speed                   [mode id 12]
    PM_WIP3,           // RGB Control for Speed                     [mode id 13]
    PM_WIP4,            // RGB Control for Speed                    [mode id 14]
    PM_WIP5,           // RGB Control for Speed                     [mode id 15]
};

const uint16_t pointing_device_mode_maps[][4] = {
    // PM_BROW
    [0] = POINTING_MODE_LAYOUT(
                C(S(KC_PGUP)),
        C(S(KC_TAB)),       C(KC_TAB),
                C(S(KC_PGDN))
    ),
    // PM_RGB_MODE_VAL
    [1] = POINTING_MODE_LAYOUT(
                RGB_VAI,
        RGB_RMOD,        RGB_MOD,
                RGB_VAD
    ),
    // PM_RGB_HUE_SAT
    [2] = POINTING_MODE_LAYOUT(
                RGB_SAI,
        RGB_HUD,        RGB_HUI,
                RGB_SAD
    ),
    // PM_RGB_SPEED
    [3] = POINTING_MODE_LAYOUT(
                KC_NO,
        RGB_SPD,        RGB_SPI,
                KC_NO
    ),
    // PM_WINDOW
    [4] = POINTING_MODE_LAYOUT(
                G(KC_UP),
        G(KC_LEFT),      G(KC_RIGHT),
                G(KC_DOWN)
    ),
    // PM_SWITCHER
    [5] = POINTING_MODE_LAYOUT(
                G(KC_UP),
        G(KC_LEFT),      G(KC_RIGHT),
                G(KC_DOWN)
    ),
    [6] = POINTING_MODE_LAYOUT(
                KC_NO,
        RGB_SPD,        RGB_SPI,
                KC_NO
    ),
    [7] = POINTING_MODE_LAYOUT(
                KC_NO,
        RGB_SPD,        RGB_SPI,
                KC_NO
    ),
    [8] = POINTING_MODE_LAYOUT(
                KC_NO,
        RGB_SPD,        RGB_SPI,
                KC_NO
    ),
    [9] = POINTING_MODE_LAYOUT(
                KC_NO,
        RGB_SPD,        RGB_SPI,
                KC_NO
    )
};

uint8_t get_pointing_mode_divisor_user(uint8_t mode_id, uint8_t direction) {
    switch(mode_id) {

        case PM_BROW:
            // half speed for vertical axis
            return direction < PD_LEFT ? 128 : 64;
        case PM_RGB_MODE_VAL:
            // half speed for horizontal axis
            return direction < PD_LEFT ? 64 : 128;
        case PM_RGB_HUE_SAT:
            // example of unique divisor for each mode (not actually recommended for this mode (64 would be a good divisor here))
            switch(direction) {
                case PD_DOWN:
                    return 32;
                case PD_UP:
                    return 64;
                case PD_LEFT:
                    return 16;
                case PD_RIGHT:
                    return 128;
            }
        case PM_RGB_SPEED:
            return 64; // could skip adding this if default if POINTING_DEFAULT_DIVISOR is 64
        case PM_WINDOW:
            // half speed for vertical axis
            return 128;
        case PM_SWITCHER:
            // half speed for horizontal axis
            return 64;
        case PM_WIP2:
            // example of unique divisor for each mode (not actually recommended for this mode (64 would be a good divisor here))
            switch(direction) {
                case PD_DOWN:
                    return 32;
                case PD_UP:
                    return 64;
                case PD_LEFT:
                    return 16;
                case PD_RIGHT:
                    return 128;
            }
        case PM_WIP3:
            return 64; // could skip adding this if default if POINTING_DEFAULT_DIVISOR is 64
        case PM_WIP4:
            return 64; // could skip adding this if default if POINTING_DEFAULT_DIVISOR is 64
        case PM_WIP5:
            return 64; // could skip adding this if default if POINTING_DEFAULT_DIVISOR is 64
    }

    return 0; // returning 0 to let processing of divisors continue
}


enum custom_keycodes {
  ST_MACRO_0 = NEW_SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6
};

// clang-format off

#define LAYOUT_douballz_wrapper(...) LAYOUT_douballz(__VA_ARGS__)
#define LAYOUT_douballz_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A,\
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
) \
    LAYOUT_douballz_wrapper( \
    KC_MINUS,  ________________NUMBER_LEFT________________,                                                                  ________________NUMBER_RIGHT_______________, KC_EQUAL,\
    PM_MO(3),         K01,         K02,          K03,           K04,        K05,                                            K06,     K07,     K08,     K09,     K0A,   BSP_KEY, \
    CTLGRVE, LGUI_T(K11), LALT_T(K12),  LCTL_T(K13),   LSFT_T(K14),         K15,                                            K16,     RSFT_T(K17),     RCTL_T(K18),     RALT_T(K19),     RGUI_T(K1A),     RALT_T(K1B), \
    LALT_T(KC_DEL), LCTL_T(K21),  K22,          K23,            K24,        K25,        PM_SWITCH,          ALT_TAB,        K26,     K27,     K28,     K29, RCTL_T(K2A), KC_BSLS, \
                                                            TAB_RSE,        SPC_LSH,    ENT_LWR,            ESC_LWR,        BSP_KEY,    DEL_RSE,\
                                                                            KC_BTN1,    KC_BTN2,            KC_BTN2,        KC_BTN1,\
                                                            DPI_RMOD,       RGB_TOG1,   DPI_MOD,            RGB_RMOD,       KC_RGB_T,    RGB_MOD,\
                                                            KC_TRNS,       KC_TRNS,                                       KC_TRNS,   KC_TRNS\
    )


#define LAYOUT_base_wrapper(...) LAYOUT_douballz_base(__VA_ARGS__)
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

    [_MOUSE] = LAYOUT_douballz(
        _______,        KC_E,       KC_WH_L,    KC_WH_R,    _______,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
        _______,        S(KC_M),    KC_WH_D,    KC_WH_U,    KC_ESC,     KC_POSR,                                                    _______,    KC_ESC,     KC_WH_U,    KC_WH_D,    S(KC_M),    _______,
        _______,        KC_WH_L,    KC_BTN2,    KC_BTN1,    KC_BTN3,    PM_MO(10),                                                    KC_WH_L,    KC_BTN2,    KC_BTN1,    KC_BTN3,    KC_WH_R,    _______,
        _______,        KC_INTR,    TD_PMD1,    TD_DRGS,    NX_TAB,     PM_MO(6),  _______,                              _______,    PM_BROW,    BK_TAB,     TD_DRGS,    NX_TAB,     KC_INTR,    _______,
                                                                        _______,    _______,    _______,    _______,    _______,    _______,
                                                                                    _______,    _______,    _______,    _______,
                                                                        _______,    _______,    _______,    _______,    _______,    _______,
                                                                        _______,    _______,                _______,    _______
    ),

    [_MEDIA] = LAYOUT_douballz(
        _______,        KC_E,       KC_WH_D,    KC_WH_U,    _______,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
        _______,        S(KC_M),    KC_WH_D,    KC_WH_U,    KC_ESC,     _______,                                                    _______,    KC_ESC,     KC_WH_U,    KC_WH_D,    S(KC_M),    _______,
        _______,        KC_POSR,    KC_BTN2,    KC_BTN1,    KC_BTN3,    _______,                                                    _______,    KC_BTN2,    KC_BTN1,    KC_BTN3,    KC_POSR,    _______,
        _______,        KC_INTR,     BK_TAB,    TD_DRGS,    NX_TAB,     _______,    _______,                            _______,    _______,    BK_TAB,     TD_DRGS,    NX_TAB,     KC_INTR,    _______,
                                                                        _______,    _______,    _______,    _______,    _______,    _______,
                                                                                    _______,    _______,    _______,    _______,
                                                                        _______,    _______,    _______,    _______,    _______,    _______,
                                                                        _______,    _______,                _______,    _______
    ),

    [_LOWER] = LAYOUT_douballz_wrapper(
        KC_F12,         _________________FUNC_LEFT_________________,                                                    _________________FUNC_RIGHT________________,     KC_F11,
        KC_CAPS,        _________________LOWER_L1__________________,                                                    _________________LOWER_R1__________________,    _______,
        _______,        _________________LOWER_L2__________________,                                                    _________________LOWER_R2__________________,    KC_PIPE,
        _______,        _________________LOWER_L3__________________,    _______,                            _______,    _________________LOWER_R3__________________,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                                        _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                            _______,    _______,                            _______,    _______
    ),
    [_RAISE] = LAYOUT_douballz_wrapper(
        KC_F12,         _________________FUNCA_LEFT________________,                                                    _________________FUNC_RIGHT________________,     KC_F11,
        KC_CAPS,        _________________RAISE_L1__________________,                                                    _________________RAISE_R1__________________,    _______,
        _______,        _________________RAISE_L2__________________,                                                    _________________RAISE_R2__________________,    KC_PIPE,
        _______,        _________________RAISE_L3__________________,    _______,                            _______,    _________________RAISE_R3__________________,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                                        _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                            _______,    _______,                            _______,    _______
    ),
    [_ADJUST] = LAYOUT_douballz_wrapper(
        QK_BOOT,        _________________FUNC_LEFT_________________,                                                    _________________FUNC_RIGHT________________,    QK_BOOT,
        EE_CLR,         _________________ADJUST_L1_________________,                                                    _________________ADJUST_R1_________________,    EE_CLR,
        KEYLOCK,        _________________ADJUST_L2_________________,                                                    _________________ADJUST_R2_________________,    TG_MODS,
        UC_MOD,         _________________ADJUST_L3_________________,    AML_TOG,                            SNP_TOG,    _________________ADJUST_R3_________________,    KC_MPLY,
                                                            SH_TT,      DPI_MOD,    DPI_RMOD,   DRGSCRL,        DQT,    _______,
                                                                        _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                            _______,    _______,                            _______,    _______
    ),
    [_KEYPAD] = LAYOUT_douballz_wrapper(
        QK_MAKE,        _________________FUNC_LEFT_________________,                                                    _________________FUNC_RIGHT________________,    QK_BOOT,
        EE_CLR,         ________________NUMPAD1_LEFT_______________,                                                     _________________ADJUST_R1_________________,    EE_CLR,
        KC_SCROLL_LOCK, ________________NUMPAD2_LEFT_______________,                                                    _________________ADJUST_R2_________________,    TG_MODS,
        UC_MOD,         ________________NUMPAD3_LEFT_______________,    LVGL_ENCODER_BUTTON,       LVGL_ENCODER_BUTTON, _________________ADJUST_R3_________________,    KC_MPLY,
                                                            KC_BSPC,    DPI_MOD,    DPI_RMOD,   DRGSCRL,        DQT,    _______,
                                                                        _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
                                                            _______,    _______,                            _______,    _______
    ),
    [_GAMEPAD] = LAYOUT_douballz_wrapper(
        QK_MAKE,        _________________FUNC_LEFT_________________,                                                    _________________FUNC_RIGHT________________,    QK_BOOT,
        EE_CLR,         ________________NUMPAD1_LEFT_______________,                                                     _________________ADJUST_R1_________________,    EE_CLR,
        KEYLOCK,        ________________NUMPAD2_LEFT_______________,                                                    _________________ADJUST_R2_________________,    TG_MODS,
        UC_MOD,         ________________NUMPAD3_LEFT_______________,    LVGL_ENCODER_BUTTON,       LVGL_ENCODER_BUTTON, _________________ADJUST_R3_________________,    KC_MPLY,
                                                            KC_BSPC,    DPI_MOD,    DPI_RMOD,   DRGSCRL,        DQT,    _______,
                                                                        _______,    _______,    _______,    _______,
                                                            _______,    _______,    _______,    _______,    _______,    _______,
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



#define BASE_ENCODERS { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U)}
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_DEFAULT_LAYER_1] = BASE_ENCODERS,
    [_DEFAULT_LAYER_2] = BASE_ENCODERS,
    [_DEFAULT_LAYER_3] = BASE_ENCODERS,
    [_DEFAULT_LAYER_4] = BASE_ENCODERS,
    [_MOUSE] = BASE_ENCODERS,
    [_GAMEPAD]         = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(_______, _______) },
    [_MEDIA]           = { ENCODER_CCW_CW(_______, _______ ), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_RAISE]           = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(KC_WH_L, KC_WH_R)  },
    [_LOWER]           = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_ADJUST]          = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_SPD, RGB_SPI) },
    [_KEYPAD]          = { ENCODER_CCW_CW(LVGL_CLOCKWISE, LVGL_COUNTER_CLOCKWISE), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) }
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
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
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


void init_and_clear(painter_device_t device, painter_rotation_t rotation) {
    uint16_t width;
    uint16_t height;
    qp_get_geometry(device, &width, &height, NULL, NULL, NULL);

    qp_init(device, rotation);
    qp_clear(device);
    qp_rect(device, 0, 0, width, height, 0, 0, 0, true);
}

layer_state_t layer_state_set_keymap(layer_state_t state) {
    if (get_toggled_pointing_mode_id() != get_pointing_mode_id()) {
        set_pointing_mode_id(get_toggled_pointing_mode_id());
    }
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
            set_pointing_mode_id(PM_BROW);
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
    }
    return state;
}

#include "combos.c"

void matrix_io_delay(void) {
    __asm__ volatile("nop\nnop\nnop\n");
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    for (int32_t i = 0; i < 40; i++) {
        __asm__ volatile("nop" ::: "memory");
    }
}
