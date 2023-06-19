# This file intentionally left blank
MCU = RP2040
BOOTLOADER = rp2040
CONSOLE_ENABLE = yes
AUDIO_ENABLE                 = no
BACKLIGHT_ENABLE 			 = no
TAP_DANCE_ENABLE             = yes
UNICODE_ENABLE               = yes
OLED_ENABLE                  = no
ENCODER_ENABLE               = no
# DEBOUNCE_TYPE = sym_eager_pk
KEYBOARD_SHARED_EP = yes   # Free up some extra endpoints - needed if console+mouse+extra
MOUSE_SHARED_EP    = yes
OLED_DRIVER = custom
SPLIT_KEYBOARD = yes

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
#POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
# POINTING_DEVICE_DRIVER = pmw3360
HAPTIC_DRIVER += DRV2605L

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = vendor

CUSTOM_MATRIX = lite
EEPROM_DRIVER = i2c
# WEAR_LEVELING_DRIVER = rp2040_flash

SERIAL_DRIVER = vendor

DEFERRED_EXEC_ENABLE  = yes

QUANTUM_PAINTER_DRIVERS = gc9a01_spi

# CAPS_WORD_ENABLE = yes
# SRC += qmk_rc.c

# DEFAULT_FOLDER = emblem/rev1

COMBO_ENABLE = yes
VPATH += keyboards/gboards
CUSTOM_MATRIX = lite

SRC +=  ui/ui.c \
		ui/ui_helpers.c \
		ui/assets/ui_img_2120736529.c \
		ui/assets/ui_img_logo_test_png.c \
		ui/assets/ui_img_city_png.c \
		ui/assets/ui_img_emblem_80_png.c \
		ui/assets/ui_img_numpad_80_png.c \
		ui/assets/ui_img_trackball_png.c \
		ui/assets/ui_img_toolbox_80_png.c \
		ui/assets/ui_img_lower_80_png.c \
		ui/assets/ui_img_raise_80_png.c \
		ui/bindings/bindings.c \
		ui/fonts/ui_font_Futura12.c \
		ui/fonts/ui_font_Futura18.c \
		ui/fonts/ui_font_Futura20.c \
		ui/fonts/ui_font_Futura22.c \
		ui/fonts/ui_font_Futura24.c \
		ui/fonts/eleganticons.c \


QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF = yes
CIE1931_CURVE = yes
CUSTOM_KEYLOGGER = no

AUTOCORRECT_ENABLE = yes
CAPS_WORD_ENABLE = yes
CUSTOM_UNICODE_ENABLE = yes
CUSTOM_SPLIT_TRANSPORT_SYNC = yes
