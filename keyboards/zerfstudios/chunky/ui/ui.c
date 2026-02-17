// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project
 // * Copyright 2023 Freznel B. Sta. Ana <freznel@gmail.com> (@freznel10)

#include "ui.h"
#include "ui_helpers.h"
#include "bindings/bindings.h"
#include "freznel.h"
#include <ctype.h>
#include "../chunky/chunky.h"
#include "quantum.h"
#include "users/freznel/split/transport_sync.h"
#ifdef OS_DETECTION_ENABLE
#include "os_detection.h"
#endif
#include <stdio.h>
#include <stdint.h>
#include "math.h"
#include "lv_math.h"

// #include "menu.h"
// #include "dial_menu/dial_menu.h"
// #include "settings/appr/appr.h"
// #include "styles/styles.h"
// #include "widgets/bpm.h"
// #include "settings/screensaver/screensaver.h"

extern user_runtime_config_t user_state;
extern userspace_config_t userspace_config;
extern unicode_config_t unicode_config;

// ///////////////////// VARIABLES ////////////////////
// extern uint8_t scroll_mode;i
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Screen1_Button1;
lv_obj_t * ui_Screen1_Image1;
// lv_obj_t * ui_Screen1_Panel_KB_Status;
// lv_obj_t * ui_Screen1_Label_CAPS;
// lv_obj_t * ui_Screen1_Label_SCLK;
// lv_obj_t * ui_Screen1_Label_NMLK;
lv_obj_t * ui_Screen1_Panel_HSV;
// lv_obj_t * ui_Screen1_Label_AUDIO;
// lv_obj_t * ui_Screen1_Label_CLICKY;
// lv_obj_t * ui_Screen1_Label_ACRT;
// lv_obj_t * ui_Screen1_Label_H;
// lv_obj_t * ui_Screen1_Label_S;
// lv_obj_t * ui_Screen1_Label_V;
lv_obj_t * ui_Screen2_Label_CPI;
lv_obj_t * ui_Screen1_Label_RGB;
#ifdef UI_RENDER_WPM
lv_obj_t * ui_Screen1_Label_WPM;
#endif
lv_obj_t * ui_Screen1_Label_OS;
// lv_obj_t * ui_Screen1_Label_CTRL;
// lv_obj_t * ui_Screen1_Label_ALT;
// lv_obj_t * ui_Screen1_Label_GUI;
// lv_obj_t * ui_Screen1_Label_SHIFT;
// lv_obj_t * ui_Screen1_Panel_Status;
#ifdef CUSTOM_KEYLOGGER
lv_obj_t * ui_Screen1_Label_KL;
#endif
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Screen2_Image2;
lv_obj_t * ui_Screen2_deflayer;
lv_obj_t * ui_Screen2_deflayer_list;
lv_obj_t * ui_Layer_Indicator;
lv_obj_t * ui_Label_PM_mode;
lv_obj_t * ui_Screen2_Label_PM_side;
lv_obj_t * ui_Panel_Layer;
lv_obj_t * ui_Label_Layer_Name;
lv_obj_t * ui_Panel_Pointing_Mode;
lv_obj_t * ui_Screen2_Label_Pointing_Mode;
lv_obj_t * ui_PM_led1;
lv_obj_t * ui_PM_led2;
lv_obj_t * ui_PM_led3;
lv_obj_t * ui_Label_Unicode_Mode;
lv_obj_t * monitormund_test;

lv_obj_t * ui_Arc1;
lv_obj_t * ui_Label_Dpi;
lv_obj_t * ui_DpiTitle;

lv_obj_t * ui_Colorwheel1;

// lv_obj_t * ui_Main1;
// lv_obj_t * ui_Image1;
// lv_obj_t * ui_Arc1;
// lv_obj_t * ui_Panel1;
// lv_obj_t * ui_Layer1;
// lv_obj_t * ui_Panel2;
// lv_obj_t * ui_Label1;
// lv_obj_t * ui_Arc3;
// lv_obj_t * ui_dflayer_dropdown;
// lv_obj_t * ui_Settings1;
// lv_obj_t * ui_SettingsMain;
// lv_obj_t * ui_Screen2;
// lv_obj_t * ui_SettingsAux;
// lv_obj_t * ui_Settings2;
// lv_obj_t * ui_StatusPanel;
// lv_obj_t * ui_Status_Sniping;
// lv_obj_t * ui_Status_Dragscroll;
// lv_obj_t * ui_Status_Caret;
// lv_obj_t * ui_Status_Volume;
// lv_obj_t * ui_Sktatus_Audio;
// lv_obj_t * ui_Status_Clicky;
// lv_obj_t * ui_Status_Autocorrect;
// lv_obj_t * meter;
lv_obj_t * mbox1;
lv_obj_t * mbox1_title;
lv_obj_t * mbox1_text;
lv_obj_t * mbox2;
lv_obj_t * mbox2_title;
lv_obj_t * mbox2_text;
// lv_obj_t * mbox2;
// lv_obj_t * mbox2_title;
// lv_obj_t * mbox2_text;
// lv_meter_indicator_t * indic3;

lv_obj_t * ui_Mods;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label4;

lv_obj_t * ui_Status;
lv_obj_t * ui_CapsLock;
lv_obj_t * ui_Clicky;
lv_obj_t * ui_ScrollLock;
lv_obj_t * ui_Audio;
lv_obj_t * ui_NumLock;
lv_obj_t * ui_Autocorrect;

lv_obj_t * ui_wpmPanel;
lv_obj_t * ui_wpmCount;
lv_obj_t * ui_wpmLabel;

lv_obj_t * ui_HueArc;

lv_obj_t * ui_HSVPanel;
lv_obj_t * ui_HSVLabel;
lv_obj_t * ui_RGBLabel;

lv_timer_t* timer;

// #define NUM_ICONS 10
// #define CIRCLE_RADIUS 100
// #define X_OFFSET 20
// #define Y_OFFSET 5

// char *label_text[NUM_ICONS] = {
//     "GUI",
//     "ALT",
//     "CTRL",
//     "SHIFT",
//     "CAPS",
//     "NMLK",
//     "SCLC",
//     "AUD",
//     "CLCK",
//     "ACRT",
// };

// lv_obj_t *labels[NUM_ICONS] = {NULL};


#define LV_STYLE_INIT(var_name, prop_array) lv_style_t var_name = { .v_p = { .const_props = prop_array }, .has_group = 0xFF, .is_const = 1 }
#define C_LV_STYLE_PROP_INV { .prop = LV_STYLE_PROP_INV, .value = {0} }

lv_style_t style_label_futura22;
lv_style_t style_label_futura20;
lv_style_t style_label_futura18;
lv_style_t style_label_futura12;
lv_style_t style_panel_flex_mods;

const lv_style_const_prop_t style_label_futura22_props[] = {
    LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE16(0xff, 0xff, 0xff)),
    LV_STYLE_CONST_TEXT_FONT(&ui_font_Futura22),
    LV_STYLE_CONST_WIDTH(LV_SIZE_CONTENT),
    LV_STYLE_CONST_HEIGHT(LV_SIZE_CONTENT),
    LV_STYLE_CONST_ALIGN(LV_ALIGN_CENTER),
    C_LV_STYLE_PROP_INV,

};
LV_STYLE_INIT(style_label_futura22, style_label_futura22_props);


const lv_style_const_prop_t style_label_futura20_props[] = {
    LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE16(0xff, 0xff, 0xff)),
    LV_STYLE_CONST_TEXT_FONT(&ui_font_Futura20),
    LV_STYLE_CONST_WIDTH(LV_SIZE_CONTENT),
    LV_STYLE_CONST_HEIGHT(LV_SIZE_CONTENT),
    LV_STYLE_CONST_ALIGN(LV_ALIGN_CENTER),
    C_LV_STYLE_PROP_INV,

};
LV_STYLE_INIT(style_label_futura20, style_label_futura20_props);

const lv_style_const_prop_t style_label_futura18_props[] = {
    LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE16(0xff, 0xff, 0xff)),
    LV_STYLE_CONST_TEXT_FONT(&ui_font_Futura18),
    LV_STYLE_CONST_WIDTH(LV_SIZE_CONTENT),
    LV_STYLE_CONST_HEIGHT(LV_SIZE_CONTENT),
    LV_STYLE_CONST_ALIGN(LV_ALIGN_CENTER),
    C_LV_STYLE_PROP_INV,

};
LV_STYLE_INIT(style_label_futura18, style_label_futura18_props);


const lv_style_const_prop_t style_label_futura12_props[] = {
    LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE16(0xff, 0xff, 0xff)),
    LV_STYLE_CONST_TEXT_FONT(&ui_font_Futura12),
    LV_STYLE_CONST_WIDTH(LV_SIZE_CONTENT),
    LV_STYLE_CONST_HEIGHT(LV_SIZE_CONTENT),
    LV_STYLE_CONST_ALIGN(LV_ALIGN_CENTER),
    C_LV_STYLE_PROP_INV,

};
LV_STYLE_INIT(style_label_futura12, style_label_futura12_props);


const lv_style_const_prop_t style_label_futura24_props[] = {
    LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE16(0xff, 0xff, 0xff)),
    LV_STYLE_CONST_TEXT_FONT(&ui_font_Futura24),
    LV_STYLE_CONST_WIDTH(LV_SIZE_CONTENT),
    LV_STYLE_CONST_HEIGHT(LV_SIZE_CONTENT),
    LV_STYLE_CONST_ALIGN(LV_ALIGN_CENTER),
    C_LV_STYLE_PROP_INV,

};
LV_STYLE_INIT(style_label_futura24, style_label_futura24_props);


    // static lv_style_t style_test_2;
    // lv_style_init(&style_test_2);
    // lv_style_set_pad_all(&style_test_2, 0);
    // lv_style_set_layout(&style_test_2,LV_LAYOUT_FLEX );
    // lv_style_set_pad_left(&style_test_2, 0);
    // lv_style_set_pad_right(&style_test_2, 0);
    // lv_style_set_pad_top(&style_test_2, 0);
    // lv_style_set_pad_bottom(&style_test_2, 0);
    // lv_style_set_pad_row(&style_test_2, 1);
    // lv_style_set_pad_column(&style_test_2, 5);
    // lv_style_set_flex_flow(&style_test_2, LV_FLEX_FLOW_ROW);
    // lv_style_set_flex_main_place(&style_test_2, LV_FLEX_ALIGN_SPACE_AROUND);
    // lv_style_set_flex_cross_place(&style_test_2, LV_FLEX_ALIGN_CENTER );
    // lv_style_set_flex_track_place(&style_test_2, LV_FLEX_ALIGN_CENTER);

