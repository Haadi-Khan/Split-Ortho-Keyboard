/* Copyright 2021 Haadi Khan
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

enum layers {
    _BASE,
    _FN
};

enum macros {
    M_SRCH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /* Base
    * ,----------------------------------------|      |-----------------------------------------.
    * |  Esc |   1  |   2  |   3  |   4  |  5  |      |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+-----|      |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |  T  |      |   Y  |   U  |   I  |   O  |   P  | Del  |
    * |------+------+------+------+------+-----|      |------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |  G  |      |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+-----|      |------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |  B  |      |   N  |   M  |   ,  |   .  |   /  |  Fn  |
    * |------+------+------+------+------+-----|      |------+------+------+------+------+------|
    * | Ctrl | GUI | Alt   | M(1) |      | Home|      |  =   |      | Left | Down |  Up  |Right |
    * |------+------+------+------+Sp ace+-----|      |------+------+------+------+------+------|
    * |      |      |      |     |       | End |      |  -   |      |       |     |      |      |
    * `----------------------------------------|      |-----------------------------------------'
    */

    [_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_DEL,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, MO(1),
        KC_LCTL, KC_LGUI, KC_LALT, M_SRCH,  KC_SPC,  KC_HOME, KC_EQL,  KC_ENT,  KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT,
                                                     KC_END,  KC_MINS
    ),

    /* Function
    * ,----------------------------------------|      |-----------------------------------------.
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6 |      |  F7  |  F8  |  F9  |  F10 |  F11 | F12 |
    * |------+------+------+------+------+-----|      |------+------+------+------+------+-----|
    * |      |   `  |  [   |  ]   |  \   |     |      |      |      |      |      |      |RESET|
    * |------+------+------+------+------+-----|      |------+------+------+------+------+-----|
    * |      |      |      |      |      |     |      |      |      |      |      |      |     |
    * |------+------+------+------+------+-----|      |------+------+------+------+------+-----|
    * |      |      |      |      |      |     |      |      |      |      |      |      |     |
    * |------+------+------+------+------+-----|      |------+------+------+------+------+-----|
    * |      |      |      |      |      | PgUp|      |      |     |       |      |      |     |
    * |------+------+------+------+Sp ace+-----|      |------+-----+------+------+------+------|
    * |      |      |      |     |       | PgDn|      |      |     |       |     |      |      |
    * `----------------------------------------|      |----------------------------------------'
    */

    [_FN] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_GRV,  KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,
                                                     KC_PGDN, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed) {
        switch(keycode) {
            case M_SRCH:
                SEND_STRING(SS_LGUI("'"));
                return false;
                break;   
        }
    }
    return true;
};
