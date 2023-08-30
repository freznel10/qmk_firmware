<<<<<<<< HEAD:keyboards/zerfstudios/chunky/rev2/rev2.h
<<<<<<<< HEAD:keyboards/zerfstudios/chunky/rev2/rev2.h
/* Copyright 2022 Freznel B. Sta. Ana (Freznel10)
========
/* Copyright 2020 QMK
>>>>>>>> upstream/develop:keyboards/keychron/c2_pro/mcuconf.h
 *
========
/*
 * Copyright 2023 Kevin Gee <info@controller.works>
 * 
>>>>>>>> upstream/develop:keyboards/controllerworks/city42/config.h
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

<<<<<<<< HEAD:keyboards/zerfstudios/chunky/rev2/rev2.h
<<<<<<<< HEAD:keyboards/zerfstudios/chunky/rev2/rev2.h
#include "chunky.h"


========
#include_next <mcuconf.h>

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE
>>>>>>>> upstream/develop:keyboards/keychron/c2_pro/mcuconf.h
========
#define WS2812_PIO_USE_PIO1
#define RGB_MATRIX_LED_COUNT 42

#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP16
#define POINTING_DEVICE_CS_PIN GP17

#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_1X
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
>>>>>>>> upstream/develop:keyboards/controllerworks/city42/config.h
