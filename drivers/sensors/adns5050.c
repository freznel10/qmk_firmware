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

#include "adns5050.h"
#include "wait.h"
#include "debug.h"
#include "gpio.h"

// Registers
typedef enum {
    ADNS5050_REG_PRODUCT_ID     = 0x00,
    ADNS5050_REG_REVISION_ID    = 0x01,
    ADNS5050_REG_MOTION         = 0x02,
    ADNS5050_REG_DELTA_X        = 0x03,
    ADNS5050_REG_DELTA_Y        = 0x04,
    ADNS5050_REG_SQUAL          = 0x05,
    ADNS5050_REG_SHUTTER_UPPER  = 0x06,
    ADNS5050_REG_SHUTTER_LOWER  = 0x07,
    ADNS5050_REG_MAXIMUM_PIXEL  = 0x08,
    ADNS5050_REG_PIXEL_SUM      = 0x09,
    ADNS5050_REG_MINIMUM_PIXEL  = 0x0a,
    ADNS5050_REG_PIXEL_GRAB     = 0x0b,
    ADNS5050_REG_MOUSE_CONTROL  = 0x0d,
    ADNS5050_REG_MOUSE_CONTROL2 = 0x19,
    ADNS5050_REG_LED_DC_MODE    = 0x22,
    ADNS5050_REG_CHIP_RESET     = 0x3a,
    ADNS5050_REG_PRODUCT_ID2    = 0x3e,
    ADNS5050_REG_INV_REV_ID     = 0x3f,
    ADNS5050_REG_MOTION_BURST   = 0x63,
} adns5050_regs;

const pointing_device_driver_t adns5050_driver_default = {.init = adns5050_init, .get_report = adns5050_get_report, .set_cpi = adns5050_set_cpi, .get_cpi = adns5050_get_cpi};
#if defined(ADNS5050_SCLK_PIN) & defined(ADNS5050_SDIO_PIN) & defined(ADNS5050_CS_PIN)
const pointing_device_3wire_spi_config_t adns5050_config_default = {.cs = ADNS5050_CS_PIN, .sclk = ADNS5050_SCLK_PIN, .sdio = ADNS5050_SDIO_PIN};
#endif

void              adns5050_sync(pointing_device_3wire_spi_config_t* adns5050_config);
uint8_t           adns5050_serial_read(pointing_device_3wire_spi_config_t* adns5050_config);
void              adns5050_serial_write(pointing_device_3wire_spi_config_t* adns5050_config, uint8_t data);
uint8_t           adns5050_read_reg(pointing_device_3wire_spi_config_t* adns5050_config, uint8_t reg_addr);
void              adns5050_write_reg(pointing_device_3wire_spi_config_t* adns5050_config, uint8_t reg_addr, uint8_t data);
report_adns5050_t adns5050_read_burst(pointing_device_3wire_spi_config_t* adns5050_config);
int8_t            adns5050_convert_twoscomp(uint8_t data);

void adns5050_init(const void* config) {
    pointing_device_3wire_spi_config_t* adns5050_config = (pointing_device_3wire_spi_config_t*)config;

    // Initialize the ADNS serial pins.
    setPinOutput(adns5050_config->sclk);
    setPinOutput(adns5050_config->sdio);
    setPinOutput(adns5050_config->cs);

    // reboot the adns.
    // if the adns hasn't initialized yet, this is harmless.
    adns5050_write_reg(adns5050_config, ADNS5050_REG_CHIP_RESET, 0x5a);

    // wait maximum time before adns is ready.
    // this ensures that the adns is actuall ready after reset.
    wait_ms(55);

    // read a burst from the adns and then discard it.
    // gets the adns ready for write commands
    // (for example, setting the dpi).
    adns5050_read_burst(adns5050_config);
}

// Perform a synchronization with the ADNS.
// Just as with the serial protocol, this is used by the slave to send a
// synchronization signal to the master.
void adns5050_sync(pointing_device_3wire_spi_config_t* adns5050_config) {
    writePinLow(adns5050_config->cs);
    wait_us(1);
    writePinHigh(adns5050_config->cs);
}

void adns5050_cs_select(pointing_device_3wire_spi_config_t* adns5050_config) {
    writePinLow(adns5050_config->cs);
}

void adns5050_cs_deselect(pointing_device_3wire_spi_config_t* adns5050_config) {
    writePinHigh(adns5050_config->cs);
}

uint8_t adns5050_serial_read(pointing_device_3wire_spi_config_t* adns5050_config) {
    setPinInput(adns5050_config->sdio);
    uint8_t byte = 0;

    for (uint8_t i = 0; i < 8; ++i) {
        writePinLow(adns5050_config->sclk);
        wait_us(1);

        byte = (byte << 1) | readPin(adns5050_config->sdio);

        writePinHigh(adns5050_config->sclk);
        wait_us(1);
    }

    return byte;
}

