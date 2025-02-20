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

// BEGIN tap-dance config
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_TAP,
    TD_HOLD,
    TD_TAP_TAP,
    TD_TAP_HOLD,
    TD_TAP_TAP_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum td_sequences {
    THUMB_L_INNER,
    THUMB_L_OUTER,
    THUMB_R_INNER,
    THUMB_R_OUTER
};

td_state_t current_td_state(tap_dance_state_t *state);

void thumb_l_inner_finished(tap_dance_state_t *state, void *user_date);
void thumb_l_inner_reset(tap_dance_state_t *state, void *user_date);
void thumb_l_outer_finished(tap_dance_state_t *state, void *user_date);
void thumb_l_outer_reset(tap_dance_state_t *state, void *user_date);
void thumb_r_inner_finished(tap_dance_state_t *state, void *user_date);
void thumb_r_inner_reset(tap_dance_state_t *state, void *user_date);
void thumb_r_outer_finished(tap_dance_state_t *state, void *user_date);
void thumb_r_outer_reset(tap_dance_state_t *state, void *user_date);

// END tap-dance config

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
        KC_P,           KC_W,           KC_F,           KC_H,               XXXXXXX,                    XXXXXXX,            KC_J,               KC_K,               KC_L,           KC_DEL,
        LT(_FUNL, KC_A),LT(_NUM, KC_S), LT(_MSE, KC_E), LT(_I3, KC_T),      KC_G,                       KC_D,               LT(_KITTY, KC_O),   LT(_NAV, KC_I),   LT(_SYM, KC_N), LT(_FUNR, KC_Y),
        KC_X,           KC_Q,           KC_U,           KC_R,               KC_TAB,                     KC_V,               KC_M,               KC_C,               KC_B,           KC_Z,
                                                        TD(THUMB_L_INNER),  TD(THUMB_L_OUTER),          TD(THUMB_R_OUTER),  TD(THUMB_R_INNER)
    ),

    [_NUM] = LAYOUT(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            KC_7,           KC_8,               KC_9,           XXXXXXX,
        XXXXXXX,        _______,        KC_MINS,        KC_EQL,         XXXXXXX,                    XXXXXXX,            KC_1,           KC_2,               KC_3,           KC_PERC,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_GRAVE,       XXXXXXX,                    XXXXXXX,            KC_4,           KC_5,               KC_6,           XXXXXXX,
                                                        CMD_T(KC_COMM), SFT_T(KC_DOT),              CTL_T(KC_QUOTE),    ALT_T(KC_0)
    ),

    [_I3] = LAYOUT(
        XXXXXXX,        XXXXXXX,        G(KC_UP),       XXXXXXX,        XXXXXXX,                    XXXXXXX,            G(KC_7),        G(KC_8),            G(KC_9),        XXXXXXX,
        XXXXXXX,        G(KC_LEFT),     G(KC_RIGHT),    _______,        XXXXXXX,                    XXXXXXX,            G(KC_1),        G(KC_2),            G(KC_3),        XXXXXXX,
        XXXXXXX,        XXXXXXX,        G(KC_DOWN),     XXXXXXX,        XXXXXXX,                    XXXXXXX,            G(KC_4),        G(KC_5),            G(KC_6),        XXXXXXX,
                                                        G(KC_GRAVE),    KC_LSFT,                    G(KC_0),            G(KC_D)
    ),

    [_MSE] = LAYOUT(
        XXXXXXX,        KC_WH_U,        XXXXXXX,        KC_WFWD,        XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        KC_WBAK,        KC_WH_L,        _______,        KC_WH_D,        XXXXXXX,                    XXXXXXX,            KC_MS_L,        KC_MS_U,            KC_MS_R,        KC_ESC,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_WH_R,        KC_ACL2,                    KC_MS_BTN2,         XXXXXXX,        KC_MS_D,            XXXXXXX,        KC_ESC,
                                                        CTL_T(KC_ACL1), SFT_T(KC_ACL0),             KC_MS_BTN1,         KC_MS_BTN3
    ),

    [_SYM] = LAYOUT(
        KC_LABK,        KC_LBRC,        KC_RBRC,        KC_RABK,        XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        KC_CIRC,        KC_LPRN,        KC_RPRN,        KC_DLR,         KC_AT,                      XXXXXXX,            KC_HASH,        KC_PIPE,            _______,        XXXXXXX,
        XXXXXXX,        KC_LCBR,        KC_RCBR,        KC_SCLN,        KC_AMPR,                    XXXXXXX,            KC_EXLM,        KC_TILDE,           XXXXXXX,        XXXXXXX,
                                                        KC_LCMD,        SFT_T(KC_PAST),             CTL_T(KC_SLASH),    ALT_T(KC_BSLS)
    ),

    [_KITTY] = LAYOUT(
        A(KC_F1),       A(KC_F2),       A(KC_F3),       A(KC_F4),       A(KC_F5),                   XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        RCS(KC_COMMA),  RCS(KC_DOT),    S(KC_LEFT),     S(KC_RIGHT),    A(KC_F6),                   XXXXXXX,            _______,        A(KC_F8),           A(KC_F9),       A(KC_F10),
        RCS(KC_B),      RCS(KC_F),      RCS(KC_LEFT),   RCS(KC_RIGHT),  A(KC_F7),                   XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
                                                        RCS(KC_DOWN),   S(KC_DOWN),                 RCS(KC_L),          S(KC_UP)
    ),

    [_NAV] = LAYOUT(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,
        KC_PGUP,        KC_LEFT,        KC_UP,          KC_RIGHT,       XXXXXXX,                    XXXXXXX,            XXXXXXX,        _______,            XXXXXXX,        XXXXXXX,
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
        XXXXXXX,        RGB_VAD,        RGB_TOG,        RGB_VAI,        XXXXXXX,                    XXXXXXX,            KC_F7,          KC_F8,              KC_F9,          _______,
        XXXXXXX,        XXXXXXX,        RGB_MOD,        XXXXXXX,        XXXXXXX,                    XXXXXXX,            KC_F10,         KC_F11,             KC_F12,         XXXXXXX,
                                                        KC_PASTE,       KC_COPY,                    KC_VOLD,            KC_VOLU
    ),
};

