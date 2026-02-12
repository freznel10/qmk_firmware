/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
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

#include "freznel.h"
#include "bindings.h"
#include "../../douballz.h"
#include "users/freznel/split/transport_sync.h"

extern user_runtime_config_t user_state;

uint8_t qmk_lv_get_bpm(void) {
#ifdef WPM_ENABLE
    return get_current_wpm();
#else
    return 0;
#endif
}

lv_color_hsv_t qmk_lv_rgb_matrix_get_hsv(void) {
    lv_color_hsv_t col_hsv = {0, 0, 0};
    col_hsv.h = rgb_matrix_get_hue();
    col_hsv.s = rgb_matrix_get_sat();
    col_hsv.v = (uint8_t)(((float)(rgb_matrix_get_val() / 150.0)) * 255.0); // Scale up brightness
    return col_hsv;
}

void qmk_lv_rgb_matrix_sethsv(uint16_t hue, uint8_t sat, uint8_t val, bool eeprom) {
    val = (uint8_t)(((float)(val / 255.0)) * 150.0); // Scale down brightness
    if (eeprom)
        rgb_matrix_sethsv(hue, sat, val);
    else
        rgb_matrix_sethsv_noeeprom(hue, sat, val);
}

uint8_t qmk_lv_rgb_matrix_get_speed(void) {
    uint8_t speed = 0;
    speed = rgb_matrix_get_speed();
    return speed;
}

void qmk_lv_rgb_matrix_set_speed(uint8_t speed, bool eeprom) {
    if (eeprom)
        rgb_matrix_set_speed(speed);
    else
        rgb_matrix_set_speed_noeeprom(speed);
}

uint8_t qmk_lv_rgb_matrix_get_mode(void) {
    uint8_t mode = 0;
    mode = rgb_matrix_get_mode();
    return mode;
}

void qmk_lv_rgb_matrix_mode(uint8_t mode, bool eeprom) {
    if (eeprom)
        rgb_matrix_mode(mode);
    else
        rgb_matrix_mode_noeeprom(mode);
}

void qmk_lv_tap_keycode(int keycode) {
    switch(keycode){
        case QK_BOOT:
            reset_keyboard();
            break;
        case DB_TOGG:
            debug_enable ^= 1;
            break;
        case EE_CLR:
            eeconfig_disable();
            soft_reset_keyboard();
            break;
    }
}

void qmk_lv_set_layer(uint8_t layer) {
    layer_move(layer);
}

uint8_t qmk_lv_geT_layer() {
    uint8_t layer = 0;
    layer = get_highest_layer(default_layer_state);
    return layer;
}

uint8_t qmk_lv_active_layer(void) {
    uint8_t active_layer = 0;
    active_layer = get_highest_layer(layer_state);
    return active_layer;
}

uint16_t qmk_lv_get_cpi(void) {
    uint16_t cpi = 0;
    cpi = user_state.split_pointing_mode == PM_PRECISION ? charybdis_get_pointer_sniping_dpi() : charybdis_get_pointer_default_dpi();
    return cpi;
}
