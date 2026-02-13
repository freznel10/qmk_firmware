# Chunky Rev4 Freznel Layer Map

Source: `keyboards/zerfstudios/chunky/keymaps/freznel/keymap.c`

This is a visual/text grid of the declared layers.

## Base Template (`LAYOUT_4x6_base`)

```text
R0: KC_MINUS | NUMBER_LEFT(1..5)                          || NUMBER_RIGHT(6..0)                         | KC_EQUAL
R1: CTLGRVE  | K01 K02 K03 K04 K05                        || K06 K07 K08 K09 K0A                        | BSP_KEY
R2: OS_LSFT  | LGUI_T(K11) LALT_T(K12) LCTL_T(K13) LSFT_T(K14) K15 || K16 RSFT_T(K17) RCTL_T(K18) RALT_T(K19) RGUI_T(K1A) RALT_T(K1B)
R3: LALT_T(KC_DEL) | LCTL_T(K21) K22 K23 K24 K25          || K26 K27 K28 K29 RCTL_T(K2A)                | KC_BSLS
Thumbs/extra:
  A(KC_F4) TAB_RSE SPC_LSH ENT_LWR KC_BTN1 || KC_BTN1 ESC_LWR BSP_KEY DEL_RSE SELWORD
  LVGL_BTN C(KC_B) PM_TG(2) KC_BTN3 KC_BTN2 || KC_BTN2 C_L C_R PM_TG(3) PMR_CYD
  DPI_RMOD KC_PGDN KC_PGUP DPI_MOD KC_MUTE || RGB_TOG1 PMR_LEFT KC_PGDN KC_PGUP PMR_RGHT
  RGB_RMOD RGB_MOD RGB_SAD TG(_GAMEPAD) TG(_BG) KC_RGB_T KC_F7 KC_F8 KC_9 KC_F10 KC_F11 KC_F12 KC_F13 KC_F14 KC_F15 KC_F16
```

## Default Layer Mapping

```text
_DEFAULT_LAYER_1: COLEMAK MOD-DH (L1/L2/L3 macros)
_DEFAULT_LAYER_2: COLEMAK MOD-DH (L1/L2/L3 macros)
_DEFAULT_LAYER_3: QWERTY (L1/L2/L3 macros)
_DEFAULT_LAYER_4: DVORAK (L1/L2/L3 macros)
```

## `_LOWER`

```text
R0: _______ | FUNC_LEFT                                    || FUNC_RIGHT                                  | _______
R1: _______ | LOWER_L1                                     || LOWER_R1_ALT                                | _______
R2: _______ | LOWER_L2                                     || LOWER_R2_ALT                                | _______
R3: _______ | LOWER_L3                                     || LOWER_R3                                    | _______
```

## `_RAISE`

```text
R0: _______ | FUNC_LEFT                                    || FUNC_RIGHT                                  | _______
R1: KC_CAPS | RAISE_L1                                     || EXTEND_R1                                   | _______
R2: _______ | RAISE_L2                                     || EXTEND_R2                                   | _______
R3: _______ | RAISE_L3                                     || EXTEND_R3                                   | _______
```

## `_ADJUST`

```text
R0: QK_BOOT | UNICO_L1                                     || UNICO_R1                                    | QK_BOOT
R1: EE_CLR  | ADJUST_L1                                    || ADJUST_R1                                   | QK_MAKE
R2: KEYLOCK | ADJUST_L2                                    || ADJUST_R2                                   | TG_MODS
R3: DQT     | ADJUST_L3                                    || ADJUST_R3                                   | AM_TOGGLE
```

## `_MOUSE`

```text
R0: _______ | KC_E PM_MO(14) TCK_PRE TCK_CME _______       || _______ TCK_CME TCK_PRE PM_MO(14) KC_E _______
R1: _______ | S(KC_M) TCK_WTH KC_BTN2 VIA_WTH PM_MO(6)     || PM_MO(6) VIA_WTH KC_BTN2 TCK_WTH S(KC_M) _______
R2: _______ | PM_MO(14) ROTATE KC_BTN1 KC_BTN3 KB_MO_WINDOW || _______ KC_BTN3 KC_BTN1 ROTATE PM_MO(14) _______
R3: KC_DEL  | KC_BTN1 ROUTE TD_DRGS DRG_TCK PLC_VIA        || _______ _______ TD_DRGS _______ _______ _______
```

## `_GAMEPAD`

```text
R0: KC_ESC  | GAMING_L0                                    || NUMBER_RIGHT                                | _______
R1: KC_CAPS | GAMING_L1                                    || GAMING_R1                                   | _______
R2: KC_RSFT | GAMING_L2                                    || GAMING_R2                                   | KC_QUOT
R3: KC_RCTL | GAMING_L3                                    || GAMING_R3                                   | _______
```

## `_BG`

```text
R0: KC_0    | NUMBER_LEFT                                  || NUMBER_RIGHT                                | G(KC_D)
R1: KC_TAB  | COLEMAK_MOD_DH_L1                            || COLEMAK_MOD_DH_R1                           | _______
R2: KC_LSFT | COLEMAK_MOD_DH_L2                            || COLEMAK_MOD_DH_R2                           | (none in source line)
R3: KC_LCTL | COLEMAK_MOD_DH_L3                            || COLEMAK_MOD_DH_R3                           | _______
```

## `_KEYPAD`

```text
R0: KC_NUM_LOCK     | FUNC_LEFT                            || FUNC_RIGHT                                  | _______
R1: KC_SCROLL_LOCK  | NUMPAD1_LEFT                         || ADJUST_R1                                   | _______
R2: KC_PRINT_SCREEN | NUMPAD2_LEFT                         || ADJUST_R2                                   | _______
R3: _______         | NUMPAD3_LEFT                         || ADJUST_R3                                   | _______
```

## Notes

- Most alphanumeric content is macro-driven via your userspace (for example `COLEMAK_MOD_DH_*`, `LOWER_*`, `RAISE_*`).
- To render true per-key labels as SVG/PNG, `qmk info`/`qmk c2json` must parse keyboard JSON cleanly first.