// const lv_style_const_prop_t style_panel_flex_mods_props[] = {
//     LV_STYLE_CONST_PAD_TOP(0),
//     LV_STYLE_CONST_PAD_BOTTOM(0),
//     LV_STYLE_CONST_PAD_LEFT(0),
//     LV_STYLE_CONST_PAD_RIGHT(0),
//     LV_STYLE_CONST_PAD_ROW(1),
//     LV_STYLE_CONST_PAD_COLUMN(5),
//     C_LV_STYLE_PROP_INV,
// };

// LV_STYLE_INIT(style_panel_flex_mods, style_panel_flex_mods_props);






//----------------------------------------------------------
// RGB Matrix naming

extern rgb_config_t rgb_matrix_config;

//----------------------------------------------------------
// RGB Matrix naming
#if defined(RGB_MATRIX_ENABLE)
#    include <rgb_matrix.h>

#    if defined(RGB_MATRIX_EFFECT)
#        undef RGB_MATRIX_EFFECT
#    endif // defined(RGB_MATRIX_EFFECT)

#    define RGB_MATRIX_EFFECT(x) RGB_MATRIX_EFFECT_##x,
enum {
    RGB_MATRIX_EFFECT_NONE,
#    include "rgb_matrix_effects.inc"
#    undef RGB_MATRIX_EFFECT
#    ifdef RGB_MATRIX_CUSTOM_KB
#        include "rgb_matrix_kb.inc"
#    endif
#    ifdef RGB_MATRIX_CUSTOM_USER
#        include "rgb_matrix_user.inc"
#    endif
};

#    define RGB_MATRIX_EFFECT(x)    \
        case RGB_MATRIX_EFFECT_##x: \
            return #x;
const char *rgb_matrix_name(uint8_t effect) {
    switch (effect) {
        case RGB_MATRIX_EFFECT_NONE:
            return "NONE";
#    include "rgb_matrix_effects.inc"
#    undef RGB_MATRIX_EFFECT
#    ifdef RGB_MATRIX_CUSTOM_KB
#        include "rgb_matrix_kb.inc"
#    endif
#    ifdef RGB_MATRIX_CUSTOM_USER
#        include "rgb_matrix_user.inc"
#    endif
        default:
            return "UNKNOWN";
    }
}
#endif // defined(RGB_MATRIX_ENABLE)

///////////////////// CUSTOM EVENTS ////////////////////
uint32_t USER_EVENT_DF_LAYER_CHANGE;
uint32_t USER_EVENT_CPI_UPDATE;
uint32_t USER_EVENT_WPM_UPDATE;
uint32_t USER_EVENT_ACTIVE_LAYER_CHANGE;
uint32_t USER_EVENT_PANEL_CHANGE;
uint32_t USER_EVENT_RGBMODE_UPDATE;
uint32_t USER_EVENT_CAPS_WORD_UPDATE;
uint32_t USER_EVENT_PM_STATE_CHANGE;
uint32_t USER_EVENT_PM_SIDE_CHANGE;
uint32_t USER_EVENT_AM_STATE_CHANGE;
uint32_t USER_EVENT_RGBHUE_UPDATE;
uint32_t USER_EVENT_RGBSAT_UPDATE;
uint32_t USER_EVENT_RGBVAL_UPDATE;
uint32_t USER_EVENT_KEYLOG_UPDATE;
uint32_t USER_EVENT_UNICODE_MODE_UPDATE;



///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

// ///////////////////// ANIMATIONS ////////////////////

// void pulse_Animation(lv_obj_t * TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 100);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
//     lv_anim_set_values(&PropertyAnimation_0, 0, 150);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, 1);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_zoom);
//     lv_anim_start(&PropertyAnimation_0);
//     lv_anim_t PropertyAnimation_1;
//     lv_anim_init(&PropertyAnimation_1);
//     lv_anim_set_time(&PropertyAnimation_1, 100);
//     lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_image_zoom);
//     lv_anim_set_values(&PropertyAnimation_1, 150, 0);
//     lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_1, delay + 200);
//     lv_anim_set_playback_time(&PropertyAnimation_1, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_1, 1);
//     lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_1, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_image_zoom);
//     lv_anim_start(&PropertyAnimation_1);
// }

