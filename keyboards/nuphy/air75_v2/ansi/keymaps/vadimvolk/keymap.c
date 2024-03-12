/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    L_MAIN,
    L_NEW_TAB,
    L_MEDIA_LAUNCHER, // media control. all keys sent together with KC_LAUNCHER for intercept with Karabiner Elements
    L_CONTROL, // keyboard control
    // original layers for reference
    // L_WINDOWS,
    // L_WINDOWS_MEDIA,
    // L_SIDE_CTL
};


enum my_keycodes {
    _KC_CLP_M = RGB_TEST + 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer Mac
[L_MAIN] = LAYOUT_ansi_84(
	KC_ESC, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  						KC_F7,  	KC_F8,  	KC_F9, 			KC_F10, 	KC_F11, 	KC_F12, 	MAC_PRT,	_KC_CLP_M,	KC_F13,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,    	KC_5,   	KC_6,   						KC_7,   	KC_8,   	KC_9,  			KC_0,   	KC_MINS,	KC_EQL, 				KC_BSPC,	MO(L_CONTROL),
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   						KC_U,   	KC_I,   	KC_O,  			KC_P,   	KC_LBRC,	KC_RBRC, 				KC_BSLS,	_______,
	KC_CAPS,	KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   						KC_J,   	KC_K,   	KC_L,  			KC_SCLN,	KC_QUOT, 	 						KC_ENT,		KC_PGUP,
	KC_LSFT,				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   						KC_N,   	KC_M,   	KC_COMM,		KC_DOT,		KC_SLSH,				KC_RSFT,	KC_UP,		KC_PGDN,
	KC_LCTL,	KC_LALT,	KC_LGUI,										LT(L_MEDIA_LAUNCHER, KC_SPC), 							KC_RGUI,		KC_RALT,   	KC_RCTL,				KC_LEFT,	KC_DOWN,    KC_RGHT),

[L_MEDIA_LAUNCHER] = LAYOUT_ansi_84(
	_______, 	KC_BRID,  					KC_BRIU,  					MAC_TASK, 	KC_F13,		MAC_VOICE,  						MAC_DND,    						KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 							KC_VOLD, 	KC_VOLU, 	MAC_PRTA,	_______,	_______,
	_______, 	QK_DYNAMIC_MACRO_PLAY_1,  	QK_DYNAMIC_MACRO_PLAY_2,  	_______,  	_______,   	QK_DYNAMIC_MACRO_RECORD_START_1,   	QK_DYNAMIC_MACRO_RECORD_START_2,   	_______,   	_______,   	_______,  	QK_DYNAMIC_MACRO_RECORD_STOP,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   					_______,   					_______,  	_______,   	_______,   							_______,   							_______,   	_______,   	_______,  	_______,   							_______,	_______, 				_______,	_______,
	_______,	_______,   					_______,   					_______,  	_______,   	_______,   							_______,							_______,   	_______,   	_______,  	_______,							_______, 	 						_______,	_______,
	_______,								_______,   					_______,   	_______,  	_______,   							_______,   							_______,	_______, 	_______,	_______,							_______,				_______,	_______,	_______,
	_______,	_______,					_______,																				_______, 							_______,	_______,   													_______,				_______,	_______,    _______),

[L_CONTROL] = LAYOUT_ansi_84(
	_______, 	_______,  	_______,  	_______, 	_______,	_______,  	_______,    _______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______, 	RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

/*
// layer Mac Fn
[L_MEDIA] = LAYOUT_ansi_84(
	_______, 	KC_BRID,  	KC_BRIU,  	MAC_TASK, 	KC_F13,		MAC_VOICE,  MAC_DND,    KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU, 	MAC_PRTA,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	MO(4), 		RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(1),   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

// layer win
[L_WINDOWS] = LAYOUT_ansi_84(
	KC_ESC, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR,	KC_INS,		KC_DEL,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 				KC_BSPC,	KC_PGUP,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC, 				KC_BSLS,	KC_PGDN,
	KC_CAPS,	KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 						KC_ENT,		KC_HOME,
	KC_LSFT,				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,				KC_RSFT,	KC_UP,		KC_END,
	KC_LCTL,	KC_LGUI,	KC_LALT,										KC_SPC, 							KC_RALT,	MO(3),   	KC_RCTL,				KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer win Fn
[L_WINDOWS_MEDIA] = LAYOUT_ansi_84(
	_______, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,   	KC_MPLY,   	KC_MNXT,  	KC_MUTE, 	KC_VOLD, 	KC_VOLU,	_______,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	MO(4), 		RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(3),   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

// layer 4
[L_SIDE_CTL] = LAYOUT_ansi_84(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	SIDE_SPD,	SIDE_SPI,	_______,				_______,	SIDE_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(4),   	_______,				SIDE_MOD,	SIDE_VAD,   SIDE_HUI)*/
};

/* qmk process record */
bool process_record_vadimvolk(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _KC_CLP_M:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_V);
                wait_ms(50);
                unregister_code(KC_V);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            return false;
        default:
            return true;
    }
}

bool launcherSent = false;

layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case L_MEDIA_LAUNCHER:
			register_code(KC_LAUNCHER);
			launcherSent = true;
			break;
		default:
			if (launcherSent) {
				launcherSent = false;
				unregister_code(KC_LAUNCHER);
			}
			break;
	}
	return state;
}
