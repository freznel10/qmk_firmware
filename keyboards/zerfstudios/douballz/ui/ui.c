// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"
#include "bindings/bindings.h"
#include "freznel.h"
#include <ctype.h>
#include "../douballz/douballz.h"
#include "quantum.h"
#include "./quantum/pointing_device/pointing_device_modes.h"
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

// ///////////////////// VARIABLES ////////////////////
// extern uint8_t scroll_mode;i
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Screen1_Image1;
lv_obj_t * ui_Screen1_Panel_KB_Status;
lv_obj_t * ui_Screen1_Label_CAPS;
lv_obj_t * ui_Screen1_Label_SCLK;
lv_obj_t * ui_Screen1_Label_NMLK;
lv_obj_t * ui_Screen1_Panel_HSV;
lv_obj_t * ui_Screen1_Label_AUDIO;
lv_obj_t * ui_Screen1_Label_CLICKY;
lv_obj_t * ui_Screen1_Label_ACRT;
lv_obj_t * ui_Screen1_Label_H;
lv_obj_t * ui_Screen1_Label_S;
lv_obj_t * ui_Screen1_Label_V;
lv_obj_t * ui_Screen2_Label_CPI;
lv_obj_t * ui_Screen1_Label_RGB;
lv_obj_t * ui_Screen1_Label_WPM;
lv_obj_t * ui_Screen1_Label_OS;
lv_obj_t * ui_Screen1_Label_CTRL;
lv_obj_t * ui_Screen1_Label_ALT;
lv_obj_t * ui_Screen1_Label_GUI;
lv_obj_t * ui_Screen1_Label_SHIFT;
lv_obj_t * ui_Screen1_Panel_Status;
#ifdef CUSTOM_KEYLOGGER
lv_obj_t * ui_Screen1_Label_KL;
#endif
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Screen2_Image2;
lv_obj_t * ui_Screen2_deflayer;
lv_obj_t * ui_Screen2_deflayer_list;
lv_obj_t * ui_Layer_Indicator;
lv_obj_t * ui_Screen2_Label_PM_mode;
lv_obj_t * ui_Screen2_Label_PM_side;
lv_obj_t * ui_Screen2_Panel_Layer;
lv_obj_t * ui_Screen2_Label_Layer;
lv_obj_t * ui_Screen2_Panel_Pointing_Mode;
lv_obj_t * ui_Screen2_Label_Pointing_Mode;
lv_obj_t * ui_Screen2_led1;
lv_obj_t * ui_Screen2_led2;

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
uint32_t USER_EVENT_RGBHUE_UPDATE = 9;
uint32_t USER_EVENT_RGBSAT_UPDATE = 10;
uint32_t USER_EVENT_RGBVAL_UPDATE = 11;
uint32_t USER_EVENT_KEYLOG_UPDATE = 12;


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
/*WPM RENDER*/
void set_wpm_text_value(lv_obj_t* lbl) {
    if (lv_obj_is_valid(lbl)) {
        char buf[9];
        snprintf(buf, sizeof(buf), "WPM: %d", (int)qmk_lv_get_bpm());
        lv_label_set_text(lbl, buf);
    }
}
void ui_render_wpm(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_WPM_UPDATE) {
        set_wpm_text_value(ui_Screen1_Label_WPM);
    }
}

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
    static uint16_t trial_hue;
    trial_hue = ((rgb_matrix_get_hue() * 360) >> 8);
    trial = lv_color_hsv_to_rgb(trial_hue, 100, 100);
    trial_2 = lv_color_hsv_to_rgb((trial_hue + 8), 100, 100);
    trial_3 = lv_color_hsv_to_rgb((trial_hue + 14), 100, 100);
    trial_4 = lv_color_hsv_to_rgb((trial_hue + 34), 100, 100);
    trial_5 = lv_color_hsv_to_rgb((trial_hue + 44), 100, 100);
    trial_6 = lv_color_hsv_to_rgb((trial_hue + 54), 100, 100);
    if(event_code == USER_EVENT_RGBHUE_UPDATE) {
        if(target == ui_Screen2_Panel_Layer) {
            lv_obj_set_style_outline_color(ui_Screen2_Panel_Layer, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        if(target == ui_Screen2_Panel_Pointing_Mode) {
            lv_obj_set_style_outline_color(ui_Screen2_Panel_Pointing_Mode, trial_2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        if(target == ui_Screen1) {
            lv_obj_set_style_outline_color(ui_Screen1_Panel_Status, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(ui_Screen1_Panel_KB_Status, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(ui_Screen1_Panel_HSV, trial_3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_Screen1_Label_ALT, trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Screen1_Label_CTRL, trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Screen1_Label_GUI, trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Screen1_Label_SHIFT, trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Screen1_Label_CAPS, trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Screen1_Label_NMLK, trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Screen1_Label_SCLK, trial, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Screen1_Label_AUDIO, trial_4, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Screen1_Label_CLICKY, trial_5, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_color(ui_Screen1_Label_ACRT, trial_6, LV_PART_MAIN | LV_STATE_FOCUSED);
        }
        if(target == ui_Screen1_Label_H) {
            char buf[6];
            snprintf(buf, sizeof(buf), "H:%d", rgb_matrix_get_hue());
            lv_label_set_text(ui_Screen1_Label_H, buf);
        }
    }
}

void ui_render_rgbval_redraw(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target(e);
    if(event_code == USER_EVENT_RGBVAL_UPDATE) {
        if(target == ui_Screen1_Label_V) {
            char buf[6];
            snprintf(buf, sizeof(buf), "V:%d", rgb_matrix_get_val());
            lv_label_set_text(ui_Screen1_Label_V, buf);
        }
    }
}

void ui_render_rgbsat_redraw(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target(e);
    if(event_code == USER_EVENT_RGBSAT_UPDATE) {
        if(target == ui_Screen1_Label_S) {
            char buf[6];
            snprintf(buf, sizeof(buf), "S:%d", rgb_matrix_get_sat());
            lv_label_set_text(ui_Screen1_Label_S, buf);
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

//user_state.split_pointing_mode)
/*PM RENDER*/
void set_pm_text_value(lv_obj_t* lbl) {
    if (lv_obj_is_valid(lbl)) {
        char buf[32];
        const char *pm_name = "-----";
        switch (user_state.split_pointing_mode) {
            case 1:
                pm_name = "DRAGSCROLL";
                break;
            case 2:
                pm_name = "PRECISION";
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
                pm_name = "BACK_FWD"; //STILL DECIDING
                break;
            case 15:
                pm_name = "WIP"; //STILL DECIDING
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
        if (target == ui_Screen2_Label_PM_mode) {
            set_pm_text_value(ui_Screen2_Label_PM_mode);
        }
    }
    if(event_code == USER_EVENT_PM_SIDE_CHANGE) {
        if ((target == ui_Screen2_led1 || ui_Screen2_led2) && (user_state.pointing_side)) {
                lv_led_on(ui_Screen2_led1);
                lv_led_off(ui_Screen2_led2);
        } else {
                lv_led_off(ui_Screen2_led1);
                lv_led_on(ui_Screen2_led2);
        }
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
        snprintf(buf, sizeof(buf), "CPI: %d", (int)qmk_lv_get_cpi());
        lv_label_set_text(lbl, buf);
    }
}

void ui_render_cpi(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_CPI_UPDATE) {
         set_cpi_text_value(ui_Screen2_Label_CPI);
        //  lv_arc_set_value(ui_Arc3, qmk_lv_get_cpi());
    }
}

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
        snprintf(buf, sizeof(buf), "RGB: %s", rgb_matrix_name(curr_effect));
            for (int i = 5; i < sizeof(buf); ++i) {
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
         set_rgbmode_text_value(ui_Screen1_Label_RGB);
    }
}

/*ACTIVE LAYER CHANGE*/
void ui_active_layer_change(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_ACTIVE_LAYER_CHANGE) {
        switch (get_highest_layer(layer_state | default_layer_state )) {
            case _COLEMAK_DH:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "LAYER");
                break;
            case 1:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "LAYER");
                break;
            case 2:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "LAYER");
                break;
            case 3:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "LAYER");
                break;
            case _MOUSE:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_trackball_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "MOUSE");
                break;
            case _LOWER:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_lower_80_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "LOWER");
                 break;
            case _RAISE:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_raise_80_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "RAISE");
                break;
            case _ADJUST:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_toolbox_80_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "ADJUST");
                break;
            case _KEYPAD:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_numpad_80_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "KEYPAD");
                break;
            case _MEDIA:
                lv_img_set_src(ui_Layer_Indicator, &ui_img_emblem_80_png);
                lv_label_set_text(ui_Screen2_Label_Layer, "MEDIA");
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
        char buf[5];
        snprintf(buf, sizeof(buf), "%s", keylog_str);
        lv_label_set_text(ui_Screen1_Label_KL, buf);
    }
}
#endif


