/* Copyright 2022 Freznel B. Sta. Ana (Freznel10)
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


#include "rev3.h"

const pointing_device_spi_config_t cirque_config_spi_left = {.cs = CIRQUE_PINNACLE_SPI_CS_PIN, .mode = CIRQUE_PINNACLE_SPI_MODE, .divisor = CIRQUE_PINNACLE_SPI_DIVISOR};
const pointing_device_spi_config_t cirque_config_spi_right = {.cs = CIRQUE_PINNACLE_SPI_CS_PIN, .mode = CIRQUE_PINNACLE_SPI_MODE, .divisor = CIRQUE_PINNACLE_SPI_DIVISOR};

const pointing_device_config_t pointing_device_configs[POINTING_DEVICE_COUNT] = {
    {.driver = &cirque_driver_spi_default, .config = &cirque_config_spi_left, .throttle = 10, .side = LEFT},
    {.driver = &cirque_driver_spi_default, .config = &cirque_config_spi_right, .throttle = 10, .side = RIGHT}
};
