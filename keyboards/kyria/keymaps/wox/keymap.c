#include QMK_KEYBOARD_H

#include "wox.h"
#include "matrix.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = USER_KEYMAPS;

const matrix_row_t matrix_mask[MATRIX_ROWS] =
{
  0b01111100,
  0b01111100,
  0b01111100,
  0b00001110,
  0b01111100,
  0b01111100,
  0b01111100,
  0b00001110,
};