// // static void poll_cpi(lv_timer_t* timer) {
// //     LV_UNUSED(timer);
// //     lv_obj_t* ui_Label1 = timer->user_data;
// //     if (lv_obj_is_valid(ui_Label1)) {
// //         char buf[5];
// //         snprintf(buf, sizeof(buf), "%s", keylog_str);
// //         lv_label_set_text(ui_Label1, buf);
// //     }
// // }

// void ui_event_StatusPanel(lv_event_t * e) {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     // lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == USER_EVENT_PANEL_CHANGE) {
//         switch ((int)get_scroll_mode()) {
//         case 0:
//             _ui_state_modify(ui_Status_Dragscroll, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//             _ui_state_modify(ui_Status_Caret, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//             _ui_state_modify(ui_Status_Volume, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//             break;
//         case 1:
//             _ui_state_modify(ui_Status_Dragscroll, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
//             break;
//         case 2:
//             _ui_state_modify(ui_Status_Caret, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
//             break;
//         case 3:
//             _ui_state_modify(ui_Status_Volume, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
//             break;
//         }
//         if(emblem_get_pointer_sniping_enabled()) {
//             _ui_state_modify(ui_Status_Sniping, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
//         } else {
//             _ui_state_modify(ui_Status_Sniping, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//         }
//         if(is_audio_on()) {
//             _ui_state_modify(ui_Status_Audio, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
//         } else {
//             _ui_state_modify(ui_Status_Audio, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//         }
//         if(is_clicky_on()) {
//             _ui_state_modify(ui_Status_Clicky, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
//         } else {
//             _ui_state_modify(ui_Status_Clicky, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//         }
//         if(autocorrect_is_enabled()) {
//             _ui_state_modify(ui_Status_Autocorrect, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
//         } else {
//             _ui_state_modify(ui_Status_Autocorrect  , LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//         }
//     }
//     // if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_DEFAULT)) {
//     //     _ui_state_modify(ui_Status_Sniping, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//     //     _ui_state_modify(ui_Status_Dragscroll, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//     //     _ui_state_modify(ui_Status_Caret, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//     //     _ui_state_modify(ui_Status_Volume, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
//     // }
// }


// ///////////////////// SCREENS ////////////////////
// void ui_Screen1_screen_init(void) {

//     if (timer != NULL) {
//         lv_timer_del(timer);
//         timer = NULL;
//     }
//     ui_Screen1 = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_color(ui_Screen1, lv_color_hex(0xCBC90F), LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_Main1 = lv_obj_create(ui_Screen1);
//     lv_obj_clear_flag(ui_Main1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_color(ui_Main1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_Main1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_color(ui_Main1, lv_color_hex(0xCBC90F), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_x(ui_Main1, 0);
//     lv_obj_set_y(ui_Main1, 0);
//     lv_obj_set_width(ui_Main1, 240);   /// 81
//     lv_obj_set_height(ui_Main1, 240);    /// 55
//     lv_obj_set_align(ui_Main1, LV_ALIGN_CENTER);
//     lv_obj_set_style_border_side(ui_Main1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_Image1 = lv_img_create(ui_Main1);
//     lv_obj_add_event_cb(ui_Image1, ui_active_layer_change, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
//     // lv_img_set_src(ui_Image1, &ui_img_emblem_80_png);
//     lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 81
//     lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 55
//     lv_obj_set_x(ui_Image1, 0);
//     lv_obj_set_y(ui_Image1, -42);
//     lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
//     lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);

//     ui_Arc1 = lv_arc_create(ui_Main1);
//     lv_obj_set_width(ui_Arc1, 200);
//     lv_obj_set_height(ui_Arc1, 200);
//     lv_obj_set_x(ui_Arc1, 0);
//     lv_obj_set_y(ui_Arc1, 0);
//     lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);

//     lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0xDC81EF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_rounded(ui_Arc1, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

//     lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xF4F385), LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_arc_set_range(ui_Arc1, 0, 200);

//     // timer = lv_timer_create(add_data, 100, ui_Arc1);

//     // ui_Panel1 = lv_obj_create(ui_Screen1);
//     // lv_obj_set_width(ui_Panel1, 80);
//     // lv_obj_set_height(ui_Panel1, 20);
//     // lv_obj_set_x(ui_Panel1, 0);
//     // lv_obj_set_y(ui_Panel1, 20);
//     // lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
//     // lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     // ui_Layer1 = lv_label_create(ui_Panel1);
//     // lv_obj_set_width(ui_Layer1, LV_SIZE_CONTENT);   /// 1
//     // lv_obj_set_height(ui_Layer1, LV_SIZE_CONTENT);    /// 1
//     // lv_obj_set_align(ui_Layer1, LV_ALIGN_CENTER);
//     // lv_obj_set_style_text_align(ui_Layer1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
//     // lv_obj_set_style_text_font(ui_Layer1, &ui_font_Font12, LV_PART_MAIN | LV_STATE_DEFAULT);
//     // lv_obj_set_style_bg_grad_color(ui_Layer1, lv_color_hex(0xDD2C2C), LV_PART_MAIN | LV_STATE_DEFAULT);
//     // // timer = lv_timer_create(poll_layer, 100, ui_Layer1);
//     // lv_obj_add_event_cb(ui_Layer1, ui_df_layer_change, USER_EVENT_DF_LAYER_CHANGE, NULL);

//     ui_Panel2 = lv_obj_create(ui_Main1);
//     lv_obj_set_width(ui_Panel2, 80);
//     lv_obj_set_height(ui_Panel2, 20);
//     lv_obj_set_x(ui_Panel2, 0);
//     lv_obj_set_y(ui_Panel2, 110);
//     lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     ui_Label1 = lv_label_create(ui_Panel2);
//     lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
//     lv_obj_set_style_text_font(ui_Label1, &ui_font_Font12, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_add_event_cb(ui_Label1, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);
//     // timer = lv_timer_create(poll_cpi, 100, ui_Label1);


//     ui_Arc3 = lv_arc_create(ui_Main1);
//     lv_obj_set_width(ui_Arc3, 235);
//     lv_obj_set_height(ui_Arc3, 235);
//     lv_obj_set_align(ui_Arc3, LV_ALIGN_CENTER);
//     lv_arc_set_range(ui_Arc3, 200, 3400);
//     lv_obj_add_event_cb(ui_Arc3, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);
//     // timer = lv_timer_create(poll_cpi_text, 100, ui_Arc3);

//     ui_Settings1 = lv_btn_create(ui_Main1);
//     lv_obj_set_width(ui_Settings1, 80);
//     lv_obj_set_height(ui_Settings1, 20);
//     lv_obj_set_x(ui_Settings1, 0);
//     lv_obj_set_y(ui_Settings1, 60);
//     lv_obj_set_align(ui_Settings1, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_Settings1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     // if (lv_scr_act() == ui_Screen2) {
//     //     lv_obj_add_flag(ui_Settings1, LV_OBJ_FLAG_HIDDEN);
//     // } else {
//     //     lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_HIDDEN);
//     // }
//     lv_obj_set_style_bg_color(ui_Settings1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_Settings1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_color(ui_Settings1, lv_color_hex(0xFE0000), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_shadow_opa(ui_Settings1, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_shadow_width(ui_Settings1, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_shadow_spread(ui_Settings1, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
//     // lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     // lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLLABLE);
//     // lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
//     // lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_CLICKABLE);

