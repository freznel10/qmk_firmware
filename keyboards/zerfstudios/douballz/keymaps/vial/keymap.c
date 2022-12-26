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
#include "select_word.h"

#include <math.h>
#include <stdio.h>
#include "ctype.h"
#include "color.h"
#include <qp.h>

static painter_font_handle_t iosevka11;
static painter_font_handle_t futurabold;

#ifdef HAPTIC_ENABLE
//#include "keyboards/zerf9/mx_track/haptic_utils.h"
#include "drivers/haptic/DRV2605L.h"
#endif

#define DRAGSCROLL_PADDING 6
#define DQT QK_DEBUG_TOGGLE


#define DYN_000 DYN_MACRO_KEY00
#define DYN_001 DYN_MACRO_KEY01

// enum keymap_pointing_device_modes {
//     PM_BROW,      // BROWSER TAB Manipulation            [index 0]
//     PM_RGB_MD_VA, // RGB Control for mode and Brightness [index 1]
//     PM_RGB_HU_SA, // RGB Control for HUE and Saturation  [index 2]
//     PM_RGB_SPEED  // RGB Control for Speed               [index 3]
// };

// const uint16_t pointing_device_mode_maps[][4] = {
//     [PM_BROW] = POINTING_MODE_LAYOUT(
//                 C(S(KC_PGUP)),
//         C(S(KC_TAB)),       C(KC_TAB),
//                 C(S(KC_PGDN))
//     ),
//     [PM_RGB_MD_VA] = POINTING_MODE_LAYOUT(
//                 RGB_VAI,
//         RGB_RMOD,        RGB_MOD,
//                 RGB_VAD
//     ),
//     [PM_RGB_HU_SA] = POINTING_MODE_LAYOUT(
//                 RGB_SAI,
//         RGB_HUD,        RGB_HUI,
//                 RGB_SAD
//     ),
//     [PM_RGB_SPEED] = POINTING_MODE_LAYOUT(
//                 KC_NO,
//         RGB_SPD,        RGB_SPI,
//                 KC_NO
//     )
// };

// uint8_t get_pointing_mode_divisor_user(uint8_t mode_id, uint8_t direction) {
//     switch(mode_id) {

//         case PM_BROW:
//             // half speed for vertical axis
//             return direction < PD_LEFT ? 128 : 64;

//         case PM_RGB_MD_VA:
//             // half speed for horizontal axis
//             return direction < PD_LEFT ? 64 : 128;

//         case PM_RGB_HU_SA:
//             // example of unique divisor for each mode (not actually recommended for this mode (64 would be a good divisor here))
//             switch(direction) {
//                 case PD_DOWN:
//                     return 32;
//                 case PD_UP:
//                     return 64;
//                 case PD_LEFT:
//                     return 16;
//                 case PD_RIGHT:
//                     return 128;
//             }

//         case PM_RGB_SPEED:
//             return 64; // could skip adding this if default if POINTING_DEFAULT_DIVISOR is 64
//     }

//     return 0; // returning 0 to let processing of divisors continue
// }


