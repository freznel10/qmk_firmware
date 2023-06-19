<<<<<<<< HEAD:keyboards/emblem/ui/assets/assets.h
﻿/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
========
/* Copyright 2023 Cipulot
>>>>>>>> upstream/develop:keyboards/cipulot/ec_pro2/halconf.h
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

<<<<<<<< HEAD:keyboards/emblem/ui/assets/assets.h
#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif //__has_include("lvgl.h")

LV_IMG_DECLARE(badge_dark);
LV_IMG_DECLARE(sama);

#ifdef __cplusplus
} /*extern "C"*/
#endif
========
#define HAL_USE_ADC TRUE

#include_next <halconf.h>
>>>>>>>> upstream/develop:keyboards/cipulot/ec_pro2/halconf.h
