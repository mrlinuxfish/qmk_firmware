/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

// Add retro shift and auto shift
#ifdef AUTO_SHIFT_ENABLE
  #define RETRO_SHIFT 500
  #define AUTO_SHIFT_TIMEOUT 175
  #define NO_AUTO_SHIFT_SPECIAL
  #define NO_AUTO_SHIFT_NUMERIC
#endif

// Fix problems with fast typing and homerow mods
#define TAPPING_TERM 125
#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD_PER_KEY
#define BILATERAL_COMBINATIONS

// Unicode support
#define UNICODE_SELECTED_MODES UC_LNX

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 60000
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // Orients Kyria LEDs to a circle around both halves. From James Incandenza
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_SLEEP true  // turn off leds on sleep
  #define RGBLIGHT_LIMIT_VAL 150 // Fix led brightness brownout issue
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

// #define SPLIT_USB_TIMEOUT 2500

// USB wakeup option allows both sides to initialize propperly when booting
// EE_HANDS sets side of board in eeprom
#define USB_SUSPEND_WAKEUP_DELAY 0
#define EE_HANDS

// Disable unnecessary features
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2
#define ENCODER_DIRECTION_FLIP
