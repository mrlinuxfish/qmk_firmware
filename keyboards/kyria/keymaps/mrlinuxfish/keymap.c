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
#ifdef COMBO_ENABLE
  #include "g/keymap_combo.h"
#endif

#include "keymap.h"

#ifdef AUTO_SHIFT_ENABLE
  #include "process_auto_shift.h"
#endif

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT( \
 //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                           KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_BSPC,\
 //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
      KC_ESC,   GUI_A,   ALT_R,  CTRL_S,  SHFT_T,    KC_G,                                           KC_M,  SHFT_N,  CTRL_E,   ALT_I,   GUI_O, KC_SCLN,\
 //|--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, _______, _______,    KC_BTN1, KC_BTN2,    KC_K,    KC_H, KC_COMM, AGR_DOT, KC_SLSH, SFT_ENT,\
 //`--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
                                KC_MUTE, KC_MUTE, MED_ESC, NAV_SPC, MOS_TAB,    SYM_ENT, NUM_BSC,  FN_DEL,  KC_ESC,  KC_ESC \
                            //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_GAME] = LAYOUT( \
 //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
 //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
 //|--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LCTL, _______,    _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SCLN, SFT_ENT,\
 //`--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
                                _______, KC_LALT, MED_ESC,  KC_SPC, NAV_SPC,    SYM_ENT, NUM_BSC,  FN_DEL, _______, _______ \
                            //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_MEDR] = LAYOUT( \
 //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
     _______, _______,    GAME, COLEMAK, KC_ASTG, _______,                                        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,\
 //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                        _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,\
 //|--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,\
 //`--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
                                _______, _______, _______, _______, _______,    KC_MSTP, KC_MPLY, KC_MUTE, _______, _______ \
                            //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_NAVR] = LAYOUT( \
 //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                                          U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND, _______,\
 //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                        KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,\
 //|--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
     _______, S(KC_ENT), _______, KC_F2, _______, _______, _______, _______,    _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,\
 //`--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
                                _______, _______, _______, _______, _______,     KC_ENT, KC_BSPC,  KC_DEL, _______, _______ \
                            //`--------------------------------------------'  `--------------------------------------------'
    ),


    [_MOUR] = LAYOUT( \
 //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                        _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,\
 //|--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
     _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, _______,    _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,\
 //`--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
                                _______, _______, _______, _______, _______,    KC_BTN3, KC_BTN1, KC_BTN2, _______, _______ \
                            //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_NSSL] = LAYOUT( \
 //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
     _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                        _______, _______, _______, _______, _______,  _______,\
 //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
     _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                        _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,\
 //|--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
     _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______,    _______, _______, _______, _______, _______, KC_RALT, _______, _______,\
 //`--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
                                _______, _______, KC_LPRN, KC_RPRN, KC_UNDS,    _______, _______, _______, _______, _______ \
                            //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_NSL] = LAYOUT( \
 //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
     _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                                        _______, _______, _______, _______, _______,  _______,\
 //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
     _______, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                                        _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,\
 //|--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
     _______, KC_GRV,     KC_1,    KC_2,    KC_3, KC_BSLS, _______, _______,    _______, _______, _______, _______, _______, KC_RALT, _______, _______,\
 //`--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
                                _______, _______,  KC_DOT,    KC_0, KC_MINS,    _______, _______, _______, _______, _______ \
                            //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_FUNL] = LAYOUT( \
 //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
     _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                                        _______, _______, _______, _______, _______,  _______,\
 //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
     _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                                        _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,\
 //|--------+--------+--------+--------+--------+--------+-----------------.  ,-----------------+--------+--------+--------+--------+--------+--------|
     _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______, _______,    _______, _______, _______, _______, _______, KC_RALT, _______, _______,\
 //`--------------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------------------------'
                                _______, _______, KC_APP, KC_SPC, UC(0x2014),   _______, _______, _______, _______, _______ \
                            //`--------------------------------------------'  `--------------------------------------------'
    ),
};