//     ui_SettingsMain = lv_label_create(ui_Settings1);
//     lv_obj_set_width(ui_SettingsMain, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_SettingsMain, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_align(ui_SettingsMain, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_SettingsMain, "SETTINGS");
//     lv_obj_set_style_text_color(ui_SettingsMain, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_SettingsMain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_SettingsMain, &ui_font_Font12, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_SettingsMain, lv_color_hex(0xFF0505), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_text_opa(ui_SettingsMain, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
//     // lv_obj_clear_flag(ui_SettingsMain, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     // lv_obj_clear_flag(ui_SettingsMain, LV_OBJ_FLAG_SCROLLABLE);
//     // lv_obj_clear_flag(ui_SettingsMain, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
//     // lv_obj_clear_flag(ui_SettingsMain, LV_OBJ_FLAG_CLICKABLE);

//     ui_StatusPanel = lv_obj_create(ui_Main1);
//     lv_obj_set_width(ui_StatusPanel, 125);
//     lv_obj_set_height(ui_StatusPanel, 55);
//     lv_obj_set_x(ui_StatusPanel, 0);
//     lv_obj_set_y(ui_StatusPanel, 25);
//     lv_obj_set_align(ui_StatusPanel, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_StatusPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_color(ui_StatusPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_StatusPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_StatusPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_StatusPanel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_StatusPanel, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_Status_Sniping = lv_label_create(ui_StatusPanel);
//     lv_obj_set_width(ui_Status_Sniping, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Status_Sniping, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_Status_Sniping, -50);
//     lv_obj_set_y(ui_Status_Sniping, -14);
//     lv_obj_set_align(ui_Status_Sniping, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_Status_Sniping, FBS_ICON_SNIPING);
//     lv_obj_set_style_text_color(ui_Status_Sniping, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_Status_Sniping, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_Status_Sniping, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_Status_Sniping, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_text_opa(ui_Status_Sniping, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

//     ui_Status_Dragscroll = lv_label_create(ui_StatusPanel);
//     lv_obj_set_width(ui_Status_Dragscroll, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Status_Dragscroll, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_Status_Dragscroll, -20);
//     lv_obj_set_y(ui_Status_Dragscroll, -14);
//     lv_obj_set_align(ui_Status_Dragscroll, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_Status_Dragscroll, FBS_ICON_DRAGSCROLL);
//     lv_obj_set_style_text_color(ui_Status_Dragscroll, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_Status_Dragscroll, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_Status_Dragscroll, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_Status_Dragscroll, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_text_opa(ui_Status_Dragscroll, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

//     ui_Status_Caret = lv_label_create(ui_StatusPanel);
//     lv_obj_set_width(ui_Status_Caret, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Status_Caret, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_Status_Caret, 20);
//     lv_obj_set_y(ui_Status_Caret, -14);
//     lv_obj_set_align(ui_Status_Caret, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_Status_Caret, FBS_ICON_CARET);
//     lv_obj_set_style_text_color(ui_Status_Caret, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_Status_Caret, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_Status_Caret, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_Status_Caret, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_text_opa(ui_Status_Caret, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

//     ui_Status_Volume = lv_label_create(ui_StatusPanel);
//     lv_obj_set_width(ui_Status_Volume, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Status_Volume, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_Status_Volume, 50);
//     lv_obj_set_y(ui_Status_Volume, -14);
//     lv_obj_set_align(ui_Status_Volume, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_Status_Volume, FBS_ICON_VOLUME);
//     lv_obj_set_style_text_color(ui_Status_Volume, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_Status_Volume, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_Status_Volume, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_Status_Volume, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_text_opa(ui_Status_Volume, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

//     ui_Status_Audio = lv_label_create(ui_StatusPanel);
//     lv_obj_set_width(ui_Status_Audio, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Status_Audio, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_Status_Audio, -50);
//     lv_obj_set_y(ui_Status_Audio, 9);
//     lv_obj_set_align(ui_Status_Audio, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_Status_Audio, FBS_ICON_HP);
//     lv_obj_set_style_text_color(ui_Status_Audio, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_Status_Audio, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_Status_Audio, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_Status_Audio, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_text_opa(ui_Status_Audio, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

//     ui_Status_Clicky = lv_label_create(ui_StatusPanel);
//     lv_obj_set_width(ui_Status_Clicky, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Status_Clicky, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_Status_Clicky, -20);
//     lv_obj_set_y(ui_Status_Clicky, 9);
//     lv_obj_set_align(ui_Status_Clicky, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_Status_Clicky, FBS_ICON_BELL);
//     lv_obj_set_style_text_color(ui_Status_Clicky, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_Status_Clicky, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_Status_Clicky, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_Status_Clicky, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_text_opa(ui_Status_Clicky, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

//     ui_Status_Autocorrect = lv_label_create(ui_StatusPanel);
//     lv_obj_set_width(ui_Status_Au    tocorrect, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_Status_Autocorrect, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_Status_Autocorrect, 20);
//     lv_obj_set_y(ui_Status_Autocorrect, 9);
//     lv_obj_set_align(ui_Status_Autocorrect, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_Status_Autocorrect, FBS_ICON_CHECK);
//     lv_obj_set_style_text_color(ui_Status_Autocorrect, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_Status_Autocorrect, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_Status_Autocorrect, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_Status_Autocorrect, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_text_opa(ui_Status_Autocorrect, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

// //     meter = lv_meter_create(ui_Screen1);
// //     lv_obj_center(meter);
// //     lv_obj_set_size(meter, 200, 200);

// //     /*Remove the circle from the middle*/
// //     lv_obj_remove_style(meter, NULL, LV_PART_INDICATOR);

// //     /*Add a scale first*/
// //     lv_meter_scale_t * scale = lv_meter_add_scale(meter);
// //     // lv_meter_set_scale_ticks(meter, scale, 11, 2, 10, lv_palette_main(LV_PALETTE_GREY));
// //     // lv_meter_set_scale_major_ticks(meter, scale, 1, 2, 30, lv_color_hex3(0xeee), 15);
// //     lv_meter_set_scale_range(meter, scale, 0, 300, 270, 90);

// //     /*Add a three arc indicator*/
// //     // lv_meter_indicator_t * indic1 = lv_meter_add_arc(meter, scale, 10, lv_palette_main(LV_PALETTE_RED), 0);
// //     // lv_meter_indicator_t * indic2 = lv_meter_add_arc(meter, scale, 10, lv_palette_main(LV_PALETTE_GREEN), -10);
// //     indic3 = lv_meter_add_arc(meter, scale, 10, lv_palette_main(LV_PALETTE_BLUE), -20);
// //  lv_obj_add_event_cb(meter, ui_render_wpm, USER_EVENT_WPM_UPDATE, NULL);



//     ui_Screen2 = lv_obj_create(ui_Screen1);
//     lv_obj_add_flag(ui_Screen2, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_width(ui_Screen2, 240);
//     lv_obj_set_height(ui_Screen2, 240);
//     lv_obj_set_x(ui_Screen2, 0);
//     lv_obj_set_y(ui_Screen2, 0);
//     lv_obj_set_align(ui_Screen2, LV_ALIGN_CENTER);
//     lv_obj_set_style_border_side(ui_Screen2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//    /// Flags

//     lv_obj_t* background = lv_obj_create(ui_Screen2);

//     lv_obj_set_size(background, 240, 240);
//     lv_obj_set_style_border_width(background, 0, 0);
//     lv_obj_set_style_pad_all(background, 0, 0);
//     lv_obj_center(background);

