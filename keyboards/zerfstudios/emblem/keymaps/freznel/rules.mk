AUDIO_ENABLE                 = yes
BACKLIGHT_ENABLE 			 = yes
COMMAND_ENABLE               = no
TAP_DANCE_ENABLE             = yes
OLED_ENABLE                  = no
WPM_ENABLE                   = yes
ENCODER_ENABLE               = yes
ENCODER_MAP_ENABLE           = yes
# DEBOUNCE_TYPE = sym_eager_pk

LTO_SUPPORTED = no
OLED_DRIVER = custom

AUTOCORRECT_ENABLE = yes
CAPS_WORD_ENABLE = yes

HAPTIC_ENABLE = yes		# Enable Pimoroni Haptic Bzzz LRA (+1192)
HAPTIC_DRIVER += DRV2605L
PROGRAMMABLE_BUTTON_ENABLE = yes

DEFERRED_EXEC_ENABLE  = yes

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = gc9a01_spi

AUDIO_DRIVER  = pwm_hardware
BACKLIGHT_DRIVER = pwm

COMBO_ENABLE = yes
VPATH += keyboards/gboards

CUSTOM_DYNAMIC_MACROS_ENABLE = no
CUSTOM_UNICODE_ENABLE = yes

VIA_ENABLE = yes
VIAL_ENABLE = yes

POINTING_MODE_ABSOLUTE = yes



