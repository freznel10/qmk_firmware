// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2020 @jola5
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "freznel.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/
// clang-format off
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________GAMING_L0_________________       KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT,KC_R
#define _________________GAMING_L1_________________       KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R
#define _________________GAMING_L2_________________       KC_LSFT,  KC_A,    KC_S,   KC_D,    KC_F
#define _________________GAMING_L3_________________       KC_LCTL,  KC_Z,    KC_X,   KC_C,    KC_V

#define _________________GAMING_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________GAMING_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________GAMING_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________DVORAK_L1_________________       KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________       KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________       KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________       KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH
#define _________________DVORAK_R3_________________       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z


#define ________________DVORAK_AU_L1_______________       KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define ________________DVORAK_AU_L2_______________       KC_O,    KC_A,    KC_E,   KC_I,     KC_U
#define ________________DVORAK_AU_L3_______________       KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define ________________DVORAK_AU_R1_______________       KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define ________________DVORAK_AU_R2_______________       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH
#define ________________DVORAK_AU_R3_______________       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define _________________WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________       KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT
#define _________________WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________NORMAN_L1_________________       KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define _________________NORMAN_L2_________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define _________________NORMAN_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________NORMAN_R1_________________       KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN
#define _________________NORMAN_R2_________________       KC_Y,    KC_N,    KC_I,    KC_O,    KC_U,    KC_QUOT
#define _________________NORMAN_R3_________________       KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________MALTRON_L1________________       KC_Q,    KC_P,    KC_Y,    KC_C,    KC_B
#define _________________MALTRON_L2________________       KC_A,    KC_N,    KC_I,    KC_S,    KC_F
#define _________________MALTRON_L3________________       KC_SCLN, KC_SLSH, KC_J,    KC_G,    KC_COMM

#define _________________MALTRON_R1________________       KC_V,    KC_M,    KC_U,    KC_Z,    KC_L
#define _________________MALTRON_R2________________       KC_D,    KC_T,    KC_D,    KC_O,    KC_R,    KC_QUOT
#define _________________MALTRON_R3________________       KC_DOT,  KC_W,    KC_K,    KC_MINS, KC_X


#define _________________EUCALYN_L1________________       KC_Q,    KC_W,    KC_COMM, KC_DOT,  KC_SCLN
#define _________________EUCALYN_L2________________       KC_A,    KC_O,    KC_E,    KC_I,    KC_U
#define _________________EUCALYN_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_F

#define _________________EUCALYN_R1________________       KC_M,    KC_R,    KC_D,    KC_Y,    KC_P
#define _________________EUCALYN_R2________________       KC_G,    KC_T,    KC_K,    KC_S,    KC_N,    KC_QUOT
#define _________________EUCALYN_R3________________       KC_B,    KC_H,    KC_J,    KC_L,    KC_SLSH

// Qwerty-like
#define _____________CARPLAX_QFMLWY_L1_____________       KC_Q,    KC_F,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QFMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QFMLWY_L3_____________       KC_Z,    KC_V,    KC_G,    KC_C,    KC_X

#define _____________CARPLAX_QFMLWY_R1_____________       KC_Y,    KC_U,    KC_O,    KC_B,    KC_J
#define _____________CARPLAX_QFMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_H,    KC_SCLN, KC_QUOT
#define _____________CARPLAX_QFMLWY_R3_____________       KC_P,    KC_K,    KC_COMM, KC_DOT,  KC_SLSH

// Colemak like
#define _____________CARPLAX_QGMLWB_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QGMLWB_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QGMLWB_L3_____________       KC_Z,    KC_X,    KC_C,    KC_F,    KC_J

#define _____________CARPLAX_QGMLWB_R1_____________       KC_B,    KC_Y,    KC_U,    KC_V,    KC_SCLN
#define _____________CARPLAX_QGMLWB_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT
#define _____________CARPLAX_QGMLWB_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH

