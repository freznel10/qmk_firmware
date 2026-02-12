/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#pragma once

/* Key matrix configuration. */
#define MATRIX_ROWS 12 // Rows are doubled-up.
#define MATRIX_COLS 6

#define SPLIT_HAND_PIN  GP4
// #define USB_VBUS_PIN   GP13

#define WS2812_DI_PIN      GP25
#define WS2812_PIO_USE_PIO0

#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL 84
#define RGB_MATRIX_LED_COUNT 84
#define RGB_MATRIX_SPLIT { 42, 42 }
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255 //
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#endif

#ifdef AUDIO_ENABLE
#define AUDIO_PIN GP24
#define AUDIO_PWM_DRIVER PWMD4
#define AUDIO_PWM_CHANNEL 1
#endif //AUDIO_ENABLE

#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PWM_DRIVER PWMD6
#define BACKLIGHT_PWM_CHANNEL 2
#define BACKLIGHT_PIN GP29
#define BACKLIGHT_LEVELS 4
#endif //BACKLIGHT_ENABLE

/* serial.c configuration for split keyboard */
#define SERIAL_USART_FULL_DUPLEX  // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN      GP0
#define SERIAL_USART_RX_PIN      GP1
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600
#define SERIAL_USART_PIN_SWAP
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

#define SPLIT_ACTIVITY_ENABLE

#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC
#define SPLIT_MAX_CONNECTION_ERRORS 10

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN      GP2
#define I2C1_SDA_PIN      GP3
#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

#define EEPROM_I2C_MB85RC256V


#ifdef HAPTIC_ENABLE
#define SPLIT_HAPTIC_ENABLE
#if defined(USE_VL91022_LRA)
	#define FB_ERM_LRA 1
	#define FB_BRAKEFACTOR 2	// For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7
	#define FB_LOOPGAIN 3 		// For  Low:0, Medium:1, High:2, Very High:3

	// Refer to datasheet for the optimal setting for specific motors.
	#define RATED_VOLTAGE 3
	#define V_PEAK 3.3
	#define V_RMS 1.65
	#define F_LRA 160
#else
	#define FB_ERM_LRA 1
	#define FB_BRAKEFACTOR 2	// For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7
	#define FB_LOOPGAIN 3 		// For  Low:0, Medium:1, High:2, Very High:3

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
#define SPLIT_HAPTIC_ENABLE
#endif

/* Pointing device configuration. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP20

#define POINTING_MODES_NUM_DEVICES 2

#ifdef POINTING_DEVICE_ENABLE
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED
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
// #define POINTING_DEVICE_DEBUG
// #define POINTING_MODES_SINGLE_CONTROL

// #define MOUSE_SCROLL_HIRES_ENABLE
// #define MOUSE_SCROLL_EXTENDED_REPORT
#define MOUSE_EXTENDED_REFORT

#define AUTO_MOUSE_DEFAULT_LAYER 4
#define AUTO_MOUSE_TIME 650
#define AUTO_MOUSE_DEBOUNCE 25

// #ifdef POINTING_DEVICE_DRIVER_PMW3360
#define PMW33XX_LIFTOFF_DISTANCE 0x03
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_X_RIGHT
#define PMW33XX_CS_PIN_RIGHT GP21
#define PMW33XX_CS_PIN GP14
// #define PMW33XX_CS_PIN GP21
#define PMW33XX_SPI_DIVISOR 64
#endif //POINTING_DEVICE_DRIVER_PMW3360

// #endif // POINTING_DEVICE_ENABLE

#ifdef QUANTUM_PAINTER_ENABLE
/* right */
#define DISPLAY_CS_PIN_RIGHT GP11
#define DISPLAY_RST_PIN_RIGHT GP15
#define DISPLAY_DC_PIN_RIGHT GP10

/*  left */
#define DISPLAY_CS_PIN GP17
#define DISPLAY_RST_PIN GP15
#define DISPLAY_DC_PIN GP16

#define QUANTUM_PAINTER_CONCURRENT_ANIMATIONS 8
#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
#define QUANTUM_PAINTER_NUM_IMAGES 14
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE (96U * 1024U) //1024
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
#define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 30000

#endif // QUANTUM_PAINTER_ENABLE

#ifndef LCD_ACTIVITY_TIMEOUT
#    define LCD_ACTIVITY_TIMEOUT 30000
#endif // LCD_ACTIVITY_TIMEOUTk

#define DYNAMIC_KEYMAP_LAYER_COUNT 11
#ifndef IMAGE_LAYER_ZOOM
#define IMAGE_LAYER_ZOOM 256
#endif

// Not yet available in `info.json`
#ifdef BOOTMAGIC_ENABLE
     // Top left key on left half
#    define BOOTMAGIC_LITE_ROW 0
#    define BOOTMAGIC_LITE_COLUMN 0
     // Top right key on right half
#    define BOOTMAGIC_LITE_ROW_RIGHT    6
#    define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#endif

#define MIDI_ADVANCED

#define TRI_LAYER_LOWER_LAYER 5
#define TRI_LAYER_UPPER_LAYER  6
#define TRI_LAYER_ADJUST_LAYER 7
