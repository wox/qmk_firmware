/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "oneshot.h"

#define ONESHOT_TIMEOUT 500

#define LA_NAV MO(1)
#define LA_NUM MO(2)
#define LA_WIN MO(3)
#define LA_FUNC MO(4)
#define LA_L2 MO(5)
#define LA_L1 MO(6)

enum layers {
    _QWERTY = 0,
    _NAV,
    _NUM,
    _WIN,
    _FUNC,
    _L2,
    _L1,
};

enum keycodes {
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3 (
    XXXXXXX,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,             KC_Y,     KC_U,   KC_I,    KC_O,  KC_P,    XXXXXXX,
    XXXXXXX,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,             KC_H,     KC_J,   KC_K,    KC_L,  OS_SHFT, XXXXXXX,
    XXXXXXX,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,             KC_N,     KC_M, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX,
                              LA_WIN, LA_NAV,  LA_NUM,            LA_L2,  LA_L1, LA_FUNC
    ),

    [1] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_ESC,     LALT(KC_A), LALT(KC_Q), LALT(KC_O), KC_DEL,              KC_NO,   KC_PGDN, KC_UP,   KC_PGUP, KC_NO,  XXXXXXX,
    XXXXXXX, OS_CTRL,    OS_ALT,     OS_CMD,     OS_SHFT,    KC_ENT,              KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, XXXXXXX,
    XXXXXXX, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_BSPC,             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  XXXXXXX,
                                                 KC_NO,      KC_TRNS, KC_TRNS,    KC_ENT, KC_BSPC, KC_SPC
    ),

	[2] = LAYOUT(
    XXXXXXX, KC_NO, A(S(KC_F2)), A(KC_F2), C(S(KC_N)), KC_NO, KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS, XXXXXXX,
    XXXXXXX, KC_NO, LGUI(KC_LBRC), LGUI(KC_RBRC), LGUI(KC_B), LGUI(KC_N), KC_PAST, KC_4, KC_5, KC_6, KC_0, XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_NO, A(G(KC_B)), KC_NO, KC_PPLS, KC_1, KC_2, KC_3, KC_PEQL, XXXXXXX,
    KC_NO, KC_NO, KC_TRNS, KC_PENT, KC_COMM, KC_DOT
    ),

    [3] = LAYOUT(
    XXXXXXX, KC_NO, KC_CAPS, KC_INS, KC_NO, RESET, HYPR(KC_P), HYPR(KC_1), HYPR(KC_UP), HYPR(KC_2), HYPR(KC_M), XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_NO, LGUI(KC_SPC), KC_TRNS, LCA(KC_E), HYPR(KC_LEFT), HYPR(KC_ENT), HYPR(KC_RGHT), LCA(KC_T), XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCA(KC_D), HYPR(KC_3), HYPR(KC_DOWN), HYPR(KC_4), LCA(KC_G), XXXXXXX,
    KC_TRNS, KC_NO, KC_TRNS, S(C(G(KC_TAB))),  C(G(KC_TAB)), KC_NO
    ),

    [4] = LAYOUT(
    XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO, XXXXXXX,
    XXXXXXX, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, XXXXXXX,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
    ),

    [5] = LAYOUT(
    XXXXXXX, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   XXXXXXX,
    XXXXXXX, KC_AT, KC_LBRC, KC_LCBR, KC_LPRN, KC_NO,      KC_SLSH, OS_SHFT, OS_CMD,  OS_ALT, OS_CTRL, XXXXXXX,
    XXXXXXX, KC_NO, KC_RBRC, KC_RCBR, KC_RPRN, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   XXXXXXX,
                             KC_NO,   KC_SPC,  KC_TAB,     KC_NO,   KC_NO,   KC_NO
    ),

    [6] = LAYOUT(
    XXXXXXX, KC_DLR,  KC_PLUS, KC_MINS, KC_GT,   KC_QUES,     KC_BSLS, KC_GRV,  KC_DQUO, KC_QUOT, KC_HASH, XXXXXXX,
    XXXXXXX, KC_AT,   KC_LBRC, KC_LCBR, KC_LPRN, KC_EXLM,     KC_SLSH, KC_DOT,  KC_COLN, KC_EQL,  KC_PIPE, XXXXXXX,
    XXXXXXX, KC_TILD, KC_PERC, KC_UNDS, KC_LT,   KC_CIRC,     KC_NO,   KC_COMM, KC_SCLN, KC_ASTR, KC_AMPR, XXXXXXX,
                               KC_NO,   KC_SPC,  KC_TAB,      KC_NO,   KC_NO,   KC_NO
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NAV:
    case LA_NUM:
    case LA_L1:
    case LA_L2:
    case LA_FUNC:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

uint16_t timer = 0;

void update_oneshots(
    uint16_t keycode,
    keyrecord_t *record
) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Base!"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Other!"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      set_keylog(keycode, record);
    }

      // retro tapping with timeouts
    if (record->event.pressed) {
        switch (keycode) {
        case LA_WIN:
        case LA_NAV:
        case LA_NUM:
        case LA_L1:
        case LA_L2:
        case LA_FUNC:
            timer = timer_read();
            break;
        default:
            timer = 0;
        }
    } else {
        if (timer_elapsed(timer) < ONESHOT_TIMEOUT) {
            switch (keycode) {
            case LA_WIN:
                tap_code(KC_ESC);
                update_oneshots(KC_ESC, record);
                break;
            case LA_NAV:
                tap_code(KC_SPC);
                update_oneshots(KC_ESC, record);
                break;
             case LA_NUM:
                tap_code(KC_TAB);
                update_oneshots(KC_ESC, record);
                break;
            case LA_L2:
                tap_code(KC_ENT);
                update_oneshots(KC_ESC, record);
                break;
            case LA_L1:
                tap_code(KC_BSPC);
                update_oneshots(KC_ESC, record);
                break;
            }
        }
    }

    update_oneshots(keycode, record);

    return true;
}
