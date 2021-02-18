#pragma once

#include "quantum.h"
#include "oneshot.h"

#define RETRO_TAPPING_TIMEOUT 500

#define LA_NAV MO(1)
#define LA_NUM MO(2)
#define LA_OS MO(3)
#define LA_DEV MO(4)
#define LA_SYM MO(5)

#define SWE_AA LALT(KC_A)
#define SWE_AE LALT(KC_Q)
#define SWE_OO LALT(KC_O)

#define SPACE MT(MOD_LGUI, KC_SPC)

enum layers {
    _BASE = 0,
    _NAV,
    _NUM,
    _OS,
    _DEV,
    _SYM,
};

enum keycodes {
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    OS_CANCEL,
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define MYLAYOUT LAYOUT_split_3x5_3

#define USER_KEYMAPS { \
	[_BASE] = MYLAYOUT ( \
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,        KC_Y,     KC_U,   KC_I,    KC_O,   KC_P,    \
    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,        KC_H,     KC_J,   KC_K,    KC_L,   OS_SHFT, \
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,        KC_N,     KC_M,   SWE_AA,  SWE_AE, SWE_OO, \
                    LA_OS,  SPACE, LA_NAV,       LA_NUM,   LA_SYM, LA_DEV \
    ), \
 \
    [_NAV] = MYLAYOUT( \
    OS_CANCEL,  KC_NO,      KC_SPC,     KC_ESC,     KC_DEL,     KC_NO,   KC_PGDN, KC_UP,   KC_PGUP, KC_NO,  \
    OS_CTRL,    OS_ALT,     OS_CMD,     OS_SHFT,    KC_ENT,     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, \
    LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_BSPC,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
                            KC_NO,      KC_NO,      KC_NO,      KC_ENT, KC_BSPC, KC_DEL \
    ), \
 \
    [_NUM] = MYLAYOUT( \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,     KC_8,   KC_9,    KC_0,    \
    KC_F11,  KC_F12,  KC_PLUS, KC_MINS, KC_ASTR,     KC_SLSH, OS_SHFT,  OS_CMD, OS_ALT,  OS_CTRL, \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,    KC_F8,  KC_F9,   KC_F10,  \
                      KC_DOT,  KC_COMM, KC_TAB,      KC_NO,  KC_NO,     KC_NO \
    ), \
 \
    [_OS] = MYLAYOUT( \
    KC_NO,  KC_CAPS,  KC_INS,  KC_NO,   RESET,       HYPR(KC_P), HYPR(KC_1),    HYPR(KC_UP),   HYPR(KC_2),    HYPR(KC_M), \
    KC_NO,  KC_VOLD,  KC_MUTE, KC_VOLU, KC_NO,       LCA(KC_E),  HYPR(KC_LEFT), HYPR(KC_ENT),  HYPR(KC_RGHT), LCA(KC_T), \
    KC_NO,  KC_MRWD,  KC_MPLY, KC_MFFD, KC_NO,       LCA(KC_D),  HYPR(KC_3),    HYPR(KC_DOWN), HYPR(KC_4),    LCA(KC_G), \
                      KC_NO,   KC_NO,   KC_NO,       S(C(G(KC_TAB))), C(G(KC_TAB)), KC_NO \
    ), \
 \
    [_DEV] = MYLAYOUT( \
    KC_NO, A(S(KC_F2)),   A(KC_F2),      C(S(KC_N)), KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO, LGUI(KC_LBRC), LGUI(KC_RBRC), LGUI(KC_B), LGUI(KC_N),   KC_NO, KC_RPRN, KC_RCBR, KC_RBRC, KC_NO, \
    KC_NO, KC_NO,         KC_NO,         A(G(KC_B)), KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, \
                          KC_NO,         KC_NO,      KC_NO,        KC_NO, KC_NO,   KC_NO \
    ), \
 \
    [_SYM] = MYLAYOUT( \
    KC_DLR,  KC_PLUS, KC_MINS, KC_GT,   KC_QUES,     KC_BSLS, KC_GRV,  KC_DQUO, KC_QUOT, KC_HASH, \
    KC_AT,   KC_LBRC, KC_LCBR, KC_LPRN, KC_EXLM,     KC_SLSH, KC_DOT,  KC_COLN, KC_EQL,  KC_PIPE, \
    KC_TILD, KC_PERC, KC_UNDS, KC_LT,   KC_CIRC,     KC_NO,   KC_COMM, KC_SCLN, KC_ASTR, KC_AMPR, \
                      KC_NO,   KC_SPC,  KC_TAB,      KC_NO,   KC_NO,   KC_NO \
    ), \
};
