// keymap for Kinesis Advantage2 (KB600) QWERTZ layout
// designed to run on MacOS/iPadOS/iOS and Windows
// please set system keyboard language to german!

#include QMK_KEYBOARD_H

enum keyboard_layer {
  MACOS,
  WINDOWS,
  NUMBER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /******************************************************/
  /******************* base layer mac *******************/
  /******************************************************/

  [MACOS] = LAYOUT(
    // left keywell
    XXXXXXX,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,  KC_F6,  KC_F7,  KC_F8,
    XXXXXXX,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,
    XXXXXXX,      KC_Q,       KC_W,       KC_E,       KC_R,       KC_F,
    XXXXXXX,      KC_A,       KC_S,       KC_D,       KC_T,       KC_G,
    XXXXXXX,      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,
                  XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LGUI,
    // left thumb
                  LALT_T(KC_DELETE),   XXXXXXX,
                                       KC_LCTRL,
    KC_SPACE,     LSFT_T(KC_TAB),      KC_LGUI,
    // right keywell
    KC_F9,      KC_F10,    KC_F11,     KC_F12,    KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  XXXXXXX,  RESET,
    KC_6,       KC_7,      KC_8,       KC_9,      KC_0,           KC_MINUS,
    KC_Y,       KC_U,      KC_I,       KC_O,      XXXXXXX,        XXXXXXX,
    KC_H,       KC_N,      KC_K,       KC_L,      KC_P,           XXXXXXX,
    KC_J,       KC_M,      KC_COMMA,   KC_DOT,    KC_SLASH,       XXXXXXX,
                KC_LEFT,   KC_DOWN,    KC_UP,     KC_RIGHT,
    // right thumb
    XXXXXXX,            LALT_T(KC_BSPACE),
    XXXXXXX,
    LGUI_T(KC_ESCAPE),  KC_RSHIFT,     KC_ENTER
  ),

  /******************************************************/
  /**************** base windows layer ******************/
  /******************************************************/

  [WINDOWS] = LAYOUT(
    // left keywell
    _______,      _______,     _______,     _______,     _______,    _______,  _______,  _______,  _______,
    _______,      _______,     _______,     _______,     _______,    _______,
    _______,      _______,     _______,     _______,     _______,    _______,
    _______,      _______,     _______,     _______,     _______,    _______,
    _______,      _______,     _______,     _______,     _______,    _______,
                  _______,     _______,     _______,     KC_LALT,
    // left thumb
                  RALT_T(KC_DELETE),  KC_LALT,
                                      KC_LGUI,
    _______,      _______,            KC_LCTRL,
    // right keywell
    _______,      _______,      _______,    _______,    _______,  _______,  _______,  _______,  _______,
    _______,      _______,      _______,    _______,    _______,  _______,
    _______,      _______,      _______,    _______,    _______,  _______,
    _______,      _______,      _______,    _______,    _______,  _______,
    _______,      _______,      _______,    _______,    _______,  _______,
                  _______,      _______,    _______,    _______,
    // right thumb
    _______,            RALT_T(KC_BSPACE),
    _______,
    LCTL_T(KC_ESCAPE),  _______,    _______
  ),

  /******************************************************/
  /******************* numpad layer *********************/
  /******************************************************/

  [NUMBER] = LAYOUT(
    // left keywell
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    DF(MACOS),  DF(WINDOWS),  DF(WINDOWS),  XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    _______,    XXXXXXX,
                  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,
    // left thumb
                  XXXXXXX,   XXXXXXX,
                             XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,
    // right keywell
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  XXXXXXX,  XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,              XXXXXXX,
    XXXXXXX,      KC_7,      KC_8,      KC_9,       XXXXXXX,              XXXXXXX,
    XXXXXXX,      KC_4,      KC_5,      KC_6,       XXXXXXX,              XXXXXXX,
    XXXXXXX,      KC_1,      KC_2,      KC_3,       XXXXXXX,              XXXXXXX,
                  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,
    // right thumb
    XXXXXXX,  XXXXXXX,
    XXXXXXX,
    XXXXXXX,  XXXXXXX,  KC_0
  ),
};



uint8_t HOLD_TIMEOUT;
#define HOLD_TIMER 200

#define is_mac (default_layer_state & (1UL << MACOS)) // 1UL is 32bit unsigned long of type uint32_t
#define is_win (default_layer_state & (1UL << WINDOWS))

#define has_mods(mask) ((get_mods() & (mask)) != 0)
#define rm_mods(mask) (get_mods() & ~(mask))

// for modifier masks see https://github.com/vomindoraan/qmk_firmware/blob/master/tmk_core/common/keycode.h
#define without_mods(mask, ...) { \
  const uint16_t tmp = get_mods(); \
  set_mods(rm_mods((mask))); \
  {__VA_ARGS__} \
  set_mods(tmp); \
}

#define report(loops, ...) { \
  for(uint8_t n = 1; n <= (loops); n++) { \
    {__VA_ARGS__} \
  } \
}

#define key_down(record) (record->event.pressed && !record->event.interrupted)
#define key_up(record)   (record->event.interrupted || !record->event.pressed)
#define key_hold(record) (timer_elapsed(HOLD_TIMEOUT) >= 0)



void hold_reset(void) {

};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(keycode == KC_D) {
    if(key_up(record) && key_hold(record)) {
      report(record->tap.count, {

      });
    }
    return false;
  }

  return true;
};
