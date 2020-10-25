#include QMK_KEYBOARD_H

enum custom_layer {
  QWERTY_MACOS,
  QWERTY_WINDOWS
};

enum custom_key {
  KC_PROGM
};

enum custom_modifier {
  MOD_PROGM = MOD_HYPR + 1 // TODO is it possible to create new modifier keys myself?
};

/*
*
* The ASCII-graphic shows a Kinesis Advantage2 with its default QWERTY layout
* However, this particular layout is MY favorite key- and macro mappings for both Windows and MacOS
* Please note that this layout is meant to be used on computers with their system language set to german (it won't work with en_us)!!!
* Also note that I'm using a Kinesis Advantage2 KB600 DE QWERTZ
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY_MACOS] = LAYOUT(
    // left keywell
    XXXXXXX,      KC_F1,    KC_F2,    KC_F3,    KC_F4,      KC_F5,  KC_F6,  KC_F7,  KC_F8,

    XXXXXXX,      KC_1,     KC_2,     KC_3,     KC_4,       KC_5,
    XXXXXXX,      KC_Q,     KC_W,     KC_E,     KC_R,       KC_F,
    KC_EXCLAIM,   KC_A,     KC_S,     KC_D,     KC_T,       KC_G,
    XXXXXXX,      KC_Z,     KC_X,     KC_C,     KC_V,       KC_B,
                  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LGUI,
    
    LALT_T(KC_DELETE),  XXXXXXX,
                        KC_LCTRL,
    KC_SPACE,           KC_LSHIFT,  KC_LGUI,

    // right keywell
    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC__MUTE,   KC__VOLDOWN,  KC__VOLUP,  XXXXXXX,  KC_PROGM,

    KC_6,     KC_7,     KC_8,       KC_9,     KC_0,       XXXXXXX,
    KC_Y,     KC_U,     KC_I,       KC_O,     XXXXXXX,    XXXXXXX,
    KC_H,     KC_N,     KC_K,       KC_L,     KC_P,       KC_QUESTION,
    KC_J,     KC_M,     KC_COMMA,   KC_DOT,   KC_SLASH,   XXXXXXX,
              KC_LEFT,  KC_DOWN,    KC_UP,    KC_RGHT,

    KC_LALT,          LALT_T(KC_BSPACE),
    XXXXXXX,
    KC_LEAD,  RSFT_T(KC_ENTER),   XXXXXXX
  )
};



void matrix_init_user(void) {
};



bool chord_leader_succeeded;
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    chord_leader_succeeded = leading = false;

    SEQ_TWO_KEYS(KC_A, KC_E) {
      register_code(KC_BSLASH);
      unregister_code(KC_BSLASH);
      chord_leader_succeeded = true;
      return leader_end();
    }

    SEQ_TWO_KEYS(KC_S, KC_S) {
      register_code(KC_MINUS);
      unregister_code(KC_MINUS);
      chord_leader_succeeded = true;
      return leader_end();
    }

    SEQ_TWO_KEYS(KC_U, KC_E) {
      register_code(KC_QUOTE);
      unregister_code(KC_QUOTE);
      chord_leader_succeeded = true;
      return leader_end();
    }

    SEQ_TWO_KEYS(KC_O, KC_E) {
      register_code(KC_SCOLON);
      unregister_code(KC_SCOLON);
      chord_leader_succeeded = true;
      return leader_end();
    }

    leader_end();
  }
};



void leader_end(void) {
  if(!chord_leader_succeeded) {
    register_code(KC_ESCAPE); // escape key is also the leader key for key chords
    unregister_code(KC_ESCAPE);
  }
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { // override default tap-and-hold timing on a key-basis
    switch(keycode) {
        case LALT_T(KC_DELETE) || LALT_T(KC_BSPACE) || RSFT_T(KC_ENTER) || RGUI_T(KC_ESCAPE): return 100;
        default: return TAPPING_TERM;
    }
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {

    // re-program teensy 3.6 board
    case KC_F9:
      if(record->event.pressed && get_mods() & MOD_BIT(KC_PROGM)) {
        SEND_STRING("TODO software solution to enter dfu-mode without pressing reset button in hardware?");
      }
      return false;
    

    // switch to PC/Windows layout
    case KC_F7:
      if(record->event.pressed && /*!IS_LAYER_ON(QWERTY_WINDOWS) &&*/ get_mods() & MOD_BIT(KC_PROGM)) {
        set_single_persistent_default_layer(QWERTY_WINDOWS);
        SEND_STRING("set default to QWERTY_WINDOWS");
      }
      return false;
    

    // switch to MacOS/iOS/iPadOS keyboard layout
    case KC_F5:
      if(record->event.pressed && /*!IS_LAYER_ON(QWERTY_MACOS) &&*/ get_mods() & MOD_BIT(KC_PROGM)) {
        set_single_persistent_default_layer(QWERTY_MACOS);
        SEND_STRING("set default to QWERTY_MACOS");
      }
      return false; // prevent default (QMK does not send events for this key)
    

    // quit current application
    // KC_LGUI + KC_Q on mac equals to KC_LALT + KC_F4 on windows
    case KC_Q:
      if(record->event.pressed && /*IS_LAYER_ON(QWERTY_WINDOWS) &&*/ get_mods() & MOD_BIT(MOD_LGUI)) { //MOD_BIT(MOD_LGUI | MOD_RGUI)
        SEND_STRING("quit application (windows only)");
        return false;
	    }
    

    default:
      return true;
  }
};



void led_set_user(uint8_t usb_led) {
};
