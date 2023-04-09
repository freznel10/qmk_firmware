/*
<<<<<<<< HEAD:keyboards/zerf9/space_control1/post_config.h
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
========
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2023 André Büsgen <andre.buesgen@posteo.de>
>>>>>>>> upstream/develop:keyboards/handwired/dactyl_manuform/4x6/keymaps/via/config.h

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

<<<<<<<< HEAD:keyboards/zerf9/space_control1/post_config.h
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
/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT

#define EE_HANDS
>>>>>>>> upstream/develop:keyboards/handwired/dactyl_manuform/4x6/keymaps/via/config.h
