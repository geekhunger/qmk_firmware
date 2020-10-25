#ifndef KINT36_CONFIG_H
#define KINT36_CONFIG_H

#include "../config.h"

/* USB Device descriptor parameter */
#undef VENDOR_ID
#define VENDOR_ID 0x1209
#undef PRODUCT_ID
#define PRODUCT_ID 0x345C
#undef DEVICE_VER
#define DEVICE_VER 0x0001  // 0 or 1?
#undef MANUFACTURER
#define MANUFACTURER "https://github.com/stapelberg"
#undef PRODUCT
#define PRODUCT "https://github.com/kinx-project/kint"

/* key matrix size */
#define MATRIX_ROWS 15
#define MATRIX_COLS 7

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS           \
{                                 \
        LINE_PIN8,  /* ROW_EQL */ \
        LINE_PIN9,  /* ROW_1 */   \
        LINE_PIN10, /* ROW_2 */   \
        LINE_PIN11, /* ROW_3 */   \
        LINE_PIN7,  /* ROW_4 */   \
        LINE_PIN16, /* ROW_5 */   \
        LINE_PIN5,  /* ROW_6 */   \
        LINE_PIN3,  /* ROW_7 */   \
        LINE_PIN4,  /* ROW_8 */   \
        LINE_PIN1,  /* ROW_9 */   \
        LINE_PIN0,  /* ROW_0 */   \
        LINE_PIN2,  /* ROW_MIN */ \
        LINE_PIN17, /* ROW_ESC */ \
        LINE_PIN23, /* ROW_F1 */  \
        LINE_PIN21, /* ROW_F2 */  \
    }

#define MATRIX_COL_PINS         \
    {                           \
        LINE_PIN18, /* COL_0 */ \
        LINE_PIN14, /* COL_1 */ \
        LINE_PIN15, /* COL_2 */ \
        LINE_PIN20, /* COL_3 */ \
        LINE_PIN22, /* COL_4 */ \
        LINE_PIN19, /* COL_5 */ \
        LINE_PIN6   /* COL_6 */ \
    }
//#define MATRIX_ROW_PINS { D0, D1, D2, D3, D4, D5, D6, D7, C0, C1, C2, C3, C4, C5, C6 }
//#define MATRIX_COL_PINS { B0, B1, B2, B3, B4, B5, B6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
//#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* don't know if this should be defined at the board or top level. Assuming board
#define MOUSEKEY_DELAY          100
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_MAX_SPEED      3
#define MOUSEKEY_TIME_TO_MAX    10
*/

#define IGNORE_MOD_TAP_INTERRUPT

// Reduce input latency by lowering the USB polling interval
// from its 10ms default to the 1ms minimum that USB 1.x (Full Speed) allows:
#define USB_POLLING_INTERVAL_MS 1

#endif
