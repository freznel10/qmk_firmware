# MCU name
MCU = STM32F411

# Bootloader selection
#BOOTLOADER = stm32-dfu
BOOTLOADER = tinyuf2

# Build Options
#   change yes to no to disable
#
# BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
# MOUSEKEY_ENABLE = yes       # Mouse keys
# EXTRAKEY_ENABLE = yes       # Audio control and System control
# CONSOLE_ENABLE = yes      # Console for debug
# COMMAND_ENABLE = no         # Commands for debug and configuration
# # Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
# SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# # if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
ENCODER_ENABLE = yes        # Enable rotary encoder support
AUDIO_ENABLE = yes          # Audio output
KEYBOARD_SHARED_EP = yes   # Free up some extra endpoints - needed if console+mouse+extra

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
MOUSE_SHARED_EP    = yes

RGBLIGHT_DRIVER = WS2812

EEPROM_DRIVER = spi
WS2812_DRIVER = pwm
SERIAL_DRIVER = usart
AUDIO_DRIVER  = pwm_hardware

DEBOUNCE_TYPE = asym_eager_defer_pk
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = usart
OLED_ENABLE = yes
WS2812_DRIVER = pwm
OLED_DRIVER = SSD1306
OPT_DEFS += -DSTM32_DMA_REQUIRED=TRUE

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
COMBO_ENABLE = yes
VPATH += keyboards/gboards

AUTOCORRECTION_ENABLE = yes
CAPS_WORD_ENABLE = yes
CUSTOM_UNICODE_ENABLE = yes

HAPTIC_ENABLE = yes			# Enable Pimoroni Haptic Bzzz LRA (+1192)
HAPTIC_DRIVER += DRV2605L

DEFERRED_EXEC_ENABLE             = yes
ENCODER_MAP_ENABLE               = yes
SWAP_HANDS_ENABLE                = yes
SRC += haptic_utils.c


