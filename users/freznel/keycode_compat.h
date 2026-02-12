// Copyright 2026 Freznel B. Sta. Ana (@freznel10)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef HAPTIC_ENABLE
#    include "drivers/haptic/drv2605l.h"
#endif

#ifndef RGB_TOG
#    define RGB_TOG QK_UNDERGLOW_TOGGLE
#endif
#ifndef RGB_MOD
#    define RGB_MOD QK_UNDERGLOW_MODE_NEXT
#endif
#ifndef RGB_RMOD
#    define RGB_RMOD QK_UNDERGLOW_MODE_PREVIOUS
#endif
#ifndef RGB_HUI
#    define RGB_HUI QK_UNDERGLOW_HUE_UP
#endif
#ifndef RGB_HUD
#    define RGB_HUD QK_UNDERGLOW_HUE_DOWN
#endif
#ifndef RGB_SAI
#    define RGB_SAI QK_UNDERGLOW_SATURATION_UP
#endif
#ifndef RGB_SAD
#    define RGB_SAD QK_UNDERGLOW_SATURATION_DOWN
#endif
#ifndef RGB_VAI
#    define RGB_VAI QK_UNDERGLOW_VALUE_UP
#endif
#ifndef RGB_VAD
#    define RGB_VAD QK_UNDERGLOW_VALUE_DOWN
#endif
#ifndef RGB_SPI
#    define RGB_SPI QK_UNDERGLOW_SPEED_UP
#endif
#ifndef RGB_SPD
#    define RGB_SPD QK_UNDERGLOW_SPEED_DOWN
#endif

#ifndef RESET
#    define RESET QK_BOOT
#endif

#if !defined(MAGIC_TOGGLE_NKRO)
#    define MAGIC_TOGGLE_NKRO NK_TOGG
#endif

#ifndef NEW_SAFE_RANGE
#    define NEW_SAFE_RANGE USER_SAFE_RANGE
#endif

#ifndef UC_MOD
#    define UC_MOD UC_NEXT
#endif

#ifndef SH_TG
#    define SH_TG SH_TOGG
#endif

#if !defined(KC_BTN1)
#    define KC_BTN1 MS_BTN1
#endif
#if !defined(KC_BTN2)
#    define KC_BTN2 MS_BTN2
#endif
#if !defined(KC_BTN3)
#    define KC_BTN3 MS_BTN3
#endif
#if !defined(KC_BTN4)
#    define KC_BTN4 MS_BTN4
#endif
#if !defined(KC_BTN5)
#    define KC_BTN5 MS_BTN5
#endif
#if !defined(KC_BTN6)
#    define KC_BTN6 MS_BTN6
#endif
#if !defined(KC_BTN7)
#    define KC_BTN7 MS_BTN7
#endif
#if !defined(KC_BTN8)
#    define KC_BTN8 MS_BTN8
#endif

#if !defined(KC_WH_U)
#    define KC_WH_U MS_WHLU
#endif
#if !defined(KC_WH_D)
#    define KC_WH_D MS_WHLD
#endif
#if !defined(KC_WH_L)
#    define KC_WH_L MS_WHLL
#endif
#if !defined(KC_WH_R)
#    define KC_WH_R MS_WHLR
#endif

#if !defined(XY_REPORT_MIN)
#    define XY_REPORT_MIN MOUSE_REPORT_XY_MIN
#endif
#if !defined(XY_REPORT_MAX)
#    define XY_REPORT_MAX MOUSE_REPORT_XY_MAX
#endif

#ifndef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY 0
#endif
#ifndef MOUSEKEY_WHEEL_INTERVAL
#    define MOUSEKEY_WHEEL_INTERVAL 16
#endif

#if !defined(soft_bump)
#    define soft_bump DRV2605L_EFFECT_SOFT_BUMP_100
#endif
#if !defined(transition_rampup_short_sharp1_50)
#    define transition_rampup_short_sharp1_50 DRV2605L_EFFECT_TRANSITION_RAMP_DOWN_LONG_SHARP_1_100
#endif
#if !defined(lg_dblclick_str)
#    define lg_dblclick_str DRV2605L_EFFECT_SHORT_DOUBLE_CLICK_STRONG_1_100
#endif
#if !defined(sharp_click)
#    define sharp_click DRV2605L_EFFECT_SHARP_TICK_1_100
#endif
#if !defined(pulsing_sharp)
#    define pulsing_sharp DRV2605L_EFFECT_PULSING_SHARP_1_100
#endif
