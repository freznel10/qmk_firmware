/* Copyright 2022 Freznel B. Sta. Ana (@freznel10) <freznel@gmail.com>
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

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS  2
#define MATRIX_COLS  6

/* audio config */
#define AUDIO_PIN          B1
#define AUDIO_PWM_DRIVER   PWMD3
#define AUDIO_PWM_CHANNEL  4
#define AUDIO_PWM_PAL_MODE 2
#define AUDIO_STATE_TIMER  GPTD4

/* trackpoing config */
#define PS2_CLOCK_PIN B6
#define PS2_DATA_PIN A2
// #define PS2_MOUSE_DEBUG_RAW
#define PS2_MOUSE_ROTATE 90

#define PS2_MOUSE_X_MULTIPLIER 2
#define PS2_MOUSE_Y_MULTIPLIER 2
#define PS2_MOUSE_USE_REMOTE_MODE

/* spi config */
#define SPI_DRIVER                           SPID1
#define SPI_SCK_PIN                          A5
#define SPI_SCK_PAL_MODE                     5
#define SPI_MOSI_PIN                         A7
#define SPI_MOSI_PAL_MODE                    5
#define SPI_MISO_PIN                         A6
#define SPI_MISO_PAL_MODE                    5

/* eeprom config */
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A4
// #define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR    64
// #define EXTERNAL_EEPROM_BYTE_COUNT           32768
// #define EXTERNAL_EEPROM_PAGE_SIZE            64
// #define EXTERNAL_EEPROM_ADDRESS_SIZE         2
// #define DEBUG_EEPROM_OUTPUT
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR    64

#define ENABLE_COMPILE_KEYCODE
