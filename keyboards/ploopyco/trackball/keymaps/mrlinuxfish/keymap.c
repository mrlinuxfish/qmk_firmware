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

enum my_keycodes {
    WHEELDPI = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, KC_BTN2,
          KC_BTN4, LT(1, KC_BTN5)
    ),
    [1] = LAYOUT(
        _______, _______, _______,
          WHEELDPI, _______
    )
};

// Set the wheel dpi to 1 while holding WHEELDPI
// for some reason, the wheel is disabled when a layer key is held
extern uint8_t wheel_dpi;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WHEELDPI:
      if (record->event.pressed) {
          wheel_dpi = 1;
      } else {
          wheel_dpi = 3;
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

extern bool is_drag_scroll;

layer_state_t layer_state_set_user(layer_state_t state) {
    static bool is_drag_on = false;
    if (layer_state_cmp(state, 1) != is_drag_on) {
        is_drag_on = layer_state_cmp(state, 1);
        if (is_drag_on) {
            is_drag_scroll = 1;
            pmw_set_cpi(is_drag_scroll ? 100 : dpi_array[keyboard_config.dpi_config]);
        } else {
            is_drag_scroll = 0;
            pmw_set_cpi(is_drag_scroll ? 1500 : dpi_array[keyboard_config.dpi_config]);
        }
    }
    return state;
}
