#include "jialu.h"
#include "quantum.h"

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void keyboard_post_init_user(void) {
#if defined(RGB_MATRIX_REST_MODE)
    keyboard_post_init_rgb_matrix();
#endif
#if defined(SPLIT_TRANSACTION_IDS_USER)
    keyboard_post_init_transport_sync();
#endif
    keyboard_post_init_keymap();
}

/* Activate mouse button layer with PS2 mouse - crkbd:manna-harbour */
#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE

static uint16_t mh_auto_buttons_timer;
extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
  if (mh_auto_buttons_timer) {
    mh_auto_buttons_timer = timer_read();
  } else {
    if (!tp_buttons) {
      layer_on(MH_AUTO_BUTTONS_LAYER);
      mh_auto_buttons_timer = timer_read();
  #if defined CONSOLE_ENABLE
      print("mh_auto_buttons: on\n");
  #endif
    }
  }
}

#endif // defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && #defined MOUSEKEY_ENABLE

// No global matrix scan code, so just run keymap's matrix
// scan function
__attribute__((weak)) void matrix_scan_keymap(void) {}
__attribute__((weak)) void matrix_scan_secret(void) {}
void matrix_scan_user(void) {
#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE
    if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > MH_AUTO_BUTTONS_TIMEOUT)) {
        if (!tp_buttons) {
            layer_off(MH_AUTO_BUTTONS_LAYER);
            mh_auto_buttons_timer = 0;
        #if defined CONSOLE_ENABLE
            print("mh_auto_buttons: off\n");
        #endif
        }
    }
#endif

    static bool has_ran_yet;
    if (!has_ran_yet) {
        has_ran_yet = true;
        // startup_user();
    }

#if defined(RGB_MATRIX_REST_MODE)
    matrix_scan_rgb_matrix();
#endif
    matrix_scan_secret();

    matrix_scan_keymap();
}
