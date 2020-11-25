// keymap for Kinesis Advantage2 (KB600) QWERTZ layout
// designed to run on MacOS/iPadOS/iOS and Windows
// please set system keyboard language to german!

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum keyboard_layer {
  MACOS,
  WINDOWS,
  NUMPAD,
};

enum custom_keycode {
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
    DE_ACUT,      DE_1,       DE_2,       DE_3,       DE_4,            DE_5,
    XXXXXXX,      XXXXXXX,    TD(DE_W),   TD(DE_E),   TD(DE_R),        TD(DE_F),
    XXXXXXX,      TD(DE_A),   TD(DE_S),   TD(DE_D),   TD(DE_T),        TD(DE_G),
    XXXXXXX,      TD(DE_Y),   TD(DE_X),   TD(DE_C),   TD(DE_V),        TD(DE_B),
                  DE_CIRC,    DE_LABK,    XXXXXXX,    KC_LGUI,
    // left thumb
                  LALT_T(KC_DELETE),      XXXXXXX,
                                          KC_LCTRL,
    KC_SPACE,     LSFT_T(KC_TAB),         KC_LGUI,
    // right keywell
    KC_F9,      KC_F10,    KC_F11,        KC_F12,      KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  XXXXXXX,  RESET,
    DE_6,       DE_7,      DE_8,          DE_9,        DE_0,           DE_SS,
    TD(DE_Z),   TD(DE_U),  TD(DE_I),      TD(DE_O),    XXXXXXX,        XXXXXXX,
    TD(DE_H),   TD(DE_N),  TD(DE_K),      TD(DE_L),    TD(DE_P),       XXXXXXX,
    TD(DE_J),   TD(DE_M),  TD(DE_COMM),   TD(DE_DOT),  TD(DE_MINS),    XXXXXXX,
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
    XXXXXXX,      KC_BRIGHTNESS_UP,   KC_BRIGHTNESS_DOWN,   XXXXXXX,    XXXXXXX,    MAC,      WIN,  XXXXXXX,  XXXXXXX,
    XXXXXXX,      XXXXXXX,            XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,      XXXXXXX,            XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,      DE_1,               DE_2,                 DE_3,       DE_4,       DE_5,
    XXXXXXX,      XXXXXXX,            XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,
                  XXXXXXX,            XXXXXXX,              XXXXXXX,    XXXXXXX,
    // left thumb
                  XXXXXXX,   XXXXXXX,
                             _______,
    _______,      XXXXXXX,   _______,
    // right keywell
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  XXXXXXX,  XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,     XXXXXXX,
    XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,     XXXXXXX,
    DE_6,         DE_7,      DE_8,      DE_9,       DE_0,        XXXXXXX,
    XXXXXXX,      XXXXXXX,   DE_COMM,   DE_DOT,     XXXXXXX,     XXXXXXX,
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
          tap_code16(LSFT(LALT(DE_Q))); // »
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
        tap_code(DE_EURO); // €
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
          tap_code16(LALT(DE_R)); // ®
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
        if(is_mac()) tap_code16(LALT(DE_8)); // {
        else if(is_win()) tap_code(DE_LCBR);
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
        tap_code(DE_ADIA); // ä
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) { // alt but no shift pressed (ctrl or gui may be present)
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code(DE_PLUS); // +
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
          tap_code(DE_DLR); // $
        });
      } else if(has_mods(MOD_MASK_ALT)) {
        without_mods(MOD_MASK_ALT, {
          tap_code(DE_SECT); // §
        });
      } else {
        tap_code(DE_SS); // ß
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code(DE_MINS); // -
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
          if(is_mac()) tap_code16(LALT(DE_7)); // back slash
          else if(is_win()) tap_code(DE_BSLS);
        });
      } else if(has_mods(MOD_MASK_ALT)) {
        without_mods(MOD_MASK_SA, {
          key_report(state->count, {
            if(is_mac()) tap_code16(LALT(DE_7)); // pipe
            else if(is_win()) tap_code(DE_PIPE);
          });
        });
      } else {
        key_report(state->count, {
          tap_code(DE_SLSH); // forward slash
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code(DE_SLSH); // divide
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
          tap_code(DE_QUOT); // '
        });
      } else {
        without_mods(MOD_MASK_ALT, {
          tap_code(DE_DQUO); // "
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LSFT(LALT(DE_D))); // ™
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
          if(is_mac()) tap_code16(LALT(DE_5)); // [
          else if(is_win()) tap_code(DE_LBRC);
        });
      } else {
        without_mods(MOD_MASK_ALT, {
          tap_code(DE_LPRN); // (
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      tap_code(DE_DEG); // °
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
          tap_code(DE_ACUT); // ´
        });
      } else {
        without_mods(MOD_MASK_SA, {
          tap_code(DE_GRV); // `
        });
      }
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LALT(DE_G)); // ©
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
        tap_code16(LSFT(LALT(DE_E))); // ‰
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
            tap_code(DE_CIRC); // ^
          });
        });
      } else {
        without_mods(MOD_MASK_ALT, {
          tap_code(DE_LABK); // <
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
        if(is_mac()) tap_code16(LALT(DE_9)); // {
        else if(is_win()) tap_code(DE_LCBR);
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
        tap_code(DE_UDIA); // ü
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LALT(DE_U)); // umlaut (¨)
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
          tap_code16(LALT(DE_Q)); // «
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
        tap_code(DE_ODIA); // ö
      });
      return;
    }
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LSFT(LALT(DE_O))); // Ø
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
          if(is_mac()) tap_code16(LALT(DE_6)); // ]
          else if(is_win()) tap_code(DE_RBRC);
        });
      } else {
        without_mods(MOD_MASK_ALT, {
          tap_code(DE_RPRN); // )
        });
      }
      return;
    }
  }
  if(is_win() && has_mods(MOD_MASK_CTRL) && !has_mods(MOD_MASK_SAG)) { // ctrl + h keybinding
    without_mods(MOD_MASK_CSAG, {
      tap_code16(LGUI(KC_DOWN)); // send Win + Arrow Down to emulate Cmd + H on MacOS
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code(DE_HASH); // #
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
      if(is_mac()) tap_code16(LALT(DE_N)); // ~
      else if(is_win()) tap_code(DE_TILD);
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



void k(qk_tap_dance_state_t *state, void *user_data) { // also q key
  if(key_down(state)) {
    if(is_win() && has_mods(MOD_MASK_CTRL) && !has_mods(MOD_MASK_SAG)) { // ctrl + q keybinding
      without_mods(MOD_MASK_CSAG, {
        tap_code16(LALT(KC_F4)); // send Alt+F4 to emulate Cmd + Q on MacOS
      });
      return;
    }
    if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_CG)) { // alt pressed (additionally shift might be present)
      without_mods(MOD_MASK_ALT, {
        key_report(state->count, {
          tap_code(DE_Q); // Q key
        });
      });
      return;
    }
    key_report(state->count, {
      tap_code(DE_Q);
    });
    return;
  }
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      key_report(state->count, {
        tap_code(DE_EQL); // =
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
      if(is_mac()) tap_code16(LALT(DE_L)); // @
      else if(is_win()) tap_code(DE_AT);
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
          tap_code16(LALT(DE_P)); // π
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
        tap_code(DE_PERC); // %
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
        tap_code(DE_RABK); // >
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
          tap_code(DE_AMPR); // &
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
        if(is_mac()) tap_code16(LALT(DE_M)); // µ
        else if(is_win()) tap_code(DE_MICR);
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
          tap_code(DE_ASTR); // *
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
        tap_code(DE_QUES); // ?
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
          tap_code16(LALT(DE_DOT)); // …
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
          tap_code(DE_EXLM); // !
        });
      });
    }
    return;
  }
  key_pass(state);
};