// colemak like, zxcv fixed
#define _____________CARPLAX_QGMLWY_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QGMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QGMLWY_L3_____________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_J

#define _____________CARPLAX_QGMLWY_R1_____________       KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN
#define _____________CARPLAX_QGMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT
#define _____________CARPLAX_QGMLWY_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH

// teeheehee
#define _____________CARPLAX_TNWCLR_L1_____________       KC_T,    KC_N,    KC_W,    KC_C,    KC_L
#define _____________CARPLAX_TNWCLR_L2_____________       KC_S,    KC_K,    KC_J,    KC_X,    KC_G
#define _____________CARPLAX_TNWCLR_L3_____________       KC_E,    KC_O,    KC_D,    KC_I,    KC_A

#define _____________CARPLAX_TNWCLR_R1_____________       KC_R,    KC_B,    KC_F,    KC_M,    KC_H
#define _____________CARPLAX_TNWCLR_R2_____________       KC_P,    KC_Q,    KC_Z,    KC_V,    KC_SCLN, KC_QUOT
#define _____________CARPLAX_TNWCLR_R3_____________       KC_U,    KC_Y,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________WHITE_R1__________________       KC_V,    KC_Y,    KC_D,    KC_COMM, KC_QUOT
#define _________________WHITE_R2__________________       KC_A,    KC_T,    KC_H,    KC_E,    KC_B
#define _________________WHITE_R3__________________       KC_P,    KC_K,    KC_G,    KC_W,    KC_Q

#define _________________WHITE_L1__________________       KC_INT1, KC_J,    KC_M,    KC_L,    KC_U
#define _________________WHITE_L2__________________       KC_MINS, KC_C,    KC_S,    KC_N,    KC_O,    KC_I
#define _________________WHITE_L3__________________       KC_X,    KC_R,    KC_F,    KC_DOT,  KC_Z


#define _________________HALMAK_L1_________________       KC_W,    KC_L,    KC_R,    KC_B,    KC_Z
#define _________________HALMAK_L2_________________       KC_S,    KC_H,    KC_N,    KC_T,    KC_COMM
#define _________________HALMAK_L3_________________       KC_F,    KC_M,    KC_V,    KC_V,    KC_SLASH

#define _________________HALMAK_R1_________________       KC_SCLN, KC_Q,    KC_U,    KC_D,    KC_J
#define _________________HALMAK_R2_________________       KC_DOT,  KC_A,    KC_E,    KC_O,    KC_I,    KC_QUOTE
#define _________________HALMAK_R3_________________       KC_G,    KC_P,    KC_X,    KC_K,    KC_Y


#define __________________ISRT_L1__________________       KC_W,    KC_C,    KC_L,    KC_M,    KC_K
#define __________________ISRT_L2__________________       KC_I,    KC_S,    KC_R,    KC_T,    KC_G
#define __________________ISRT_L3__________________       KC_Q,    KC_V,    KC_W,    KC_D,    KC_J

#define __________________ISRT_R1__________________       KC_Z,    KC_F,    KC_U,    KC_COMM, KC_QUOTE
#define __________________ISRT_R2__________________       KC_P,    KC_N,    KC_E,    KC_A,    KC_O,    KC_SCLN
#define __________________ISRT_R3__________________       KC_B,    KC_H,    KC_SLSH, KC_DOT,  KC_X


#define __________________SOUL_L1__________________       KC_Q,    KC_W,    KC_L,    KC_D,    KC_P
#define __________________SOUL_L2__________________       KC_A,    KC_S,    KC_R,    KC_T,    KC_G
#define __________________SOUL_L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_J

#define __________________SOUL_R1__________________       KC_K,    KC_M,    KC_U,    KC_Y,    KC_SCLN
#define __________________SOUL_R2__________________       KC_F,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOTE
#define __________________SOUL_R3__________________       KC_B,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH


