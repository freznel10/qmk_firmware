// Copyright (c) 2018 Cirque Corp. Restrictions apply. See: www.cirque.com/sw-license
// based on https://github.com/cirque-corp/Cirque_Pinnacle_1CA027/tree/master/Circular_Trackpad
// with modifications and changes for QMK
// refer to documentation: Gen2 and Gen3 (Pinnacle ASIC) at https://www.cirque.com/documentation

#include "cirque_pinnacle.h"
#include "cirque_pinnacle_gestures.h"
#include "wait.h"
#include "timer.h"

#include <stdlib.h>

#ifndef CIRQUE_PINNACLE_ATTENUATION
#    ifdef CIRQUE_PINNACLE_CURVED_OVERLAY
#        define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X
#    else
#        define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X
#    endif
#endif

uint16_t scale_data = CIRQUE_PINNACLE_DEFAULT_SCALE;

void cirque_pinnacle_clear_flags(const cirque_rap_t* cirque_rap, const void* config);
void cirque_pinnacle_enable_feed(const cirque_rap_t* cirque_rap, const void* config, bool feedEnable);

#if CIRQUE_PINNACLE_POSITION_MODE
/*  Logical Scaling Functions */
// Clips raw coordinates to "reachable" window of sensor
// NOTE: values outside this window can only appear as a result of noise
void ClipCoordinates(pinnacle_data_t* coordinates) {
    if (coordinates->xValue < CIRQUE_PINNACLE_X_LOWER) {
        coordinates->xValue = CIRQUE_PINNACLE_X_LOWER;
    } else if (coordinates->xValue > CIRQUE_PINNACLE_X_UPPER) {
        coordinates->xValue = CIRQUE_PINNACLE_X_UPPER;
    }
    if (coordinates->yValue < CIRQUE_PINNACLE_Y_LOWER) {
        coordinates->yValue = CIRQUE_PINNACLE_Y_LOWER;
    } else if (coordinates->yValue > CIRQUE_PINNACLE_Y_UPPER) {
        coordinates->yValue = CIRQUE_PINNACLE_Y_UPPER;
    }
}
#endif

uint16_t cirque_pinnacle_get_scale(const void* config) {
    return scale_data;
}
void cirque_pinnacle_set_scale(const void* config, uint16_t scale) {
    scale_data = scale;
}

// Scales data to desired X & Y resolution
void cirque_pinnacle_scale_data(pinnacle_data_t* coordinates, uint16_t xResolution, uint16_t yResolution) {
#if CIRQUE_PINNACLE_POSITION_MODE
    uint32_t xTemp = 0;
    uint32_t yTemp = 0;

    ClipCoordinates(coordinates);

    xTemp = coordinates->xValue;
    yTemp = coordinates->yValue;

    // translate coordinates to (0, 0) reference by subtracting edge-offset
    xTemp -= CIRQUE_PINNACLE_X_LOWER;
    yTemp -= CIRQUE_PINNACLE_Y_LOWER;

    // scale coordinates to (xResolution, yResolution) range
    coordinates->xValue = (uint16_t)(xTemp * xResolution / CIRQUE_PINNACLE_X_RANGE);
    coordinates->yValue = (uint16_t)(yTemp * yResolution / CIRQUE_PINNACLE_Y_RANGE);
#else
    int32_t        xTemp = 0, yTemp = 0;
    ldiv_t         temp;
    static int32_t xRemainder, yRemainder;

    temp       = ldiv(((int32_t)coordinates->xDelta) * (int32_t)xResolution + xRemainder, (int32_t)CIRQUE_PINNACLE_X_RANGE);
    xTemp      = temp.quot;
    xRemainder = temp.rem;

    temp       = ldiv(((int32_t)coordinates->yDelta) * (int32_t)yResolution + yRemainder, (int32_t)CIRQUE_PINNACLE_Y_RANGE);
    yTemp      = temp.quot;
    yRemainder = temp.rem;

    coordinates->xDelta = (int16_t)xTemp;
    coordinates->yDelta = (int16_t)yTemp;
#endif
}

// Clears Status1 register flags (SW_CC and SW_DR)
void cirque_pinnacle_clear_flags(const cirque_rap_t* cirque_rap, const void* config) {
    cirque_rap->write(config, HOSTREG__STATUS1, HOSTREG__STATUS1_DEFVAL & ~(HOSTREG__STATUS1__COMMAND_COMPLETE | HOSTREG__STATUS1__DATA_READY));
    wait_us(50);
}

