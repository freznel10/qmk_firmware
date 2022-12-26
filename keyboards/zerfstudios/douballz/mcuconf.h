/* Copyright 2020 QMK
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

/*
 * This file was auto-generated by:
 *    `qmk chibios-confupdate -i keyboards/tkw/grandiceps/mcuconf.h -r platforms/chibios/BLACKPILL_STM32_F411/configs/mcuconf.h`
 */

#pragma once

#include_next "mcuconf.h"

#undef RP_SIO_I2C_USE_I20
#define RP_SIO_I2C_USE_I20 FALSE

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

#undef RP_PWM_USE_PWM6
#define RP_PWM_USE_PWM6 TRUE

#undef RP_PWM_USE_PWM4
#define RP_PWM_USE_PWM4 TRUE

// #undef RP_SIO_USE_UART0
// #define RP_SIO_USE_UART0 TRUE
// #undef RP_SIO_USE_UART1
// #define RP_SIO_USE_UART1 FALSE

// #undef RP_USB_USE_ERROR_DATA_SEQ_INTR
// #define RP_USB_USE_ERROR_DATA_SEQ_INTR TRUE
