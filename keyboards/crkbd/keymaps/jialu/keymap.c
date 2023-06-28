/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
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
#include <stdio.h>
#include <keymap.h>
#include "jialu.h"

// Debug
#if defined CONSOLE_ENABLE
#include <print.h>
#endif

// Mouse stuff
#if defined PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#endif

#if defined MOUSEKEY_ENABLE
#include "mousekey.h"
#endif

enum custom_keycodes {
  G_LABEL = SAFE_RANGE,
  SCLN_SCR,
  SLSH_SCH,
  Y_LWIN,
  U_RWIN,
  N_BACK,
  M_FWD,
};

/* Keymap macros - @jialu */
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
#define LOWER  LT(1,KC_LEFT)
#define RAISE  LT(2,KC_RGHT)

#define MC_LANG   LCTL(LALT(KC_SPC))    // Switch keyboard language
#define MC_WNDF   RCTL(RALT(KC_DOWN))   // Spectacle: fullsize window
#define MC_WNDL   RCTL(RALT(KC_LEFT))   // Spectacle: left half
#define MC_WNDR   RCTL(RALT(KC_RGHT))   // Spectacle: right half
#define MC_SLP    LGUI(LCTL(KC_Q))      // Put display to sleep
#define MC_SCR0   LGUI(LSFT(KC_3))      // Take screenshot
#define MC_SCR1   LGUI(LSFT(KC_4))      // Take partial screenshot

#define MC_SFAL   MT(MOD_LSFT|MOD_LALT|MOD_RSFT|MOD_RALT,KC_NO) // Shift-alt

/* Keymap - @jialu*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE (ALPHAS) */
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       ALTTAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       Y_LWIN,  U_RWIN,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
       CTLESC,    KC_A,    KC_S,    KC_D,    KC_F, G_LABEL,                         KC_H,    KC_J,    KC_K,    KC_L,SCLN_SCR, KC_QUOT,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
       SFTLFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       N_BACK,   M_FWD, KC_COMM,  KC_DOT,SLSH_SCH,  ENTMOU,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            GUIRT,   MO(1),  KC_SPC,    SPCSCRN,   MO(2),  RSFDEL
                                      //`--------------------------'  `--------------------------'
  ),


  /* NUMBERS */
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO, KC_MINS,  KC_EQL,   KC_NO,   KC_NO,                       PRETAB,  NXTTAB, KC_LBRC, KC_RBRC,   KC_UP,  KC_DEL,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9, KC_LEFT, KC_RGHT,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       ALTLFT,   ALTRT, KC_BSLS,  KC_DOT, KC_DOWN,    KC_0,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS, KC_TRNS,    KC_TRNS,   MO(3), KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  /* SYMBOLS */
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO, KC_UNDS, KC_PLUS,   KC_NO,   KC_NO,                        KC_NO,   KC_NO, KC_LCBR, KC_RCBR,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,    COPY,   PASTE,  SPASTE,                        KC_NO,   KC_NO, KC_PIPE, KC_RPRN, KC_HOME,  KC_END,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   MO(3), KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),


  /* SPECIALS */
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
        KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_MPRV,                      KC_MNXT, KC_BRMD,  KC_BRK, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, RGB_VAD, RGB_VAI, RGB_TOG, RGB_MOD, RGB_HUD,                      RGB_HUI, RGB_SAD, RGB_SAI, RGB_SPI, RGB_SPD,   RESET,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            RESET, _______, KC_TRNS,    KC_TRNS, _______,    RESET
                                      //`--------------------------'  `--------------------------'
  ),

  /* MOMENTARY MOUSE BUTTONS FOR TRACKPOINT */
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, KC_WH_D, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN3, KC_BTN1, KC_BTN2,    KC_BTN1, KC_BTN2, KC_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

  /* SCREEN SWITCH */
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       LFTWIN,  RGTWIN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|--------|                    |--------|--------+--------+--------+--------+--------|
      XXXXXXX,    SCN1,    SCN2,    SCN3, KC_WH_U, XXXXXXX,                      XXXXXXX,  PRESCN, NXTSCN,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX,                      KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};


char wpm_str[10];
uint8_t current_wpm = 0;

/* keyboard pet jump status variables */
bool isBarking = false;
bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;

char keylog_str[24] = {};

/* This section from crkbd:default
 * Luna qmk pet from HellSingCoder
 * Send debug info to OLED */
#ifdef OLED_ENABLE

static const char PROGMEM layer_names[5][5] = {
  "Base",
  "Num",
  "Sym",
  "Fn",
  "     ",
};

// recall that layer_state flips bits for each layer that is activated;
// multiple layers may be active
void oled_render_layer_state(int KEYBOARD_X, int KEYBOARD_Y) {
    oled_set_cursor(KEYBOARD_X, KEYBOARD_Y);
    oled_write_P(PSTR("Layer"), false);
    if (IS_LAYER_ON(MH_AUTO_BUTTONS_LAYER)) {
        oled_write_ln_P(PSTR("Mouse"), false);
        return;
    }
    // Loop through layers in reverse. Write & quit on the first active one.
    for(int i = 5; i >= 0; i--) {
        if (IS_LAYER_ON(i)) {
            oled_write_ln_P(layer_names[i], false);
            oled_write_ln_P(PSTR("     "), false);
            return;
        }
    }
    oled_write_ln_P(PSTR("???"), false);
}


