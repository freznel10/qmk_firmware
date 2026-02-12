// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2022 Freznel B. Sta. Ana  (@freznel10) <freznel@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Use custom magic number so that when switching branches, EEPROM always gets reset
#define EECONFIG_MAGIC_NUMBER   (uint16_t)0x1339

#ifdef IS_COMMAND
#undef IS_COMMAND
#endif
#define IS_COMMAND() (((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) == MOD_MASK_SHIFT)

/* Set Polling rate to 1000Hz */
// #define USB_POLLING_INTERVAL_MS 1


#if defined(SPLIT_KEYBOARD)
#    include "split/split_config.h"
#endif

#if defined(WPM_ENABLE)
// #    define WPM_LAUNCH_CONTROL
// #    define WPM_ALLOW_COUNT_REGRESSOIN
#    define WPM_UNFILTERED
#    define WPM_SAMPLE_SECONDS      10
#    define WPM_SAMPLE_PERIODS      50
#    define WPM_ESTIMATED_WORD_SIZE 5
#endif



#ifdef AUDIO_ENABLE
#    define AUDIO_CLICKY
#    define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f

#    ifdef USER_SONG_LIST
// #        define STARTUP_SONG SONG(IMPERIAL_MARCH)
#        define GOODBYE_SONG SONG(SONIC_RING)
#        define DEFAULT_LAYER_SONGS \
            { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND), SONG(OVERWATCH_THEME) }
#        define UNICODE_SONG_MAC  SONG(MARIO_THEME)
#        define UNICODE_SONG_LNX  SONG(MARIO_POWERUP)
#        define UNICODE_SONG_WIN  SONG(MARIO_ONEUP)
#        define UNICODE_SONG_BSD  SONG(RICK_ROLL)
#        define UNICODE_SONG_WINC SONG(RICK_ROLL)
#    else
#        define STARTUP_SONG SONG(STARTUP_SOUND)
#        define GOODBYE_SONG SONG(GOODBYE_SOUND)
#        define DEFAULT_LAYER_SONGS \
            { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND), SONG(WORKMAN_SOUND) }
#        define UNICODE_SONG_MAC  SONG(QWERTY_SOUND)
#        define UNICODE_SONG_LNX  SONG(COLEMAK_SOUND)
#        define UNICODE_SONG_WIN  SONG(DVORAK_SOUND)
#        define UNICODE_SONG_BSD  SONG(WORKMAN_SOUND)
#        define UNICODE_SONG_WINC SONG(PLOVER_GOODBYE_SOUND)
#    endif
#endif  // !AUDIO_ENABLE

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_EFFECT_TWINKLE_LIFE        250
#    define RGBLIGHT_EFFECT_TWINKLE_PROBABILITY 1 / 24
#endif  // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
#    include "rgb/rgb_matrix_config.h"
#endif // RGB_MATRIX_ENABLE

#ifdef OLED_ENABLE
#    ifdef SPLIT_KEYBOARD
#        define OLED_UPDATE_INTERVAL 60
#    else
#        define OLED_UPDATE_INTERVAL 15
#    endif
#    define OLED_DISABLE_TIMEOUT
#    ifdef OLED_FONT_H
#        undef OLED_FONT_H
#    endif
#    define OLED_FONT_H   "oled/freznel_font.h"
#    define OLED_FONT_END 255
// #    define OLED_FONT_5X5
 #    define OLED_FONT_AZTECH
// #    define OLED_FONT_BMPLAIN
// #    define OLED_FONT_CRACKERS
// #    define OLED_FONT_DEAD_MEAL
// #    define OLED_FONT_EIN
// #    define OLED_FONT_HISKYF21
// #    define OLED_FONT_SQUASH
// #    define OLED_FONT_ZXPIX
// #    define OLED_FONT_SUPER_DIGG

 #    define OLED_LOGO_BEBOP
