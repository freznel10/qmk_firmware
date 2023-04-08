#include "pointing_device.h"
#include "ps2_trackpoint.h"
#include "ps2_mouse.h"
#include "wait.h"
#include "gpio.h"
#include "host.h"
#include "timer.h"
#include "print.h"
#include "report.h"
#include "debug.h"
#include "ps2.h"

static inline void ps2_mouse_print_report(report_mouse_t *mouse_report);
static inline void ps2_mouse_convert_report_to_hid(report_mouse_t *mouse_report);
static inline void ps2_mouse_enable_scrolling(void);
__attribute__((unused)) static inline void ps2_mouse_scroll_button_task(report_mouse_t *mouse_report);

const pointing_device_driver_t     ps2_trackpoint_driver_ps2_default = {.init = ps2_mouse_init, .get_report = ps2_trackpoint_get_report, .set_cpi = NULL, .get_cpi = NULL};
const pointing_device_ps2_config_t ps2_trackpoint_config_ps2_default = {.data_pin = PS2_DATA_PIN, .clock_pin = PS2_CLOCK_PIN};


#define X_IS_NEG (mouse_report->buttons & (1 << PS2_MOUSE_X_SIGN))
#define Y_IS_NEG (mouse_report->buttons & (1 << PS2_MOUSE_Y_SIGN))
#define X_IS_OVF (mouse_report->buttons & (1 << PS2_MOUSE_X_OVFLW))
#define Y_IS_OVF (mouse_report->buttons & (1 << PS2_MOUSE_Y_OVFLW))


void ps2_mouse_init(const void *config) {
   __attribute__((unused)) pointing_device_ps2_config_t *ps2_config = (pointing_device_ps2_config_t *)config;
    ps2_host_init();

    wait_ms(PS2_MOUSE_INIT_DELAY); // wait for powering up

    PS2_MOUSE_SEND(PS2_MOUSE_RESET, "ps2_mouse_init: sending reset");

    PS2_MOUSE_RECEIVE("ps2_mouse_init: read BAT");
    PS2_MOUSE_RECEIVE("ps2_mouse_init: read DevID");

#ifdef PS2_MOUSE_USE_REMOTE_MODE
    ps2_mouse_set_remote_mode();
#else
    ps2_mouse_enable_data_reporting();
    ps2_mouse_set_stream_mode();
#endif

#ifdef PS2_MOUSE_ENABLE_SCROLLING
    ps2_mouse_enable_scrolling();

#endif

#ifdef PS2_MOUSE_USE_2_1_SCALING
    ps2_mouse_set_scaling_2_1();
#endif

    ps2_mouse_init_user();
}