// const char code_to_name[60] = {
//     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
//     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
//     'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
//     'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
//     '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

// void set_keylog(uint16_t keycode, keyrecord_t *record) {
//     char name = ' ';
//     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
//         (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
//     if (keycode < 60) {
//         name = code_to_name[keycode];
//     }
//     bool on_left = (record->event.key.row < 4);
//     sprintf(keylog_str, "%c%dx%d ", on_left ? 'L' : 'R', record->event.key.row % 4, record->event.key.col);
//     switch (keycode) {
//         case KC_BSPC:
//             snprintf(keylog_str, sizeof(keylog_str), "<<<<<");
//             break;
//         case KC_RGUI:
//             snprintf(keylog_str, sizeof(keylog_str), ">CMD_RHT<");
//             break;
//         case KC_LCTL:
//         case KC_RCTL:
//             snprintf(keylog_str, sizeof(keylog_str), ">CTL<");
//             break;
//         default:
//             snprintf(keylog_str + strlen(keylog_str), sizeof(keylog_str), " %c(%2d)   ", name, keycode);
//             break;
//     }
// }

void oled_render_keylog(int KEYBOARD_X, int KEYBOARD_Y) {
    oled_set_cursor(KEYBOARD_X, KEYBOARD_Y);
    oled_write(keylog_str, false);
}

void oled_render_wpm(int KEYBOARD_X, int KEYBOARD_Y) {
    oled_set_cursor(KEYBOARD_X, KEYBOARD_Y);
    sprintf(wpm_str, "WPM: %03d", current_wpm);
    oled_write(wpm_str, false);                       // writes wpm on top left corner of string
}

/* Keyboard Pet settings */
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 50
#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
#define ANIM_SIZE 96 // number of bytes per image

