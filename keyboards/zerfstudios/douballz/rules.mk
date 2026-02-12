# MCU name
MCU = RP2040

# Bootloader selection
#BOOTLOADER = stm32-dfu
BOOTLOADER = rp2040

# Build Options
BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
KEYBOARD_SHARED_EP = yes   # Free up some extra endpoints - needed if console+mouse
MIDI_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
MOUSE_SHARED_EP    = yes
AUDIO_DRIVER  = pwm_hardware
TRI_LAYER_ENABLE = yes

SWAP_HANDS_ENABLE = no
EEPROM_DRIVER = i2c

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

OLED_ENABLE = no
WS2812_DRIVER = vendor

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
COMBO_ENABLE = yes
VPATH += keyboards/gboards

CAPS_WORD_ENABLE = yes
# CUSTOM_UNICODE_ENABLE = yes
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += gc9a01_spi

DEFERRED_EXEC_ENABLE             = yes
ENCODER_MAP_ENABLE               = no
SWAP_HANDS_ENABLE                = no

CUSTOM_SPLIT_TRANSPORT_SYNC = no

PER_KEY_TAPPING  = yes

# HAPTIC_ENABLE = yes			# Enable Pimoroni Haptic Bzzz LRA (+1192)
HAPTIC_DRIVER = drv2605l
USE_VL91022_LRA = no

ifeq ($(strip $(USE_VL91022)), yes)
   USE_VL91022_LRA := yes
endif

I2C_SCANNER_ENABLE = no

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

QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF = yes
CIE1931_CURVE = yes
CUSTOM_KEYLOGGER = no
EXTRAFLAGS += -Wno-format-truncation
