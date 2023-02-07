/* Copyright 2022 Alabastard
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

#include <string.h>
#include "quantum.h"
#include "pointing_device.h"

/* sanity check */
#if !defined(POINTING_DEVICE_MODES_ENABLE) || !defined(POINTING_DEVICE_ENABLE)
#    error "POINTING_DEVICE_MODES_ENABLE or POINTING_DEVICE_ENABLE not defined! check settings!"
#endif

/* default settings */
#ifndef POINTING_TAP_DELAY
#    define POINTING_TAP_DELAY 0
#endif
#ifndef POINTING_MODE_DEFAULT
#    define POINTING_MODE_DEFAULT PM_NONE
#endif
#if defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
#    if defined(POINTING_MODES_LEFT)
#        define POINTING_MODES_LEFT_DEFAULT true
#    else
#        define POINTING_MODES_LEFT_DEFAULT false
#    endif
#endif

/* default divisors */
#ifndef POINTING_DEFAULT_DIVISOR
#    define POINTING_DEFAULT_DIVISOR 64
#endif
#ifndef POINTING_HISTORY_DIVISOR
#    define POINTING_HISTORY_DIVISOR 64
#endif
#ifndef POINTING_VOLUME_DIVISOR
#    define POINTING_VOLUME_DIVISOR 64
#endif
#ifndef POINTING_CARET_DIVISOR
#    define POINTING_CARET_DIVISOR 32
#endif
#ifndef POINTING_CARET_DIVISOR_H
#    define POINTING_CARET_DIVISOR_H POINTING_CARET_DIVISOR
#endif
#ifndef POINTING_CARET_DIVISOR_V
#    define POINTING_CARET_DIVISOR_V POINTING_CARET_DIVISOR
#endif
#ifndef POINTING_PRECISION_DIVISOR
#    define POINTING_PRECISION_DIVISOR 2
#endif
#ifndef POINTING_DRAG_DIVISOR
#    define POINTING_DRAG_DIVISOR 16
#endif
#ifndef POINTING_DRAG_DIVISOR_H
#    define POINTING_DRAG_DIVISOR_H POINTING_DRAG_DIVISOR
#endif
#ifndef POINTING_DRAG_DIVISOR_V
#    define POINTING_DRAG_DIVISOR_V POINTING_DRAG_DIVISOR
#endif

/* error checking */
#if (POINTING_DEFAULT_DIVISOR == 0)
#    pragma message "DEFAULT_DIVISOR must be non zero value"
#    error DEFAULT_DIVISOR set to zero
#endif
/* check valid keycode range */
#if (!((POINTING_MODE_COUNT - 1) & (~POINTING_MODE_COUNT)))
#    pragma message "Total number of keycodes in QK_POINTING_MODE range must be a power of 2"
#    error QK_POINTING_MODE keycode range is not a power of two
#endif

/* keycode setup */
#define POINTING_MODE_MO QK_POINTING_MODE
#define POINTING_MODE_MO_MAX (POINTING_MODE_MO + POINTING_MODE_COUNT - 1)
#define POINTING_MODE_TG (POINTING_MODE_MO_MAX + 1)
#define POINTING_MODE_TG_MAX QK_POINTING_MODE_MAX

/* enum typedefs */
enum pointing_device_directions { PD_DOWN = 0, PD_UP, PD_LEFT, PD_RIGHT };

/* local data structures */
/* pointing mode structure for tracking mode data */
typedef struct {
    uint8_t id;
    uint8_t divisor;
    uint8_t direction;
    int16_t x;
    int16_t y;
} pointing_mode_t;

/* context structure to track additional data */
typedef struct {
    struct {
#if defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
        bool is_left;
#endif
        uint8_t tg_mode_id;
    } config;
    pointing_mode_t mode;
} context_pointing_mode_t;

/* ----------Controlling pointing device modes-------------------------------------------------------------------- */
void    set_pointing_mode_id(uint8_t mode_id);    // set current pointing_mode.id to mode_id
void    toggle_pointing_mode_id(uint8_t mode_id); // toggle pointing mode
uint8_t get_pointing_mode_id(void);               // returns current pointing_mode.id
uint8_t get_toggled_pointing_mode_id(void);       // return current tg_mode_id

