#include QMK_KEYBOARD_H

#include "wox.h"
#include "matrix.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = USER_KEYMAPS;

const matrix_row_t matrix_mask[MATRIX_ROWS] =
{
  0b11111100,
  0b11111100,
  0b11111111,
  0b00011111,
  0b11111100,
  0b11111100,
  0b11111111,
  0b00011111,
};
