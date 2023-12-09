// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {_BASE, _L1, _L2, _L3};

#define CM_LNG2 LCMD_T(KC_LNG2)
#define CM_LNG1 RCMD_T(KC_LNG1)
#define FN      MO(_L1)
#define FN_LOCK TG(_L2)
#define FN_NUM  LT(_L1,KC_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
//     +-------+-------+-------+-------+-------+-------+-------+-------+
        KC_U,   KC_I,   KC_O,   KC_P,           KC_R,   KC_P7,  KC_E,   KC_P8,  KC_W,   KC_P9,  KC_Q,   KC_PPLS, 
        KC_Y,   KC_RBRC,KC_LBRC,KC_BSPC,        KC_T,   KC_P4,          KC_P5,          KC_P6,  KC_TAB,         KC_LSFT,
        KC_J,   KC_K,   KC_L,   KC_SCLN,        KC_F,   KC_P1,  KC_D,   KC_P2,  KC_S,   KC_P3,  KC_A,   KC_PENT,KC_RSFT,
        KC_H,                   KC_QUOT,KC_LALT,KC_G,   KC_SPC,         KC_P0,          KC_PDOT,QK_GESC,KC_UP,    
        KC_M,   KC_COMM,KC_DOT, KC_BSLS,KC_ENT, KC_V,   KC_PEQL,KC_C,   KC_PSLS,KC_X,   KC_PAST,KC_Z,      
        KC_N,                   KC_SLSH,CM_LNG2,KC_B,   KC_DOWN,        KC_RGHT,        KC_PMNS,        KC_LEFT,FN,
        KC_6,   KC_EQL,         KC_MINS,        KC_5,   KC_PGDN,        KC_PGUP,        CM_LNG1,KC_GRV, KC_HOME,KC_LCTL,
        KC_7,   KC_8,   KC_9,   KC_0,           KC_4,           KC_3,           KC_2,   KC_RALT,KC_1,   KC_END
    ),
    [_L1] = LAYOUT(
//     +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+        
        _______,_______,_______,_______,        _______,KC_PGUP,_______,KC_UP,  _______,KC_HOME,_______,_______, 
        _______,_______,_______,QK_RBT,         _______,KC_LEFT,        _______,        KC_RGHT,_______,        _______,
        _______,_______,_______,_______,        _______,KC_PGDN,_______,KC_DOWN,_______,KC_END, _______,_______,_______,
        _______,                _______,_______,_______,_______,        KC_INS,         KC_DEL, QK_BOOT,_______,    
        _______,_______,_______,_______,_______,_______,_______,_______,_______,RGB_MOD,_______,RGB_TOG,      
        _______,                _______,_______,_______,_______,        _______,        _______,        _______,_______,
        KC_F6,  KC_F12,         KC_F11,         KC_F5,  KC_VOLD,        KC_VOLU,        _______,FN_LOCK,KC_BRIU,KC_CAPS,
        KC_F7,  KC_F8,  KC_F9,  KC_F10,         KC_F4,           KC_F3,         KC_F2,  _______,KC_F1,  KC_BRID
    ),
    [_L2] = LAYOUT(
//     +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+        
        _______,_______,_______,_______,        _______,_______,_______,_______,_______,_______,_______,_______, 
        _______,_______,_______,KC_BSPC,        _______,_______,        _______,        _______,_______,        _______,
        _______,_______,_______,_______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,                _______,_______,_______,_______,        _______,        _______,QK_GESC,_______,    
        _______,_______,_______,_______,_______,_______,_______,_______,_______,KC_X,   _______,KC_Z,      
        _______,                _______,_______,_______,_______,        _______,        _______,        _______,_______,
        _______,_______,        _______,        _______,_______,        _______,        _______,_______,_______,_______,
        _______,_______,_______,_______,        _______,        _______,        _______,_______,_______,_______
    )

};

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 30 //Switch to fast animation when over words per minute

#ifdef OLED_ENABLE
#include "aquatan.c"

