/*
<<<<<<<< HEAD:keyboards/zerfpoint/config.h
Copyright 2022 Freznel B. Sta. Ana (@freznel10) <freznel@gmail.com>
========
Copyright 2013 Jun Wako <wakojun@gmail.com>
>>>>>>>> parent of f0b203dcb7 (Merge branch 'feature_pointing_device_scroll_framework' of https://github.com/Alabastard-64/qmk_firmware into pr/18218):quantum/logging/nodebug.h

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

<<<<<<<< HEAD:keyboards/zerfpoint/config.h
#include "config_common.h"

/* USB Device descriptor parameter */
// #define VENDOR_ID    0xFEED
// #define PRODUCT_ID   0x6465
// #define DEVICE_VER   0x0001
// #define MANUFACTURER Freznel


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

========
#ifndef NO_DEBUG
#    define NO_DEBUG
#    include "debug.h"
#    undef NO_DEBUG
#else
#    include "debug.h"
#endif
>>>>>>>> parent of f0b203dcb7 (Merge branch 'feature_pointing_device_scroll_framework' of https://github.com/Alabastard-64/qmk_firmware into pr/18218):quantum/logging/nodebug.h