// #    define OLED_LOGO_CORNE
// #    define OLED_LOGO_GMK_BAD
// #    define OLED_LOGO_GOTHAM
// #    define OLED_LOGO_HUE_MANITEE
// #    define OLED_LOGO_LOOSE
//  #    define OLED_LOGO_SCIFI
// #    define OLED_LOGO_SETS3N
// #    define OLED_LOGO_SKEEB
//#    define OLED_LOGO_FREZNEL
#endif

// #define WPM_ESTIMATED_WORD_SIZE 5
#define WPM_ALLOW_COUNT_REGRESSION
// #define WPM_UNFILTERED
// #define WPM_SAMPLE_SECONDS 5
// #define WPM_SAMPLE_PERIODS 50
// #define WPM_LAUNCH_CONTROL


#ifndef ONESHOT_TAP_TOGGLE
#    define ONESHOT_TAP_TOGGLE 2
#endif  // !ONESHOT_TAP_TOGGLE

#ifndef ONESHOT_TIMEOUT
#    define ONESHOT_TIMEOUT 3000
#endif  // !ONESHOT_TIMEOUT

#if defined(PER_KEY_TAPPING)
#    define PERMISSIVE_HOLD_PER_KEY
#    define QUICK_TAP_TERM_PER_KEY
#    define HOLD_ON_OTHER_KEY
#    define RETRO_TAPPING_PER_KEY
#    define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#    define TAPPING_TERM_PER_KEY
#else
#    define IGNORE_MOD_TAP_INTERRUPT
#    undef PERMISSIVE_HOLD
#endif
#define AUTO_MOUSE_DEFAULT_LAYER 4

#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 1
#endif

#define TAP_CODE_DELAY 5

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif

#ifdef CONVERT_TO_PROTON_C
// pins that are available but not present on Pro Micro
#    define A3  PAL_LINE(GPIOA, 3)
#    define A4  PAL_LINE(GPIOA, 4)
#    define A5  PAL_LINE(GPIOA, 5)
#    define A6  PAL_LINE(GPIOA, 6)
#    define A7  PAL_LINE(GPIOA, 7)
#    define A8  PAL_LINE(GPIOA, 8)
#    define A13 PAL_LINE(GPIOA, 13)
#    define A14 PAL_LINE(GPIOA, 14)
#    define A15 PAL_LINE(GPIOA, 15)
#    define B10 PAL_LINE(GPIOB, 10)
#    define B11 PAL_LINE(GPIOB, 11)
#    define B12 PAL_LINE(GPIOB, 12)
#    define C13 PAL_LINE(GPIOC, 13)
#    define C14 PAL_LINE(GPIOC, 14)
#    define C15 PAL_LINE(GPIOC, 15)
#endif

#ifdef OLED_DRIVER_SH1107
#    define OLED_DISPLAY_CUSTOM
#    define OLED_IC_SH1107 2
#    define OLED_DISPLAY_128X128
#    define OLED_DISPLAY_WIDTH 128
#    define OLED_DISPLAY_HEIGHT 128
#    define OLED_MATRIX_SIZE (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH)
#    define OLED_BLOCK_TYPE uint32_t
#    define OLED_SOURCE_MAP \
        { 0, 8, 16, 24, 32, 40, 48, 56 }
#    define OLED_TARGET_MAP \
        { 56, 48, 40, 32, 24, 16, 8, 0 }
#    define OLED_BLOCK_COUNT (sizeof(OLED_BLOCK_TYPE) * 8)
#    define OLED_BLOCK_SIZE (OLED_MATRIX_SIZE / OLED_BLOCK_COUNT)
#    define OLED_COM_PINS COM_PINS_ALT
#    define OLED_IC OLED_IC_SH1107
#    ifndef OLED_BRIGHTNESS
#        define OLED_BRIGHTNESS 50
#    endif
#    if !defined(STM32F4XX)
#        undef OLED_UPDATE_INTERVAL
#        define OLED_UPDATE_INTERVAL 75
#    endif
#endif

#define ENABLE_COMPILE_KEYCODE

#define AUTOCORRECT_DATA_H "users/freznel/keyrecords/autocorrection/autocorrection_data.h"

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
