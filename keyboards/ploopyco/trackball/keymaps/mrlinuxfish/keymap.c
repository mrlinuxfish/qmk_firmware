/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, KC_BTN2,
          KC_BTN4, LT(1, KC_BTN5)
    ),
    [1] = LAYOUT(
        DRAG_SCROLL, _______, _______,
          _______, _______
    )
};

extern bool is_drag_scroll;

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

layer_state_t layer_state_set_user(layer_state_t state) {
    static bool is_drag_on = false;
    if (layer_state_cmp(state, 1) != is_drag_on) {
        is_drag_on = layer_state_cmp(state, 1);
        if (is_drag_on) {
            is_drag_scroll = 1;
        } else {
            is_drag_scroll = 0;
        }
    }
    return layer_state_set_keymap(state);
}
