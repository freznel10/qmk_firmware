﻿/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
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

#include "rgb_mode.h"
// #include "rgb_modes.h"

#include "../../../dial_menu/dial_menu.h"
#include "../../../styles/styles.h"
#include "../../../bindings/bindings.h"

extern rgb_config_t rgb_matrix_config;

// const char* rgb_modes[] = { "Solid", "Solid", VALID_RGB_MODES };
char buf[40] = {0};

//----------------------------------------------------------
// RGB Matrix naming
#include <rgb_matrix.h>
#include <ctype.h>

#if defined(RGB_MATRIX_EFFECT)
#    undef RGB_MATRIX_EFFECT
#endif  // defined(RGB_MATRIX_EFFECT)

#define RGB_MATRIX_EFFECT(x) RGB_MATRIX_EFFECT_##x,
enum {
    RGB_MATRIX_EFFECT_NONE,
#include "rgb_matrix_effects.inc"
#undef RGB_MATRIX_EFFECT
#ifdef RGB_MATRIX_CUSTOM_KB
#    include "rgb_matrix_kb.inc"
#endif
#ifdef RGB_MATRIX_CUSTOM_USER
#    include "rgb_matrix_user.inc"
#endif
};

#define RGB_MATRIX_EFFECT(x)    \
    case RGB_MATRIX_EFFECT_##x: \
        return #x;
const char *rgb_matrix_name(uint8_t effect) {
    switch (effect) {
        case RGB_MATRIX_EFFECT_NONE:
            return "NONE";
#include "rgb_matrix_effects.inc"
#undef RGB_MATRIX_EFFECT
#ifdef RGB_MATRIX_CUSTOM_KB
#    include "rgb_matrix_kb.inc"
#endif
#ifdef RGB_MATRIX_CUSTOM_USER
#    include "rgb_matrix_user.inc"
#endif
        default:
            return "UNKNOWN";
    }
}
//-------------------------------------------------


lv_obj_t* arc;
lv_obj_t* previous_focus_item;

static void close_rgb_speed_pane(lv_event_t* event) {
    lv_group_focus_obj(previous_focus_item);

    uint16_t mode = lv_arc_get_value(arc);
    ui_lv_rgb_matrix_mode(mode, true);

    if (lv_obj_is_valid(arc)) {
        lv_obj_del(arc);
    }
}

static void arc_value_changed(lv_event_t* event) {

// static uint16_t last_effect       = 0xFFFF;
// bool rgb_effect_redraw           = false;
uint8_t curr_effect = rgb_matrix_config.mode;
//     if (last_effect != curr_effect) {
//         last_effect     = curr_effect;
//         rgb_effect_redraw = true;
//     }
//     if (rgb_effect_redraw) {
        snprintf(buf, sizeof(buf), "%s", rgb_matrix_name(curr_effect));
//             // for (int i = 5; i < sizeof(buf); ++i) {
//             //     if (buf[i] == 0)
//             //         break;
//             //     else if (buf[i] == '_')
//             //         buf[i] = ' ';
//             //     else if (buf[i - 1] == ' ')
//             //         buf[i] = toupper(buf[i]);
//             //     else if (buf[i - 1] != ' ')
//             //         buf[i] = tolower(buf[i]);
//             // }
//      }


    uint16_t mode = lv_arc_get_value(arc);

    // dial_menu_set_label_text(rgb_modes[mode]);
    dial_menu_set_label_text(rgb_matrix_name(curr_effect));
    ui_lv_rgb_matrix_mode(mode, false);
}

void init_rgb_mode_pane() {
    previous_focus_item = *(lv_group_get_default()->obj_focus);

    arc = lv_arc_create(lv_scr_act());

    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);  /*To not allow adjusting by click*/

    lv_obj_add_style(arc, &style_dial_menu_arc, LV_STATE_DEFAULT);
    lv_obj_add_style(arc, &style_dial_menu_arc_indicator, LV_PART_INDICATOR);

    lv_arc_set_rotation(arc, 135);
    lv_arc_set_bg_angles(arc, 30, 240);
    lv_arc_set_value(arc, ui_lv_rgb_matrix_get_mode());
    lv_arc_set_range(arc, 0, 44);

    lv_group_add_obj(lv_group_get_default(), arc);
    lv_group_focus_obj(arc);

    lv_obj_add_event_cb(arc, close_rgb_speed_pane, LV_EVENT_LONG_PRESSED_REPEAT, NULL);
    lv_obj_add_event_cb(arc, close_rgb_speed_pane, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(arc, arc_value_changed, LV_EVENT_VALUE_CHANGED, NULL);
}
