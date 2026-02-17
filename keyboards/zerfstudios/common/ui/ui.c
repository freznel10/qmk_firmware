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
#include "../douballz/douballz.h"
#include "quantum.h"
#ifdef OS_DETECTION_ENABLE
#include "os_detection.h"
#endif

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
lv_obj_t * ui_Image1;
lv_obj_t * ui_Panel_KB_Status;
lv_obj_t * ui_Label_CAPS;
lv_obj_t * ui_Label_SCLK;
lv_obj_t * ui_Label_NMLK;
lv_obj_t * ui_Panel_HSV;
lv_obj_t * ui_Label_AUDIO;
lv_obj_t * ui_Label_CLICKY;
lv_obj_t * ui_Label_ACRT;
lv_obj_t * ui_Label_H;
lv_obj_t * ui_Label_S;
lv_obj_t * ui_Label_V;
lv_obj_t * ui_Label_CPI;
lv_obj_t * ui_Label_RGB;
#ifdef UI_RENDER_WPM
lv_obj_t * ui_Label_WPM;
#endif
lv_obj_t * ui_Screen1_OS;
lv_obj_t * ui_Label_CTRL;
lv_obj_t * ui_Label_ALT;
lv_obj_t * ui_Label_GUI;
lv_obj_t * ui_Label_SHIFT;
lv_obj_t * ui_Panel_Mods;
#ifdef CUSTOM_KEYLOGGER
lv_obj_t * ui_Label_Keylog;
#endif
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Dropdown_Deflayer;
lv_obj_t * ui_Dropdown_Deflayer_list;
lv_obj_t * ui_Layer_Indicator;
lv_obj_t * ui_Label_PM_mode;
lv_obj_t * ui_Label_PM_side;
lv_obj_t * ui_Panel_Layer;
lv_obj_t * ui_Label_Layer_Name;
lv_obj_t * ui_Panel_Pointing_Mode;
lv_obj_t * ui_Label_Pointing_Mode;
lv_obj_t * ui_PM_led1;
lv_obj_t * ui_PM_led2;
lv_obj_t * ui_PM_led3;
lv_obj_t * ui_Label_Unicode_Mode;
lv_obj_t * monitormund_test;



// lv_obj_t * ui_Main1;
// lv_obj_t * ui_Image1;
// lv_obj_t * ui_Arc1;
// lv_obj_t * ui_Panel1;
// lv_obj_t * ui_Layer1;
// lv_obj_t * ui_Panel2;
lv_obj_t * ui_Label1;
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

lv_timer_t* timer;


#define LV_STYLE_INIT(var_name, prop_array) lv_style_t var_name = { .v_p = { .const_props = prop_array }, .has_group = 0xFF, .is_const = 1 }
#define C_LV_STYLE_PROP_INV { .prop = LV_STYLE_PROP_INV, .value = {0} }




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
uint32_t USER_EVENT_DF_LAYER_CHANGE = 0;
uint32_t USER_EVENT_CPI_UPDATE = 1;
uint32_t USER_EVENT_WPM_UPDATE = 2;
uint32_t USER_EVENT_ACTIVE_LAYER_CHANGE = 3;
uint32_t USER_EVENT_PANEL_CHANGE = 4;
uint32_t USER_EVENT_RGBMODE_UPDATE = 5;
uint32_t USER_EVENT_CAPS_WORD_UPDATE = 6;
uint32_t USER_EVENT_PM_STATE_CHANGE = 7;
uint32_t USER_EVENT_PM_SIDE_CHANGE = 8;
uint32_t USER_EVENT_AM_STATE_CHANGE = 9;
uint32_t USER_EVENT_RGBHUE_UPDATE = 10;
uint32_t USER_EVENT_RGBSAT_UPDATE = 11;
uint32_t USER_EVENT_RGBVAL_UPDATE = 12;
uint32_t USER_EVENT_KEYLOG_UPDATE = 13;
uint32_t USER_EVENT_UNICODE_MODE_UPDATE = 14;



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
bool apply_autocorrect(uint8_t backspaces, const char *str) {
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
#ifdef UI_RENDER_WPM
/*WPM RENDER*/
void set_wpm_text_value(lv_obj_t* lbl) {
    if (lv_obj_is_valid(lbl)) {
        char buf[9];
        snprintf(buf, sizeof(buf), "WPM: %d", (int)ui_lv_get_bpm());
        lv_label_set_text(lbl, buf);
    }
}
void ui_render_wpm(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_WPM_UPDATE) {
        set_wpm_text_value(ui_Label_WPM);
    }
}
#endif