#define __________________NIRO_L1__________________       KC_Q,    KC_W,    KC_U,    KC_D,    KC_P
#define __________________NIRO_L2__________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define __________________NIRO_L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define __________________NIRO_R1__________________       KC_J,    KC_F,    KC_Y,    KC_L,    KC_SCLN
#define __________________NIRO_R2__________________       KC_H,    KC_N,    KC_I,    KC_R,    KC_O,    KC_QUOTE
#define __________________NIRO_R3__________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________ASSET_L1__________________       KC_Q,    KC_W,    KC_J,    KC_F,    KC_G
#define _________________ASSET_L2__________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_D
#define _________________ASSET_L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________ASSET_R1__________________       KC_Y,    KC_P,    KC_U,    KC_L,    KC_SCLN
#define _________________ASSET_R2__________________       KC_H,    KC_N,    KC_I,    KC_O,    KC_R,    KC_QUOTE
#define _________________ASSET_R3__________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________MTGAP_L1__________________       KC_Y,    KC_P,    KC_O,    KC_U,    KC_J
#define _________________MTGAP_L2__________________       KC_I,    KC_N,    KC_E,    KC_A,    KC_COMM
#define _________________MTGAP_L3__________________       KC_Q,    KC_Z,    KC_SLSH, KC_DOT,  KC_SCLN

#define _________________MTGAP_R1__________________       KC_K,    KC_D,    KC_L,    KC_C,    KC_W
#define _________________MTGAP_R2__________________       KC_M,    KC_H,    KC_T,    KC_S,    KC_R,    KC_QUOTE
#define _________________MTGAP_R3__________________       KC_B,    KC_F,    KC_G,    KC_V,    KC_X

#define _________________MINIMAK_L1________________       KC_Q,    KC_W,    KC_D,    KC_R,    KC_K
#define _________________MINIMAK_L2________________       KC_A,    KC_S,    KC_T,    KC_F,    KC_G
#define _________________MINIMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________MINIMAK_R1________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________MINIMAK_R2________________       KC_H,    KC_J,    KC_E,    KC_L,    KC_SCLN, KC_QUOT
#define _________________MINIMAK_R3________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ________________MINIMAK_8_L1_______________       KC_Q,    KC_W,    KC_D,    KC_R,    KC_K
#define ________________MINIMAK_8_L2_______________       KC_A,    KC_S,    KC_T,    KC_F,    KC_G
#define ________________MINIMAK_8_L3_______________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ________________MINIMAK_8_R1_______________       KC_Y,    KC_U,    KC_I,    KC_L,    KC_P
#define ________________MINIMAK_8_R2_______________       KC_H,    KC_N,    KC_E,    KC_O,    KC_SCLN, KC_QUOT
#define ________________MINIMAK_8_R3_______________       KC_J,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _______________MINIMAK_12_L1_______________       KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define _______________MINIMAK_12_L2_______________       KC_A,    KC_S,    KC_T,    KC_R,    KC_G
#define _______________MINIMAK_12_L3_______________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _______________MINIMAK_12_R1_______________       KC_Y,    KC_U,    KC_I,    KC_L,    KC_SCLN
#define _______________MINIMAK_12_R2_______________       KC_H,    KC_N,    KC_E,    KC_O,    KC_P,    KC_QUOT
#define _______________MINIMAK_12_R3_______________       KC_J,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ________________NUMPAD1_LEFT_______________       KC_PAST,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS
#define ________________NUMPAD2_LEFT_______________       KC_PSLS,  KC_P4,   KC_P5,   KC_P6,   KC_PMNS
#define ________________NUMPAD3_LEFT_______________       KC_P0,    KC_P1,   KC_P2,   KC_P3,   KC_PDOT
#define ___________________BLANK___________________       _______, _______, _______, _______, _______

