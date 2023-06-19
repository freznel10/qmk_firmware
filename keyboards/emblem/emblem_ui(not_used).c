
#include <qp.h>
#include <qp_draw.h>
#include <stdio.h>
#include "ctype.h"
#include "pointing_device.h"
//#include <qp_gc9a01.h>
// #include "qp_gc9a01.h"
// #include "graphics/matrix.qgf.c"
//#include "graphics/ters1.qgf.c"
#include "graphics/zerfstudios1.qgf.c"
// #include "graphics/finger.qgf.c"
#include "graphics/emblem.qgf.c"
#include "graphics/bastard.qgf.c"
#include "graphics/noun-mouse-scroll2.qgf.c"
#include "graphics/noun-mouse-scroll.qgf.c"
#include "graphics/noun-target.qgf.c"
#include "graphics/noun-target2.qgf.c"
#include "graphics/layer_lower.qgf.c"
#include "graphics/layer_upper.qgf.c"
#include "graphics/layer_numpad.qgf.c"
#include "graphics/layer_adjust.qgf.c"
#include "graphics/trackball.qgf.c"
#include "graphics/caps_lock_icon.qgf.c"
// #include "graphics/test-anim.qgf.c"
// #include "graphics/loading.qgf.c"
#include "graphics/thintel.qff.c"
#include "graphics/iosevka11.qff.c"
#include "graphics/futurabold.qff.c"
// #include "graphics/lock-caps-ON.qgf.c"
// #include "graphics/lock-scrl-ON.qgf.c"
// #include "graphics/cg_on.qgf.c"
// #include "graphics/cg_off.qgf.c"
// #include "graphics/lock-num-ON.qgf.c"
// #include "graphics/lock-caps-OFF.qgf.c"
// #include "graphics/lock-scrl-OFF.qgf.c"
// #include "graphics/lock-num-OFF.qgf.c"
#include "./drivers/painter/generic/qp_rgb565_surface.c"



#ifdef UNICODE_COMMON_ENABLE
#    include "process_unicode_common.h"
#    include "keyrecords/unicode.h"
#endif
#ifdef AUDIO_CLICKY
#    include "process_clicky.h"
#endif
#if defined(AUTOCORRECTION_ENABLE)
#    include "keyrecords/autocorrection/autocorrection.h"
#endif
#include <string.h>

#define FRAMEBUFFER_W 240
#define FRAMEBUFFER_H 240


//painter_device_t qp_display;
painter_device_t qp_display;
static painter_device_t surface;
static uint16_t surface_buffer[FRAMEBUFFER_W * FRAMEBUFFER_H];


//painter_image_handle_t ters1;
static painter_image_handle_t zerfstudios1;
static painter_image_handle_t mouse_scroll;
static painter_image_handle_t mouse_scroll2;
static painter_image_handle_t mouse_sniping;
static painter_image_handle_t mouse_sniping2;
static painter_image_handle_t layer_lower;
static painter_image_handle_t layer_upper;
static painter_image_handle_t logo;
static painter_image_handle_t layer_numpad;
static painter_image_handle_t layer_mouse;
static painter_image_handle_t layer_adjust;
static painter_image_handle_t caps_lock_icon;
static painter_font_handle_t thintel;
static painter_font_handle_t iosevka11;
static painter_font_handle_t futurabold;
//static painter_image_handle_t bastard;
//static deferred_token matrix_anim;
// static painter_image_handle_t lock_caps_on;
// static painter_image_handle_t lock_caps_off;
// // static painter_image_handle_t lock_num_on;
// // static painter_image_handle_t lock_num_off;
// // static painter_image_handle_t lock_scrl_on;
// // static painter_image_handle_t lock_scrl_off;
// static painter_image_handle_t cg_on;
// static painter_image_handle_t cg_off;
// //static painter_image_handle_t matrix;
// static painter_image_handle_t test_anim;


#define MODS_SHIFT ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
#define MODS_CTRL  ((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL)
#define MODS_ALT   ((get_mods() | get_oneshot_mods()) & MOD_MASK_ALT)
#define MODS_GUI   ((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI)

//----------------------------------------------------------
// Keylogger

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
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
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