//     lv_obj_add_style(background, &style_main_screen, 0);

//     ui_dflayer_dropdown = lv_dropdown_create(ui_Main1);
//     static const char * opts = "CLMK_DH\n"
//                                "COLEMAK\n"
//                                "QWERTY\n"
//                                "DVORAK";
//     lv_dropdown_set_options_static(ui_dflayer_dropdown, opts);
//     lv_obj_set_width(ui_dflayer_dropdown, 80);
//     lv_obj_set_height(ui_dflayer_dropdown, 25);
//     lv_obj_set_x(ui_dflayer_dropdown, 0);
//     lv_obj_set_y(ui_dflayer_dropdown, 85);
//     lv_obj_set_align(ui_dflayer_dropdown, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_SCROLLABLE);
//     lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
//     lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_CHECKABLE);
//     lv_obj_add_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
//     // lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_SCROLLABLE);
//     // if (lv_scr_act() == ui_Screen2) {
//     //     lv_obj_add_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
//     // } else {
//     //     lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
//     // }
//     lv_obj_set_style_text_align(ui_dflayer_dropdown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_decor(ui_dflayer_dropdown, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_dflayer_dropdown, &ui_font_Font12, LV_PART_MAIN | LV_STATE_DEFAULT);


//     lv_obj_add_event_cb(ui_dflayer_dropdown, ui_event_dflayer_dropdown, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_StatusPanel, ui_event_StatusPanel, USER_EVENT_PANEL_CHANGE, NULL);
//     lv_obj_add_event_cb(ui_Settings1, ui_event_Settings1, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_Arc1, ui_render_wpm, USER_EVENT_WPM_UPDATE, NULL);

// }

// // void ui_Screen2_screen_init(void)
// // {
// //     ui_Screen2 = lv_obj_create(ui_Screen1);
// //     lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
// //     lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
// //     lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
// //     lv_obj_set_width(ui_Screen2, 240);
// //     lv_obj_set_height(ui_Screen2, 240);
// //     lv_obj_set_x(ui_Screen2, 0);
// //     lv_obj_set_y(ui_Screen2, 0);
// //     lv_obj_set_align(ui_Screen2, LV_ALIGN_CENTER);
// //    /// Flags

// //     lv_obj_t* background = lv_obj_create(ui_Screen2);

// //     lv_obj_set_size(background, 240, 240);
// //     lv_obj_set_style_border_width(background, 0, 0);
// //     lv_obj_set_style_pad_all(background, 0, 0);
// //     lv_obj_center(background);

// //     lv_obj_add_style(background, &style_main_screen, 0);


// // //     ui_SettingsAux = lv_btn_create(ui_Screen2);
// // //     lv_obj_set_width(ui_SettingsAux, 20);
// // //     lv_obj_set_height(ui_SettingsAux, 20);
// // //     lv_obj_set_x(ui_SettingsAux, -50);
// // //     lv_obj_set_y(ui_SettingsAux, -20);
// // //     lv_obj_set_align(ui_SettingsAux, LV_ALIGN_CENTER);
// // //     lv_obj_add_flag(ui_SettingsAux, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
// // //     lv_obj_clear_flag(ui_SettingsAux, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
// // //     lv_obj_set_style_bg_color(ui_SettingsAux, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
// // //     lv_obj_set_style_bg_opa(ui_SettingsAux, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
// // //     lv_obj_set_style_text_align(ui_SettingsAux, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
// // //     lv_obj_set_style_text_font(ui_SettingsAux, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);
// // //     // lv_obj_add_event_cb(ui_SettingsAux, screen_loader, LV_EVENT_PRESSED, NULL);


// // //     ui_Settings2 = lv_label_create(ui_SettingsAux);
// // //     lv_obj_set_width(ui_Settings2, LV_SIZE_CONTENT);   /// 1
// // //     lv_obj_set_height(ui_Settings2, LV_SIZE_CONTENT);    /// 1
// // //     lv_obj_set_align(ui_Settings2, LV_ALIGN_CENTER);
// // //     lv_obj_set_style_text_color(ui_Settings2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
// // //     lv_obj_set_style_text_opa(ui_Settings2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
// // //     lv_obj_set_style_text_color(ui_Settings2, lv_color_hex(0x11A200), LV_PART_MAIN | LV_STATE_PRESSED);
// // //     lv_obj_set_style_text_opa(ui_Settings2, 255, LV_PART_MAIN | LV_STATE_PRESSED);
// // //     lv_obj_set_style_text_font(ui_Settings2, &ui_font_Font12, LV_PART_MAIN | LV_STATE_PRESSED);
// // //     lv_obj_set_style_text_color(ui_Settings2, lv_color_hex(0xCB0006), LV_PART_MAIN | LV_STATE_FOCUSED);
// // //     lv_obj_set_style_text_opa(ui_Settings2, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
// // //     lv_obj_set_style_text_font(ui_Settings2, &ui_font_Font12, LV_PART_MAIN | LV_STATE_FOCUSED);

// // //     lv_obj_add_event_cb(ui_SettingsAux, ui_event_SettingsAux, LV_EVENT_ALL, NULL);
// // }

// // void lvgl_control_led_indicators(void)
// // {
// //     /*Create a LED and switch it OFF*/
// //     lv_obj_t * led1  = lv_led_create(lv_scr_act());
// //     lv_obj_align(led1, LV_ALIGN_CENTER, -80, 0);
// //     lv_led_off(led1);

// //     /*Copy the previous LED and set a brightness*/
// //     lv_obj_t * led2  = lv_led_create(lv_scr_act());
// //     lv_obj_align(led2, LV_ALIGN_CENTER, 80, 0);
// //     lv_led_set_brightness(led2, 150);
// //     lv_led_set_color(led2, lv_palette_main(LV_PALETTE_RED));

// //     /*Copy the previous LED and switch it ON*/
// //     lv_obj_t * led3  = lv_led_create(lv_scr_act());
// //     lv_obj_align(led3, LV_ALIGN_CENTER, 80, 0);
// //     lv_led_on(led3);
// // }
// bool lvgl_control = 0;

// void disable_lvgl() {
//     lvgl_control = false;
// }


// void ui_init(void)
// {
//     lv_disp_t * dispp = lv_disp_get_default();
//     lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
//                                                false, LV_FONT_DEFAULT);
//     lv_disp_set_theme(dispp, theme);
//     ui_Screen1_screen_init();
//     // ui_Screen2_screen_init();
//     lv_disp_load_scr(ui_Screen1);
//     lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_add_flag(ui_Settings1, LV_OBJ_FLAG_CLICKABLE);

//     init_menu();

//     // lv_disp_load_scr(ui_Screen2);

//     init_dial_menu(ui_Screen2);
//     create_dial_menu(ui_Screen2, &root);
//     // _ui_flag_modify(ui_Screen2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

//     // init_layer_widget();


// }

// // void screen_loader(lv_event_t * e) {
// //     lv_event_code_t code = lv_event_get_code(e);
// //     lv_obj_t * btn = lv_event_get_target(e);
// //     if(code == LV_EVENT_PRESSED && btn == ui_Settings1) {
// //         lv_disp_load_scr(ui_Screen2);
// //     }
// //     if(code == LV_EVENT_PRESSED && btn == ui_SettingsAux) {
// //         lv_disp_load_scr(ui_Screen1);
// //     }
// // }

// void ui_event_Settings1(lv_event_t * e) {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     // lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_HIDDEN);
//         lv_obj_add_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
//         lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_CLICKABLE);
//         lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLLABLE);

