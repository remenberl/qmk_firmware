// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "jialu.h"
#include "rgb_matrix.h"
#include "lib/lib8tion/lib8tion.h"

extern led_config_t g_led_config;

void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    switch (mode) {
        case 1:  // breathing
        {
            uint16_t time = scale16by8(g_rgb_timer / 24, speed);
            hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
            // Mapped to [30, 200]
            hsv.v = hsv.v * 200 / 256 + 30;
            RGB rgb       = hsv_to_rgb(hsv);
            for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
            break;
        }
        default:  // Solid Color
        {
            RGB rgb = hsv_to_rgb(hsv);
            for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
            break;
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case 1:
            rgb_matrix_layer_helper(HSV_YELLOW, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            break;
        case 2:
            rgb_matrix_layer_helper(HSV_GREEN, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            break;
        case 3:
            rgb_matrix_layer_helper(HSV_RED, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            break;
        case 4:
            rgb_matrix_layer_helper(HSV_MAGENTA, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            break;
        default: {
            rgb_matrix_layer_helper(HSV_AZURE, 1, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            break;
        }
    }
    return true;
}

#if defined(RGB_MATRIX_REST_MODE)
static uint32_t hypno_timer;

__attribute__((weak)) void rgb_matrix_indicator_keymap(void) {}

void matrix_scan_rgb_matrix(void) {
    if (RGB_MATRIX_REST_MODE != RGB_MATRIX_TYPING_HEATMAP &&
            rgb_matrix_get_mode() == RGB_MATRIX_TYPING_HEATMAP && sync_timer_elapsed32(hypno_timer) > 10000) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE);
    }
    rgb_matrix_indicator_keymap();
}

void keyboard_post_init_rgb_matrix(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE);
}

bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
    if (RGB_MATRIX_REST_MODE == RGB_MATRIX_TYPING_HEATMAP) return true;
    hypno_timer = sync_timer_read32();
    if (rgb_matrix_get_mode() == RGB_MATRIX_REST_MODE) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
    }
    return true;
}
#endif