bool process_record_painter(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode, record);
    }
    return true;
}





//----------------------------------------------------------
// RGB Matrix naming
#include <rgb_matrix.h>

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

// double rad=0.01745;
// int angle;

// int sx=120;
// int sy=120;
// int r=76;

// float x[360];
// float y[360];

// int chosenOne=0;
// int minValue[6]={0,20,0,0,0,80};
// int maxValue[6]={40,100,60,80,70,160};
// int dbounce=0;

// void setup(void) {
//   int i=0;
//   int a=136;

//   while(a!=44)
//   {
//    x[i]=r*cos(rad*a)+sx;
//    y[i]=r*sin(rad*a)+sy;

//    i++;
//    a++;
//     if(a==360){
//         a=0;
//     }
//   }
// }

// //min angle 136 or 137
// //max angle 43

// int a1,a2;
// int result=0;

// void loop(void) {
// result=((int)get_current_wpm());
// angle=result;

//  a1=angle-4;
//  a2=angle+4;

// if(a1<0) {
//     a1=angle-4+359;}


// if(a2>=359){
//     a2=angle+4-359;}

// // qp_circle(qp_display, x[angle], y[angle], 10, 5, 255, 0, true);

// if(result<=(0)) {
//     qp_circle(surface, x[angle], y[angle+2], 10, 0, 0, 0, true);
// } else if (result>=(240)) {
//     qp_circle(surface, x[angle], y[angle-2], 10, 0, 0, 0, true);
// } else {
//     qp_clear(surface);
//     qp_circle(surface, x[angle], y[angle], 10, 234, 209, 123, true);
// }
// qp_rgb565_surface_draw(surface, qp_display, 0, 0);
// }

void init_and_clear(painter_device_t device, painter_rotation_t rotation) {
    uint16_t width;
    uint16_t height;
    qp_get_geometry(device, &width, &height, NULL, NULL, NULL);
    qp_init(device, rotation);
    qp_rect(device, 0, 0, width, height, 0, 0, 0, true);
}

void ui_init(void) {
    zerfstudios1 = qp_load_image_mem(gfx_zerfstudios1);
#if defined LOGO_BASTARD
    logo = qp_load_image_mem(gfx_bastard);
#else
    logo = qp_load_image_mem(gfx_emblem);
#endif
    mouse_sniping = qp_load_image_mem(gfx_noun_target);
    mouse_sniping2 = qp_load_image_mem(gfx_noun_target2);
    mouse_scroll = qp_load_image_mem(gfx_noun_mouse_scroll);
    mouse_scroll2 = qp_load_image_mem(gfx_noun_mouse_scroll2);
    layer_lower = qp_load_image_mem(gfx_layer_lower);
    layer_upper = qp_load_image_mem(gfx_layer_upper);
    layer_adjust = qp_load_image_mem(gfx_layer_adjust);
    layer_numpad = qp_load_image_mem(gfx_layer_numpad);
    layer_mouse = qp_load_image_mem(gfx_trackball);
    caps_lock_icon = qp_load_image_mem(gfx_caps_lock_icon);
    //bastard = qp_load_image_mem(gfx_bastard);
    // lock_caps_on  = qp_load_image_mem(gfx_lock_caps_ON);
    // lock_caps_off = qp_load_image_mem(gfx_lock_caps_OFF);
    // // lock_num_on   = qp_load_image_mem(gfx_lock_NUM_ON);
    // // lock_num_off  = qp_load_image_mem(gfx_lock_NUM_OFF);
    // // // lock_scrl_on  = qp_load_image_mem(gfx_lock_scrl_ON);
    // // // lock_scrl_off = qp_load_image_mem(gfx_lock_scrl_off);
    // //matrix = qp_load_image_mem(gfx_matrix);
    // cg_on = qp_load_image_mem(gfx_cg_on);
    // cg_off  = qp_load_image_mem(gfx_cg_off);
    thintel = qp_load_font_mem(font_thintel);
    iosevka11 = qp_load_font_mem(font_iosevka11);
    futurabold = qp_load_font_mem(font_futurabold);


    qp_display = qp_gc9a01_make_spi_device(240, 240, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 8, 0);
    surface = qp_rgb565_make_surface(FRAMEBUFFER_W, FRAMEBUFFER_H, surface_buffer);
    init_and_clear(qp_display, QP_ROTATION_90);
    qp_init(surface, QP_ROTATION_90);
// #elif defined(KEYBOARD_emblem_rev2)
//     init_and_clear(qp_display, QP_ROTATION_270);
// #endif
    qp_clear(surface);
    qp_clear(qp_display);
    wait_ms(50);
    qp_power(qp_display, true);

}