// Disabling permissive hold for home row mods.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { // {{{
    switch (keycode) {
//        case SHFT_T:
//        case SHFT_N:
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

#ifdef OLED_DRIVER_ENABLE
// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 30 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 45 // above this wpm value typing animation to trigger

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 636 // number of bytes in array, minimize for adequate firmware size, max is 1024
#define LINE_SIZE 128

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;
static const char PROGMEM base_frame[636] = {0, 0, 126, 126, 24, 60, 102, 66, 0, 12, 28, 112, 112, 28, 12, 0, 116, 116, 20, 20, 124, 104, 0, 124, 124, 0, 112, 120, 44, 36, 124, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 4, 4, 4, 8, 48, 64, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 192, 96, 48, 24, 12, 132, 198, 98, 35, 51, 17, 145, 113, 241, 113, 145, 17, 51, 35, 98, 198, 132, 12, 24, 48, 96, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 100, 130, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 196, 4, 196, 4, 196, 2, 194, 2, 194, 1, 1, 1, 1, 0, 0, 0, 0, 0, 252, 15, 1, 0, 248, 14, 31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224, 249, 166, 164, 148, 148, 140, 109, 31, 14, 248, 0, 1, 15, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 56, 4, 3, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 13, 1, 0, 64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8, 8, 4, 4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 170, 170, 255, 255, 195, 191, 127, 3, 127, 191, 195, 255, 255, 170, 170, 0, 0, 0, 0, 0, 0, 31, 120, 192, 0, 15, 56, 124, 219, 152, 20, 20, 18, 50, 207, 3, 255, 3, 207, 50, 18, 20, 20, 152, 219, 124, 56, 15, 0, 192, 120, 31, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8, 8, 8, 8, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 130, 135, 31, 7, 159, 7, 28, 7, 159, 7, 159, 7, 2, 130, 0, 0, 0, 0, 32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98, 102, 68, 68, 71, 71, 71, 68, 68, 102, 98, 35, 49, 16, 24, 12, 6, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 8, 23, 0, 15, 1, 2, 1, 15, 0, 15, 2, 5, 8};

#define REGIONS_LEN_0 0
static const uint16_t PROGMEM regions_0[REGIONS_LEN_0] = {};
#define DIFF_LEN_0 0
static const char PROGMEM diff_0[DIFF_LEN_0] = {};
#define REGIONS_LEN_1 0
static const uint16_t PROGMEM regions_1[REGIONS_LEN_1] = {};
#define DIFF_LEN_1 0
static const char PROGMEM diff_1[DIFF_LEN_1] = {};
#define REGIONS_LEN_2 26
static const uint16_t PROGMEM regions_2[REGIONS_LEN_2] = {58, 69, 71, 74, 75, 79, 177, 181, 183, 187, 190, 192, 201, 202, 203, 205, 206, 216, 304, 308, 315, 320, 323, 330, 334, 338};
#define DIFF_LEN_2 61
static const char PROGMEM diff_2[DIFF_LEN_2] = {0, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 4, 2, 2, 24, 96, 128, 0, 60, 194, 1, 1, 4, 4, 2, 1, 0, 0, 0, 96, 96, 129, 130, 130, 132, 8, 16, 32, 64, 128, 0, 128, 112, 25, 6, 24, 24, 24, 27, 3, 34, 36, 20, 18, 18, 18, 11, 5, 5, 9, 9};
#define REGIONS_LEN_3 8
static const uint16_t PROGMEM regions_3[REGIONS_LEN_3] = {51, 53, 69, 76, 177, 183, 304, 307};
#define DIFF_LEN_3 18
static const char PROGMEM diff_3[DIFF_LEN_3] = {128, 128, 8, 4, 2, 1, 1, 2, 12, 30, 225, 0, 0, 1, 1, 128, 112, 12};
#define REGIONS_LEN_4 8
static const uint16_t PROGMEM regions_4[REGIONS_LEN_4] = {69, 70, 71, 77, 177, 181, 304, 307};
#define DIFF_LEN_4 14
static const char PROGMEM diff_4[DIFF_LEN_4] = {8, 4, 2, 2, 2, 4, 56, 28, 226, 1, 1, 128, 112, 12};
#define REGIONS_LEN_5 20
static const uint16_t PROGMEM regions_5[REGIONS_LEN_5] = {51, 53, 69, 76, 177, 183, 185, 188, 206, 217, 304, 307, 310, 321, 322, 323, 336, 345, 441, 451};
#define DIFF_LEN_5 63
static const char PROGMEM diff_5[DIFF_LEN_5] = {128, 128, 8, 4, 2, 1, 1, 2, 12, 30, 225, 0, 0, 1, 1, 129, 128, 128, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 128, 112, 12, 24, 6, 5, 152, 153, 132, 195, 124, 65, 65, 64, 32, 4, 4, 4, 4, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define REGIONS_LEN_6 32
static const uint16_t PROGMEM regions_6[REGIONS_LEN_6] = {51, 53, 69, 76, 86, 90, 95, 97, 177, 183, 185, 188, 206, 210, 214, 218, 219, 227, 304, 307, 310, 321, 322, 323, 346, 355, 416, 417, 441, 451, 477, 480};
#define DIFF_LEN_6 78
static const char PROGMEM diff_6[DIFF_LEN_6] = {128, 128, 8, 4, 2, 1, 1, 2, 12, 248, 248, 248, 248, 128, 128, 30, 225, 0, 0, 1, 1, 129, 128, 128, 0, 1, 1, 2, 67, 135, 7, 1, 184, 188, 190, 159, 95, 95, 79, 76, 128, 112, 12, 24, 6, 5, 152, 153, 132, 67, 124, 65, 65, 64, 32, 61, 124, 252, 252, 252, 252, 252, 60, 12, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3};

#define REGIONS_LEN_7 22
static const uint16_t PROGMEM regions_7[REGIONS_LEN_7] = {51, 53, 69, 76, 177, 183, 206, 217, 304, 307, 315, 319, 336, 345, 433, 441, 448, 452, 565, 572, 576, 584};
#define DIFF_LEN_7 69
static const char PROGMEM diff_7[DIFF_LEN_7] = {128, 128, 8, 4, 2, 1, 1, 2, 12, 30, 225, 0, 0, 1, 1, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 128, 112, 12, 0, 0, 0, 1, 4, 4, 4, 4, 2, 2, 2, 1, 1, 122, 122, 121, 121, 121, 121, 57, 49, 136, 136, 135, 128, 48, 120, 124, 254, 255, 63, 7, 255, 255, 127, 127, 63, 62, 28, 24};


void write_frame(const uint16_t* regions, const uint16_t regions_len, const char* diff, const uint16_t diff_len) {
    uint16_t diff_index = 0;
    for (uint16_t region_index = 0; region_index < regions_len; region_index += 2) {
        uint16_t start = pgm_read_word_near(regions + region_index);
        uint16_t end = pgm_read_word_near(regions + region_index + 1);
        oled_write_raw_range_P(diff + diff_index,start , end);
        diff_index += end - start;
    }
}


#define WRITE_FRAME(INDEX) \
    write_frame(&regions_##INDEX[0], REGIONS_LEN_##INDEX, &diff_##INDEX[0], DIFF_LEN_##INDEX)

void write_frame_at_index(int index) {
    switch (index) {
        case 0:
            WRITE_FRAME(0);
            break;
        case 1:
            WRITE_FRAME(1);
            break;
        case 2:
            WRITE_FRAME(2);
            break;
        case 3:
            WRITE_FRAME(3);
            break;
        case 4:
            WRITE_FRAME(4);
            break;
        case 5:
            WRITE_FRAME(5);
            break;
        case 6:
            WRITE_FRAME(6);
            break;
        case 7:
            WRITE_FRAME(7);
            break;
        default:
            break;
    }
}

static void render_anim(void) {
  void animation_phase(void) {
    oled_clear();
    oled_write_raw_P(base_frame, ANIM_SIZE);
    if(get_current_wpm() <=IDLE_SPEED){
        current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
        int index = abs(IDLE_FRAMES - 1 - current_idle_frame);
        write_frame_at_index(index);
     }
     if(get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED){
         int index = IDLE_FRAMES;
         write_frame_at_index(index);
     }
     if(get_current_wpm() >= TAP_SPEED){
         current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
         int index = IDLE_FRAMES + 1 + abs(TAP_FRAMES - 1 - current_tap_frame);
         write_frame_at_index(index);
     }
  }

  if(get_current_wpm() != 0) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress

        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();

    switch (get_highest_layer(default_layer_state)) {
        case _GAME:
            oled_write_P(PSTR("Qwerty"), false);
            break;
        default:
            oled_write_P(PSTR("Colemak DHm"), false);
    }
#ifdef AUTO_SHIFT_ENABLE
    // Auto shift state
    switch (get_autoshift_state()) {
        case true:
            oled_write_P(PSTR(" Auto"), false);
        default:
            oled_write_P(PSTR("\n"), false);
    }
#else
    oled_write_P(PSTR("\n"), false);
#endif
    oled_write_P(PSTR("\n"), false);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _MEDR:
            oled_write_P(PSTR("Media\n"), false);
            break;
        case _NAVR:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _MOUR:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _NSSL:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case _NSL:
            oled_write_P(PSTR("Number\n"), false);
            break;
        case _FUNL:
            oled_write_P(PSTR("Fn\n"), false);
            break;
       default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

char wpm_str[10];
void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_anim();
        uint8_t n = get_current_wpm();
        char wpm_counter[4];
        wpm_counter[3] = '\0';
        wpm_counter[2] = '0' + n % 10;
        wpm_counter[1] = ( n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
        wpm_counter[0] = n / 10 ? '0' + n / 10 : ' ';
        oled_set_cursor(0,6);
        oled_write("       WPM:", false);
        if (wpm_counter[0]==' ') {
            if (wpm_counter[1]==' ') {
                oled_write(&wpm_counter[2], false);
            } else {
                oled_write(&wpm_counter[1], false);
            }
        } else {
            oled_write(&wpm_counter[0], false);
        }
    }
}
#endif

#ifdef AUTO_SHIFT_ENABLE
// Disable auto shift by default on game layer
layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _GAME:
        autoshift_disable();
        break;
    default:
        autoshift_enable();
        break;
    }
return state;
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Scroll through active workspaces i3
        if (clockwise) {
            tap_code(KC_VOLU);
            // tap_code16(G(C(S((KC_RGHT)))));
        } else {
            tap_code(KC_VOLD);
            // tap_code16(G(C(S((KC_LEFT)))));
        }
    }
    else if (index == 1) {
        // Scroll through unread Discord channels
        if (clockwise) {
            tap_code16(S(A(KC_UP)));
        } else {
            tap_code16(S(A(KC_DOWN)));
        }
    }
}
#endif