void lv_msgbox_1(void) {
    mbox1 = lv_msgbox_create(ui_Screen1, "CAPS WORD", "ACTIVE", NULL, false);// Do something when Caps Word activates.
    mbox1_title = lv_msgbox_get_title(mbox1);
    mbox1_text = lv_msgbox_get_text(mbox1);
    lv_obj_set_style_text_font(mbox1_title, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(mbox1_text, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_x(mbox1_title, 0);
    lv_obj_set_style_text_align(mbox1_title, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_x(mbox1_text, 0);
    lv_obj_set_style_text_align(mbox1_text, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(mbox1_text, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_center(mbox1);
    lv_obj_center(mbox1_title);
    lv_obj_center(mbox1_text);
}

void lv_msgbox_pm_mode(void) {
    mbox2 = lv_msgbox_create(ui_Screen2, "DRAGSCROLL", "ACTIVE", NULL, false);
    mbox2_title = lv_msgbox_get_title(mbox2);
    mbox2_text = lv_msgbox_get_text(mbox2);
    lv_obj_set_style_text_font(mbox2_title, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(mbox2_text, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_x(mbox2_title, 0);
    lv_obj_set_style_text_align(mbox2_title, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_x(mbox2_text, 0);
    lv_obj_set_style_text_align(mbox2_text, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(mbox2_text, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_center(mbox2);
    lv_obj_center(mbox2_title);
    lv_obj_center(mbox2_text);

}

#if defined(AUTOCORRECT_ENABLE) && defined(AUDIO_ENABLE)
#    ifdef USER_SONG_LIST

float autocorrect_song[][2] = SONG(MARIO_GAMEOVER);
#    else
float autocorrect_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#    endif
bool apply_autocorrect(uint8_t backspaces, const char* str, char *typo, char *correct) {
    PLAY_SONG(autocorrect_song);
    return true;
}

float violin_song[][2] = SONG(VIOLIN_SOUND);

void caps_word_set_user(bool active) {
    if (active) {
        PLAY_SONG(autocorrect_song);
        lv_msgbox_1();
    } else {
        PLAY_SONG(violin_song);// Do something when Caps Word deactivates.
        lv_msgbox_close(mbox1);
    }
}
#endif

static void anim_x_cb(void * var, int32_t v)
{
    lv_obj_set_x(var, v);
}

static void anim_size_cb(void * var, int32_t v)
{
    lv_obj_set_size(var, v, v);
}

/**
 * Create a playback animation
 */
void lv_anim_2(lv_obj_t * TargetObject) {

    lv_anim_t a;
    lv_anim_set_user_data(&a, TargetObject);
    lv_anim_init(&a);
    lv_anim_set_var(&a, TargetObject);
    lv_anim_set_values(&a, 10, 90);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_playback_delay(&a, 100);
    lv_anim_set_playback_time(&a, 300);
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_repeat_count(&a, 1);
    lv_anim_set_path_cb(&a, lv_anim_path_linear);

    lv_anim_set_exec_cb(&a, anim_size_cb);
    lv_anim_start(&a);
    lv_anim_set_exec_cb(&a, anim_x_cb);
    lv_anim_set_values(&a, 0, 0);
    lv_anim_start(&a);
}

/////////////////////// FUNCTIONS ////////////////////
/*WPM RENDER*/
void set_wpm_text_value(lv_obj_t* lbl) {
    if (lv_obj_is_valid(lbl)) {
        char buf[9];
        snprintf(buf, sizeof(buf), "%d", (int)qmk_lv_get_bpm());
        lv_label_set_text(lbl, buf);
    }
}
void ui_render_wpm(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_WPM_UPDATE) {
        set_wpm_text_value(ui_wpmCount);
    }
}


/*HUE REDRAW*/
void ui_render_rgbhue_redraw(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target(e);
    lv_color_hsv_t wheel_color = qmk_lv_rgb_matrix_get_hsv();
    static lv_color_t trial;
    static lv_color_t trial_2;
    static lv_color_t trial_3;
    static lv_color_t trial_4;
    // static lv_color_t trial_5;
    // static lv_color_t trial_6;
    // static lv_color_t trial_7;
    // static lv_color_t trial_8;
    static uint16_t trial_hue;
    trial_hue = (rgb_matrix_get_hue() * 360) / 255;//((rgb_matrix_get_hue() * 360) >> 8);
    trial = lv_color_hsv_to_rgb(trial_hue, wheel_color.s, wheel_color.v);
    trial_2 = lv_color_hsv_to_rgb((trial_hue + 8), wheel_color.s, wheel_color.v);
    trial_3 = lv_color_hsv_to_rgb((trial_hue + 34), wheel_color.s, wheel_color.v);
    trial_4 = lv_color_hsv_to_rgb((trial_hue + 64), wheel_color.s, wheel_color.v);
    // trial_5 = lv_color_hsv_to_rgb((trial_hue + 44), 100, 100);
    // trial_6 = lv_color_hsv_to_rgb((trial_hue + 54), 100, 100);
    // trial_7 = lv_color_hsv_to_rgb((trial_hue + 64), 100, 100);
    // trial_8 = lv_color_hsv_to_rgb((trial_hue + 84), 100, 100);
    if(event_code == USER_EVENT_RGBHUE_UPDATE) {
        if(target == ui_Screen2) {
            lv_obj_set_style_outline_color(ui_Panel_Layer, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(ui_Panel_Pointing_Mode, trial_2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(ui_Screen2_deflayer, trial_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        if(target == ui_Colorwheel1 ) {
            lv_colorwheel_set_hsv(ui_Colorwheel1, wheel_color);
        }
        if(target == ui_Screen1) {
            // lv_obj_set_style_outline_color(ui_Screen1_Panel_Status, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            // lv_obj_set_style_outline_color(ui_Screen1_Panel_KB_Status, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            // lv_obj_set_style_outline_color(ui_Screen1_Panel_HSV, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_Label1, trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label2, trial_2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label3, trial_3, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label4, trial_4, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_arc_color(ui_HueArc, trial, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_HueArc, trial, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_arc_set_value(ui_HueArc, trial_hue);
            // lv_obj_set_style_text_color(labels[4], trial_7, LV_PART_MAIN | LV_STATE_FOCUSED);
            // lv_obj_set_style_text_color(labels[5], trial_8, LV_PART_MAIN | LV_STATE_FOCUSED);
            // lv_obj_set_style_text_color(labels[6], trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            // lv_obj_set_style_text_color(labels[7], trial_4, LV_PART_MAIN | LV_STATE_FOCUSED);
            // lv_obj_set_style_text_color(labels[8], trial_5, LV_PART_MAIN | LV_STATE_FOCUSED);
            // lv_obj_set_style_text_color(labels[9], trial_6, LV_PART_MAIN | LV_STATE_FOCUSED);
        }
        if(target == ui_HSVLabel) {
            char buf[17];
            snprintf(buf, sizeof(buf), "H:%d S:%d V:%d", rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val());
            lv_label_set_text(ui_HSVLabel, buf);
        }

    }
}

void ui_render_rgbval_redraw(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target(e);
    lv_color_hsv_t wheel_color = qmk_lv_rgb_matrix_get_hsv();
    static lv_color_t redraw_val;
    redraw_val =  lv_color_hsv_to_rgb(wheel_color.h, wheel_color.s, wheel_color.v);
    if(event_code == USER_EVENT_RGBVAL_UPDATE) {
        if(target == ui_HSVLabel) {
            char buf[17];
            snprintf(buf, sizeof(buf), "H:%d S:%d V:%d", rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val());
            lv_label_set_text(ui_HSVLabel, buf);
        }
        if(target == ui_Colorwheel1) {
            lv_colorwheel_set_hsv(ui_Colorwheel1, wheel_color);
        }
        if(target == ui_HueArc) {
            lv_obj_set_style_arc_color(ui_HueArc, redraw_val, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_HueArc, redraw_val, LV_PART_KNOB | LV_STATE_DEFAULT);
        }

    }
}

void ui_render_rgbsat_redraw(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target(e);
    lv_color_hsv_t wheel_color = qmk_lv_rgb_matrix_get_hsv();
    static lv_color_t redraw_sat;
    redraw_sat =  lv_color_hsv_to_rgb(wheel_color.h, wheel_color.s, wheel_color.v);
    if(event_code == USER_EVENT_RGBSAT_UPDATE) {
        if(target == ui_HSVLabel) {
            char buf[18];
            snprintf(buf, sizeof(buf), "H:%d S:%d V:%d", rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val());
            lv_label_set_text(ui_HSVLabel, buf);
        }
        if(target == ui_Colorwheel1) {
            lv_colorwheel_set_hsv(ui_Colorwheel1, wheel_color);
        }
        if(target == ui_HueArc) {
            lv_obj_set_style_arc_color(ui_HueArc, redraw_sat, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_HueArc, redraw_sat, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
    }
}


//user_state.split_pointing_mode)
/*OS RENDER*/
#ifdef OS_DETECTION_ENABLE
void set_OS_text_value(lv_obj_t* lbl) {
    if (lv_obj_is_valid(lbl)) {
        char buf[12];
        const char *detected_os = "-----";
        switch (is_keyboard_left() ? detected_host_os() : user_state.detected_os) {
             case 0:
                detected_os = "UNSURE";
                break;
            case 1:
                detected_os = "LINUX";
                break;
            case 2:
                detected_os = "WINDOWS";
                break;
            case 3:
                detected_os = "MACOS";
                break;
            case 4:
                detected_os = "IOS";
                break;
        }
        snprintf(buf, sizeof(buf), "OS: %s", detected_os);
        lv_label_set_text(lbl, buf);
    }
}
#endif

/*CUSTOM UNICODE RENDER*/
#ifdef CUSTOM_UNICODE_ENABLE
extern const char unicode_mode_str;

void set_unicode_mode_text_value(lv_obj_t* lbl) {
    if (lv_obj_is_valid(lbl)) {
        char buf[32];
        const char *unicode_mode_display = "-----";
        switch (user_state.unicode_typing_mode) {
             case 0:
                unicode_mode_display = "NO MODE";
                break;
            case 1:
                unicode_mode_display = "WIDE";
                break;
            case 2:
                unicode_mode_display = "SCRIPT";
                break;
            case 3:
                unicode_mode_display = "BLOCKS";
                break;
            case 4:
                unicode_mode_display = "REGIONAL";
                break;
            case 5:
                unicode_mode_display = "AUSSIE";
                break;
            case 6:
                unicode_mode_display = "ZALGO";
                break;
            case 7:
                unicode_mode_display = "SUPER";
                break;
            // case 8:
            //     unicode_mode_display = "COMIC";
            //     break;
            default:
                unicode_mode_display = " ";
                break;
        }

        snprintf(buf, sizeof(buf), "UM: %s", unicode_mode_display);
        lv_label_set_text(lbl, buf);
    }
}

void ui_unicode_mode_change(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == USER_EVENT_UNICODE_MODE_UPDATE ) {
        if (target == ui_Label_Unicode_Mode) {
            set_unicode_mode_text_value(ui_Label_Unicode_Mode);
        }
    }
}
#endif


/*PM RENDER*/
void set_pm_text_value(lv_obj_t* lbl) {
    if (lv_obj_is_valid(lbl)) {
        char buf[34];
        const char *pm_name = "-----";
        const char *pm_side = "-";
        switch (user_state.split_pointing_mode) {
            case PM_NONE:
                pm_name = "PM: NONE";
                break;
            case PM_DRAG:
                pm_name = "PM_DRAG";
                break;
            case PM_BROW:
                pm_name = "BROWSER";
                break;
            case PM_RGB_MODE_VAL:
                pm_name = "RGB_VAL";
                break;
            case PM_RGB_HUE_SAT:
                pm_name = "RGB_SAT";
                break;
            case PM_RGB_SPEED:
                pm_name = "RGB_SPEED";
                break;
            case PM_WINDOW:
                pm_name = "WINDOW";
                break;
            case PM_SWITCHER:
                pm_name = "SWITCHER";
                break;
            case PM_BROWSER_CONTROL:
                pm_name = "BACK_FWD";
                break;
            case PM_CARET:
                pm_name = "CARET";
                break;
            case PM_HISTORY:
                pm_name = "HISTORY";
                break;
            case PM_VOL:
                pm_name = "VOLUME";
                break;
            case PM_APP_2:
                pm_name = "ALT_TAB";
                break;
            case PM_WIN_POS:
                pm_name = "WIN_POS";
                break;
            case PM_CUR_ACCEL:
                pm_name = "ACCELL";
                break;
            case PM_PRECISION:
                pm_name = "PRECISION";
                break;
            default:
                pm_name = "PM: NONE";
                break;
        }
        switch (user_state.pointing_side) {
             case 0:
                pm_side = "P";
                break;
            case 1:
                pm_side = "S";
                break;
        }
        snprintf(buf, sizeof(buf), "%s %s", pm_name, pm_side);
        lv_label_set_text(lbl, buf);
    }
}

void ui_pm_state_change(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == USER_EVENT_PM_STATE_CHANGE) {
        if (target == ui_Label_PM_mode) {
            set_pm_text_value(ui_Label_PM_mode);
        }
    }
    // if(event_code == USER_EVENT_PM_SIDE_CHANGE) {
    //     if ((target == ui_PM_led1 || ui_PM_led2) && ( user_state.pointing_side == PM_LEFT_DEVICE )) {
    //             lv_led_on(ui_PM_led1);
    //             lv_led_off(ui_PM_led2);
    //     } else {
    //             lv_led_off(ui_PM_led1);
    //             lv_led_on(ui_PM_led2);
    //     }
    // }
}

void ui_am_state_change(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_AM_STATE_CHANGE) {
            lv_led_on(ui_PM_led3);
        } else {
            lv_led_off(ui_PM_led3);
        }

}

/*DF LAYER RENDER*/
void ui_event_dflayer_dropdown(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
         switch (lv_dropdown_get_selected(target)) {
            case 0:
                set_single_persistent_default_layer(0);
                break;
            case 1:
                set_single_persistent_default_layer(1);
                break;
            case 2:
                set_single_persistent_default_layer(2);
                break;
            case 3:
                set_single_persistent_default_layer(3);
                break;
        }
        dprintf("Default layer changed");
    }
    if(event_code == USER_EVENT_DF_LAYER_CHANGE) {
         switch (get_highest_layer(default_layer_state)) {
            case 0:
                lv_dropdown_set_selected(target, 0);
                break;
            case 1:
                lv_dropdown_set_selected(target, 1);
                break;
            case 2:
                lv_dropdown_set_selected(target, 2);
                break;
            case 3:
                lv_dropdown_set_selected(target, 3);
                break;
        }
        dprintf("Default layer changed");
    }
}

/*CPI RENDER*/
void set_cpi_text_value(lv_obj_t* lbl) {
    if (lv_obj_is_valid(lbl)) {
        char buf[5];
        snprintf(buf, sizeof(buf), "%d", (int)qmk_lv_get_cpi());
        lv_label_set_text(lbl, buf);
    }
}

void ui_render_cpi(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == USER_EVENT_CPI_UPDATE) {
        if (target == ui_Label_Dpi) {
            set_cpi_text_value(ui_Label_Dpi);
        }
        if (target == ui_Arc1) {
            lv_arc_set_value(ui_Arc1, qmk_lv_get_cpi());
        }

    }
}

/*CAPSWORD RENDER*/
void ui_render_caps_word(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_CAPS_WORD_UPDATE) {
        lv_msgbox_1();
    }
}

/*RGB Naming*/
void set_rgbmode_text_value(lv_obj_t* lbl) {
    uint8_t curr_effect = rgb_matrix_config.mode;
    if (lv_obj_is_valid(lbl)) {
        char buf[32];
        snprintf(buf, sizeof(buf), "%s", rgb_matrix_name(curr_effect));
            for (int i = 1; i < sizeof(buf); ++i) {
                if (buf[i] == 0)
                    break;
                else if (buf[i] == '_')
                    buf[i] = ' ';
                else if (buf[i - 1] == ' ')
                    buf[i] = toupper(buf[i]);
                else if (buf[i - 1] != ' ')
                    buf[i] = tolower(buf[i]);
            }
        lv_label_set_text(lbl, buf);
    }
}

void ui_render_rgbmode(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_RGBMODE_UPDATE) {
         set_rgbmode_text_value(ui_RGBLabel);
    }
}

void gif_load (lv_obj_t* scr) {
    monitormund_test = lv_gif_create(ui_Screen2);
    lv_gif_set_src(monitormund_test, &monitormund);
    lv_obj_align(monitormund_test, LV_ALIGN_CENTER, 0, 0);

} //further testing neededo for this.

/*ACTIVE LAYER CHANGE*/
void ui_active_layer_change(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_ACTIVE_LAYER_CHANGE) {
        switch (get_highest_layer(layer_state | default_layer_state )) {
            case _COLEMAK_DH:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_chunky2040_v3_png);
                // &ui_img_emblem_80_png
                lv_label_set_text(ui_Label_Layer_Name, "LAYER");
                break;
            case 1:
                lv_img_set_src(ui_Layer_Indicator,  &ui_img_chunky2040_v3_png);
                lv_label_set_text(ui_Label_Layer_Name, "LAYER");
                break;
            case 2:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
                lv_label_set_text(ui_Label_Layer_Name, "LAYER");
                break;
            case 3:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
                lv_label_set_text(ui_Label_Layer_Name, "LAYER");
                break;
            case _BG:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_20466782);
                lv_label_set_text(ui_Label_Layer_Name, "BALDUR");
                break;
            case _KEYPAD:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_numpad_80_png);
                lv_label_set_text(ui_Label_Layer_Name, "KEYPAD");
                break;
            case _MOUSE:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_trackball_png);
                lv_label_set_text(ui_Label_Layer_Name, "MOUSE");
                break;
            case _LOWER:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_chunky_lower_png);
                lv_label_set_text(ui_Label_Layer_Name, "LOWER");
                 break;
            case _RAISE:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_chunky_upper_png);
                lv_label_set_text(ui_Label_Layer_Name, "RAISE");
                break;
            case _ADJUST:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_ui_image_adjust_png);
                lv_label_set_text(ui_Label_Layer_Name, "ADJUST");
                break;

            // case _MEDIA:
            //     lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
            //     lv_label_set_text(ui_Label_Layer_Name, "MEDIA");
            case _GAMEPAD:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
                lv_label_set_text(ui_Label_Layer_Name, "GAMEPAD");
                break;

        }
        // lv_anim_2(ui_Layer_Indicator);
    }
}

