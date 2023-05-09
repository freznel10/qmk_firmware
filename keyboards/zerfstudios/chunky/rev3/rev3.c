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


const pointing_device_config_t pointing_device_configs[POINTING_DEVICE_COUNT] = {
    {.driver = &pmw3360_driver_spi_default, .config = &pmw3360_config_spi_default, .throttle = 10, .invert = INVERT_X, .side = LEFT},
    {.driver = &pmw3360_driver_spi_default, .config = &pmw3360_config_spi_default, .throttle = 10, .invert = INVERT_X, .side = RIGHT},
    {.driver = &ps2_trackpoint_driver_ps2_default, .config = &ps2_trackpoint_config_ps2_default, .side = LEFT}

};
