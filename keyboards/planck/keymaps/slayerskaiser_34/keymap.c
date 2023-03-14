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

enum planck_layers {
  _BASE,
  _SYM,
  _BRAC,
  _FUN,
  _NUM,
  _MOUSE,
  _BLANK,
};

enum planck_keycodes {
    CAPSWORD = SAFE_RANGE,
};

#define TO_BASE TO(_BASE)
#define TO_MOUSE TO(_MOUSE)
#define TO_NUM TO(_NUM)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_SHFT OSM(MOD_LSFT)
#define LAY_SYM MO(_SYM)
#define LAY_BRC MO(_BRAC)
#define LAY_NUM MO(_NUM)

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Qwerty layout
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Shift |Brackt|             |  Sym |Space |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    XXXXXXX, XXXXXXX, XXXXXXX, OS_SHFT, LAY_BRC, XXXXXXX, XXXXXXX, LAY_SYM, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX
),

/* Symbols, navigation, and modifiers
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   -  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Alt |  GUI |Shift |  Esc |      |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |Insert|Delete| BkSp |  Tab |      |      | Home |PageDn|PageUp| End  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL ,
    OS_CTRL, OS_ALT,  OS_GUI,  OS_SHFT, KC_ESC,  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    KC_GRV,  KC_INS,  KC_DEL,  KC_BSPC, KC_TAB,  XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ENT ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Brackets
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |   !  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   |  |   {  |   }  |   -  |   \  |      |      |   :  |   =  |   (  |   )  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   <  |   >  |   _  |   /  |      |      |   *  |   +  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BRAC] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EXLM, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_BSLS, XXXXXXX, XXXXXXX, KC_COLN, KC_EQL,  KC_LPRN, KC_RPRN, KC_SCLN,
    KC_TILD, KC_LABK, KC_RABK, KC_UNDS, KC_SLSH, XXXXXXX, XXXXXXX, KC_ASTR, KC_PLUS, KC_LBRC, KC_RBRC, KC_ENT ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Function keys
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F6  |  F4  |  F10 |  F2  |  F12 |      |      |  F11 |  F3  |  F1  |  F5  |  F7  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  F8  |      |      |      |      |  F9  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX,
    KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,  XXXXXXX, XXXXXXX, KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7  ,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F9,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |  Tab |BRT DN|BRT DN|      |      |      |M PREV|M NEXT|V MUTE|VOL DN|VOL UP| BkSp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   6  |   4  |   0  |   2  |      |      |      |M PLAY|   3  |   1  |   5  |   7  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   8  |      |      |      |      |   9  |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    KC_TAB,  KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSPC,
    KC_6,    KC_4,    KC_0,    KC_2,    XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_3,    KC_1,    KC_5,    KC_7   ,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_8,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_9,    XXXXXXX, XXXXXXX, KC_ENT ,
    XXXXXXX, XXXXXXX, XXXXXXX, TO_BASE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Mouse layer for test layout
 * ,-----------------------------------------------------------------------------------.
 * |      |MWhl L|Mous U|MWhl R|      |      |      |      |MousA0|MousA1|MousA2|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Mous L|Mous D|Mous R|      |      |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MWhl U|MWhl D|      |      |      |      |MousLC|MousMC|MousRC|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Base |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,
    XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_WH_U, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, TO_BASE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Blank layer for copying
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BLANK] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _SYM, _BRAC, _FUN);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case CAPSWORD:
    if (record->event.pressed) {
      caps_word_on();
    }
    return false;
    break;
  }

  return true;
}

void matrix_scan_user(void) {
}