const uint16_t PROGMEM fh_plus[]        = {KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM se_comma[]       = {LT(_NUM, KC_S), LT(_MSE, KC_E), COMBO_END};
const uint16_t PROGMEM et_dot[]         = {LT(_MSE, KC_E), LT(_I3, KC_T), COMBO_END};
const uint16_t PROGMEM ur_colon[]       = {KC_U, KC_R, COMBO_END};
const uint16_t PROGMEM qu_semi[]        = {KC_Q, KC_U, COMBO_END};
const uint16_t PROGMEM st_question[]    = {LT(_NUM, KC_S), LT(_I3, KC_T), COMBO_END};
const uint16_t PROGMEM qr_under[]       = {KC_Q, KC_R, COMBO_END};
const uint16_t PROGMEM oi_quote[]       = {LT(_KITTY, KC_O), LT(_NAV, KC_I), COMBO_END};
const uint16_t PROGMEM in_dquote[]      = {LT(_NAV, KC_I), LT(_SYM, KC_N), COMBO_END};
const uint16_t PROGMEM mc_slash[]       = {KC_M, KC_C, COMBO_END};
const uint16_t PROGMEM cb_bslash[]      = {KC_C, KC_B, COMBO_END};

combo_t key_combos[] = {
    COMBO(fh_plus,      KC_KP_PLUS),
    COMBO(se_comma,     KC_COMMA),
    COMBO(et_dot,       KC_DOT),
    COMBO(ur_colon,     KC_COLON),
    COMBO(qu_semi,      KC_SEMICOLON),
    COMBO(st_question,  LSFT(KC_SLASH)),
    COMBO(qr_under,     LSFT(KC_MINUS)),
    COMBO(oi_quote,     KC_QUOTE),
    COMBO(in_dquote,    KC_DOUBLE_QUOTE),
    COMBO(mc_slash,     KC_SLASH),
    COMBO(cb_bslash,    KC_BACKSLASH),
};

void keyboard_pre_init_user(void) {
    // Set LED pin as output and turn off as soon as QMK starts up.
    // SplitKB advises that due to technical reasons, high is off and low is on.
    setPinOutput(24);
    writePinHigh(24);
}

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _FUNL:
        case _FUNR:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case _I3:
        case _KITTY:
            rgb_matrix_set_color_all(RGB_TURQUOISE);
            break;
        case _MSE:
        case _NAV:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case _SYM:
        case _NUM:
            rgb_matrix_set_color_all(RGB_YELLOW);
            break;
        default:
            rgb_matrix_set_color_all(RGB_RED);
    }

    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(THUMB_L_INNER):
        case TD(THUMB_L_OUTER):
        case TD(THUMB_R_OUTER):
        case TD(THUMB_R_INNER):
            return 220;
        default:
            return TAPPING_TERM;
    }
}

// BEGIN tap-dance implementation

td_state_t current_td_state(tap_dance_state_t *state) {
    // Interruptions do not change the interpretation.
    if (1 == state->count) {
        if (!state->pressed) {
            return TD_TAP;
        } else {
            return TD_HOLD;
        }
    } else if (2 == state->count) {
        if (!state->pressed) {
            return TD_TAP_TAP;
        } else {
            return TD_TAP_HOLD;
        }
    } else if (3 == state->count) {
        // Must be fast typing; not expected to be used for held keys.
        return TD_TAP_TAP_TAP;
    }

    return TD_UNKNOWN;
}

static td_tap_t td_state_thumb_l_inner = {
    .is_press_action = true,
    .state = TD_NONE
};

