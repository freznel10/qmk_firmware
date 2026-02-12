#include "combos.h"

/*COMBOS*/

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
const uint16_t PROGMEM raise_combo[] = {RSFT_T(KC_N), RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM clear_line_combo[] = {KC_K, KC_COMMA, COMBO_END};
const uint16_t PROGMEM backspace_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM undo_combo[] = {LCTL_T(KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM redo_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {LGUI_T(KC_A), KC_G, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {LCTL_T(KC_Z), KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM keypad_combo[] = {LGUI_T(KC_A), LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM lower_combo[] = {RCTL_T(KC_E), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM wback_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM wfwd_combo[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM nextsen_combo[] = {RALT_T(KC_I), KC_DOT, COMBO_END};
const uint16_t PROGMEM negativepaste_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM numone_combo[] = { KC_Q, LGUI_T(KC_A), COMBO_END};
const uint16_t PROGMEM numtwo_combo[] = { KC_W, LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM numthree_combo[] = { KC_F, LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM numfour_combo[] = { KC_P, LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM numfive_combo[] = { KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM numsix_combo[] = { KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM numseven_combo[] = { KC_L, RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM numeight_combo[] = { KC_U, RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM numnine_combo[] = { KC_Y, RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM numzero_combo[] = { KC_SCLN, RGUI_T(KC_O), COMBO_END};
const uint16_t PROGMEM cirquescroll_combo[] = { KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM mouselayer_combo[] = { LALT_T(KC_R), LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM mouselayer_r_combo[] = { RALT_T(KC_I), RGUI_T(KC_O), COMBO_END};
const uint16_t PROGMEM navup_combo[] = { KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM navdn_combo[] = { KC_W, KC_F, COMBO_END};

combo_t key_combos[] = {
  [RAISE_TOGGLE] = COMBO_ACTION(raise_combo),
  [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
  [BACKLU] = COMBO_ACTION(backspace_combo),
  [UNDO] = COMBO_ACTION(undo_combo),
  [REDO] = COMBO_ACTION(redo_combo),
  [ENTER] = COMBO_ACTION(enter_combo),
  [CUT] = COMBO_ACTION(cut_combo),
  [COPY] = COMBO_ACTION(copy_combo),
  [PASTE] = COMBO_ACTION(paste_combo),
  [KEYPAD] = COMBO_ACTION(keypad_combo),
  [LOWER_TOGGLE] = COMBO_ACTION(lower_combo),
  [LPAREN] = COMBO_ACTION(lparen_combo),
  [RPAREN] = COMBO_ACTION(rparen_combo),
  [WBACK] = COMBO_ACTION(wback_combo),
  [WFWD] = COMBO_ACTION(wfwd_combo),
  [NEXTSEN] = COMBO_ACTION(nextsen_combo),
  [NEGATIVEPASTE] = COMBO_ACTION(negativepaste_combo),
  [NUMONE] = COMBO(numone_combo, KC_1),
  [NUMTWO] = COMBO(numtwo_combo, KC_2),
  [NUMTHREE] = COMBO(numthree_combo, KC_3),
  [NUMFOUR] = COMBO(numfour_combo, KC_4),
  [NUMFIVE] = COMBO(numfive_combo, KC_5),
  [NUMSIX] = COMBO(numsix_combo, KC_6),
  [NUMSEVEN] = COMBO(numseven_combo, KC_7),
  [NUMEIGHT] = COMBO(numeight_combo, KC_8),
  [NUMNINE] = COMBO(numnine_combo, KC_9),
  [NUMZERO] = COMBO(numzero_combo, KC_0),
  [CIRQUE_SCROLL] = COMBO(cirquescroll_combo, DRG_TOG),
  [MOUSE_LAYER] = COMBO(mouselayer_combo, TT(_MOUSE)),
  [MOUSE_LAYER_TWO] = COMBO(mouselayer_r_combo, TT(_MOUSE)),
  [NAVUP] = COMBO(navup_combo, KC_PGUP),
  [NAVDN] = COMBO(navdn_combo, KC_PGDN),

};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case RAISE_TOGGLE:
      if (pressed) {
        layer_invert(_RAISE);
      }
      break;
    case BSPC_LSFT_CLEAR:
      if (pressed) {
        tap_code16(KC_END);
        tap_code16(C(KC_LEFT));
        tap_code_delay(KC_BSPC, 5);
      }
      break;
    case BACKLU:
      if (pressed) {
        tap_code16(C(S(KC_LEFT)));
        tap_code16(KC_BSPC);
      }
      break;
    case UNDO:
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
    break;
    case REDO:
      if (pressed) {
        tap_code16(LCTL(KC_Y));
      }
      break;
  case ENTER:
      if (pressed) {
        tap_code16(KC_ENTER);
      }
      break;
  case CUT:
      if (pressed) {
        tap_code16(C(KC_X));
      }
      break;
  case COPY:
      if (pressed) {
        tap_code16(C(KC_C));
      }
      break;
  case PASTE:
      if (pressed) {
        tap_code16(C(KC_V));
      }
      break;
  case KEYPAD:
      if (pressed) {
        layer_invert(_KEYPAD);
      }
      break;
  case LOWER_TOGGLE:
      if (pressed) {
        layer_invert(_LOWER);
      }
      break;
  case LPAREN:
      if (pressed) {
        tap_code16(KC_LPRN);
      }
      break;
  case RPAREN:
      if (pressed) {
        tap_code16(KC_RPRN);
      }
      break;
  case WBACK:
      if (pressed) {
        tap_code16(KC_WBAK);
      }
      break;
  case WFWD:
      if (pressed) {
        tap_code16(KC_WFWD);
      }
      break;
  case NEXTSEN:
    if (pressed) {
        SEND_STRING(". ");
        add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
        }
      break;
  case NEGATIVEPASTE:
    if (pressed) {
        SEND_STRING("-");
        tap_code16(C(KC_V));
        }
      break;
//   case MOUSE_LAYER:
//     if (pressed) {
//         layer_invert(_MOUSE);
//       }
      break;
  }
}
