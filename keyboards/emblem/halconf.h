<<<<<<<< HEAD:keyboards/emblem/halconf.h
/* Copyright 2022 QMK
========
/* Copyright (C) 2022 jonylee@hfd
>>>>>>>> upstream/develop:keyboards/monsgeek/m5/mcuconf.h
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

<<<<<<<< HEAD:keyboards/emblem/halconf.h
#define HAL_USE_I2C     TRUE
#define HAL_USE_SPI     TRUE
#define HAL_USE_PWM     TRUE

#include_next <halconf.h>
========
#include_next <mcuconf.h>

#undef WB32_SPI_USE_QSPI
#define WB32_SPI_USE_QSPI TRUE

#undef WB32_I2C_USE_I2C1
#define WB32_I2C_USE_I2C1 TRUE
>>>>>>>> upstream/develop:keyboards/monsgeek/m5/mcuconf.h