void draw_ui_user(void) {
    static uint16_t last_hue   = 0xFFFF;
    uint8_t         curr_hue   = rgb_matrix_get_hue();
    static uint16_t last_cpi   = 0xFFFF;
    uint16_t        curr_cpi   = emblem_get_pointer_sniping_enabled() ? emblem_get_pointer_sniping_dpi() : emblem_get_pointer_default_dpi();
    uint16_t width;
    uint16_t height;
    qp_get_geometry(qp_display, &width, &height, NULL, NULL, NULL);


    bool hue_redraw = false;
    if (last_hue != curr_hue) {
        last_hue   = curr_hue;
        hue_redraw = true;
    }

    bool cpi_redraw = false;
    if (last_cpi != curr_cpi) {
        last_cpi   = curr_cpi;
        cpi_redraw = true;
    }

//     bool ctrlmod_state_redraw = false;
//     static uint32_t last_ctrlmod_state   = 0;
//     if (last_ctrlmod_state != MODS_CTRL) {
//         last_ctrlmod_state = MODS_CTRL;
//         ctrlmod_state_redraw = true;
//     }

//     bool sftmod_state_redraw = false;
//     static uint32_t last_sftmod_state   = 0;
//     if (last_sftmod_state != MODS_SHIFT ) {
//         last_sftmod_state = MODS_SHIFT ;
//         sftmod_state_redraw = true;
//     }

//     bool altmod_state_redraw = false;
//     static uint32_t last_altmod_state   = 0;
//     if (last_altmod_state != MODS_ALT) {
//         last_altmod_state = MODS_ALT;
//         altmod_state_redraw = true;
//     }

//     bool guimod_state_redraw = false;
//     static uint32_t last_guimod_state   = 0;
//     if (last_guimod_state != MODS_GUI) {
//         last_guimod_state = MODS_GUI ;
//         guimod_state_redraw = true;
//     }

    bool            layer_state_redraw = false;
    static uint32_t last_layer_state   = 0;
    if (last_layer_state != layer_state) {
        last_layer_state   = layer_state;
        layer_state_redraw = true;
    }

    bool            dl_state_redraw = false;
    static uint32_t last_dl_state   = 0;
    if (last_dl_state != default_layer_state) {
        last_dl_state   = default_layer_state;
        dl_state_redraw = true;
    }

    // bool            ds_state_redraw = false;
    // static uint32_t last_ds_state   = 0;
    // if (last_ds_state != emblem_get_pointer_dragscroll_enabled()) {
    //     last_ds_state   = emblem_get_pointer_dragscroll_enabled();
    //     ds_state_redraw = true;
    // }

    bool            ds_state_redraw = false;
    static uint32_t last_ds_state   = 0;
    if (last_ds_state != get_scroll_mode()) {
        last_ds_state   = get_scroll_mode();
        ds_state_redraw = true;
    }


    bool            sp_state_redraw = false;
    static uint32_t last_sp_state   = 0;
    if (last_sp_state != emblem_get_pointer_sniping_enabled()) {
        last_sp_state  = emblem_get_pointer_sniping_enabled();
        sp_state_redraw = true;
    }

//     bool            am_state_redraw = false;
//     static uint32_t last_am_state   = 0;
//     if (last_am_state != get_auto_mouse_state()) {
//         last_am_state = get_auto_mouse_state();
//         am_state_redraw = true;
//     }

    // bool            wpm_redraw      = false;
    // static uint32_t last_wpm_update = 0;
    // if (timer_elapsed32(last_wpm_update) > 125) {
    //     last_wpm_update = timer_read32();
    //     wpm_redraw      = true;
    // }

//     bool            scan_redraw      = false;
//     static uint32_t last_scan_update = 0;
//     if (timer_elapsed32(last_scan_update) > 125) {
//         last_scan_update = timer_read32();
//         scan_redraw      = true;
//     }

// #if defined(RGB_MATRIX_ENABLE)
//     bool            rgb_effect_redraw = false;
//     static uint16_t last_effect       = 0xFFFF;
//     uint8_t         curr_effect       = rgb_matrix_config.mode;
//     if (last_effect != curr_effect) {
//         last_effect       = curr_effect;
//         rgb_effect_redraw = true;
//     }
// #endif
    // if (hue_redraw) {
    //     // //  qp_drawimage_recolor(qp_display, 320 - zerfstudios1->width, 240 - zerfstudios1->height,  zerfstudios1, curr_hue, 255, 255, curr_hue, 255, 0);
    //     qp_drawimage(qp_display, 240 - logo->width, 240 - logo->height,  logo);
    //     // //  qp_rect(qp_display, 320 - zerfstudios1->width, (240 - zerfstudios1->height) - (finger->height + 16), 320, 240 - zerfstudios1->height, 0, 0, 0, true);
    //     // //  //qp_drawimage_recolor(qp_display, 320 - (zerfstudios1->width) + 32, (240 - zerfstudios1->height) - finger->height,  finger, curr_hue, 255, 255, curr_hue, 255, 0);
    //     // // qp_rect(qp_display, 320 - (zerfstudios1->width) + 32, (240 - zerfstudios1->height) - finger->height, 320, 240 - ((zerfstudios1->height) + (finger->height)), 0, 0, 0, true);

    // }

    // bool            kyl_redraw      = false;
    // static uint32_t last_kyl_update = 0;
    // if (timer_elapsed32(last_kyl_update) > 125) {
    //     last_kyl_update   = timer_read32();
    //     kyl_redraw      = true;
    // }

        char buf[32] = {0};
        int  xpos    = 5;

        // // int yrpos = 80;
        // if (hue_redraw || wpm_redraw) {
        //     // static int max_wpm_xpos = 0;
        //     // xpos                    = 5;
        //     // snprintf(buf, sizeof(buf), "WPM: %d", (int)get_current_wpm());
        //     // xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
        //     // if (max_wpm_xpos < xpos) {
        //     //     max_wpm_xpos = xpos;
        //     // }
        //     // qp_rect(surface, xpos, yrpos, max_wpm_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
        //     setup();
        //     loop();
        // }


        if (hue_redraw || layer_state_redraw ) {
            static painter_image_handle_t layer_name;
            switch (get_highest_layer(layer_state)) {
                case _COLEMAK_DH:
                    layer_name = logo;
                    break;
                case _MOUSE:
                    layer_name = layer_mouse;
                    break;
                case _LOWER:
                    layer_name = layer_lower;
                    break;
                case _RAISE:
                    layer_name = layer_upper;
                    break;
                case _ADJUST:
                    layer_name = layer_adjust;
                    break;
                case _KEYPAD:
                    layer_name = layer_numpad;
                    break;
                case _MEDIA:
                    layer_name = layer_upper;
                    break;

            }

            // static int max_layer_xpos = 0;
            // xpos                      = 7;
            // snprintf(buf, sizeof(buf), "LAYER: %s", layer_name);
            // xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            // if (max_layer_xpos < xpos) {
            //     max_layer_xpos = xpos;
            // }
            // qp_rect(qp_display, xpos, yrpos, max_layer_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
            qp_rect(surface, 60, 60, 240-60, 240-60, 0, 0, 0, true);
            qp_drawimage(surface, 60, 60,  layer_name);
            qp_rgb565_surface_draw(surface, qp_display, 0, 0);
        }



    if (hue_redraw || ds_state_redraw) {
        static painter_image_handle_t scroll_mode_name;
        switch (get_scroll_mode()) {
            case 1:
                scroll_mode_name = mouse_scroll;
                break;
            default:
                scroll_mode_name = mouse_scroll2;
        }
        xpos                    = 160;
        qp_drawimage(qp_display, xpos, 190, scroll_mode_name);
        qp_rgb565_surface_draw(surface, qp_display, xpos, 190);
        // qp_flush(qp_display);
    }



    if (hue_redraw || sp_state_redraw) {
        xpos                    = 190;
        qp_drawimage(qp_display, xpos, 150, emblem_get_pointer_sniping_enabled() ? mouse_sniping : mouse_sniping2);
        qp_rgb565_surface_draw(surface, qp_display, 0, 0);
        // qp_flush(qp_display);
    }


// //         yrpos += futurabold->line_height + 4;
//         if (hue_redraw || scan_redraw) {
//             static int max_scans_xpos = 0;
//             xpos                      = 5;
//             snprintf(buf, sizeof(buf), "SCANS: %d", (int)get_matrix_scan_rate());
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
//             if (max_scans_xpos < xpos) {
//                 max_scans_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_scans_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
//         }

//         yrpos += futurabold->line_height + 4;
//         if (hue_redraw || ds_state_redraw) {
//             static int max_dss_xpos = 0;
//             xpos                    = 5;
//             const char* buf = emblem_get_pointer_dragscroll_enabled() ? "DS:ACTIVE" : "DS:OFF";
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, emblem_get_pointer_dragscroll_enabled() ? 153 : 255, 255, 255, emblem_get_pointer_dragscroll_enabled() ? 153 : 255, 255, 0);
//             if (max_dss_xpos < xpos) {
//                 max_dss_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_dss_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
//         }



