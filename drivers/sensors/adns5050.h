/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2019 Hiroyuki Okada
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

#include <stdbool.h>
#include <stdint.h>
#include "pointing_device.h"

// CPI values
// clang-format off
#define CPI125  0x11
#define CPI250  0x12
#define CPI375  0x13
#define CPI500  0x14
#define CPI625  0x15
#define CPI750  0x16
#define CPI875  0x17
#define CPI1000 0x18
#define CPI1125 0x19
#define CPI1250 0x1a
#define CPI1375 0x1b
// clang-format on

#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

typedef struct {
    int8_t dx;
    int8_t dy;
} report_adns5050_t;

typedef struct {
    pin_t sdio;
    pin_t sclk;
    pin_t cs;
} adns5050_config_t;

const pointing_device_driver_t adns5050_driver_default;

#if defined(ADNS5050_SCLK_PIN) & defined(ADNS5050_SDIO_PIN) & defined(ADNS5050_CS_PIN)
const adns5050_config_t adns5050_config_default;
#endif

// A bunch of functions to implement the ADNS5050-specific serial protocol.
// Note that the "serial.h" driver is insufficient, because it does not
// manually manipulate a serial clock signal.
void              adns5050_init(const void* config);
void              adns5050_sync(adns5050_config_t* adns5050_config);
uint8_t           adns5050_serial_read(adns5050_config_t* adns5050_config);
void              adns5050_serial_write(adns5050_config_t* adns5050_config, uint8_t data);
uint8_t           adns5050_read_reg(adns5050_config_t* adns5050_config, uint8_t reg_addr);
void              adns5050_write_reg(adns5050_config_t* adns5050_config, uint8_t reg_addr, uint8_t data);
report_adns5050_t adns5050_read_burst(adns5050_config_t* adns5050_config);
void              adns5050_set_cpi(const void* config, uint16_t cpi);
uint16_t          adns5050_get_cpi(const void* config);
int8_t            convert_twoscomp(uint8_t data);
bool              adns5050_check_signature(adns5050_config_t* adns5050_config);
report_mouse_t    adns5050_get_report(const void* config);
