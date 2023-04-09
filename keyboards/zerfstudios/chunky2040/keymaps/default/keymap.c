#include QMK_KEYBOARD_H

enum Layers {
    _BASE = 0
    // _SYM  = 1,
    // _NAV  = 2,
    // _FN   = 3,
    // _RGB  = 4,
    // _GAME = 5,
};


// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_5x8_new(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_BTN1, KC_BTN2,            KC_BTN2, AU_TOG, KC_WH_U, _______, _______, _______, _______, RGB_TOG,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_Y,                                _______, _______, _______, _______, RGB_HUD, _______, _______,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_F,  KC_G,    KC_MUTE,            _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  _______, _______,            _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LGUI,  _______, _______, _______,       _______, _______, _______,            _______, _______, _______,          _______, _______, _______,_______
  )

};


static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_logo();
    } else {
        render_logo();
    }
    return false;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}


// uint8_t prng(void) {
//     static uint8_t s = 0xAA, a = 0;
//     s ^= s << 3;
//     s ^= s >> 5;
//     s ^= a++ >> 2;
//     return s;
// }

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard=true;
}

// void matrix_scan_user(void) {
//     static uint32_t last_eeprom_access = 0;
//     uint32_t        now                = timer_read32();
//     if (now - last_eeprom_access > 5000) {
//         dprint("reading eeprom\n");
//         last_eeprom_access = now;

//         union {
//             uint8_t  bytes[4];
//             uint32_t raw;
//         } tmp;
//         tmp.bytes[0] = prng();
//         tmp.bytes[1] = prng();
//         tmp.bytes[2] = prng();
//         tmp.bytes[3] = prng();

//         eeconfig_update_user(tmp.raw);
//         uint32_t value = eeconfig_read_user();
//         if (value != tmp.raw) {
//             dprint("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//             dprint("!! EEPROM readback mismatch!\n");
//             dprint("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         }
//     }
// }
