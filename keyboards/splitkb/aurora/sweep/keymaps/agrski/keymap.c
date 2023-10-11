/* Copyright 2023 Alex Rakowski (@agrski)
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

enum layer_names {
    _BASE,  // Alphabetic
    _NUM,   // Numeric
    _I3,    // i3wm
    _SYM,   // Symbolic
    _NAV,   // Navigation
    _MSE,   // Mouse
    _FUNL,  // Functions, left hand
    _FUNR,  // Functions, right hand
    _KITTY, // KiTTY terminal
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,           KC_W,           KC_F,           KC_P,           XXXXXXX,                    XXXXXXX,        KC_J,               KC_K,               KC_L,           KC_DEL,
        LT(_FUNL, KC_A),LT(_NUM, KC_S), LT(_I3, KC_E),  LT(_MSE, KC_T), KC_R,                       KC_C,           LT(_NAV, KC_I),     LT(_KITTY, KC_O),   LT(_SYM, KC_N), LT(_FUNR, KC_D),
        KC_X,           KC_G,           KC_U,           KC_H,           KC_TAB,                     KC_V,           KC_B,               KC_Y,               KC_M,           KC_Z,
                                                        CMD_T(KC_BSPC), SFT_T(KC_SPC),              CTL_T(KC_ENT),  ALT_T(KC_ESC)
    ),

    [_NUM] = LAYOUT(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            KC_7,           KC_8,               KC_9,           XXXXXXX,
        XXXXXXX,        _______,        KC_MINS,        KC_EQL,         XXXXXXX,                    XXXXXXX,            KC_1,           KC_2,               KC_3,           KC_PERC,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_GRAVE,       XXXXXXX,                    XXXXXXX,            KC_4,           KC_5,               KC_6,           XXXXXXX,
                                                        CMD_T(KC_COMM), SFT_T(KC_DOT),              CTL_T(KC_QUOTE),    ALT_T(KC_0)
    ),

    [_I3] = LAYOUT(
        XXXXXXX,        G(KC_UP),       XXXXXXX,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            G(KC_7),        G(KC_8),            G(KC_9),        XXXXXXX,
        XXXXXXX,        G(KC_LEFT),     _______,        G(KC_RIGHT),    XXXXXXX,                    XXXXXXX,            G(KC_1),        G(KC_2),            G(KC_3),        KC_PERC,
        XXXXXXX,        G(KC_DOWN),     XXXXXXX,        G(KC_GRAVE),    XXXXXXX,                    XXXXXXX,            G(KC_4),        G(KC_5),            G(KC_6),        XXXXXXX,
                                                        XXXXXXX,        KC_LSFT,                    G(KC_D),            G(KC_0)
    ),

    [_MSE] = LAYOUT(
        XXXXXXX,        KC_WFWD,        KC_WBAK,        XXXXXXX,            XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        XXXXXXX,        KC_WH_U,        KC_WH_D,        _______,            XXXXXXX,                    XXXXXXX,            KC_MS_L,        KC_MS_U,            KC_MS_R,        KC_ESC,
        XXXXXXX,        KC_WH_L,        KC_WH_R,        XXXXXXX,            KC_MS_BTN3,                 KC_MS_BTN3,         XXXXXXX,        KC_MS_D,            XXXXXXX,        KC_ESC,
                                                        CMD_T(KC_MS_BTN2),  SFT_T(KC_MS_BTN1),          CTL_T(KC_MS_BTN1),  ALT_T(KC_MS_BTN2)
    ),

    [_SYM] = LAYOUT(
        KC_LABK,        KC_LBRC,        KC_RBRC,        KC_RABK,        XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        KC_CIRC,        KC_LPRN,        KC_RPRN,        KC_DLR,         KC_AT,                      XXXXXXX,            KC_TILDE,       KC_PIPE,            _______,        XXXXXXX,
        XXXXXXX,        KC_LCBR,        KC_RCBR,        KC_SCLN,        KC_AMPR,                    XXXXXXX,            KC_EXLM,        XXXXXXX,            XXXXXXX,        XXXXXXX,
                                                        CMD_T(KC_HASH), SFT_T(KC_ASTR),             CTL_T(KC_SLASH),    ALT_T(KC_BSLS)
    ),

    [_KITTY] = LAYOUT(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        RCS(KC_COMMA),  S(KC_LEFT),     S(KC_RIGHT),    RCS(KC_DOT),    XXXXXXX,                    XXXXXXX,            XXXXXXX,        _______,            XXXXXXX,        XXXXXXX,
        RCS(KC_B),      RCS(KC_LEFT),   RCS(KC_RIGHT),  RCS(KC_F),      XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
                                                        RCS(KC_DOWN),   S(KC_DOWN),                 RCS(KC_L),          S(KC_UP)
    ),

    [_NAV] = LAYOUT(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        KC_PGUP,        KC_LEFT,        KC_UP,          KC_RIGHT,       XXXXXXX,                    XXXXXXX,            _______,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        KC_PGDN,        KC_HOME,        KC_DOWN,        KC_END,         XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
                                                        KC_LCMD,        KC_LSFT,                    KC_LCTL,            KC_LALT
    ),

    [_FUNL] = LAYOUT(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        _______,        KC_F1,          KC_F2,          KC_F3,          XXXXXXX,                    XXXXXXX,            DT_UP,          DT_DOWN,            XXXXXXX,        XXXXXXX,
        XXXXXXX,        KC_F4,          KC_F5,          KC_F6,          XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        _______,
                                                        KC_PASTE,       KC_COPY,                    KC_VOLD,            KC_VOLU
    ),

    [_FUNR] = LAYOUT(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        XXXXXXX,        BL_DOWN,        BL_TOGG,        BL_UP,          XXXXXXX,                    XXXXXXX,            KC_F7,          KC_F8,              KC_F9,          _______,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            KC_F10,         KC_F11,             KC_F12,         XXXXXXX,
                                                        KC_PASTE,       KC_COPY,                    KC_VOLD,            KC_VOLU
    ),
};
