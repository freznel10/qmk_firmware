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

#include "rev1.h"
#include "qp_st77xx_opcodes.h"
#include "qp_st7735_opcodes.h"
#include <qp.h>
#include <qp_comms.h>


#ifndef ST7735_NO_AUTOMATIC_OFFSETS
static inline void st7735_automatic_viewport_offsets(painter_device_t device, painter_rotation_t rotation) {
    struct painter_driver_t *driver = (struct painter_driver_t *)device;

    // clang-format off
    const struct {
        uint16_t offset_x;
        uint16_t offset_y;
    } rotation_offsets_80x160[] = {
        [QP_ROTATION_0]   = { .offset_x = 24, .offset_y =  0 },
        [QP_ROTATION_90]  = { .offset_x =  0, .offset_y = 24 },
        [QP_ROTATION_180] = { .offset_x = 24, .offset_y =  0 },
        [QP_ROTATION_270] = { .offset_x =  0, .offset_y = 24 },
    };
    // clang-format on

    if (driver->panel_width == 80 && driver->panel_height == 160) {
        driver->offset_x = rotation_offsets_80x160[rotation].offset_x;
        driver->offset_y = rotation_offsets_80x160[rotation].offset_y;
    }
}
#endif


bool qp_st7735_init(painter_device_t device, painter_rotation_t rotation) {
    // clang-format off
    const uint8_t st7735_init_sequence[] = {
        // Command,                 Delay, N, Data[N]
        ST77XX_CMD_RESET,              5,  0,
        ST77XX_CMD_SLEEP_OFF,          120,  0,
        ST77XX_CMD_INVERT_ON,          0,  0,
        ST77XX_CMD_INVERT_ON,          0,  0,
        ST7735_SET_FRAME_RATE_CTL_1,   0,  3, 0x05, 0x3A, 0x3A,
        ST7735_SET_FRAME_RATE_CTL_2,   0,  3, 0x05, 0x3A, 0x3A,
        ST7735_SET_FRAME_RATE_CTL_3,   0,  3, 0x05, 0x3A, 0x3A,

        ST7735_SET_INVERSION_CTL,      0,  1, 0x03,

        ST7735_SET_POWER_CTL_1,        0,  3, 0x62, 0x02, 0x04,
        ST7735_SET_POWER_CTL_2,        0,  1, 0xC0,
        ST7735_SET_POWER_CTL_3,        0,  2, 0x0D, 0x00,
        ST7735_SET_POWER_CTL_4,        0,  2, 0x8D, 0x6A,
        ST7735_SET_POWER_CTL_5,        0,  2, 0x8D, 0xEE,

        ST7735_SET_VCOM_CTL,           0,  1, 0x0E,

        ST7735_SET_PGAMMA,             0,  16, 0x10, 0x0E, 0x02, 0x03,
                                               0x0E, 0x07, 0x02, 0x07,
                                               0x0A, 0x12, 0x27, 0x37,
                                               0x00, 0x0D, 0x0E, 0x10,

        ST7735_SET_NGAMMA,             0,  16, 0x10, 0x0E, 0x03, 0x03,
                                               0x0F, 0x06, 0x02, 0x08,
                                               0x0A, 0x13, 0x26, 0x36,
                                               0x00, 0x0D, 0x0E, 0x10,

        ST77XX_SET_PIX_FMT,            0,  1, 0x55, //RGB565
       // ST77XX_SET_MADCTL,             0,  1, 0xA8
        ST77XX_CMD_DISPLAY_ON,        20,  0
    };
    // clang-format on
    qp_comms_bulk_command_sequence(device, st7735_init_sequence, sizeof(st7735_init_sequence));

    // Configure the rotation (i.e. the ordering and direction of memory writes in GRAM)
    const uint8_t madctl[] = {
        [QP_ROTATION_0]   = ST77XX_MADCTL_BGR,
        [QP_ROTATION_90]  = ST77XX_MADCTL_BGR | ST77XX_MADCTL_MX | ST77XX_MADCTL_MV,
        [QP_ROTATION_180] = ST77XX_MADCTL_BGR | ST77XX_MADCTL_MX | ST77XX_MADCTL_MY,
        [QP_ROTATION_270] = ST77XX_MADCTL_BGR | ST77XX_MADCTL_MV | ST77XX_MADCTL_MY,
    };
    qp_comms_command_databyte(device, ST77XX_SET_MADCTL, madctl[rotation]);

    #ifndef ST7735_NO_AUTOMATIC_VIEWPORT_OFFSETS
        st7735_automatic_viewport_offsets(device, rotation);
    #endif // ST7735_NO_AUTOMATIC_VIEWPORT_OFFSETS

    return true;
}