static inline void ps2_mouse_convert_report_to_hid(report_mouse_t *mouse_report) {
    // PS/2 mouse data is '9-bit integer'(-256 to 255) which is comprised of sign-bit and 8-bit value.
    // bit: 8    7 ... 0
    //      sign \8-bit/
    //
    // Meanwhile USB HID mouse indicates 8bit data(-127 to 127), note that -128 is not used.
    //
    // This converts PS/2 data into HID value. Use only -127-127 out of PS/2 9-bit.
    mouse_report->x = X_IS_NEG ? ((!X_IS_OVF && -127 <= mouse_report->x && mouse_report->x <= -1) ? mouse_report->x : -127) : ((!X_IS_OVF && 0 <= mouse_report->x && mouse_report->x <= 127) ? mouse_report->x : 127);
    mouse_report->y = Y_IS_NEG ? ((!Y_IS_OVF && -127 <= mouse_report->y && mouse_report->y <= -1) ? mouse_report->y : -127) : ((!Y_IS_OVF && 0 <= mouse_report->y && mouse_report->y <= 127) ? mouse_report->y : 127);

#ifdef PS2_MOUSE_INVERT_BUTTONS
    // swap left & right buttons
    uint8_t needs_left    = mouse_report->buttons & PS2_MOUSE_BTN_RIGHT;
    uint8_t needs_right   = mouse_report->buttons & PS2_MOUSE_BTN_LEFT;
    mouse_report->buttons = (mouse_report->buttons & ~(PS2_MOUSE_BTN_MASK)) | (needs_left ? PS2_MOUSE_BTN_LEFT : 0) | (needs_right ? PS2_MOUSE_BTN_RIGHT : 0);
#else
    // remove sign and overflow flags
    mouse_report->buttons &= PS2_MOUSE_BTN_MASK;
#endif

#ifdef PS2_MOUSE_INVERT_X
    mouse_report->x = -mouse_report->x;
#endif
#ifndef PS2_MOUSE_INVERT_Y // NOTE if not!
    // invert coordinate of y to conform to USB HID mouse
    mouse_report->y = -mouse_report->y;
#endif

#ifdef PS2_MOUSE_ROTATE
    int8_t x = mouse_report->x;
    int8_t y = mouse_report->y;
#    if PS2_MOUSE_ROTATE == 90
    mouse_report->x = y;
    mouse_report->y = -x;
#    elif PS2_MOUSE_ROTATE == 180
    mouse_report->x = -x;
    mouse_report->y = -y;
#    elif PS2_MOUSE_ROTATE == 270
    mouse_report->x = -y;
    mouse_report->y = x;
#    endif
#endif
}

static inline void ps2_mouse_print_report(report_mouse_t *mouse_report) {
    if (!debug_mouse) return;
    print("ps2_mouse: [");
    print_hex8(mouse_report->buttons);
    print("|");
    print_hex8((uint8_t)mouse_report->x);
    print(" ");
    print_hex8((uint8_t)mouse_report->y);
    print(" ");
    print_hex8((uint8_t)mouse_report->v);
    print(" ");
    print_hex8((uint8_t)mouse_report->h);
    print("]\n");
}

static inline void ps2_mouse_enable_scrolling(void) {
    PS2_MOUSE_SEND(PS2_MOUSE_SET_SAMPLE_RATE, "Initiaing scroll wheel enable: Set sample rate");
    PS2_MOUSE_SEND(200, "200");
    PS2_MOUSE_SEND(PS2_MOUSE_SET_SAMPLE_RATE, "Set sample rate");
    PS2_MOUSE_SEND(100, "100");
    PS2_MOUSE_SEND(PS2_MOUSE_SET_SAMPLE_RATE, "Set sample rate");
    PS2_MOUSE_SEND(80, "80");
    PS2_MOUSE_SEND(PS2_MOUSE_GET_DEVICE_ID, "Finished enabling scroll wheel");
    wait_ms(20);
}


#define PRESS_SCROLL_BUTTONS mouse_report->buttons |= (PS2_MOUSE_SCROLL_BTN_MASK)
#define RELEASE_SCROLL_BUTTONS mouse_report->buttons &= ~(PS2_MOUSE_SCROLL_BTN_MASK)
static inline void ps2_mouse_scroll_button_task(report_mouse_t *mouse_report) {
    static enum {
        SCROLL_NONE,
        SCROLL_BTN,
        SCROLL_SENT,
    } scroll_state                     = SCROLL_NONE;
    static uint16_t scroll_button_time = 0;

    if (PS2_MOUSE_SCROLL_BTN_MASK == (mouse_report->buttons & (PS2_MOUSE_SCROLL_BTN_MASK))) {
        // All scroll buttons are pressed

        if (scroll_state == SCROLL_NONE) {
            scroll_button_time = timer_read();
            scroll_state       = SCROLL_BTN;
        }

        // If the mouse has moved, update the report to scroll instead of move the mouse
        if (mouse_report->x || mouse_report->y) {
            scroll_state    = SCROLL_SENT;
            mouse_report->v = -mouse_report->y / (PS2_MOUSE_SCROLL_DIVISOR_V);
            mouse_report->h = mouse_report->x / (PS2_MOUSE_SCROLL_DIVISOR_H);
            mouse_report->x = 0;
            mouse_report->y = 0;
#ifdef PS2_MOUSE_INVERT_H
            mouse_report->h = -mouse_report->h;
#endif
#ifdef PS2_MOUSE_INVERT_V
            mouse_report->v = -mouse_report->v;
#endif
        }
    } else if (0 == (PS2_MOUSE_SCROLL_BTN_MASK & mouse_report->buttons)) {
        // None of the scroll buttons are pressed

#if PS2_MOUSE_SCROLL_BTN_SEND
        if (scroll_state == SCROLL_BTN && timer_elapsed(scroll_button_time) < PS2_MOUSE_SCROLL_BTN_SEND) {
            PRESS_SCROLL_BUTTONS;
            host_mouse_send(mouse_report);
            wait_ms(100);
            RELEASE_SCROLL_BUTTONS;
        }
#endif
        scroll_state = SCROLL_NONE;
    }

    RELEASE_SCROLL_BUTTONS;
}
static report_mouse_t mouse_report = {};