void render_logo(void) {
    static const char NeXT_logo [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 
	0x20, 0x20, 0x10, 0x90, 0x98, 0x98, 0x9c, 0x3c, 0x3e, 0x7c, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 
	0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xe4, 0x84, 0x1e, 0x3e, 0xff, 0xff, 0x03, 0x00, 0x38, 
	0x1e, 0x9f, 0x8f, 0xcf, 0xc7, 0xe7, 0xe3, 0xf3, 0xf9, 0xf8, 0x1c, 0x0d, 0x8f, 0xfc, 0xf0, 0xc0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe2, 0x8e, 0x3b, 0x73, 0xc3, 0x03, 
	0x23, 0x67, 0xe7, 0xc7, 0xcf, 0xcf, 0xcf, 0x8f, 0x9f, 0x9e, 0x98, 0x00, 0x03, 0x0f, 0x3c, 0xf8, 
	0xf1, 0xf3, 0xe3, 0xe7, 0xe7, 0x67, 0x63, 0x33, 0x11, 0x18, 0x0c, 0x4e, 0xc7, 0xe7, 0xe3, 0xf3, 
	0xf3, 0xfe, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xe1, 0x87, 
	0x1c, 0x70, 0xc1, 0x87, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3e, 0x07, 
	0x83, 0xf3, 0xff, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xe1, 0x87, 0x1f, 0x3f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xfe, 0xfc, 0xf1, 0xc7, 0x1f, 0x3c, 0xfc, 0xf8, 0xf9, 0xf9, 0xf1, 0xf3, 0x13, 0x03, 0xc0, 0xe0, 
	0xe7, 0xc7, 0xcf, 0xcf, 0xcf, 0x8f, 0x9f, 0x9f, 0xff, 0x7f, 0x7f, 0x3f, 0xbf, 0x9f, 0xde, 0xc8, 
	0xe4, 0xe7, 0xf3, 0xf3, 0xf9, 0xf9, 0x7c, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc3, 0x0f, 0x3f, 0x67, 0x60, 0x20, 0xbe, 0x9f, 0xdf, 
	0xcf, 0xe7, 0xe7, 0xf3, 0xf3, 0xf9, 0xf9, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x7f, 0x1f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 
	0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x03, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 
	0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x07, 0x1f, 0x1f, 0x03, 0x20, 0x3e, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 
	0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    for (int i = 0; i < 64 * 8; i += 64) { 
        oled_set_cursor(6, i / 64);
        oled_write_raw_P(NeXT_logo + i, 64);
    }
}

#endif

// -- Probably some other stuff and then --

#ifdef OLED_ENABLE

bool first_call = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (first_call) {
    oled_clear();
    oled_render();
    first_call = false;
  }
  switch (keycode) {
    case QK_BOOT:
      if (record->event.pressed) {
        oled_set_cursor(4,6);
        oled_write_ln_P(PSTR("[Firmware download]"), false);
        wait_ms(100);
      }
      return true; 
    case CM_LNG1:
    case CM_LNG2:
      if (record->event.pressed) {
        oled_set_cursor(17,7);
        oled_write_char(0x1E, false);
      } else {
        oled_set_cursor(17,7);
        oled_write_char(' ', false);
      }
      return true; 
    case KC_LALT:
    case KC_RALT:
      if (record->event.pressed) {
        oled_set_cursor(18,7);
        oled_write_char(0x1F, false);
      } else {
        oled_set_cursor(18,7);
        oled_write_char(' ', false);
      }
      return true; 
    case KC_LCTL:
      if (record->event.pressed) {
        oled_set_cursor(19,7);
        oled_write_char('^', false);
      } else {
        oled_set_cursor(19,7);
        oled_write_char(' ', false);
      }
      return true; 
    case KC_LSFT:
    case KC_RSFT:
      if (record->event.pressed) {
        oled_set_cursor(20,7);
        oled_write_char(0x18, false);
      } else {
        oled_set_cursor(20,7);
        oled_write_char(' ', false);
      }
      return true; 
    default:            
      return true; // Process all other keycodes normalllllllkljddd
  }
}

void oled_write_host_led_state(void) {
    const led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock) {
      oled_set_cursor(11,7);
      oled_write_char(0x1a, false);
      oled_set_cursor(12,7);
      oled_write_char(0x1b, false);
    } else {
      oled_set_cursor(11,7);
      oled_write_char(' ', false);
      oled_set_cursor(12,7);
      oled_write_char(' ', false);
    }
    if (led_state.caps_lock) {
      oled_set_cursor(8,7);
      oled_write_char(0x16, false);
      oled_set_cursor(9,7);
      oled_write_char(0x17, false);
    } else {
      oled_set_cursor(8,7);
      oled_write_char(' ', false);
      oled_set_cursor(9,7);
      oled_write_char(' ', false);
    }
}

void oled_write_layer_state(void) {
//    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _BASE:                               // 各レイヤーで表示する内容を定義
            oled_set_cursor(14,7);
            oled_write_char(' ', false);
            oled_set_cursor(15,7);
            oled_write_char(' ', false);
            break;
        case _L1:
            oled_set_cursor(14,7);
            oled_write_char(0x1c, false);
            oled_set_cursor(15,7);
            oled_write_char(0x1d, false);
            break;
        case _L2:
            oled_set_cursor(14,7);
            oled_write_char(0x1c, false);
            oled_set_cursor(15,7);
            oled_write_char(0x1d, false);
            break;
        default:
            oled_set_cursor(14,7);
            oled_write_char(' ', false);
            oled_set_cursor(15,7);
            oled_write_char(' ', false);
            break;
    }
}

bool oled_task_user(void) {
  if (first_call) {
    render_logo();
  } else {
    oled_render_anim();
    oled_write_layer_state();
    oled_write_host_led_state();
   }
  return false;
}
#endif

/*
#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return false;
}
#endif
*/