// Enables/Disables the feed
void cirque_pinnacle_enable_feed(const cirque_rap_t* cirque_rap, const void* config, bool feedEnable) {
    uint8_t feedconfig1;
    cirque_rap->read(config, HOSTREG__FEEDCONFIG1, &feedconfig1, 1);

    if (feedEnable) {
        feedconfig1 |= HOSTREG__FEEDCONFIG1__FEED_ENABLE;
    } else {
        feedconfig1 &= ~HOSTREG__FEEDCONFIG1__FEED_ENABLE;
    }
    cirque_rap->write(config, HOSTREG__FEEDCONFIG1, feedconfig1);
}

/*  ERA (Extended Register Access) Functions  */
// Reads <count> bytes from an extended register at <address> (16-bit address),
// stores values in <*data>
void ERA_ReadBytes(const cirque_rap_t* cirque_rap, const void* config, uint16_t address, uint8_t* data, uint16_t count) {
    uint8_t  ERAControlValue = 0xFF;
    uint16_t timeout_timer;

    cirque_pinnacle_enable_feed(cirque_rap, config, false); // Disable feed

    cirque_rap->write(config, HOSTREG__EXT_REG_AXS_ADDR_HIGH, (uint8_t)(address >> 8));    // Send upper byte of ERA address
    cirque_rap->write(config, HOSTREG__EXT_REG_AXS_ADDR_LOW, (uint8_t)(address & 0x00FF)); // Send lower byte of ERA address

    for (uint16_t i = 0; i < count; i++) {
        cirque_rap->write(config, HOSTREG__EXT_REG_AXS_CTRL, HOSTREG__EREG_AXS__INC_ADDR_READ | HOSTREG__EREG_AXS__READ); // Signal ERA-read (auto-increment) to Pinnacle

        // Wait for status register 0x1E to clear
        timeout_timer = timer_read();
        do {
            cirque_rap->read(config, HOSTREG__EXT_REG_AXS_CTRL, &ERAControlValue, 1);
        } while ((ERAControlValue != 0x00) && (timer_elapsed(timeout_timer) <= CIRQUE_PINNACLE_TIMEOUT));

        cirque_rap->read(config, HOSTREG__EXT_REG_AXS_VALUE, data + i, 1);

        cirque_pinnacle_clear_flags(cirque_rap, config);
    }
}

// Writes a byte, <data>, to an extended register at <address> (16-bit address)
void ERA_WriteByte(const cirque_rap_t* cirque_rap, const void* config, uint16_t address, uint8_t data) {
    uint8_t  ERAControlValue = 0xFF;
    uint16_t timeout_timer;

    cirque_pinnacle_enable_feed(cirque_rap, config, false); // Disable feed

    cirque_rap->write(config, HOSTREG__EXT_REG_AXS_VALUE, data); // Send data byte to be written

    cirque_rap->write(config, HOSTREG__EXT_REG_AXS_ADDR_HIGH, (uint8_t)(address >> 8));    // Upper byte of ERA address
    cirque_rap->write(config, HOSTREG__EXT_REG_AXS_ADDR_LOW, (uint8_t)(address & 0x00FF)); // Lower byte of ERA address

    cirque_rap->write(config, HOSTREG__EXT_REG_AXS_CTRL, HOSTREG__EREG_AXS__WRITE); // Signal an ERA-write to Pinnacle

    // Wait for status register 0x1E to clear
    timeout_timer = timer_read();
    do {
        cirque_rap->read(config, HOSTREG__EXT_REG_AXS_CTRL, &ERAControlValue, 1);
    } while ((ERAControlValue != 0x00) && (timer_elapsed(timeout_timer) <= CIRQUE_PINNACLE_TIMEOUT));

    cirque_pinnacle_clear_flags(cirque_rap, config);
}

bool cirque_pinnacle_set_adc_attenuation(const cirque_rap_t* cirque_rap, const void* config, uint8_t adcGain) {
    uint8_t adcconfig = 0x00;

    ERA_ReadBytes(cirque_rap, config, EXTREG__TRACK_ADCCONFIG, &adcconfig, 1);
    adcGain &= EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_MASK;
    if (adcGain == (adcconfig & EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_MASK)) {
        return false;
    }
    adcconfig &= ~EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_MASK;
    adcconfig |= adcGain;
    ERA_WriteByte(cirque_rap, config, EXTREG__TRACK_ADCCONFIG, adcconfig);
    ERA_ReadBytes(cirque_rap, config, EXTREG__TRACK_ADCCONFIG, &adcconfig, 1);

    return true;
}

