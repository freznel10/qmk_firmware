<<<<<<<< HEAD:keyboards/emblem/keymaps/freznel/graphics/djinn.h
/* Copyright 2021 QMK
========
/* Copyright 2020 QMK
>>>>>>>> Alabastard-64/feature_pointing_device_scroll_framework:keyboards/keychron/q12/mcuconf.h
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

<<<<<<<< HEAD:keyboards/emblem/keymaps/freznel/graphics/djinn.h
/*
 * This file was auto-generated by `qmk painter-convert-graphics -i djinn.png -f mono16`
 */

#pragma once

#include <qp.h>

extern painter_image_t gfx_djinn PROGMEM;
========
#pragma once

#include_next <mcuconf.h>

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE
>>>>>>>> Alabastard-64/feature_pointing_device_scroll_framework:keyboards/keychron/q12/mcuconf.h
