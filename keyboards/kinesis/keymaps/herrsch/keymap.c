// keymap for Kinesis Advantage2 (KB600) QWERTZ layout
// designed to run on MacOS/iPadOS/iOS and Windows
// please set system keyboard language to german!

#include QMK_KEYBOARD_H

enum keyboard_layer {
  MACOS,
  WINDOWS,
  NUMPAD,
};

enum os_layout_key {
  MAC = SAFE_RANGE,
  WIN
};

// IMPORTANT NOTE!!!
// I messed up my wiring because I suck at electronics and now my fn keys are swapped^^
// I swap them to right positions in software, see down below...
// ESC   F1   F2   F3   F4   F5   F6    F7   F8
//  |       X      |       X      |        X
// ESC   F2   F1   F3   F5   F4   F6    F8   F7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MACOS] = LAYOUT(
    // left keywell
    XXXXXXX,      KC_F2,      KC_F1,      KC_F3,      KC_F5,           KC_F4,       KC_F6,  KC_F8,  KC_F7,
    XXXXXXX,      KC_1,       KC_2,       KC_3,       KC_4,            KC_5,
    XXXXXXX,      TD(KC_Q),   TD(KC_W),   TD(KC_E),   TD(KC_R),        TD(KC_F),
    XXXXXXX,      TD(KC_A),   TD(KC_S),   TD(KC_D),   TD(KC_T),        TD(KC_G),
    XXXXXXX,      TD(KC_Z),   TD(KC_X),   TD(KC_C),   TD(KC_V),        TD(KC_B),
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
    LGUI_T(KC_ESCAPE),  RSFT_T(KC_ENTER),   MO(NUMPAD)
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


  [NUMPAD] = LAYOUT(
    // left keywell
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    MAC,      WIN,  XXXXXXX,  XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,      KC_1,      KC_2,      KC_3,       KC_4,       KC_5,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,
                  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,
    // left thumb
                  XXXXXXX,   XXXXXXX,
                             _______,
    _______,      XXXXXXX,   _______,
    // right keywell
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  XXXXXXX,  XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,     XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,     XXXXXXX,
    KC_6,         KC_7,      KC_8,      KC_9,       KC_0,        XXXXXXX,
    XXXXXXX,      XXXXXXX,   KC_COMMA,  KC_DOT,     XXXXXXX,     XXXXXXX,
                  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,
    // right thumb
    XXXXXXX,  KC_BSPACE,
    XXXXXXX,
    XXXXXXX,  KC_RSHIFT,  _______
  ),
};



#define HOLD_TIMER 200 // this timeout has same meaning as TAPPING_TERM but with different value

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

bool is_mac(void) {return default_layer_state == (1UL << MACOS);};
bool is_win(void) {return default_layer_state == (1UL << WINDOWS);};

bool real_mods_have(uint8_t mask) {return (get_mods() & mask) != 0;};
bool weak_mods_have(uint8_t mask) {return (get_weak_mods() & mask) != 0;};
bool has_mods(uint8_t mask) {return (weak_mods_have(mask) || real_mods_have(mask));};

// for modifier masks see https://github.com/vomindoraan/qmk_firmware/blob/master/tmk_core/common/keycode.h
#define without_mods(mask, ...) { \
  const uint8_t _real = get_mods(); \
  const uint8_t _weak = get_weak_mods(); \
  if(_real & mask) unregister_mods(mask); \
  if(_weak & mask) unregister_weak_mods(mask); \
  {__VA_ARGS__} \
  set_mods(_real); \
  set_weak_mods(_weak); \
}

#define with_numlock(...) { \
  tap_code16(KC_NUMLOCK); \
  {__VA_ARGS__} \
  tap_code16(KC_NUMLOCK); \
}

#define key_report(loops, ...) { \
  for(uint8_t n = 1; n <= loops; n++) { \
    {__VA_ARGS__} \
  } \
}

void key_pass(qk_tap_dance_state_t *state) {
  if((is_mac() && has_mods(MOD_MASK_GUI)) || (is_win() && has_mods(MOD_MASK_CTRL))) {
    tap_code(state->keycode); // tap key only once for OS commands
    return;
  }
  key_report(state->count, {
    tap_code(state->keycode);
  });
};

bool key_up(qk_tap_dance_state_t *state) {return state->interrupted || !state->pressed;};
bool key_down(qk_tap_dance_state_t *state) {return state->pressed && !state->interrupted;};



