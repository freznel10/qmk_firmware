/* Copyright 2023 Freznel B. Sta. Ana <freznel@gmail.com>
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

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

//Special symblols and icons
#include "fonts/eleganticons.h"
#include "fonts/extra_icons.h"
#include "fonts/extra_symbols.h"


extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Screen2;

// extern lv_obj_t * ui_Screen1_Image2;
extern lv_obj_t * ui_Screen1_Button1;
#ifdef WPM_ENABLE
extern lv_obj_t * ui_Label_WPM;
#endif
#ifdef OS_DETECTION_ENABLE
extern lv_obj_t * ui_Screen1_OS;
#endif
#ifdef CUSTOM_KEYLOGGER
extern lv_obj_t * ui_Label_Keylog;
#endif
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_Image2;

//Panel KB Status
extern lv_obj_t * ui_Panel_KB_Status;
extern lv_obj_t * ui_Label_CAPS;
extern lv_obj_t * ui_Label_SCLK;
extern lv_obj_t * ui_Label_NMLK;
extern lv_obj_t * ui_Label_AUDIO;
extern lv_obj_t * ui_Label_CLICKY;
extern lv_obj_t * ui_Label_ACRT;

//Panel Mods Status
extern lv_obj_t * ui_Panel_Mods;
extern lv_obj_t * ui_Label_CTRL;
extern lv_obj_t * ui_Label_ALT;
extern lv_obj_t * ui_Label_GUI;
extern lv_obj_t * ui_Label_SHIFT;

//Panel RGB and HSV
extern lv_obj_t * ui_Label_RGB;
extern lv_obj_t * ui_Panel_HSV;
extern lv_obj_t * ui_Label_H;
extern lv_obj_t * ui_Label_S;
extern lv_obj_t * ui_Label_V;

//Panel Layer and Unicode Mode
extern lv_obj_t * ui_Panel_Layer;
extern lv_obj_t * ui_Layer_Indicator;
extern lv_obj_t * ui_Label_Layer_Name;
extern lv_obj_t * ui_Label_Unicode_Mode;

//Panel Default Layer
extern lv_obj_t * ui_Dropdown_Deflayer;

//Panel Pointing
extern lv_obj_t * ui_Panel_Pointing_Mode;
extern lv_obj_t * ui_Label_Pointing_Mode;
extern lv_obj_t * ui_Label_CPI;
extern lv_obj_t * ui_PM_led1;
extern lv_obj_t * ui_PM_led2;
extern lv_obj_t * ui_PM_led3;
extern lv_obj_t * ui_Label_PM_mode;
extern lv_obj_t * ui_Label_PM_side;

extern lv_obj_t * mbox1;
extern lv_obj_t * mbox2;

//Label setting funcsions
void set_cpi_text_value(lv_obj_t* lbl);
void set_wpm_text_value(lv_obj_t* lbl);
void set_pm_text_value(lv_obj_t* lbl);
void set_unicode_mode_text_value(lv_obj_t* lbl);

//Event triggers
void ui_df_layer_change(lv_event_t * e);
void ui_event_dflayer_dropdown(lv_event_t * e);
void ui_active_layer_change(lv_event_t * e);
void ui_pm_state_change(lv_event_t * e);
void ui_am_state_change(lv_event_t * e);
void ui_unicode_mode_change(lv_event_t * e);
void ui_render_cpi(lv_event_t * e);
void ui_render_wpm(lv_event_t * e);
void ui_render_rgbmode(lv_event_t * e);
void ui_render_rgbhue_redraw(lv_event_t * e);
void ui_render_rgbval_redraw(lv_event_t * e);
void ui_render_rgbsat_redraw(lv_event_t * e);
void ui_render_caps_word(lv_event_t * e);
void lv_anim_2 (lv_obj_t * TargetObject);

//UI and event triggrs
void lvgl_event_triggers(void);
void ui_init(void);

//Fonts

LV_FONT_DECLARE(ui_font_Futura12);
LV_FONT_DECLARE(ui_font_Futura18);
LV_FONT_DECLARE(ui_font_Futura20);
LV_FONT_DECLARE(ui_font_Futura22);
LV_FONT_DECLARE(ui_font_Futura24);
LV_FONT_DECLARE(eleganticons);
LV_FONT_DECLARE(impact_45);
LV_FONT_DECLARE(impact_22);
LV_FONT_DECLARE(extra_icons);

//Images
LV_IMG_DECLARE(ui_img_2120736529);
LV_IMG_DECLARE(ui_img_bk80_png);
LV_IMG_DECLARE(ui_img_logo_test_png);
LV_IMG_DECLARE(ui_img_city_png);
LV_IMG_DECLARE(ui_img_emblem_80_png);
LV_IMG_DECLARE(ui_img_trackball_png);
LV_IMG_DECLARE(ui_img_toolbox_80_png);
LV_IMG_DECLARE(ui_img_lower_80_png);
LV_IMG_DECLARE(ui_img_raise_80_png);
LV_IMG_DECLARE(ui_img_numpad_80_png);
LV_IMG_DECLARE(monitormund);

// // User Defines
// #define ARC_SIZE 176
// #define ARC_WIDTH 34
// #define ARC_POS_X 0
// #define ARC_POS_Y 80
// #define ARC_Y ARC_POS_Y
// #define MENU_KNOB_SIZE 110
// #define LAYER_POS_Y -60
// #define LAYER_POS_X 0

#ifndef QP_DISPLAY_WIDTH
    #error "QP_DISPLAY_WIDTH must be defined in the keybord config."
#endif

#ifndef QP_DISPLAY_HEIGHT
    #error "QP_DISPLAY_HEIGHT must be defined in the keybord config."
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
