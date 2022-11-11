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
#include "keymap.h"
#include "keymap_steno.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT( \
 //,--------------------------------------------.  ,--------------------------------------------.
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
       GUI_A,   ALT_R,  CTRL_S,  SHFT_T,    KC_G,       KC_M,  SHFT_N,  CTRL_E,   ALT_I,   GUI_O,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM, AGR_DOT, KC_SLSH,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                                NAV_SPC, MOS_TAB,    SYM_ENT, NUM_BSC \
                            //`-----------------'  `-----------------'
    ),

    [_GAME] = LAYOUT( \
 //,--------------------------------------------.  ,--------------------------------------------.
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SCLN,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                                NAV_SPC,  KC_SPC,    NUM_BSC, FN_DEL \
                            //`-----------------'  `-----------------'
    ),

    [_MEDR] = LAYOUT( \
 //,--------------------------------------------.  ,--------------------------------------------.
     _______,    GAME, COLEMAK,  PLOVER, _______,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,    _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,\
 //|--------+--------+--------+--------+--------.  ,-----------------+--------+--------+--------|
     _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+--------+--------'
                                _______, _______,    KC_MSTP, KC_MPLY \
                            //`-----------------'  `-----------------'
    ),

    [_NAVR] = LAYOUT( \
 //,--------------------------------------------.  ,--------------------------------------------.
     _______,    GAME, COLEMAK,  PLOVER, _______,      U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,    KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,\
 //|--------+--------+--------+--------+--------.  ,-----------------+--------+--------+--------|
     S(KC_ENT), _______, KC_F2, _______, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                                _______, _______,     KC_ENT, KC_BSPC \
                            //`-----------------'  `-----------------'
    ),

    [_MOUR] = LAYOUT( \
 //,--------------------------------------------.  ,--------------------------------------------.
     _______, _______, _______, _______, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,    _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
     _______, KC_BTN3, KC_BTN2, KC_BTN1, _______,    _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                                _______, _______,    KC_BTN3, KC_BTN1 \
                            //`-----------------'  `-----------------'
    ),

    [_NSSL] = LAYOUT( \
 //,--------------------------------------------.  ,--------------------------------------------.
     KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,    _______, _______, _______, KC_RALT, _______,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                                KC_RPRN, KC_UNDS,    _______, _______ \
                            //`-----------------'  `-----------------'
    ),

    [_NSL] = LAYOUT( \
 //,--------------------------------------------.  ,--------------------------------------------.
     KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,    _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
     KC_GRV,     KC_1,    KC_2,    KC_3, KC_BSLS,    _______, _______, _______, KC_RALT, _______,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                                   KC_0, KC_MINS,    _______, _______ \
                            //`-----------------'  `-----------------'
    ),

    [_FUNL] = LAYOUT( \
 //,--------------------------------------------.  ,--------------------------------------------.
     KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,    _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
     KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
     KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,    _______, _______, _______, KC_RALT, _______,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                               KC_SPC, UC(0x2014),    _______, _______ \
                            //`-----------------'  `-----------------'
    ),

    [_PLOVER] = LAYOUT( \
 //,--------------------------------------------.  ,--------------------------------------------.
      STN_N1,  STN_N2,  STN_N3,  STN_N4, EXT_PLV,     STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,\
 //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
      STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,     STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,\
 //|--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------|
      STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,     STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,\
 //`-----------------+--------+--------+--------|  |--------+--------+--------+-----------------'
                                  STN_A,   STN_O,      STN_E,   STN_U \
                            //`-----------------'  `-----------------'
    ),
};

// Disabling permissive hold for home row mods.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
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

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_BSC:
            return false;
        default:
            return true;
    }
}

// Layer change code for plover keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PLOVER:
            if (!record->event.pressed) {
                layer_on(_PLOVER);
            }
        case EXT_PLV:
            if (record->event.pressed) {
                layer_off(_PLOVER);
            }
            return false;
            break;
    }
    return true;
}
