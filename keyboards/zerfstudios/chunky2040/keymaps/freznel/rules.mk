RGBLIGHT_ENABLE              = no
RGBLIGHT_STARTUP_ANIMATION   = no
AUDIO_ENABLE                 = yes
HAPTIC_ENABLE                = yes
COMMAND_ENABLE               = no
TAP_DANCE_ENABLE             = yes
UNICODE_ENABLE               = yes
OLED_ENABLE                  = no
WPM_ENABLE                   = yes
ENCODER_ENABLE               = no
ENCODER_MAP_ENABLE           = no
# DEBOUNCE_TYPE = sym_eager_pk

LTO_SUPPORTED = yes
OLED_DRIVER = custom

AUTOCORRECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes
CUSTOM_UNICODE_ENABLE = yes
CUSTOM_SPLIT_TRANSPORT_SYNC = yes
QUANTUM_PAINTER_ENABLE = yes

HAPTIC_ENABLE = yes			# Enable Pimoroni Haptic Bzzz LRA (+1192)
HAPTIC_DRIVER += drv2605l

DEFERRED_EXEC_ENABLE  = yes

VPATH += keyboards/gboards