// Changes thresholds to improve detection of fingers
// Not needed for flat overlay?
void cirque_pinnacle_tune_edge_sensitivity(const cirque_rap_t* cirque_rap, const void* config) {
    uint8_t widezmin = 0x00;

    ERA_ReadBytes(cirque_rap, config, EXTREG__XAXIS_WIDEZMIN, &widezmin, 1);
    ERA_WriteByte(cirque_rap, config, EXTREG__XAXIS_WIDEZMIN, 0x04); // magic number from Cirque sample code
    ERA_ReadBytes(cirque_rap, config, EXTREG__XAXIS_WIDEZMIN, &widezmin, 1);

    ERA_ReadBytes(cirque_rap, config, EXTREG__YAXIS_WIDEZMIN, &widezmin, 1);
    ERA_WriteByte(cirque_rap, config, EXTREG__YAXIS_WIDEZMIN, 0x03); // magic number from Cirque sample code
    ERA_ReadBytes(cirque_rap, config, EXTREG__YAXIS_WIDEZMIN, &widezmin, 1);
}

// Perform calibration
void cirque_pinnacle_calibrate(const cirque_rap_t* cirque_rap, const void* config) {
    uint8_t  calconfig;
    uint16_t timeout_timer;

    cirque_rap->read(config, HOSTREG__CALCONFIG1, &calconfig, 1);
    calconfig |= HOSTREG__CALCONFIG1__CALIBRATE;
    cirque_rap->write(config, HOSTREG__CALCONFIG1, calconfig);

    // Calibration takes ~100ms according to GT-AN-090624, doubling the timeout just to be safe
    timeout_timer = timer_read();
    do {
        cirque_rap->read(config, HOSTREG__CALCONFIG1, &calconfig, 1);
    } while ((calconfig & HOSTREG__CALCONFIG1__CALIBRATE) && (timer_elapsed(timeout_timer) <= 200));

    cirque_pinnacle_clear_flags(cirque_rap, config);
}

// Enable/disable cursor smoothing, smoothing is enabled by default
void cirque_pinnacle_cursor_smoothing(const cirque_rap_t* cirque_rap, const void* config, bool enable) {
    uint8_t feedconfig3;

    cirque_rap->read(config, HOSTREG__FEEDCONFIG3, &feedconfig3, 1);
    if (enable) {
        feedconfig3 &= ~HOSTREG__FEEDCONFIG3__DISABLE_CROSS_RATE_SMOOTHING;
    } else {
        feedconfig3 |= HOSTREG__FEEDCONFIG3__DISABLE_CROSS_RATE_SMOOTHING;
    }
    cirque_rap->write(config, HOSTREG__FEEDCONFIG3, feedconfig3);
}