//         if (hue_redraw || am_state_redraw) {
//             static int max_ams_xpos = 0;
//             xpos                    = 5 + (qp_textwidth(futurabold, "DS: ACTIVE"));
//             const char* buf = get_auto_mouse_state() ? "AM:ACTIVE" : "AM:OFF";
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, get_auto_mouse_state() ? 34 : 255, 255, 255, get_auto_mouse_state() ? 34 : 255, 255, 0);
//             if (max_ams_xpos < xpos) {
//                 max_ams_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_ams_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);

//         }

//         yrpos += futurabold->line_height + 4;
//         if (hue_redraw || sp_state_redraw) {
//             static int max_sps_xpos = 0;
//             xpos                    = 5;
//             const char* buf = emblem_get_pointer_sniping_enabled() ? "SN:ACTIVE" : "SN:OFF";
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, emblem_get_pointer_sniping_enabled() ? 153 : 255, 255, 255, emblem_get_pointer_sniping_enabled() ? 153 : 255, 255, 0);
//             if (max_sps_xpos < xpos) {
//                 max_sps_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_sps_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);

//         }


        static led_t last_led_state = {0};
        if (hue_redraw || last_led_state.raw != host_keyboard_led_state().raw) {
            last_led_state.raw = host_keyboard_led_state().raw;
            // qp_rect(qp_display, 240 - (32 * 3), 0,(240- (32 * 3))+60, 60,255, 43, 43, true);
            qp_drawimage_recolor(surface, 240- (32 * 3), 0, caps_lock_icon, 0, 0, 0, last_led_state.caps_lock ? curr_hue : 0, last_led_state.caps_lock ? 255 : 0, last_led_state.caps_lock ? 255 : 0);
//         //     qp_drawimage_recolor(qp_display, 320 - (32 * 2), 0, last_led_state.num_lock ? lock_num_on : lock_num_off, curr_hue, 255, last_led_state.num_lock ? 255 : 32, curr_hue, 255, 0);
//         //     qp_drawimage_recolor(qp_display, 320 - (32 * 1), 0, last_led_state.scroll_lock ? lock_scrl_on : lock_scrl_off, curr_hue, 255, last_led_state.scroll_lock ? 255 : 32, curr_hue, 255, 0);
                qp_rgb565_surface_draw(surface, qp_display, 0, 0);
        }
        // qp_rect(qp_display, 240 - (32 * 3), 0,(240- (32 * 3))+60, 60,0, 0, 0, true);


