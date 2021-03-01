/* Copyright 2021 Martin Woxneryd <martin@woxneryd.com>
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

#pragma once



#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

#define WOX_LAYOUT( \
    L01, L02, L03, L04, L05,                R06, R07, R08, R09, R10, \
    L13, L14, L15, L16, L17,                R18, R19, R20, R21, R22, \
    L25, L26, L27, L28, L29,                R34, R35, R36, R37, R38, \
                   L41, L42, L43,      R46, R47, R48 \
) \
{ \
    { KC_NO, KC_NO, L05,   L04,   L03,   L02,   L01,   KC_NO   }, \
    { KC_NO, KC_NO, L17,   L16,   L15,   L14,   L13,   KC_NO   }, \
    { KC_NO, KC_NO, L29,   L28,   L27,   L26,   L25,   KC_NO   }, \
    { KC_NO, L43,   L42,   L41,   KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, R06,   R07,   R08,   R09,   R10,   KC_NO   }, \
    { KC_NO, KC_NO, R18,   R19,   R20,   R21,   R22,   KC_NO   }, \
    { KC_NO, KC_NO, R34,   R35,   R36,   R37,   R38,   KC_NO   }, \
    { KC_NO, R46,   R47,   R48,   KC_NO, KC_NO, KC_NO, KC_NO }, \
}

#define MATRIX_MASKED

