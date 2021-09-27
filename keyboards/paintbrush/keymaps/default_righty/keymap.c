/* This keymap is just for testing that the keyboard and OLED are functioning properly.
This is NOT an ARTSEY.IO keymap. It does not require any special ARTSEY files.
If you wish to compile an ARTSEY.IO keymap, read the readme file at paintbrush/keymaps/readme.md 
 */

#include "paintbrush.h"
#include "defaultoled.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, 
		KC_A, KC_S, KC_D, KC_F),

};