enum custom_keycodes {
  ST_MACRO_0 = NEW_SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
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
    KC_RGB_T,         K01,         K02,          K03,           K04,        K05,                                            K06,     K07,     K08,     K09,     K0A,   BSP_KEY, \
    CTLGRVE, LGUI_T(K11), LALT_T(K12),  LCTL_T(K13),   LSFT_T(K14),        K15,                                            K16,     RSFT_T(K17),     RCTL_T(K18),     RALT_T(K19),     RGUI_T(K1A),     RALT_T(K1B), \
    LALT_T(KC_DEL), LCTL_T(K21),  K22,          K23,            K24,        K25,        TD_DRGS,            ALT_TAB,        K26,     K27,     K28,     K29, RCTL_T(K2A), KC_BSLS, \
                                                            TAB_RSE,        SPC_LSH,    ENT_LWR,            ESC_LWR,        BSP_KEY,    DEL_RSE,\
                                                                            KC_BTN1,    KC_BTN2,            KC_BTN2,        KC_BTN1,\
                                                            DPI_RMOD,       RGB_TOG1,   DPI_MOD,            RGB_RMOD,       RGB_TOG,    RGB_MOD,\
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
        _______,        KC_E,       KC_WH_D,    KC_WH_U,    _______,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
        _______,        S(KC_M),    KC_WH_D,    KC_WH_U,    KC_ESC,     _______,                                                    _______,    KC_ESC,     KC_WH_U,    KC_WH_D,    S(KC_M),    _______,
        _______,        KC_POSR,    KC_BTN2,    KC_BTN1,    KC_BTN3,    _______,                                                    _______,    KC_BTN2,    KC_BTN1,    KC_BTN3,    KC_POSR,    _______,
        _______,        KC_INTR,     BK_TAB,    TD_DRGS,    NX_TAB,     _______,    _______,                            _______,    _______,    BK_TAB,     TD_DRGS,    NX_TAB,     KC_INTR,    _______,
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
        KC_F12,         _________________FUNC_LEFT_________________,                                                    _________________FUNC_RIGHT________________,     KC_F11,
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
        KC_SCROLL_LOCK,        ________________NUMPAD2_LEFT_______________,                                                    _________________ADJUST_R2_________________,    TG_MODS,
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
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
if(!process_select_word(keycode, record, SELWORD)) { return false; }
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
    [_RAISE]           = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_LOWER]           = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_ADJUST]          = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
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

#ifdef QUANTUM_PAINTER_ENABLE
#include <qp.h>
// #include <qp_st7735.h>
//#include "graphics/matrix.qgf.c"
#include "graphics/zerfstudios1.qgf.c"
//#include "graphics/test-anim.qgf.c"
#include "graphics/thintel.qff.c"
#include "graphics/iosevka11.qff.c"
#include "graphics/lock-caps-ON.qgf.c"
#include "graphics/lock-scrl-ON.qgf.c"
#include "graphics/cg_on.qgf.c"
#include "graphics/cg_off.qgf.c"
#include "graphics/lock-num-ON.qgf.c"
#include "graphics/lock-caps-OFF.qgf.c"
#include "graphics/lock-scrl-OFF.qgf.c"
#include "graphics/lock-num-OFF.qgf.c"
#include "ui/fonts/futurabold.qff.c"
#endif



#ifdef QUANTUM_PAINTER_ENABLE
extern painter_device_t qp_display;

//painter_image_handle_t ters1;
// static painter_image_handle_t zerfstudios1;
static painter_font_handle_t futurabold;

//static deferred_token matrix_anim;
// static painter_image_handle_t lock_caps_on;
// static painter_image_handle_t lock_caps_off;
// static painter_image_handle_t lock_num_on;
// static painter_image_handle_t lock_num_off;
// static painter_image_handle_t lock_scrl_on;
// static painter_image_handle_t lock_scrl_off;
// static painter_image_handle_t cg_on;
// static painter_image_handle_t cg_off;

//----------------------------------------------------------
// RGB Matrix naming
#include <rgb_matrix.h>

#if defined(RGB_MATRIX_EFFECT)
#    undef RGB_MATRIX_EFFECT
#endif  // defined(RGB_MATRIX_EFFECT)

#define RGB_MATRIX_EFFECT(x) RGB_MATRIX_EFFECT_##x,
enum {
    RGB_MATRIX_EFFECT_NONE,
#include "rgb_matrix_effects.inc"
#undef RGB_MATRIX_EFFECT
#ifdef RGB_MATRIX_CUSTOM_KB
#    include "rgb_matrix_kb.inc"
#endif
#ifdef RGB_MATRIX_CUSTOM_USER
#    include "rgb_matrix_user.inc"
#endif
};

#define RGB_MATRIX_EFFECT(x)    \
    case RGB_MATRIX_EFFECT_##x: \
        return #x;
