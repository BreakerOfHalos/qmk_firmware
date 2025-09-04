/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdint.h>
#include "quantum.h"
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "status.h"
#include "oneshot.h"
#include "casemodes.h"
#include "layermodes.h"
#include "tap_hold.h"
#include "repeat.h"
#include "roll.h"
#include "leader.h"

#include "keymap_swedish.h"
#include "sendstring_swedish.h"
#include "g/keymap_combo.h"

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: Modified THE-1
     */
    [_BASE] = LAYOUT(
      _______, KC_K,    KC_M,    KC_L,    K_U,     SKC_QN_EX,                                           KC_V,   KC_D,    KC_LPRN, KC_RPRN, KC_SLSH, _______,
      _______, KC_A,    KC_T,    KC_H,    KC_R,    SKC_DT_CN,                                           KC_C,   KC_S,    KC_N,    KC_O,    KC_I,    REPEAT,
      _______, KC_UNDS, KC_P,    KC_F,    KC_J,    SKC_CM_SC, _______, _______,      _______, _______,  KC_B,   KC_G,    KC_W,    KC_X,    KC_Y,    _______,
                                 _______, _______, SHRT,      KC_E,    _______,      _______, MT_SPC,   SPEC,   _______, _______,
    ),
    [_NUM]  = LAYOUT(
      _______, KC_K,    KC_PLUS, KC_ASTR, KC_EXLM, _______,                                            _______, _______, KC_LPRN, KC_RPRN, KC_SLSH, _______,
      _______, KC_6,    KC_4,    KC_0,    KC_2,    KC_8,                                               KC_9,    KC_3,    KC_1,    KC_5,    KC_7,    REPEAT,
      _______, KC_UNDS, KC_P,    _______, KC_J,    SKC_CM_SC, _______, _______,      _______, _______, _______, NUM_G,   QU,      KC_X,    _______, _______,
                                 _______, _______, _______,   CANCEL,  _______,      _______, MT_SPC,  _______, _______, _______,
    ),
    [_NAV]  = LAYOUT(
      _______, xxxxxxx, KC_LEFT, KC_UP,   KC_RGHT, xxxxxxx,                                            xxxxxxx, KC_HOME, G(KC_O), KC_END,  xxxxxxx, _______,
      _______, KC_PGUP, SC_TAB,  DN_CTRL, C_TAB,   xxxxxxx,                                            xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      _______, KC_ENT,  xxxxxxx, xxxxxxx, KC_PGDN, xxxxxxx,   _______, _______,      _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
                                 _______, _______, KC_LGUI,   WNAV,    _______,      _______, MT_SPC,  _______, _______, _______,
    ),
    [_WIN]  = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                            _______, _______, _______, _______, _______, _______,
      _______, _______, S_TAB,   _______, KC_TAB,  _______,   _______, _______,                        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,   _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,   _______, _______,      _______, _______, _______, _______, _______
    ),
    // Important that the symbols on the base layer have the same positions as these symbols
    [_SYM]  = LAYOUT(
      _______, KC_TILD, KC_PLUS, KC_ASTR, KC_EXLM, SKC_QN_EX,                                          KC_CIRC, KC_HASH, KC_LPRN, KC_RPRN, KC_SLSH, _______,
      _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINS, SKC_DT_CN,                                          KC_GRV,  KC_AT,   KC_LCBR, KC_RCBR, REPEAT,  _______,
      _______, KC_UNDS, KC_LABK, KC_RABK, KC_PERC, SKC_CM_SC, _______, _______,      _______, _______, xxxxxxx, KC_AMPR, KC_BSLS, xxxxxxx, xxxxxxx, _______,
                                 _______, _______, _______,   _______, _______,      _______, CANCEL,  _______, _______, _______
    ),
    [_MODS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                            xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
      _______, _______, _______, _______, _______, _______,                                            xxxxxxx, OS_GUI,  OS_CTRL, OS_SHFT, OS_ALT,  _______,
      _______, _______, _______, _______, _______, _______,  _______, _______,       _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MY_RALT, _______,
                                 _______, _______, _______,  _______, _______,       _______, _______, _______, _______, _______
    ),
    [_SHRT] = LAYOUT(
      _______, C(KC_Q), C(KC_W), C(KC_E), C(KC_R), C(KC_T),                                            _______, _______, _______, _______, _______, _______,
      _______, C(KC_A), C(KC_S), C(KC_D), C(KC_F), C(KC_G),                                            _______, _______, _______, _______, _______, _______,
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B),  _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, SHRT,     _______, _______,       _______, _______, FUN,     _______, _______,
    ),
    [_WNAV] = LAYOUT(
      _______, G(KC_ESC), G(KC_C), xxxxxxx, xxxxxxx, xxxxxxx,                                            xxxxxxx, G(SE_W), G(SE_E), G(SE_R), xxxxxxx, _______,
      _______, xxxxxxx, G(SE_4), G(SE_0), G(SE_2), G(SE_K),                                            xxxxxxx, G(SE_3), G(SE_1), G(SE_5), G(SE_7), _______,
      _______, xxxxxxx, xxxxxxx, xxxxxxx, G(SE_8), xxxxxxx, _______,  _______,       _______, _______, xxxxxxx, G(SE_9), G(SE_H), G(SE_L), xxxxxxx, _______,
                                 _______, _______, _______, G(KC_SPC),_______,       _______, WNAV,    _______, _______, _______
    ),
    [_FUN]  = LAYOUT(
      _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                                            xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
      _______, KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,                                             KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,   _______,
      _______, xxxxxxx, xxxxxxx, xxxxxxx, KC_F8,   xxxxxxx,  _______, _______,       _______, _______, xxxxxxx, KC_F9,   xxxxxxx, xxxxxxx, xxxxxxx, _______,
                                 _______, _______, SHRT,     _______, _______,       _______, _______, SPEC,    _______, _______
    ),
    [_SPEC] = LAYOUT(
      _______, ALGR(KC_TILD), SYM_LQO, _______, SYM_RQO, _______,                                            _______, _______, _______, ALGR(KC_CIRC), KC_DIAE, _______,
      _______, _______, SYM_LDQ, _______, SYM_RDQ, ALGR(KC_QUOT),                                            ALGR(KC_GRV),  SYM_LFT, SYM_DWN, SYM_UP,  SYM_RHT, _______,
      _______, _______, _______, _______, _______, _______,  _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, FUN,      _______, _______,       _______, _______, SPEC,    _______, _______
    )
};


bool process_record_skc(const uint16_t kc_0, const uint16_t kc_1, const keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    const uint8_t mods_held = mod_config(get_mods());
    const uint8_t mods_osm = mod_config(get_oneshot_mods());
    del_mods(mods_held);
    clear_oneshot_mods();
    if ((mods_held | mods_osm) & MOD_MASK_SHIFT) {
        tap_code16(kc_1);
    } else {
        tap_code16(kc_0);
    }
    add_mods(mods_held);
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case SKC_QUESTION_EXCLAMATION:
          process_record_skc(KC_QUES, KC_EXLM, record);
          break;
      case SKC_DOT_COLON:
          process_record_skc(KC_DOT, KC_COLN, record);
          break;
      case SKC_COMMA_SEMICOLON:
          process_record_skc(KC_COMM, KC_SCLN, record);
          break;
    }
    return true;
}

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev3.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _THE_ONE:
                oled_write_P(PSTR("THE-1\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */
