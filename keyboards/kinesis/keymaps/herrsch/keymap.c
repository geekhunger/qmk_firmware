#include QMK_KEYBOARD_H
#include <string.h>



// keymap for Kinesis Advantage2 (KB600) QWERTZ layout
// designed to run on MacOS/iPadOS/iOS and Windows
// please set system keyboard language to german!



enum keyboard_layer {
  QWERTZ_MACOS,   // default mac layer
  QWERTZ_WINDOWS, // default windows layer
  QWERTZ_KEYPAD,  // keypad layer
  QWERTZ_SYMBOLS  // symbols layer
};



enum custom_key {
  KCC_SUPER,  // chain keys to trigger macro (custom implementation analog to leader key concept)
  KCC_KEYPAD, // tap for shift and double-tap for keypad layer
  KCC_SYMBOLS // activate symbols layer
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /******************************************************/
  /******************* base layer mac *******************/
  /******************************************************/

  [QWERTZ_MACOS] = LAYOUT(
    // left keywell
    XXXXXXX,      KC_F1,    KC_F2,      KC_F3,    KC_F4,      KC_F5,  KC_F6,  KC_F7,  KC_F8,
    XXXXXXX,      KC_1,     KC_2,       KC_3,     KC_4,       KC_5,
    XXXXXXX,      KC_Q,     KC_W,       KC_E,     KC_R,       KC_F,
    XXXXXXX,      KC_A,     KC_S,       KC_D,     KC_T,       KC_G,
    KC_EXCLAIM,   KC_Z,     KC_X,       KC_C,     KC_V,       KC_B,
                  XXXXXXX,  XXXXXXX,    XXXXXXX,  KC_LGUI,
    // left thumb
                  LALT_T(KC_DELETE),    XXXXXXX,
                                        KC_LCTRL,
    KC_SPACE,     KC_LSHIFT,            KC_LGUI,
    // right keywell
    KC_F9,    KC_F10,   KC_F11,     KC_F12,     KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  XXXXXXX,  RESET,
    KC_6,     KC_7,     KC_8,       KC_9,       KC_0,           XXXXXXX,
    KC_Y,     KC_U,     KC_I,       KC_O,       XXXXXXX,        XXXXXXX,
    KC_H,     KC_N,     KC_K,       KC_L,       KC_P,           XXXXXXX,
    KC_J,     KC_M,     KC_COMMA,   KC_DOT,     KC_SLASH,       LSFT(KC_MINUS),
              KC_LEFT,  KC_DOWN,    KC_UP,      KC_RGHT,
    // right thumb
    XXXXXXX,            LALT_T(KC_BSPACE),
    XXXXXXX,
    LGUI_T(KC_ESCAPE),  RSFT_T(KC_ENTER),       KCC_SUPER
  ),

  /******************************************************/
  /***************** base layer windows *****************/
  /******************************************************/
  
  [QWERTZ_WINDOWS] = LAYOUT(
    // left keywell
    XXXXXXX,      KC_F1,    KC_F2,    KC_F3,    KC_F4,      KC_F5,  KC_F6,  KC_F7,  KC_F8,
    XXXXXXX,      KC_1,     KC_2,     KC_3,     KC_4,       KC_5,
    XXXXXXX,      KC_Q,     KC_W,     KC_E,     KC_R,       KC_F,
    XXXXXXX,      KC_A,     KC_S,     KC_D,     KC_T,       KC_G,
    KC_EXCLAIM,   KC_Z,     KC_X,     KC_C,     KC_V,       KC_B,
                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // left thumb
                  RALT_T(KC_DELETE),  XXXXXXX,
                                      KC_LGUI,
    KC_SPACE,     KC_LSHIFT,          KC_LCTRL,
    // right keywell
    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  XXXXXXX,  RESET,
    KC_6,     KC_7,     KC_8,       KC_9,     KC_0,           XXXXXXX,
    KC_Y,     KC_U,     KC_I,       KC_O,     XXXXXXX,        XXXXXXX,
    KC_H,     KC_N,     KC_K,       KC_L,     KC_P,           XXXXXXX,
    KC_J,     KC_M,     KC_COMMA,   KC_DOT,   KC_SLASH,       LSFT(KC_MINUS),
              KC_LEFT,  KC_DOWN,    KC_UP,    KC_RGHT,
    // right thumb
    XXXXXXX,            RALT_T(KC_BSPACE),
    XXXXXXX,
    LCTL_T(KC_ESCAPE),  RSFT_T(KC_ENTER),     XXXXXXX
  ),

  /******************************************************/
  /******************* keypad layer *********************/
  /******************************************************/

  [QWERTZ_KEYPAD] = LAYOUT(
    // left keywell
    XXXXXXX,      KC_BRIGHTNESS_DOWN,       KC_BRIGHTNESS_UP,     XXXXXXX,    XXXXXXX,  DF(QWERTZ_MACOS),  XXXXXXX,  DF(QWERTZ_WINDOWS),  XXXXXXX,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,              XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,              XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,              XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,              XXXXXXX,    XXXXXXX,
                  XXXXXXX,     XXXXXXX,     XXXXXXX,              _______,
    // left thumb
                  _______,  _______,
                            _______,
    KC_TAB,       _______,  _______,
    // right keywell
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  XXXXXXX,  _______,
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,
    XXXXXXX,      KC_KP_7,      KC_KP_8,    KC_KP_9,    XXXXXXX,              XXXXXXX,
    XXXXXXX,      KC_KP_4,      KC_KP_5,    KC_KP_6,    XXXXXXX,              XXXXXXX,
    KC_KP_EQUAL,  KC_KP_1,      KC_KP_2,    KC_KP_3,    XXXXXXX,              XXXXXXX,
                  _______,      _______,    _______,    _______,
    // right thumb
    _______,  _______,
    _______,
    _______,  KC_KP_ENTER,  KC_KP_0
  ),

