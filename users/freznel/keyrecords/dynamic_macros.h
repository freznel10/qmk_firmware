/* Copyright 2016 Jack Humbert
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

/* Author: Wojciech Siewierski < wojciech dot siewierski at onet dot pl > */
#pragma once

#include "action.h"
#include "action_layer.h"

#ifndef DYNAMIC_MACRO_COUNT
#    define DYNAMIC_MACRO_COUNT 16
#endif

#ifndef DYNAMIC_MACRO_SIZE
#    define DYNAMIC_MACRO_SIZE 64
#endif

enum dynamic_macro_recording_state {
    STATE_NOT_RECORDING,
    STATE_RECORD_KEY_PRESSED,
    STATE_CURRENTLY_RECORDING,
};

typedef struct {
    keyrecord_t events[DYNAMIC_MACRO_SIZE];
    uint8_t     length;
    uint16_t    checksum;
} dynamic_macro_t;

void dynamic_macro_init(void);
void dynamic_macro_led_blink(void);
void dynamic_macro_record_start(uint8_t macro_id);
void dynamic_macro_play(uint8_t macro_id);
void dynamic_macro_record_key(uint8_t macro_id, keyrecord_t* record);
void dynamic_macro_record_end(uint8_t macro_id);
bool process_record_dynamic_macro(uint16_t keycode, keyrecord_t* record);

#define DYNAMIC_MACRO_CRC_LENGTH (sizeof(dynamic_macro_t) - sizeof(uint16_t))
#define IS_DYN_KEYCODE(keycode) (keycode >= DYN_MACRO_KEY00 && keycode <= DYN_MACRO_KEY15)

#define DYNAMIC_MACRO_EEPROM_MAGIC (uint16_t)0xDEAD

uint16_t dynamic_macro_calc_crc(dynamic_macro_t* macro);
void     dynamic_macro_load_eeprom_all(void);
void     dynamic_macro_load_eeprom(uint8_t macro_id);
void     dynamic_macro_save_eeprom(uint8_t macro_id);
bool     dynamic_macro_header_correct(void);
