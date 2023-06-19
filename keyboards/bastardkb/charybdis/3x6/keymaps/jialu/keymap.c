/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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
 *
 * qmk flash -kb bastardkb/charybdis/3x6/v2/splinky_3 -km jialu
*/
#include QMK_KEYBOARD_H

//#include "ps2_mouse.h"

enum custom_keycodes {
  F_LABEL = SAFE_RANGE,
  SCLN_SCR,
  SLSH_SCH,
  Y_LWIN,
  U_RWIN,
  N_BACK,
  M_FWD,
  QUO_SCL,
};

#define RESET QK_BOOT
#define LFTWIN LSA(KC_J)
#define RGTWIN LSA(KC_K)
#define ALTTAB LALT_T(KC_TAB)
#define CTLESC LCTL_T(KC_ESC)
#define RSFDEL RSFT_T(KC_DEL)
#define GUIRT  LGUI_T(KC_RGHT)
#define SFTLFT LSFT_T(KC_LEFT)
#define ENTMOU LT(4,KC_ENT)
#define SPCSCRN LT(5,KC_SPC)
#define PRETAB RCS(KC_TAB)
#define NXTTAB LCTL(KC_TAB)
#define ALTLFT LALT(KC_LEFT)
#define ALTRT  LALT(KC_RGHT)
#define SCN1   LCTL(KC_1)
#define SCN2   LCTL(KC_2)
#define SCN3   LCTL(KC_3)
#define SCN4   LCTL(KC_4)
#define PRESCN LCTL(KC_LEFT)
#define NXTSCN LCTL(KC_RGHT)
#define COPY   LGUI(KC_C)
#define PASTE  LGUI(KC_V)
#define SPASTE SGUI(KC_V)

/* Keymap - @jialu*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE (ALPHAS) */
  [0] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       ALTTAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       Y_LWIN,  U_RWIN,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
       CTLESC,    KC_A,    KC_S,    KC_D, F_LABEL,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,SCLN_SCR, KC_QUOT,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
       SFTLFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       N_BACK,   M_FWD, KC_COMM,  KC_DOT,SLSH_SCH,  ENTMOU,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            GUIRT,   MO(1),  KC_SPC,    SPCSCRN,   MO(2)
                                      //`--------------------------'  `--------------------------'
  ),


  /* NUMBERS */
  [1] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,   KC_NO, KC_MINS,  KC_EQL,   KC_NO,   KC_NO,                       PRETAB,  NXTTAB, KC_LBRC, KC_RBRC,   KC_UP,  KC_DEL,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9, KC_LEFT, KC_RGHT,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       ALTLFT,   ALTRT, KC_BSLS,  KC_DOT, KC_DOWN,    KC_0,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS, KC_TRNS,    KC_TRNS,   MO(3)
                                      //`--------------------------'  `--------------------------'
  ),

  /* SYMBOLS */
  [2] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO, KC_UNDS, KC_PLUS,   KC_NO,   KC_NO,                        KC_NO,   KC_NO, KC_LCBR, KC_RCBR,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,    COPY,   PASTE,  SPASTE,                        KC_NO,   KC_NO, KC_PIPE, KC_RPRN, KC_HOME,  KC_END,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   MO(3), KC_TRNS,    KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),


  /* SPECIALS */
  [3] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
        KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_MPRV,                      KC_MNXT, KC_BRMD,  KC_BRK, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, RGB_VAD, RGB_VAI, RGB_TOG, RGB_MOD, RGB_HUD,                      RGB_HUI, RGB_SAD, RGB_SAI, RGB_SPI, RGB_SPD,   RESET,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            RESET, _______, KC_TRNS,    KC_TRNS, _______
                                      //`--------------------------'  `--------------------------'
  ),

  /* MOMENTARY MOUSE BUTTONS */
  [4] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
       CTLESC, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,SCLN_SCR, XXXXXXX,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN3,   MO(1), KC_BTN2,    KC_BTN1, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  /* SCREEN SWITCH */
  [5] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       LFTWIN,  RGTWIN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
      XXXXXXX,    SCN1,    SCN2,    SCN3, KC_WH_U, XXXXXXX,                      XXXXXXX,  PRESCN, NXTSCN,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX,                      KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};


bool isBarking = false;
bool isSneaking = false;

void handle_tap_hold_keycode(uint16_t* keycode, uint16_t timer) {
    if (*keycode == 0) return;
    uint16_t tapping_term = 170;
    if (*keycode == KC_N || *keycode == KC_M) {
        tapping_term = 300;
    }
    // Mod key is on. No need to process tap/hold.
    if (!isSneaking && !isBarking && timer_elapsed(timer) >= tapping_term) {
        if (*keycode == KC_F || *keycode == KC_SCLN || *keycode == KC_SLSH || *keycode == KC_Y || *keycode == KC_U) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            tap_code(*keycode);
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
        }
        if (*keycode == KC_N) {
            register_code(KC_LGUI);
            tap_code(KC_LBRC);
            unregister_code(KC_LGUI);
        }
        if (*keycode == KC_M) {
            register_code(KC_LGUI);
            tap_code(KC_RBRC);
            unregister_code(KC_LGUI);
        }
    } else {
        tap_code(*keycode);
    }
    *keycode = 0;   // Resets.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
#ifdef RGB_MATRIX_REST_MODE
    if (!(process_record_user_rgb_matrix(keycode, record)&& true)) {
        return false;
    }
#endif
    static uint16_t timer;
    static uint16_t tap_hold_keycode;
    switch(keycode) {
        case SFTLFT:
	    isBarking = record->event.pressed;
            break;
        case GUIRT:
	    isSneaking = record->event.pressed;
            break;
	case CTLESC:
	    charybdis_set_pointer_sniping_enabled(record->event.pressed);
	    break;
	case SCLN_SCR:
	    charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
	    if(record->event.pressed) {
	        timer = timer_read();
	    } else {
		if (timer_elapsed(timer) < TAPPING_TERM) {
		    SEND_STRING(";");
		}
	    }
	    break;
        case F_LABEL:
    	    handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
            	tap_hold_keycode = KC_F;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case SLSH_SCH:
    	    handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
            	tap_hold_keycode = KC_SLSH;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case Y_LWIN:
    	    handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
            	tap_hold_keycode = KC_Y;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case U_RWIN:
    	    handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
            	tap_hold_keycode = KC_U;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case N_BACK:
    	    handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
            	tap_hold_keycode = KC_N;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case M_FWD:
    	    handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
            	tap_hold_keycode = KC_M;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        default: {
            handle_tap_hold_keycode(&tap_hold_keycode, timer);
            break;
        }
    }
    return true;
}

void pointing_device_init_user(void) {
  set_auto_mouse_enable(true);
}
