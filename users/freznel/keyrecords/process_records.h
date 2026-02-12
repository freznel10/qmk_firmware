// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "freznel.h"

// #if defined(KEYBOARD_zerf9) && defined(POINTING_DEVICE_ENABLE)
// #    define PLACEHOLDER_SAFE_RANGE QK_USER
// #elif defined(KEYBOARD_zerfstudios)
// #    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
// #elif defined(KEYBOARD_bastardkb_charybdis)
// #    define PLACEHOLDER_SAFE_RANGE CHARYBDIS_SAFE_RANGE
// #elif defined(KEYBOARD_rocksolid)
// #    define PLACEHOLDER_SAFE_RANGE ROCKSOLID_SAFE_RANGE
// #elif defined(KEYBOARD_unichunky)
// #    define PLACEHOLDER_SAFE_RANGE UNICHUNKY_SAFE_RANGE
// #elif defined(KEYBOARD_chunkx)
// #    define PLACEHOLDER_SAFE_RANGE CHARYBDIS_SAFE_RANGE
// #elif defined(KEYBOARD_zerfstudios_emblem)
// #    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
// #else
// #    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
// #endif

enum userspace_custom_keycodes {
    VRSN = QK_USER,                           // Prints QMK Firmware and board info
    KC_QWERTY,                                // Sets default layer to QWERTY
    FIRST_DEFAULT_LAYER_KEYCODE = KC_QWERTY,  // Sets default layer to QWERTY
    KC_COLEMAK_DH,                            // Sets default layer to COLEMAK
    KC_COLEMAK,                               // Sets default layer to COLEMAK
    KC_DVORAK,                                // Sets default layer to DVORAK
    LAST_DEFAULT_LAYER_KEYCODE = KC_DVORAK,   // Sets default layer to WORKMAN
    KC_DIABLO_CLEAR,                          // Clears all Diablo Timers
    KC_RGB_T,                                 // Toggles RGB Layer Indication mode
    RGB_IDL,                                  // RGB Idling animations
    KC_SECRET_1,                              // test1
    KC_SECRET_2,                              // test2
    KC_SECRET_3,                              // test3
    KC_SECRET_4,                              // test4
    KC_SECRET_5,                              // test5
    KC_CCCV,                                  // Hold to copy, tap to paste
    KC_NUKE,                                  // NUCLEAR LAUNCH DETECTED!!!
    UC_FLIP,                                  // (ಠ痊ಠ)┻━┻
    UC_TABL,                                  // ┬─┬ノ( º _ ºノ)
    UC_SHRG,                                  // ¯\_(ツ)_/¯
    UC_DISA,                                  // ಠ_ಠ
    UC_IRNY,
    UC_CLUE,
    KEYLOCK,                                  // Locks keyboard by unmounting driver
    KC_NOMODE,
    KC_WIDE,
    KC_SCRIPT,
    KC_BLOCKS,
    KC_REGIONAL,
    KC_AUSSIE,
    KC_ZALGO,
    KC_SUPER,
    KC_COMIC,
    KC_ACCEL,
    DRAG_MOM,
    DRAG_SCROLL,
    CARET,
    MEDIA,
    ALT_TAB,

    BK_TAB,
    NX_TAB,

    SELWORD,

    KB_TG_ACCEL,
    KB_MO_APP,
    KB_MO_WINDOW,
    AM_TOGGLE,
    PM_SWITCH,
    PMR_DRAG,
    PML_DRAG,
    PMR_VOL,
    PML_VOL,

    RAISE_TOGGLE, //combos
    BSPC_LSFT_CLEAR,
    BACKLU,
    UNDO,
    REDO,
    ENTER,
    CUT,
    COPY,
    PASTE,
    KEYPAD,
    LOWER_TOGGLE,
    GAMEPAD_TOGGLE,
    LPAREN,
    RPAREN,
    WBACK,
    WFWD,
    NEXTSEN,
    NEGATIVEPASTE,

    ENC_ALT_TAB,
    ENC_ALT_TAB_REV,
    ALTTABF, // ALT-TAB forward
	ALTTABB, // ALT-TAB backwards
    CTLTABF, //
	CTLTABB, //

    ROUTE,
    ROTATE,
    DRAG_TRACKS,
    PLACE_VIA,
    TRACK_WIDTH,
    VIA_WIDTH,
    TRACK_POSTURE,
    TRACK_CORNER_MODE,

    DYN_MACRO_PROG,
    DYN_MACRO_KEY00,
    DYN_MACRO_KEY01,
    DYN_MACRO_KEY02,
    DYN_MACRO_KEY03,
    DYN_MACRO_KEY04,
    DYN_MACRO_KEY05,
    DYN_MACRO_KEY06,
    DYN_MACRO_KEY07,
    DYN_MACRO_KEY08,
    DYN_MACRO_KEY09,
    DYN_MACRO_KEY10,
    DYN_MACRO_KEY11,
    DYN_MACRO_KEY12,
    DYN_MACRO_KEY13,
    DYN_MACRO_KEY14,
    DYN_MACRO_KEY15,
    ST_MACRO_6,

