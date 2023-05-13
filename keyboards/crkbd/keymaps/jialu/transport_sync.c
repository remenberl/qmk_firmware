#include <string.h>

#include "jialu.h"
#include "quantum.h"
#include "transactions.h"

void keylogger_string_sync(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == OLED_KEYLOGGER_LENGTH) {
        memcpy(&keylog_str, initiator2target_buffer, initiator2target_buffer_size);
    }
}

void keyboard_post_init_transport_sync(void) {
    // Register keyboard state sync split transaction
    transaction_register_rpc(RPC_ID_USER_KEYLOG_STR, keylogger_string_sync);
}

void user_transport_sync(void) {
    if (is_keyboard_master()) {
        static uint32_t last_sync;
        bool            needs_sync = false;
        static char keylog_temp[OLED_KEYLOGGER_LENGTH] = {0};

        // Check if the state values are different
        if (memcmp(&keylog_str, &keylog_temp, OLED_KEYLOGGER_LENGTH) != 0) {
            needs_sync = true;
            memcpy(&keylog_temp, &keylog_str, OLED_KEYLOGGER_LENGTH);
        }
        if (timer_elapsed32(last_sync) > 250) {
            needs_sync = true;
        }

        // Perform the sync if requested
        if (needs_sync) {
            if (transaction_rpc_send(RPC_ID_USER_KEYLOG_STR, OLED_KEYLOGGER_LENGTH, &keylog_str)) {
                last_sync = timer_read32();
            } 
            needs_sync = false;
        }
    }
}

void housekeeping_task_user(void) {
    // Data sync from master to slave
    user_transport_sync();
}
