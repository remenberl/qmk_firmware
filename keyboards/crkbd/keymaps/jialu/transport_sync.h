#pragma once

#define OLED_KEYLOGGER_LENGTH 24

extern char keylog_str[OLED_KEYLOGGER_LENGTH];

void keyboard_post_init_transport_sync(void);