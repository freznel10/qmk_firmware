/* Copyright 2021 Freznel B. Sta. Ana (freznel@gmail.com) (@freznel10)
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

#include "config_common.h"

/* USB Device descriptor parameter */
// #define VENDOR_ID 0x9678
// #define PRODUCT_ID 0x0998
// #define DEVICE_VER 0x0001
// #define MANUFACTURER Freznel10
// #define PRODUCT Zerf9
/* key matrix size */
#define MATRIX_ROWS  10
#define MATRIX_COLS  8


// #define MATRIX_COL_PINS   { B12, B13, B14, B15, A8, A10, C13, B9 }
// #define MATRIX_ROW_PINS   { A15, B3, B4, B5, B8 }

// Space command version
// #define MATRIX_COL_PINS  { B13, B14, B15, A8, A10, A13, C13, C14 }
// #define MATRIX_ROW_PINS  { A14, A15, B3, B4, B9 }


// #define DIODE_DIRECTION     COL2ROW
// #define USB_VBUS_PIN        A9

#define SPLIT_HAND_PIN        C15    // high = left, low = right
//WS2812 RGB LED strip input and number of LEDs
#define RGB_DI_PIN          A1
#define WS2812_PWM_DRIVER   PWMD2  // default: PWMD2
#define WS2812_PWM_CHANNEL  2      // default: 2
#define WS2812_PWM_PAL_MODE 1      // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 2
#define WS2812_EXTERNAL_PULLUP
//#define WS2812_PWM_COMPLEMENTARY_OUTPUT // Define for a complementary timer output (TIMx_CHyN); omit for a normal timer output (TIMx_CHy).
#define WS2812_DMA_STREAM   STM32_DMA1_STREAM7  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMA_CHANNEL  3
#define WS2812_PWM_TARGET_PERIOD 800000


#ifdef RGBLIGHT_ENABLE
#define RGBLED_NUM          96
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT \
    { 48, 48 }
#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_DEFAULT_MODE         RGBLIGHT_MODE_STATIC_GRADIENT + 9
#define RGBLIGHT_DEFAULT_HUE          222
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_LAYERS
#endif


#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL 96
#define RGB_MATRIX_SPLIT { 48, 48 }
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#endif


/* Audio config */
#define AUDIO_PIN          B1
#define AUDIO_PWM_DRIVER   PWMD3
#define AUDIO_PWM_CHANNEL  4
#define AUDIO_PWM_PAL_MODE 2
#define AUDIO_STATE_TIMER  GPTD4


/* serial.c configuration for split keyboard */
#define SERIAL_USART_FULL_DUPLEX  // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN      A2
#define SERIAL_USART_RX_PIN      A3
#define SERIAL_USART_DRIVER      SD2
#define SERIAL_USART_TX_PAL_MODE 7    // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_RX_PAL_MODE 7    // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED


/* i2c config for oleds */
#define I2C_DRIVER        I2CD1
#define I2C1_SCL_PIN      B6
#define I2C1_SDA_PIN      B7
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4
#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A {B9, B10}
#define ENCODERS_PAD_B {C13, C13}
#define ENCODERS_PAD_A_RIGHT {B9, B10}
#define ENCODERS_PAD_B_RIGHT {C13, C13}
#define ENCODER_DEFAULT_POS 0x3
#endif

/* spi config for eeprom and  pmw3360 sensor */
#define SPI_DRIVER                           SPID1
#define SPI_SCK_PIN                          A5
#define SPI_SCK_PAL_MODE                     5
#define SPI_MOSI_PIN                         A7
#define SPI_MOSI_PAL_MODE                    5
#define SPI_MISO_PIN                         A6
#define SPI_MISO_PAL_MODE                    5

/* eeprom config */
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A4
// #define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR    64
// #define EXTERNAL_EEPROM_BYTE_COUNT           32768
// #define EXTERNAL_EEPROM_PAGE_SIZE            64
// #define EXTERNAL_EEPROM_ADDRESS_SIZE         2
// #define DEBUG_EEPROM_OUTPUT
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR    64


/* Bootmagic*/
#define BOOTMAGIC_LITE_ROW          0
#define BOOTMAGIC_LITE_COLUMN       0
#define BOOTMAGIC_LITE_ROW_RIGHT    5
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0

#define DYNAMIC_KEYMAP_LAYER_COUNT  7
#define LAYER_STATE_16BIT

// #define OLED_DISPLAY_128X64
// #define DEBUG_EEPROM_OUTPUT

/*Enable when trackball is attached */
#ifdef POINTING_DEVICE_DRIVER_PMW3360
#define PMW3360_CS_PIN                       B0
#define PMW3360_SPI_MODE                     3
#define PMW3360_SPI_DIVISOR                  64
#define ROTATIONAL_TRANSFORM_ANGLE  -25
#define POINTING_DEVICE_INVERT_X
#endif

/*Enable when trackpoint is attached */
// #define PS2_CLOCK_PIN B0
// #define PS2_DATA_PIN B1

#ifdef HAPTIC_ENABLE
	#define FB_ERM_LRA 1
	#define FB_BRAKEFACTOR 2	// For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7
	#define FB_LOOPGAIN 3 		// For  Low:0, Medium:1, High:2, Very High:3

	// Refer to datasheet for the optimal setting for specific motors.
	#define RATED_VOLTAGE 2 //2Vrms per ELV1411A datasheet, which is the LRA used for the Pimoroni Haptic Bzzz driver DRV2605.
	#define V_PEAK 2.0		//Per QMK docs.
	#define V_RMS 2.0 		//Per ELV1411A datasheet.
	#define F_LRA 150 		//Resonant frequency per ELV1411A datasheet.

	//#define HAPTIC_OFF_IN_LOW_POWER 1 //Turn off haptic feedback while sleeping (+54).
	#define NO_HAPTIC_PUNCTUATION
	#define NO_HAPTIC_ALPHA
	#define NO_HAPTIC_MOD
    #define NO_HAPTIC_FN
    #define DRV_GREETING       alert_750ms
    #define DRV_MODE_DEFAULT   sharp_tick1
	#define NO_HAPTIC_NUMERIC
	//#define NO_HAPTIC_NAV
#endif


#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_TASK_THROTTLE_MS 10

#define CIRQUE_PINNACLE_ADDR 0x2A
#define POINTING_DEVICE_ROTATION_180

#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC, RPC_ID_SYNC_STATE_KB


#define ENABLE_COMPILE_KEYCODE

// #undef STM32_HSECLK
// #define STM32_HSECLK 8000000U

#ifdef PS2_MOUSE_ENABLE
#define PS2_CLOCK_PIN B9
#define PS2_DATA_PIN A10
#endif