/*HUE REDRAW*/
void ui_render_rgbhue_redraw(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target(e);
    static lv_color_t trial;
    static lv_color_t trial_2;
    static lv_color_t trial_3;
    static lv_color_t trial_4;
    static lv_color_t trial_5;
    static lv_color_t trial_6;
    static lv_color_t trial_7;
    static lv_color_t trial_8;
    static uint16_t trial_hue;
    trial_hue = ((rgb_matrix_get_hue() * 360) >> 8);
    trial = lv_color_hsv_to_rgb(trial_hue, 100, 100);
    trial_2 = lv_color_hsv_to_rgb((trial_hue + 8), 100, 100);
    trial_3 = lv_color_hsv_to_rgb((trial_hue + 14), 100, 100);
    trial_4 = lv_color_hsv_to_rgb((trial_hue + 34), 100, 100);
    trial_5 = lv_color_hsv_to_rgb((trial_hue + 44), 100, 100);
    trial_6 = lv_color_hsv_to_rgb((trial_hue + 54), 100, 100);
    trial_7 = lv_color_hsv_to_rgb((trial_hue + 64), 100, 100);
    trial_8 = lv_color_hsv_to_rgb((trial_hue + 84), 100, 100);
    if(event_code == USER_EVENT_RGBHUE_UPDATE) {
        if(target == ui_Screen2) {
            lv_obj_set_style_outline_color(ui_Panel_Layer, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(ui_Panel_Pointing_Mode, trial_2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(ui_Dropdown_Deflayer, trial_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        if(target == ui_Screen1) {
            lv_obj_set_style_outline_color(ui_Panel_Mods, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(ui_Panel_KB_Status, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(ui_Panel_HSV, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_Label_ALT, trial_6, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label_CTRL, trial_2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label_GUI, trial_3, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label_SHIFT, trial_4, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label_CAPS, trial_7, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label_NMLK, trial_8, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label_SCLK, trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label_AUDIO, trial_4, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label_CLICKY, trial_5, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Label_ACRT, trial_6, LV_PART_MAIN | LV_STATE_FOCUSED);
        }
        if(target == ui_Label_H) {
            char buf[6];
            snprintf(buf, sizeof(buf), "H:%d", rgb_matrix_get_hue());
            lv_label_set_text(ui_Label_H, buf);
        }
    }
}

void ui_render_rgbval_redraw(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target(e);
    if(event_code == USER_EVENT_RGBVAL_UPDATE) {
        if(target == ui_Label_V) {
            char buf[6];
            snprintf(buf, sizeof(buf), "V:%d", rgb_matrix_get_val());
            lv_label_set_text(ui_Label_V, buf);
        }
    }
}

void ui_render_rgbsat_redraw(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target(e);
    if(event_code == USER_EVENT_RGBSAT_UPDATE) {
        if(target == ui_Label_S) {
            char buf[6];
            snprintf(buf, sizeof(buf), "S:%d", rgb_matrix_get_sat());
            lv_label_set_text(ui_Label_S, buf);
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
            case 8:
                unicode_mode_display = "COMIC";
                break;
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
        char buf[32];
        const char *pm_name = "-----";
        switch (user_state.split_pointing_mode) {
            case PM_PRECISION:
                pm_name = "PRECISION";
                break;
            case PM_DRAG:
                pm_name = "PM_DRAG";
                break;
            case 3:
                pm_name = "CARET";
                break;
            case 4:
                pm_name = "HISTORY";
                break;
            case 5:
                pm_name = "VOLUME";
                break;
            case 6:
                pm_name = "BROWSER";
                break;
            case 7:
                pm_name = "RGB_VAL";
                break;
            case 8:
                pm_name = "RGB_SAT";
                break;
            case 9:
                pm_name = "RGB_SPEED";
                break;
            case 10:
                pm_name = "WINDOW";
                break;
            case 11:
                pm_name = "WINDOW";
                break;
            case 12:
                pm_name = "ALT_TAB";
                break;
            case 13:
                pm_name = "ACCELL";
            case 14:
                pm_name = "BACK_FWD";
                break;
            case 15:
                pm_name = "WIN_POS";
                break;
            case 16:
                pm_name = "ACCELL";
                break;
            default:
                pm_name = " ";
                break;
        }
        snprintf(buf, sizeof(buf), "%s", pm_name);
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
    if(event_code == USER_EVENT_PM_SIDE_CHANGE) {
        if ((target == ui_PM_led1 || ui_PM_led2) && (user_state.pointing_side)) {
                lv_led_on(ui_PM_led1);
                lv_led_off(ui_PM_led2);
        } else {
                lv_led_off(ui_PM_led1);
                lv_led_on(ui_PM_led2);
        }
    }
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
        char buf[11];
        snprintf(buf, sizeof(buf), "CPI: %d", (int)ui_lv_get_cpi());
        lv_label_set_text(lbl, buf);
    }
}

void ui_render_cpi(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_CPI_UPDATE) {
         set_cpi_text_value(ui_Label_CPI);
        //  lv_arc_set_value(ui_Arc3, ui_lv_get_cpi());
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
        snprintf(buf, sizeof(buf), "M: %s", rgb_matrix_name(curr_effect));
            for (int i = 3; i < sizeof(buf); ++i) {
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
         set_rgbmode_text_value(ui_Label_RGB);
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
                lv_img_set_src(ui_Layer_Indicator, &ui_img_bk80_png);
                // &ui_img_emblem_80_png
                lv_label_set_text(ui_Label_Layer_Name, "LAYER");
                break;
            case 1:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
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
            case _MOUSE:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_trackball_png);
                lv_label_set_text(ui_Label_Layer_Name, "MOUSE");
                break;
            case _LOWER:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_lower_80_png);
                lv_label_set_text(ui_Label_Layer_Name, "LOWER");
                 break;
            case _RAISE:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_raise_80_png);
                lv_label_set_text(ui_Label_Layer_Name, "RAISE");
                break;
            case _ADJUST:
                // lv_img_set_src(ui_Layer_Indicator, &ui_img_toolbox_80_png);
                lv_label_set_text(ui_Label_Layer_Name, "ADJUST");
                break;
            case _KEYPAD:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_numpad_80_png);
                lv_label_set_text(ui_Label_Layer_Name, "KEYPAD");
                break;
            case _MEDIA:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
                lv_label_set_text(ui_Label_Layer_Name, "MEDIA");
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


#define KEYLOGGER_LENGTH 5
uint32_t        display_timer                     = 0;
char            keylog_str[KEYLOGGER_LENGTH] = {0};
static uint16_t log_timer                         = 0;


void add_keylog(uint16_t keycode, keyrecord_t *record) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        if (((keycode & 0xFF) == KC_BSPC) && mod_config(get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL) {
            memset(keylog_str, ' ', KEYLOGGER_LENGTH);
            return;
        }
        if (record->tap.count) {
            keycode &= 0xFF;
        } else if (keycode > 0xFF) {
            return;
        }
    }
    if (keycode > 0xFF) {
        return;
    }

    memmove(keylog_str, keylog_str + 1, KEYLOGGER_LENGTH - 1);

    if (keycode < (sizeof(code_to_name) / sizeof(char))) {
        keylog_str[(KEYLOGGER_LENGTH - 1)] = pgm_read_byte(&code_to_name[keycode]);
    }

    log_timer = timer_read();
}


// void set_keylogger(const char keylogger, lv_obj_t* ui_Label_Keylog) {
//     if (lv_obj_is_valid(ui_Label1)) {
//         char buf[5];
//         snprintf(buf, sizeof(buf), "%s", keylog_str);
//         lv_label_set_text(ui_Label_Keylog, buf);
//     }
// }


static void ui_render_keylogger(lv_timer_t* timer) {
    LV_UNUSED(timer);
    lv_obj_t* ui_Label_Keylog = timer->user_data;;
    if(lv_obj_is_valid(ui_Label_Keylog)) {
        char buf[5];
        snprintf(buf, sizeof(buf), "%s", keylog_str);
        lv_label_set_text(ui_Label_Keylog, buf);
    }
}
#endif

//PANELS

void render_panel_pointing (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font, lv_style_t * style_font_2,
                            lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {

    ui_Panel_Pointing_Mode = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel_Pointing_Mode, w);
    lv_obj_set_height(ui_Panel_Pointing_Mode, h);
    lv_obj_set_x(ui_Panel_Pointing_Mode, x);
    lv_obj_set_y(ui_Panel_Pointing_Mode, y);
    lv_obj_set_align(ui_Panel_Pointing_Mode, align);
    lv_obj_clear_flag(ui_Panel_Pointing_Mode, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // gif_load(ui_Screen2);

    lv_obj_set_style_outline_opa(ui_Panel_Pointing_Mode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Panel_Pointing_Mode, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Panel_Pointing_Mode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PM_led1 = lv_led_create(ui_Panel_Pointing_Mode);
    lv_obj_set_size(ui_PM_led1, 10, 10);
    lv_obj_align(ui_PM_led1, LV_ALIGN_CENTER, (((w/2)-10) * (-1)), (((h/2)-15) * (-1)));
    lv_led_set_brightness(ui_PM_led1, 255);
    lv_led_set_color(ui_PM_led1, lv_palette_main(LV_PALETTE_RED));

    ui_PM_led2  = lv_led_create(ui_Panel_Pointing_Mode);
    lv_obj_set_size(ui_PM_led2, 10, 10);
    lv_obj_align(ui_PM_led2, LV_ALIGN_CENTER, (((w/2)-30) * (-1)), (((h/2)-15) * (-1)));
    lv_led_set_brightness(ui_PM_led2, 255);
    lv_led_set_color(ui_PM_led2, lv_palette_main(LV_PALETTE_RED));

    ui_PM_led3  = lv_led_create(ui_Panel_Pointing_Mode);
    lv_obj_set_size(ui_PM_led3, 10, 10);
    lv_obj_align(ui_PM_led3, LV_ALIGN_CENTER, (((w/2)-40), ((h/2)-15) * (-1)));
    lv_led_set_brightness(ui_PM_led3, 255);
    lv_led_set_color(ui_PM_led3, lv_palette_main(LV_PALETTE_GREEN));

    ui_Label_PM_mode = lv_label_create(ui_Panel_Pointing_Mode);
    lv_obj_set_x(ui_Label_PM_mode, 0);
    lv_obj_set_y(ui_Label_PM_mode, -5);
    lv_obj_add_style(ui_Label_PM_mode, style_font, 0);
    lv_label_set_text(ui_Label_PM_mode, " ");

    ui_Label_Pointing_Mode = lv_label_create(ui_Panel_Pointing_Mode);
    lv_obj_set_x(ui_Label_Pointing_Mode, 0);
    lv_obj_set_y(ui_Label_Pointing_Mode, 15);
    lv_obj_add_style(ui_Label_Pointing_Mode, style_font_2, 0);
    lv_label_set_text(ui_Label_Pointing_Mode, "POINTING MODE");

    ui_Label_CPI = lv_label_create(ui_Panel_Pointing_Mode);
    lv_obj_set_x(ui_Label_CPI, 0);
    lv_obj_set_y(ui_Label_CPI, 35);
    lv_obj_add_style(ui_Label_CPI, style_font, 0);

    lv_obj_add_event_cb(ui_Label_PM_mode, event_cb, filter, user_data);
    lv_obj_add_event_cb(ui_PM_led1, ui_pm_state_change, USER_EVENT_PM_SIDE_CHANGE, NULL);
    lv_obj_add_event_cb(ui_PM_led2, ui_pm_state_change, USER_EVENT_PM_SIDE_CHANGE, NULL);
    lv_obj_add_event_cb(ui_PM_led3, ui_am_state_change, USER_EVENT_AM_STATE_CHANGE, NULL); //not working ATM
    lv_obj_add_event_cb(ui_Label_CPI, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);
}

void render_panel_deflayer (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, const lv_font_t * deflayer_font,
                            lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {

    ui_Dropdown_Deflayer = lv_dropdown_create(scr);
    static const char * opts = "COLEMAK_DH\n"
                               "COLEMAK\n"
                               "QWERTY\n"
                               "DVORAK";
    lv_dropdown_set_options_static(ui_Dropdown_Deflayer, opts);
    ui_Dropdown_Deflayer_list =  lv_dropdown_get_list(ui_Dropdown_Deflayer) ;
    lv_obj_set_style_text_font(ui_Dropdown_Deflayer_list , &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(ui_Dropdown_Deflayer, 140);
    lv_obj_set_height(ui_Dropdown_Deflayer, 40);
    lv_obj_set_x(ui_Dropdown_Deflayer, x);
    lv_obj_set_y(ui_Dropdown_Deflayer, y);
    lv_obj_set_align(ui_Dropdown_Deflayer, align);
    lv_obj_set_style_text_align(ui_Dropdown_Deflayer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Dropdown_Deflayer, deflayer_font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Dropdown_Deflayer, LV_TEXT_ALIGN_CENTER, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Dropdown_Deflayer, deflayer_font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Dropdown_Deflayer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Dropdown_Deflayer, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Dropdown_Deflayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Dropdown_Deflayer, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN | LV_STATE_DEFAULT | LV_STATE_CHECKED | LV_STATE_FOCUSED );
    lv_obj_add_event_cb(ui_Dropdown_Deflayer, event_cb, filter, user_data);
}

void render_rgb_mode_status (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font,
                            lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {
    ui_Label_RGB = lv_label_create(scr);
    lv_obj_set_align(ui_Label_RGB, align);
    lv_obj_set_x(ui_Label_RGB, x);
    lv_obj_set_y(ui_Label_RGB, y);
    lv_obj_add_style(ui_Label_RGB, style_font, 0);
    lv_label_set_text(ui_Label_RGB, "RGB");
    lv_obj_add_event_cb(ui_Label_RGB, event_cb, filter, user_data);
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
    lv_obj_set_style_outline_opa(ui_Panel_Layer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Panel_Layer, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Panel_Layer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel_Layer, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel_Layer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel_Layer, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel_Layer, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

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

void render_panel_kb_status (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font,
                            lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {
    // static lv_style_t style_test;
    // lv_style_init(&style_test);
    // lv_style_set_layout(&style_test, LV_LAYOUT_FLEX);
    // lv_style_set_flex_flow(&style_test, LV_FLEX_FLOW_ROW_WRAP);
    // lv_style_set_flex_main_place(&style_test, LV_FLEX_ALIGN_CENTER);
    // lv_style_set_flex_cross_place(&style_test, LV_FLEX_ALIGN_START );
    // lv_style_set_flex_track_place(&style_test, LV_FLEX_ALIGN_SPACE_EVENLY);

    static lv_style_t style_test;
    static lv_coord_t column_dsc[] = {42, 42, 42, LV_GRID_TEMPLATE_LAST};   /*2 columns with 100 and 400 ps width*/
    static lv_coord_t row_dsc[] = {30, 30, LV_GRID_TEMPLATE_LAST}; /*3 100 px tall rows*/
    lv_style_init(&style_test);
    lv_style_set_layout(&style_test, LV_LAYOUT_GRID);
    lv_style_set_grid_row_dsc_array(&style_test, row_dsc);
    lv_style_set_grid_column_dsc_array(&style_test, column_dsc);
    lv_style_set_pad_all(&style_test, 0);


    ui_Panel_KB_Status = lv_obj_create(scr);
    lv_obj_add_style(ui_Panel_KB_Status, &style_test, 0);
    lv_obj_set_x(ui_Panel_KB_Status, x);
    lv_obj_set_y(ui_Panel_KB_Status, y);
    lv_obj_set_content_width(ui_Panel_KB_Status, w);
    lv_obj_set_content_height(ui_Panel_KB_Status, h);
    lv_obj_set_width(ui_Panel_KB_Status, w);
    lv_obj_set_height(ui_Panel_KB_Status, h);
    lv_obj_set_align(ui_Panel_KB_Status, align);
    lv_obj_add_flag(ui_Panel_KB_Status, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui_Panel_KB_Status, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_add_flag(ui_Panel_KB_Status, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_clear_flag(ui_Panel_KB_Status, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_style(ui_Panel_KB_Status, style_font, 0);
    lv_obj_set_style_outline_opa(ui_Panel_KB_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Panel_KB_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Panel_KB_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel_KB_Status, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel_KB_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel_KB_Status, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel_KB_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // uint32_t i;
    // for(i = 0; i < 6; i++) {
    //     uint8_t grid_col = i % 3;
    //     uint8_t grid_row = i / 2;
        ui_Label_CAPS = lv_label_create(ui_Panel_KB_Status);
        lv_label_set_text(ui_Label_CAPS, "CAPS");
        lv_obj_set_grid_cell(ui_Label_CAPS, LV_GRID_ALIGN_CENTER  , 0, 1, LV_GRID_ALIGN_CENTER   , 0, 1);

        ui_Label_SCLK = lv_label_create(ui_Panel_KB_Status);
        lv_label_set_text(ui_Label_SCLK, "SCLK");
        lv_obj_set_grid_cell(ui_Label_SCLK, LV_GRID_ALIGN_CENTER  , 1, 1, LV_GRID_ALIGN_CENTER  , 0, 1);

        ui_Label_NMLK = lv_label_create(ui_Panel_KB_Status);
        lv_label_set_text(ui_Label_NMLK, "NMLK");
        lv_obj_set_grid_cell(ui_Label_NMLK, LV_GRID_ALIGN_CENTER  , 2, 1, LV_GRID_ALIGN_CENTER  , 0, 1);

        ui_Label_AUDIO = lv_label_create(ui_Panel_KB_Status);
        lv_label_set_text(ui_Label_AUDIO, "AUD");
        lv_obj_set_grid_cell(ui_Label_AUDIO, LV_GRID_ALIGN_CENTER , 0, 1, LV_GRID_ALIGN_CENTER , 1, 1);

        ui_Label_CLICKY = lv_label_create(ui_Panel_KB_Status);
        lv_label_set_text(ui_Label_CLICKY, "CLKY");
        lv_obj_set_grid_cell(ui_Label_CLICKY, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER , 1, 1);

        ui_Label_ACRT = lv_label_create(ui_Panel_KB_Status);
        lv_label_set_text(ui_Label_ACRT, "ACRT");
        lv_obj_set_grid_cell(ui_Label_ACRT, LV_GRID_ALIGN_CENTER , 2, 1, LV_GRID_ALIGN_CENTER , 1, 1);
    // }

    lv_obj_add_event_cb(ui_Panel_KB_Status, event_cb, filter, user_data);
}

void render_panel_HSV (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font,
                            lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {
    static lv_style_t hsv_style;
    lv_style_init(&hsv_style);
    lv_style_set_layout(&hsv_style, LV_LAYOUT_FLEX );
    lv_style_set_flex_flow(&hsv_style, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_pad_left(&hsv_style, 0);
    lv_style_set_pad_right(&hsv_style, 0);
    lv_style_set_pad_top(&hsv_style, 0);
    lv_style_set_pad_bottom(&hsv_style, 0);
    lv_style_set_pad_row(&hsv_style, 1);
    lv_style_set_pad_column(&hsv_style, 5);
    lv_style_set_flex_flow(&hsv_style, LV_FLEX_FLOW_ROW);
    lv_style_set_flex_main_place(&hsv_style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_cross_place(&hsv_style, LV_FLEX_ALIGN_START );
    lv_style_set_flex_track_place(&hsv_style, LV_FLEX_ALIGN_SPACE_BETWEEN);


    ui_Panel_HSV = lv_obj_create(scr);
    lv_obj_add_style (ui_Panel_HSV, &hsv_style, 0);
    lv_obj_set_width(ui_Panel_HSV, w);
    lv_obj_set_height(ui_Panel_HSV, h);
    lv_obj_set_x(ui_Panel_HSV, x);
    lv_obj_set_y(ui_Panel_HSV, y);
    lv_obj_set_align(ui_Panel_HSV, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel_HSV, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_style(ui_Panel_HSV, style_font, 0);
    lv_obj_set_style_outline_opa(ui_Panel_HSV, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Panel_HSV, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Panel_HSV, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel_HSV, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel_HSV, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel_HSV, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel_HSV, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    render_rgb_mode_status(ui_Panel_HSV, LV_ALIGN_TOP_LEFT, 5, -15, LV_SIZE_CONTENT, LV_SIZE_CONTENT, &style_label_futura18, ui_render_rgbmode, USER_EVENT_RGBMODE_UPDATE, NULL);

    ui_Label_H = lv_label_create(ui_Panel_HSV);
    lv_obj_add_flag(ui_Label_H, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
    lv_label_set_text(ui_Label_H, "H");

    ui_Label_S = lv_label_create(ui_Panel_HSV);
    lv_label_set_text(ui_Label_S, "S");

    ui_Label_V = lv_label_create(ui_Panel_HSV);
    lv_label_set_text(ui_Label_V, "V");


    lv_obj_add_event_cb(ui_Panel_HSV, event_cb, filter, user_data);
    lv_obj_add_event_cb(ui_Label_H, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Label_S, ui_render_rgbsat_redraw, USER_EVENT_RGBSAT_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Label_V, ui_render_rgbval_redraw, USER_EVENT_RGBVAL_UPDATE, NULL);
}

void render_panel_mods (lv_obj_t *scr, lv_align_t align, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, lv_style_t * style_font,
                            lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data) {


    static lv_style_t style_test_2;
    lv_style_init(&style_test_2);
    lv_style_set_pad_all(&style_test_2, 0);
    lv_style_set_layout(&style_test_2,LV_LAYOUT_FLEX );
    lv_style_set_pad_left(&style_test_2, 0);
    lv_style_set_pad_right(&style_test_2, 0);
    lv_style_set_pad_top(&style_test_2, 0);
    lv_style_set_pad_bottom(&style_test_2, 0);
    lv_style_set_pad_row(&style_test_2, 1);
    lv_style_set_pad_column(&style_test_2, 5);
    lv_style_set_flex_flow(&style_test_2, LV_FLEX_FLOW_ROW);
    lv_style_set_flex_main_place(&style_test_2, LV_FLEX_ALIGN_SPACE_AROUND);
    lv_style_set_flex_cross_place(&style_test_2, LV_FLEX_ALIGN_CENTER );
    lv_style_set_flex_track_place(&style_test_2, LV_FLEX_ALIGN_CENTER);

    ui_Panel_Mods = lv_obj_create(scr);
    lv_obj_set_width(ui_Panel_Mods, w);
    lv_obj_set_height(ui_Panel_Mods, h);
    lv_obj_set_x(ui_Panel_Mods, x);
    lv_obj_set_y(ui_Panel_Mods, y);
    lv_obj_set_align(ui_Panel_Mods, align);
    lv_obj_clear_flag(ui_Panel_Mods, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_style(ui_Panel_Mods, style_font, 0);
    lv_obj_add_style(ui_Panel_Mods, &style_test_2, 0);

    lv_obj_set_style_outline_opa(ui_Panel_Mods, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Panel_Mods, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Panel_Mods, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel_Mods, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel_Mods, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel_Mods, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel_Mods, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_GUI = lv_label_create(ui_Panel_Mods);
    lv_label_set_text(ui_Label_GUI, "GUI");

    ui_Label_ALT = lv_label_create(ui_Panel_Mods);
    lv_label_set_text(ui_Label_ALT, "ALT");

    ui_Label_CTRL = lv_label_create(ui_Panel_Mods);
    lv_label_set_text(ui_Label_CTRL, "CTRL");
    lv_obj_add_flag(ui_Label_CTRL, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);

    ui_Label_SHIFT = lv_label_create(ui_Panel_Mods);
    lv_label_set_text(ui_Label_SHIFT, "SHIFT");

    lv_obj_add_event_cb(ui_Panel_Mods, event_cb, filter, user_data);
}

bool process_record_painter(uint16_t keycode, keyrecord_t *record) {
#ifdef CUSTOM_KEYLOGGER
    if (record->event.pressed) {
        add_keylog(keycode, record);
    }
    #endif
    return true;
}


///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
#ifdef CUSTOM_KEYLOGGER
    if (timer != NULL) {
        lv_timer_del(timer);
        timer = NULL;
    }
#endif

    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        render_rgb_mode_status(ui_Screen1, LV_ALIGN_TOP_LEFT, 5, 2, LV_SIZE_CONTENT, LV_SIZE_CONTENT, &style_label_futura12, ui_render_rgbmode, USER_EVENT_RGBMODE_UPDATE, NULL);
        render_panel_kb_status (ui_Screen1, LV_ALIGN_CENTER, 0, -20, (TFT_WIDTH - 10), 60, &style_label_futura12, 0, 0, 0);
        render_panel_HSV (ui_Screen1, LV_ALIGN_CENTER, 0, 57, (TFT_WIDTH - 10) , 25, &style_label_futura12, 0, 0, 0);
        render_panel_mods (ui_Screen1, LV_ALIGN_CENTER, 0, 50, (TFT_WIDTH - 10), 40, &style_label_futura12, 0, 0, 0);
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        // render_rgb_mode_status(ui_Screen1, LV_ALIGN_TOP_LEFT, 5, 57, LV_SIZE_CONTENT, LV_SIZE_CONTENT, &style_label_futura18, ui_render_rgbmode, USER_EVENT_RGBMODE_UPDATE, NULL);
        render_panel_kb_status (ui_Screen1, LV_ALIGN_CENTER, 0, -55, (TFT_WIDTH - 20), 70, &style_label_futura22, 0, 0, 0);
        render_panel_HSV (ui_Screen1, LV_ALIGN_CENTER, 0, 40, (TFT_WIDTH - 20) , 50, &style_label_futura18, 0, 0, 0);
        render_panel_mods (ui_Screen1, LV_ALIGN_CENTER, 0, 118, (TFT_WIDTH - 20), 70, &style_label_futura24, 0, 0, 0);
    #endif

//for conversion and laying out properly
#ifdef UI_RENDER_WPM
    ui_Label_WPM = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label_WPM, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_WPM, LV_SIZE_CONTENT);    /// 1
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Label_WPM, 5);
        lv_obj_set_y(ui_Label_WPM, 33);
        lv_obj_set_style_text_font(ui_Screen1_Label _WPM, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Label_WPM, 9);
        lv_obj_set_y(ui_Label_WPM,20);
        lv_obj_set_style_text_font(ui_Label_WPM, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
    #endif
    lv_label_set_text(ui_Label_WPM, "WPM");
#endif
#ifdef OS_DETECTION_ENABLE
    ui_Screen1_OS = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_OS, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_OS, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_OS, 9);
    lv_obj_set_y(ui_Screen1_OS, 174);
    set_OS_text_value(ui_Screen1_OS);
    lv_obj_set_style_text_font(ui_Screen1_OS, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
#endif

#ifdef CUSTOM_KEYLOGGER
    ui_Label_Keylog = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label_Keylog, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Keylog, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Keylog, 9);
    lv_obj_set_y(ui_Label_Keylog, 200);
    lv_obj_set_style_text_font(ui_Label_Keylog, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
    timer = lv_timer_create(ui_render_keylogger, 1000, ui_Label_Keylog);
#endif

    lv_obj_add_event_cb(ui_Screen1, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
#ifdef UI_RENDER_WPM
    lv_obj_add_event_cb(ui_Label_WPM, ui_render_wpm, USER_EVENT_WPM_UPDATE, NULL);
#endif
}

void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0xE30303), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen2, lv_color_hex(0x2862DD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Screen2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Screen2, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        render_panel_layer (ui_Screen2, LV_ALIGN_CENTER, 0, 10, (TFT_WIDTH - 5), 70, LV_SIZE_CONTENT, LV_SIZE_CONTENT, &style_label_futura12, &style_label_futura12, ui_active_layer_change, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
        render_panel_pointing (ui_Screen2, LV_ALIGN_CENTER, 0, -50, (TFT_WIDTH - 20), 50, &style_label_futura12, &style_label_futura12, ui_pm_state_change, USER_EVENT_PM_STATE_CHANGE, NULL);
        render_panel_deflayer (ui_Screen2, LV_ALIGN_CENTER, 0, 130, &ui_font_Futura18, ui_event_dflayer_dropdown, LV_EVENT_ALL, NULL);
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        render_panel_layer(ui_Screen2, LV_ALIGN_CENTER, 0, 30, (TFT_WIDTH - 20), 120, LV_SIZE_CONTENT, LV_SIZE_CONTENT, &style_label_futura22, &style_label_futura18, ui_active_layer_change, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
        render_panel_pointing (ui_Screen2, LV_ALIGN_CENTER, 0, -95, (TFT_WIDTH - 20), 100, &style_label_futura22, &style_label_futura18, ui_pm_state_change, USER_EVENT_PM_STATE_CHANGE, NULL);
        render_panel_deflayer (ui_Screen2, LV_ALIGN_CENTER, 0, 130, &ui_font_Futura22, ui_event_dflayer_dropdown, LV_EVENT_ALL, NULL);
    #endif

    lv_obj_add_event_cb(ui_Screen2, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
}

void lvgl_event_triggers(void) {
    static uint32_t last_dl_state   = 0;
    bool dl_state_redraw = false;
    if (last_dl_state != default_layer_state) {
        last_dl_state   = default_layer_state;
        dl_state_redraw = true;
    }
    if (dl_state_redraw) {
        lv_event_send(ui_Dropdown_Deflayer, USER_EVENT_DF_LAYER_CHANGE, NULL);
    }
    static uint16_t last_cpi   = 0xFFFF;
    uint16_t curr_cpi   = user_state.split_pointing_mode == 2 ? charybdis_get_pointer_sniping_dpi() : charybdis_get_pointer_default_dpi();
    bool cpi_redraw = false;
    if (last_cpi != curr_cpi) {
        last_cpi   = curr_cpi;
        cpi_redraw = true;
    }
    if (cpi_redraw) {
        lv_event_send(ui_Label_CPI, USER_EVENT_CPI_UPDATE, NULL);
    }
#ifdef UI_RENDER_WPM
    bool            wpm_redraw      = false;
    static uint32_t last_wpm_update = 0;
    if (timer_elapsed32(last_wpm_update) > 500) {
        last_wpm_update = timer_read32();
        wpm_redraw      = true;
    }
    if (wpm_redraw) {
        lv_event_send(ui_Label_WPM, USER_EVENT_WPM_UPDATE, NULL);
    }
#endif
    bool            rgb_effect_redraw = false;
    static uint16_t last_effect       = 0xFFFF;
    uint8_t         curr_effect       = rgb_matrix_config.mode;
    if (last_effect != curr_effect) {
        last_effect       = curr_effect;
        rgb_effect_redraw = true;
    }
    if (rgb_effect_redraw) {
        lv_event_send(ui_Label_RGB, USER_EVENT_RGBMODE_UPDATE, NULL);
    }
    bool          hue_redraw = false;
    static uint16_t last_hue       = 0xFFFF;
    uint16_t         curr_hue       = rgb_matrix_get_hue();
    if (last_hue != curr_hue) {
        last_hue       = curr_hue;
        hue_redraw = true;
    }
    if (hue_redraw) {
        lv_event_send(ui_Screen2, USER_EVENT_RGBHUE_UPDATE, NULL);
        // lv_event_send(ui_Panel_Layer, USER_EVENT_RGBHUE_UPDATE, NULL);
        // lv_event_send(ui_Panel_Pointing_Mode, USER_EVENT_RGBHUE_UPDATE, NULL);
        lv_event_send(ui_Screen1, USER_EVENT_RGBHUE_UPDATE, NULL);
        lv_event_send(ui_Label_H, USER_EVENT_RGBHUE_UPDATE, NULL);
    }
    bool          sat_redraw = false;
    static uint16_t last_sat      = 0;
    uint16_t        curr_sat      = rgb_matrix_get_sat();
    if (last_sat != curr_sat) {
        last_sat  = curr_sat;
        sat_redraw = true;
    }
    if (sat_redraw) {
        lv_event_send(ui_Label_S, USER_EVENT_RGBSAT_UPDATE, NULL);
    }
    bool          val_redraw = false;
    static uint16_t last_val       = 0;
    uint16_t        curr_val       = rgb_matrix_get_val();
    if (last_val != curr_val) {
        last_val  = curr_val;
        val_redraw = true;
    }
    if (val_redraw) {
        lv_event_send(ui_Label_V, USER_EVENT_RGBVAL_UPDATE, NULL);
    }
    bool            layer_state_redraw = false;
    static uint32_t last_layer_state   = 0;
    if (last_layer_state != layer_state) {
        last_layer_state   = layer_state;
        layer_state_redraw = true;
    }
    if (layer_state_redraw) {
        lv_event_send(ui_Layer_Indicator, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
        lv_event_send(ui_Label_Layer_Name, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
    }
    bool            pm_state_redraw = false;
    static uint8_t last_pm_state   = 0;
    if (last_pm_state != user_state.split_pointing_mode) {
        last_pm_state  = user_state.split_pointing_mode;
        pm_state_redraw = true;
    }
    if (pm_state_redraw ) {
        lv_event_send(ui_Label_PM_mode, USER_EVENT_PM_STATE_CHANGE, NULL);
        lv_event_send(ui_Panel_Pointing_Mode, USER_EVENT_PM_STATE_CHANGE, NULL);
    }
    static bool pm_side_redraw = false;
    bool            last_pm_side   = 1;
    if (last_pm_side != user_state.pointing_side) {
        last_pm_side  = user_state.pointing_side;
        pm_side_redraw = true;
    }
    if (pm_side_redraw) {
        lv_event_send(ui_PM_led1, USER_EVENT_PM_SIDE_CHANGE, NULL);
        lv_event_send(ui_PM_led2, USER_EVENT_PM_SIDE_CHANGE, NULL);
    }
    static bool am_state_redraw = false;
    bool            last_am_state   = 0;
    if (last_am_state != get_auto_mouse_toggle()) {
        last_am_state  = get_auto_mouse_toggle();
        am_state_redraw = true;
    }
    if (am_state_redraw) {
        lv_event_send(ui_PM_led3, USER_EVENT_AM_STATE_CHANGE, NULL);
    }

    if MODS_ALT {
        _ui_state_modify(ui_Label_ALT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Label_ALT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_CTRL {
        _ui_state_modify(ui_Label_CTRL, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Label_CTRL, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_GUI {
        _ui_state_modify(ui_Label_GUI, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Label_GUI, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_SHIFT {
        _ui_state_modify(ui_Label_SHIFT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Label_SHIFT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if (autocorrect_is_enabled()) {
        _ui_state_modify(ui_Label_ACRT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Label_ACRT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    static bool led_state_redraw = false;
    static led_t last_led_state = {0};
    if (last_led_state.raw != host_keyboard_led_state().raw) {
        last_led_state.raw = host_keyboard_led_state().raw;
        led_state_redraw = true;
    }
    if (led_state_redraw) {
        if (host_keyboard_led_state().caps_lock) {
            _ui_state_modify(ui_Label_CAPS, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Label_CAPS, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if (host_keyboard_led_state().num_lock) {
            _ui_state_modify(ui_Label_NMLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Label_NMLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if (host_keyboard_led_state().scroll_lock) {
            _ui_state_modify(ui_Label_SCLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Label_SCLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
    }
    static bool user_state_redraw = false;
    static user_runtime_config_t last_user_state = {0};
    if (last_user_state.raw != user_state.raw) {
        last_user_state.raw  = user_state.raw;
        user_state_redraw = true;
    }
    if (user_state_redraw) {
        if (user_state.audio_enable) {
            _ui_state_modify(ui_Label_AUDIO, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Label_AUDIO, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if (user_state.audio_clicky_enable) {
            _ui_state_modify(ui_Label_CLICKY, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Label_CLICKY, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
    }
    static bool unicode_mode_redraw = false;
    static uint8_t last_unicode_mode = {0};
    if (last_unicode_mode != user_state.unicode_typing_mode) {
        last_unicode_mode  = user_state.unicode_typing_mode;
        unicode_mode_redraw = true;
    }
    if (unicode_mode_redraw) {
        lv_event_send(ui_Label_Unicode_Mode, USER_EVENT_UNICODE_MODE_UPDATE, NULL);
    }
    // if (get_auto_mouse_toggle()) {
    //         lv_led_on(ui_PM_led3);
    //     } else {
    //         lv_led_off(ui_PM_led3);
    // }

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