#define ________________NUMPAD1_RIGHT______________       KC_PAST,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS
#define ________________NUMPAD2_RIGHT______________       KC_ENT,  KC_RSFT,  KC_RCTL, KC_RALT, KC_RGUI
#define ________________NUMPAD3_RIGHT______________       KC_P0,    KC_P1,   KC_P2,   KC_P3,   KC_PDOT

#define _________________FUNCA_LEFT________________       A(KC_F1),   A(KC_F2),  A(KC_F3),   A(KC_F4),  A(KC_F5)
#define _________________FUNCA_RIGHT_______________       A(KC_F6),   A(KC_F7),  A(KC_F8),   A(KC_F9),  A(KC_F10)

#define _________________LOWER_L1__________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________       C_L,     CS_L,    CS_R,    C_R,   C(KC_W)
#define _________________LOWER_L3__________________       G(KC_LEFT), G(KC_DOWN), G(KC_UP), G(KC_RGHT), A(KC_F4)

#define _________________LOWER_R1__________________       _______, C_L,     CS_L,    CS_R,    C_R
#define _________________LOWER_R2__________________       _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END
#define _________________LOWER_R3__________________       _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR

#define _________________LOWER_R2_ALT______________       _______, C_L,     CS_L,    CS_R,    C_R
#define _________________LOWER_R1_ALT______________       _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END
#define _________________LOWER_R3__________________       _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR

#define _________________RAISE_L1__________________       KC_CIRC, KC_AT,   KC_EXLM, KC_QUES, KC_PERC
#define _________________RAISE_L2__________________       LGUI_T(KC_GRAVE), LALT_T(KC_MINUS), KC_PLUS, LSFT_T(KC_EQUAL), KC_UNDS
#define _________________RAISE_L3__________________       KC_LCBR, KC_LBRC, KC_NUHS, KC_RBRC, KC_RCBR

#define _________________RAISE_R1__________________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________RAISE_R2__________________       KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
#define _________________RAISE_R3__________________       SELWORD, KC_WWW_BACK, KC_PGDN, KC_PGUP, KC_END

#define _________________EXTEND_R1_________________       KC_PGUP, KC_HOME, KC_INS,  KC_END,  KC_PRINT_SCREEN
#define _________________EXTEND_R2_________________       KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
#define _________________EXTEND_R3_________________       SELWORD, KC_HOME, KC_PGDN, KC_PGUP, KC_END

#define _________________UNICO_L1__________________       KC_WIDE, KC_SCRIPT, KC_BLOCKS, KC_REGIONAL, KC_AUSSIE
#define _________________UNICO_R1__________________       KC_ZALGO, KC_SUPER, KC_COMIC, KC_NOMODE, UC(0x2763)

#define _________________ADJUST_L1_________________       RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_IDL
#define _________________ADJUST_L2_________________       MU_TOGG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM
#define _________________ADJUST_L3_________________       RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_RGB_T

#define _________________ADJUST_R1_________________       HF_TOGG, HF_BUZZ, HF_FDBK, HF_PREV, HF_NEXT
#define _________________ADJUST_R2_________________       CG_SWAP, DEFLYR1, DEFLYR2, DEFLYR3, DEFLYR4
#define _________________ADJUST_R3_________________       HF_RST, KC_MUTE, KC_VOLD, HF_CONT, HF_CONU

#define ______________COLEMAK_MOD_DH_Q1____________       KC_Q,         KC_W,         KC_F,         KC_P,         KC_B
#define ______________COLEMAK_MOD_DH_Q2____________       LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G
#define ______________COLEMAK_MOD_DH_Q3____________       LCTL_T(KC_Z),         KC_X,         KC_C,         KC_D,         KC_V

#define ______________COLEMAK_MOD_DH_W1____________       KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN
#define ______________COLEMAK_MOD_DH_W2____________       KC_M,    RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),    KC_QUOT
#define ______________COLEMAK_MOD_DH_W3____________       KC_K,    KC_H,         KC_COMM,      KC_DOT,       RCTL_T(KC_SLASH)
// clang-format on
