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

/*
 * Custom implementation to handle register/unregister key.
 */

#include "print.h"
#include "action_util.h"
#include "key58.h"

#ifdef DEBUG_ACTION
#include "debug.h"
#else
#include "nodebug.h"
#endif

bool lambda_pressed = 0;

void process_register_key(uint8_t code)
{
    dprintf("process_register_key: code=%X\n", code);
    if (code == KC_LAMBDA)
    {
        dprintf("    lambda\n");
        lambda_pressed = 1;
    }
    else if (code == KC_TILDE)
    {
        dprintf("    tilde\n");
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_TLDE_S);
        send_keyboard_report();
    }
    else if (code == KC_EXCLAM)
    {
        dprintf("    exclam\n");
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_EXCL_S);
        send_keyboard_report();
    }
    else if (code == KC_AT_SIGN)
    {
        dprintf("    at_sign\n");
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_ATSI_S);
        send_keyboard_report();
    }
    else if (code == KC_NUMBER_SIGN)
    {
        dprintf("    num_sign\n");
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_NUSI_S);
        send_keyboard_report();
    }
    else if (code == KC_DOLLAR_SIGN)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_DOSI_S);
        send_keyboard_report();
    }
    else if (code == KC_PERCENT)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_PCNT_S);
        send_keyboard_report();
    }
    else if (code == KC_CARET)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_CART_S);
        send_keyboard_report();
    }
    else if (code == KC_AMPERSTAND)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_AMPT_S);
        send_keyboard_report();
    }
    else if (code == KC_ASTERISK)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_ASTK_S);
        send_keyboard_report();
    }
    else if (code == KC_LPARENT)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_LPAR_S);
        send_keyboard_report();
    }
    else if (code == KC_RPARENT)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_RPAR_S);
        send_keyboard_report();
    }
    else if (code == KC_UNDERSCORE)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_UNDS_S);
        send_keyboard_report();
    }
    else if (code == KC_PLUS)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_PLUS_S);
        send_keyboard_report();
    }
    else if (code == KC_LCBRACKET)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_LCBR_S);
        send_keyboard_report();
    }
    else if (code == KC_RCBRACKET)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_RCBR_S);
        send_keyboard_report();
    }
    else if (code == KC_PIPE)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_PIPE_S);
        send_keyboard_report();
    }
    else if (code == KC_DOUBLE_QUOTE)
    {
        add_mods(MOD_BIT(KC_LSFT));
        add_key(KC_DQUO_S);
        send_keyboard_report();
    }
    else
    {
        add_key(code);
        send_keyboard_report();
    }
}

void process_unregister_key(uint8_t code)
{
    dprintf("process_unregister_key: code=%X\n", code);
    if (code == KC_LAMBDA)
    {
        dprintf("    lambda\n");
        lambda_pressed = 1;
    }
    else if (code == KC_TILDE)
    {
        dprintf("    tilde\n");
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_TLDE_S);
        send_keyboard_report();
    }
    else if (code == KC_EXCLAM)
    {
        dprintf("    exclam\n");
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_EXCL_S);
        send_keyboard_report();
    }
    else if (code == KC_AT_SIGN)
    {
        dprintf("    at_sign\n");
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_ATSI_S);
        send_keyboard_report();
    }
    else if (code == KC_NUMBER_SIGN)
    {
        dprintf("    num_sign\n");
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_NUSI_S);
        send_keyboard_report();
    }
    else if (code == KC_DOLLAR_SIGN)
    {
        dprintf("    dollar_sign\n");
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_DOSI_S);
        send_keyboard_report();
    }
    else if (code == KC_PERCENT)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_PCNT_S);
        send_keyboard_report();
    }
    else if (code == KC_CARET)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_CART_S);
        send_keyboard_report();
    }
    else if (code == KC_AMPERSTAND)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_AMPT_S);
        send_keyboard_report();
    }
    else if (code == KC_ASTERISK)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_ASTK_S);
        send_keyboard_report();
    }
    else if (code == KC_LPARENT)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_LPAR_S);
        send_keyboard_report();
    }
    else if (code == KC_RPARENT)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_RPAR_S);
        send_keyboard_report();
    }
    else if (code == KC_UNDERSCORE)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_UNDS_S);
        send_keyboard_report();
    }
    else if (code == KC_PLUS)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_PLUS_S);
        send_keyboard_report();
    }
    else if (code == KC_LCBRACKET)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_LCBR_S);
        send_keyboard_report();
    }
    else if (code == KC_RCBRACKET)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_RCBR_S);
        send_keyboard_report();
    }
    else if (code == KC_PIPE)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_PIPE_S);
        send_keyboard_report();
    }
    else if (code == KC_DOUBLE_QUOTE)
    {
        del_mods(MOD_BIT(KC_LSFT));
        del_key(KC_DQUO_S);
        send_keyboard_report();
    }
    else
    {
        del_key(code);
        send_keyboard_report();
    }
}
