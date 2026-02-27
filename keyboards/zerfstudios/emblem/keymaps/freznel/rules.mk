BACKLIGHT_ENABLE 			 = no
COMMAND_ENABLE               = no
TAP_DANCE_ENABLE             = yes
UNICODE_ENABLE               = no
OLED_ENABLE                  = no
WPM_ENABLE                   = yes
ENCODER_ENABLE               = no
ENCODER_MAP_ENABLE           = no
# DEBOUNCE_TYPE = sym_eager_pk

LTO_SUPPORTED = no
OLED_DRIVER = custom

AUTOCORRECT_ENABLE = yes
CAPS_WORD_ENABLE = yes

HAPTIC_ENABLE = yes		# Enable Pimoroni Haptic Bzzz LRA (+1192)
HAPTIC_DRIVER = drv2605l
PROGRAMMABLE_BUTTON_ENABLE = yes

DEFERRED_EXEC_ENABLE  = yes

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = gc9a01_spi

# SRC += select_word.c

AUDIO_DRIVER  = pwm_hardware
BACKLIGHT_DRIVER = pwm

COMBO_ENABLE = yes
VPATH += keyboards/gboards

CUSTOM_DYNAMIC_MACROS_ENABLE = no

VIA_ENABLE = yes
VIAL_ENABLE = yes

