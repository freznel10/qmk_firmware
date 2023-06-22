<<<<<<<< HEAD:keyboards/zerfstudios/emblem/halconf.h
/* Copyright 2022 QMK
========
/* Copyright 2023 nacly (https://github.com/Na-Cly)
>>>>>>>> upstream/develop:keyboards/nacly/bigsmoothknob/config.h
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
<<<<<<<< HEAD:keyboards/zerfstudios/emblem/halconf.h

#define HAL_USE_I2C     TRUE
#define HAL_USE_SPI     TRUE
#define HAL_USE_PWM     TRUE

#include_next <halconf.h>
========
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
>>>>>>>> upstream/develop:keyboards/nacly/bigsmoothknob/config.h