void mins(qk_tap_dance_state_t *state, void *user_data) {
  if(has_mods(MOD_MASK_ALT) && !has_mods(MOD_MASK_SHIFT)) {
    without_mods(MOD_MASK_ALT, {
      if(is_mac()) {
        tap_code16(LALT(DE_MINS)); // hyphen (–)
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
  [DE_W] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, w, NULL, HOLD_TIMER),
  [DE_E] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, e, NULL, HOLD_TIMER),
  [DE_R] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, r, NULL, HOLD_TIMER),
  [DE_F] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, f, NULL, HOLD_TIMER),
  [DE_A] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, a, NULL, HOLD_TIMER),
  [DE_S] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, s, NULL, HOLD_TIMER),
  [DE_D] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, d, NULL, HOLD_TIMER),
  [DE_T] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, t, NULL, HOLD_TIMER),
  [DE_G] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, g, NULL, HOLD_TIMER),
  [DE_Z] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, z, NULL, HOLD_TIMER), // german y
  [DE_X] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, x, NULL, HOLD_TIMER),
  [DE_C] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, c, NULL, HOLD_TIMER),
  [DE_V] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, v, NULL, HOLD_TIMER),
  [DE_B] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, b, NULL, HOLD_TIMER),
  [DE_Y] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, y, NULL, HOLD_TIMER), // german z
  [DE_U] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, u, NULL, HOLD_TIMER),
  [DE_I] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, i, NULL, HOLD_TIMER),
  [DE_O] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, o, NULL, HOLD_TIMER),
  [DE_H] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, h, NULL, HOLD_TIMER),
  [DE_N] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, n, NULL, HOLD_TIMER),
  [DE_K] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, k, NULL, HOLD_TIMER),
  [DE_L] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, l, NULL, HOLD_TIMER),
  [DE_P] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, p, NULL, HOLD_TIMER),
  [DE_J] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, j, NULL, HOLD_TIMER),
  [DE_M] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, m, NULL, HOLD_TIMER),
  [DE_COMM] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, comma, NULL, HOLD_TIMER),
  [DE_DOT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dot, NULL, HOLD_TIMER),
  [DE_MINS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, mins, NULL, HOLD_TIMER),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case MAC:
      if(!is_mac()) {
        set_single_persistent_default_layer(MACOS);
        return false;
      }
    case WIN:
      if(!is_win()) {
        set_single_persistent_default_layer(WINDOWS);
        return false;
      }
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
