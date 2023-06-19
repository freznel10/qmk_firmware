RGBLIGHT_ENABLE              = no
RGBLIGHT_STARTUP_ANIMATION   = no
AUDIO_ENABLE                 = yes
HAPTIC_ENABLE                = yes
COMMAND_ENABLE               = no
TAP_DANCE_ENABLE             = yes
UNICODE_ENABLE               = yes
OLED_ENABLE                  = no
WPM_ENABLE                   = yes
ENCODER_ENABLE               = yes
ENCODER_MAP_ENABLE           = yes
# DEBOUNCE_TYPE = sym_eager_pk

LTO_SUPPORTED = yes
OLED_DRIVER = custom

AUTOCORRECT_ENABLE = yes
CAPS_WORD_ENABLE = yes
CUSTOM_UNICODE_ENABLE = yes
CUSTOM_SPLIT_TRANSPORT_SYNC = yes
QUANTUM_PAINTER_ENABLE = yes

HAPTIC_ENABLE = yes
HAPTIC_DRIVER += DRV2605L

DEFERRED_EXEC_ENABLE  = yes
SRC += select_word.c
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
VIAL_ENABLE = yes
USER_NAME = freznel
QMK_SETTINGS = no



