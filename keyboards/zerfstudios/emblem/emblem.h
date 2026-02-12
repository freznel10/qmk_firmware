/* Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2020-2022 Christopher Courtney, aka Drashna Jael're <drashna@live.com> (@drashna)
 * Copyright 2021-2022 Sadek Baroudi <sadekbaroudi@gmail.com> <@sadekbaroudi>
 * Copyright 2022 Freznel B. Sta. Ana <freznel@gmail.com> (@freznel10)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"
#include "pointing_device.h"
#ifdef QUANTUM_PAINTER_ENABLE
#include <qp.h>
#endif

// #if defined (KEYBOARD_emblem_rev2)
// #   include "rev2.h"
// #elif defined(KEYBOARD_emblem_rev1)
// #   include "rev1.h"
// #endif

#pragma pack(push)
#pragma pack(1)

#ifdef QUANTUM_PAINTER_ENABLE
extern painter_device_t qp_display;
typedef struct kb_runtime_config {
    unsigned          lcd_power : 1;
} kb_runtime_config;
#endif

#pragma pack(pop)

extern kb_runtime_config kb_state;

enum emblem_keycodes {
    POINTER_DEFAULT_DPI_FORWARD = SAFE_RANGE,  // Increase trackpad default DPI
    POINTER_DEFAULT_DPI_REVERSE,              // Decrease trackpad default DPI
    POINTER_SNIPING_DPI_FORWARD,              // Increase trackpad sniping DPI
    POINTER_SNIPING_DPI_REVERSE,              // Decrease trackpad sniping DPI
    RGB_TOG1,
    SNIPING_MODE,
    SNIPING_MODE_TOGGLE,
    DRAGSCROLL_MODE,
    DRAGSCROLL_MODE_TOGGLE,
    AUTO_MOUSE_LAYER_TOGGLE,
    LVGL_CLOCKWISE,
    LVGL_COUNTER_CLOCKWISE,
    LVGL_ENCODER_BUTTON,
    LVGL_CONTROL_NEXT,
    LVGL_CONTROL_PREV,
    LVGL_CONTROL_LEFT,
    LVGL_CONTROL_RIGHT,
    LVGL_CONTROL_ENTER,
    LO_RES_DOWN,
    LO_RES_UP,
    KEYMAP_SAFE_RANGE,
};
#        define EMBLEM_SAFE_RANGE KEYMAP_SAFE_RANGE
#        define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#        define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#        define S_D_MOD POINTER_SNIPING_DPI_FORWARD
#        define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#        define SNIPING SNIPING_MODE
#        define SNP_TOG SNIPING_MODE_TOGGLE
#        define DRGSCRL DRAGSCROLL_MODE
#        define DRG_TOG DRAGSCROLL_MODE_TOGGLE
#        define AML_TOG AUTO_MOUSE_LAYER_TOGGLE

#ifdef POINTING_DEVICE_ENABLE
/*Adapted from drashna's tractly code and 0xcharly's charybdis code*/

/** \brief Return the current DPI value for the pointer's default mode. */
uint16_t emblem_get_pointer_default_dpi(void);

/**
 * \brief Update the pointer's default DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to EMBLEM_DEFAULT_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void emblem_cycle_pointer_default_dpi(bool forward);

/**
 * \brief Same as `emblem_cycle_pointer_default_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void emblem_cycle_pointer_default_dpi_noeeprom(bool forward);

/** \brief Return the current DPI value for the pointer's sniper-mode. */
uint16_t emblem_get_pointer_sniping_dpi(void);

/**
 * \brief Update the pointer's sniper-mode DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to EMBLEM_SNIPING_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void emblem_cycle_pointer_sniping_dpi(bool forward);

/**
 * \brief Same as `emblem_cycle_pointer_sniping_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void emblem_cycle_pointer_sniping_dpi_noeeprom(bool forward);

/** \brief Whether sniper-mode is enabled. */
bool emblem_get_pointer_sniping_enabled(void);

/**
 * \brief Enable/disable sniper mode.
 *
 * When sniper mode is enabled the dpi is reduced to slow down the pointer for
 * more accurate movements.
 */
void emblem_set_pointer_sniping_enabled(bool enable);

/** \brief Whether drag-scroll is enabled. */
bool emblem_get_pointer_dragscroll_enabled(void);

/**
 * \brief Enable/disable drag-scroll mode.
 *
 * When drag-scroll mode is enabled, horizontal and vertical pointer movements
 * are translated into horizontal and vertical scroll movements.
 */
void emblem_set_pointer_dragscroll_enabled(bool enable);
#endif  // POINTING_DEVICE_ENABLE

/**
 * \brief Cycles through keylight and underglow if the normal RGB matrix mode is activated.
 *
 */
void rgb_matrix_increase_flags(void);

/**
 * \brief Sends events to LGVL objects
 */
void lvgl_event_triggers(void);

