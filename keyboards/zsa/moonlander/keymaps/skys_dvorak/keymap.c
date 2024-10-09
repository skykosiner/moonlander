/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
    MDIA, // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    KC_PLUS_CUSTOM, // Define a custom keycode for '+'
    KC_BRACKET_LEFT,
    KC_BRACE_LEFT,
    KC_PAREN_LEFT,
    KC_AMP_CUSTOM,
    KC_EQUAL_CUSTOM,
    KC_PAREN_RIGHT,
    KC_BRACE_RIGHT,
    KC_BRACKET_RIGHT,
    KC_ASTR_CUSTOM,
    KC_DGRAVE,
    KC_BSLH_HASH,
    KC_AT_CAR,
    KC_PIPE_GRAVE,
    KC_EXCL_PER,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_PIPE_GRAVE,  KC_PLUS_CUSTOM,    KC_BRACKET_LEFT,    KC_BRACE_LEFT,    KC_PAREN_LEFT,    KC_AMP_CUSTOM,    KC_VOLU,         KC_RGHT, KC_EQUAL_CUSTOM,    KC_PAREN_RIGHT,    KC_BRACE_RIGHT,    KC_BRACKET_RIGHT,    KC_ASTR_CUSTOM,    KC_EXCL_PER,
        KC_TAB,  KC_SEMICOLON,    KC_COMMA,    KC_DOT,    KC_P,    KC_Y,    KC_VOLD,                TG(SYMB), KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLH_HASH,
        KC_LGUI, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_MUTE,                              KC_MUTE,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINUS,
                    KC_ESC, KC_QUOTE, KC_Q,KC_J,    KC_K,    KC_X,                                            KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSFT,
    LT(SYMB,KC_GRV),KC_DGRAVE,A(KC_LSFT),KC_LEFT, KC_RGHT,  KC_LEFT_CTRL,                         KC_RIGHT_ALT,   KC_UP,   KC_DOWN, KC_SLASH, KC_AT_CAR, MO(SYMB),
                                            KC_BACKSPACE,  KC_LSFT, KC_LGUI,                        KC_LALT,  KC_ENT,  KC_SPACE
    ),

    [SYMB] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
        _______, KC_1, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EE_CLR,  _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    ),

    [MDIA] = LAYOUT(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_PLUS_CUSTOM:
                // Send '+' when the key is pressed
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("1");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("+");
                }
                return false; // Prevent further processing
            case KC_BRACKET_LEFT:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("2");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("[");
                }
                return false; // Prevent further processing
            case KC_BRACE_LEFT:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("3");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("{");
                }
                return false; // Prevent further processing
            case KC_PAREN_LEFT:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("4");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("(");
                }
                return false; // Prevent further processing
            case KC_AMP_CUSTOM:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("5");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("&");
                }
                return false; // Prevent further processing
            case KC_EQUAL_CUSTOM:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("6");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("=");
                }
                return false; // Prevent further processing
            case KC_PAREN_RIGHT:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("7");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string(")");
                }
                return false; // Prevent further processing
            case KC_BRACE_RIGHT:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("8");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("}");
                }
                return false; // Prevent further processing
            case KC_BRACKET_RIGHT:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("9");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("]");
                }
                return false; // Prevent further processing
            case KC_ASTR_CUSTOM:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("0");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("*");
                }
                return false; // Prevent further processing
            case KC_DGRAVE:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("~");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("$");
                }
                return false; // Prevent further processing
            case KC_BSLH_HASH:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("#");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("\\");
                }
                return false; // Prevent further processing
            case KC_AT_CAR:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("^");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("@");
                }
                return false; // Prevent further processing
            case KC_PIPE_GRAVE:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("`");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("|");
                }
                return false; // Prevent further processing
            case KC_EXCL_PER:
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                    del_mods(MOD_BIT(KC_LSFT));
                    send_string("%");
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    send_string("!");
                }
                return false; // Prevent further processing
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true; // Process all other keycodes normally
}
