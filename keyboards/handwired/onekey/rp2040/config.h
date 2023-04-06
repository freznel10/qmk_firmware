// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define DEBUG_MATRIX_SCAN_RATE

#define QMK_WAITING_TEST_BUSY_PIN GP8
#define QMK_WAITING_TEST_YIELD_PIN GP9

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define BACKLIGHT_PWM_DRIVER PWMD4
#define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_B

#define AUDIO_PIN GP16
#define AUDIO_PWM_DRIVER PWMD0
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A

// #define ADC_PIN GP26

# define POINTING_DEVICE_COUNT 1
#define PMW33XX_CS_PIN GP21

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP20

#define PMW33XX_SPI_DIVISOR 64

// #define CIRQUE_PINNACLE_DIAMETER_MM 40
// #define CIRQUE_PINNACLE_SPI_CS_PIN GP14
// #define POINTING_DEVICE_ROTATION_270
// #define CIRQUE_PINNACLE_TAP_ENABLE
// #define CIRQUE_PINNACLE_CURVED_OVERLAY

// #define PS2_CLOCK_PIN GP6
// #define PS2_DATA_PIN GP5
// #define PS2_MOUSE_USE_REMOTE_MODE