//         yrpos += futurabold->line_height + 4;
//         if (hue_redraw || rgb_effect_redraw) {
//             static int max_rgb_xpos = 0;
//             xpos                    = 5;
//             snprintf(buf, sizeof(buf), "RGB: %s", rgb_matrix_name(curr_effect));

//             for (int i = 5; i < sizeof(buf); ++i) {
//                 if (buf[i] == 0)
//                     break;
//                 else if (buf[i] == '_')
//                     buf[i] = ' ';
//                 else if (buf[i - 1] == ' ')
//                     buf[i] = toupper(buf[i]);
//                 else if (buf[i - 1] != ' ')
//                     buf[i] = tolower(buf[i]);
//             }

//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
//             if (max_rgb_xpos < xpos) {
//                 max_rgb_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_rgb_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
//         }

        // yrpos = 210;
        if (hue_redraw || dl_state_redraw) {
            const char *dl_name = "unknown";
            switch (get_highest_layer(default_layer_state)) {
                case _COLEMAK_DH:
                    dl_name = "COLEMAK_DH";
                    break;
                case _COLEMAK:
                    dl_name = " COLEMAK  ";
                    break;
                case _QWERTY:
                    dl_name = "  QWERTY  ";
                    break;
                case _DVORAK:
                    dl_name = "  DVORAK  ";
                    break;
            }
            static int max_layer_xpos = 0;
            xpos                      = 70;
            snprintf(buf, sizeof(buf), "%s", dl_name);
            xpos += qp_drawtext_recolor(surface, xpos, (240 - ((futurabold->line_height * 2)) - 10), futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_layer_xpos < xpos) {
                max_layer_xpos = xpos;
            }
            qp_rect(surface, xpos, (240 - ((futurabold->line_height * 2)) - 10), max_layer_xpos, (240 - ((futurabold->line_height * 2)) - 10) + futurabold->line_height, 0, 0, 0, true);
            qp_rgb565_surface_draw(surface, qp_display, 0, 0);
        }

        // yrpos += futurabold->line_height + 4;


        // yrpos += futurabold->line_height + 4;
        if (hue_redraw || cpi_redraw) {
            static int max_cpi_xpos = 0;
            xpos                    = 90;
            snprintf(buf, sizeof(buf), "C: %d", (int)emblem_get_pointer_sniping_enabled() ? emblem_get_pointer_sniping_dpi() : emblem_get_pointer_default_dpi());
            xpos += qp_drawtext_recolor(surface, xpos, (240 - futurabold->line_height) - 5, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_cpi_xpos < xpos) {
                max_cpi_xpos = xpos;
            }
            qp_rect(surface, xpos, (240 - futurabold->line_height) - 5, max_cpi_xpos, (240 - futurabold->line_height) + futurabold->line_height, 0, 0, 0, true);
            qp_rgb565_surface_draw(surface, qp_display, 0, 0);
        }

        // yrpos += futurabold->line_height + 15;
        // if (hue_redraw || kyl_redraw) {
        //     static int max_kyl_xpos = 0;
        //     xpos                      = 20;
        //     snprintf(buf, sizeof(buf), "KYL: %s", keylog_str);
        //     xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, curr_hue, 255, 255, curr_hue, 255, 0);
        //     if (max_kyl_xpos < xpos) {
        //         max_kyl_xpos = xpos;
        //     }
        // //    qp_rect(qp_display, xpos, yrpos, max_kyl_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
        // }