/* Keyboard Pet status variables */
uint8_t current_frame = 0;
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* Keyboard Pet logic */
static void render_keyboard_pet(int KEYBOARD_PET_X, int KEYBOARD_PET_Y) {

    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
            0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
            0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
            0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {
        {
            0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
            0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
            0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
            0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {
        {
            0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    // Sneak
    // static const char PROGMEM sneak[2][ANIM_SIZE] = {
    //     // 'sneak1', 32x22px
    //     {
    //         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
    //         0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    //         0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
    //         0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00,
    //         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
    //         0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
    //     },

    //     // 'sneak2', 32x22px
    //     {
    //         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    //         0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    //         0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
    //         0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00,
    //         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
    //         0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    //     }
    // };

    /* animation */
    void animate_keyboard_pet(void) {

        /* jump */
        if (isJumping || !showedJump) {
            oled_set_cursor(KEYBOARD_PET_X,KEYBOARD_PET_Y +2);
            oled_write_P(PSTR("     "), false);
            oled_set_cursor(KEYBOARD_PET_X,KEYBOARD_PET_Y -1);
            showedJump = true;
        } else {
            oled_set_cursor(KEYBOARD_PET_X,KEYBOARD_PET_Y -1);
            oled_write_P(PSTR("     "), false);
            oled_set_cursor(KEYBOARD_PET_X,KEYBOARD_PET_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current animation status */
        if (isBarking) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);
        // } else if(isSneaking) {
            // oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);
        } else if(current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);
        } else if(current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);
        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        if(timer_elapsed32(anim_sleep) < OLED_TIMEOUT) {
            animate_keyboard_pet();
        }
    }

}

static void print_status_narrow(void) {

    /* Print current OS */
    // oled_set_cursor(2,0);
    // if (keymap_config.swap_lctl_lgui) {
    //     oled_write_P(PSTR("\x9E"), false);
    // } else {
    //     oled_write_P(PSTR("\x9F"), false);
    // }

    /* Print current layer */
    if(timer_elapsed32(anim_sleep) < OLED_TIMEOUT) {
        oled_render_layer_state(0, 0);
        oled_render_keylog(0, 3);
        oled_render_wpm(0, 7);
        /* Keyboard Pet Render */
        render_keyboard_pet(0,13);
    }

   /* Joystick debugging */
#      ifdef JOYSTICK_ENABLE
        if (joystick_debug) {
            oled_set_cursor(0,10);
            oled_write_P(PSTR("X:"), false);
            uint16_t val = analogReadPin(JOYSTICK_X_PIN);
            char val_str[3];
            itoa(val, val_str, 10);
            oled_write(val_str, false);
            oled_set_cursor(0,11);
            oled_write_P(PSTR("Y:"), false);
            val = analogReadPin(JOYSTICK_Y_PIN);
            itoa(val, val_str, 10);
            oled_write(val_str, false);
        } else {
            oled_set_cursor(0,10);
            oled_write_P(PSTR("     "), false);
            oled_set_cursor(0,11);
            oled_write_P(PSTR("     "), false);
        }
#       endif


    if (current_wpm > 0) {
        anim_sleep = timer_read32();
    } else if(timer_elapsed32(anim_sleep) >= OLED_TIMEOUT) {
        if(is_oled_on() && timer_elapsed32(anim_sleep) > OLED_TIMEOUT + 100) {
            anim_sleep = timer_read32();
        } else {
            oled_off();
        }
    }
}

/* vertical screens orientation fix */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    /* Keyboard Pet Variables */
#ifdef WPM_ENABLE
    current_wpm = get_current_wpm();
#endif
    print_status_narrow();
    return false;
}

#endif // OLED_ENABLE

const char code_to_name[58] = {
    ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/'};
const char code_to_name_extra[30] = {
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', // 542-551
    ' ', ' ', ' ', ' ', ' ', '_', '+', '{', '}', '|', // 552-561
    ' ', ' ', ' ', '~', ' ', ' ', ' ', ' ', ' ', ' ', // 562-571
    };

void handle_tap_hold_keycode(uint16_t* keycode, uint16_t timer) {
    if (*keycode == 0) return;
    uint16_t tapping_term = 300;
    // Mod key is on. No need to process tap/hold.
    if (!isSneaking && !isBarking && timer_elapsed(timer) >= tapping_term) {
        if (*keycode == KC_G || *keycode == KC_SCLN || *keycode == KC_SLSH || *keycode == KC_Y || *keycode == KC_U) {
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
    char keystr[10] = "";
    switch(keycode) {
        case ENTMOU:
            strcpy(keystr, "ENTER   ");
        case SFTLFT:
	    isBarking = record->event.pressed;
            if (keystr[0] == '\0') {
                strcpy(keystr, "SFT  LFT");
            }
            break;
        case CTLESC:
            strcpy(keystr, "CTL  ESC");
        case GUIRT:
            isSneaking = record->event.pressed;
	    if (keystr[0] == '\0') {
                strcpy(keystr, "CMD  RGT");
            }
            break;
        case KC_SPC:
            strcpy(keystr, "SPACE   ");
        case ALTTAB:
            if (record->event.pressed) {
                /*Keyboard Pet jump*/
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            if (keystr[0] == '\0') {
                strcpy(keystr, "ALT  TAB");
            }
            break;
        case RSFDEL:
            strcpy(keystr, "SFT  DEL");
            break;
        case KC_BSPC:
            strcpy(keystr, "BS      ");
            break;
        case KC_LEFT:
            strcpy(keystr, "LEFT    ");
            break;
        case KC_RGHT:
            strcpy(keystr, "RIGHT    ");
            break;
        case KC_UP:
            strcpy(keystr, "UP       ");
            break;
        case KC_DOWN:
            strcpy(keystr, "DOWN     ");
            break;
        default:
            break;
    }
    switch(keycode) {
        case G_LABEL:
            keycode = 10;
            handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
                tap_hold_keycode = KC_G;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case SCLN_SCR:
            keycode = 51;
            handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
                tap_hold_keycode = KC_SCLN;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case SLSH_SCH:
            keycode = 56;
            handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
                tap_hold_keycode = KC_SLSH;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case Y_LWIN:
            keycode = 28;
            handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
                tap_hold_keycode = KC_Y;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case U_RWIN:
            keycode = 24;
            handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
                tap_hold_keycode = KC_U;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case N_BACK:
            keycode = 17;
            handle_tap_hold_keycode(&tap_hold_keycode, timer);
            if(record->event.pressed) {
                tap_hold_keycode = KC_N;
                timer = timer_read();
            } else {
                handle_tap_hold_keycode(&tap_hold_keycode, timer);
            }
            break;
        case M_FWD:
            keycode = 16;
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
#ifdef OLED_ENABLE
    if (keycode < 58) {
        char name = code_to_name[keycode];
        snprintf(keystr, sizeof(keystr), "%c-%d     ", name, keycode);
    } else if (keycode > 541 && keycode < 572) {
        char name = code_to_name_extra[keycode - 542];
        snprintf(keystr, sizeof(keystr), "%c-%d    ", name, keycode);
    } else if (keycode < 70) {
        snprintf(keystr, sizeof(keystr), "F%d-%d   ", keycode - 57, keycode);
    } else {
        snprintf(keystr, sizeof(keystr), "         ");
    }
    bool on_left = (record->event.key.row < 4);
    sprintf(keylog_str, "%c%dx%d %s", on_left ? 'L' : 'R', record->event.key.row % 4, record->event.key.col, keystr);
#endif
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPCSCRN:
            return 300;
        case SFTLFT:
            return 3000;
        case GUIRT:
            return 1000;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPCSCRN:
            return false;
        default:
            return true;
    }
}
