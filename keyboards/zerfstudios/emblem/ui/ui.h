// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

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

#include "fonts/extra_symbols.h"
#include "fonts/fonts.h"

extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Main1;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_Arc1;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_Layer1;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_Arc3;
extern lv_obj_t * ui_dflayer_dropdown;
extern lv_obj_t * ui_Settings1;
extern lv_obj_t * ui_SettingsMain;
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_SettingsAux;
extern lv_obj_t * ui_Settings2;
extern lv_obj_t * ui_StatusPanel;
extern lv_obj_t * ui_Status_Sniping;
extern lv_obj_t * ui_Status_Dragscroll;
extern lv_obj_t * ui_Status_Caret;
extern lv_obj_t * ui_Status_Volume;
extern lv_obj_t * ui_Status_Audio;
extern lv_obj_t * ui_Status_Clicky;
extern lv_obj_t * ui_Status_Autocorrect;
extern lv_obj_t * meter;
extern lv_obj_t * mbox1;
extern lv_meter_indicator_t * indic3;
void screen_loader(lv_event_t * e);
void ui_event_StatusPanel(lv_event_t * e);
void screen_loader_2(lv_event_t * e);
void ui_df_layer_change(lv_event_t * e);
void ui_event_dflayer_dropdown(lv_event_t * e);
void ui_active_layer_change(lv_event_t * e);
void ui_render_cpi(lv_event_t * e);
void ui_render_wpm(lv_event_t * e);
void pulse_Animation(lv_obj_t * TargetObject, int delay);
void lvgl_control_led_indicators(void);
void ui_event_Settings1(lv_event_t * e);
void ui_event_SettingsAux(lv_event_t * e);
void ui_dflayer_dropdown_create (void);

LV_IMG_DECLARE(ui_img_emblem_80_png);    // assets\emblem_80.png
LV_IMG_DECLARE(ui_img_trackball_png);
LV_IMG_DECLARE(ui_img_toolbox_80_png);
LV_IMG_DECLARE(ui_img_lower_80_png);
LV_IMG_DECLARE(ui_img_raise_80_png);
LV_IMG_DECLARE(ui_img_controller80_png);


LV_IMG_DECLARE(ui_img_numpad_80_png);

LV_FONT_DECLARE(ui_font_Font1);
LV_FONT_DECLARE(ui_font_Font18);
LV_FONT_DECLARE(ui_font_Font16);
LV_FONT_DECLARE(ui_font_Font12);
LV_FONT_DECLARE(extra_symbols);


//////////////////////////////////////////////////////////////
// User Defines
#define ARC_SIZE 176
#define ARC_WIDTH 34
#define ARC_POS_X 0
#define ARC_POS_Y 80
#define ARC_Y ARC_POS_Y
#define MENU_KNOB_SIZE 110
#define LAYER_POS_Y -60
#define LAYER_POS_X 0



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
