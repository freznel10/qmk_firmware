# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040
TAP_DANCE_ENABLE             = yes
UNICODE_ENABLE               = yes
OLED_ENABLE                  = no
# DEBOUNCE_TYPE = sym_eager_pk
KEYBOARD_SHARED_EP = no   # Free up some extra endpoints - needed if console+mouse+extra
MOUSE_SHARED_EP    = no
OLED_DRIVER = custom

POINTING_DEVICE_ENABLE = yes
# #POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
# #POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
HAPTIC_DRIVER = drv2605l

# PS2_ENABLE = yes
# PS2_MOUSE_ENABLE = yes
# PS2_DRIVER = vendor

# POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
POINTING_DEVICE_DRIVER = pmw3360

WS2812_DRIVER = vendor
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812

CUSTOM_MATRIX = lite
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = rp2040_flash

SERIAL_DRIVER = vendor

DEFERRED_EXEC_ENABLE  = yes
ENCODER_MAP_ENABLE = no

# QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += gc9a01_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF = no

LCD_ONBOARD = no

CAPS_WORD_ENABLE = yes

SRC += ui/ui.c \
		ui/assets/ui_img_emblem_80_png.c \
		ui/assets/ui_img_controller80_png.c \
		ui/assets/ui_img_numpad_80_png.c \
		ui/assets/ui_img_trackball_png.c \
		ui/assets/ui_img_toolbox_80_png.c \
		ui/assets/ui_img_lower_80_png.c \
		ui/assets/ui_img_raise_80_png.c \
		ui/ui_comp.c \
		ui/ui_helpers.c \
		ui/fonts/ui_font_Font16.c \
		ui/fonts/ui_font_Font18.c \
		ui/fonts/ui_font_Font1.c \
		ui/fonts/extra_icons.c \
		ui/fonts/impact_22.c \
		ui/fonts/impact_45.c \
		ui/bindings/bindings.c \
		ui/fonts/ui_font_Font12.c \
		ui/fonts/extra_symbols.c \
		ui/widgets/lv_custom_colorwheel.c \
		ui/assets/sama.c \
		ui/assets/badge-dark.c \
		ui/settings/screensaver/screensaver.c \
		ui/settings/appr/layer/layer.c \
		ui/settings/appr/img/img.c \
		ui/settings/appr/appr.c \
		ui/settings/rgb/rgb_mode/rgb_mode.c \
		ui/settings/rgb/rgb_speed/rgb_speed.c \
		ui/settings/rgb/rgb_hsv/rgb_hsv.c \
		ui/settings/dev/dev.c \
		ui/manu.c \
		ui/fonts/impact_45.c \
		ui/fonts/impact_22.c \
		ui/dial_menu/dial_menu.c \
        ui/widgets/lv_custom_colorwheel.c \
		ui/widgets/bpm.c \
		ui/layers/layers.c \
		ui/styles/styles.c \

LTO_ENABLE = yes
EXTRAFLAGS += -Wno-format-truncation
