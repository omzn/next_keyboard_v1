# This file intentionally left blank
BOOTLOADER = rp2040
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OPT_DEFS += -DHAL_USE_I2C=TRUE

WPM_ENABLE = yes  # Enable word per minute counter

RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor
