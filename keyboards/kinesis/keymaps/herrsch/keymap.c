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
  [MACOS] = LAYOUT(
    // left keywell
    XXXXXXX,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,  KC_F6,  KC_F7,  KC_F8,
    XXXXXXX,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,
    XXXXXXX,      TD(KC_Q),   TD(KC_W),   TD(KC_E),   TD(KC_R),   TD(KC_F),
    XXXXXXX,      TD(KC_A),   TD(KC_S),   TD(KC_D),   TD(KC_T),   TD(KC_G),
    XXXXXXX,      TD(KC_Z),   TD(KC_X),   TD(KC_C),   TD(KC_V),   TD(KC_B),
                  XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LGUI,
    // left thumb
                  LALT_T(KC_DELETE),      XXXXXXX,
                                          KC_LCTRL,
    KC_SPACE,     LSFT_T(KC_TAB),         KC_LGUI,
    // right keywell
    KC_F9,      KC_F10,    KC_F11,        KC_F12,      KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  XXXXXXX,  RESET,
    KC_6,       KC_7,      KC_8,          KC_9,        KC_0,           KC_MINUS,
    TD(KC_Y),   TD(KC_U),  TD(KC_I),      TD(KC_O),    XXXXXXX,        XXXXXXX,
    TD(KC_H),   TD(KC_N),  TD(KC_K),      TD(KC_L),    TD(KC_P),       XXXXXXX,
    TD(KC_J),   TD(KC_M),  TD(KC_COMMA),  TD(KC_DOT),  TD(KC_SLASH),   XXXXXXX,
                KC_LEFT,   KC_DOWN,       KC_UP,       KC_RIGHT,
    // right thumb
    XXXXXXX,            LALT_T(KC_BSPACE),
    XXXXXXX,
    LGUI_T(KC_ESCAPE),  KC_RSHIFT,        KC_ENTER
  ),


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



#define HOLD_TIMER 200 // this timeout has same meaning as TAPPING_TERM but with different value

bool is_mac(void) {return (default_layer_state & (1UL << MACOS)) != 0;}; // 1UL is 32bit unsigned long of type uint32_t
bool is_win(void) {return (default_layer_state & (1UL << WINDOWS)) != 0;};

bool real_mods_have(uint8_t mask) {return (get_mods() & mask) != 0;};
bool weak_mods_have(uint8_t mask) {return (get_weak_mods() & mask) != 0;};
bool has_mods(uint8_t mask) {return (weak_mods_have(mask) || real_mods_have(mask));};

// for modifier masks see https://github.com/vomindoraan/qmk_firmware/blob/master/tmk_core/common/keycode.h
#define without_mods(mask, ...) { \
  const bool is_real = real_mods_have(mask); \
  const bool is_weak = weak_mods_have(mask); \
  if(is_real) del_mods(mask); \
  else if(is_weak) del_weak_mods(mask); \
  {__VA_ARGS__} \
  if(is_real) add_mods(mask); \
  else if(is_weak) add_weak_mods(mask); \
}

#define report(loops, ...) { \
  for(uint8_t n = 1; n <= (loops); n++) { \
    {__VA_ARGS__} \
  } \
}

bool key_up(qk_tap_dance_state_t *state) {return state->interrupted || !state->pressed;};
bool key_down(qk_tap_dance_state_t *state) {return state->pressed;};
bool key_hold(qk_tap_dance_state_t *state) {return state->count && timer_elapsed(state->timer) >= HOLD_TIMER;};

void pass(qk_tap_dance_state_t *state) {
  if(has_mods(MOD_MASK_GUI | MOD_MASK_CTRL)) {
    tap_code(state->keycode);
    return;
  }
  report(state->count, {
    tap_code(state->keycode);
  });
};



void _(qk_tap_dance_state_t *state, void *user_data) {
  pass(state); // do not modify anything, just pass the keycode straight out again
};



void q(qk_tap_dance_state_t *state, void *user_data) {
  if(is_win() && has_mods(MOD_MASK_GUI | MOD_MASK_CTRL)) {
    without_mods(MOD_MASK_CSAG, {
      tap_code16(LALT(KC_F4)); // send Alt+F4 to emulate Cmd + Q on MacOS
    });
    return;
  }
  without_mods(MOD_MASK_ALT, {
    pass(state);
  });
}


void e(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) { // still holding
    without_mods((MOD_MASK_SHIFT | MOD_MASK_ALT), {
      if(is_mac()) {
        tap_code16(LCTL(LALT(KC_E))); // »
      } else if(is_win()) {
        // for available codes see https://wintipps.com/tastenkombination-sonderzeichen/
        register_code(KC_LALT);
        tap_code(KC_KP_0);
        tap_code(KC_KP_1);
        tap_code(KC_KP_7);
        tap_code(KC_KP_5);
        unregister_code(KC_LALT);
      }
    });
    state->pressed = true;
    return;
  }
  if(has_mods(MOD_MASK_ALT)) {
    without_mods((MOD_MASK_SHIFT | MOD_MASK_ALT), {
      tap_code16(LCA(KC_E)); // €
    });
    state->pressed = true;
    return;
  }
  pass(state);
};



qk_tap_dance_action_t tap_dance_actions[] = {
  [KC_Q] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, q, NULL, HOLD_TIMER),
  [KC_W] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_E] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, e, NULL, HOLD_TIMER),
  [KC_R] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_F] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_A] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_S] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_D] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_T] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_G] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_Z] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_X] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_C] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_V] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_B] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_Y] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_U] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_I] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_O] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_H] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_N] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_K] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_L] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_P] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_J] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_M] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_DOT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
  [KC_SLASH] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, _, NULL, HOLD_TIMER),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
};
