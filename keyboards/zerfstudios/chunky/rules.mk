KEYBOARD_SHARED_EP = yes   # Free up some extra endpoints - needed if console+mouse
MIDI_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
POINTING_DEVICE_DRIVER = pmw3360
# PS2_ENABLE = yes
# PS2_MOUSE_ENABLE = yes
# PS2_DRIVER = vendor

MOUSE_SHARED_EP    = yes
AUDIO_DRIVER  = pwm_hardware
TRI_LAYER_ENABLE = yes

SWAP_HANDS_ENABLE = no
EEPROM_DRIVER = i2c

SERIAL_DRIVER = vendor

WS2812_DRIVER = vendor
CUSTOM_MATRIX = lite

COMBO_ENABLE = yes
VPATH += keyboards/gboards

CAPS_WORD_ENABLE = yes
PER_KEY_TAPPING = yes
# CUSTOM_UNICODE_ENABLE = yes

DEFERRED_EXEC_ENABLE             = yes
ENCODER_MAP_ENABLE               = yes
SWAP_HANDS_ENABLE                = no

CUSTOM_SPLIT_TRANSPORT_SYNC = yes

HAPTIC_DRIVER += DRV2605L
USE_VL91022_LRA = no

ifeq ($(strip $(USE_VL91022)), yes)
   USE_VL91022_LRA := yes
endif

I2C_SCANNER_ENABLE = no

QUANTUM_PAINTER_DRIVERS += gc9a01_spi

SRC +=  ui/ui.c \
		ui/ui_helpers.c \
		ui/assets/ui_img_2120736529.c \
		ui/assets/ui_img_bk80_png.c \
		ui/assets/ui_img_logo_test_png.c \
		ui/assets/ui_img_city_png.c \
		ui/assets/ui_img_emblem_80_png.c \
		ui/assets/ui_img_numpad_80_png.c \
		ui/assets/ui_img_trackball_png.c \
		ui/assets/ui_img_toolbox_80_png.c \
		ui/assets/ui_img_lower_80_png.c \
		ui/assets/ui_img_raise_80_png.c \
		ui/assets/monitormund.c \
		ui/bindings/bindings.c \
		ui/fonts/ui_font_Futura12.c \
		ui/fonts/ui_font_Futura18.c \
		ui/fonts/ui_font_Futura20.c \
		ui/fonts/ui_font_Futura22.c \
		ui/fonts/ui_font_Futura24.c \
		ui/fonts/eleganticons.c \
		adps9660.c  \

QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF = yes
CIE1931_CURVE = yes
CUSTOM_KEYLOGGER = no
