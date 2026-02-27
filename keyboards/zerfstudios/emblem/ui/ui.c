// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"
#include "bindings/bindings.h"
#include "freznel.h"
#include "../zerfstudios/emblem/emblem.h"

#include "menu.h"
#include "dial_menu/dial_menu.h"
#include "settings/appr/appr.h"
#include "styles/styles.h"
#include "widgets/bpm.h"
#include "settings/screensaver/screensaver.h"

#if !defined(AUDIO_ENABLE)
static inline bool is_audio_on(void) {
    return false;
}
static inline bool is_clicky_on(void) {
    return false;
}
#endif




///////////////////// VARIABLES ////////////////////
extern uint8_t scroll_mode;
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Main1;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Arc1;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Layer1;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Arc3;
lv_obj_t * ui_dflayer_dropdown;
lv_obj_t * ui_Settings1;
lv_obj_t * ui_SettingsMain;
lv_obj_t * ui_Screen2;
lv_obj_t * ui_SettingsAux;
lv_obj_t * ui_Settings2;
lv_obj_t * ui_StatusPanel;
lv_obj_t * ui_Status_Sniping;
lv_obj_t * ui_Status_Dragscroll;
lv_obj_t * ui_Status_Caret;
lv_obj_t * ui_Status_Volume;
lv_obj_t * ui_Status_Audio;
lv_obj_t * ui_Status_Clicky;
lv_obj_t * ui_Status_Autocorrect;
lv_obj_t * meter;
lv_obj_t * mbox1;
lv_obj_t * mbox1_title;
lv_obj_t * mbox1_text;
lv_obj_t * mbox2;
lv_obj_t * mbox2_title;
lv_obj_t * mbox2_text;
lv_meter_indicator_t * indic3;

lv_timer_t* timer;

uint32_t USER_EVENT_DF_LAYER_CHANGE = 0;
uint32_t USER_EVENT_CPI_UPDATE = 1;
uint32_t USER_EVENT_WPM_UPDATE = 2;
uint32_t USER_EVENT_ACTIVE_LAYER_CHANGE = 3;
uint32_t USER_EVENT_PANEL_CHANGE = 4;



///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

void pulse_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 100);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_0, 0, 150);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 1);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_zoom);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 100);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_1, 150, 0);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 200);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 1);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_image_zoom);
    lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////

// static void poll_layer(lv_timer_t* timer) {
//     LV_UNUSED(timer);
//     lv_obj_t* ui_Layer1 = timer->user_data;

//     set_layer_text_value(qmk_lv_geT_layer(), ui_Layer1);
// }

// static void poll_cpi_text(lv_timer_t* timer) {
//     LV_UNUSED(timer);
//     lv_obj_t* ui_Arc3 = timer->user_data;

//    lv_arc_set_value(ui_Arc3, qmk_lv_get_cpi());
// }

// static void add_data(lv_timer_t* timer) {
//     LV_UNUSED(timer);
//     lv_obj_t* ui_Arc1 = timer->user_data;
// }
/*WPM RENDER*/
void ui_render_wpm(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_WPM_UPDATE) {
        lv_arc_set_value(ui_Arc1, qmk_lv_get_bpm());

    }
}

/*DEFAULT LAYER CHANGE*/
void set_layer_text_value(const char dl_name, lv_obj_t* ui_Layer1) {
    if (lv_obj_is_valid(ui_Layer1)) {
        char buf[5];
        const char *dl_name = "unknown";
        switch (get_highest_layer(default_layer_state)) {
            case 0:
                dl_name = "C_DH";
                break;
            case 1:
                dl_name = "C_MK";
                break;
            case 2:
                dl_name = "QWERTY";
                break;
            case 3:
                dl_name = "DVORAK";
                break;
        }
        snprintf(buf, sizeof(buf), "%s", dl_name);
        lv_label_set_text(ui_Layer1, buf);
    }
}

void ui_df_layer_change(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_DF_LAYER_CHANGE) {
        set_layer_text_value(qmk_lv_geT_layer(), ui_Layer1);
        dprintf("Default layer changed");
    }
}

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
    }
}

/*CPI*/
void set_cpi_text_value(uint16_t i, lv_obj_t* lbl) {
    if (lv_obj_is_valid(lbl)) {
        char buf[5];
        snprintf(buf, sizeof(buf), "%d", i);
        lv_label_set_text(lbl, buf);
    }
}

