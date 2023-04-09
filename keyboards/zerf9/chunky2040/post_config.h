/*
<<<<<<<< HEAD:keyboards/zerf9/chunky2040/post_config.h
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
========
Copyright 2022 Joe Scotto
>>>>>>>> upstream/develop:keyboards/handwired/jscotto/scotto40/keymaps/default/config.h

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

<<<<<<<< HEAD:keyboards/zerf9/chunky2040/post_config.h
#ifndef RGBLIGHT_LIMIT_VAL
#    if defined(OLED_ENABLE)
#        define RGBLIGHT_LIMIT_VAL 100
#    else
#        define RGBLIGHT_LIMIT_VAL 150
#    endif
#endif

#ifndef OLED_BRIGHTNESS
#    ifdef RGBLIGHT_ENABLE
#        define OLED_BRIGHTNESS 80
#    else
#        define OLED_BRIGHTNESS 150
#    endif
#endif
========
// Define options
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 135
#define PERMISSIVE_HOLD
#define TAPPING_TERM_PER_KEY
>>>>>>>> upstream/develop:keyboards/handwired/jscotto/scotto40/keymaps/default/config.h
