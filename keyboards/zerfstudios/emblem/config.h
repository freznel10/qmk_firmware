// Copyright 2022 freznel10 (@freznel10)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define MATRIX_SHIFT_REGISTER_COUNT 10
#define SPI_MATRIX_CHIP_SELECT_PIN GP15
#define SPI_MATRIX_DIVISOR 16

#define RGB_DI_PIN GP25
#define WS2812_PIO_USE_PIO1

#ifdef RGBLIGHT_ENABLE
#define RGBLED_NUM          70
#define RGBLIGHT_LIMIT_VAL 100
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_DEFAULT_MODE         RGBLIGHT_MODE_STATIC_GRADIENT + 9
#define RGBLIGHT_DEFAULT_HUE          222
#define RGBLIGHT_LAYERS
#endif

// #define LCD_POWER_ENABLE_PIN GP4
// #define LCD_POWER_ENABLE_PIN GP26

#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

// #define ENCODERS_PAD_A {GP12, GP8, GP10}
// #define ENCODERS_PAD_B {GP14, GP7, GP9}
// #define ENCODER_RESOLUTIONS { 1, 2, 2 }

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_LED_COUNT 70
#define DRIVER_LED_TOTAL 70
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 220 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
// #define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#endif

#ifdef AUDIO_ENABLE
#define AUDIO_PIN GP0
#define AUDIO_PWM_DRIVER PWMD0
#define AUDIO_PWM_CHANNEL 1
#endif //AUDIO_ENABLE

#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PWM_DRIVER PWMD4
#define BACKLIGHT_PWM_CHANNEL 1
#define BACKLIGHT_PIN GP24
#define BACKLIGHT_LEVELS 4
#endif //BACKLIGHT_ENABLE


/* eeprom config */

// #define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN GP21
// #define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
// // // #define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR    64
// // // #define EXTERNAL_EEPROM_BYTE_COUNT           32768
// // // #define EXTERNAL_EEPROM_PAGE_SIZE            64
// // // #define EXTERNAL_EEPROM_ADDRESS_SIZE         2
// // // #define DEBUG_EEPROM_OUTPUT
// #define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR    8
// #define EXTERNAL_EEPROM_BYTE_COUNT 8192
// #define EXTERNAL_EEPROM_PAGE_SIZE 64
// #define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 8
// #define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN GP17

//#define EEPROM_I2C_CAT24C512

//Pointing device config
#ifdef POINTING_DEVICE_DRIVER_CIRQUE_PINNACLE_SPI
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_SPI_CS_PIN GP11
#define POINTING_DEVICE_ROTATION_270
#define CIRQUE_PINNACLE_TAP_ENABLE
#endif //POINTING_DEVICE_DRIVER_CIRQUE_PINNACLE_SPI

#ifdef POINTING_DEVICE_DRIVER_PMW3360
#define PMW33XX_CS_PIN GP11
#define PMW33XX_LIFTOFF_DISTANCE 0x03
#define POINTING_DEVICE_INVERT_X
#endif //POINTING_DEVICE_DRIVER_PMW3360


// #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
// #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
// #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE




#define POINTING_DEVICE_TASK_THROTTLE_MS 10

// #define OLED_DISPLAY_128X64
// #define DEBUG_EEPROM_OUTPUT

/*Enable when trackpoint is attached */
// #define PS2_CLOCK_PIN B0
// #define PS2_DATA_PIN B1

#ifdef HAPTIC_ENABLE
	#define FB_ERM_LRA 1
	#define FB_BRAKEFACTOR 2	// For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7
	#define FB_LOOPGAIN 3 		// For  Low:0, Medium:1, High:2, Very High:3

	// Refer to datasheet for the optimal setting for specific motors.
	#define RATED_VOLTAGE 2
	#define V_PEAK 2.0
	#define V_RMS 2.0
	#define F_LRA 200

	//#define HAPTIC_OFF_IN_LOW_POWER 1 //Turn off haptic feedback while sleeping (+54).
	#define NO_HAPTIC_PUNCTUATION
	#define NO_HAPTIC_ALPHA
	#define NO_HAPTIC_MOD
    //#define NO_HAPTIC_FN
    #define DRV_GREETING       alert_750ms
    #define DRV_MODE_DEFAULT   sharp_tick1
	//#define NO_HAPTIC_NUMERIC
	//#define NO_HAPTIC_NAV
#endif


//SPI Config
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP16


//Bootmagic (could not get this)
#define BOOTMAGIC_LITE_ROW          0
#define BOOTMAGIC_LITE_COLUMN       2


// Display common config
#define DISPLAY_DC_PIN GP20
#define DISPLAY_CS_PIN GP21
#define DISPLAY_RST_PIN GP22

// #define QUANTUM_PAINTER_CONCURRENT_ANIMATIONS 8
// #define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
// #define QUANTUM_PAINTER_NUM_IMAGES 20
// #define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 1024
// #define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE (48U * 1024U)  //4096


#ifndef LCD_ACTIVITY_TIMEOUT
#    define LCD_ACTIVITY_TIMEOUT 30000
#endif // LCD_ACTIVITY_TIMEOUT
#define GC9A01_NUM_DEVICES 1
// #define RGB565_SURFACE_NUM_DEVICES 1

// #define BUSY_WAIT// #define BUSY_WAIT_INSTRUCTIONS 40 // Increase if two rows are pressed at the same time.

#define COMBO_TERM 30

// #define LAYER_STATE_16BIT

//#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 9

#define WEAR_LEVELING_RP2040_FLASH_SIZE 1048576

#define POINTING_DEVICE_MODES_ENABLE
#define POINTING_MODE_MAP_COUNT 10
#define POINTING_DEFAULT_DIVISOR 64
#define POINTING_HISTORY_DIVISOR 64
#define POINTING_VOLUME_DIVISOR 64
#define POINTING_CARET_DIVISOR 32
#define POINTING_CARET_DIVISOR_V 32
#define POINTING_CARET_DIVISOR_H 32
#define POINTING_PRECISION_DIVISOR 32
#define POINTING_DRAG_DIVISOR 4
#define POINTING_MODE_DEFAULT PM_NONE

#define MOUSE_SCROLL_HIRES_ENABLE
#define MOUSE_SCROLL_EXTENDED_REPORT
#define MOUSE_EXTENDED_REFORT