report_mouse_t ps2_trackpoint_get_report(const void *config)  {

    // static uint8_t buttons_prev = 0;
    // extern int     tp_buttons;

    /* receives packet from mouse */
#ifdef PS2_MOUSE_USE_REMOTE_MODE
    uint8_t rcv;
    rcv = ps2_host_send(PS2_MOUSE_READ_DATA);
    if (rcv == PS2_ACK) {
        mouse_report.buttons = ps2_host_recv_response();
        mouse_report.x       = ps2_host_recv_response() * PS2_MOUSE_X_MULTIPLIER;
        mouse_report.y       = ps2_host_recv_response() * PS2_MOUSE_Y_MULTIPLIER;
// #    ifdef PS2_MOUSE_ENABLE_SCROLLING
//         mouse_report.v = -(ps2_host_recv_response() & PS2_MOUSE_SCROLL_MASK) * PS2_MOUSE_V_MULTIPLIER;
// #    endif
    } else {
        if (debug_mouse) print("ps2_mouse: fail to get mouse packet\n");
    }
#else
    if (pbuf_has_data()) {
        mouse_report.buttons = ps2_host_recv_response();
        mouse_report.x       = ps2_host_recv_response() * PS2_MOUSE_X_MULTIPLIER;
        mouse_report.y       = ps2_host_recv_response() * PS2_MOUSE_Y_MULTIPLIER;
// #    ifdef PS2_MOUSE_ENABLE_SCROLLING
//         mouse_report.v       = -(ps2_host_recv_response() & PS2_MOUSE_SCROLL_MASK) * PS2_MOUSE_V_MULTIPLIER;
// #    endif
    } else {
        // if (debug_mouse) print("ps2_mouse: fail to get mouse packet\n");
    }
#endif

    // mouse_report.buttons |= tp_buttons;
    /* if mouse moves or buttons state changes */
    if (mouse_report.x || mouse_report.y) { // || mouse_report.v || ((mouse_report.buttons ^ buttons_prev) & PS2_MOUSE_BTN_MASK)) {
#ifdef PS2_MOUSE_DEBUG_RAW
        // Used to debug raw ps2 bytes from mouse
        ps2_mouse_print_report(&mouse_report);
#endif
        // buttons_prev = mouse_report.buttons;
        ps2_mouse_convert_report_to_hid(&mouse_report);
// #if PS2_MOUSE_SCROLL_BTN_MASK
//         ps2_mouse_scroll_button_task(&mouse_report);
// #endif
//         if (mouse_report.x || mouse_report.y || mouse_report.v) {
//             ps2_mouse_moved_user(&mouse_report);
//         }
// // #ifdef PS2_MOUSE_DEBUG_HID
//         // Used to debug the bytes sent to the host
//         ps2_mouse_print_report(&mouse_report);
// // #endif
    }

    return mouse_report;
}