#ifdef CUSTOM_KEYLOGGER
static const char PROGMEM code_to_name[256] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,  // 3x
    0xDB,0xDC,0xDD,0xDE,0XDF,0xFB,'P', 'S',  19, ' ',  17,  30,  16,  16,  31,  26,  // 4x
     27,  25,  24, 'N', '/', '*', '-', '+',  23, '1', '2', '3', '4', '5', '6', '7',  // 5x
    '8', '9', '0', '.','\\', 'A',   0, '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ',   0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', 0x2E, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  24,  26,  24,  // Ex
     25,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,  24,  25,  27,  26, ' ', ' ', ' '   // Fx
};



// #    define KEYLOGGER_LENGTH 8
char        painter_keylog_str[KEYLOGGER_LENGTH] = {0};
static bool klog_redraw                          = false;

void add_keylog(uint16_t keycode, keyrecord_t* record) {
    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
        keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    } else if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    } else if (keycode >= QK_MODS && keycode <= QK_MODS_MAX) {
        keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
    }

    if ((keycode == KC_BSPC) && mod_config(get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL) {
        memset(painter_keylog_str, ' ', KEYLOGGER_LENGTH);
        painter_keylog_str[KEYLOGGER_LENGTH - 1] = 0x00;
        return;
    }
    if (record->tap.count) {
        keycode &= 0xFF;
    } else if (keycode > 0xFF) {
        return;
    }

    memmove(painter_keylog_str, painter_keylog_str + 1, KEYLOGGER_LENGTH - 2);

    if (keycode < ARRAY_SIZE(code_to_name)) {
        painter_keylog_str[(KEYLOGGER_LENGTH - 2)] = pgm_read_byte(&code_to_name[keycode]);
        klog_redraw                                = true;
    }
}

// void set_keylogger(const char keylogger, lv_obj_t* ui_Screen1_Label_KL) {
//     if (lv_obj_is_valid(ui_Label1)) {
//         char buf[5];
//         snprintf(buf, sizeof(buf), "%s", keylog_str);
//         lv_label_set_text(ui_Screen1_Label_KL, buf);
//     }
// }


static void ui_render_keylogger(lv_timer_t* timer) {
    LV_UNUSED(timer);
    lv_obj_t* ui_Screen1_Label_KL = timer->user_data;;
    if(lv_obj_is_valid(ui_Screen1_Label_KL)) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%s", painter_keylog_str);
        lv_label_set_text(ui_Screen1_Label_KL, buf);
    }
}
#endif

//PANELS

// void render_panel_pointing (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font, lv_style_t * style_font_2,
//                             lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {

//     ui_Panel_Pointing_Mode = lv_obj_create(ui_Screen2);
//     lv_obj_set_width(ui_Panel_Pointing_Mode, w);
//     lv_obj_set_height(ui_Panel_Pointing_Mode, h);
//     lv_obj_set_x(ui_Panel_Pointing_Mode, x);
//     lv_obj_set_y(ui_Panel_Pointing_Mode, y);
//     lv_obj_set_align(ui_Panel_Pointing_Mode, align);
//     lv_obj_clear_flag(ui_Panel_Pointing_Mode, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     // gif_load(ui_Screen2);

//     lv_obj_set_style_outline_opa(ui_Panel_Pointing_Mode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_width(ui_Panel_Pointing_Mode, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_pad(ui_Panel_Pointing_Mode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


//     ui_PM_led3  = lv_led_create(ui_Panel_Pointing_Mode);
//     lv_obj_set_size(ui_PM_led3, 10, 10);
//     lv_obj_align(ui_PM_led3, LV_ALIGN_CENTER, ((w/2)-40), ((h/2)-15) * (-1));
//     lv_led_set_brightness(ui_PM_led3, 255);
//     lv_led_set_color(ui_PM_led3, lv_palette_main(LV_PALETTE_GREEN));

//     ui_Screen2_Label_Pointing_Mode = lv_label_create(ui_Panel_Pointing_Mode);
//     lv_obj_set_x(ui_Screen2_Label_Pointing_Mode, 0);
//     lv_obj_set_y(ui_Screen2_Label_Pointing_Mode, 15);
//     lv_obj_add_style(ui_Screen2_Label_Pointing_Mode, style_font_2, 0);
//     lv_label_set_text(ui_Screen2_Label_Pointing_Mode, "POINTING MODE");

//     ui_Screen2_Label_CPI = lv_label_create(ui_Panel_Pointing_Mode);
//     lv_obj_set_x(ui_Screen2_Label_CPI, 0);
//     lv_obj_set_y(ui_Screen2_Label_CPI, 35);
//     lv_obj_add_style(ui_Screen2_Label_CPI, style_font, 0);

//     lv_obj_add_event_cb(ui_PM_led1, ui_pm_state_change, USER_EVENT_PM_SIDE_CHANGE, NULL);
//     lv_obj_add_event_cb(ui_PM_led2, ui_pm_state_change, USER_EVENT_PM_SIDE_CHANGE, NULL);
//     lv_obj_add_event_cb(ui_PM_led3, ui_am_state_change, USER_EVENT_AM_STATE_CHANGE, NULL); //not working ATM
//     lv_obj_add_event_cb(ui_Screen2_Label_CPI, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);
// }

