#include "wox.h"

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case OS_CANCEL:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_OS:
    case LA_NAV:
    case LA_NUM:
    case LA_SYM:
    case LA_DEV:
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

uint16_t retro_tapping_timer = 0;

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
            case LA_OS:
            case LA_NAV:
            case LA_NUM:
            case LA_SYM:
            case LA_DEV:
                retro_tapping_timer = timer_read();
                break;
            default:
                retro_tapping_timer = 0;
        }
    } else {
        if (timer_elapsed(retro_tapping_timer) < RETRO_TAPPING_TIMEOUT) {
            switch (keycode) {
            case LA_OS:
                tap_code(KC_ESC);
                update_oneshots(KC_ESC, record);
                break;
            case LA_NAV:
                tap_code(KC_TAB);
                update_oneshots(KC_TAB, record);
                break;
            case LA_SYM:
                tap_code(KC_BSPC);
                update_oneshots(KC_BSPC, record);
                break;
            case LA_NUM:
                tap_code(KC_ENT);
                update_oneshots(KC_ENT, record);
                break;
            case LA_DEV:
                tap_code(KC_DEL);
                update_oneshots(KC_DEL, record);
                break;
            }
        }
    }

    update_oneshots(keycode, record);

    return process_record_keymap(keycode, record);
}

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
