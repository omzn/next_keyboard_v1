// Copyright 2023 omzn (@omzn)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_HAS_GHOST

#define LED_CAPS_LOCK_PIN GP0

#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP20
#define I2C1_SCL_PIN GP21

#define OLED_DISPLAY_128X64
#define OLED_DISPLAY_HEIGHT 64
#define OLED_DISPLAY_WIDTH 128
#define OLED_MATRIX_SIZE 1024

#define OLED_FONT_H "keyboards/next_keyboard_v1/glcdfont.c"

#define WS2812_DI_PIN GP1
#define WS2812_PIO_USE_PIO1
#define RGBLED_NUM 90
#define NOP_FUDGE 0.4

#define RGBLIGHT_EFFECT_BREATHING

//#define ENABLE_COMPILE_KEYCODE
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
