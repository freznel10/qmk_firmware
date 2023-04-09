<<<<<<<< HEAD:keyboards/emblem/ui/settings/dev/dev.c
﻿/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
========
/* Copyright 2022 Viktus Design LLC
>>>>>>>> upstream/develop:keyboards/viktus/osav2_numpad/keymaps/via/keymap.c
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

<<<<<<<< HEAD:keyboards/emblem/ui/settings/dev/dev.c
#include "dev.h"
#include "../../bindings/bindings.h"

void dev_qk_boot(void) {
    qmk_lv_tap_keycode(QK_BOOT);
}
void dev_dbg_toggle(void) {
    qmk_lv_tap_keycode(DB_TOGG);
}
void dev_clr_eeprom(void) {
    qmk_lv_tap_keycode(EE_CLR);
}
========
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all_split(
        KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,  KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,  KC_P5,   KC_P6,   KC_PEQL,
        KC_P1,  KC_P2,   KC_P3,   KC_DEL,
        KC_P0,  KC_P0,   KC_PDOT, KC_PENT
    )
};
>>>>>>>> upstream/develop:keyboards/viktus/osav2_numpad/keymaps/via/keymap.c