void adns5050_serial_write(pointing_device_3wire_spi_config_t* adns5050_config, uint8_t data) {
    setPinOutput(adns5050_config->sdio);

    for (int8_t b = 7; b >= 0; b--) {
        writePinLow(adns5050_config->sclk);

        if (data & (1 << b))
            writePinHigh(adns5050_config->sdio);
        else
            writePinLow(adns5050_config->sdio);

        wait_us(2);

        writePinHigh(adns5050_config->sclk);
    }

    // tSWR. See page 15 of the ADNS spec sheet.
    // Technically, this is only necessary if the next operation is an SDIO
    // read. This is not guaranteed to be the case, but we're being lazy.
    wait_us(4);

    // Note that tSWW is never necessary. All write operations require at
    // least 32us, which exceeds tSWW, so there's never a need to wait for it.
}

// Read a byte of data from a register on the ADNS.
// Don't forget to use the register map (as defined in the header file).
uint8_t adns5050_read_reg(pointing_device_3wire_spi_config_t* adns5050_config, adns5050_regs reg_addr) {
    adns5050_cs_select(adns5050_config);

    adns5050_serial_write(adns5050_config, reg_addr);

    // We don't need a minimum tSRAD here. That's because a 4ms wait time is
    // already included in adns5050_serial_write(), so we're good.
    // See page 10 and 15 of the ADNS spec sheet.
    // wait_us(4);

    uint8_t byte = adns5050_serial_read(adns5050_config);

    // tSRW & tSRR. See page 15 of the ADNS spec sheet.
    // Technically, this is only necessary if the next operation is an SDIO
    // read or write. This is not guaranteed to be the case.
    // Honestly, this wait could probably be removed.
    wait_us(1);

    adns5050_cs_deselect(adns5050_config);

    return byte;
}

void adns5050_write_reg(pointing_device_3wire_spi_config_t* adns5050_config, adns5050_regs reg_addr, uint8_t data) {
    adns5050_cs_select(adns5050_config);
    adns5050_serial_write(adns5050_config, 0b10000000 | reg_addr);
    adns5050_serial_write(adns5050_config, data);
    adns5050_cs_deselect(adns5050_config);
}

report_adns5050_t adns5050_read_burst(pointing_device_3wire_spi_config_t* adns5050_config) {
    adns5050_cs_select(adns5050_config);

    report_adns5050_t data;
    data.dx = 0;
    data.dy = 0;

    adns5050_serial_write(adns5050_config, ADNS5050_REG_MOTION_BURST);

    // We don't need a minimum tSRAD here. That's because a 4ms wait time is
    // already included in adns5050_serial_write(), so we're good.
    // See page 10 and 15 of the ADNS spec sheet.
    // wait_us(4);

    uint8_t x = adns5050_serial_read(adns5050_config);
    uint8_t y = adns5050_serial_read(adns5050_config);

    // Burst mode returns a bunch of other shit that we don't really need.
    // Setting CS to high ends burst mode early.
    adns5050_cs_deselect(adns5050_config);

    data.dx = adns5050_convert_twoscomp(x);
    data.dy = adns5050_convert_twoscomp(y);

    return data;
}

// Convert a two's complement byte from an unsigned data type into a signed
// data type.
int8_t adns5050_convert_twoscomp(uint8_t data) {
    if ((data & 0x80) == 0x80)
        return -128 + (data & 0x7F);
    else
        return data;
}

// Don't forget to use the definitions for CPI in the header file.
void adns5050_set_cpi(const void* config, uint16_t cpi) {
    pointing_device_3wire_spi_config_t* adns5050_config = (pointing_device_3wire_spi_config_t*)config;
    uint8_t                             cpival          = constrain((cpi / 125), 0x1, 0xD); // limits to 0--119

    adns5050_write_reg(adns5050_config, ADNS5050_REG_MOUSE_CONTROL2, 0b10000 | cpival);
}

uint16_t adns5050_get_cpi(const void* config) {
    pointing_device_3wire_spi_config_t* adns5050_config = (pointing_device_3wire_spi_config_t*)config;
    uint8_t                             cpival          = adns5050_read_reg(adns5050_config, ADNS5050_REG_MOUSE_CONTROL2);
    return (uint16_t)((cpival & 0b10000) * 125);
}

bool adns5050_check_signature(pointing_device_3wire_spi_config_t* adns5050_config) {
    uint8_t pid  = adns5050_read_reg(adns5050_config, ADNS5050_REG_PRODUCT_ID);
    uint8_t rid  = adns5050_read_reg(adns5050_config, ADNS5050_REG_REVISION_ID);
    uint8_t pid2 = adns5050_read_reg(adns5050_config, ADNS5050_REG_PRODUCT_ID2);

    return (pid == 0x12 && rid == 0x01 && pid2 == 0x26);
}

report_mouse_t adns5050_get_report(const void* config) {
    pointing_device_3wire_spi_config_t* adns5050_config = (pointing_device_3wire_spi_config_t*)config;

    report_adns5050_t data         = adns5050_read_burst(adns5050_config);
    report_mouse_t    mouse_report = {0};

    if (data.dx != 0 || data.dy != 0) {
        pd_dprintf("Raw ] X: %d, Y: %d\n", data.dx, data.dy);
        mouse_report.x = (mouse_xy_report_t)data.dx;
        mouse_report.y = (mouse_xy_report_t)data.dy;
    }

    return mouse_report;
}