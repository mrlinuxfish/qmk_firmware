/* Copyright 2020 Dustin Bosveld <steamyleafjuice@protonmail.com>
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
#include "g/keymap_combo.h"

enum layers {
    _COLEMAK = 0,
    _GAME,
    _MEDR,
    _NAVR,
    _MOUR,
    _NSSL,
    _NSL,
    _FUNL
};

/* Add definitions for MT and LT */
#define SHFT_T MT(MOD_LSFT, KC_T)
#define SHFT_N MT(MOD_RSFT, KC_N)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define CTRL_S MT(MOD_LCTL, KC_S)
#define CTRL_E MT(MOD_LCTL, KC_E)
#define ALT_R MT(MOD_LALT, KC_R)
#define ALT_I MT(MOD_LALT, KC_I)
#define AGR_X MT(MOD_RALT, KC_X)
#define AGR_DOT MT(MOD_RALT, KC_DOT)
#define GUI_A MT(MOD_LGUI, KC_A)
#define GUI_O MT(MOD_LGUI, KC_O)
#define MED_ESC LT(_MEDR, KC_ESC)
#define NAV_SPC LT(_NAVR, KC_SPC)
#define MOS_TAB LT(_MOUR, KC_TAB)
#define SYM_ENT LT(_NSSL, KC_ENT)
#define NUM_BSC LT(_NSL, KC_BSPC)
#define FN_DEL LT(_FUNL, KC_DEL)
#define COLEMAK DF(_COLEMAK)
#define GAME DF(_GAME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_gergoplex( \
 //,--------------------------------------------.  ,--------------------------------------------.
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
       GUI_A,   ALT_R,  CTRL_S,  SHFT_T,    KC_G,       KC_M,  SHFT_N,  CTRL_E,   ALT_I,   GUI_O,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM, AGR_DOT, KC_SLSH,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                       MED_ESC, NAV_SPC, MOS_TAB,    SYM_ENT, NUM_BSC,  FN_DEL \
                   //`--------------------------'  `--------------------------'
    ),

    [_GAME] = LAYOUT_gergoplex( \
 //,--------------------------------------------.  ,--------------------------------------------.
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SCLN,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                       MED_ESC,  KC_SPC, NAV_SPC,    SYM_ENT, NUM_BSC,  FN_DEL \
                   //`--------------------------'  `--------------------------'
    ),

    [_MEDR] = LAYOUT_gergoplex( \
 //,--------------------------------------------.  ,--------------------------------------------.
     _______,    GAME, COLEMAK, _______, _______,    _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,    _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,\
 //|--------+--------+--------+--------+--------.  ,-----------------+--------+--------+--------|
     _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+--------+--------'
                       _______, _______, _______,    KC_MSTP, KC_MPLY, KC_MUTE \
                   //`--------------------------'  `--------------------------'
    ),

    [_NAVR] = LAYOUT_gergoplex( \
 //,--------------------------------------------.  ,--------------------------------------------.
     _______, _______, _______, _______, _______,    KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,    KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,\
 //|--------+--------+--------+--------+--------.  ,-----------------+--------+--------+--------|
     S(KC_ENT), _______, KC_F2, _______, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                       _______, _______, _______,     KC_ENT, KC_BSPC,  KC_DEL \
                   //`--------------------------'  `--------------------------'
    ),

    [_MOUR] = LAYOUT_gergoplex( \
 //,--------------------------------------------.  ,--------------------------------------------.
     _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,    _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______,    _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                       _______, _______, _______,    KC_BTN3, KC_BTN1, KC_BTN2 \
                   //`--------------------------'  `--------------------------'
    ),

    [_NSSL] = LAYOUT_gergoplex( \
 //,--------------------------------------------.  ,--------------------------------------------.
     KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,    _______, _______, _______, KC_RALT, _______,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                         KC_GT, KC_RPRN, KC_UNDS,    _______, _______, _______ \
                   //`--------------------------'  `--------------------------'
    ),

    [_NSL] = LAYOUT_gergoplex( \
 //,--------------------------------------------.  ,--------------------------------------------.
     KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,    _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
     KC_GRV,     KC_1,    KC_2,    KC_3, KC_BSLS,    _______, _______, _______, KC_RALT, _______,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                        KC_DOT,    KC_0, KC_MINS,    _______, _______, _______ \
                   //`--------------------------'  `--------------------------'
    ),

    [_FUNL] = LAYOUT_gergoplex( \
 //,--------------------------------------------.  ,--------------------------------------------.
     KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,    _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
     KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,    _______, _______, _______, KC_RALT, _______,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                       KC_APP,   KC_SPC,  KC_TAB,    _______, _______, _______ \
                   //`--------------------------'  `--------------------------'
    ),
};

// Disabling permissive hold for home row mods.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { // {{{
    switch (keycode) {
        case SHFT_T:
        case SHFT_N:
        case SFT_ENT:
        case CTRL_S:
        case CTRL_E:
        case ALT_R:
        case ALT_I:
        case AGR_X:
        case AGR_DOT:
        case GUI_A:
        case GUI_O:
            // This actually *disables* the permissive hold for these keys.
            // See issue https://github.com/qmk/qmk_firmware/issues/8999
            return true;
        default:
            return false;
    }
}


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_BSC:
            return false;
        default:
            return true;
    }
}
