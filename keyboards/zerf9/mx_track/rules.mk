# MCU name
MCU = STM32F411

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#

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

HAPTIC_ENABLE = no			# Enable Pimoroni Haptic Bzzz LRA (+1192)
HAPTIC_DRIVER += DRV2605L

DEFERRED_EXEC_ENABLE             = yes
ENCODER_MAP_ENABLE               = yes

SRC += haptic_utils.c
PS2_MOUSE_ENABLE = no
PS2_USE_INT = no