//         yrpos += futurabold->line_height + 4;
//         if (hue_redraw || guimod_state_redraw) {
//             static int max_guimod_xpos = 0;
//             xpos                      = 5;
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, "|GUI|", MODS_GUI ? 34 : 255, 255, 255, MODS_GUI ? 34 : 255, 255, 0);
//             if (max_guimod_xpos < xpos) {
//                 max_guimod_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_guimod_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
//         }

//         if (hue_redraw || altmod_state_redraw) {
//             static int max_altmod_xpos = 0;
//             xpos                      = 5  + (qp_textwidth(futurabold, "|GUI| "));
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, "|ALT|", MODS_ALT  ? 34 : 255, 255, 255, MODS_ALT ? 34 : 255, 255, 0);
//             if (max_altmod_xpos < xpos) {
//                 max_altmod_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_altmod_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
//         }

//         if (hue_redraw || ctrlmod_state_redraw) {
//             static int max_ctrlmod_xpos = 0;
//             xpos                      = 5 + (qp_textwidth(futurabold, "|GUI| |ALT| "));;
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, "|CTRL|", MODS_CTRL  ? 34 : 255, 255, 255, MODS_CTRL ? 34 : 255, 255, 0);
//             if (max_ctrlmod_xpos < xpos) {
//                 max_ctrlmod_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_ctrlmod_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
//         }

