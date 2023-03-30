// Copyright (c) 2018 Cirque Corp. Restrictions apply. See: www.cirque.com/sw-license

#pragma once

#include "cirque_pinnacle_regdefs.h"
#include <stdint.h>
#include <stdbool.h>
#include "pointing_device_internal.h"
#include "pointing_device.h"

#ifndef CIRQUE_PINNACLE_TIMEOUT
#    define CIRQUE_PINNACLE_TIMEOUT 20 // I2C timeout in milliseconds
#endif

#define CIRQUE_PINNACLE_ABSOLUTE_MODE 1
#define CIRQUE_PINNACLE_RELATIVE_MODE 0
#ifndef CIRQUE_PINNACLE_POSITION_MODE
#    define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
#endif

#define CIRQUE_PINNACLE_DEFAULT_SCALE 1024
#ifndef CIRQUE_PINNACLE_DIAMETER_MM
#    define CIRQUE_PINNACLE_DIAMETER_MM 40
#endif

#if CIRQUE_PINNACLE_POSITION_MODE
// Coordinate scaling values
#    ifndef CIRQUE_PINNACLE_X_LOWER
#        define CIRQUE_PINNACLE_X_LOWER 127 // min "reachable" X value
#    endif
#    ifndef CIRQUE_PINNACLE_X_UPPER
#        define CIRQUE_PINNACLE_X_UPPER 1919 // max "reachable" X value
#    endif
#    ifndef CIRQUE_PINNACLE_Y_LOWER
#        define CIRQUE_PINNACLE_Y_LOWER 63 // min "reachable" Y value
#    endif
#    ifndef CIRQUE_PINNACLE_Y_UPPER
#        define CIRQUE_PINNACLE_Y_UPPER 1471 // max "reachable" Y value
#    endif
#    ifndef CIRQUE_PINNACLE_X_RANGE
#        define CIRQUE_PINNACLE_X_RANGE (CIRQUE_PINNACLE_X_UPPER - CIRQUE_PINNACLE_X_LOWER)
#    endif
#    ifndef CIRQUE_PINNACLE_Y_RANGE
#        define CIRQUE_PINNACLE_Y_RANGE (CIRQUE_PINNACLE_Y_UPPER - CIRQUE_PINNACLE_Y_LOWER)
#    endif
#    if defined(POINTING_DEVICE_GESTURES_SCROLL_ENABLE)
#        define CIRQUE_PINNACLE_CIRCULAR_SCROLL_ENABLE
#    endif
#else
#    define CIRQUE_PINNACLE_X_RANGE 256
#    define CIRQUE_PINNACLE_Y_RANGE 256
#    if defined(POINTING_DEVICE_GESTURES_SCROLL_ENABLE)
#        define CIRQUE_PINNACLE_SIDE_SCROLL_ENABLE
#    endif
#endif
#if !defined(POINTING_DEVICE_TASK_THROTTLE_MS)
#    define POINTING_DEVICE_TASK_THROTTLE_MS 10 // Cirque Pinnacle in normal operation produces data every 10ms. Advanced configuration for pen/stylus usage might require lower values.
#endif
#if defined(POINTING_DEVICE_DRIVER_CIRQUE_PINNACLE_I2C)
#    include "i2c_master.h"
// Cirque's 7-bit I2C Slave Address
#    ifndef CIRQUE_PINNACLE_ADDR
#        define CIRQUE_PINNACLE_ADDR I2C_ADDRESS_DEFAULT
#    endif
#endif
#if defined(POINTING_DEVICE_DRIVER_CIRQUE_PINNACLE_SPI)
#    include "spi_master.h"
#    ifndef CIRQUE_PINNACLE_CLOCK_SPEED
#        define CIRQUE_PINNACLE_CLOCK_SPEED 10000000
#    endif\\s
#    ifndef CIRQUE_PINNACLE_SPI_MODE
#        define CIRQUE_PINNACLE_SPI_MODE 1
#    endif
#    ifndef CIRQUE_PINNACLE_SPI_DIVISOR
#        ifdef __AVR__
#            define CIRQUE_PINNACLE_SPI_DIVISOR (F_CPU / CIRQUE_PINNACLE_CLOCK_SPEED)
#        else
#            define CIRQUE_PINNACLE_SPI_DIVISOR 64
#        endif
#        ifndef CIRQUE_PINNACLE_SPI_CS_PIN
#            ifdef POINTING_DEVICE_CS_PIN
#                define CIRQUE_PINNACLE_SPI_CS_PIN POINTING_DEVICE_CS_PIN
#            else
#                error "No Chip Select pin has been defined -- missing POINTING_DEVICE_CS_PIN or CIRQUE_PINNACLE_SPI_CS_PIN define"
#            endif
#        endif
#    endif
#endif

