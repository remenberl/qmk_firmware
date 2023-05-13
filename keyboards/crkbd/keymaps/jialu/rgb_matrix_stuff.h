// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "quantum.h"

bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record);

void keyboard_post_init_rgb_matrix(void);
void matrix_scan_rgb_matrix(void);
bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
bool rgb_matrix_indicators_keymap(void);