//         if (hue_redraw || sftmod_state_redraw) {
//             static int max_sftmod_xpos = 0;
//             xpos                      = 5 + (qp_textwidth(futurabold, "|GUI| |ALT| |CTRL| "));
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, "|SHIFT|", MODS_SHIFT  ? 34 : 255, 255, 255, MODS_SHIFT? 34 : 255, 255, 0);
//             if (max_sftmod_xpos < xpos) {

//                 max_sftmod_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_sftmod_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
//         }

//         static keymap_config_t last_keymap_config = {0};
//         if (hue_redraw || last_keymap_config.raw != keymap_config.raw) {
//             last_keymap_config.raw = keymap_config.raw;
//             static int max_bpm_xpos = 0;
//             xpos                    = cg_off->width;
//             yrpos                    = 240 - (cg_off->height);
//             const char* buf = "NKRO ";
//             // const char* buf1 = "CRCT ";
//             const char* buf2 = "1SHOT ";
//             // snprintf(buf, sizeof(buf), );
//             // snprintf(buf1, sizeof(buf1), "CRCT");
//             // snprintf(buf2, sizeof(buf2), "1SHOT");
//             // snprintf(buf3, sizeof(buf3), "SWAP");
//             qp_drawimage(qp_display, 0, yrpos, last_keymap_config.swap_lctl_lgui ? cg_on : cg_off);
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf, last_keymap_config.nkro? 153 : 255, 255, 255, last_keymap_config.nkro ? 153 : 255, 255, 0);
//             //xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf1, last_keymap_config.autocorrect_enable? 153 : 255, 255, 255, last_keymap_config.autocorrect_enable ? 153 : 255, 255, 0);
//             xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf2, last_keymap_config.oneshot_enable? 153 : 255, 255, 255, last_keymap_config.oneshot_enable ? 153 : 255, 255, 0);
//             if (max_bpm_xpos < xpos) {
//                 max_bpm_xpos = xpos;
//             }
//             qp_rect(qp_display, xpos, yrpos, max_bpm_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);

//         }



//         //ypos += futurabold->line_height + 4;
//         // static user_runtime_config_t last_user_state = {0};
//         // if (hue_redraw || last_user_state.raw != user_state.raw) {
//         //     last_user_state.raw = user_state.raw;
//         //     static int max_upm_xpos = 0;
//         //     xpos                    = (qp_textwidth(futurabold, "NKRO, 1SHOT") + cg_off->width);
//         //     yrpos                    = 240 - (cg_off->height);
//         //     const char* buf = "AUD ";
//         //     const char* buf1 = "CLCK ";
//         //     const char* buf2 = "HOST ";
//         //     //const char* buf3 = "SWAP ";
//         //     qp_drawtext_recolor(qp_display, 0, yrpos, futurabold, buf, last_user_state.audio_enable? 153 : 255, 255, 255, last_user_state.audio_enable ? 153 : 255, 255, 0);
//         //     xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf1, last_user_state.audio_clicky_enable ? 153 : 255, 255, 255, last_user_state.audio_clicky_enable ? 153 : 255, 255, 0);
//         //     xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf2, last_user_state.host_driver_disabled ? 153 : 255, 255, 255, last_user_state.host_driver_disabled ? 153 : 255, 255, 0);
//         //     //xpos += qp_drawtext_recolor(qp_display, xpos, yrpos, futurabold, buf3, last_user_state.swap_hands ? 153 : 255, 255, 255, last_user_state.swap_hands ? 153 : 255, 255, 0);
//         //     if (max_upm_xpos < xpos) {
//         //         max_upm_xpos = xpos;
//         //     }
//         //     qp_rect(qp_display, xpos, yrpos, max_upm_xpos, yrpos + futurabold->line_height, 0, 0, 0, true);
//         // }
            qp_flush(qp_display);
}






