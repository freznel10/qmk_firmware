<<<<<<<< HEAD:keyboards/zerfstudios/emblem/rev1/rev1.h
/* Copyright 2022 Freznel B. Sta. Ana (Freznel10)
========
/* Copyright (C) 2022 jonylee@hfd
>>>>>>>> upstream/develop:keyboards/akko/5108/halconf.h
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

<<<<<<<< HEAD:keyboards/zerfstudios/emblem/rev1/rev1.h
#include "emblem.h"
#include "quantum.h"

========
#define HAL_USE_I2C TRUE
#define HAL_USE_SPI TRUE
#define SPI_USE_WAIT TRUE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD

#include_next <halconf.h>
>>>>>>>> upstream/develop:keyboards/akko/5108/halconf.h
