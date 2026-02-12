#include <stdio.h>
#include "zerf9.h"
#include "freznel.h"
#include "qp.h"
#include "qp_ssd1351.h"


#include "graphics/matrix.qgf.c"
#include "graphics/zerfstudios1.qgf.c"
#include "graphics/test-anim.qgf.c"
#include "graphics/thintel.qff.c"
#include "graphics/iosevka11.qff.c"
#include "graphics/lock-caps-ON.qgf.c"
#include "graphics/lock-scrl-ON.qgf.c"
#include "graphics/cg_on.qgf.c"
#include "graphics/cg_off.qgf.c"
#include "graphics/lock-num-ON.qgf.c"
#include "graphics/lock-caps-OFF.qgf.c"
#include "graphics/lock-scrl-OFF.qgf.c"
#include "graphics/lock-num-OFF.qgf.c"

painter_device_t ssd1351;

static painter_image_handle_t zerfstudios1;
static painter_font_handle_t thintel;
static painter_font_handle_t iosevka11;
static painter_image_handle_t lock_caps_on;
static painter_image_handle_t lock_caps_off;
static painter_image_handle_t lock_num_on;
static painter_image_handle_t lock_num_off;
static painter_image_handle_t lock_scrl_on;
static painter_image_handle_t lock_scrl_off;
static painter_image_handle_t cg_on;
static painter_image_handle_t cg_off;


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


void ui_init(void) {
    zerfstudios1    = qp_load_image_mem(gfx_zerfstudios1);
    lock_caps_on    = qp_load_image_mem(gfx_lock_caps_ON);
    lock_caps_off   = qp_load_image_mem(gfx_lock_caps_OFF);
    lock_num_on     = qp_load_image_mem(gfx_lock_NUM_ON);
    lock_num_off    = qp_load_image_mem(gfx_lock_NUM_OFF);
    lock_scrl_on    = qp_load_image_mem(gfx_lock_scrl_ON);
    lock_scrl_off   = qp_load_image_mem(gfx_lock_scrl_off);
    cg_on           = qp_load_image_mem(gfx_cg_on);
    cg_off          = qp_load_image_mem(gfx_cg_off);
    thintel         = qp_load_font_mem(font_thintel);
    iosevka11       = qp_load_font_mem(font_iosevka11);

    qp_init(ssd1351, QP_ROTATION_270);
    qp_rect(ssd1351, 0, 0, 127, 127, 0, 0, 0, true);
    qp_flush(ssd1351);
}


