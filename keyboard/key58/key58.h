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

#ifndef KEY58_H
#define KEY58_H

/*
 * This file is an extension of the keycode.h for the Key58 keyboard,
 * inspired by the key64 extension.
 */


#define KEYMAP_DEFAULT_LAYER DEFAULT_LAYER

enum keymap_layer {
    DEFAULT_LAYER = (uint8_t) 0,
    FN_LAYER
//    NLCK_LAYER,
};


/*
 *   Key58 additional keys:
 */

// num lock layer //
//#define KC_P00    KC_KP_00

// fn layer
#define KC_TLDE   KC_TILDE
#define KC_EXCL   KC_EXCLAM
#define KC_ATSI	  KC_AT_SIGN
#define KC_NUSI	  KC_NUMBER_SIGN
#define KC_DOSI	  KC_DOLLAR_SIGN
#define KC_PCNT	  KC_PERCENT
#define KC_CART	  KC_CARET
#define KC_AMPT	  KC_AMPERSTAND
#define KC_ASTK	  KC_ASTERISK
#define KC_LPAR	  KC_LPARENT
#define KC_RPAR	  KC_RPARENT
#define KC_UNDS	  KC_UNDERSCORE
#define KC_PLUS	  KC_PLUS
#define KC_LCBR	  KC_LCBRACKET
#define KC_RCBR	  KC_RCBRACKET
#define KC_PIPE	  KC_PIPE
#define KC_DQUO	  KC_DOUBLE_QUOTE

// _S means via shift
#define KC_TLDE_S  KC_GRAVE
#define KC_EXCL_S  KC_1
#define KC_ATSI_S  KC_2
#define KC_NUSI_S  KC_3
#define KC_DOSI_S  KC_4
#define KC_PCNT_S  KC_5
#define KC_CART_S  KC_6
#define KC_AMPT_S  KC_7
#define KC_ASTK_S  KC_8
#define KC_LPAR_S  KC_9
#define KC_RPAR_S  KC_0
#define KC_UNDS_S  KC_MINUS
#define KC_PLUS_S  KC_EQUAL
#define KC_LCBR_S  KC_LBRACKET
#define KC_RCBR_S  KC_RBRACKET
#define KC_PIPE_S  KC_BSLASH
#define KC_DQUO_S  KC_QUOTE

enum key58_special_keycodes {
    /*
     * According to the USB HID Usage Table specified in the following document:
     * http://www.usb.org/developers/hidpage/Hut1_12v2.pdf
     * 0xE8 and forward are reserved for future use.
     */
    KC_LAMBDA             = 0xE8,

    KC_TILDE              , // ~  PRIO
    KC_EXCLAM             , // !
    KC_AT_SIGN            , // @
    KC_NUMBER_SIGN        , // #
    KC_DOLLAR_SIGN        , // $
    KC_PERCENT            , // %
    KC_CARET              , // ^
    KC_AMPERSTAND         , // &
    KC_ASTERISK           , // *
    KC_LPARENT            , // ( 0xD0 )
    KC_RPARENT            , // )
    KC_UNDERSCORE         , // _ PRIO
    KC_PLUS               , // +
    KC_LCBRACKET          , // { PRIO
    KC_RCBRACKET          , // } PRIO
    KC_PIPE               , // |
    KC_DOUBLE_QUOTE       , // " PRIO

};

#define IS_EXTENDED_KEY(code)             (KC_TILDE <= (code) && (code) <= KC_DOUBLE_QUOTE)

#endif
