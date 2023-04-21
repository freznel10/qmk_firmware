// Copyright 2023 Freznel B. Sta. Ana (@freznel10)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


// #define PS2_MOUSE_REMOTE_MODE

#define MATRIX_SHIFT_REGISTER_COUNT 12
#define SPI_MATRIX_CHIP_SELECT_PIN GP21
#define SPI_MATRIX_DIVISOR 16

/* RGB configuration*/
#ifdef RGB_MATRIX_ENABLE
    #define WS2812_DI_PIN GP25
    #define WS2812_PIO_USE_PIO0
    #define RGB_MATRIX_LED_COUNT 68
#endif

/* Audio configuration */
#ifdef AUDIO_ENABLE
    #define AUDIO_PIN GP24
    #define AUDIO_PWM_DRIVER PWMD4
    #define AUDIO_PWM_CHANNEL 1
#endif //AUDIO_ENABLE

/* Backlight configuration for TFT Screen */
#ifdef BACKLIGHT_ENABLE
    #define BACKLIGHT_PWM_DRIVER PWMD3
    #define BACKLIGHT_PWM_CHANNEL 2
#endif //BACKLIGHT_ENABLE

/* serial.c configuration for split keyboard */
#define SERIAL_USART_FULL_DUPLEX  // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN      GP0
#define SERIAL_USART_RX_PIN      GP1
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 806400 //460800

#define SERIAL_USART_PIN_SWAP
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

#define SPLIT_ACTIVITY_ENABLE

#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC
#define SPLIT_MAX_CONNECTION_ERRORS 10

#define SPLIT_HAND_PIN  GP4

/* i2c configuration */
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN      GP2
#define I2C1_SDA_PIN      GP3
#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

/* EEPROM configuration */
#define EEPROM_I2C_MB85RC256V

#ifdef HAPTIC_ENABLE
    #define SPLIT_HAPTIC_ENABLE
#   if defined(USE_VL91022_LRA)
	#define FB_ERM_LRA 1
	#define FB_BRAKEFACTOR 2
	#define FB_LOOPGAIN 3

	// Refer to datasheet for the optimal setting for specific motors.
	#define RATED_VOLTAGE 3
	#define V_PEAK 3.3
	#define V_RMS 1.65
	#define F_LRA 160
#else
	#define FB_ERM_LRA 1
	#define FB_BRAKEFACTOR 2
	#define FB_LOOPGAIN 3

	// Refer to datasheet for the optimal setting for specific motors.
	#define RATED_VOLTAGE 2
	#define V_PEAK 2.0
	#define V_RMS 2.05
	#define F_LRA 200
#endif
	//#define HAPTIC_OFF_IN_LOW_POWER 1 //Turn off haptic feedback while sleeping (+54).
	// #define NO_HAPTIC_PUNCTUATION
	#define NO_HAPTIC_ALPHA
	// #define NO_HAPTIC_MOD
    // #define NO_HAPTIC_FN
    #define DRV_GREETING       alert_750ms
    #define DRV_MODE_DEFAULT   sharp_tick1
	// #define NO_HAPTIC_NUMERIC
	// #define NO_HAPTIC_NAV
#endif //HAPTIC_ENABLE

/* SPI configuration. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP20

/* Pointing device configuration. */
#ifdef POINTING_DEVICE_ENABLE
    #define SPLIT_POINTING_ENABLE
    #define POINTING_DEVICE_COMBINED
    #define POINTING_MODES_NUM_DEVICES 2
    #define POINTING_DEVICE_TASK_THROTTLE_MS 10
    #define POINTING_DEVICE_MODES_ENABLE
    #define POINTING_MODE_MAP_COUNT 10
    #define POINTING_DEFAULT_DIVISOR 64
    #define POINTING_HISTORY_DIVISOR 64
    #define POINTING_VOLUME_DIVISOR 64
    #define POINTING_CARET_DIVISOR 32
    #define POINTING_CARET_DIVISOR_V 32
    #define POINTING_CARET_DIVISOR_H 32
    #define POINTING_PRECISION_DIVISOR 4
    #define POINTING_DRAG_DIVISOR 4
    #define POINTING_MODE_DEFAULT PM_NONE

    #define MOUSE_EXTENDED_REFORT
    #define POINTING_DEVICE_COUNT 2

    #define AUTO_MOUSE_DEFAULT_LAYER 4
    #define AUTO_MOUSE_TIME 650
    #define AUTO_MOUSE_DEBOUNCE 25

    #ifdef POINTING_DEVICE_DRIVER_PMW3360
        #define PMW33XX_LIFTOFF_DISTANCE 0x03
        #define POINTING_DEVICE_INVERT_X
        #define POINTING_DEVICE_INVERT_X_RIGHT
        #define PMW33XX_CS_PIN GP14
    #endif //POINTING_DEVICE_DRIVER_PMW3360

     #ifdef POINTING_DEVICE_DRIVER_CIRQUE_PINNACLE_SPI
        #define CIRQUE_PINNACLE_DIAMETER_MM 40
        #define CIRQUE_PINNACLE_SPI_CS_PIN GP14
        #define POINTING_DEVICE_ROTATION_270
        #define CIRQUE_PINNACLE_TAP_ENABLE
        // #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
        // #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
    #endif //POINTING_DEVICE_DRIVER_CIRQUE_PINNACLE_SPI
#endif //POINTING_DEVICE_ENABLE


/* Trackpoint configuration. */
#define PS2_PIO_USE_PIO1
#define PS2_MOUSE_X_MULTIPLIER 1
#define PS2_MOUSE_Y_MULTIPLIER 1
// #define PS2_MOUSE_ENABLE_SCROLLING
#define PS2_MOUSE_INIT_DELAY 1000

/* Combo configuration. */
#define COMBO_TERM 30

/* QP and LVGL */
#ifdef QUANTUM_PAINTER_ENABLE
    /* right */
    #define DISPLAY_CS_PIN_RIGHT GP22
    #define DISPLAY_RST_PIN_RIGHT GP16
    #define DISPLAY_DC_PIN_RIGHT GP17

    /*  left */
    #define DISPLAY_CS_PIN GP22
    #define DISPLAY_RST_PIN GP16
    #define DISPLAY_DC_PIN GP17

    #define QUANTUM_PAINTER_CONCURRENT_ANIMATIONS 8
    #define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
    #define QUANTUM_PAINTER_NUM_IMAGES 14
    #define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
    #define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE (96U * 1024U) //1024
    #define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
    #define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF
    #define GC9A01_NUM_DEVICES 2
#endif //POINTING_DEVICE_ENABLE

#ifndef LCD_ACTIVITY_TIMEOUT
#    define LCD_ACTIVITY_TIMEOUT 30000
#endif // LCD_ACTIVITY_TIMEOUT

#define DYNAMIC_KEYMAP_LAYER_COUNT  11
#define LAYER_STATE_16BIT

#define MIDI_ADVANCED

#define TRI_LAYER_LOWER_LAYER 5
#define TRI_LAYER_UPPER_LAYER  6
#define TRI_LAYER_ADJUST_LAYER 7



// #define ENCODER_DIRECTION_FLIP
