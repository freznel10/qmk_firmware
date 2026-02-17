/*
Copyright 2021-2022 Rocco Meli <@RMeli>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keyrecords/tap_dances.h"

// + ---------- +
// + TAP DANCES |
// + ---------- +

// Tap dances definitions
// Need to needs to be defined in a .c file to avoid a linker error (multiple definitions)
tap_dance_action_t tap_dance_actions[] = {
    [TD_LSPO_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, LSPO_CAPS_finished, LSPO_CAPS_reset),
    [TD_DRG_SNP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, DRG_SNP_finished, DRG_SNP_reset),
    [TD_DRG_SNP_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, DRG_SNP_R_finished, DRG_SNP_R_reset),
    [TD_PM_MODES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, PM_MOD1_finished, PM_MOD1_reset),
    [TD_ESC_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_DEL),
};

// + ------ +
// + DANCES |
// + ------ +

// https://github.com/qmk/qmk_firmware/blob/9294258c02d3e025e01935a06c4d9f1997535bda/users/gordon/gordon.c#L112-L135
td_state_t hold_cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted) {
            if (!state->pressed)
                return TD_SINGLE_TAP;
            else
                return TD_SINGLE_HOLD;
        } else {
            if (!state->pressed)
                return TD_SINGLE_TAP;
            else
                return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted) {
            if (!state->pressed)
                return TD_DOUBLE_TAP;
            else
                return TD_DOUBLE_HOLD;
        } else {
            if (!state->pressed)
                return TD_DOUBLE_TAP;
            else
                return TD_DOUBLE_HOLD;
        }
    } else
        return TD_NONE;
}

// + ------------------------------------------------ +
// + LEFT SHIFT PARENTHESIS OPEN (LSPO) AND CAPS LOCK |
// + ------------------------------------------------ +

// Create an instance of 'td_tap_t' for the 'LSPO_CAPS' tap dance.
static td_tap_t LSPO_CAPS_state = {.is_press_action = true, .state = TD_NONE};

void LSPO_CAPS_finished(tap_dance_state_t *state, void *user_data) {
    LSPO_CAPS_state.state = hold_cur_dance(state);
    switch (LSPO_CAPS_state.state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LPRN);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_LSFT);
            break;
        case TD_DOUBLE_TAP:
            register_code16(KC_CAPS);
            break;
        case TD_DOUBLE_HOLD:
            register_code16(KC_CAPS);
            break;
        case TD_NONE:
            break;
    }
}

void LSPO_CAPS_reset(tap_dance_state_t *state, void *user_data) {
    switch (LSPO_CAPS_state.state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(KC_LSFT);
            break;
        case TD_DOUBLE_TAP:
            unregister_code16(KC_CAPS);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code16(KC_CAPS);
            break;
        case TD_NONE:
            break;
    }
    LSPO_CAPS_state.state = TD_NONE;
}


extern uint8_t rec1;
extern uint8_t rec2;


// + -------------------------------------------------- +
// + DRAG SCROLL and SNIPING into one button |
// + -------------------------------------------------- +

// Create an instance of 'td_tap_t' for the 'DRG_SNP' tap dance.
static td_tap_t DRG_SNP_state = {.is_press_action = true, .state = TD_NONE};

void DRG_SNP_finished(tap_dance_state_t *state, void *user_data) {
    DRG_SNP_state.state = hold_cur_dance(state);
    switch (DRG_SNP_state.state) {
        case TD_SINGLE_TAP:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_dragscroll_enabled(!unichunky_get_pointer_dragscroll_enabled());
            #endif
            #if (defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)) && defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
                if (!is_pointing_mode_on_left())    {
                    pointing_modes_toggle_mode(PM_DRAG);
                } else {
                    pointing_mode_switch_hands();
                    pointing_modes_toggle_mode(PM_DRAG);
                };
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_toggle_mode(PM_DRAG);
            #endif
            break;
        case TD_SINGLE_HOLD:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_dragscroll_enabled(1);
            #endif
            #if (defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)) && defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
                if (!is_pointing_mode_on_left())    {
                    pointing_modes_set_mode(PM_DRAG);
                } else {
                    pointing_mode_switch_hands();
                    pointing_modes_set_mode(PM_DRAG);
                }
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_set_mode(PM_DRAG);
            #endif
            break;
        case TD_DOUBLE_TAP:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_sniping_enabled(!unichunky_get_pointer_sniping_enabled());
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_toggle_mode(PM_PRECISION);
            #endif
            #if (defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)) && defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
                if (!is_pointing_mode_on_left())    {
                    pointing_modes_toggle_mode(PM_PRECISION);
                } else {
                    pointing_mode_switch_hands();
                    pointing_modes_toggle_mode(PM_PRECISION);
                }
            #endif
            break;
        case TD_DOUBLE_HOLD:
            #if defined(KEYBOARD_unichunky)
                pointing_modes_set_mode(PM_PRECISION);
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_set_mode(PM_PRECISION);
            #endif
            #if (defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)) && defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
                if (!is_pointing_mode_on_left())    {
                    pointing_modes_set_mode(PM_PRECISION);
                } else {
                    pointing_mode_switch_hands();
                    pointing_modes_set_mode(PM_PRECISION);
                }
            #endif
            break;
        case TD_NONE:
            break;
    }
}

void DRG_SNP_reset(tap_dance_state_t *state, void *user_data) {
    switch (DRG_SNP_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_dragscroll_enabled(0);
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)
                pointing_modes_set_mode(PM_NONE);
            #endif
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_sniping_enabled(0);
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)
                 pointing_modes_toggle_mode(PM_NONE);
            #endif
            break;
        case TD_NONE:
            break;
    }
    DRG_SNP_state.state = TD_NONE;
}

// + -------------------------------------------------- +
// + DRAG SCROLL and SNIPING into one button | Right version
// + -------------------------------------------------- +

// Create an instance of 'td_tap_t' for the 'DRG_SNP' tap dance.
static td_tap_t DRG_SNP_R_state = {.is_press_action = true, .state = TD_NONE};

void DRG_SNP_R_finished(tap_dance_state_t *state, void *user_data) {
    DRG_SNP_R_state.state = hold_cur_dance(state);
    switch (DRG_SNP_R_state.state) {
        case TD_SINGLE_TAP:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_dragscroll_enabled(!unichunky_get_pointer_dragscroll_enabled());
            #endif
            #if (defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)) && defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
                if (!is_pointing_mode_on_left())    {
                    pointing_mode_switch_hands();
                    pointing_modes_toggle_mode(PM_DRAG);
                } else {
                    pointing_modes_toggle_mode(PM_DRAG);
                }
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_toggle_mode(PM_DRAG);
            #endif
            break;
        case TD_SINGLE_HOLD:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_dragscroll_enabled(1);
            #endif
            #if (defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)) && defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
                if (!is_pointing_mode_on_left())    {
                    pointing_mode_switch_hands();
                    pointing_modes_set_mode(PM_DRAG);
                } else {
                    pointing_modes_set_mode(PM_DRAG);
                }
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_set_mode(PM_DRAG);
            #endif
            break;
        case TD_DOUBLE_TAP:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_sniping_enabled(!unichunky_get_pointer_sniping_enabled());
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_toggle_mode(PM_PRECISION);
            #endif
            #if (defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)) && defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
                if (!is_pointing_mode_on_left())    {
                    pointing_mode_switch_hands();
                    pointing_modes_toggle_mode(PM_PRECISION);
                } else {
                    pointing_modes_toggle_mode(PM_PRECISION);
                }
            #endif
            break;
        case TD_DOUBLE_HOLD:
            #if defined(KEYBOARD_unichunky)
                pointing_modes_set_mode(PM_PRECISION);
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_set_mode(PM_PRECISION);
            #endif
            #if (defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)) && defined(SPLIT_POINTING_ENABLE) && defined(POINTING_DEVICE_COMBINED)
                if (!is_pointing_mode_on_left())    {
                    pointing_mode_switch_hands();
                    pointing_modes_set_mode(PM_PRECISION);
                } else {
                    pointing_modes_set_mode(PM_PRECISION);
                }
            #endif
            break;
        case TD_NONE:
            break;
    }
}

void DRG_SNP_R_reset(tap_dance_state_t *state, void *user_data) {
    switch (DRG_SNP_R_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_dragscroll_enabled(0);
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_set_mode(PM_NONE);
            #endif
            #if defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)
                pointing_modes_set_mode(PM_NONE);
            #endif
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            #if defined(KEYBOARD_unichunky)
                unichunky_set_pointer_sniping_enabled(0);
            #endif
            #if defined(KEYBOARD_zerf9) || defined(KEYBOARD_zerfstudios_emblem)
                pointing_modes_toggle_mode(PM_NONE);
            #endif
            #if defined(KEYBOARD_zerfstudios) || defined(KEYBOARD_chunkx)
                 pointing_modes_toggle_mode(PM_NONE);
            #endif
            break;
        case TD_NONE:
            break;
    }
    DRG_SNP_R_state.state = TD_NONE;
}


// + -------------------------------------------------- +
// BROWSER, CARET in one button |
// + -------------------------------------------------- +

// Create an instance of 'td_tap_t' for the 'DRG_SNP' tap dance.
static td_tap_t PM_MOD1_state = {.is_press_action = true, .state = TD_NONE};

void PM_MOD1_finished(tap_dance_state_t *state, void *user_data) {
    PM_MOD1_state.state = hold_cur_dance(state);
    switch (PM_MOD1_state.state) {
        case TD_SINGLE_TAP:
                tap_code16(S(C(KC_TAB)));
            break;
        case TD_SINGLE_HOLD:
                pointing_modes_set_mode(6);
            break;
        case TD_DOUBLE_TAP:
                pointing_modes_toggle_mode(3);
            break;
        case TD_DOUBLE_HOLD:
                pointing_modes_set_mode(3);
            break;
        case TD_NONE:
            break;
    }
}

void PM_MOD1_reset(tap_dance_state_t *state, void *user_data) {
    switch (PM_MOD1_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
                pointing_modes_set_mode(0);
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
                pointing_modes_toggle_mode(PM_NONE);
            break;
        case TD_NONE:
            break;
    }
    PM_MOD1_state.state = TD_NONE;
}

