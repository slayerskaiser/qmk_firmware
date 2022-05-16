/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

// #include "g/keymap_combo.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _ONEPRODUCT,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _MOVEMENT,
  _NUMPAD
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  ONEPDCT,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)
// #define LOWER LT(_LOWER, KC_ENTER)
#define RAISE LT(_RAISE, KC_ENTER)
#define MOVE MO(_MOVEMENT)
#define C_ESC LCTL_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Move | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    C_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
    MOVE,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Move | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    C_ESC,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
    MOVE,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Move | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    C_ESC,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    SFT_ENT,
    MOVE,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Oneproduct
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   B  |   L  |   D  |   W  |   G  |   J  |   ,  |   O  |   Y  |   Q  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   N  |   R  |   S  |   T  |   M  |   U  |   A  |   E  |   I  |   H  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   P  |   Z  |   C  |   F  |   V  |   X  |   .  |   ;  |   /  |   K  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Move | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_ONEPRODUCT] = LAYOUT_planck_grid(
    KC_TAB,  KC_B,    KC_L,    KC_D,    KC_W,    KC_G,    KC_J,    KC_COMM, KC_O,    KC_Y,    KC_Q,    KC_BSPC,
    C_ESC,   KC_N,    KC_R,    KC_S,    KC_T,    KC_M,    KC_U,    KC_A,    KC_E,    KC_I,    KC_H,    KC_QUOT,
    KC_LSFT, KC_P,    KC_Z,    KC_C,    KC_F,    KC_V,    KC_X,    KC_DOT,  KC_SCLN, KC_SLSH, KC_K,    SFT_ENT,
    MOVE,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |      |      |   %  |   ^  |   &  |   *  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |   {  |   [  |   (  |      |      |   )  |   ]  |   }  |   |  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   _  |   -  |      |      |   =  |   +  |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  XXXXXXX, XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSPC,
    KC_DEL,  XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX, XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE, KC_BSLS, 
    _______, XXXXXXX, XXXXXXX, KC_UNDS, KC_MINS, XXXXXXX, XXXXXXX, KC_EQL,  KC_PLUS, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |   {  |   [  |   (  |      |      |   )  |   ]  |   }  |   |  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   _  |   -  |      |      |   =  |   +  |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX, XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE, KC_BSLS,
    _______, XXXXXXX, XXXXXXX, KC_UNDS, KC_MINS, XXXXXXX, XXXXXXX, KC_EQL,  KC_PLUS, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|1Prdct|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |Brght-|Brght+|      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  PLOVER,  ONEPDCT,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_BRMD, KC_BRMU, _______
),

/* Movement
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |MousLC|Mous L|Mous D|Mous U|Mous R|  Del | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |MousMC| Left | Down |  Up  |Right |      |PrtScr|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |MousRC| MW L | MW D | MW U | MW R |Insert|Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             | Menu | Home |Pg Dn |Pg Up | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVEMENT] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_DEL,  KC_BSPC,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_BTN3, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_PSCR,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BTN2, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_INS,  KC_ENT ,
    _______, _______, _______, _______, _______, _______, _______, KC_APP,  KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |   E  |   7  |   8  |   9  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |   *  |   4  |   5  |   6  |   -  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |   /  |   1  |   2  |   3  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   .  |   ,  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, KC_E,    KC_7,    KC_8,    KC_9,    XXXXXXX, KC_BSPC,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_PAST, KC_4,    KC_5,    KC_6,    KC_PMNS, KC_EQL ,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_PSLS, KC_1,    KC_2,    KC_3,    KC_PPLS, KC_ENT ,
    _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_COMM, XXXXXXX, XXXXXXX
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  // return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWER, _MOVEMENT, _NUMPAD);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // print("mode just switched to qwerty and this is a huge string\n");
        // set_single_persistent_default_layer(_QWERTY);
        default_layer_set(1 << _QWERTY);
        // combo_enable();
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        // set_single_persistent_default_layer(_COLEMAK);
        default_layer_set(1 << _COLEMAK);
        // combo_disable();
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        // set_single_persistent_default_layer(_DVORAK);
        default_layer_set(1 << _DVORAK);
        // combo_disable();
      }
      return false;
      break;
    case ONEPDCT:
      if (record->event.pressed) {
        default_layer_set(1 << _ONEPRODUCT);
        // combo_disable();
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      // combo_disable();
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);

        if (default_layer_state == (1 << _QWERTY)) {
          // Combs defined assuming QWERTY
          // combo_enable();
        }
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

const key_override_t prev_track_override = ko_make_basic(MOD_MASK_GUI, KC_MNXT, KC_MPRV);
const key_override_t mute_volup_override = ko_make_basic(MOD_MASK_GUI, KC_VOLU, KC_MUTE);
const key_override_t mute_voldown_override = ko_make_basic(MOD_MASK_GUI, KC_VOLD, KC_MUTE);
// const key_override_t oneproduct_slash_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_SLSH, 1 << _ONEPRODUCT);
// const key_override_t oneproduct_qmark_override = ko_make_with_layers_and_negmods(0, KC_SLSH, KC_QUESTION, 1 << _ONEPRODUCT, MOD_MASK_SHIFT);

const key_override_t **key_overrides = (const key_override_t *[]){
    &prev_track_override,
    &mute_volup_override,
    &mute_voldown_override,
    NULL
};