  /******************************************************/
  /****************** symbols layer *********************/
  /******************************************************/

  [QWERTZ_SYMBOLS] = LAYOUT(
    // left keywell
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    DF(QWERTZ_MACOS),  XXXXXXX,  DF(QWERTZ_WINDOWS),  XXXXXXX,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,
    XXXXXXX,      KC_KP_1,     KC_KP_2,     KC_KP_3,     KC_KP_4,    KC_KP_5,
    XXXXXXX,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,
                  XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,
    // left thumb
                  _______,  _______,
                            _______,
    KC_TAB,       _______,  _______,
    // right keywell
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  XXXXXXX,  _______,
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,
    KC_KP_6,      KC_KP_7,      KC_KP_8,    KC_KP_9,    KC_KP_0,              XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,
                  _______,      _______,    _______,    _______,
    // right thumb
    XXXXXXX,  XXXXXXX,
    XXXXXXX,
    XXXXXXX,  XXXXXXX,  _______
  )
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LALT_T(KC_DELETE):
    case LALT_T(KC_BSPACE):
    case LGUI_T(KC_ESCAPE):
    case RSFT_T(KC_ENTER):
        return 100;
    default:
        return TAPPING_TERM;
  }
};



uint16_t a_umlaut[2]       = {KC_A, KC_E};
uint16_t u_umlaut[2]       = {KC_U, KC_E};
uint16_t o_umlaut[2]       = {KC_O, KC_E};
uint16_t s_umlaut[2]       = {KC_S, KC_S};
uint16_t and_symbol[1]     = {KC_U};
uint16_t usd_symbol[1]     = {KC_S};
uint16_t eur_symbol[1]     = {KC_E};
uint16_t tilde_symbol[1]   = {KC_N};
uint16_t hash_symbol[2]    = {KC_H, KC_H};
uint16_t at_symbol[1]      = {KC_L};
uint16_t celcius_symbol[1] = {KC_C};
uint16_t percent_symbol[1] = {KC_P};

void a_umlaut_macro(void) {tap_code(KC_QUOTE);};
void u_umlaut_macro(void) {tap_code(KC_LBRACKET);};
void o_umlaut_macro(void) {tap_code(KC_SCOLON);};
void s_umlaut_macro(void) {tap_code(KC_MINUS);};
void and_symbol_macro(void) {SEND_STRING("&");};
void usd_symbol_macro(void) {SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_4) SS_UP(X_LSFT));};
void eur_symbol_macro(void) {SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_E) SS_UP(X_LALT));};
void tilde_symbol_macro(void) {SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_N) SS_UP(X_LALT) SS_TAP(X_SPACE));};
void hash_symbol_macro(void) {tap_code(KC_NONUS_HASH);};
void at_symbol_macro(void) {SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_L) SS_UP(X_LALT));};
void celcius_symbol_macro(void) {};
void percent_symbol_macro(void) {};



uint16_t super_queue[4]; // of finite length
uint16_t super_queue_index;
uint16_t super_find;
uint16_t super_timestamp;
uint16_t super_timeout = 400; // adjust to your liking!
bool super_update_timeout = true; // restart timer for every new sequence segment while listening
bool super_running = false;

void super_reset(void) {
  // TODO flush evenrything from buffer to the screen
  memset(super_queue, 0, sizeof(super_queue));
  super_queue_index = 0;
  super_find = 0;
  super_timestamp = super_timeout + timer_read();
  super_running = false;
};

bool super_overdue(void) {
  return timer_read() >= super_timestamp || super_queue_index >= sizeof(super_queue) / sizeof(super_queue[0]);
};

bool super_record(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed) { // on keydown
    if(keycode == KCC_SUPER) {
      super_reset();
      super_running = true;
      return true;
    } else if(super_running && !super_overdue()) {
      if(super_update_timeout) super_timestamp = super_timeout + timer_read();
      super_queue[super_queue_index] = keycode;
      super_queue_index++;
      return true;
    }
  }
  return false;
};

void super_macro(uint16_t *match_arr, void (*replace_fn)(void)) {
  if(super_running && super_queue_index == sizeof(&match_arr) / sizeof(match_arr[0])) {
    bool resolve = true;
    for(uint16_t kc = 0; kc < sizeof(super_queue) / sizeof(super_queue[0]); kc++) {
      if((kc < super_queue_index && super_queue[kc] != match_arr[kc]) || (kc >= super_queue_index && super_queue[kc] != 0)) {
        resolve = false;
        break;
      }
    }
    if(resolve) {
      replace_fn();
      super_reset();
    }
  }
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(super_record(keycode, record)) return false; // swallow keystroke
  switch(keycode) {
    default: return true;
  }
};



void matrix_scan_user(void) {
  super_macro(a_umlaut,       a_umlaut_macro);
  super_macro(u_umlaut,       u_umlaut_macro);
  super_macro(o_umlaut,       o_umlaut_macro);
  super_macro(s_umlaut,       s_umlaut_macro);
  super_macro(and_symbol,     and_symbol_macro);
  super_macro(usd_symbol,     usd_symbol_macro);
  super_macro(eur_symbol,     eur_symbol_macro);
  super_macro(tilde_symbol,   tilde_symbol_macro);
  super_macro(hash_symbol,    hash_symbol_macro);
  super_macro(at_symbol,      at_symbol_macro);
  super_macro(celcius_symbol, celcius_symbol_macro);
  super_macro(percent_symbol, percent_symbol_macro);
  if(super_overdue()) super_reset();
};
