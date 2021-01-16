
/* Copyright 2021 Dustin Bosveld <steamyleafjuice@protonmail.com>
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
#include QMK_KEYBOARD_H

/* Modtaps */
#define SHFT_Z MT(MOD_LSFT, KC_Z)
#define CTRL_A MT(MOD_LCTL, KC_A)
#define SFT_SSH MT(MOD_RSFT, KC_SLSH)
#define ALT_ENT MT(MOD_LALT, KC_ENT)
#define GUI_ESC MT(MOD_LGUI, KC_ESC)
#define CTRL_SC MT(MOD_LCTL, KC_SCLN)

/* Layertaps */
#define SYM_SPC LT(SYMB, KC_SPC)
#define NUM_SPC LT(NUMB, KC_SPC)
