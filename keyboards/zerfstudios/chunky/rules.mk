KEYBOARD_SHARED_EP = no  # Free up some extra endpoints - needed if console+mouse
MIDI_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
# POINTING_DEVICE_DRIVER = cirque_pinnacle_spi  # reference: cirque option
# POINTING_DEVICE_DRIVER = ps2_trackpoint       # reference: trackpoint option
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor

MOUSE_SHARED_EP    = no
AUDIO_DRIVER  = pwm_hardware
TRI_LAYER_ENABLE = yes

SWAP_HANDS_ENABLE = no

SERIAL_DRIVER = vendor
SPLIT_KEYBOARD = yes
CUSTOM_KEYLOGGER = yes

CUSTOM_MATRIX = lite

COMBO_ENABLE = yes
VPATH += keyboards/gboards

PER_KEY_TAPPING = no
# CUSTOM_UNICODE_ENABLE = yes

DEFERRED_EXEC_ENABLE             = yes
ENCODER_MAP_ENABLE               = no
SWAP_HANDS_ENABLE                = no

CUSTOM_SPLIT_TRANSPORT_SYNC = yes

HAPTIC_DRIVER = drv2605l
USE_VL91022_LRA = no

ifeq ($(strip $(USE_VL91022)), yes)
   USE_VL91022_LRA := yes
endif

I2C_SCANNER_ENABLE = no

QUANTUM_PAINTER_DRIVERS += gc9a01_spi

SRC +=  ui/ui.c \
		ui/ui_helpers.c \
		ui/assets/ui_img_2120736529.c \
		ui/assets/ui_img_2040_png.c \
		ui/assets/ui_img_chunky_lower_png.c \
		ui/assets/ui_img_chunky_upper_png.c \
		ui/assets/ui_img_chunky2040_v3_png.c \
		ui/assets/ui_img_bk80_png.c \
		ui/assets/ui_img_logo_test_png.c \
		ui/assets/ui_img_logo_png.c \
		ui/assets/ui_img_city_png.c \
		ui/assets/ui_img_emblem_80_png.c \
		ui/assets/ui_img_numpad_80_png.c \
		ui/assets/ui_img_trackball_png.c \
		ui/assets/ui_img_toolbox_80_png.c \
		ui/assets/ui_img_lower_80_png.c \
		ui/assets/ui_img_raise_80_png.c \
		ui/assets/ui_img_ui_image_adjust_png.c \
		ui/assets/ui_img_audio_32_png.c \
		ui/assets/ui_img_clicky_32_png.c \
		ui/assets/ui_img_autocorrect_32_png.c \
		ui/assets/ui_img_caps_lock_32_png.c \
		ui/assets/ui_img_num_lock_32_png.c \
		ui/assets/ui_img_scroll_lock_32_png.c \
		ui/assets/ui_img_20466782.c \
		ui/assets/monitormund.c \
		ui/bindings/bindings.c \
		ui/fonts/ui_font_Futura12.c \
		ui/fonts/ui_font_Futura18.c \
		ui/fonts/ui_font_Futura20.c \
		ui/fonts/ui_font_Futura22.c \
		ui/fonts/ui_font_Futura24.c \
		ui/fonts/ui_font_GaretHeavy14.c \
		ui/fonts/ui_font_GaretHeavy18.c \
		ui/fonts/ui_font_GaretHeavy48.c \
		ui/fonts/ui_font_SpaceGrotesk18.c \
		ui/fonts/ui_font_SpaceGrotesk50.c \
		ui/fonts/ui_font_Space11.c \
		ui/fonts/eleganticons.c \
		adps9660.c  \

QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF = yes
CIE1931_CURVE = yes
CUSTOM_KEYLOGGER = no
UI_RENDER_WPM = yes
EXTRAFLAGS += -Wno-format-truncation
BOOTMAGIC_ENABLE = yes