void ui_render_cpi(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_CPI_UPDATE) {
         set_cpi_text_value(qmk_lv_get_cpi(), ui_Label1);
         lv_arc_set_value(ui_Arc3, qmk_lv_get_cpi());
    }
}

/*ACTIVE LAYER CHANGE*/
void ui_active_layer_change(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == USER_EVENT_ACTIVE_LAYER_CHANGE) {
            switch (get_highest_layer(layer_state)) {
                case _COLEMAK_DH:
                    lv_img_set_src(ui_Image1, &ui_img_emblem_80_png);
                    break;
                case _MOUSE:
                    lv_img_set_src(ui_Image1, &ui_img_trackball_png);
                    break;
                case _LOWER:
                    lv_img_set_src(ui_Image1, &ui_img_lower_80_png);
                    break;
                case _RAISE:
                    lv_img_set_src(ui_Image1, &ui_img_raise_80_png);
                    break;
                case _ADJUST:
                    lv_img_set_src(ui_Image1, &ui_img_toolbox_80_png);
                case _KEYPAD:
                    lv_img_set_src(ui_Image1, &ui_img_numpad_80_png);
                    break;
                case _MEDIA:
                    lv_img_set_src(ui_Image1, &ui_img_emblem_80_png);
                    break;
                case _GAMEPAD:
                    lv_img_set_src(ui_Image1, &ui_img_controller80_png);
                    break;
                default:
                    lv_img_set_src(ui_Image1, &ui_img_numpad_80_png);
                    break;

            }
    }
}



// static void poll_cpi(lv_timer_t* timer) {
//     LV_UNUSED(timer);
//     lv_obj_t* ui_Label1 = timer->user_data;

//     set_cpi_text_value(qmk_lv_get_cpi(), ui_Label1);
// }


//----------------------------------------------------------
// Keylogger

// static const char PROGMEM code_to_name[256] = {
// //   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
//     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
//     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
//     '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
//     ']','\\', '#', ';','\'', '`', ',', '.', '/', 128,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,  // 3x
//     0xDB,0xDC,0xDD,0xDE,0XDF,0xFB,'P', 'S',  19, ' ',  17,  30,  16,  16,  31,  26,  // 4x
//      27,  25,  24, 'N', '/', '*', '-', '+',  23, '1', '2', '3', '4', '5', '6', '7',  // 5x
//     '8', '9', '0', '.','\\', 'A',   0, '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
//     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
//     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
//     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
//     ' ', ' ', ' ', ' ', ' ',   0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
//     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
//     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
//     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
//     'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  24,  26,  24,  // Ex
//      25,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,  24,  25,  27,  26, ' ', ' ', ' '   // Fx
// };


// #define KEYLOGGER_LENGTH 5
// uint32_t        display_timer                     = 0;
// char            keylog_str[KEYLOGGER_LENGTH] = {0};
// static uint16_t log_timer                         = 0;


// void add_keylog(uint16_t keycode, keyrecord_t *record) {
//     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
//         if (((keycode & 0xFF) == KC_BSPC) && mod_config(get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL) {
//             memset(keylog_str, ' ', KEYLOGGER_LENGTH);
//             return;
//         }
//         if (record->tap.count) {
//             keycode &= 0xFF;
//         } else if (keycode > 0xFF) {
//             return;
//         }
//     }
//     if (keycode > 0xFF) {
//         return;
//     }

//     memmove(keylog_str, keylog_str + 1, KEYLOGGER_LENGTH - 1);

//     if (keycode < (sizeof(code_to_name) / sizeof(char))) {
//         keylog_str[(KEYLOGGER_LENGTH - 1)] = pgm_read_byte(&code_to_name[keycode]);
//     }

//     log_timer = timer_read();
// }



// void set_keylogger(const char keylogger, lv_obj_t* ui_Label1) {
//     if (lv_obj_is_valid(ui_Label1)) {
//         char buf[5];
//         snprintf(buf, sizeof(buf), "%s", keylog_str);
//         lv_label_set_text(ui_Label1, buf);
//     }
// }


// static void poll_cpi(lv_timer_t* timer) {
//     LV_UNUSED(timer);
//     lv_obj_t* ui_Label1 = timer->user_data;
//     if (lv_obj_is_valid(ui_Label1)) {
//         char buf[5];
//         snprintf(buf, sizeof(buf), "%s", keylog_str);
//         lv_label_set_text(ui_Label1, buf);
//     }
// }