void thumb_l_inner_finished(tap_dance_state_t *state, void *user_date) {
    td_state_thumb_l_inner.state = current_td_state(state);

    switch (td_state_thumb_l_inner.state) {
        case TD_TAP:
            register_code(KC_BSPC);
            break;
        case TD_HOLD:
            register_mods(MOD_BIT(KC_LCMD));
            break;
        case TD_TAP_TAP:
            tap_code(KC_BSPC);
            register_code(KC_BSPC);
            break;
        case TD_TAP_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        case TD_TAP_TAP_TAP:
            tap_code(KC_BSPC);
            tap_code(KC_BSPC);
            register_code(KC_BSPC);
            break;
        default:
            break;
    }
}

void thumb_l_inner_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state_thumb_l_inner.state) {
        case TD_TAP:
        case TD_TAP_TAP:
        case TD_TAP_TAP_TAP:
            unregister_code(KC_BSPC);
            break;
        case TD_HOLD:
            unregister_mods(MOD_BIT(KC_LCMD));
            break;
        case TD_TAP_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
}

static td_tap_t td_state_thumb_l_outer = {
    .is_press_action = true,
    .state = TD_NONE
};

void thumb_l_outer_finished(tap_dance_state_t *state, void *user_date) {
    td_state_thumb_l_outer.state = current_td_state(state);

    switch (td_state_thumb_l_outer.state) {
        case TD_TAP:
            register_code(KC_SPC);
            break;
        case TD_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_TAP_TAP:
            tap_code(KC_SPC);
            register_code(KC_SPC);
            break;
        case TD_TAP_HOLD:
            register_mods(MOD_BIT(KC_LCTL));
            break;
        case TD_TAP_TAP_TAP:
            tap_code(KC_SPC);
            tap_code(KC_SPC);
            register_code(KC_SPC);
            break;
        default:
            break;
    }
}

void thumb_l_outer_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state_thumb_l_outer.state) {
        case TD_TAP:
        case TD_TAP_TAP:
        case TD_TAP_TAP_TAP:
            unregister_code(KC_SPC);
            break;
        case TD_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_TAP_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL));
            break;
        default:
            break;
    }
}

static td_tap_t td_state_thumb_r_inner = {
    .is_press_action = true,
    .state = TD_NONE
};

void thumb_r_inner_finished(tap_dance_state_t *state, void *user_date) {
    td_state_thumb_r_inner.state = current_td_state(state);

    switch (td_state_thumb_r_inner.state) {
        case TD_TAP:
            register_code(KC_ESC);
            break;
        case TD_HOLD:
            register_mods(MOD_BIT(KC_LALT));
            break;
        case TD_TAP_TAP:
            tap_code(KC_ESC);
            register_code(KC_ESC);
            break;
        case TD_TAP_HOLD:
            register_mods(MOD_BIT(KC_LCMD));
            break;
        case TD_TAP_TAP_TAP:
            tap_code(KC_ESC);
            tap_code(KC_ESC);
            register_code(KC_ESC);
            break;
        default:
            break;
    }
}

void thumb_r_inner_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state_thumb_r_inner.state) {
        case TD_TAP:
        case TD_TAP_TAP:
        case TD_TAP_TAP_TAP:
            unregister_code(KC_ESC);
            break;
        case TD_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        case TD_TAP_HOLD:
            unregister_mods(MOD_BIT(KC_LCMD));
            break;
        default:
            break;
    }
}

static td_tap_t td_state_thumb_r_outer = {
    .is_press_action = true,
    .state = TD_NONE
};

void thumb_r_outer_finished(tap_dance_state_t *state, void *user_date) {
    td_state_thumb_r_outer.state = current_td_state(state);

    switch (td_state_thumb_r_outer.state) {
        case TD_TAP:
            register_code(KC_ENT);
            break;
        case TD_HOLD:
            register_mods(MOD_BIT(KC_LCTL));
            break;
        case TD_TAP_TAP:
            tap_code(KC_ENT);
            register_code(KC_ENT);
            break;
        case TD_TAP_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_TAP_TAP_TAP:
            tap_code(KC_ENT);
            tap_code(KC_ENT);
            register_code(KC_ENT);
            break;
        default:
            break;
    }
}

void thumb_r_outer_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state_thumb_r_outer.state) {
        case TD_TAP:
        case TD_TAP_TAP:
        case TD_TAP_TAP_TAP:
            unregister_code(KC_ENT);
            break;
        case TD_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL));
            break;
        case TD_TAP_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [THUMB_L_INNER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, thumb_l_inner_finished, thumb_l_inner_reset),
    [THUMB_L_OUTER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, thumb_l_outer_finished, thumb_l_outer_reset),
    [THUMB_R_INNER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, thumb_r_inner_finished, thumb_r_inner_reset),
    [THUMB_R_OUTER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, thumb_r_outer_finished, thumb_r_outer_reset)
};

// END tap-dance implementation