/*  Pinnacle-based TM040040/TM035035/TM023023 Functions  */
void cirque_pinnacle_init(const cirque_rap_t* cirque_rap, const void* config) {

    // send a RESET command now, in case QMK had a soft-reset without a power cycle
    cirque_rap->write(config, HOSTREG__SYSCONFIG1, HOSTREG__SYSCONFIG1__RESET);
    wait_ms(30); // Pinnacle needs 10-15ms to boot, so wait long enough before configuring
    cirque_rap->write(config, HOSTREG__SYSCONFIG1, HOSTREG__SYSCONFIG1_DEFVAL);
    wait_us(50);

    // Host clears SW_CC flag
    cirque_pinnacle_clear_flags(cirque_rap, config);

#if CIRQUE_PINNACLE_POSITION_MODE
    cirque_rap->write(config, HOSTREG__FEEDCONFIG2, HOSTREG__FEEDCONFIG2_DEFVAL);
#else
    // FeedConfig2 (Feature flags for Relative Mode Only)
    uint8_t feedconfig2 = HOSTREG__FEEDCONFIG2__GLIDE_EXTEND_DISABLE | HOSTREG__FEEDCONFIG2__INTELLIMOUSE_MODE;
#    if !defined(CIRQUE_PINNACLE_TAP_ENABLE)
    feedconfig2 |= HOSTREG__FEEDCONFIG2__ALL_TAP_DISABLE;
#    endif
#    if !defined(CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE)
    feedconfig2 |= HOSTREG__FEEDCONFIG2__SECONDARY_TAP_DISABLE;
#    elif !defined(CIRQUE_PINNACLE_TAP_ENABLE)
#        error CIRQUE_PINNACLE_TAP_ENABLE must be defined for CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE to work
#    endif
#    if !defined(CIRQUE_PINNACLE_SIDE_SCROLL_ENABLE)
    feedconfig2 |= HOSTREG__FEEDCONFIG2__SCROLL_DISABLE;
#    endif
    cirque_rap->write(config, HOSTREG__FEEDCONFIG2, feedconfig2);
#endif

    // FeedConfig1 (Data Output Flags)
    cirque_rap->write(config, HOSTREG__FEEDCONFIG1, CIRQUE_PINNACLE_POSITION_MODE ? HOSTREG__FEEDCONFIG1__DATA_TYPE__REL0_ABS1 : HOSTREG__FEEDCONFIG1_DEFVAL);

#if CIRQUE_PINNACLE_POSITION_MODE
    // Host sets z-idle packet count to 5 (default is 0x1E/30)
    cirque_rap->write(config, HOSTREG__ZIDLE, 5);
#endif

    bool calibrate = cirque_pinnacle_set_adc_attenuation(cirque_rap, config, CIRQUE_PINNACLE_ATTENUATION);

#ifdef CIRQUE_PINNACLE_CURVED_OVERLAY
    cirque_pinnacle_tune_edge_sensitivity(cirque_rap, config);
    calibrate = true;
#endif
    if (calibrate) {
        // Force a calibration after setting ADC attenuation
        cirque_pinnacle_calibrate(cirque_rap, config);
    }

    cirque_pinnacle_enable_feed(cirque_rap, config, true);
}

pinnacle_data_t cirque_pinnacle_read_data(const cirque_rap_t* cirque_rap, const void* config) {
    uint8_t         data_ready = 0;
    uint8_t         data[6]    = {0};
    pinnacle_data_t result     = {0};

    // Check if there is valid data available
    cirque_rap->read(config, HOSTREG__STATUS1, &data_ready, 1);
    if ((data_ready & HOSTREG__STATUS1__DATA_READY) == 0) {
        // no data available yet
        result.valid = false; // be explicit
        return result;
    }

    // Read all data bytes
    cirque_rap->read(config, HOSTREG__PACKETBYTE_0, data, 6);

    // Get ready for the next data sample
    cirque_pinnacle_clear_flags(cirque_rap, config);

#if CIRQUE_PINNACLE_POSITION_MODE
    // Decode data for absolute mode
    // Register 0x13 is unused in this mode (palm detection area)
    result.buttonFlags = data[0] & 0x3F;                             // bit0 to bit5 are switch 0-5, only hardware button presses (from input pin on the Pinnacle chip)
    result.xValue      = data[2] | ((data[4] & 0x0F) << 8);          // merge high and low bits for X
    result.yValue      = data[3] | ((data[4] & 0xF0) << 4);          // merge high and low bits for Y
    result.zValue      = data[5] & 0x3F;                             // Z is only lower 6 bits, upper 2 bits are reserved/unused
    result.touchDown   = (result.xValue != 0 || result.yValue != 0); // (0,0) is a "magic coordinate" to indicate "finger touched down"
#else
    // Decode data for relative mode
    // Registers 0x16 and 0x17 are unused in this mode
    result.buttons = data[0] & 0x07; // Only three buttons are supported
    if ((data[0] & 0x10) && data[1] != 0) {
        result.xDelta = -((int16_t)256 - (int16_t)(data[1]));
    } else {
        result.xDelta = data[1];
    }
    if ((data[0] & 0x20) && data[2] != 0) {
        result.yDelta = ((int16_t)256 - (int16_t)(data[2]));
    } else {
        result.yDelta = -((int16_t)data[2]);
    }
    result.wheelCount = ((int8_t*)data)[3];
#endif

    result.valid = true;
    return result;
}

#ifdef POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
static bool cursor_glide_enable = true;