void ui_event_StatusPanel(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if(event_code == USER_EVENT_PANEL_CHANGE) {
        switch ((int)pointing_modes_get_mode()) {
        case 0:
            _ui_state_modify(ui_Status_Dragscroll, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
            _ui_state_modify(ui_Status_Caret, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
            _ui_state_modify(ui_Status_Volume, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
            _ui_state_modify(ui_Status_Sniping, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
            break;
        case 1:
            _ui_state_modify(ui_Status_Sniping, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
            break;
        case 2:
            _ui_state_modify(ui_Status_Dragscroll, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
            break;
        case 3:
            _ui_state_modify(ui_Status_Caret, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
            break;
        case 5:
            _ui_state_modify(ui_Status_Volume, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
            break;
        }
        if(is_audio_on()) {
            _ui_state_modify(ui_Status_Audio, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Status_Audio, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if(is_clicky_on()) {
            _ui_state_modify(ui_Status_Clicky, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Status_Clicky, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
        if(autocorrect_is_enabled()) {
            _ui_state_modify(ui_Status_Autocorrect, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Status_Autocorrect  , LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        }
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void) {

    if (timer != NULL) {
        lv_timer_del(timer);
        timer = NULL;
    }
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1, lv_color_hex(0xCBC90F), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Main1 = lv_obj_create(ui_Screen1);
    lv_obj_clear_flag(ui_Main1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Main1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Main1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Main1, lv_color_hex(0xCBC90F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_x(ui_Main1, 0);
    lv_obj_set_y(ui_Main1, 0);
    lv_obj_set_width(ui_Main1, 240);   /// 81
    lv_obj_set_height(ui_Main1, 240);    /// 55
    lv_obj_set_align(ui_Main1, LV_ALIGN_CENTER);
    lv_obj_set_style_border_side(ui_Main1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image1 = lv_img_create(ui_Main1);
    lv_obj_add_event_cb(ui_Image1, ui_active_layer_change, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
    lv_img_set_src(ui_Image1, &ui_img_emblem_80_png);
    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 81
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 55
    lv_obj_set_x(ui_Image1, 0);
    lv_obj_set_y(ui_Image1, -42);
    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);

    ui_Arc1 = lv_arc_create(ui_Main1);
    lv_obj_set_width(ui_Arc1, 200);
    lv_obj_set_height(ui_Arc1, 200);
    lv_obj_set_x(ui_Arc1, 0);
    lv_obj_set_y(ui_Arc1, 0);
    lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);

    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0xDC81EF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_Arc1, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xF4F385), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_arc_set_range(ui_Arc1, 0, 200);

    // timer = lv_timer_create(add_data, 100, ui_Arc1);

    // ui_Panel1 = lv_obj_create(ui_Screen1);
    // lv_obj_set_width(ui_Panel1, 80);
    // lv_obj_set_height(ui_Panel1, 20);
    // lv_obj_set_x(ui_Panel1, 0);
    // lv_obj_set_y(ui_Panel1, 20);
    // lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    // lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // ui_Layer1 = lv_label_create(ui_Panel1);
    // lv_obj_set_width(ui_Layer1, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Layer1, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_align(ui_Layer1, LV_ALIGN_CENTER);
    // lv_obj_set_style_text_align(ui_Layer1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_Layer1, &ui_font_Font12, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_grad_color(ui_Layer1, lv_color_hex(0xDD2C2C), LV_PART_MAIN | LV_STATE_DEFAULT);
    // // timer = lv_timer_create(poll_layer, 100, ui_Layer1);
    // lv_obj_add_event_cb(ui_Layer1, ui_df_layer_change, USER_EVENT_DF_LAYER_CHANGE, NULL);

    ui_Panel2 = lv_obj_create(ui_Main1);
    lv_obj_set_width(ui_Panel2, 80);
    lv_obj_set_height(ui_Panel2, 20);
    lv_obj_set_x(ui_Panel2, 0);
    lv_obj_set_y(ui_Panel2, 110);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label1 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_Label1, &ui_font_Font12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_Label1, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);
    // timer = lv_timer_create(poll_cpi, 100, ui_Label1);


    ui_Arc3 = lv_arc_create(ui_Main1);
    lv_obj_set_width(ui_Arc3, 235);
    lv_obj_set_height(ui_Arc3, 235);
    lv_obj_set_align(ui_Arc3, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Arc3, 200, 3400);
    lv_obj_add_event_cb(ui_Arc3, ui_render_cpi, USER_EVENT_CPI_UPDATE, NULL);
    // timer = lv_timer_create(poll_cpi_text, 100, ui_Arc3);

    ui_Settings1 = lv_btn_create(ui_Main1);
    lv_obj_set_width(ui_Settings1, 80);
    lv_obj_set_height(ui_Settings1, 20);
    lv_obj_set_x(ui_Settings1, 0);
    lv_obj_set_y(ui_Settings1, 60);
    lv_obj_set_align(ui_Settings1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Settings1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // if (lv_scr_act() == ui_Screen2) {
    //     lv_obj_add_flag(ui_Settings1, LV_OBJ_FLAG_HIDDEN);
    // } else {
    //     lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_HIDDEN);
    // }
    lv_obj_set_style_bg_color(ui_Settings1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Settings1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Settings1, lv_color_hex(0xFE0000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_opa(ui_Settings1, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui_Settings1, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_spread(ui_Settings1, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    // lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLLABLE);
    // lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    // lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_CLICKABLE);

    ui_SettingsMain = lv_label_create(ui_Settings1);
    lv_obj_set_width(ui_SettingsMain, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SettingsMain, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SettingsMain, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingsMain, "SETTINGS");
    lv_obj_set_style_text_color(ui_SettingsMain, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SettingsMain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SettingsMain, &ui_font_Font12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_SettingsMain, lv_color_hex(0xFF0505), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_SettingsMain, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    // lv_obj_clear_flag(ui_SettingsMain, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_SettingsMain, LV_OBJ_FLAG_SCROLLABLE);
    // lv_obj_clear_flag(ui_SettingsMain, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    // lv_obj_clear_flag(ui_SettingsMain, LV_OBJ_FLAG_CLICKABLE);



    ui_StatusPanel = lv_obj_create(ui_Main1);
    lv_obj_set_width(ui_StatusPanel, 125);
    lv_obj_set_height(ui_StatusPanel, 55);
    lv_obj_set_x(ui_StatusPanel, 0);
    lv_obj_set_y(ui_StatusPanel, 25);
    lv_obj_set_align(ui_StatusPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_StatusPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_StatusPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_StatusPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_StatusPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_StatusPanel, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StatusPanel, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Status_Sniping = lv_label_create(ui_StatusPanel);
    lv_obj_set_width(ui_Status_Sniping, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Status_Sniping, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Status_Sniping, -50);
    lv_obj_set_y(ui_Status_Sniping, -14);
    lv_obj_set_align(ui_Status_Sniping, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Status_Sniping, FBS_ICON_SNIPING);
    lv_obj_set_style_text_color(ui_Status_Sniping, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Status_Sniping, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Status_Sniping, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Status_Sniping, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_Status_Sniping, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Status_Dragscroll = lv_label_create(ui_StatusPanel);
    lv_obj_set_width(ui_Status_Dragscroll, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Status_Dragscroll, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Status_Dragscroll, -20);
    lv_obj_set_y(ui_Status_Dragscroll, -14);
    lv_obj_set_align(ui_Status_Dragscroll, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Status_Dragscroll, FBS_ICON_DRAGSCROLL);
    lv_obj_set_style_text_color(ui_Status_Dragscroll, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Status_Dragscroll, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Status_Dragscroll, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Status_Dragscroll, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_Status_Dragscroll, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Status_Caret = lv_label_create(ui_StatusPanel);
    lv_obj_set_width(ui_Status_Caret, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Status_Caret, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Status_Caret, 20);
    lv_obj_set_y(ui_Status_Caret, -14);
    lv_obj_set_align(ui_Status_Caret, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Status_Caret, FBS_ICON_CARET);
    lv_obj_set_style_text_color(ui_Status_Caret, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Status_Caret, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Status_Caret, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Status_Caret, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_Status_Caret, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Status_Volume = lv_label_create(ui_StatusPanel);
    lv_obj_set_width(ui_Status_Volume, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Status_Volume, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Status_Volume, 50);
    lv_obj_set_y(ui_Status_Volume, -14);
    lv_obj_set_align(ui_Status_Volume, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Status_Volume, FBS_ICON_VOLUME);
    lv_obj_set_style_text_color(ui_Status_Volume, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Status_Volume, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Status_Volume, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Status_Volume, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_Status_Volume, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Status_Audio = lv_label_create(ui_StatusPanel);
    lv_obj_set_width(ui_Status_Audio, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Status_Audio, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Status_Audio, -50);
    lv_obj_set_y(ui_Status_Audio, 9);
    lv_obj_set_align(ui_Status_Audio, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Status_Audio, FBS_ICON_HP);
    lv_obj_set_style_text_color(ui_Status_Audio, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Status_Audio, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Status_Audio, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Status_Audio, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_Status_Audio, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Status_Clicky = lv_label_create(ui_StatusPanel);
    lv_obj_set_width(ui_Status_Clicky, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Status_Clicky, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Status_Clicky, -20);
    lv_obj_set_y(ui_Status_Clicky, 9);
    lv_obj_set_align(ui_Status_Clicky, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Status_Clicky, FBS_ICON_BELL);
    lv_obj_set_style_text_color(ui_Status_Clicky, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Status_Clicky, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Status_Clicky, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Status_Clicky, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_Status_Clicky, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_Status_Autocorrect = lv_label_create(ui_StatusPanel);
    lv_obj_set_width(ui_Status_Autocorrect, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Status_Autocorrect, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Status_Autocorrect, 20);
    lv_obj_set_y(ui_Status_Autocorrect, 9);
    lv_obj_set_align(ui_Status_Autocorrect, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Status_Autocorrect, FBS_ICON_CHECK);
    lv_obj_set_style_text_color(ui_Status_Autocorrect, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Status_Autocorrect, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Status_Autocorrect, &extra_symbols, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Status_Autocorrect, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui_Status_Autocorrect, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

//     meter = lv_meter_create(ui_Screen1);
//     lv_obj_center(meter);
//     lv_obj_set_size(meter, 200, 200);

//     /*Remove the circle from the middle*/
//     lv_obj_remove_style(meter, NULL, LV_PART_INDICATOR);

//     /*Add a scale first*/
//     lv_meter_scale_t * scale = lv_meter_add_scale(meter);
//     // lv_meter_set_scale_ticks(meter, scale, 11, 2, 10, lv_palette_main(LV_PALETTE_GREY));
//     // lv_meter_set_scale_major_ticks(meter, scale, 1, 2, 30, lv_color_hex3(0xeee), 15);
//     lv_meter_set_scale_range(meter, scale, 0, 300, 270, 90);

//     /*Add a three arc indicator*/
//     // lv_meter_indicator_t * indic1 = lv_meter_add_arc(meter, scale, 10, lv_palette_main(LV_PALETTE_RED), 0);
//     // lv_meter_indicator_t * indic2 = lv_meter_add_arc(meter, scale, 10, lv_palette_main(LV_PALETTE_GREEN), -10);
//     indic3 = lv_meter_add_arc(meter, scale, 10, lv_palette_main(LV_PALETTE_BLUE), -20);
//  lv_obj_add_event_cb(meter, ui_render_wpm, USER_EVENT_WPM_UPDATE, NULL);



    ui_Screen2 = lv_obj_create(ui_Screen1);
    lv_obj_add_flag(ui_Screen2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(ui_Screen2, 240);
    lv_obj_set_height(ui_Screen2, 240);
    lv_obj_set_x(ui_Screen2, 0);
    lv_obj_set_y(ui_Screen2, 0);
    lv_obj_set_align(ui_Screen2, LV_ALIGN_CENTER);
    lv_obj_set_style_border_side(ui_Screen2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
   /// Flags

    lv_obj_t* background = lv_obj_create(ui_Screen2);

    lv_obj_set_size(background, 240, 240);
    lv_obj_set_style_border_width(background, 0, 0);
    lv_obj_set_style_pad_all(background, 0, 0);
    lv_obj_center(background);

    lv_obj_add_style(background, &style_main_screen, 0);

    ui_dflayer_dropdown = lv_dropdown_create(ui_Main1);
    static const char * opts = "CLMK_DH\n"
                               "COLEMAK\n"
                               "QWERTY\n"
                               "DVORAK";
    lv_dropdown_set_options_static(ui_dflayer_dropdown, opts);
    lv_obj_set_width(ui_dflayer_dropdown, 80);
    lv_obj_set_height(ui_dflayer_dropdown, 25);
    lv_obj_set_x(ui_dflayer_dropdown, 0);
    lv_obj_set_y(ui_dflayer_dropdown, 85);
    lv_obj_set_align(ui_dflayer_dropdown, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_SCROLLABLE);
    // if (lv_scr_act() == ui_Screen2) {
    //     lv_obj_add_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
    // } else {
    //     lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
    // }
    lv_obj_set_style_text_align(ui_dflayer_dropdown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_dflayer_dropdown, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_dflayer_dropdown, &ui_font_Font12, LV_PART_MAIN | LV_STATE_DEFAULT);


    lv_obj_add_event_cb(ui_dflayer_dropdown, ui_event_dflayer_dropdown, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_StatusPanel, ui_event_StatusPanel, USER_EVENT_PANEL_CHANGE, NULL);
    lv_obj_add_event_cb(ui_Settings1, ui_event_Settings1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Arc1, ui_render_wpm, USER_EVENT_WPM_UPDATE, NULL);

}

// void ui_Screen2_screen_init(void)
// {
//     ui_Screen2 = lv_obj_create(ui_Screen1);
//     lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_width(ui_Screen2, 240);
//     lv_obj_set_height(ui_Screen2, 240);
//     lv_obj_set_x(ui_Screen2, 0);
//     lv_obj_set_y(ui_Screen2, 0);
//     lv_obj_set_align(ui_Screen2, LV_ALIGN_CENTER);
//    /// Flags

//     lv_obj_t* background = lv_obj_create(ui_Screen2);

//     lv_obj_set_size(background, 240, 240);
//     lv_obj_set_style_border_width(background, 0, 0);
//     lv_obj_set_style_pad_all(background, 0, 0);
//     lv_obj_center(background);

//     lv_obj_add_style(background, &style_main_screen, 0);


// //     ui_SettingsAux = lv_btn_create(ui_Screen2);
// //     lv_obj_set_width(ui_SettingsAux, 20);
// //     lv_obj_set_height(ui_SettingsAux, 20);
// //     lv_obj_set_x(ui_SettingsAux, -50);
// //     lv_obj_set_y(ui_SettingsAux, -20);
// //     lv_obj_set_align(ui_SettingsAux, LV_ALIGN_CENTER);
// //     lv_obj_add_flag(ui_SettingsAux, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
// //     lv_obj_clear_flag(ui_SettingsAux, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
// //     lv_obj_set_style_bg_color(ui_SettingsAux, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
// //     lv_obj_set_style_bg_opa(ui_SettingsAux, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
// //     lv_obj_set_style_text_align(ui_SettingsAux, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
// //     lv_obj_set_style_text_font(ui_SettingsAux, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);
// //     // lv_obj_add_event_cb(ui_SettingsAux, screen_loader, LV_EVENT_PRESSED, NULL);


// //     ui_Settings2 = lv_label_create(ui_SettingsAux);
// //     lv_obj_set_width(ui_Settings2, LV_SIZE_CONTENT);   /// 1
// //     lv_obj_set_height(ui_Settings2, LV_SIZE_CONTENT);    /// 1
// //     lv_obj_set_align(ui_Settings2, LV_ALIGN_CENTER);
// //     lv_obj_set_style_text_color(ui_Settings2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
// //     lv_obj_set_style_text_opa(ui_Settings2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
// //     lv_obj_set_style_text_color(ui_Settings2, lv_color_hex(0x11A200), LV_PART_MAIN | LV_STATE_PRESSED);
// //     lv_obj_set_style_text_opa(ui_Settings2, 255, LV_PART_MAIN | LV_STATE_PRESSED);
// //     lv_obj_set_style_text_font(ui_Settings2, &ui_font_Font12, LV_PART_MAIN | LV_STATE_PRESSED);
// //     lv_obj_set_style_text_color(ui_Settings2, lv_color_hex(0xCB0006), LV_PART_MAIN | LV_STATE_FOCUSED);
// //     lv_obj_set_style_text_opa(ui_Settings2, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
// //     lv_obj_set_style_text_font(ui_Settings2, &ui_font_Font12, LV_PART_MAIN | LV_STATE_FOCUSED);

// //     lv_obj_add_event_cb(ui_SettingsAux, ui_event_SettingsAux, LV_EVENT_ALL, NULL);
// }



#if defined(AUTOCORRECT_ENABLE) && defined(AUDIO_ENABLE)
// #    ifdef USER_SONG_LIST

// float autocorrect_song[][2] = SONG(MARIO_GAMEOVER);
// #    else
float autocorrect_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
// #    endif
bool apply_autocorrect(uint8_t backspaces, const char *str) {
    PLAY_SONG(autocorrect_song);
    return true;
}

float violin_song[][2] = SONG(VIOLIN_SOUND);

void caps_word_set_user(bool active) {
    if (active) {
        PLAY_SONG(autocorrect_song);
        mbox1 = lv_msgbox_create(NULL, "CAPS WORD", "ACTIVE", NULL, false);// Do something when Caps Word activates.
        mbox1_title = lv_msgbox_get_title(mbox1);
        mbox1_text = lv_msgbox_get_text(mbox1);
        lv_obj_set_style_text_font(mbox1_title, &ui_font_Font16, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(mbox1_text, &ui_font_Font16, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_x(mbox1_title, 0);
        lv_obj_set_style_text_align(mbox1_title, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_set_x(mbox1_text, 0);
        lv_obj_set_style_text_align(mbox1_text, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_set_style_text_color(mbox1_text, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_center(mbox1);
        lv_obj_center(mbox1_title);
        lv_obj_center(mbox1_text);
    } else {
        PLAY_SONG(violin_song);// Do something when Caps Word deactivates.
        lv_msgbox_close(mbox1);
    }
}
#endif



void lvgl_event_triggers(void) {
    static uint32_t last_dl_state   = 0;
    bool dl_state_redraw = false;
    if (last_dl_state != default_layer_state) {
        last_dl_state   = default_layer_state;
        dl_state_redraw = true;
    }
    if (dl_state_redraw) {
        lv_event_send(ui_dflayer_dropdown, USER_EVENT_DF_LAYER_CHANGE, NULL);
    }
    static uint16_t last_cpi   = 0xFFFF;
    uint16_t curr_cpi   = emblem_get_pointer_sniping_enabled() ? emblem_get_pointer_sniping_dpi() : emblem_get_pointer_default_dpi();
    bool cpi_redraw = false;
    if (last_cpi != curr_cpi) {
        last_cpi   = curr_cpi;
        cpi_redraw = true;
    }
    if (cpi_redraw) {
        lv_event_send(ui_Label1, USER_EVENT_CPI_UPDATE, NULL);
    }
    bool            wpm_redraw      = false;
    static uint32_t last_wpm_update = 0;
    if (timer_elapsed32(last_wpm_update) > 125) {
        last_wpm_update = timer_read32();
        wpm_redraw      = true;
    }
    if (wpm_redraw) {
        lv_event_send(ui_Arc1, USER_EVENT_WPM_UPDATE, NULL);
        // lv_event_send(meter, USER_EVENT_WPM_UPDATE, NULL);
    }
    // #if defined(RGB_MATRIX_ENABLE)
    // bool            rgb_effect_redraw = false;
    // static uint16_t last_effect       = 0xFFFF;
    // uint8_t         curr_effect       = rgb_matrix_config.mode;
    // if (last_effect != curr_effect) {
    //     last_effect       = curr_effect;
    //     rgb_effect_redraw = true;
    // }
    // #endif
    bool            layer_state_redraw = false;
    static uint32_t last_layer_state   = 0;
    if (last_layer_state != layer_state) {
        last_layer_state   = layer_state;
        layer_state_redraw = true;
    }
    if (layer_state_redraw) {
        lv_event_send(ui_Image1, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
    }
    bool            scroll_state_redraw = false;
    static uint8_t last_scroll_state   = 0;
    if (last_scroll_state != pointing_modes_get_mode()) {
        last_scroll_state  = pointing_modes_get_mode();
        scroll_state_redraw = true;
    }
    bool            audio_state_redraw = false;
    static uint8_t last_audio_state   = 0;
    if (last_audio_state != is_audio_on()) {
        last_audio_state  = is_audio_on();
        audio_state_redraw = true;
    }
    bool            clicky_state_redraw = false;
    static uint8_t last_clicky_state   = 0;
    if (last_clicky_state != is_clicky_on()) {
        last_clicky_state  = is_clicky_on();
        clicky_state_redraw = true;
    }
    bool            autocorrect_state_redraw = false;
    static uint8_t last_autocorrect_state   = 0;
    if (last_autocorrect_state != autocorrect_is_enabled()) {
        last_autocorrect_state  = autocorrect_is_enabled();
        autocorrect_state_redraw = true;
    }
    if (scroll_state_redraw || audio_state_redraw || clicky_state_redraw || autocorrect_state_redraw ) {
        lv_event_send(ui_StatusPanel, USER_EVENT_PANEL_CHANGE, NULL);
    }

}

// void lvgl_control_led_indicators(void)
// {
//     /*Create a LED and switch it OFF*/
//     lv_obj_t * led1  = lv_led_create(lv_scr_act());
//     lv_obj_align(led1, LV_ALIGN_CENTER, -80, 0);
//     lv_led_off(led1);

//     /*Copy the previous LED and set a brightness*/
//     lv_obj_t * led2  = lv_led_create(lv_scr_act());
//     lv_obj_align(led2, LV_ALIGN_CENTER, 80, 0);
//     lv_led_set_brightness(led2, 150);
//     lv_led_set_color(led2, lv_palette_main(LV_PALETTE_RED));

//     /*Copy the previous LED and switch it ON*/
//     lv_obj_t * led3  = lv_led_create(lv_scr_act());
//     lv_obj_align(led3, LV_ALIGN_CENTER, 80, 0);
//     lv_led_on(led3);
// }
bool lvgl_control = 0;

void disable_lvgl() {
    lvgl_control = false;
}


void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    // ui_Screen2_screen_init();
    lv_disp_load_scr(ui_Screen1);
    lv_obj_clear_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Settings1, LV_OBJ_FLAG_CLICKABLE);

    init_menu();

    // lv_disp_load_scr(ui_Screen2);

    init_dial_menu(ui_Screen2);
    create_dial_menu(ui_Screen2, &root);
    // _ui_flag_modify(ui_Screen2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

    // init_layer_widget();


}

// void screen_loader(lv_event_t * e) {
//     lv_event_code_t code = lv_event_get_code(e);
//     lv_obj_t * btn = lv_event_get_target(e);
//     if(code == LV_EVENT_PRESSED && btn == ui_Settings1) {
//         lv_disp_load_scr(ui_Screen2);
//     }
//     if(code == LV_EVENT_PRESSED && btn == ui_SettingsAux) {
//         lv_disp_load_scr(ui_Screen1);
//     }
// }

void ui_event_Settings1(lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_dflayer_dropdown, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(ui_Settings1, LV_OBJ_FLAG_SCROLLABLE);

        // lv_obj_add_flag(ui_Settings1, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(ui_SettingsMain, LV_OBJ_FLAG_HIDDEN);
        // _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
    }
}
// void ui_event_SettingsAux(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     // lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_PRESSED) {
//         _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }

bool process_record_painter(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case POINTER_DEFAULT_DPI_FORWARD:
            if (record->event.pressed) {
                mbox2 = lv_msgbox_create(NULL, "DPI", "MOD+", NULL, false);// Do something when Caps Word activates.
                mbox2_title = lv_msgbox_get_title(mbox2);
                mbox2_text = lv_msgbox_get_text(mbox2);
                lv_obj_set_style_text_font(mbox2_title, &ui_font_Font16, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(mbox2_text, &ui_font_Font16, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_x(mbox2_title, 0);
                lv_obj_set_style_text_align(mbox2_title, LV_TEXT_ALIGN_CENTER, 0);
                lv_obj_set_x(mbox2_text, 0);
                lv_obj_set_style_text_align(mbox2_text, LV_TEXT_ALIGN_CENTER, 0);
                lv_obj_set_style_text_color(mbox2_text, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_center(mbox2);
                lv_obj_center(mbox2_title);
                lv_obj_center(mbox2_text);
                break;
            }
            wait_ms(500);
            lv_msgbox_close(mbox2);
            break;
        case POINTER_DEFAULT_DPI_REVERSE:
            if (record->event.pressed) {
                mbox2 = lv_msgbox_create(NULL, "DPI", "MOD-", NULL, false);
                mbox2_title = lv_msgbox_get_title(mbox2);
                mbox2_text = lv_msgbox_get_text(mbox2);
                lv_obj_set_style_text_font(mbox2_title, &ui_font_Font16, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(mbox2_text, &ui_font_Font16, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_x(mbox2_title, 0);
                lv_obj_set_style_text_align(mbox2_title, LV_TEXT_ALIGN_CENTER, 0);
                lv_obj_set_x(mbox2_text, 0);
                lv_obj_set_style_text_align(mbox2_text, LV_TEXT_ALIGN_CENTER, 0);
                lv_obj_set_style_text_color(mbox2_text, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_center(mbox2);
                lv_obj_center(mbox2_title);
                lv_obj_center(mbox2_text);
                break;
            }
            wait_ms(500);
            lv_msgbox_close(mbox2);
            break;
    }
    return true;
}
