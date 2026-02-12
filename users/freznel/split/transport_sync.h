
// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2022 Freznel B. Sta. Ana  (@freznel10) <freznel@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "freznel.h"
#ifdef OLED_ENABLE
#    include "oled/oled_stuff.h"
extern char painter_keylog_str[OLED_KEYLOGGER_LENGTH];
#endif

#ifdef CUSTOM_KEYLOGGER
#define KEYLOGGER_LENGTH 8
extern char painter_keylog_str[KEYLOGGER_LENGTH];
#endif

typedef union {
    uint32_t raw;
    struct {
        bool    audio_enable         :1;
        bool    audio_clicky_enable  :1;
        bool    tap_toggling         :1;
        uint8_t unicode_mode         :3;
        bool    swap_hands           :1;
        bool    host_driver_disabled :1;
        uint8_t unicode_typing_mode  :3;
        uint8_t detected_os          :3;
        bool    is_oled_enabled      :1;
        bool    is_caps_word_on      :1;
        bool    pointing_side        :1;
        uint8_t split_pointing_mode  :4;
    };
} user_runtime_config_t;

extern user_runtime_config_t user_state;

void keyboard_post_init_transport_sync(void);
void housekeeping_task_transport_sync(void);