    USER_SAFE_RANGE // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record);
#ifdef CUSTOM_UNICODE_ENABLE
bool process_record_unicode(uint16_t keycode, keyrecord_t *record);
#endif
#ifdef QUANTUM_PAINTER_ENABLE
bool process_record_painter(uint16_t keycode, keyrecord_t *record);
#endif

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define TG_MODS OS_TOGG
#define TG_GAME TG(_GAMEPAD)

#define OS_LWR OSL(_LOWER)
#define OS_RSE OSL(_RAISE)
#define KC_MAKE QK_MAKE
#define BSP_RSH MT(MOD_RSFT, KC_BSPC)
#define BSP_KEY LT(_KEYPAD, KC_BSPC)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)
#define GSC_LWR LT(_LOWER, QK_GESC)
#define SPC_LSH MT(MOD_LSFT, KC_SPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define C_L C(KC_LEFT)
#define C_R C(KC_RIGHT)
#define CS_L C(S(KC_LEFT))
#define CS_R C(S(KC_RIGHT))

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define QWERTY KC_QWERTY
#define DVORAK KC_DVORAK
#define COLEMAK KC_COLEMAK
#define COLEMAKDH KC_COLEMAK_DH

#define DEFLYR1 FIRST_DEFAULT_LAYER_KEYCODE
#define DEFLYR2 (FIRST_DEFAULT_LAYER_KEYCODE + 1)
#define DEFLYR3 (FIRST_DEFAULT_LAYER_KEYCODE + 2)
#define DEFLYR4 (FIRST_DEFAULT_LAYER_KEYCODE + 3)
#if LAST_DEFAULT_LAYER_KEYCODE > (FIRST_DEFAULT_LAYER_KEYCODE + 3)
#    define DEFLYR5 (FIRST_DEFAULT_LAYER_KEYCODE + 4)
#    define DEFLYR6 (FIRST_DEFAULT_LAYER_KEYCODE + 5)
#    define DEFLYR7 (FIRST_DEFAULT_LAYER_KEYCODE + 6)
#    define DEFLYR8 (FIRST_DEFAULT_LAYER_KEYCODE + 7)
#    if LAST_DEFAULT_LAYER_KEYCODE > (FIRST_DEFAULT_LAYER_KEYCODE + 7)
#        define DEFLYR9 (FIRST_DEFAULT_LAYER_KEYCODE + 8)
#        define DEFLYR10 (FIRST_DEFAULT_LAYER_KEYCODE + 9)
#        define DEFLYR11 (FIRST_DEFAULT_LAYER_KEYCODE + 10)
#        define DEFLYR12 (FIRST_DEFAULT_LAYER_KEYCODE + 11)
#    endif
#endif

#define KC_RESET QK_BOOT
#define KC_RST   KC_RESET

#define BK_LWER LT(_LOWER, KC_BSPC)
#define SP_LWER LT(_LOWER, KC_SPC)
#define DL_RAIS LT(_RAISE, KC_DEL)
#define ET_RAIS LT(_RAISE, KC_ENTER)

#define CTLNUBS MT(MOD_LCTL, KC_NUBS)
#define CTLGRVE MT(MOD_LCTL, KC_GRAVE)
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

/* OSM keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#ifndef OS_MEH
#define OS_MEH OSM(MOD_MEH)
#endif
#ifndef OS_HYPR
#define OS_HYPR OSM(MOD_HYPR)
#endif

#define ALT_APP ALT_T(KC_APP)

#define MG_NKRO NK_TOGG

#define AUTO_CTN AUTOCORRECT_TOGGLE

/*
Custom Keycodes for Diablo 3 layer
But since TD() doesn't work when tap dance is disabled
We use custom codes here, so we can substitute the right stuff
*/
#ifdef TAP_DANCE_ENABLE
#    define KC_D3_1 TD(TD_D3_1)
#    define KC_D3_2 TD(TD_D3_2)
#    define KC_D3_3 TD(TD_D3_3)
#    define KC_D3_4 TD(TD_D3_4)
#else  // TAP_DANCE_ENABLE
#    define KC_D3_1 KC_1
#    define KC_D3_2 KC_2
#    define KC_D3_3 KC_3
#    define KC_D3_4 KC_4
#endif  // TAP_DANCE_ENABLE

#define REBOOT QK_REBOOT

#define PMR_LEFT PML_DRAG
#define PMR_RGHT PMR_VOL
#define PMR_CYD QK_PM_CYCLE_DEVICES