#define DIVIDE_UNSIGNED_ROUND(numerator, denominator) (((numerator) + ((denominator) / 2)) / (denominator))
#define CIRQUE_PINNACLE_INCH_TO_PX(inch) (DIVIDE_UNSIGNED_ROUND((inch) * (uint32_t)CIRQUE_PINNACLE_DIAMETER_MM * 10, 254))
#define CIRQUE_PINNACLE_PX_TO_INCH(px) (DIVIDE_UNSIGNED_ROUND((px) * (uint32_t)254, CIRQUE_PINNACLE_DIAMETER_MM * 10))

// Convenient way to store and access measurements
typedef struct {
    bool valid; // true if valid data was read, false if no data was ready
#if CIRQUE_PINNACLE_POSITION_MODE
    uint16_t xValue;
    uint16_t yValue;
    uint16_t zValue;
    uint8_t  buttonFlags;
    bool     touchDown;
#else
    int16_t xDelta;
    int16_t yDelta;
    int8_t  wheelCount;
    uint8_t buttons;
#endif
} pinnacle_data_t;

typedef struct {
    void (*read)(const void* config, uint8_t regaddr, uint8_t* data, uint8_t length);
    void (*write)(const void* config, uint8_t regaddr, uint8_t data);
} cirque_rap_t;

void            cirque_pinnacle_init(const cirque_rap_t* cirque_rap, const void* config);
void            cirque_pinnacle_calibrate(const cirque_rap_t* cirque_rap, const void* config);
void            cirque_pinnacle_cursor_smoothing(const cirque_rap_t* cirque_rap, const void* config, bool enable);
pinnacle_data_t cirque_pinnacle_read_data(const cirque_rap_t* cirque_rap, const void* config);
void            cirque_pinnacle_scale_data(pinnacle_data_t* coordinates, uint16_t xResolution, uint16_t yResolution);
uint16_t        cirque_pinnacle_get_scale(const void* config);
void            cirque_pinnacle_set_scale(const void* config, uint16_t scale);
report_mouse_t  cirque_pinnacle_get_report(const cirque_rap_t* cirque_rap, const void* config);

void cirque_read_i2c(const void* config, uint8_t regaddr, uint8_t* data, uint8_t count);
void cirque_write_i2c(const void* config, uint8_t regaddr, uint8_t data);

void cirque_read_spi(const void* config, uint8_t regaddr, uint8_t* data, uint8_t count);
void cirque_write_spi(const void* config, uint8_t regaddr, uint8_t data);

void           cirque_pinnacle_init_i2c(const void* config);
report_mouse_t cirque_pinnacle_get_report_i2c(const void* config);

void           cirque_pinnacle_init_spi(const void* config);
report_mouse_t cirque_pinnacle_get_report_spi(const void* config);

const cirque_rap_t cirque_read_write_i2c;
const cirque_rap_t cirque_read_write_spi;

const pointing_device_driver_t     cirque_driver_i2c_default;
const pointing_device_i2c_config_t cirque_config_i2c_default;