void ui_task(void) {
    bool            hue_redraw = false, cpi_redraw = false;
    static uint16_t last_hue   = 0xFFFF;
    uint8_t         curr_hue   = rgb_matrix_get_hue();
    static uint16_t last_cpi   = 0xFFFF;
    uint16_t        curr_cpi   = charybdis_get_pointer_sniping_enabled() ? charybdis_get_pointer_sniping_dpi() : charybdis_get_pointer_default_dpi();
    uint16_t width;
    uint16_t height;
    qp_get_geometry(ssd1351, &width, &height, NULL, NULL, NULL);

    if (last_hue != curr_hue) {
        last_hue   = curr_hue;
        hue_redraw = true;
    }
    if (last_cpi != curr_cpi) {
        last_cpi   = curr_cpi;
        cpi_redraw = true;
    }

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

    bool            ds_state_redraw = false;
    static uint32_t last_ds_state   = 0;
    if (last_ds_state != charybdis_get_pointer_dragscroll_enabled()) {
        last_ds_state   = charybdis_get_pointer_dragscroll_enabled();
        ds_state_redraw = true;
    }


    bool            sp_state_redraw = false;
    static uint32_t last_sp_state   = 0;
    if (last_sp_state != charybdis_get_pointer_sniping_enabled()) {
        last_sp_state  = charybdis_get_pointer_sniping_enabled();
        sp_state_redraw = true;
    }

    bool            am_state_redraw = false;
    static uint32_t last_am_state   = 0;
    if (last_am_state != charybdis_get_auto_mouse_enabled()) {
        last_am_state = charybdis_get_auto_mouse_enabled();
        am_state_redraw = true;
    }

    bool            wpm_redraw      = false;
    static uint32_t last_wpm_update = 0;
    if (timer_elapsed32(last_wpm_update) > 125) {
        last_wpm_update = timer_read32();
        wpm_redraw      = true;
    }

    bool            scan_redraw      = false;
    static uint32_t last_scan_update = 0;
    if (timer_elapsed32(last_scan_update) > 125) {
        last_scan_update = timer_read32();
        scan_redraw      = true;
    }

#if defined(RGB_MATRIX_ENABLE)
    bool            rgb_effect_redraw = false;
    static uint16_t last_effect       = 0xFFFF;
    uint8_t         curr_effect       = rgb_matrix_config.mode;
    if (last_effect != curr_effect) {
        last_effect       = curr_effect;
        rgb_effect_redraw = true;
    }
#endif
    int yrpos = 13;
    if (!is_keyboard_left()) {
        char buf[32] = {0};
        int  xpos    = 5;
        // if (hue_redraw) {
        //     qp_drawimage_recolor(ssd1351, 0, 128 - zerfstudios1->height,  zerfstudios1, curr_hue, 255, 255, curr_hue, 255, 0);
        // }

        yrpos += iosevka11->line_height + 4;
        if (hue_redraw || wpm_redraw) {
            static int max_wpm_xpos = 0;
            xpos                    = 5;
            snprintf_(buf, sizeof(buf), "WPM: %d", (int)get_current_wpm());
            xpos += qp_drawtext_recolor(ssd1351, xpos, yrpos, iosevka11, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_wpm_xpos < xpos) {
                max_wpm_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, yrpos, max_wpm_xpos, yrpos + iosevka11->line_height, 0, 0, 0, true);

        }

        yrpos += iosevka11->line_height + 4;
        if (hue_redraw || scan_redraw) {
            static int max_scans_xpos = 0;
            xpos                      = 5;
            snprintf_(buf, sizeof(buf), "SCANS: %d", (int)get_matrix_scan_rate());
            xpos += qp_drawtext_recolor(ssd1351, xpos, yrpos, iosevka11, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_scans_xpos < xpos) {
                max_scans_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, yrpos, max_scans_xpos, yrpos + iosevka11->line_height, 0, 0, 0, true);
        }

        yrpos += iosevka11->line_height + 4;
        if (hue_redraw || ds_state_redraw) {
            static int max_dss_xpos = 0;
            xpos                    = 5;
            const char* buf = charybdis_get_pointer_dragscroll_enabled() ? "DS:ACTIVE" : "DS:OFF";
            xpos += qp_drawtext_recolor(ssd1351, xpos, yrpos, iosevka11, buf, charybdis_get_pointer_dragscroll_enabled() ? 153 : 255, 255, 255, charybdis_get_pointer_dragscroll_enabled() ? 153 : 255, 255, 0);
            if (max_dss_xpos < xpos) {
                max_dss_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, yrpos, max_dss_xpos, yrpos + iosevka11->line_height, 0, 0, 0, true);

        }


        if (hue_redraw || am_state_redraw) {
            static int max_ams_xpos = 0;
            xpos                    = 5 + (qp_textwidth(iosevka11, "DS: ACTIVE"));
            const char* buf = charybdis_get_auto_mouse_enabled() ? "AM:ACTIVE" : "AM:OFF";
            xpos += qp_drawtext_recolor(ssd1351, xpos, yrpos, iosevka11, buf, charybdis_get_auto_mouse_enabled()  ? 34 : 255, 255, 255, charybdis_get_pointer_sniping_enabled() ? 34 : 255, 255, 0);
            if (max_ams_xpos < xpos) {
                max_ams_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, yrpos, max_ams_xpos, yrpos + iosevka11->line_height, 0, 0, 0, true);

        }

        yrpos += iosevka11->line_height + 4;
        if (hue_redraw || sp_state_redraw) {
            static int max_sps_xpos = 0;
            xpos                    = 5;
            const char* buf = charybdis_get_pointer_sniping_enabled() ? "SN:ACTIVE" : "SN:OFF";
            xpos += qp_drawtext_recolor(ssd1351, xpos, yrpos, iosevka11, buf, charybdis_get_pointer_sniping_enabled() ? 153 : 255, 255, 255, charybdis_get_pointer_sniping_enabled() ? 153 : 255, 255, 0);
            if (max_sps_xpos < xpos) {
                max_sps_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, yrpos, max_sps_xpos, yrpos + iosevka11->line_height, 0, 0, 0, true);

        }



        static led_t last_led_state = {0};
        if (hue_redraw || last_led_state.raw != host_keyboard_led_state().raw) {
            last_led_state.raw = host_keyboard_led_state().raw;
            qp_drawimage_recolor(ssd1351, 128 - (32 * 3), 0, last_led_state.caps_lock ? lock_caps_on : lock_caps_off, curr_hue, 255, last_led_state.caps_lock ? 255 : 32, curr_hue, 255, 0);
            qp_drawimage_recolor(ssd1351, 128 - (32 * 2), 0, last_led_state.num_lock ? lock_num_on : lock_num_off, curr_hue, 255, last_led_state.num_lock ? 255 : 32, curr_hue, 255, 0);
            qp_drawimage_recolor(ssd1351, 128 - (32 * 1), 0, last_led_state.scroll_lock ? lock_scrl_on : lock_scrl_off, curr_hue, 255, last_led_state.scroll_lock ? 255 : 32, curr_hue, 255, 0);
        }

        static keymap_config_t last_keymap_config = {0};
        if (hue_redraw || last_keymap_config.raw != keymap_config.raw) {
            last_keymap_config.raw = keymap_config.raw;
            static int max_bpm_xpos = 0;
            xpos                    = cg_off->width;
            yrpos                    = 128 - (cg_off->height);
            const char* buf = "NKRO ";
            const char* buf1 = "CRCT ";
            const char* buf2 = "1SHOT ";
            // snprintf(buf, sizeof(buf), );
            // snprintf(buf1, sizeof(buf1), "CRCT");
            // snprintf(buf2, sizeof(buf2), "1SHOT");
            // snprintf(buf3, sizeof(buf3), "SWAP");
            qp_drawimage(ssd1351, 0, yrpos, last_keymap_config.swap_lctl_lgui ? cg_on : cg_off);
            xpos += qp_drawtext_recolor(ssd1351, xpos, yrpos, iosevka11, buf, last_keymap_config.nkro? 153 : 255, 255, 255, last_keymap_config.nkro ? 153 : 255, 255, 0);
            //xpos += qp_drawtext_recolor(ssd1351, xpos, yrpos, iosevka11, buf1, last_keymap_config.autocorrect_enable? 153 : 255, 255, 255, last_keymap_config.autocorrect_enable ? 153 : 255, 255, 0);
            xpos += qp_drawtext_recolor(ssd1351, xpos, yrpos, iosevka11, buf2, last_keymap_config.oneshot_enable? 153 : 255, 255, 255, last_keymap_config.oneshot_enable ? 153 : 255, 255, 0);
            if (max_bpm_xpos < xpos) {
                max_bpm_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, yrpos, max_bpm_xpos, yrpos + iosevka11->line_height, 0, 0, 0, true);

        }
    }

    int ypos = 0;
    if (is_keyboard_left()) {
        char buf[32] = {0};
        int  xpos    = 5;

        if (hue_redraw)  {
        qp_drawimage_recolor(ssd1351, 0, 128 - zerfstudios1->height,  zerfstudios1, curr_hue, 255, 255, curr_hue, 255, 0);
        }

        ypos += iosevka11->line_height;
        if (hue_redraw || rgb_effect_redraw) {
            static int max_rgb_xpos = 0;
            xpos                    = 5;
            snprintf_(buf, sizeof(buf), "RGB: %s", rgb_matrix_name(curr_effect));

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

            xpos += qp_drawtext_recolor(ssd1351, xpos, ypos, thintel, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_rgb_xpos < xpos) {
                max_rgb_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, ypos, max_rgb_xpos, ypos + iosevka11->line_height, 0, 0, 0, true);
        }

        ypos += iosevka11->line_height + 4;
        if (hue_redraw || dl_state_redraw) {
            const char *dl_name = "unknown";
            switch (get_highest_layer(default_layer_state)) {
                case _COLEMAK_DH:
                    dl_name = "COLEMAK_DH";
                    break;
                case _COLEMAK:
                    dl_name = "COLEMAK";
                    break;
                case _QWERTY:
                    dl_name = "QWERTY:";
                    break;
                case _DVORAK:
                    dl_name = "DVORAK";
                    break;
            }

            static int max_layer_xpos = 0;
            xpos                      = 5;
            snprintf_(buf, sizeof(buf), "LAYOUT: %s", dl_name);
            xpos += qp_drawtext_recolor(ssd1351, xpos, ypos, iosevka11, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_layer_xpos < xpos) {
                max_layer_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, ypos, max_layer_xpos, ypos + iosevka11->line_height, 0, 0, 0, true);

        }

        ypos += iosevka11->line_height + 4;
        if (hue_redraw || layer_state_redraw) {
            const char *layer_name = "default";
            switch (get_highest_layer(layer_state)) {
                case _MOUSE:
                    layer_name = "mouse";
                    break;
                case _LOWER:
                    layer_name = "lower";
                    break;
                case _RAISE:
                    layer_name = "raise";
                    break;
                case _ADJUST:
                    layer_name = "adjust";
                    break;
                case _KEYPAD:
                    layer_name = "keypad";
                case _MEDIA:
                    layer_name = "keypad";
                    break;
            }

            static int max_layer_xpos = 0;
            xpos                      = 5;
            snprintf_(buf, sizeof(buf), "LAYER: %s", layer_name);
            xpos += qp_drawtext_recolor(ssd1351, xpos, ypos, iosevka11, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_layer_xpos < xpos) {
                max_layer_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, ypos, max_layer_xpos, ypos + iosevka11->line_height, 0, 0, 0, true);

        }

        ypos += iosevka11->line_height + 4;
        if (hue_redraw || cpi_redraw) {
            static int max_cpi_xpos = 0;
            xpos                      = 5;
            snprintf_(buf, sizeof(buf), "CPI: %d", (int)charybdis_get_pointer_sniping_enabled() ? charybdis_get_pointer_sniping_dpi() : charybdis_get_pointer_default_dpi());
            xpos += qp_drawtext_recolor(ssd1351, xpos, ypos, iosevka11, buf, curr_hue, 255, 255, curr_hue, 255, 0);
            if (max_cpi_xpos < xpos) {
                max_cpi_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, ypos, max_cpi_xpos, ypos + iosevka11->line_height, 0, 0, 0, true);
        }


        ypos += iosevka11->line_height + 4;
        static user_runtime_config_t last_user_state = {0};
        if (hue_redraw || last_user_state.raw != user_state.raw) {
            last_user_state.raw = user_state.raw;
            static int max_upm_xpos = 0;
            xpos                    = qp_textwidth(iosevka11, "CLCK");
            ypos                    = 128 - (iosevka11->line_height);
            const char* buf = "AUD ";
            const char* buf1 = "CLCK ";
            const char* buf2 = "HOST ";
            const char* buf3 = "SWAP ";
            qp_drawtext_recolor(ssd1351, 0, ypos, iosevka11, buf, last_user_state.audio_enable? 153 : 255, 255, 255, last_user_state.audio_enable ? 153 : 255, 255, 0);
            xpos += qp_drawtext_recolor(ssd1351, xpos, ypos, iosevka11, buf1, last_user_state.audio_clicky_enable ? 153 : 255, 255, 255, last_user_state.audio_clicky_enable ? 153 : 255, 255, 0);
            xpos += qp_drawtext_recolor(ssd1351, xpos, ypos, iosevka11, buf2, last_user_state.host_driver_disabled ? 153 : 255, 255, 255, last_user_state.host_driver_disabled ? 153 : 255, 255, 0);
            xpos += qp_drawtext_recolor(ssd1351, xpos, ypos, iosevka11, buf3, last_user_state.swap_hands ? 153 : 255, 255, 255, last_user_state.swap_hands ? 153 : 255, 255, 0);
            if (max_upm_xpos < xpos) {
                max_upm_xpos = xpos;
            }
            qp_rect(ssd1351, xpos, ypos, max_upm_xpos, ypos + iosevka11->line_height, 0, 0, 0, true);
        }
    }
    qp_flush(ssd1351);

}

