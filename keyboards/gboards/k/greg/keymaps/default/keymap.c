/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "keymap.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

/* Combomap
 *
 * ,-----------------------.       ,--------------------------------.
 * |     |    ESC    |     |      |     |    ESC    |    BSLH      |
 * |-----+-----+-----+-----|      |-----+-----+-----+--------------|
 * |     |   BSPC   ENT    |      |    LES   COLN  GRT    |        |
 * `-----+-----+-----+-----'      `--------------------------------'
 *  .----------------.           .-----------------.
 *  |        |       |           |        |    |   |
 *  '----------------'           '-----------------'
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,------------------------.      ,--------------------------.
 * |    Q |  W  |  E  |  R  |      |  U  |  I  |  O  |    P   |
 * |----A-+--S--+--D--+--F--|      |--J--+--K--+--L--+----;---|
 * |SHFT/Z|  X  |  C  |  V  |      |  M  |  <  |  >  | SHFT/? |
 * `------+-----+-----+-----'      `--------------------------'
 *  .-------------------------.           .-----------------.
 *  |ESC/META|ENT/ALT|SPC(SYM)|           |SPC(NUM)|BSPC|TAB|
 *  '-------------------------'           '-----------------'
 */
[BASE] = LAYOUT_split_2x4_2(
    KC_Q,   KC_W, KC_E, KC_R,     KC_U, KC_I,    KC_O,   KC_P,
    SHFT_Z, KC_X, KC_C, KC_V,     KC_M, KC_COMM, KC_DOT, SFT_SSH,
            ALT_ENT, SYM_SPC,     NUM_SPC, KC_BSPC
    ),
/* Keymap 1: Symbols layer
 * ,-----------------------------.       ,--------------------------------.
 * |  !   |  @  |  {  |  }  |       |  `  |  ~  |     |     |    \   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |  #   |  $  |  (  |  )  | LMB |      |  +  |  -  |  /  |  *  |    '   |
 * |-----+-----+-----+-----+------+        |--------------------------------|
 * |  %   |  ^  |  [  |  ]  | RMB |      |  &  |  =  |  ,  |  .  |   -    |
 * `------+-----+-----+------+----'        `--------------------------------'
 *             .-----------------.           .------------------.
 *             |MMB |  ;  |   =  |           |  =  |  ;  |  DEL |
 *             '-----------------'           '------------------'
 */
[SYMB] = LAYOUT_split_2x4_2(
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR,   KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC,   KC_EQL,  KC_COMM, KC_DOT,  KC_MINS,
                      KC_SCLN, KC_EQL,    KC_EQL,  KC_SCLN
    ),
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |-----+-----+-----+-----+------|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP |
 * |-----+-----+-----+-----+------+        |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      |MLFT | MDWN| MUP | MRGT| VOLDN |
 * `------+-----+-----+------+----'        `-------------------------------'
 *                  .-----------------.           .-----------------.
 *                  | F11 | F12|        |                       |     | PLY | SKP |
 *                  '-----------------'           '-----------------'
 */
[NUMB] = LAYOUT_split_2x4_2(
    KC_1,  KC_2,  KC_3,   KC_4,       KC_7,    KC_8,    KC_9,    KC_0,
    KC_F6, KC_F7, KC_F8,  KC_F9,      KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
                  KC_F11, KC_F12,     KC_MPLY, KC_MNXT
    )
};
