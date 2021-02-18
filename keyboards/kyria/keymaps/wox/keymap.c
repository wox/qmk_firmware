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
	[0] = LAYOUT(
    XXXXXXX,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,     KC_U,   KC_I,    KC_O,    KC_P, XXXXXXX,
    XXXXXXX,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                      KC_H,     KC_J,   KC_K,    KC_L, OS_SHFT, XXXXXXX,
    XXXXXXX,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_N,     KC_M, OS_CTRL, OS_ALT,  OS_CMD, XXXXXXX,
                             XXXXXXX, LA_WIN, LA_NAV,  LA_NUM, XXXXXXX, XXXXXXX,   LA_L2,  LA_L1, LA_FUNC, XXXXXXX
    ),

    [1] = LAYOUT(
    XXXXXXX, KC_ESC,     LALT(KC_A), LALT(KC_Q), LALT(KC_O), KC_DEL,                                      KC_NO,   KC_PGDN, KC_UP,   KC_PGUP, KC_NO,  XXXXXXX,
    XXXXXXX, OS_CTRL,    OS_ALT,     OS_CMD,     OS_SHFT,    KC_ENT,                                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, XXXXXXX,
    XXXXXXX, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  XXXXXXX,
                                        XXXXXXX,      KC_NO, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX,  KC_ENT, KC_BSPC, KC_SPC,  XXXXXXX
    ),

	[2] = LAYOUT(
    XXXXXXX, KC_NO, A(S(KC_F2)), A(KC_F2), C(S(KC_N)), KC_NO, KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS, XXXXXXX,
    XXXXXXX, KC_NO, LGUI(KC_LBRC), LGUI(KC_RBRC), LGUI(KC_B), LGUI(KC_N), KC_PAST, KC_4, KC_5, KC_6, KC_0, XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_NO, A(G(KC_B)), KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_1, KC_2, KC_3, KC_PEQL, XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_TRNS, XXXXXXX, XXXXXXX, KC_PENT, KC_COMM, KC_DOT, XXXXXXX
    ),

    [3] = LAYOUT(
    XXXXXXX, KC_NO, KC_CAPS, KC_INS, KC_NO, RESET, HYPR(KC_P), HYPR(KC_1), HYPR(KC_UP), HYPR(KC_2), HYPR(KC_M), XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_NO, LGUI(KC_SPC), KC_TRNS, LCA(KC_E), HYPR(KC_LEFT), HYPR(KC_ENT), HYPR(KC_RGHT), LCA(KC_T), XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCA(KC_D), HYPR(KC_3), HYPR(KC_DOWN), HYPR(KC_4), LCA(KC_G), XXXXXXX,
    XXXXXXX, KC_TRNS, KC_NO, KC_TRNS, XXXXXXX, XXXXXXX, S(C(G(KC_TAB))),  C(G(KC_TAB)), KC_NO, XXXXXXX
    ),

    [4] = LAYOUT(
    XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO, XXXXXXX,
    XXXXXXX, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_F11, KC_F12, KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, XXXXXXX,
    XXXXXXX, KC_NO, KC_NO, KC_NO, XXXXXXX, XXXXXXX, KC_NO, KC_NO, KC_TRNS, XXXXXXX
    ),

    [5] = LAYOUT(
    XXXXXXX, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   XXXXXXX,
    XXXXXXX, KC_AT, KC_LBRC, KC_LCBR, KC_LPRN, KC_NO,      KC_SLSH, OS_SHFT, OS_CMD,  OS_ALT, OS_CTRL, XXXXXXX,
    XXXXXXX, KC_NO, KC_RBRC, KC_RCBR, KC_RPRN, KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, XXXXXXX,
    XXXXXXX, KC_NO, KC_SPC,  KC_TAB, XXXXXXX, XXXXXXX, KC_NO, KC_NO, KC_NO, XXXXXXX
    ),

    [6] = LAYOUT(
    XXXXXXX, KC_DLR,  KC_PLUS, KC_MINS, KC_GT,   KC_QUES,     KC_BSLS, KC_GRV,  KC_DQUO, KC_QUOT, KC_HASH, XXXXXXX,
    XXXXXXX, KC_AT,   KC_LBRC, KC_LCBR, KC_LPRN, KC_EXLM,     KC_SLSH, KC_DOT,  KC_COLN, KC_EQL,  KC_PIPE, XXXXXXX,
    XXXXXXX, KC_TILD, KC_PERC, KC_UNDS, KC_LT,   KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   KC_COMM, KC_SCLN, KC_ASTR, KC_AMPR, XXXXXXX,
    XXXXXXX, KC_NO, KC_SPC, KC_TAB, XXXXXXX, XXXXXXX, KC_NO, KC_NO, KC_NO, XXXXXXX
    )
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