void render_panel_deflayer (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, const lv_font_t * deflayer_font,
                            lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {

    ui_Screen2_deflayer = lv_dropdown_create(scr);
    static const char * opts = "COLEMAK_DH\n"
                               "COLEMAK\n"
                               "QWERTY\n"
                               "DVORAK";
    lv_dropdown_set_options_static(ui_Screen2_deflayer, opts);
    ui_Screen2_deflayer_list =  lv_dropdown_get_list(ui_Screen2_deflayer) ;
    lv_obj_set_style_text_font(ui_Screen2_deflayer_list , deflayer_font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(ui_Screen2_deflayer, 140);
    lv_obj_set_height(ui_Screen2_deflayer, 35);
    lv_obj_set_x(ui_Screen2_deflayer, x);
    lv_obj_set_y(ui_Screen2_deflayer, y);
    lv_obj_set_align(ui_Screen2_deflayer, align);
    lv_obj_add_flag(ui_Screen2_deflayer, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_bg_color(ui_Screen2_deflayer, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen2_deflayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen2_deflayer, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen2_deflayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Screen2_deflayer, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(lv_dropdown_get_list(ui_Screen2_deflayer), lv_color_hex(0xFFFFFF),  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_dropdown_get_list(ui_Screen2_deflayer), 0,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_deflayer, &ui_font_GaretHeavy14, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Screen2_deflayer, event_cb, filter, user_data);


}

void render_rgb_mode_status (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font,
                            lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {
    ui_Screen1_Label_RGB = lv_label_create(scr);
    lv_obj_set_align(ui_Screen1_Label_RGB, align);
    lv_obj_set_x(ui_Screen1_Label_RGB, x);
    lv_obj_set_y(ui_Screen1_Label_RGB, y);
    lv_obj_add_style(ui_Screen1_Label_RGB, style_font, 0);
    lv_label_set_text(ui_Screen1_Label_RGB, "RGB");
    lv_obj_add_event_cb(ui_Screen1_Label_RGB, event_cb, filter, user_data);
}

void render_panel_layer (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_coord_t layer_image_w, lv_coord_t layer_image_h, lv_style_t *layer_font, lv_style_t *unicode_mode_font,
                            lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {
    ui_Panel_Layer = lv_obj_create(scr);
    lv_obj_set_width(ui_Panel_Layer, w);
    lv_obj_set_height(ui_Panel_Layer, h);
    // lv_obj_set_width(ui_Panel_Layer, 140);
    // lv_obj_set_height(ui_Panel_Layer, 120);
    lv_obj_set_pos(ui_Panel_Layer, x, y);
    lv_obj_set_align(ui_Panel_Layer, align);
    lv_obj_clear_flag(ui_Panel_Layer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags;
    // lv_obj_set_style_outline_opa(ui_Panel_Layer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_outline_width(ui_Panel_Layer, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_outline_pad(ui_Panel_Layer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_color(ui_Panel_Layer, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_opa(ui_Panel_Layer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_Panel_Layer, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_Panel_Layer, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_Panel_Layer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel_Layer, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Layer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel_Layer, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_Label_Layer_Name = lv_label_create(ui_Panel_Layer);
    lv_obj_set_pos(ui_Label_Layer_Name, 0, ((h/2) - 12));
    lv_obj_add_style(ui_Label_Layer_Name, layer_font, 0);
    lv_label_set_text(ui_Label_Layer_Name, "LAYER");

    ui_Layer_Indicator = lv_img_create(ui_Panel_Layer);
    lv_img_set_zoom(ui_Layer_Indicator, IMAGE_LAYER_ZOOM);
    lv_obj_set_align(ui_Layer_Indicator, align);
    lv_obj_set_width(ui_Layer_Indicator, layer_image_h);
    lv_obj_set_height(ui_Layer_Indicator, layer_image_w);
    lv_obj_set_pos(ui_Layer_Indicator, 0, -5);
    lv_obj_clear_flag(ui_Layer_Indicator, LV_OBJ_FLAG_SCROLLABLE);

#ifdef CUSTOM_UNICODE_ENABLE
    ui_Label_Unicode_Mode = lv_label_create(ui_Panel_Layer);
    lv_obj_set_pos(ui_Label_Unicode_Mode, 0, ((h/2) - 12) * (-1));
    lv_obj_add_style(ui_Label_Unicode_Mode, unicode_mode_font, 0);
    lv_label_set_text(ui_Label_Unicode_Mode, " ");
#endif

    lv_obj_add_event_cb(ui_Label_Layer_Name, event_cb, filter, user_data);
    lv_obj_add_event_cb(ui_Layer_Indicator, event_cb, filter, user_data);
    lv_obj_add_event_cb(ui_Label_Unicode_Mode, ui_unicode_mode_change, USER_EVENT_UNICODE_MODE_UPDATE, NULL);
}

// void render_panel_kb_status (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font,
//                             lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {
//     // static lv_style_t style_test;
//     // lv_style_init(&style_test);
//     // lv_style_set_layout(&style_test, LV_LAYOUT_FLEX);
//     // lv_style_set_flex_flow(&style_test, LV_FLEX_FLOW_ROW_WRAP);
//     // lv_style_set_flex_main_place(&style_test, LV_FLEX_ALIGN_CENTER);
//     // lv_style_set_flex_cross_place(&style_test, LV_FLEX_ALIGN_START );
//     // lv_style_set_flex_track_place(&style_test, LV_FLEX_ALIGN_SPACE_EVENLY);

//     static lv_style_t style_test;
//     static lv_coord_t column_dsc[] = {((TFT_WIDTH - 80)/3), ((TFT_WIDTH - 80)/3), ((TFT_WIDTH - 80)/3), LV_GRID_TEMPLATE_LAST};   /*2 columns with 100 and 400 ps width*/
//     static lv_coord_t row_dsc[] = {30, 30, LV_GRID_TEMPLATE_LAST}; /*3 100 px tall rows*/
//     lv_style_init(&style_test);
//     lv_style_set_layout(&style_test, LV_LAYOUT_GRID);
//     lv_style_set_grid_column_align(&style_test, LV_GRID_ALIGN_CENTER);
//     lv_style_set_grid_row_dsc_array(&style_test, row_dsc);
//     lv_style_set_grid_column_dsc_array(&style_test, column_dsc);
//     lv_style_set_pad_all(&style_test, 0);


//     ui_Screen1_Panel_KB_Status = lv_obj_create(scr);
//     lv_obj_add_style(ui_Screen1_Panel_KB_Status, &style_test, 0);
//     lv_obj_set_x(ui_Screen1_Panel_KB_Status, x);
//     lv_obj_set_y(ui_Screen1_Panel_KB_Status, y);
//     lv_obj_set_content_width(ui_Screen1_Panel_KB_Status, w);
//     lv_obj_set_content_height(ui_Screen1_Panel_KB_Status, h);
//     lv_obj_set_width(ui_Screen1_Panel_KB_Status, w);
//     lv_obj_set_height(ui_Screen1_Panel_KB_Status, h);
//     lv_obj_set_align(ui_Screen1_Panel_KB_Status, align);
//     lv_obj_add_flag(ui_Screen1_Panel_KB_Status, LV_OBJ_FLAG_CLICKABLE);
//     lv_obj_add_flag(ui_Screen1_Panel_KB_Status, LV_OBJ_FLAG_CLICK_FOCUSABLE);
//     lv_obj_add_flag(ui_Screen1_Panel_KB_Status, LV_OBJ_FLAG_CHECKABLE);
//     lv_obj_clear_flag(ui_Screen1_Panel_KB_Status, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_add_style(ui_Screen1_Panel_KB_Status, style_font, 0);
//     lv_obj_set_style_outline_opa(ui_Screen1_Panel_KB_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_width(ui_Screen1_Panel_KB_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_pad(ui_Screen1_Panel_KB_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_color(ui_Screen1_Panel_KB_Status, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_opa(ui_Screen1_Panel_KB_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_Screen1_Panel_KB_Status, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_Screen1_Panel_KB_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

//     // uint32_t i;
//     // for(i = 0; i < 6; i++) {
//     //     uint8_t grid_col = i % 3;
//     //     uint8_t grid_row = i / 2;
//         ui_Screen1_Label_CAPS = lv_label_create(ui_Screen1_Panel_KB_Status);
//         lv_label_set_text(ui_Screen1_Label_CAPS, "CAPS");
//         lv_obj_set_grid_cell(ui_Screen1_Label_CAPS, LV_GRID_ALIGN_CENTER  , 0, 1, LV_GRID_ALIGN_CENTER   , 0, 1);

//         ui_Screen1_Label_SCLK = lv_label_create(ui_Screen1_Panel_KB_Status);
//         lv_label_set_text(ui_Screen1_Label_SCLK, "SCLK");
//         lv_obj_set_grid_cell(ui_Screen1_Label_SCLK, LV_GRID_ALIGN_CENTER  , 1, 1, LV_GRID_ALIGN_CENTER  , 0, 1);

//         ui_Screen1_Label_NMLK = lv_label_create(ui_Screen1_Panel_KB_Status);
//         lv_label_set_text(ui_Screen1_Label_NMLK, "NMLK");
//         lv_obj_set_grid_cell(ui_Screen1_Label_NMLK, LV_GRID_ALIGN_CENTER  , 2, 1, LV_GRID_ALIGN_CENTER  , 0, 1);

//         ui_Screen1_Label_AUDIO = lv_label_create(ui_Screen1_Panel_KB_Status);
//         lv_label_set_text(ui_Screen1_Label_AUDIO, "AUD");
//         lv_obj_set_grid_cell(ui_Screen1_Label_AUDIO, LV_GRID_ALIGN_CENTER , 0, 1, LV_GRID_ALIGN_CENTER , 1, 1);

//         ui_Screen1_Label_CLICKY = lv_label_create(ui_Screen1_Panel_KB_Status);
//         lv_label_set_text(ui_Screen1_Label_CLICKY, "CLKY");
//         lv_obj_set_grid_cell(ui_Screen1_Label_CLICKY, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER , 1, 1);

//         ui_Screen1_Label_ACRT = lv_label_create(ui_Screen1_Panel_KB_Status);
//         lv_label_set_text(ui_Screen1_Label_ACRT, "ACRT");
//         lv_obj_set_grid_cell(ui_Screen1_Label_ACRT, LV_GRID_ALIGN_CENTER , 2, 1, LV_GRID_ALIGN_CENTER , 1, 1);
//     // }

//     lv_obj_add_event_cb(ui_Screen1_Panel_KB_Status, event_cb, filter, user_data);
// }

// void render_panel_HSV (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font,
//                             lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {
//     static lv_style_t hsv_style;
//     lv_style_init(&hsv_style);
//     lv_style_set_layout(&hsv_style, LV_LAYOUT_FLEX );
//     lv_style_set_flex_flow(&hsv_style, LV_FLEX_FLOW_ROW_WRAP);
//     lv_style_set_pad_left(&hsv_style, 0);
//     lv_style_set_pad_right(&hsv_style, 0);
//     lv_style_set_pad_top(&hsv_style, 0);
//     lv_style_set_pad_bottom(&hsv_style, 0);
//     lv_style_set_pad_row(&hsv_style, 1);
//     lv_style_set_pad_column(&hsv_style, 5);
//     lv_style_set_flex_flow(&hsv_style, LV_FLEX_FLOW_ROW);
//     lv_style_set_flex_main_place(&hsv_style, LV_FLEX_ALIGN_CENTER);
//     lv_style_set_flex_cross_place(&hsv_style, LV_FLEX_ALIGN_START );
//     lv_style_set_flex_track_place(&hsv_style, LV_FLEX_ALIGN_SPACE_BETWEEN);


//     ui_Screen1_Panel_HSV = lv_obj_create(scr);
//     lv_obj_add_style (ui_Screen1_Panel_HSV, &hsv_style, 0);
//     lv_obj_set_width(ui_Screen1_Panel_HSV, w);
//     lv_obj_set_height(ui_Screen1_Panel_HSV, h);
//     lv_obj_set_x(ui_Screen1_Panel_HSV, x);
//     lv_obj_set_y(ui_Screen1_Panel_HSV, y);
//     lv_obj_set_align(ui_Screen1_Panel_HSV, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_Screen1_Panel_HSV, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_add_style(ui_Screen1_Panel_HSV, style_font, 0);
//     lv_obj_set_style_outline_opa(ui_Screen1_Panel_HSV, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_width(ui_Screen1_Panel_HSV, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_pad(ui_Screen1_Panel_HSV, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_color(ui_Screen1_Panel_HSV, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_opa(ui_Screen1_Panel_HSV, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_Screen1_Panel_HSV, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_Screen1_Panel_HSV, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
//     render_rgb_mode_status(ui_Screen1_Panel_HSV, LV_ALIGN_TOP_LEFT, 5, -15, LV_SIZE_CONTENT, LV_SIZE_CONTENT, &style_label_futura18, ui_render_rgbmode, USER_EVENT_RGBMODE_UPDATE, NULL);

//     // ui_Screen1_Label_H = lv_label_create(ui_Screen1_Panel_HSV);
//     // lv_obj_add_flag(ui_Screen1_Label_H, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
//     // lv_label_set_text(ui_Screen1_Label_H, "H");

//     // ui_Screen1_Label_S = lv_label_create(ui_Screen1_Panel_HSV);
//     // lv_label_set_text(ui_Screen1_Label_S, "S");

//     // ui_Screen1_Label_V = lv_label_create(ui_Screen1_Panel_HSV);
//     // lv_label_set_text(ui_Screen1_Label_V, "V");


//     // lv_obj_add_event_cb(ui_Screen1_Panel_HSV, event_cb, filter, user_data);
//     // lv_obj_add_event_cb(ui_Screen1_Label_H, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
//     // lv_obj_add_event_cb(ui_Screen1_Label_S, ui_render_rgbsat_redraw, USER_EVENT_RGBSAT_UPDATE, NULL);
//     // lv_obj_add_event_cb(ui_Screen1_Label_V, ui_render_rgbval_redraw, USER_EVENT_RGBVAL_UPDATE, NULL);
// }

// void render_panel_mods (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font,
//                             lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {


//     static lv_style_t style_test_2;
//     lv_style_init(&style_test_2);
//     lv_style_set_pad_all(&style_test_2, 0);
//     lv_style_set_layout(&style_test_2,LV_LAYOUT_FLEX );
//     lv_style_set_pad_left(&style_test_2, 0);
//     lv_style_set_pad_right(&style_test_2, 0);
//     lv_style_set_pad_top(&style_test_2, 0);
//     lv_style_set_pad_bottom(&style_test_2, 0);
//     lv_style_set_pad_row(&style_test_2, 1);
//     lv_style_set_pad_column(&style_test_2, 5);
//     lv_style_set_flex_flow(&style_test_2, LV_FLEX_FLOW_ROW);
//     lv_style_set_flex_main_place(&style_test_2, LV_FLEX_ALIGN_SPACE_AROUND);
//     lv_style_set_flex_cross_place(&style_test_2, LV_FLEX_ALIGN_CENTER );
//     lv_style_set_flex_track_place(&style_test_2, LV_FLEX_ALIGN_CENTER);

//     ui_Screen1_Panel_Status = lv_obj_create(scr);
//     lv_obj_set_width(ui_Screen1_Panel_Status, w);
//     lv_obj_set_height(ui_Screen1_Panel_Status, h);
//     lv_obj_set_x(ui_Screen1_Panel_Status, x);
//     lv_obj_set_y(ui_Screen1_Panel_Status, y);
//     lv_obj_set_align(ui_Screen1_Panel_Status, align);
//     lv_obj_clear_flag(ui_Screen1_Panel_Status, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_add_style(ui_Screen1_Panel_Status, style_font, 0);
//     lv_obj_add_style(ui_Screen1_Panel_Status, &style_test_2, 0);

//     lv_obj_set_style_outline_opa(ui_Screen1_Panel_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_width(ui_Screen1_Panel_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_pad(ui_Screen1_Panel_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_color(ui_Screen1_Panel_Status, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_opa(ui_Screen1_Panel_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_Screen1_Panel_Status, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_Screen1_Panel_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_Screen1_Label_GUI = lv_label_create(ui_Screen1_Panel_Status);
//     lv_label_set_text(ui_Screen1_Label_GUI, "GUI");

//     ui_Screen1_Label_ALT = lv_label_create(ui_Screen1_Panel_Status);
//     lv_label_set_text(ui_Screen1_Label_ALT, "ALT");

//     ui_Screen1_Label_CTRL = lv_label_create(ui_Screen1_Panel_Status);
//     lv_label_set_text(ui_Screen1_Label_CTRL, "CTRL");
//     lv_obj_add_flag(ui_Screen1_Label_CTRL, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);

//     ui_Screen1_Label_SHIFT = lv_label_create(ui_Screen1_Panel_Status);
//     lv_label_set_text(ui_Screen1_Label_SHIFT, "SHIFT");

//     lv_obj_add_event_cb(ui_Screen1_Panel_Status, event_cb, filter, user_data);
// }



// Calculate the x coordinate of the icon based on the angle
// int get_icon_x_coordinate(int angle_degrees) {
//     float angle_radians = (angle_degrees * M_PI) / 180.0;
//     return (int)(CIRCLE_RADIUS * cos(angle_radians) + TFT_WIDTH / 2);
// }

// // Calculate the y coordinate of the icon based on the angle
// int get_icon_y_coordinate(int angle_degrees) {
//     float angle_radians = (angle_degrees * M_PI) / 180.0;
//     return (int)(CIRCLE_RADIUS * sin(angle_radians) + TFT_HEIGHT / 2);
// }

    // for (int i = 0; i < NUM_ICONS; i++) {
    //     int angle_degrees = i * (360 / NUM_ICONS);
    //     labels[i] = lv_label_create(ui_Screen1);
    //     lv_label_set_text(labels[i], label_text[i]);
    //     lv_obj_set_align(labels[i], LV_ALIGN_TOP_LEFT);
    //     lv_obj_set_pos(labels[i], get_icon_x_coordinate(angle_degrees) - X_OFFSET, get_icon_y_coordinate(angle_degrees) - Y_OFFSET);
    //     lv_obj_set_style_text_font(labels[i], &ui_font_Futura18, LV_PART_MAIN);
    // }


bool process_record_painter(uint16_t keycode, keyrecord_t *record) {
#ifdef CUSTOM_KEYLOGGER
    if (record->event.pressed) {
        add_keylog(keycode, record);
    }
    #endif
    return true;
}

void render_cpi_arc(lv_obj_t *scr) {
    ui_Arc1 = lv_arc_create(scr);
    lv_obj_set_width(ui_Arc1, 230);
    lv_obj_set_height(ui_Arc1, 230);
    lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Arc1, 200, 3400);
    lv_arc_set_bg_angles(ui_Arc1, 220, 320);
    lv_obj_set_style_arc_width(ui_Arc1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0xFC0707), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xF81717), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_Arc1, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);
}

void render_pointing (lv_obj_t *scr, lv_coord_t x, lv_coord_t y ){
    ui_Label_Dpi = lv_label_create(scr);
    lv_obj_set_width(ui_Label_Dpi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Dpi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_pos(ui_Label_Dpi, x, y);
    lv_obj_set_align(ui_Label_Dpi, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label_Dpi, "3200");
    lv_obj_set_style_text_font(ui_Label_Dpi, &ui_font_GaretHeavy48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DpiTitle = lv_label_create(scr);
    lv_obj_set_width(ui_DpiTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DpiTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_pos(ui_DpiTitle, x, (y + (-31)));
    lv_obj_set_align(ui_DpiTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DpiTitle, "DPI");
    lv_obj_set_style_text_font(ui_DpiTitle, &ui_font_GaretHeavy18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_Label_Dpi, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);

    ui_Label_PM_mode = lv_label_create(scr);
    lv_obj_set_align(ui_Label_PM_mode, LV_ALIGN_CENTER);
    lv_obj_set_pos(ui_Label_PM_mode, x, y + 31);
    lv_obj_set_style_text_font(ui_Label_PM_mode, &ui_font_GaretHeavy18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(ui_Label_PM_mode, " ");
    lv_obj_add_event_cb(ui_Label_PM_mode, ui_pm_state_change, USER_EVENT_PM_STATE_CHANGE, NULL);
}

void render_rgb (lv_obj_t *scr) {
    ui_Colorwheel1 = lv_colorwheel_create(scr, true);
    lv_color_hsv_t color = qmk_lv_rgb_matrix_get_hsv();
    lv_obj_set_width(ui_Colorwheel1, 160);
    lv_obj_set_height(ui_Colorwheel1, 160);
    lv_obj_set_align(ui_Colorwheel1, LV_ALIGN_CENTER);

    lv_obj_set_style_pad_left(ui_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_colorwheel_set_hsv(ui_Colorwheel1, color);

    lv_obj_set_style_pad_left(ui_Colorwheel1, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Colorwheel1, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Colorwheel1, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Colorwheel1, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Colorwheel1, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Colorwheel1, ui_render_rgbsat_redraw, USER_EVENT_RGBSAT_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Colorwheel1, ui_render_rgbval_redraw, USER_EVENT_RGBVAL_UPDATE, NULL);
}

void render_mods (lv_obj_t *scr, lv_coord_t x, lv_coord_t y) {

    ui_Mods = lv_obj_create(scr);
    lv_obj_set_width(ui_Mods, 66);
    lv_obj_set_height(ui_Mods, 135);
    lv_obj_set_x(ui_Mods, x);
    lv_obj_set_y(ui_Mods, y);
    lv_obj_set_align(ui_Mods, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Mods, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_flex_align(ui_Mods, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Mods, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Mods, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Mods, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Mods, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Mods, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Mods, &ui_font_GaretHeavy18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Mods);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "SHIFT");

    ui_Label2 = lv_label_create(ui_Mods);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "CTRL");

    ui_Label3 = lv_label_create(ui_Mods);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "ALT");

    ui_Label4 = lv_label_create(ui_Mods);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "GUI");

}

void render_status (lv_obj_t *scr, lv_coord_t x, lv_coord_t y ) {
    ui_Status = lv_obj_create(scr);
    lv_obj_set_width(ui_Status, 116);
    lv_obj_set_height(ui_Status, 75);
    lv_obj_set_x(ui_Status, x);
    lv_obj_set_y(ui_Status, y);
    lv_obj_set_align(ui_Status, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Status, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_flex_align(ui_Status, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Status, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Status, lv_color_hex(0x474141), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Status, lv_color_hex(0x222020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Status, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Status, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CapsLock = lv_img_create(ui_Status);
    lv_img_set_src(ui_CapsLock, &ui_img_caps_lock_32_png);
    lv_obj_set_width(ui_CapsLock, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CapsLock, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_CapsLock, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_CapsLock, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CapsLock, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_CapsLock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_CapsLock, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_CapsLock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_img_recolor_opa(ui_CapsLock, 0, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Clicky = lv_img_create(ui_Status);
    lv_img_set_src(ui_Clicky, &ui_img_clicky_32_png);
    lv_obj_set_width(ui_Clicky, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Clicky, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Clicky, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Clicky, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Clicky, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Clicky, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Clicky, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Clicky, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_img_recolor_opa(ui_Clicky, 0, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_ScrollLock = lv_img_create(ui_Status);
    lv_img_set_src(ui_ScrollLock, &ui_img_scroll_lock_32_png);
    lv_obj_set_width(ui_ScrollLock, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScrollLock, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ScrollLock, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScrollLock, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScrollLock, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_ScrollLock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_ScrollLock, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_ScrollLock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_img_recolor_opa(ui_ScrollLock, 0, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Audio = lv_img_create(ui_Status);
    lv_img_set_src(ui_Audio, &ui_img_audio_32_png);
    lv_obj_set_width(ui_Audio, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Audio, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Audio, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Audio, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Audio, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Audio, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Audio, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Audio, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_img_recolor_opa(ui_Audio, 0, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_NumLock = lv_img_create(ui_Status);
    lv_img_set_src(ui_NumLock, &ui_img_num_lock_32_png);
    lv_obj_set_width(ui_NumLock, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_NumLock, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_NumLock, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_NumLock, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NumLock, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_NumLock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_NumLock, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_NumLock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_img_recolor_opa(ui_NumLock, 0, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Autocorrect = lv_img_create(ui_Status);
    lv_img_set_src(ui_Autocorrect, &ui_img_autocorrect_32_png);
    lv_obj_set_width(ui_Autocorrect, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Autocorrect, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Autocorrect, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Autocorrect, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Autocorrect, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Autocorrect, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Autocorrect, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Autocorrect, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_img_recolor_opa(ui_Autocorrect, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
}

void render_wpm (lv_obj_t *scr, lv_coord_t x, lv_coord_t y) {
    ui_wpmPanel = lv_obj_create(scr);
    lv_obj_set_width(ui_wpmPanel, 100);
    lv_obj_set_height(ui_wpmPanel, 79);
    lv_obj_set_x(ui_wpmPanel, x);
    lv_obj_set_y(ui_wpmPanel, y);
    lv_obj_set_align(ui_wpmPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_wpmPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_wpmPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_wpmPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_wpmPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wpmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_wpmPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_wpmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_wpmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_wpmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_wpmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_wpmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_wpmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_wpmPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wpmCount = lv_label_create(ui_wpmPanel);
    lv_obj_set_width(ui_wpmCount, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wpmCount, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wpmCount, LV_ALIGN_CENTER);
    lv_label_set_text(ui_wpmCount, "240");
    lv_obj_set_style_text_font(ui_wpmCount, &ui_font_SpaceGrotesk50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_wpmCount, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_wpmCount, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_wpmCount, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_wpmCount, -9, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_wpmCount, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_wpmCount, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wpmLabel = lv_label_create(ui_wpmPanel);
    lv_obj_set_width(ui_wpmLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wpmLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wpmLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_wpmLabel, "WPM");
    lv_obj_set_style_text_font(ui_wpmLabel, &ui_font_SpaceGrotesk18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_wpmLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_wpmLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_wpmLabel, -5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_wpmLabel, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_wpmLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_wpmLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_wpmCount, ui_render_wpm, USER_EVENT_WPM_UPDATE, NULL);
}

void render_Hue (lv_obj_t *scr) {
    ui_HueArc = lv_arc_create(scr);
    lv_obj_set_width(ui_HueArc, 230);
    lv_obj_set_height(ui_HueArc, 230);
    lv_obj_set_align(ui_HueArc, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_HueArc, 0, 360);

    lv_arc_set_angles(ui_HueArc, 330, 30);
    lv_arc_set_bg_angles(ui_HueArc, 330, 30);
    lv_obj_set_style_arc_width(ui_HueArc, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_HueArc, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_HueArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_HueArc, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_HueArc, lv_color_hex(0xF81717), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HueArc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_HueArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_HueArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_HueArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_HueArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_HueArc, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_HueArc, ui_render_rgbsat_redraw, USER_EVENT_RGBSAT_UPDATE, NULL);
    lv_obj_add_event_cb(ui_HueArc, ui_render_rgbval_redraw, USER_EVENT_RGBVAL_UPDATE, NULL);
}

void render_rgb_mode (lv_obj_t *scr, lv_coord_t x, lv_coord_t y) {
    ui_HSVPanel = lv_obj_create(scr);
    lv_obj_set_width(ui_HSVPanel, 141);
    lv_obj_set_height(ui_HSVPanel, 53);
    lv_obj_set_x(ui_HSVPanel, x);
    lv_obj_set_y(ui_HSVPanel, y);
    lv_obj_set_align(ui_HSVPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_HSVPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_HSVPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_HSVPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_HSVPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HSVPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_HSVPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_HSVPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HSVLabel = lv_label_create(ui_HSVPanel);
    lv_obj_set_width(ui_HSVLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HSVLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_HSVLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HSVLabel, "H:000 S:000 V:000");
    lv_obj_set_style_text_font(ui_HSVLabel, &ui_font_GaretHeavy14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RGBLabel = lv_label_create(ui_HSVPanel);
    lv_obj_set_width(ui_RGBLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_RGBLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_RGBLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_RGBLabel, "MODE");
    lv_obj_set_style_text_font(ui_RGBLabel, &ui_font_GaretHeavy14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_RGBLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_RGBLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_RGBLabel, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_RGBLabel, -1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_HSVLabel, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_HSVLabel, ui_render_rgbsat_redraw, USER_EVENT_RGBSAT_UPDATE, NULL);
    lv_obj_add_event_cb(ui_HSVLabel, ui_render_rgbval_redraw, USER_EVENT_RGBVAL_UPDATE, NULL);
    lv_obj_add_event_cb(ui_RGBLabel, ui_render_rgbmode, USER_EVENT_RGBMODE_UPDATE, NULL);

}
///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // render_rgb_mode_status(ui_Screen1, LV_ALIGN_TOP_LEFT, 5, 57, LV_SIZE_CONTENT, LV_SIZE_CONTENT, &style_label_futura18, ui_render_rgbmode, USER_EVENT_RGBMODE_UPDATE, NULL);
    // render_panel_kb_status (ui_Screen1, LV_ALIGN_CENTER, 0, -55, (TFT_WIDTH - 80), 70, &style_label_futura22, 0, 0, 0);
    // render_panel_HSV (ui_Screen1, LV_ALIGN_CENTER, 0, -50, (TFT_WIDTH - 80) , 50, &style_label_futura18, 0, 0, 0);
    // render_panel_mods (ui_Screen1, LV_ALIGN_CENTER, 0, 100, (TFT_WIDTH - 80), 70, &style_label_futura18, 0, 0, 0);
    render_mods(ui_Screen1, -66, 0);
    render_status(ui_Screen1, 17, 58);
    render_wpm(ui_Screen1, 14, -80);
    render_Hue(ui_Screen1);
    render_rgb_mode (ui_Screen1, 30, -11);

    // lv_obj_t *labels[NUM_ICONS];
    // for (int i = 0; i < NUM_ICONS; i++) {
    //     int angle_degrees = i * (360 / NUM_ICONS);
    //     labels[i] = lv_label_create(ui_Screen1);
    //     lv_label_set_text(labels[i], label_text[i]);
    //     lv_obj_set_align(labels[i], LV_ALIGN_TOP_LEFT);
    //     lv_obj_set_pos(labels[i], get_icon_x_coordinate(angle_degrees) - X_OFFSET, get_icon_y_coordinate(angle_degrees) - Y_OFFSET);
    //     lv_obj_set_style_text_font(labels[i], &ui_font_GaretHeavy18, LV_PART_MAIN);
    // }
    // render_rgb (ui_Screen1);

//for conversion and laying out properly
// #ifdef UI_RENDER_WPM
//     ui_Screen1_Label_WPM = lv_label_create(ui_Screen1);
//     lv_obj_set_width(ui_Screen1_Label_WPM, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Screen1_Label_WPM, LV_SIZE_CONTENT);    /// 1
//         lv_obj_set_x(ui_Screen1_Label_WPM, 9);
//         lv_obj_set_y(ui_Screen1_Label_WPM,20);
//         lv_obj_set_style_text_font(ui_Screen1_Label_WPM, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_label_set_text(ui_Screen1_Label_WPM, "WPM");
// #endifSSS
#ifdef OS_DETECTION_ENABLE
    ui_Screen1_Label_OS = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label_OS, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_OS, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label_OS, 9);
    lv_obj_set_y(ui_Screen1_Label_OS, 174);
    set_OS_text_value(ui_Screen1_Label_OS);
    lv_obj_set_style_text_font(ui_Screen1_Label_OS, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
#endif

// #ifdef CUSTOM_KEYLOGGER
//     ui_Screen1_Label_KL = lv_label_create(ui_Screen1);
//     lv_obj_set_width(ui_Screen1_Label_KL, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Screen1_Label_KL, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_Screen1_Label_KL, 9);
//     lv_obj_set_y(ui_Screen1_Label_KL, 200);
//     lv_obj_set_style_text_font(ui_Screen1_Label_KL, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
//     timer = lv_timer_create(ui_render_keylogger, 1000, ui_Screen1_Label_KL);
// #endif

    lv_obj_add_event_cb(ui_Screen1, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);

}

void ui_Screen2_screen_init(void)
{

#ifdef CUSTOM_KEYLOGGER
    if (timer != NULL) {
        lv_timer_del(timer);

        timer = NULL;
    }
#endif
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0xE30303), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_grad_color(ui_Screen2, lv_color_hex(0x2862DD), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_main_stop(ui_Screen2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_grad_stop(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_grad_dir(ui_Screen2, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    render_panel_layer(ui_Screen2, LV_ALIGN_CENTER, 0, 30, (TFT_WIDTH - 60), 100, LV_SIZE_CONTENT, LV_SIZE_CONTENT, &style_label_futura22, &style_label_futura18, ui_active_layer_change, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
    // render_panel_pointing (ui_Screen2, LV_ALIGN_CENTER, 0, -90, (TFT_WIDTH - 60), 100, &style_label_futura18, &style_label_futura18, ui_pm_state_change, USER_EVENT_PM_STATE_CHANGE, NULL);
    render_cpi_arc(ui_Screen2);
    render_pointing(ui_Screen2, 0, -59);
    render_panel_deflayer (ui_Screen2, LV_ALIGN_CENTER, 0, 100, &ui_font_GaretHeavy14, ui_event_dflayer_dropdown, LV_EVENT_ALL, NULL);


    // ui_PM_led1 = lv_led_create(ui_Screen2);
    // lv_obj_set_size(ui_PM_led1, 10, 10);
    // lv_obj_align(ui_PM_led1, LV_ALIGN_CENTER, 100, 0);
    // lv_led_set_brightness(ui_PM_led1, 255);
    // lv_led_set_color(ui_PM_led1, lv_palette_main(LV_PALETTE_RED));

    // ui_PM_led2  = lv_led_create(ui_Screen2);
    // lv_obj_set_size(ui_PM_led2, 10, 10);
    // lv_obj_align(ui_PM_led2, LV_ALIGN_CENTER, 120, 0);
    // lv_led_set_brightness(ui_PM_led2, 255);
    // lv_led_set_color(ui_PM_led2, lv_palette_main(LV_PALETTE_RED));

    //     lv_obj_add_event_cb(ui_PM_led1, ui_pm_state_change, USER_EVENT_PM_SIDE_CHANGE, NULL);
    // lv_obj_add_event_cb(ui_PM_led2, ui_pm_state_change, USER_EVENT_PM_SIDE_CHANGE, NULL);


 #ifdef CUSTOM_KEYLOGGER
    ui_Screen1_Label_KL = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Screen1_Label_KL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_KL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label_KL, LV_ALIGN_CENTER);
    lv_obj_set_x(ui_Screen1_Label_KL, -100);
    lv_obj_set_y(ui_Screen1_Label_KL, 0);
    lv_obj_set_style_text_font(ui_Screen1_Label_KL, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(ui_Screen1_Label_KL, "new");
    timer = lv_timer_create(ui_render_keylogger, 125, ui_Screen1_Label_KL);
#endif

    // lv_obj_add_event_cb(ui_Screen2, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    // lv_obj_add_event_cb(ui_Arc1, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);
}

void lvgl_event_triggers(void) {
    static uint32_t last_dl_state   = 0;
    if (last_dl_state != default_layer_state) {
        last_dl_state   = default_layer_state;
        lv_event_send(ui_Screen2_deflayer, USER_EVENT_DF_LAYER_CHANGE, NULL);
    }
    static uint16_t last_cpi   = 0xFFFF;
    uint16_t curr_cpi   = pointing_device_get_cpi();
    if (last_cpi != curr_cpi) {
        last_cpi   = curr_cpi;
        lv_event_send(ui_Label_Dpi, USER_EVENT_CPI_UPDATE, NULL);
        lv_event_send(ui_Arc1, USER_EVENT_CPI_UPDATE, NULL);
    }
#ifdef WPM_ENABLE
    static uint32_t last_wpm_update = 0;
    if (timer_elapsed32(last_wpm_update) > 500) {
        last_wpm_update = timer_read32();
        lv_event_send(ui_wpmCount, USER_EVENT_WPM_UPDATE, NULL);
    }
#endif
    static uint16_t last_effect       = 0xFFFF;
    uint8_t         curr_effect       = rgb_matrix_config.mode;
    if (last_effect != curr_effect) {
        last_effect       = curr_effect;
       lv_event_send(ui_RGBLabel, USER_EVENT_RGBMODE_UPDATE, NULL);
    }
    static uint16_t last_hue       = 0xFFFF;
    uint16_t         curr_hue       = rgb_matrix_get_hue();
    if (last_hue != curr_hue) {
        last_hue       = curr_hue;
        lv_event_send(ui_Screen2, USER_EVENT_RGBHUE_UPDATE, NULL);
        // lv_event_send(ui_Panel_Layer, USER_EVENT_RGBHUE_UPDATE, NULL);
        // lv_event_send(ui_Panel_Pointing_Mode, USER_EVENT_RGBHUE_UPDATE, NULL);
        lv_event_send(ui_Screen1, USER_EVENT_RGBHUE_UPDATE, NULL);
        lv_event_send(ui_HSVLabel, USER_EVENT_RGBHUE_UPDATE, NULL);
        lv_event_send(ui_Colorwheel1, USER_EVENT_RGBHUE_UPDATE, NULL);
        lv_event_send(ui_HueArc, USER_EVENT_RGBHUE_UPDATE, NULL);
    }
    static uint16_t last_sat      = 0;
    uint16_t        curr_sat      = rgb_matrix_get_sat();

    if (last_sat != curr_sat) {
        last_sat  = curr_sat;
        lv_event_send(ui_HSVLabel, USER_EVENT_RGBSAT_UPDATE, NULL);
        lv_event_send(ui_Colorwheel1, USER_EVENT_RGBSAT_UPDATE, NULL);
        lv_event_send(ui_HueArc, USER_EVENT_RGBSAT_UPDATE, NULL);
    }

    static uint16_t last_val       = 0;
    uint16_t        curr_val       = rgb_matrix_get_val();
    if (last_val != curr_val) {
        last_val  = curr_val;
        lv_event_send(ui_HSVLabel, USER_EVENT_RGBVAL_UPDATE, NULL);
        lv_event_send(ui_Colorwheel1, USER_EVENT_RGBVAL_UPDATE, NULL);
        lv_event_send(ui_HueArc, USER_EVENT_RGBVAL_UPDATE, NULL);
    }

    static uint32_t last_layer_state   = 0;
    if (last_layer_state != layer_state) {
        last_layer_state   = layer_state;
        lv_event_send(ui_Layer_Indicator, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
        lv_event_send(ui_Label_Layer_Name, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
    }

    static uint8_t last_pm_state   = 0;
    if (last_pm_state != user_state.split_pointing_mode) {
        last_pm_state  = user_state.split_pointing_mode;
        lv_event_send(ui_Label_PM_mode, USER_EVENT_PM_STATE_CHANGE, NULL);
    }
    // bool pm_side_redraw = false;
    // bool            last_pm_side   = 1;
    // if (last_pm_side != user_state.pointing_side) {
    //     last_pm_side  = user_state.pointing_side;
    //     pm_side_redraw = true;
    // }
    // if (pm_state_redraw) {

    //     // lv_event_send(ui_Panel_Pointing_Mode, USER_EVENT_PM_STATE_CHANGE, NULL);
    //     // lv_event_send(ui_Panel_Pointing_Mode, USER_EVENT_PM_STATE_CHANGE, NULL);
    // }

    // if (pm_side_redraw) {
    //     // lv_event_send(ui_PM_led1, USER_EVENT_PM_SIDE_CHANGE, NULL);
    //     // lv_event_send(ui_PM_led2, USER_EVENT_PM_SIDE_CHANGE, NULL);
    // }

    bool            last_am_state   = 0;
    if (last_am_state != get_auto_mouse_toggle()) {
        last_am_state  = get_auto_mouse_toggle();
        lv_event_send(ui_PM_led3, USER_EVENT_AM_STATE_CHANGE, NULL);
    }

    if MODS_ALT {
        _ui_state_modify(ui_Label3, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Label3, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_CTRL {
        _ui_state_modify(ui_Label2, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Label2, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_GUI {
        _ui_state_modify(ui_Label4, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Label4, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_SHIFT {
        _ui_state_modify(ui_Label1, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Label1, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if (autocorrect_is_enabled()) {
        _ui_state_modify(ui_Autocorrect, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Autocorrect, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    }

    static led_t last_led_state = {0};
    if (last_led_state.raw != host_keyboard_led_state().raw) {
        last_led_state.raw = host_keyboard_led_state().raw;
        if (host_keyboard_led_state().caps_lock) {
            _ui_state_modify(ui_CapsLock, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_CapsLock, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if (host_keyboard_led_state().num_lock) {
            _ui_state_modify(ui_NumLock, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_NumLock, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if (host_keyboard_led_state().scroll_lock) {
            _ui_state_modify(ui_ScrollLock, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_ScrollLock, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
    }

    static user_runtime_config_t last_user_state = {0};
    if (last_user_state.raw != user_state.raw) {
        last_user_state.raw  = user_state.raw;
        if (user_state.audio_enable) {
            _ui_state_modify(ui_Clicky, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Clicky, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if (user_state.audio_clicky_enable) {
            _ui_state_modify(ui_Audio, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Audio, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }

    }

    static uint8_t last_unicode_mode = {0};
    if (last_unicode_mode != user_state.unicode_typing_mode) {
        last_unicode_mode  = user_state.unicode_typing_mode;
        lv_event_send(ui_Label_Unicode_Mode, USER_EVENT_UNICODE_MODE_UPDATE, NULL);
    // if (get_auto_mouse_toggle()) {
    //         lv_led_on(ui_PM_led3);
    //     } else {
    //         lv_led_off(ui_PM_led3);
    }

}


void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    if (is_keyboard_left()) {
        lv_disp_load_scr(ui_Screen2);
    }
    // lv_disp_load_scr(ui_Screen1);
    if (!is_keyboard_left()) {
        lv_disp_load_scr(ui_Screen1);
    }
}
