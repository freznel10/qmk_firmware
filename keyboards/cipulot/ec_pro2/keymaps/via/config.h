<<<<<<<< HEAD:keyboards/keychron/q12/mcuconf.h
/* Copyright 2020 QMK
========
/* Copyright 2023 Cipulot
>>>>>>>> upstream/develop:keyboards/cipulot/ec_pro2/keymaps/via/config.h
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

<<<<<<<< HEAD:keyboards/keychron/q12/mcuconf.h
#include_next <mcuconf.h>

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE
========
// This is the size of the EEPROM for the custom VIA-specific data
#define EECONFIG_USER_DATA_SIZE 4
>>>>>>>> upstream/develop:keyboards/cipulot/ec_pro2/keymaps/via/config.h
