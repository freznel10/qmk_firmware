// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H
#include "freznel.h"

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

#include "fonts/eleganticons.h"
// #include "fonts/fonts.h"

extern lv_obj_t * ui_Screen1;
// extern lv_obj_t * ui_Screen1_Image2;
extern lv_obj_t * ui_Screen1_Button1;
extern lv_obj_t * ui_Screen1_Label_RGB;
extern lv_obj_t * ui_Screen1_Label_WPM;
#ifdef OS_DETECTION_ENABLE
extern lv_obj_t * ui_Screen1_Label_OS;
#endif
#ifdef CUSTOM_KEYLOGGER
extern lv_obj_t * ui_Screen1_Label_KL;
#endif
extern lv_obj_t * ui_Screen1_Image1;
// extern lv_obj_t * ui_Screen1_Panel_KB_Status;
// extern lv_obj_t * ui_Screen1_Label_CAPS;
// extern lv_obj_t * ui_Screen1_Label_SCLK;
// extern lv_obj_t * ui_Screen1_Label_NMLK;
// extern lv_obj_t * ui_Screen1_Label_AUDIO;
// extern lv_obj_t * ui_Screen1_Label_CLICKY;
// extern lv_obj_t * ui_Screen1_Label_ACRT;
// extern lv_obj_t * ui_Screen1_Panel_Status;
// extern lv_obj_t * ui_Screen1_Label_H;
// extern lv_obj_t * ui_Screen1_Label_S;
// extern lv_obj_t * ui_Screen1_Label_V;
extern lv_obj_t * ui_Screen1_Panel_HSV;
// extern lv_obj_t * ui_Screen1_Label_CTRL;
// extern lv_obj_t * ui_Screen1_Label_ALT;
// extern lv_obj_t * ui_Screen1_Label_GUI;
// extern lv_obj_t * ui_Screen1_Label_SHIFT;
// extern lv_obj_t * ui_Screen1_Label_CTRL_1;
// extern lv_obj_t * ui_Screen1_Label_ALT_1;
// extern lv_obj_t * ui_Screen1_Label_GUI_1;
// extern lv_obj_t * ui_Screen1_Label_SHIFT_1;
extern lv_obj_t * labels[];

extern lv_obj_t * ui_Layer_Indicator;
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_Screen2_Image2;
extern lv_obj_t * ui_Screen2_deflayer;
extern lv_obj_t * ui_Label_PM_mode;
extern lv_obj_t * ui_Screen2_Label_PM_side;
extern lv_obj_t * ui_Panel_Layer;
extern lv_obj_t * ui_Label_Layer_Name;
extern lv_obj_t * ui_Panel_Pointing_Mode;
extern lv_obj_t * ui_Screen2_Label_Pointing_Mode;
extern lv_obj_t * ui_Screen2_Label_CPI;
extern lv_obj_t * ui_PM_led1;
extern lv_obj_t * ui_PM_led2;
extern lv_obj_t * ui_PM_led3;
extern lv_obj_t * ui_Label_Unicode_Mode;

extern lv_obj_t * ui_Arc1;
extern lv_obj_t * ui_Label_Dpi;
extern lv_obj_t * ui_DpiTitle;

extern lv_obj_t * ui_Colorwheel1;

extern lv_obj_t * ui_Mods;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Label4;

extern lv_obj_t * ui_Status;
extern lv_obj_t * ui_CapsLock;
extern lv_obj_t * ui_Clicky;
extern lv_obj_t * ui_ScrollLock;
extern lv_obj_t * ui_Audio;
extern lv_obj_t * ui_NumLock;
extern lv_obj_t * ui_Autocorrect;

extern lv_obj_t * ui_wpmPanel;
extern lv_obj_t * ui_wpmCount;
extern lv_obj_t * ui_wpmLabel;

extern lv_obj_t * ui_HueArc;

extern lv_obj_t * ui_HSVPanel;
extern lv_obj_t * ui_HSVLabel;
extern lv_obj_t * ui_RGBLabel;

// extern lv_obj_t * ui_Screen1;
// extern lv_obj_t * ui_Main1;
// extern lv_obj_t * ui_Image1;
// extern lv_obj_t * ui_Arc1;
// extern lv_obj_t * ui_Panel1;
// extern lv_obj_t * ui_Layer1;
// extern lv_obj_t * ui_Panel2;
// extern lv_obj_t * ui_Label1;
// extern lv_obj_t * ui_Arc3;
// extern lv_obj_t * ui_Settings1;
// extern lv_obj_t * ui_SettingsMain;
// extern lv_obj_t * ui_Screen2;
// extern lv_obj_t * ui_SettingsAux;
// extern lv_obj_t * ui_Settings2;
// extern lv_obj_t * ui_StatusPanel;
// extern lv_obj_t * ui_Status_Sniping;
// extern lv_obj_t * ui_Status_Dragscroll;
// extern lv_obj_t * ui_Status_Caret;
// extern lv_obj_t * ui_Status_Volume;
// extern lv_obj_t * ui_Status_Audio;N
// extern lv_obj_t * ui_Status_Clicky;
// extern lv_obj_t * ui_Status_Autocorrect;
// extern lv_obj_t * meter;
extern lv_obj_t * mbox1;
extern lv_obj_t * mbox2;
// extern lv_meter_indicator_t * indic3;
// void screen_loader(lv_event_t * e);
// void ui_event_StatusPanel(lv_event_t * e);
// void screen_loader_2(lv_event_t * e);
void set_cpi_text_value(lv_obj_t* lbl);
void set_wpm_text_value(lv_obj_t* lbl);
void set_pm_text_value(lv_obj_t* lbl);
void set_unicode_mode_text_value(lv_obj_t* lbl);
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
void lvgl_event_triggers(void);
void lv_anim_2 (lv_obj_t * TargetObject);
void render_mods_circular(lv_obj_t *scr);

