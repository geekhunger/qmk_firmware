#pragma once

// TODO kint36 seems to force-override my settings...
//#define MANUFACTURER "herrsch"
//#define PRODUCT "Kinesis Advantage2 KB600 QWERTZ"

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define ONESHOT_TIMEOUT 300
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

#define STM32_SYSCLK KINETIS_SYSCLK_FREQUENCY
#define NOP_FUDGE 0.4
#define RGB_DI_PIN LINE_PIN28
#define RGBLED_NUM 4
#define RGBLIGHT_ANIMATIONS