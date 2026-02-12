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

/* key matrix size */
#define MATRIX_ROWS  10
#define MATRIX_COLS  8


// #define MATRIX_COL_PINS { GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP24 }
// #define MATRIX_ROW_PINS  { GP11, GP12, GP14, GP15, GP23}
// #define MATRIX_COL_PINS_RIGHT { GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP24 }
// #define MATRIX_ROW_PINS_RIGHT  { GP11, GP12, GP14, GP15, GP23}

//#define USB_VBUS_PIN  P13
#define SPLIT_HAND_PIN  GP26  // high = left, low = right

//SK6803 input and number of LEDs
#define WS2812_DI_PIN      GP25
#define WS2812_PIO_USE_PIO1

#define AUDIO_PIN GP29
#define AUDIO_PWM_DRIVER PWMD6
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B

#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL 104
#define RGB_MATRIX_LED_COUNT 104
#define RGB_MATRIX_SPLIT { 52, 52 }
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#endif


/* Audio config - not yet functional*/
// #define AUDIO_PIN          GP29
// #define AUDIO_PWM_DRIVER   PWMD3
// #define AUDIO_PWM_CHANNEL  4
// #define AUDIO_PWM_PAL_MODE 2
// #define AUDIO_STATE_TIMER  GPTD4




/* serial.c configuration for split keyboard */
#define SERIAL_USART_FULL_DUPLEX  // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN      GP0
#define SERIAL_USART_RX_PIN      GP1
//#define SERIAL_USART_DRIVER SIOD0
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600
#define SERIAL_USART_PIN_SWAP
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC, RPC_ID_SYNC_STATE_KB
#define SPLIT_MAX_CONNECTION_ERRORS 10



/* i2c config for oleds */
#define I2C1_SCL_PIN      GP2
#define I2C1_SDA_PIN      GP3
#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { GP27 }
#define ENCODERS_PAD_B { GP28 }
#define ENCODERS_PAD_A_RIGHT { GP27 }
#define ENCODERS_PAD_B_RIGHT { GP28 }
#endif

/* eeprom config */

#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN GP21
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
// #define DEBUG_EEPROM_OUTPUT
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR    8
#define EXTERNAL_EEPROM_BYTE_COUNT 8192
#define EXTERNAL_EEPROM_PAGE_SIZE 64


#define BOOTMAGIC_LITE_ROW          0
#define BOOTMAGIC_LITE_COLUMN       0
#define BOOTMAGIC_LITE_ROW_RIGHT    5
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0

#define DYNAMIC_KEYMAP_LAYER_COUNT  7
#define LAYER_STATE_16BIT

/*Enable when trackball is attached */
// #define PMW3360_CS_PIN                       B0
// #define PMW3360_SPI_MODE                     3
// #define PMW3360_SPI_DIVISOR                  64
// #define ROTATIONAL_TRANSFORM_ANGLE  -25
// #define POINTING_DEVICE_INVERT_X

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
	// #define NO_HAPTIC_PUNCTUATION
	#define NO_HAPTIC_ALPHA
	// #define NO_HAPTIC_MOD
    // #define NO_HAPTIC_FN
    #define DRV_GREETING       alert_750ms
    #define DRV_MODE_DEFAULT   sharp_tick1
	// #define NO_HAPTIC_NUMERIC
	// #define NO_HAPTIC_NAV
#endif

// Display common config
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_TASK_THROTTLE_MS 10

#define CIRQUE_PINNACLE_ADDR 0x2A
#define POINTING_DEVICE_ROTATION_180
#define CIRQUE_PINNACLE_TIMEOUT 2000

#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define CIRQUE_PINNACLE_DIAMETER_MM 35


/* Enable use of pointing device on slave split. */
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





#define ENABLE_COMPILE_KEYCODE

#ifdef QUANTUM_PAINTER_ENABLE
// Display common config
#define DISPLAY_DC_PIN GP22

// 240x240 ST7789
// #define DISPLAY_CS_PIN_1_44_INCH_LCD_ILI9341 A3
// #define DISPLAY_RST_PIN_1_44_INCH_LCD_ILI9341 B1

// 128x128 SSD1351 OLED
#define DISPLAY_CS_PIN_1_5_INCH_OLED_SSD1351 GP17
#define DISPLAY_RST_PIN_1_5_INCH_OLED_SSD1351 GP20

#define QUANTUM_PAINTER_CONCURRENT_ANIMATIONS 8
#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
#define QUANTUM_PAINTER_NUM_IMAGES 14
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#endif

#ifndef LCD_ACTIVITY_TIMEOUT
#    define LCD_ACTIVITY_TIMEOUT 30000
#endif // LCD_ACTIVITY_TIMEOUT
#ifdef QUANTUM_PAINTER_ENABLE
#ifndef SSD1351_NUM_DEVICES
#define SSD1351_NUM_DEVICES 2
#endif
#endif

// #define BUSY_WAIT
// #define BUSY_WAIT_INSTRUCTIONS 40 // Increase if two rows are pressed at the same time.

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP16
//# define REALTIME_COUNTER_CLOCK 1000000


#define MOUSE_SCROLL_HIRES_ENABLE
#define MOUSE_SCROLL_EXTENDED_REPORT
#define MOUSE_EXTENDED_REFORT

#define SPLIT_HAPTIC_ENABLE