void q(qk_tap_dance_state_t *state, void *user_data) {
  if(is_win() && has_mods(MOD_MASK_CTRL)) {
    without_mods(MOD_MASK_CSAG, {
      tap_code16(LALT(KC_F4)); // send Alt+F4 to emulate Cmd + Q on MacOS
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) { // alt pressed (additionally shift might be present)
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void w(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void e(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) { // action resolved but key still being held
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_SA, {
        if(is_mac()) {
          tap_code16(LSFT(LALT(KC_Q))); // »
        } else if(is_win()) {
          // for available codes see https://wintipps.com/tastenkombination-sonderzeichen/
          register_code(KC_LALT);
          tap_code(KC_KP_1);
          tap_code(KC_KP_7);
          tap_code(KC_KP_5);
          unregister_code(KC_LALT);
        }
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG)) { // shift or alt pressed (but gui or ctrl are NOT present)
    if(has_mods(MOD_MASK_SHIFT)) { // shift is present
      without_mods(MOD_MASK_ALT, {
        key_pass(state);
      });
    } else { // alt is present
      without_mods(MOD_MASK_ALT, {
        tap_code16(LCA(KC_E)); // €
      });
    }
    return;
  }
  key_pass(state);
};



void r(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG)) { // shift or alt pressed
    if(has_mods(MOD_MASK_SHIFT)) { // shift is present
      without_mods(MOD_MASK_ALT, {
        key_pass(state);
      });
    } else { // alt is present
      without_mods(MOD_MASK_SA, {
        if(is_mac()) {
          tap_code16(LALT(KC_R)); // ®
        } else if(is_win()) {
          register_code(KC_LALT);
          tap_code(KC_KP_1);
          tap_code(KC_KP_6);
          tap_code(KC_KP_9);
          unregister_code(KC_LALT);
        }
      });
    }
    return;
  }
  key_pass(state);
};



void f(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_SA, {
        if(is_mac()) tap_code16(LALT(KC_8)); // {
        else if(is_win()) tap_code16(ALGR(KC_7));
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void a(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_ALT, {
        tap_code(KC_QUOTE); // ä
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) { // alt but no shift pressed (ctrl or gui may be present)
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code(KC_KP_PLUS); // numpad plus (+)
      });
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) { // alt+shift but no ctrl or gui
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void s(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || !has_mods(MOD_MASK_CG)) { // no mods or combination of alt and shift
      if(has_mods(MOD_MASK_SHIFT)) {
        without_mods(MOD_MASK_ALT, {
          tap_code16(LSFT(KC_4)); // $
        });
      } else if(has_mods(MOD_MASK_ALT)) {
        without_mods(MOD_MASK_ALT, {
          tap_code16(LSFT(KC_3)); // §
        });
      } else {
        tap_code(KC_MINUS); // ß
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code(KC_KP_MINUS); // numpad minus (-)
      });
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void d(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || !has_mods(MOD_MASK_CG)) { // no mods or combination of alt and shift
      if(has_mods(MOD_MASK_SHIFT)) {
        without_mods(MOD_MASK_ALT, {
          if(is_mac()) {
            tap_code16(LALT(KC_7)); // back slash
          } else if(is_win()) {
            register_code(KC_LALT);
            tap_code(KC_KP_9);
            tap_code(KC_KP_2);
            unregister_code(KC_LALT);
          }
        });
      } else if(has_mods(MOD_MASK_ALT)) {
        without_mods(MOD_MASK_SA, {
          key_report(state->count, {
            if(is_mac()) {
              tap_code16(LALT(KC_7)); // pipe
            } else if(is_win()) {
              register_code(KC_LALT);
              tap_code(KC_KP_1);
              tap_code(KC_KP_2);
              tap_code(KC_KP_4);
              unregister_code(KC_LALT);
            }
          });
        });
      } else {
        key_report(state->count, {
          tap_code16(LSFT(KC_7)); // forward slash
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code(KC_KP_SLASH); // numpad devide (/)
      });
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void t(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || !has_mods(MOD_MASK_CG)) { // no mods or combination of alt and shift
      if(has_mods(MOD_MASK_SHIFT)) {
        without_mods(MOD_MASK_SA, {
          tap_code16(LSFT(KC_BSLASH)); // '
        });
      } else {
        without_mods(MOD_MASK_ALT, {
          tap_code16(LSFT(KC_2)); // "
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LSFT(LALT(KC_D))); // ™
      } else if(is_win()) {
        register_code(KC_LALT);
        tap_code(KC_KP_0);
        tap_code(KC_KP_1);
        tap_code(KC_KP_5);
        tap_code(KC_KP_3);
        unregister_code(KC_LALT);
      }
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void g(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || !has_mods(MOD_MASK_CG)) { // no mods or combination of alt and shift
      if(has_mods(MOD_MASK_SHIFT)) {
        without_mods(MOD_MASK_SA, {
          if(is_mac()) tap_code16(LALT(KC_5)); // [
          else if(is_win()) tap_code16(ALGR(KC_8));
        });
      } else {
        without_mods(MOD_MASK_ALT, {
          tap_code16(LSFT(KC_8)); // (
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LSFT(KC_NONUS_BSLASH)); // °
      } else if(is_win()) {
        register_code(KC_LALT);
        tap_code(KC_KP_2);
        tap_code(KC_KP_4);
        tap_code(KC_KP_8);
        unregister_code(KC_LALT);
      }
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void z(qk_tap_dance_state_t *state, void *user_data) { // german y
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void x(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void c(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || !has_mods(MOD_MASK_CG)) { // no mods or combination of alt and shift
      if(has_mods(MOD_MASK_SHIFT)) {
        without_mods(MOD_MASK_SA, {
          tap_code(KC_EQUAL); // ´
        });
      } else {
        without_mods(MOD_MASK_SA, {
          tap_code16(LSFT(KC_EQUAL)); // `
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LALT(KC_G)); // ©
      } else if(is_win()) {
        register_code(KC_LALT);
        tap_code(KC_KP_1);
        tap_code(KC_KP_8);
        tap_code(KC_KP_4);
        unregister_code(KC_LALT);
      }
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void v(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_SA, {
      if(is_mac()) {
        tap_code16(LSFT(LALT(KC_E))); // ‰
      } else if(is_win()) {
        register_code(KC_LALT);
        tap_code(KC_KP_0);
        tap_code(KC_KP_1);
        tap_code(KC_KP_3);
        tap_code(KC_KP_7);
        unregister_code(KC_LALT);
      }
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void b(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || !has_mods(MOD_MASK_CG)) { // no mods or combination of alt and shift
      if(has_mods(MOD_MASK_SHIFT)) {
        without_mods(MOD_MASK_SA, {
          key_report(min(2, state->count), {
            if(is_mac()) tap_code(KC_NONUS_BSLASH); // ^
            else if(is_win()) tap_code(KC_GRAVE);
          });
        });
      } else {
        without_mods(MOD_MASK_ALT, {
          if(is_mac()) tap_code(KC_GRAVE); // <
          else if(is_win()) tap_code(KC_NONUS_BSLASH);
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void y(qk_tap_dance_state_t *state, void *user_data) { // geman z
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_SA, {
        if(is_mac()) tap_code16(LALT(KC_9)); // {
        else if(is_win()) tap_code16(ALGR(KC_0));
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void u(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_ALT, {
        tap_code(KC_LBRACKET); // ü
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LALT(KC_U)); // umlaut (¨)
      } else if(is_win()) {
        register_code(KC_LALT);
        tap_code(KC_KP_0);
        tap_code(KC_KP_1);
        tap_code(KC_KP_6);
        tap_code(KC_KP_8);
        unregister_code(KC_LALT);
      }
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void i(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_SA, {
        if(is_mac()) {
          tap_code16(LALT(KC_Q)); // «
        } else if(is_win()) {
          register_code(KC_LALT);
          tap_code(KC_KP_1);
          tap_code(KC_KP_7);
          tap_code(KC_KP_4);
          unregister_code(KC_LALT);
        }
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void o(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_ALT, {
        tap_code(KC_SCOLON); // ö
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LSFT(LALT(KC_O))); // Ø
      } else if(is_win()) {
        register_code(KC_LALT);
        tap_code(KC_KP_1);
        tap_code(KC_KP_5);
        tap_code(KC_KP_5);
        unregister_code(KC_LALT);
      }
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void h(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || !has_mods(MOD_MASK_CG)) { // no mods or combination of alt and shift
      if(has_mods(MOD_MASK_SHIFT)) {
        without_mods(MOD_MASK_SA, {
          if(is_mac()) tap_code16(LALT(KC_6)); // ]
          else if(is_win()) tap_code16(ALGR(KC_9));
        });
      } else {
        without_mods(MOD_MASK_ALT, {
          tap_code16(LSFT(KC_9)); // )
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code(KC_BSLASH); // #
      });
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void n(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) tap_code16(LALT(KC_N)); // ~
      else if(is_win()) tap_code16(ALGR(KC_RBRACKET));
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void k(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code16(LSFT(KC_0)); // =
      });
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void l(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) tap_code16(LALT(KC_L)); // @
      else if(is_win()) tap_code16(ALGR(KC_Q));
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void p(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_SA, {
        if(is_mac()) {
          tap_code16(LALT(KC_P)); // π
        } else if(is_win()) {
          register_code(KC_LALT); // this unicode does not work on all windows apps (e.g. notepad cant, but word does well)
          tap_code(KC_KP_9);
          tap_code(KC_KP_6);
          tap_code(KC_KP_0);
          unregister_code(KC_LALT);
        }
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG)) {
    if(has_mods(MOD_MASK_SHIFT)) {
      without_mods(MOD_MASK_ALT, {
        key_pass(state);
      });
    } else {
      without_mods(MOD_MASK_ALT, {
        tap_code16(LSFT(KC_5)); // %
      });
    }
    return;
  }
  key_pass(state);
};



void j(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_SA, {
        if(is_mac()) tap_code16(LSFT(KC_GRAVE)); // >
        else if(is_win()) tap_code16(LSFT(KC_NONUS_BSLASH));
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG)) {
    if(has_mods(MOD_MASK_SHIFT)) {
      without_mods(MOD_MASK_ALT, {
        key_pass(state);
      });
    } else {
      without_mods(MOD_MASK_ALT, {
        key_report(state->count, {
          tap_code16(LSFT(KC_6)); // &
        });
      });
    }
    return;
  }
  key_pass(state);
};



void m(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_SA, {
        if(is_mac()) {
          tap_code16(LALT(KC_M)); // µ
        } else if(is_win()) {
          register_code(KC_LALT);
          tap_code(KC_KP_2);
          tap_code(KC_KP_3);
          tap_code(KC_KP_0);
          unregister_code(KC_LALT);
        }
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG)) {
    if(has_mods(MOD_MASK_SHIFT)) {
      without_mods(MOD_MASK_ALT, {
        key_pass(state);
      });
    } else {
      without_mods(MOD_MASK_ALT, {
        key_report(state->count, {
          tap_code(KC_KP_ASTERISK); // numpad multiply (*)
        });
      });
    }
    return;
  }
  key_pass(state);
};



void comma(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_CSAG, {
      key_report(state->count, {
        tap_code16(LSFT(KC_MINUS)); // ?
      });
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



void dot(qk_tap_dance_state_t *state, void *user_data) {
  if(key_down(state)) {
    if(!has_mods(MOD_MASK_CSAG) || (has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG))) {
      without_mods(MOD_MASK_SA, {
        if(is_mac()) {
          tap_code16(LALT(KC_DOT)); // …
        } else if(is_win()) {
          register_code(KC_LALT);
          tap_code(KC_KP_0);
          tap_code(KC_KP_1);
          tap_code(KC_KP_3);
          tap_code(KC_KP_3);
          unregister_code(KC_LALT);
        }
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_SA) && !has_mods(MOD_MASK_CG)) {
    if(has_mods(MOD_MASK_SHIFT)) {
      without_mods(MOD_MASK_ALT, {
        key_pass(state);
      });
    } else {
      without_mods(MOD_MASK_CSAG, {
        key_report(state->count, {
          tap_code16(LSFT(KC_1)); // !
        });
      });
    }
    return;
  }
  key_pass(state);
};



void slash(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LALT(KC_SLASH)); // hyphen (–)
      } else if(is_win()) {
        register_code(KC_LALT);
        tap_code(KC_KP_4);
        tap_code(KC_KP_5);
        unregister_code(KC_LALT);
      }
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && has_mods(MOD_MASK_SHIFT) && !has_mods(MOD_MASK_CG)) {
    without_mods(MOD_MASK_ALT, {
      key_pass(state);
    });
    return;
  }
  key_pass(state);
};



qk_tap_dance_action_t tap_dance_actions[] = {
  [KC_Q] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, q, NULL, HOLD_TIMER),
  [KC_W] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, w, NULL, HOLD_TIMER),
  [KC_E] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, e, NULL, HOLD_TIMER),
  [KC_R] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, r, NULL, HOLD_TIMER),
  [KC_F] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, f, NULL, HOLD_TIMER),
  [KC_A] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, a, NULL, HOLD_TIMER),
  [KC_S] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, s, NULL, HOLD_TIMER),
  [KC_D] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, d, NULL, HOLD_TIMER),
  [KC_T] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, t, NULL, HOLD_TIMER),
  [KC_G] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, g, NULL, HOLD_TIMER),
  [KC_Z] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, z, NULL, HOLD_TIMER), // german y
  [KC_X] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, x, NULL, HOLD_TIMER),
  [KC_C] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, c, NULL, HOLD_TIMER),
  [KC_V] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, v, NULL, HOLD_TIMER),
  [KC_B] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, b, NULL, HOLD_TIMER),
  [KC_Y] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, y, NULL, HOLD_TIMER), // german z
  [KC_U] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, u, NULL, HOLD_TIMER),
  [KC_I] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, i, NULL, HOLD_TIMER),
  [KC_O] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, o, NULL, HOLD_TIMER),
  [KC_H] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, h, NULL, HOLD_TIMER),
  [KC_N] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, n, NULL, HOLD_TIMER),
  [KC_K] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, k, NULL, HOLD_TIMER),
  [KC_L] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, l, NULL, HOLD_TIMER),
  [KC_P] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, p, NULL, HOLD_TIMER),
  [KC_J] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, j, NULL, HOLD_TIMER),
  [KC_M] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, m, NULL, HOLD_TIMER),
  [KC_COMMA] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, comma, NULL, HOLD_TIMER),
  [KC_DOT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dot, NULL, HOLD_TIMER),
  [KC_SLASH] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, slash, NULL, HOLD_TIMER),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case MAC:
      set_single_persistent_default_layer(MACOS);
      return false;
    case WIN:
      set_single_persistent_default_layer(WINDOWS);
      return false;
  }

  if(is_win() && record->event.pressed && !has_mods(MOD_MASK_AG) && has_mods(MOD_MASK_CTRL)) {
    switch(keycode) {
      case KC_LEFT:
        without_mods(MOD_MASK_CTRL, {
          tap_code(KC_HOME); // jump to beginning of line or file
        });
        return false;
      
      case KC_UP:
        without_mods(MOD_MASK_CTRL, {
          tap_code16(LCTL(KC_HOME)); // KC_PGUP
        });
        return false;
      
      case KC_RIGHT:
        without_mods(MOD_MASK_CTRL, {
          tap_code(KC_END); // jump to end of line or file
        });
        return false;

      case KC_DOWN:
        without_mods(MOD_MASK_CTRL, {
          tap_code16(LCTL(KC_END)); // KC_PGDOWN
        });
        return false;
      
      case RALT_T(KC_DELETE):
      case KC_DELETE:
        without_mods(MOD_MASK_CS, {
          tap_code16(LSFT(KC_END)); // select everything to the right
          tap_code(KC_DELETE);
        });
        return false;
      
      case RALT_T(KC_BSPACE):
      case KC_BSPACE:
        without_mods(MOD_MASK_CS, {
          tap_code16(LSFT(KC_HOME)); // select everything to the left
          tap_code(KC_BSPACE);
        });
        return false;
    }
  }

  if(is_win() && record->event.pressed && !has_mods(MOD_MASK_CSG) && has_mods(MOD_MASK_ALT)) {
    switch(keycode) {
      case KC_LEFT:
        without_mods(MOD_MASK_ALT, {
          tap_code16(LCTL(keycode)); // jump over word to the left
        });
        return false;
      
      case KC_RIGHT:
        without_mods(MOD_MASK_ALT, {
          tap_code16(LCTL(keycode)); // jump over word to the right
        });
        return false;
      
      case RALT_T(KC_DELETE):
      case KC_DELETE:
        without_mods(MOD_MASK_ALT, {
          tap_code16(LCTL(KC_DELETE)); // delete word to the right
        });
        return false;
      
      case RALT_T(KC_BSPACE):
      case KC_BSPACE:
        without_mods(MOD_MASK_ALT, {
          tap_code16(LCTL(KC_BSPACE)); // delete word to the left
        });
        return false;
    }
  }

  return true;
};
