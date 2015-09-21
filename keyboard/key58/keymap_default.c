/*
  Copyright (C) 2015 xp <xp@renzhi.ca>

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
#include "keymap_common.h"
#include "key58.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LAMBDA,  \
        GRV, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   BSPC, \
        TAB, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,ENT,  \
        CAPS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,EXECUTE, \
        FN0, LALT,LCTL,LSFT,LGUI,FN2, SPC, RCTL,RALT, FN1),
    /* 1: Fn */
    KEYMAP(
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, TRNS, \
        TRNS,EXCL,ATSI,NUSI,DOSI,PCNT,CART,AMPT,ASTK,QUOT,PIPE,DEL,  \
        TRNS,LCBR,LBRC,LPAR,EQL, MINS,PLUS,DQUO,RPAR,RBRC,RCBR,TRNS, \
        NLCK,PGDN,HOME,END, PGDN,BSLS,UNDS,LEFT,DOWN,UP,  RGHT,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS)
};
const uint16_t PROGMEM fn_actions[] = {
    /* Default Layout */
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    [1] = ACTION_LAYER_MOMENTARY(1)   // to Fn overlay
};
