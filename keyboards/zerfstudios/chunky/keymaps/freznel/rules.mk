TAP_DANCE_ENABLE             = yes
OLED_ENABLE                  = no
WPM_ENABLE                   = yes
ENCODER_ENABLE               = yes
ENCODER_MAP_ENABLE           = yes
# DEBOUNCE_TYPE = sym_eager_pk

LTO_SUPPORTED = yes
OLED_DRIVER = custom

AUTOCORRECT_ENABLE = yes


HAPTIC_ENABLE = yes			# Enable Pimoroni Haptic Bzzz LRA (+1192)
HAPTIC_DRIVER += DRV2605L

DEFERRED_EXEC_ENABLE  = yes

QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_ENABLE = yes
CUSTOM_UNICODE_ENABLE = yes
CUSTOM_SPLIT_TRANSPORT_SYNC = yes
UI_RENDER_WPM = yes
OS_DETECTION_ENABLE = no

CUSTOM_KEYLOGGER?= yes

ifeq ($(strip $(CUSTOM_KEYLOGGER)), yes)
    OPT_DEFS += -DCUSTOM_KEYLOGGER
endif