const char *rgb_matrix_name(uint8_t effect) {
    switch (effect) {
        case RGB_MATRIX_EFFECT_NONE:
            return "NONE";
#include "rgb_matrix_effects.inc"
#undef RGB_MATRIX_EFFECT
#ifdef RGB_MATRIX_CUSTOM_KB
#    include "rgb_matrix_kb.inc"
#endif
#ifdef RGB_MATRIX_CUSTOM_USER
#    include "rgb_matrix_user.inc"
#endif
        default:
            return "UNKNOWN";
    }
}

void init_and_clear(painter_device_t device, painter_rotation_t rotation) {
    uint16_t width;
    uint16_t height;
    qp_get_geometry(device, &width, &height, NULL, NULL, NULL);

    qp_init(device, rotation);
    qp_clear(device);
    qp_rect(device, 0, 0, width, height, 0, 0, 0, true);
}


void draw_ui_user(void) {
    bool            hue_redraw = false, cpi_redraw = false;
    static uint16_t last_hue   = 0xFFFF;
    uint8_t         curr_hue   = rgb_matrix_get_hue();
    static uint16_t last_cpi   = 0xFFFF;
    uint16_t        curr_cpi   = charybdis_get_pointer_sniping_enabled() ? charybdis_get_pointer_sniping_dpi() : charybdis_get_pointer_default_dpi();
    uint16_t width;
    uint16_t height;
    qp_get_geometry(qp_display, &width, &height, NULL, NULL, NULL);

    if (last_hue != curr_hue) {
        last_hue   = curr_hue;
        hue_redraw = true;
    }
    if (last_cpi != curr_cpi) {
        last_cpi   = curr_cpi;
        cpi_redraw = true;
    }

    bool            layer_state_redraw = false;
    static uint32_t last_layer_state   = 0;
    if (last_layer_state != layer_state) {
        last_layer_state   = layer_state;
        layer_state_redraw = true;
    }

    bool            dl_state_redraw = false;
    static uint32_t last_dl_state   = 0;
    if (last_dl_state != default_layer_state) {
        last_dl_state   = default_layer_state;
        dl_state_redraw = true;
    }

    bool            ds_state_redraw = false;
    static uint32_t last_ds_state   = 0;
    if (last_ds_state != get_pointing_mode_id()) {
        last_ds_state   = get_pointing_mode_id();
        ds_state_redraw = true;
    }


    bool            sp_state_redraw = false;
    static uint32_t last_sp_state   = 0;
    if (last_sp_state != charybdis_get_pointer_sniping_enabled()) {
        last_sp_state  = charybdis_get_pointer_sniping_enabled();
        sp_state_redraw = true;
    }

    bool            am_state_redraw = false;
    static uint32_t last_am_state   = 0;
    if (last_am_state != charybdis_get_auto_mouse_enabled()) {
        last_am_state = charybdis_get_auto_mouse_enabled();
        am_state_redraw = true;
    }

    bool            wpm_redraw      = false;
    static uint32_t last_wpm_update = 0;
    if (timer_elapsed32(last_wpm_update) > 125) {
        last_wpm_update = timer_read32();
        wpm_redraw      = true;
    }

    bool            scan_redraw      = false;
    static uint32_t last_scan_update = 0;
    if (timer_elapsed32(last_scan_update) > 125) {
        last_scan_update = timer_read32();
        scan_redraw      = true;
    }

#if defined(RGB_MATRIX_ENABLE)
    bool            rgb_effect_redraw = false;
    static uint16_t last_effect       = 0xFFFF;
    uint8_t         curr_effect       = rgb_matrix_config.mode;
    if (last_effect != curr_effect) {
        last_effect       = curr_effect;
        rgb_effect_redraw = true;
    }
#endif
    int yrpos = 0;
    if (!is_keyboard_left()) {
        char buf[32] = {0};
        int  xpos    = 2;
        // if (hue_redraw) {
        //     qp_drawimage_recolor(qp_display, 0, 128 - zerfstudios1->height,  zerfstudios1, curr_hue, 255, 255, curr_hue, 255, 0);
        // }

        yrpos += futurabold->line_height + 4;
        if (hue_redraw || wpm_redraw) {
            static int max_wpm_xpos = 0;
            xpos                    = 1;
            snprintf(buf, sizeof(buf), "WPM: %d", (int)get_current_wpm());
            // xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_wpm_xpos < xpos) {
                max_wpm_xpos = xpos;
            }
            qp_rect(qp_display, xpos, yrpos, max_wpm_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);

        }

        yrpos += futurabold->line_height + 4;
        if (hue_redraw || scan_redraw) {
            static int max_scans_xpos = 0;
            xpos                      = 1;
            snprintf(buf, sizeof(buf), "SCANS: %d", (int)get_matrix_scan_rate());
            xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_scans_xpos < xpos) {
                max_scans_xpos = xpos;
            }
            qp_rect(qp_display, xpos, yrpos, max_scans_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
        }

        yrpos += futurabold->line_height + 4;
        if (hue_redraw || ds_state_redraw) {
            static int max_dss_xpos = 0;
            xpos                    = 1;
            const char* buf = "DS:ACTIVE";
            const char* buf1 = "DS:OFF";
            if (get_pointing_mode_id() == 14) {
               xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, 155, 255, 255, 155, 255, 255);
            } else {
               xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf1, 0, 255, 255, 0, 255, 255);
            }

            if (max_dss_xpos < xpos) {
                max_dss_xpos = xpos;
            }
            qp_rect(qp_display, xpos, yrpos, max_dss_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);

        }

        yrpos += futurabold->line_height + 4;
        if (hue_redraw || am_state_redraw) {
            static int max_ams_xpos = 0;
            xpos                    = 2;
            const char* buf = charybdis_get_auto_mouse_enabled() ? "AM:ACTIVE" : "AM:OFF";
            xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, charybdis_get_auto_mouse_enabled()  ? 34 : 255, 255, 255, charybdis_get_pointer_sniping_enabled() ? 34 : 255, 255, 0);
            if (max_ams_xpos < xpos) {
                max_ams_xpos = xpos;
            }
            qp_rect(qp_display, xpos, yrpos, max_ams_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);

        }

        yrpos += futurabold->line_height + 4;
        if (hue_redraw || sp_state_redraw) {
            static int max_sps_xpos = 0;
            xpos                    = 2;
            const char* buf = charybdis_get_pointer_sniping_enabled() ? "SN:ACTIVE" : "SN:OFF";
            xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, charybdis_get_pointer_sniping_enabled() ? 153 : 255, 255, 255, charybdis_get_pointer_sniping_enabled() ? 153 : 255, 255, 0);
            if (max_sps_xpos < xpos) {
                max_sps_xpos = xpos;
            }
            qp_rect(qp_display, xpos, yrpos, max_sps_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);

        }



        // static led_t last_led_state = {0};
        // if (hue_redraw || last_led_state.raw != host_keyboard_led_state().raw) {
        //     last_led_state.raw = host_keyboard_led_state().raw;
        //     qp_drawimage_recolor(qp_display, 128 - (32 * 3), 0, last_led_state.caps_lock ? lock_caps_on : lock_caps_off, curr_hue, 255, last_led_state.caps_lock ? 255 : 32, curr_hue, 255, 0);
        //     qp_drawimage_recolor(qp_display, 128 - (32 * 2), 0, last_led_state.num_lock ? lock_num_on : lock_num_off, curr_hue, 255, last_led_state.num_lock ? 255 : 32, curr_hue, 255, 0);
        //     qp_drawimage_recolor(qp_display, 128 - (32 * 1), 0, last_led_state.scroll_lock ? lock_scrl_on : lock_scrl_off, curr_hue, 255, last_led_state.scroll_lock ? 255 : 32, curr_hue, 255, 0);
        // }

        // static keymap_config_t last_keymap_config = {0};
        // if (hue_redraw || last_keymap_config.raw != keymap_config.raw) {
        //     last_keymap_config.raw = keymap_config.raw;
        //     static int max_bpm_xpos = 0;
        //     xpos                    = cg_off->width;
        //     yrpos                    = 128 - (cg_off->height);
        //     const char* buf = "NKRO ";
        //     //kconst char* buf1 = "CRCT ";
        //     const char* buf2 = "1SHOT ";
        //     // snprintf(buf, sizeof(buf), );
        //     // snprintf(buf1, sizeof(buf1), "CRCT");
        //     // snprintf(buf2, sizeof(buf2), "1SHOT");
        //     // snprintf(buf3, sizeof(buf3), "SWAP");
        //     qp_drawimage(qp_display, 0, yrpos, last_keymap_config.swap_lctl_lgui ? cg_on : cg_off);
        //     xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, last_keymap_config.nkro? 153 : 255, 255, 255, last_keymap_config.nkro ? 153 : 255, 255, 0);
        //     //xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf1, last_keymap_config.autocorrect_enable? 153 : 255, 255, 255, last_keymap_config.autocorrect_enable ? 153 : 255, 255, 0);
        //     xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf2, last_keymap_config.oneshot_enable? 153 : 255, 255, 255, last_keymap_config.oneshot_enable ? 153 : 255, 255, 0);
        //     if (max_bpm_xpos < xpos) {
        //         max_bpm_xpos = xpos;
        //     }
        //     qp_rect(qp_display, xpos, yrpos, max_bpm_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);

        // }
    }

    int ypos = 0;
    if (is_keyboard_left()) {
        char buf[32] = {0};
        int  xpos    = 1;

        // if (hue_redraw)  {
        // qp_drawimage_recolor(qp_display, 0, 128 - zerfstudios1->height,  zerfstudios1, curr_hue, 255, 255, curr_hue, 255, 0);
        // }

        ypos += futurabold->line_height;
        if (hue_redraw || rgb_effect_redraw) {
            static int max_rgb_xpos = 0;
            xpos                    = 1;
            snprintf(buf, sizeof(buf), "RGB: %s", rgb_matrix_name(curr_effect));

            for (int i = 5; i < sizeof(buf); ++i) {
                if (buf[i] == 0)
                    break;
                else if (buf[i] == '_')
                    buf[i] = ' ';
                else if (buf[i - 1] == ' ')
                    buf[i] = toupper(buf[i]);
                else if (buf[i - 1] != ' ')
                    buf[i] = tolower(buf[i]);
            }

            xpos += qp_drawtext_recolor(qp_display, xpos, ypos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_rgb_xpos < xpos) {
                max_rgb_xpos = xpos;
            }
            qp_rect(qp_display, xpos, ypos, max_rgb_xpos, ypos + futurabold->line_height, 0, 0, 0, true);
        }

        ypos += futurabold->line_height + 4;
        if (hue_redraw || dl_state_redraw) {
            const char *dl_name = "unknown";
            switch (get_highest_layer(default_layer_state)) {
                case _COLEMAK_DH:
                    dl_name = "COLEMAK_DH";
                    break;
                case _COLEMAK:
                    dl_name = "COLEMAK";
                    break;
                case _QWERTY:
                    dl_name = "QWERTY:";
                    break;
                case _DVORAK:
                    dl_name = "DVORAK";
                    break;
            }

            static int max_layer_xpos = 0;
            xpos                      = 1;
            snprintf(buf, sizeof(buf), "%s", dl_name);
            xpos += qp_drawtext_recolor(qp_display, xpos, ypos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_layer_xpos < xpos) {
                max_layer_xpos = xpos;
            }
            qp_rect(qp_display, xpos, ypos, max_layer_xpos, ypos + futurabold->line_height, 0, 0, 0, true);

        }

        ypos += futurabold->line_height + 4;
        if (hue_redraw || layer_state_redraw) {
            const char *layer_name = "default";
            switch (get_highest_layer(layer_state)) {
                case _MOUSE:
                    layer_name = "mouse";
                    break;
                case _LOWER:
                    layer_name = "lower";
                    break;
                case _RAISE:
                    layer_name = "raise";
                    break;
                case _ADJUST:
                    layer_name = "adjust";
                    break;
                case _KEYPAD:
                    layer_name = "keypad";
                case _MEDIA:
                    layer_name = "keypad";
                    break;
            }

            static int max_layer_xpos = 0;
            xpos                      = 1;
            snprintf(buf, sizeof(buf), "%s", layer_name);
            xpos += qp_drawtext_recolor(qp_display, xpos, ypos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_layer_xpos < xpos) {
                max_layer_xpos = xpos;
            }
            qp_rect(qp_display, xpos, ypos, max_layer_xpos, ypos + futurabold->line_height, 0, 0, 0, true);

        }

        ypos += futurabold->line_height + 4;
        if (hue_redraw || cpi_redraw) {
            static int max_cpi_xpos = 0;
            xpos                      = 1;
            snprintf(buf, sizeof(buf), "CPI: %d", (int)charybdis_get_pointer_sniping_enabled() ? charybdis_get_pointer_sniping_dpi() : charybdis_get_pointer_default_dpi());
            xpos += qp_drawtext_recolor(qp_display, xpos, ypos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_cpi_xpos < xpos) {
                max_cpi_xpos = xpos;
            }
            qp_rect(qp_display, xpos, ypos, max_cpi_xpos, ypos + futurabold->line_height, 0, 0, 0, true);
        }


        // ypos += futurabold->line_height + 4;
        // static user_runtime_config_t last_user_state = {0};
        // if (hue_redraw || last_user_state.raw != user_state.raw) {
        //     last_user_state.raw = user_state.raw;
        //     static int max_upm_xpos = 0;
        //     xpos                    = qp_textwidth(futurabold, "CLCK");
        //     ypos                    = 128 - (futurabold->line_height);
        //     const char* buf = "AUD ";
        //     const char* buf1 = "CLCK ";
        //     const char* buf2 = "HOST ";
        //     const char* buf3 = "SWAP ";
        //     qp_drawtext_recolor(qp_display, 0, ypos, futurabold, buf, last_user_state.audio_enable? 153 : 255, 255, 255, last_user_state.audio_enable ? 153 : 255, 255, 0);
        //     xpos += qp_drawtext_recolor(qp_display, xpos, ypos, futurabold, buf1, last_user_state.audio_clicky_enable ? 153 : 255, 255, 255, last_user_state.audio_clicky_enable ? 153 : 255, 255, 0);
        //     xpos += qp_drawtext_recolor(qp_display, xpos, ypos, futurabold, buf2, last_user_state.host_driver_disabled ? 153 : 255, 255, 255, last_user_state.host_driver_disabled ? 153 : 255, 255, 0);
        //     xpos += qp_drawtext_recolor(qp_display, xpos, ypos, futurabold, buf3, last_user_state.swap_hands ? 153 : 255, 255, 255, last_user_state.swap_hands ? 153 : 255, 255, 0);
        //     if (max_upm_xpos < xpos) {
        //         max_upm_xpos = xpos;
        //     }
        //     qp_rect(qp_display, xpos, ypos, max_upm_xpos, ypos + futurabold->line_height, 0, 0, 0, true);
        // }
    }
    qp_flush(qp_display);
}


void keyboard_post_init_keymap(void) {
    debug_enable   = true;

    // cg_on = qp_load_image_mem(gfx_cg_on);
    // cg_off  = qp_load_image_mem(gfx_cg_off);
    // thintel = qp_load_font_mem(font_thintel);
    iosevka11 = qp_load_font_mem(font_iosevka11);
    futurabold = qp_load_font_mem(font_futurabold);

    // init_and_clear(qp_display, QP_ROTATION_180);
    kb_state.lcd_power = 1;
    qp_power(qp_display, true);

    // wait_ms(50);

    // if (!is_keyboard_left()) {
    // qp_animate(qp_display, 128 - matrix->width,  110 - (matrix->height + iosevka11->line_height), matrix);
    // }

}

#endif


layer_state_t layer_state_set_keymap(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LOWER:
#ifdef HAPTIC_ENABLE
            DRV_pulse(soft_bump);
#endif
            break;
        case _RAISE:
#ifdef HAPTIC_ENABLE
            DRV_pulse(transition_rampup_short_sharp1_50);
#endif
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
            break;
        case _MOUSE:
#ifdef HAPTIC_ENABLE
            DRV_pulse(soft_bump);
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