//         // lv_obj_add_flag(ui_Settings1, LV_OBJ_FLAG_HIDDEN);
//         // lv_obj_add_flag(ui_SettingsMain, LV_OBJ_FLAG_HIDDEN);
//         // _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// // void ui_event_SettingsAux(lv_event_t * e)
// // {
// //     lv_event_code_t event_code = lv_event_get_code(e);
// //     // lv_obj_t * target = lv_event_get_target(e);
// //     if(event_code == LV_EVENT_PRESSED) {
// //         _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
// //     }
// // }

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

   ui_Screen1_Image1 = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_Screen1_Image1, &ui_img_city_png);
    lv_obj_set_width(ui_Screen1_Image1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Image1, LV_SIZE_CONTENT);    /// 1
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen1_Image1, -19);
        lv_obj_set_y(ui_Screen1_Image1, 18);
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen1_Image1, 1);
        lv_obj_set_y(ui_Screen1_Image1, 95);
    #endif
    lv_obj_set_align(ui_Screen1_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Label_RGB = lv_label_create(ui_Screen1);
    lv_obj_set_height(ui_Screen1_Label_RGB, LV_SIZE_CONTENT);    /// 1
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_width(ui_Screen1_Label_RGB, 70);
        lv_obj_set_style_text_font(ui_Screen1_Label_RGB, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_x(ui_Screen1_Label_RGB, 5);
        lv_obj_set_y(ui_Screen1_Label_RGB, 57);
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_width(ui_Screen1_Label_RGB, 158);
        lv_obj_set_style_text_font(ui_Screen1_Label_RGB, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_x(ui_Screen1_Label_RGB, 9);
        lv_obj_set_y(ui_Screen1_Label_RGB, 50);
    #endif
    lv_label_set_text(ui_Screen1_Label_RGB, "RGB");

    // lv_label_set_long_mode(ui_Screen1_Label_RGB, LV_LABEL_LONG_SCROLL);

    ui_Screen1_Label_WPM = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label_WPM, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_WPM, LV_SIZE_CONTENT);    /// 1
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen1_Label_WPM, 5);
        lv_obj_set_y(ui_Screen1_Label_WPM, 33);
        lv_obj_set_style_text_font(ui_Screen1_Label_WPM, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen1_Label_WPM, 9);
        lv_obj_set_y(ui_Screen1_Label_WPM,20);
        lv_obj_set_style_text_font(ui_Screen1_Label_WPM, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
    #endif
    lv_label_set_text(ui_Screen1_Label_WPM, "WPM");

#ifdef OS_DETECTION_ENABLE
    ui_Screen1_Label_OS = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label_OS, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_OS, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label_OS, 9);
    lv_obj_set_y(ui_Screen1_Label_OS, 174);
    set_OS_text_value(ui_Screen1_Label_OS);
    lv_obj_set_style_text_font(ui_Screen1_Label_OS, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
#endif

#ifdef CUSTOM_KEYLOGGER
    ui_Screen1_Label_KL = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label_KL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_KL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label_KL, 9);
    lv_obj_set_y(ui_Screen1_Label_KL, 200);
    lv_obj_set_style_text_font(ui_Screen1_Label_KL, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
    timer = lv_timer_create(ui_render_keylogger, 1000, ui_Screen1_Label_KL);
#endif


    ui_Screen1_Panel_KB_Status = lv_obj_create(ui_Screen1);
    lv_obj_set_x(ui_Screen1_Panel_KB_Status, 0);
    lv_obj_set_y(ui_Screen1_Panel_KB_Status, -10);
    lv_obj_set_width(ui_Screen1_Panel_KB_Status, 150);
    lv_obj_set_height(ui_Screen1_Panel_KB_Status, 70);
    lv_obj_set_align(ui_Screen1_Panel_KB_Status, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel_KB_Status, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_font(ui_Screen1_Panel_KB_Status, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Panel_KB_Status, lv_color_hex(0xEA3535), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_Screen1_Panel_KB_Status, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui_Screen1_Panel_KB_Status, &ui_font_Futura20, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_opa(ui_Screen1_Panel_KB_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Panel_KB_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Panel_KB_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Screen1_Panel_KB_Status, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Screen1_Panel_KB_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Screen1_Panel_KB_Status, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Screen1_Panel_KB_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label_CAPS = lv_label_create(ui_Screen1_Panel_KB_Status);
    lv_obj_set_width(ui_Screen1_Label_CAPS, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_CAPS, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label_CAPS, -48);
    lv_obj_set_y(ui_Screen1_Label_CAPS, -16);
    lv_obj_set_align(ui_Screen1_Label_CAPS, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label_CAPS, "CAPS");
    lv_obj_set_style_text_font(ui_Screen1_Label_CAPS, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_CAPS, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_CAPS, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_CAPS, lv_color_hex(0xEA3535), LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Screen1_Label_SCLK = lv_label_create(ui_Screen1_Panel_KB_Status);
    lv_obj_set_width(ui_Screen1_Label_SCLK, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_SCLK, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label_SCLK, 0);
    lv_obj_set_y(ui_Screen1_Label_SCLK, -16);
    lv_obj_set_align(ui_Screen1_Label_SCLK, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label_SCLK, "SCLK");
    lv_obj_set_style_text_font(ui_Screen1_Label_SCLK, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_SCLK, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_SCLK, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_SCLK, lv_color_hex(0xEA3535), LV_PART_MAIN | LV_STATE_FOCUSED);


    ui_Screen1_Label_NMLK = lv_label_create(ui_Screen1_Panel_KB_Status);
    lv_obj_set_width(ui_Screen1_Label_NMLK, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_NMLK, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label_NMLK, 48);
    lv_obj_set_y(ui_Screen1_Label_NMLK, -16);
    lv_obj_set_align(ui_Screen1_Label_NMLK, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label_NMLK, "NMLK");
    lv_obj_set_style_text_font(ui_Screen1_Label_NMLK, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_NMLK, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_NMLK, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_NMLK, lv_color_hex(0xEA3535), LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Screen1_Label_AUDIO = lv_label_create(ui_Screen1_Panel_KB_Status);
    lv_obj_set_width(ui_Screen1_Label_AUDIO, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_AUDIO, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label_AUDIO, -48);
    lv_obj_set_y(ui_Screen1_Label_AUDIO, 16);
    lv_obj_set_align(ui_Screen1_Label_AUDIO, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label_AUDIO, "AUD");
    lv_obj_set_style_text_font(ui_Screen1_Label_AUDIO, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_AUDIO, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_AUDIO, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_AUDIO, lv_color_hex(0xEA3535), LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Screen1_Label_CLICKY = lv_label_create(ui_Screen1_Panel_KB_Status);
    lv_obj_set_width(ui_Screen1_Label_CLICKY, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_CLICKY, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label_CLICKY, 0);
    lv_obj_set_y(ui_Screen1_Label_CLICKY, 16);
    lv_obj_set_align(ui_Screen1_Label_CLICKY, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label_CLICKY, "CLKY");
    lv_obj_set_style_text_font(ui_Screen1_Label_CLICKY, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_CLICKY, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_CLICKY, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_CLICKY, lv_color_hex(0xEA3535), LV_PART_MAIN | LV_STATE_FOCUSED);


    ui_Screen1_Label_ACRT = lv_label_create(ui_Screen1_Panel_KB_Status);
    lv_obj_set_width(ui_Screen1_Label_ACRT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_ACRT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label_ACRT, 48);
    lv_obj_set_y(ui_Screen1_Label_ACRT, 16);
    lv_obj_set_align(ui_Screen1_Label_ACRT, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label_ACRT, "ACRT");
    lv_obj_set_style_text_font(ui_Screen1_Label_ACRT, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_ACRT, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_ACRT, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_ACRT, lv_color_hex(0xEA3535), LV_PART_MAIN | LV_STATE_FOCUSED);


    ui_Screen1_Panel_HSV = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Panel_HSV, 150);
    lv_obj_set_height(ui_Screen1_Panel_HSV, 25);
    lv_obj_set_x(ui_Screen1_Panel_HSV, 0);
    lv_obj_set_y(ui_Screen1_Panel_HSV, 57);
    lv_obj_set_align(ui_Screen1_Panel_HSV, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel_HSV, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_font(ui_Screen1_Panel_HSV, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Panel_HSV, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Panel_HSV, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Panel_HSV, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Screen1_Panel_HSV, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Screen1_Panel_HSV, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Screen1_Panel_HSV, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Screen1_Panel_HSV, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label_H = lv_label_create(ui_Screen1_Panel_HSV);
    lv_obj_set_width(ui_Screen1_Label_H, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_H, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label_H, LV_ALIGN_CENTER);
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen1_Label_H, 0);
        lv_obj_set_y(ui_Screen1_Label_H, 0); //placeholder only. Only Rev2 has correct positioning.
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen1_Label_H, -50);
        lv_obj_set_y(ui_Screen1_Label_H, 0);
    #endif
    lv_obj_set_style_text_font(ui_Screen1_Label_H, &ui_font_Futura20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_H, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_H, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label_H, &ui_font_Futura20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_H, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_label_set_text(ui_Screen1_Label_H, "H");

    ui_Screen1_Label_S = lv_label_create(ui_Screen1_Panel_HSV);
    lv_obj_set_width(ui_Screen1_Label_S, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_S, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label_S, LV_ALIGN_CENTER);
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen1_Label_S, 0);
        lv_obj_set_y(ui_Screen1_Label_S, 0); //placeholder only. Only Rev2 has correct positioning.
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen1_Label_S, -1);
        lv_obj_set_y(ui_Screen1_Label_S, 0);
    #endif
    lv_obj_set_style_text_font(ui_Screen1_Label_S, &ui_font_Futura20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_S, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_S, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label_S, &ui_font_Futura20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_S, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_label_set_text(ui_Screen1_Label_S, "S");

    ui_Screen1_Label_V = lv_label_create(ui_Screen1_Panel_HSV);
    lv_obj_set_width(ui_Screen1_Label_V, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_V, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label_V, LV_ALIGN_CENTER);
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen1_Label_V, 0);
        lv_obj_set_y(ui_Screen1_Label_V, 0); //placeholder only. Only Rev2 has correct positioning.
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen1_Label_V, 45);
        lv_obj_set_y(ui_Screen1_Label_V, 0);
    #endif
    lv_obj_set_style_text_font(ui_Screen1_Label_V, &ui_font_Futura20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_V, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_V, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label_S, &ui_font_Futura20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_V, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_label_set_text(ui_Screen1_Label_V, "V");

    ui_Screen1_Panel_Status = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Panel_Status, 150);
    lv_obj_set_height(ui_Screen1_Panel_Status, 70);
    lv_obj_set_x(ui_Screen1_Panel_Status, 0);
    lv_obj_set_y(ui_Screen1_Panel_Status, 118);
    lv_obj_set_align(ui_Screen1_Panel_Status, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel_Status, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_font(ui_Screen1_Panel_Status, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Panel_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Panel_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Panel_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Screen1_Panel_Status, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Screen1_Panel_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Screen1_Panel_Status, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Screen1_Panel_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_Screen1_Label_GUI = lv_label_create(ui_Screen1_Panel_Status);
    lv_obj_set_width(ui_Screen1_Label_GUI, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_GUI, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label_GUI, LV_ALIGN_CENTER);
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen1_Label_GUI, 0);
        lv_obj_set_y(ui_Screen1_Label_GUI, 0); //placeholder only. Only Rev2 has correct positioning.
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen1_Label_GUI, -37.5);
        lv_obj_set_y(ui_Screen1_Label_GUI, -15);
    #endif
    lv_obj_set_style_text_font(ui_Screen1_Label_GUI, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_GUI, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_GUI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label_GUI, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_GUI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_label_set_text(ui_Screen1_Label_GUI, "GUI");

    ui_Screen1_Label_ALT = lv_label_create(ui_Screen1_Panel_Status);
    lv_obj_set_width(ui_Screen1_Label_ALT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_ALT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label_ALT, LV_ALIGN_CENTER);
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen1_Label_ALT, 0);
        lv_obj_set_y(ui_Screen1_Label_ALT, 0); //placeholder only. Only Rev2 has correct positioning.
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen1_Label_ALT, -37.5);
        lv_obj_set_y(ui_Screen1_Label_ALT, 15);
    #endif
    lv_obj_set_style_text_font(ui_Screen1_Label_ALT, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_ALT, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_ALT, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label_ALT, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_ALT, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_label_set_text(ui_Screen1_Label_ALT, "ALT");

    ui_Screen1_Label_CTRL = lv_label_create(ui_Screen1_Panel_Status);
    lv_obj_set_width(ui_Screen1_Label_CTRL, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_CTRL, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label_CTRL, LV_ALIGN_CENTER);
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen1_Label_CTRL, 0);
        lv_obj_set_y(ui_Screen1_Label_CTRL, 0); //placeholder only. Only Rev2 has correct positioning.
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen1_Label_CTRL, 37.5);
        lv_obj_set_y(ui_Screen1_Label_CTRL, -15);
    #endif
    lv_obj_set_style_text_font(ui_Screen1_Label_CTRL, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_CTRL, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_CTRL, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label_CTRL, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_CTRL, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_label_set_text(ui_Screen1_Label_CTRL, "CTRL");

    ui_Screen1_Label_SHIFT = lv_label_create(ui_Screen1_Panel_Status);
    lv_obj_set_width(ui_Screen1_Label_SHIFT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label_SHIFT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen1_Label_SHIFT, LV_ALIGN_CENTER);
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen1_Label_SHIFT, 0);
        lv_obj_set_y(ui_Screen1_Label_SHIFT, 0); //placeholder only. Only Rev2 has correct positioning.
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen1_Label_SHIFT, 37.5);
        lv_obj_set_y(ui_Screen1_Label_SHIFT, 15);
    #endif
    lv_obj_set_style_text_font(ui_Screen1_Label_SHIFT, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_SHIFT, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label_SHIFT, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label_SHIFT, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1_Label_SHIFT, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_label_set_text(ui_Screen1_Label_SHIFT, "SHIFT");



    lv_obj_add_event_cb(ui_Screen1, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Screen1_Label_H, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Screen1_Label_S, ui_render_rgbsat_redraw, USER_EVENT_RGBSAT_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Screen1_Label_V, ui_render_rgbval_redraw, USER_EVENT_RGBVAL_UPDATE, NULL);
    // lv_obj_add_event_cb(ui_Screen1_Label_GUI, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    // lv_obj_add_event_cb(ui_Screen1_Label_ALT, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    // lv_obj_add_event_cb(ui_Screen1_Label_CTRL, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    // lv_obj_add_event_cb(ui_Screen1_Label_SHIFT, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Screen1_Label_RGB, ui_render_rgbmode, USER_EVENT_RGBMODE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Screen1_Label_WPM, ui_render_wpm, USER_EVENT_WPM_UPDATE, NULL);
    // lv_obj_add_event_cb(ui_Screen1_Label_KL, ui_render_keylogger, USER_EVENT_KEYLOG_UPDATE, NULL);

}

void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen2_Panel_Layer = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Screen2_Panel_Layer, 140);
    lv_obj_set_height(ui_Screen2_Panel_Layer, 120);
    lv_obj_set_x(ui_Screen2_Panel_Layer, 0);
    lv_obj_set_y(ui_Screen2_Panel_Layer, 30);
    lv_obj_set_align(ui_Screen2_Panel_Layer, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen2_Panel_Layer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_outline_opa(ui_Screen2_Panel_Layer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen2_Panel_Layer, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen2_Panel_Layer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Screen2_Panel_Layer, lv_color_hex(0xF2E3E3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Screen2_Panel_Layer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Screen2_Panel_Layer, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Screen2_Panel_Layer, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen2_Label_Layer = lv_label_create(ui_Screen2_Panel_Layer);
    lv_obj_set_width(ui_Screen2_Label_Layer, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen2_Label_Layer, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen2_Label_Layer, 0);
    lv_obj_set_y(ui_Screen2_Label_Layer, 48);
    lv_obj_set_align(ui_Screen2_Label_Layer, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen2_Label_Layer, "LAYER");
    lv_obj_set_style_text_align(ui_Screen2_Label_Layer, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Screen2_Label_Layer, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label_Layer, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_Screen2_Label_Layer, ui_active_layer_change, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);

    ui_Layer_Indicator = lv_img_create(ui_Screen2_Panel_Layer);
    lv_obj_add_event_cb(ui_Layer_Indicator, ui_active_layer_change, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);

    lv_obj_set_width(ui_Layer_Indicator, LV_SIZE_CONTENT);   /// 81
    lv_obj_set_height(ui_Layer_Indicator, LV_SIZE_CONTENT);    /// 55
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Layer_Indicator, 0);
        lv_obj_set_y(ui_Layer_Indicator, -40);
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Layer_Indicator, 0);
        lv_obj_set_y(ui_Layer_Indicator, -5);
    #endif
    lv_obj_set_align(ui_Layer_Indicator, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Layer_Indicator, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Layer_Indicator, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Screen2_Image2 = lv_img_create(ui_Screen2);
    // lv_img_set_src(ui_Screen2_Image2, &ui_img_city_png);
    // lv_obj_set_width(ui_Screen2_Image2, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Screen2_Image2, LV_SIZE_CONTENT);    /// 1
    // #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
    //     lv_obj_set_x(ui_Screen2_Image2, -17);
    //     lv_obj_set_y(ui_Screen2_Image2, 30);
    // #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
    //     lv_obj_set_x(ui_Screen2_Image2, -4);
    //     lv_obj_set_y(ui_Screen2_Image2, 96);
    // #endif
    // lv_obj_set_align(ui_Screen2_Image2, LV_ALIGN_CENTER);
    // lv_obj_add_flag(ui_Screen2_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_Screen2_Image2, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_Screen2_deflayer = lv_dropdown_create(ui_Screen2);

    static const char * opts = "COLEMAK_DH\n"
                               "COLEMAK\n"
                               "QWERTY\n"
                               "DVORAK";
    lv_dropdown_set_options_static(ui_Screen2_deflayer, opts);
    ui_Screen2_deflayer_list =  lv_dropdown_get_list(ui_Screen2_deflayer) ;

    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_style_text_font(ui_Screen2_deflayer_list , &ui_font_Futura12, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_width(ui_Screen2_deflayer, 73);
        lv_obj_set_height(ui_Screen2_deflayer, 33);
        lv_obj_set_x(ui_Screen2_deflayer, 1);
        lv_obj_set_y(ui_Screen2_deflayer, 25);
        lv_obj_set_align(ui_Screen2_deflayer, LV_ALIGN_CENTER);
        lv_obj_add_flag(ui_Screen2_deflayer, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_set_style_text_align(ui_Screen2_deflayer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_Screen2_deflayer, &ui_font_Futura12, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_set_style_text_align(ui_Screen2_deflayer, LV_TEXT_ALIGN_CENTER, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_Screen2_deflayer, &ui_font_Futura12, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_style_text_font(ui_Screen2_deflayer_list , &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_width(ui_Screen2_deflayer, 140);
        lv_obj_set_height(ui_Screen2_deflayer, 40);
        lv_obj_set_x(ui_Screen2_deflayer, 0);
        lv_obj_set_y(ui_Screen2_deflayer, 130);
        lv_obj_set_align(ui_Screen2_deflayer, LV_ALIGN_CENTER);
        // lv_obj_add_flag(ui_Screen2_deflayer, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_set_style_text_align(ui_Screen2_deflayer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_Screen2_deflayer, &ui_font_Futura22, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_set_style_text_align(ui_Screen2_deflayer, LV_TEXT_ALIGN_CENTER, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_Screen2_deflayer, &ui_font_Futura22, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_outline_opa(ui_Screen2_deflayer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_outline_width(ui_Screen2_deflayer, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_outline_pad(ui_Screen2_deflayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_outline_color(ui_Screen2_deflayer, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN | LV_STATE_DEFAULT );
    #endif

    ui_Screen2_Panel_Pointing_Mode = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Screen2_Panel_Pointing_Mode, 150);
    lv_obj_set_height(ui_Screen2_Panel_Pointing_Mode, 100);
    lv_obj_set_x(ui_Screen2_Panel_Pointing_Mode, 0);
    lv_obj_set_y(ui_Screen2_Panel_Pointing_Mode, -95);
    lv_obj_set_align(ui_Screen2_Panel_Pointing_Mode, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen2_Panel_Pointing_Mode, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_set_style_outline_opa(ui_Screen2_Panel_Pointing_Mode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen2_Panel_Pointing_Mode, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen2_Panel_Pointing_Mode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_Screen2_led1 = lv_led_create(ui_Screen2_Panel_Pointing_Mode);
    lv_obj_set_size(ui_Screen2_led1, 10, 10);
    lv_obj_align(ui_Screen2_led1, LV_ALIGN_CENTER, -65, -35);
    lv_led_set_brightness(ui_Screen2_led1, 255);
    lv_led_set_color(ui_Screen2_led1, lv_palette_main(LV_PALETTE_RED));

    ui_Screen2_led2  = lv_led_create(ui_Screen2_Panel_Pointing_Mode);
    lv_obj_set_size(ui_Screen2_led2, 10, 10);
    lv_obj_align(ui_Screen2_led2, LV_ALIGN_CENTER, -45, -35);
    lv_led_set_brightness(ui_Screen2_led2, 255);
    lv_led_set_color(ui_Screen2_led2, lv_palette_main(LV_PALETTE_RED));

    ui_Screen2_Label_PM_mode = lv_label_create(ui_Screen2_Panel_Pointing_Mode);
    lv_obj_set_width(ui_Screen2_Label_PM_mode, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen2_Label_PM_mode, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen2_Label_PM_mode, 0);
    lv_obj_set_y(ui_Screen2_Label_PM_mode, -5);
    lv_obj_set_align(ui_Screen2_Label_PM_mode, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_Screen2_Label_PM_mode, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(ui_Screen2_Label_PM_mode, " ");

    ui_Screen2_Label_Pointing_Mode = lv_label_create(ui_Screen2_Panel_Pointing_Mode);
    lv_obj_set_width(ui_Screen2_Label_Pointing_Mode, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen2_Label_Pointing_Mode, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen2_Label_Pointing_Mode, 0);
    lv_obj_set_y(ui_Screen2_Label_Pointing_Mode, 15);
    lv_obj_set_align(ui_Screen2_Label_Pointing_Mode, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen2_Label_Pointing_Mode, "POINTING MODE");
    lv_obj_set_style_text_align(ui_Screen2_Label_Pointing_Mode, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Screen2_Label_Pointing_Mode, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label_Pointing_Mode, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen2_Label_CPI = lv_label_create(ui_Screen2_Panel_Pointing_Mode);
    lv_obj_set_width(ui_Screen2_Label_CPI, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen2_Label_CPI, LV_SIZE_CONTENT);    /// 1
    #if (defined(KEYBOARD_zerfstudios_douballz_rev1))
        lv_obj_set_x(ui_Screen2_Label_CPI, 5);
        lv_obj_set_y(ui_Screen2_Label_CPI, 12);
        lv_obj_set_style_text_font(ui_Screen2_Label_CPI, &ui_font_Futura18, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_align(ui_Screen2_Label_CPI, LV_ALIGN_CENTER);
    #elif (defined(KEYBOARD_zerfstudios_douballz_rev2))
        lv_obj_set_x(ui_Screen2_Label_CPI, 0);
        lv_obj_set_y(ui_Screen2_Label_CPI, 35);
        lv_obj_set_style_text_font(ui_Screen2_Label_CPI, &ui_font_Futura24, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_align(ui_Screen2_Label_CPI, LV_ALIGN_CENTER);
    #endif
    lv_obj_set_style_text_align(ui_Screen2_Label_CPI, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Screen2, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Screen2_Label_CPI, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Screen2_deflayer, ui_event_dflayer_dropdown, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen2_Label_PM_mode, ui_pm_state_change, USER_EVENT_PM_STATE_CHANGE, NULL);
    lv_obj_add_event_cb(ui_Screen2_led1, ui_pm_state_change, USER_EVENT_PM_SIDE_CHANGE, NULL);
    lv_obj_add_event_cb(ui_Screen2_led2, ui_pm_state_change, USER_EVENT_PM_SIDE_CHANGE, NULL);
    lv_obj_add_event_cb(ui_Screen2_Panel_Layer, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
    lv_obj_add_event_cb(ui_Screen2_Panel_Pointing_Mode, ui_render_rgbhue_redraw, USER_EVENT_RGBHUE_UPDATE, NULL);
}

void lvgl_event_triggers(void) {
    static uint32_t last_dl_state   = 0;
    bool dl_state_redraw = false;
    if (last_dl_state != default_layer_state) {
        last_dl_state   = default_layer_state;
        dl_state_redraw = true;
    }
    if (dl_state_redraw) {
        lv_event_send(ui_Screen2_deflayer, USER_EVENT_DF_LAYER_CHANGE, NULL);
    }
    static uint16_t last_cpi   = 0xFFFF;
    uint16_t curr_cpi   = user_state.split_pointing_mode == 2 ? charybdis_get_pointer_sniping_dpi() : charybdis_get_pointer_default_dpi();
    bool cpi_redraw = false;
    if (last_cpi != curr_cpi) {
        last_cpi   = curr_cpi;
        cpi_redraw = true;
    }
    if (cpi_redraw) {
        lv_event_send(ui_Screen2_Label_CPI, USER_EVENT_CPI_UPDATE, NULL);
    }
    bool            wpm_redraw      = false;
    static uint32_t last_wpm_update = 0;
    if (timer_elapsed32(last_wpm_update) > 125) {
        last_wpm_update = timer_read32();
        wpm_redraw      = true;
    }
    if (wpm_redraw) {
        lv_event_send(ui_Screen1_Label_WPM, USER_EVENT_WPM_UPDATE, NULL);
    }
    bool            rgb_effect_redraw = false;
    static uint16_t last_effect       = 0xFFFF;
    uint8_t         curr_effect       = rgb_matrix_config.mode;
    if (last_effect != curr_effect) {
        last_effect       = curr_effect;
        rgb_effect_redraw = true;
    }
    if (rgb_effect_redraw) {
        lv_event_send(ui_Screen1_Label_RGB, USER_EVENT_RGBMODE_UPDATE, NULL);
    }
    bool          hue_redraw = false;
    static uint16_t last_hue       = 0xFFFF;
    uint16_t         curr_hue       = rgb_matrix_get_hue();
    if (last_hue != curr_hue) {
        last_hue       = curr_hue;
        hue_redraw = true;
    }
    if (hue_redraw) {
        lv_event_send(ui_Screen2_Panel_Layer, USER_EVENT_RGBHUE_UPDATE, NULL);
        lv_event_send(ui_Screen2_Panel_Pointing_Mode, USER_EVENT_RGBHUE_UPDATE, NULL);
        lv_event_send(ui_Screen1, USER_EVENT_RGBHUE_UPDATE, NULL);
        lv_event_send(ui_Screen1_Label_H, USER_EVENT_RGBHUE_UPDATE, NULL);
    }
    bool          sat_redraw = false;
    static uint16_t last_sat      = 0;
    uint16_t        curr_sat      = rgb_matrix_get_sat();
    if (last_sat != curr_sat) {
        last_sat  = curr_sat;
        sat_redraw = true;
    }
    if (sat_redraw) {
        lv_event_send(ui_Screen1_Label_S, USER_EVENT_RGBSAT_UPDATE, NULL);
    }
    bool          val_redraw = false;
    static uint16_t last_val       = 0;
    uint16_t        curr_val       = rgb_matrix_get_val();
    if (last_val != curr_val) {
        last_val  = curr_val;
        val_redraw = true;
    }
    if (val_redraw) {
        lv_event_send(ui_Screen1_Label_V, USER_EVENT_RGBVAL_UPDATE, NULL);
    }
    bool            layer_state_redraw = false;
    static uint32_t last_layer_state   = 0;
    if (last_layer_state != layer_state) {
        last_layer_state   = layer_state;
        layer_state_redraw = true;
    }
    if (layer_state_redraw) {
        lv_event_send(ui_Layer_Indicator, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
        lv_event_send(ui_Screen2_Label_Layer, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
    }
    bool            pm_state_redraw = false;
    static uint8_t last_pm_state   = 0;
    if (last_pm_state != user_state.split_pointing_mode) {
        last_pm_state  = user_state.split_pointing_mode;
        pm_state_redraw = true;
    }
    if (pm_state_redraw ) {
        lv_event_send(ui_Screen2_Label_PM_mode, USER_EVENT_PM_STATE_CHANGE, NULL);
        lv_event_send(ui_Screen2_Panel_Pointing_Mode, USER_EVENT_PM_STATE_CHANGE, NULL);
    }
    static bool pm_side_redraw = false;
    bool            last_pm_side   = 1;
    if (last_pm_side != user_state.pointing_side) {
        last_pm_side  = user_state.pointing_side;
        pm_side_redraw = true;
    }
    if (pm_side_redraw) {
        lv_event_send(ui_Screen2_led1, USER_EVENT_PM_SIDE_CHANGE, NULL);
        lv_event_send(ui_Screen2_led2, USER_EVENT_PM_SIDE_CHANGE, NULL);
    }
    if MODS_ALT {
        _ui_state_modify(ui_Screen1_Label_ALT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Screen1_Label_ALT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_CTRL {
        _ui_state_modify(ui_Screen1_Label_CTRL, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Screen1_Label_CTRL, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_GUI {
        _ui_state_modify(ui_Screen1_Label_GUI, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Screen1_Label_GUI, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if MODS_SHIFT {
        _ui_state_modify(ui_Screen1_Label_SHIFT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Screen1_Label_SHIFT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    if (autocorrect_is_enabled()) {
        _ui_state_modify(ui_Screen1_Label_ACRT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    } else {
        _ui_state_modify(ui_Screen1_Label_ACRT, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
    }
    static bool led_state_redraw = false;
    static led_t last_led_state = {0};
    if (last_led_state.raw != host_keyboard_led_state().raw) {
        last_led_state.raw = host_keyboard_led_state().raw;
        led_state_redraw = true;
    }
    if (led_state_redraw) {
        if (host_keyboard_led_state().caps_lock) {
            _ui_state_modify(ui_Screen1_Label_CAPS, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Screen1_Label_CAPS, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if (host_keyboard_led_state().num_lock) {
            _ui_state_modify(ui_Screen1_Label_NMLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Screen1_Label_NMLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if (host_keyboard_led_state().scroll_lock) {
            _ui_state_modify(ui_Screen1_Label_SCLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Screen1_Label_SCLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
    static bool user_state_redraw = false;
    static user_runtime_config_t last_user_state = {0};
    if (last_user_state.raw != user_state.raw) {
        last_user_state.raw  = user_state.raw;
        user_state_redraw = true;
    }
    if (user_state_redraw) {
        if (user_state.audio_enable) {
            _ui_state_modify(ui_Screen1_Label_AUDIO, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Screen1_Label_AUDIO, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if (user_state.audio_clicky_enable) {
            _ui_state_modify(ui_Screen1_Label_CLICKY, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Screen1_Label_CLICKY, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        // if (is_autocorrect_on()) {
        //     _ui_state_modify(ui_Screen1_Label_SCLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        // } else {
        //     _ui_state_modify(ui_Screen1_Label_SCLK, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        // }
     }

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
        lv_disp_load_scr(ui_Screen1);
    }
    // lv_disp_load_scr(ui_Screen1);
    if (!is_keyboard_left()) {
        lv_disp_load_scr(ui_Screen2);
    }
}
