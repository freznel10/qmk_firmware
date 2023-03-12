<<<<<<<< HEAD:keyboards/zerfstudios/common/ui/settings/screensaver/screensaver.h
﻿/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
========
/* Copyright 2022 Cole Smith <cole@boardsource.xyz>
 * Copyright 2022 David Rambo <davidrambo@mailfence.com>
>>>>>>>> upstream/develop:keyboards/boardsource/lulu/keymaps/davidrambo/config.h
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

#pragma once

<<<<<<<< HEAD:keyboards/zerfstudios/common/ui/settings/screensaver/screensaver.h
#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif //__has_include("lvgl.h")

    void set_sama_svr(void);
    void set_logo_svr(void);

    void show_screensaver(void);
    void hide_screensaver(void);
    void disable_lvgl(void);

#ifdef __cplusplus
} /*extern "C"*/
========
#define MASTER_RIGHT
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.

#define TAPPING_TERM 210
/*#define PERMISSIVE_HOLD*/
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#ifdef RGB_MATRIX_ENABLE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
>>>>>>>> upstream/develop:keyboards/boardsource/lulu/keymaps/davidrambo/config.h
#endif