static cursor_glide_context_t glide = {.config = {
                                           .coef       = 102, /* Good default friction coef */
                                           .interval   = 10,  /* 100sps */
                                           .trigger_px = 10,  /* Default threshold in case of hover, set to 0 if you'd like */
                                       }};

void cirque_pinnacle_enable_cursor_glide(bool enable) {
    cursor_glide_enable = enable;
}

void cirque_pinnacle_configure_cursor_glide(float trigger_px) {
    glide.config.trigger_px = trigger_px;
}
#endif

#if CIRQUE_PINNACLE_POSITION_MODE

#    ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
static bool is_touch_down;

bool auto_mouse_activation(report_mouse_t mouse_report) {
    return is_touch_down || mouse_report.x != 0 || mouse_report.y != 0 || mouse_report.h != 0 || mouse_report.v != 0 || mouse_report.buttons;
}
#    endif

report_mouse_t cirque_pinnacle_get_report(const cirque_rap_t* cirque_rap, const void* config) {
    report_mouse_t    temp_report = {0};
    uint16_t          scale       = cirque_pinnacle_get_scale(config);
    pinnacle_data_t   touchData   = cirque_pinnacle_read_data(cirque_rap, config);
    mouse_xy_report_t report_x = 0, report_y = 0;
    static uint16_t   x = 0, y = 0, last_scale = 0;

#    if defined(CIRQUE_PINNACLE_TAP_ENABLE)
    mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, false, POINTING_DEVICE_BUTTON1);
#    endif
#    ifdef POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
    cursor_glide_t glide_report = {0};

    if (cursor_glide_enable) {
        glide_report = cursor_glide_check(&glide);
    }
#    endif

    if (!touchData.valid) {
#    ifdef POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
        if (cursor_glide_enable && glide_report.valid) {
            report_x = glide_report.dx;
            report_y = glide_report.dy;
            goto mouse_report_update;
        }
#    endif
        return temp_report;
    }

    if (touchData.touchDown) {
        pd_dprintf("cirque_pinnacle touchData x=%4d y=%4d z=%2d\n", touchData.xValue, touchData.yValue, touchData.zValue);
    }

#    ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    is_touch_down = touchData.touchDown;
#    endif

    // Scale coordinates to arbitrary X, Y resolution
    cirque_pinnacle_scale_data(&touchData, scale, scale);

    if (!cirque_pinnacle_gestures(&temp_report, touchData)) {
        if (last_scale && scale == last_scale && x && y && touchData.xValue && touchData.yValue) {
            report_x = CONSTRAIN_HID_XY((int16_t)(touchData.xValue - x));
            report_y = CONSTRAIN_HID_XY((int16_t)(touchData.yValue - y));
        }
        x          = touchData.xValue;
        y          = touchData.yValue;
        last_scale = scale;

#    ifdef POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
        if (cursor_glide_enable) {
            if (touchData.touchDown) {
                cursor_glide_update(&glide, report_x, report_y, touchData.zValue);
            } else if (!glide_report.valid) {
                glide_report = cursor_glide_start(&glide);
                if (glide_report.valid) {
                    report_x = glide_report.dx;
                    report_y = glide_report.dy;
                }
            }
        }
#    endif
    }

#    ifdef POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
mouse_report_update:
#    endif
    temp_report.x = report_x;
    temp_report.y = report_y;

    return temp_report;
}

uint16_t cirque_pinnacle_get_cpi(void* config) {
    return CIRQUE_PINNACLE_PX_TO_INCH(cirque_pinnacle_get_scale(config));
}
void cirque_pinnacle_set_cpi(void* config, uint16_t cpi) {
    cirque_pinnacle_set_scale(config, CIRQUE_PINNACLE_INCH_TO_PX(cpi));
}

#else
report_mouse_t cirque_pinnacle_get_report(report_mouse_t mouse_report) {
    pinnacle_data_t touchData = cirque_pinnacle_read_data();

    // Scale coordinates to arbitrary X, Y resolution
    cirque_pinnacle_scale_data(&touchData, cirque_pinnacle_get_scale(), cirque_pinnacle_get_scale());

    if (touchData.valid) {
        mouse_report.buttons = touchData.buttons;
        mouse_report.x = CONSTRAIN_HID_XY(touchData.xDelta);
        mouse_report.y = CONSTRAIN_HID_XY(touchData.yDelta);
        mouse_report.v = touchData.wheelCount;
    }
    return mouse_report;
}
#endif
