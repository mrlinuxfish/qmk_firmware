/* Copyright 2020 Dustin Bosveld <steamyleafjuice@protonmail>
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

#define COMBO_ALLOW_ACTION_KEYS
#define COMBO_PERMISSIVE_HOLD
#define COMBO_ONLY_FROM_LAYER 0 //Enable positional combos


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