/* ----------Controlling pointing device data conversion---------------------------------------------------------- */
report_mouse_t pointing_modes_axes_conv(pointing_mode_t pointing_mode, report_mouse_t mouse_report); // converts x & y axes to local h & v

/* ----------Setting up pointing mode custom keyrecords----------------------------------------------------------- */
void pointing_mode_key_momentary(uint8_t mode_id, bool pressed); // momentary change of pointing mode while button is held
void pointing_mode_key_toggle(uint8_t mode_id, bool pressed);    // toggle pointing mode on/off on keypress

/* ----------For custom pointing modes---------------------------------------------------------------------------- */
void              set_pointing_mode(pointing_mode_t pointing_mode);                                          // overwrite local pointing_mode status
void              pointing_mode_update(void);                                                                // update direction & divisor from current mode id, x, y
mouse_xy_report_t apply_divisor_xy(int16_t value);                                                           // divide value by current divisor and limit value to x/y range
int8_t            apply_divisor_hv(int16_t value);                                                           // divide value by current divisor and limit value to h/v range
int16_t           multiply_divisor_xy(mouse_xy_report_t value);                                              // multiply mouse x/y value by current divisor
int16_t           multiply_divisor_hv(int8_t value);                                                         // multiply mouse h/v value by current divisor
void              pointing_tap_codes(uint16_t kc_left, uint16_t kc_down, uint16_t kc_up, uint16_t kc_right); // turn pointing_mode x/y values into keycode taps

/* ----------For multiple pointing devices------------------------------------------------------------------------ */
#if defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
bool is_pointing_mode_on_left(void);   // check if left is current active pointing mode side
void pointing_mode_switch_hands(void); // change witch hand is active on pointing mode
#endif

/* ----------Callbacks for modifying and adding pointing modes---------------------------------------------------- */
bool process_pointing_mode_kb(pointing_mode_t pointing_mode, report_mouse_t* mouse_report);   // keyboard level
bool process_pointing_mode_user(pointing_mode_t pointing_mode, report_mouse_t* mouse_report); // user/keymap level

/* ----------Callbacks for adding/modifying pointing device mode divisors----------------------------------------- */
uint8_t get_pointing_mode_divisor_kb(uint8_t mode_id, uint8_t direction);   // adding divisors at keyboard level
uint8_t get_pointing_mode_divisor_user(uint8_t mode_id, uint8_t direction); // adding divisors at user/keymap level
bool    pointing_mode_divisor_postprocess_kb(uint8_t* divisor);             // modifying divisors at keyboard level
bool    pointing_mode_divisor_postprocess_user(uint8_t* divisor);           // modifying divisors at user/keymap level
void    pointing_mode_divisor_override(uint8_t divisor);                    // Override current divisor until next update

/* ----------Core functions (only used in custom pointing devices or key processing)------------------------------ */
report_mouse_t pointing_device_modes_task(report_mouse_t mouse_report);                // intercepts mouse_report (in pointing_device_task_* stack)
bool           process_pointing_mode_records(uint16_t keyrecord, keyrecord_t* record); // handle processing of built in keyrecords (in process_record stack)

/* ----------Pointing Device mode Mapping------------------------------------------------------------------------- */
#if (!defined(POINTING_MODE_MAP_COUNT) || POINTING_MODE_MAP_COUNT <= 0)
#    define POINTING_MODE_MAP_COUNT 0
#else
#    define POINTING_MODE_LAYOUT(Y_POS, X_NEG, X_POS, Y_NEG) \
        { X_NEG, Y_NEG, Y_POS, X_POS }
#    define POINTING_MODE_MAP_START PM_SAFE_RANGE

extern const uint16_t PROGMEM pointing_device_mode_maps[][4];

#    define POINTING_MODE_MAP(pm) pointing_device_mode_maps[pm][0], pointing_device_mode_maps[pm][1], pointing_device_mode_maps[pm][2], pointing_device_mode_maps[pm][3]
#endif // POINTING_MODE_MAP_COUNT > 0
