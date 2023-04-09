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


#include "rev2.h"

#include <qp.h>
#include <qp_comms.h>

#include "qp_st77xx_opcodes.h"
#include "qp_st7789_opcodes.h"

// #ifdef QUANTUM_PAINTER_DRIVERS_ST7789_SPI

#ifndef ST7789_NO_AUTOMATIC_OFFSETS
static inline void st7789_automatic_viewport_offsets(painter_device_t device, painter_rotation_t rotation) {
    struct painter_driver_t *driver = (struct painter_driver_t *)device;

    // clang-format off
    const struct {
        uint16_t offset_x;
        uint16_t offset_y;
    } rotation_offsets_240x240[] = {
        [QP_ROTATION_0]   = { .offset_x =  0, .offset_y =  0 },
        [QP_ROTATION_90]  = { .offset_x =  0, .offset_y =  0 },
        [QP_ROTATION_180] = { .offset_x =  0, .offset_y = 80 },
        [QP_ROTATION_270] = { .offset_x = 80, .offset_y =  0 },
    };
    // clang-format on

    if (driver->panel_width == 240 && driver->panel_height == 240) {
        driver->offset_x = rotation_offsets_240x240[rotation].offset_x;
        driver->offset_y = rotation_offsets_240x240[rotation].offset_y;
    }
}
#endif

bool qp_st7789_init(painter_device_t device, painter_rotation_t rotation) {
    // clang-format off
    const uint8_t st7789_init_sequence[] = {
        // Command,                 Delay, N, Data[N]

        ST77XX_CMD_RESET,              5,  0,
        ST77XX_CMD_SLEEP_OFF,          120,  0,
        ST77XX_SET_PIX_FMT,            0,  1, 0x55, //0x5
        ST77XX_SET_MADCTL,             0,  1, 0x00, //0x70
        ST7789_SET_PORCH_CTL,          0,  5, 0x0C, 0x0C, 0x0C0,
                                              0x33, 0x33,

        ST7789_SET_GATE_CTL,           0,  1, 0x35,

        ST7789_SET_VCOM,                0, 1, 0x35,

        ST7789_SET_LCM_CTL,             0, 1, 0x2C,

        ST7789_SET_VDV_VRH_ON,          0, 1, 0x01,

        ST7789_SET_VRH,                 0, 1, 0x13,

        ST7789_SET_VDV,                 0, 1, 0x20,

        ST7789_SET_FRAME_RATE_CTL_2,    0, 1, 0x0F,

        ST7789_SET_POWER_CTL_1,         0, 2, 0xA4, 0xA1,

        0xD6,                           0, 1, 0xA1,

        ST7789_SET_PGAMMA,             0,  14, 0xF0, 0x00, 0x04, 0x04,
                                               0x04, 0x05, 0x29, 0x33,
                                               0x3E, 0x38, 0x12, 0x12,
                                               0x28, 0x30,

        ST7789_SET_NGAMMA,             0,  14, 0xF0, 0x07, 0x0A, 0x0D,
                                               0x0B, 0x07, 0x28, 0x33,
                                               0x3E, 0x36, 0x14, 0x14,
                                               0x29, 0x32,

        ST77XX_CMD_INVERT_ON,           0, 0,
        ST77XX_CMD_NORMAL_ON,           0, 0,
        ST77XX_CMD_SLEEP_OFF,           120, 0,

        ST77XX_SET_PIX_FMT,            0,  1, 0x55, //RGB565

        ST77XX_CMD_DISPLAY_ON,          20,  0
    };
    // clang-format on
    qp_comms_bulk_command_sequence(device, st7789_init_sequence, sizeof(st7789_init_sequence));

    // Configure the rotation (i.e. the ordering and direction of memory writes in GRAM)
    const uint8_t madctl[] = {
        [QP_ROTATION_0]   = ST77XX_MADCTL_RGB,
        [QP_ROTATION_90]  = ST77XX_MADCTL_RGB | ST77XX_MADCTL_MX | ST77XX_MADCTL_MV,
        [QP_ROTATION_180] = ST77XX_MADCTL_RGB | ST77XX_MADCTL_MX | ST77XX_MADCTL_MY,
        [QP_ROTATION_270] = ST77XX_MADCTL_RGB | ST77XX_MADCTL_MV | ST77XX_MADCTL_MY,
    };
    qp_comms_command_databyte(device, ST77XX_SET_MADCTL, madctl[rotation]);

#ifndef ST7789_NO_AUTOMATIC_VIEWPORT_OFFSETS
    st7789_automatic_viewport_offsets(device, rotation);
#endif // ST7789_NO_AUTOMATIC_VIEWPORT_OFFSETS

    return true;
}

// #endif //QUANTUM_PAINTER_DRIVERS_ST7789_SPI
