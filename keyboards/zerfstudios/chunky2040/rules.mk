# MCU name
MCU = RP2040

# Bootloader selection
#BOOTLOADER = stm32-dfu
BOOTLOADER = rp2040

# Build Options
#   change yes to no to disable
#
# BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
# MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
# CONSOLE_ENABLE = yes      # Console for debug
# COMMAND_ENABLE = no         # Commands for debug and configuration
# # Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
# SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# # if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
ENCODER_ENABLE = no
AUDIO_ENABLE = no          # Audio output
KEYBOARD_SHARED_EP = no   # Free up some extra endpoints - needed if console+mouse+extra

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
MOUSE_SHARED_EP    = yes
AUDIO_DRIVER  = pwm_hardware

SWAP_HANDS_ENABLE = no
EEPROM_DRIVER = spi

DEBOUNCE_TYPE = asym_eager_defer_pk
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

OLED_ENABLE = no
WS2812_DRIVER = vendor

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += ssd1351_spi
COMBO_ENABLE = yes
VPATH += keyboards/gboards

AUTOCORRECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes
CUSTOM_UNICODE_ENABLE = yes

DEFERRED_EXEC_ENABLE             = yes
ENCODER_MAP_ENABLE               = no
SWAP_HANDS_ENABLE                = no