int get_icon_x_coordinate(int angle_degrees);
int get_icon_y_coordinate(int angle_degrees);

void render_pointing (lv_obj_t *scr, lv_coord_t x, lv_coord_t y );
void render_mods (lv_obj_t *scr, lv_coord_t x, lv_coord_t y );
void render_status (lv_obj_t *scr, lv_coord_t x, lv_coord_t y );
void render_wpm (lv_obj_t *scr, lv_coord_t x, lv_coord_t y );
void render_Hue (lv_obj_t *scr);
void render_rgb_mode (lv_obj_t *scr, lv_coord_t x, lv_coord_t y );

// void lvgl_control_led_indicators(void);
// void ui_event_Settings1(lv_event_t * e);
// void ui_event_SettingsAux(lv_event_t * e);
// void ui_dflayer_dropdown_create (void);

// LV_IMG_DECLARE(ui_img_emblem_80_png);    // assets\emblem_80.png
// LV_IMG_DECLARE(ui_img_trackball_png);
// LV_IMG_DECLARE(ui_img_toolbox_80_png);
// LV_IMG_DECLARE(ui_img_lower_80_png);
// LV_IMG_DECLARE(ui_img_raise_80_png);

// LV_IMG_DECLARE(ui_img_numpad_80_png);

// LV_FONT_DECLARE(ui_font_Font1);
// LV_FONT_DECLARE(ui_font_Font18);
// LV_FONT_DECLARE(ui_font_Font16);
// LV_FONT_DECLARE(ui_font_Font12);
// LV_FONT_DECLARE(extra_symbols);

LV_FONT_DECLARE(ui_font_Futura12);
LV_FONT_DECLARE(ui_font_Futura18);
LV_FONT_DECLARE(ui_font_Futura20);
LV_FONT_DECLARE(ui_font_Futura22);
LV_FONT_DECLARE(ui_font_Futura24);
LV_FONT_DECLARE(eleganticons);
LV_FONT_DECLARE(ui_font_GaretHeavy14);
LV_FONT_DECLARE(ui_font_GaretHeavy16);
LV_FONT_DECLARE(ui_font_GaretHeavy18);
LV_FONT_DECLARE(ui_font_GaretHeavy48);
LV_FONT_DECLARE(ui_font_SpaceGrotesk50);
LV_FONT_DECLARE(ui_font_SpaceGrotesk18);
LV_FONT_DECLARE(ui_font_Space11);

LV_IMG_DECLARE(ui_img_2120736529);
LV_IMG_DECLARE(ui_img_bk80_png);
LV_IMG_DECLARE(ui_img_logo_test_png);
LV_IMG_DECLARE(ui_img_logo_png);
LV_IMG_DECLARE(ui_img_city_png);
LV_IMG_DECLARE(ui_img_emblem_80_png);    // assets\emblem_80.png
LV_IMG_DECLARE(ui_img_trackball_png);
LV_IMG_DECLARE(ui_img_toolbox_80_png);
LV_IMG_DECLARE(ui_img_lower_80_png);
LV_IMG_DECLARE(ui_img_raise_80_png);
LV_IMG_DECLARE(ui_img_numpad_80_png);
LV_IMG_DECLARE(ui_img_ui_image_adjust_png);
LV_IMG_DECLARE(monitormund);
LV_IMG_DECLARE(ui_img_2040_png);    // assets\2040.png
LV_IMG_DECLARE(ui_img_chunky_lower_png);    // assets\Chunky_Lower.png
LV_IMG_DECLARE(ui_img_chunky_upper_png);    // assets\Chunky_Upper.png
LV_IMG_DECLARE(ui_img_chunky2040_v3_png);

LV_IMG_DECLARE(ui_img_caps_lock_32_png);    // assets\caps_lock_32.png
LV_IMG_DECLARE(ui_img_clicky_32_png);    // assets\clicky_32.png
LV_IMG_DECLARE(ui_img_scroll_lock_32_png);    // assets\scroll_lock_32.png
LV_IMG_DECLARE(ui_img_audio_32_png);    // assets\audio_32.png
LV_IMG_DECLARE(ui_img_num_lock_32_png);    // assets\num_lock_32.png
LV_IMG_DECLARE(ui_img_autocorrect_32_png);    // assets\autocorrect_32.png

LV_IMG_DECLARE(ui_img_20466782); //baldur's gate logo


// //////////////////////////////////////////////////////////////
// // User Defines
// #define ARC_SIZE 176
// #define ARC_WIDTH 34
// #define ARC_POS_X 0
// #define ARC_POS_Y 80
// #define ARC_Y ARC_POS_Y
// #define MENU_KNOB_SIZE 110
// #define LAYER_POS_Y -60
// #define LAYER_POS_X 0

#define TFT_WIDTH 240
#define TFT_HEIGHT 240

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
