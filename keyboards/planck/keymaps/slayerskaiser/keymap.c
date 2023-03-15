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

/* #include "tap_hold.h" */

/* #include "features/achordion.h" */

enum planck_layers {
  _QWERTY,
  /* _COLEMAK, */
  _DVORAK,
  /* _ONEPRODUCT, */
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _MOVEMENT,
  _NUMPAD,
  _TEST,
  _TEST_MOD,
  _TEST_NAV,
  _WIN_NAV,
  _TEST_NUM,
  _TEST_MOUSE,
  _TEST_FUN,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  /* COLEMAK, */
  DVORAK,
  /* ONEPDCT, */
  TEST,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  EX_TEST,
  DT_EXLM,
  WIN_ALT,
  NUMWORD,
  NCANCEL,
  SWP_S_E,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOVE MO(_MOVEMENT)
#define C_ESC LCTL_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENTER)

/* #define T_MOVE MO(_TEST_MOUSE) */
#define T_MOVE TG(_TEST_MOUSE)
#define T_NUM MO(_TEST_NUM)
#define T_FUN MO(_TEST_FUN)
#define T_SHIFT OSM(MOD_LSFT)
#define T_RSHFT OSM(MOD_RSFT)
#define T_CTRL OSM(MOD_LCTL)
#define T_ALT OSM(MOD_LALT)
#define T_GUI OSM(MOD_LGUI)

#define SPC_MOD LT(_TEST_MOD, KC_SPC)
#define BSP_MOD LT(_TEST_MOD, KC_BSPC)
#define ENT_NAV LT(_TEST_NAV, KC_ENT)

/* enum { */
/*     COM_MIN, */
/*     DOT_UND, */
/*     SLS_EQL, */
/*     Z_GUI, */
/* }; */
/* typedef struct { */
/*     uint16_t tap; */
/*     uint16_t hold; */
/*     uint16_t held; */
/* } tap_dance_tap_hold_t; */

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
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
/* [_COLEMAK] = LAYOUT_planck_grid( */
/*     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, */
/*     C_ESC,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, */
/*     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, */
/*     MOVE,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT */
/* ), */

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
/* [_ONEPRODUCT] = LAYOUT_planck_grid( */
/*     KC_TAB,  KC_B,    KC_L,    KC_D,    KC_W,    KC_G,    KC_J,    KC_COMM, KC_O,    KC_Y,    KC_Q,    KC_BSPC, */
/*     C_ESC,   KC_N,    KC_R,    KC_S,    KC_T,    KC_M,    KC_U,    KC_A,    KC_E,    KC_I,    KC_H,    KC_QUOT, */
/*     KC_LSFT, KC_P,    KC_Z,    KC_C,    KC_F,    KC_V,    KC_X,    KC_DOT,  KC_SCLN, KC_SLSH, KC_K,    SFT_ENT, */
/*     MOVE,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT */
/* ), */

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |   {  |   [  |   (  |   -  |   =  |   )  |   ]  |   }  |   |  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   _  |   +  |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_EQL,  KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE, KC_BSLS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT ,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |   {  |   [  |   (  |   -  |   =  |   )  |   ]  |   }  |   |  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   _  |   +  |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_EQL,  KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE, KC_BSLS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT ,
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
 * |      | Reset|      | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|1Prdct|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |Brght-|Brght+|      |
 * `-----------------------------------------------------------------------------------'
 */
/* TEST,    _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  PLOVER,  ONEPDCT, */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    TEST,    _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  XXXXXXX, DVORAK,  PLOVER,  XXXXXXX,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRMD, KC_BRMU, _______
),
/* _______, QK_BOOT, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL , */
/* TEST,    _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  XXXXXXX,  DVORAK,  PLOVER,  XXXXXXX, */
/* _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, */
/* _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_BRMD, KC_BRMU, _______ */

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
),

/* Test layout
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Qwerty|      |  NUM |Space |Enter |             | BkSp |      |  FUN |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* KC_ESC,  QHOME_A, QHOME_S, QHOME_D, QHOME_F, KC_G,    KC_H,    QHOME_J, QHOME_K, QHOME_L, QHOME_SC, KC_QUOT, */
/* T_SHIFT, TD(Z_GUI),    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TD(COM_MIN), TD(DOT_UND), TD(SLS_EQL), T_RSHFT, */
/* KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, */
/* EX_TEST, XXXXXXX, T_NUM,   KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, T_MOVE,  XXXXXXX, XXXXXXX */
/* EX_TEST, XXXXXXX, T_NUM,   SPC_MOD, KC_ENT,  XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, T_MOVE,  XXXXXXX, XXXXXXX */

/* KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/* KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
/* KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, */

/* EX_TEST, XXXXXXX, T_NUM,   KC_ENT,  KC_E, XXXXXXX, XXXXXXX, KC_BSPC, SPC_MOD,  T_MOVE,  XXXXXXX, XXXXXXX */
/* EX_TEST, XXXXXXX, T_NUM,   KC_ENT,  SPC_MOD, XXXXXXX, XXXXXXX, KC_E,    KC_BSPC, T_MOVE,  XXXXXXX, XXXXXXX */

/* KC_TAB,  KC_J,    KC_C,    KC_Y,    KC_F,    KC_K,    KC_Z,    KC_L,    KC_O,    KC_U,    KC_Q,    KC_EQL , */
/* KC_ESC,  KC_R,    KC_S,    KC_T,    KC_H,    KC_P,    KC_M,    KC_N,    KC_A,    KC_I,    KC_MINS, KC_QUOT, */
/* T_SHIFT, KC_SLSH, KC_V,    KC_G,    KC_D,    KC_B,    KC_X,    KC_W,    KC_DOT,  KC_COMM, KC_SCLN, T_RSHFT, */

/* KC_TAB,  KC_J,    KC_C,    KC_Y,    KC_F,    KC_K,    KC_Z,    KC_L,    KC_COMM, KC_U,    KC_Q,    KC_EQL , */
/* KC_ESC,  KC_R,    KC_S,    KC_T,    KC_H,    KC_P,    KC_M,    KC_N,    KC_A,    KC_I,    KC_O,    KC_QUOT, */
/* T_SHIFT, KC_SLSH, KC_V,    KC_G,    KC_D,    KC_B,    KC_X,    KC_W,    KC_DOT,  KC_SCLN, KC_MINS, T_RSHFT, */

/* EX_TEST, XXXXXXX, T_NUM,   ENT_NAV, KC_E,    XXXXXXX, XXXXXXX, SPC_MOD, KC_BSPC, T_FUN,   XXXXXXX, XXXXXXX */
/* EX_TEST, XXXXXXX, T_NUM,   ENT_NAV, KC_E,    XXXXXXX, XXXXXXX, KC_SPC,  BSP_MOD, T_FUN,   XXXXXXX, XXXXXXX */
/* EX_TEST, XXXXXXX, T_NUM,   ENT_NAV, KC_SPC,  XXXXXXX, XXXXXXX, KC_E,    BSP_MOD, T_FUN,   XXXXXXX, XXXXXXX */

[_TEST] = LAYOUT_planck_grid(
	KC_TAB,  KC_J,    KC_C,    KC_Y,    KC_F,    KC_K,    KC_Z,    KC_L,    KC_COMM, KC_U,    KC_Q,    KC_EQL ,
	KC_ESC,  KC_R,    KC_S,    KC_T,    KC_H,    KC_P,    KC_M,    KC_N,    KC_A,    KC_I,    KC_O,    KC_QUOT,
	T_SHIFT, KC_SLSH, KC_V,    KC_G,    KC_D,    KC_B,    KC_X,    KC_W,    DT_EXLM, KC_SCLN, KC_MINS, T_RSHFT,
    EX_TEST, XXXXXXX, T_NUM,   ENT_NAV, KC_SPC,  XXXXXXX, XXXXXXX, KC_E,    BSP_MOD, T_FUN,   XXXXXXX, XXXXXXX
),

/* KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_BSPC, */
/* KC_DEL,  KC_CIRC, KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLSH, KC_EQL , */
/* _______, KC_AMPR, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_0,    KC_1,    KC_2,    KC_3,    KC_E,    _______, */
[_TEST_MOD] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PIPE, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL, C(KC_BSPC),
    KC_GRV,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_BSPC,
    XXXXXXX, T_CTRL,  T_ALT,   T_GUI,   T_SHIFT, XXXXXXX, XXXXXXX, T_SHIFT, T_GUI,   T_ALT,   T_CTRL,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_TEST_NAV] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, C(S(KC_TAB)), KC_UP, C(KC_TAB), XXXXXXX, XXXXXXX, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, XXXXXXX,
    XXXXXXX, WIN_ALT, KC_LEFT, KC_DOWN, KC_RGHT,      XXXXXXX, XXXXXXX, KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   XXXXXXX,
    XXXXXXX, T_CTRL,  T_ALT,   T_GUI,   T_SHIFT,      XXXXXXX, XXXXXXX, T_SHIFT, T_GUI,   T_ALT,   T_CTRL,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_WIN_NAV] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, S(KC_TAB), XXXXXXX, KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),


/* Lower layer for test layout
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   +  |   7  |   8  |   9  |   *  | BkSp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Del |   ^  |   <  |   (  |   )  |   >  |   -  |   4  |   5  |   6  |   /  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   &  |   {  |   [  |   ]  |   }  |   0  |   1  |   2  |   3  |   E  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_BSPC, */
/* KC_DEL,  KC_CIRC, KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLSH, KC_EQL , */
/* _______, KC_AMPR, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_0,    KC_1,    KC_2,    KC_3,    KC_E,    _______, */
/* XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, T_MOVE,  XXXXXXX, XXXXXXX */
[_TEST_NUM] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, XXXXXXX, XXXXXXX, XXXXXXX,
    NCANCEL, KC_6,    KC_4,    KC_0,    KC_2,    XXXXXXX, XXXXXXX, KC_3,    KC_1,    KC_5,    KC_7,    XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_8,    XXXXXXX, XXXXXXX, KC_9,    KC_DOT,  XXXXXXX, KC_MINS, XXXXXXX,
    XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, T_MOVE,  XXXXXXX, XXXXXXX
),

/* Raise layer for test layout
 * ,-----------------------------------------------------------------------------------.
 * |  Tab |      | Mute |Vol Dn|Vol Up|      |  F12 |  F7  |  F8  |  F9  |  Del | BkSp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Esc | Ctrl | Alt  | GUI  |Shift |      |  F11 |  F4  |  F5  |  F6  |   |  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BritDn|BritUp|M Prev|M Play|M Next|      |  F10 |  F1  |  F2  |  F3  |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_TEST_FUN] = LAYOUT_planck_grid(
    KC_TAB,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_DEL,  KC_BSPC,
    KC_ESC,  T_CTRL,  T_ALT,   T_GUI,   T_SHIFT, XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_PIPE, KC_BSLS,
    KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, KC_ENT ,
    XXXXXXX, XXXXXXX, T_MOVE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
),

/* Mouse layer for test layout
 * ,-----------------------------------------------------------------------------------.
 * |  Tab |PageUp|MWhl L|Mous U|MWhl R|      |      |MousA0|MousA1|MousA2|  Del | BkSp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Esc |PageDn|Mous L|Mous D|Mous R|      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift | Home |  End |MWhl U|MWhl D|      |      |MousLC|MousMC|MousRC|      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Ctrl |  Alt |             |Space |  GUI |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_TEST_MOUSE] = LAYOUT_planck_grid(
    KC_TAB,  KC_PGUP, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, KC_DEL,  KC_BSPC,
    KC_ESC,  KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    T_SHIFT, KC_HOME, KC_END,  KC_WH_U, KC_WH_D, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, KC_ENT ,
    XXXXXXX, XXXXXXX, T_MOVE,  T_CTRL,  T_ALT,   XXXXXXX, XXXXXXX, KC_SPC,  T_GUI,   T_MOVE,  XXXXXXX, XXXXXXX
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  // return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWER, _MOVEMENT, _NUMPAD);
  /* state = update_tri_layer_state(state, _TEST_NUM, _TEST_MOUSE, _TEST_FUN); */
  return state;
}

static bool _num_word_enabled;
bool process_num_word(uint16_t keycode, keyrecord_t *record) {
    if (!_num_word_enabled) return true;

    switch (keycode) {
    case KC_1 ... KC_0:
    case KC_BSPC:
    case BSP_MOD:
    case KC_COMM:
    case KC_TAB:
    case KC_DOT:
    case DT_EXLM:
    case KC_MINS:
    case KC_E:
        break;
    case NCANCEL:
        if (record->event.pressed) {
            _num_word_enabled = false;
            layer_off(_TEST_NUM);
        }
        return false;
    default:
        if (record->event.pressed) {
            _num_word_enabled = false;
            layer_off(_TEST_NUM);
        }
    }

    return true;
}

/* // tap hold */
/* void tap16_repeatable(uint16_t keycode) { */
/*     tap_code16(keycode); */
/*     /\* register_key_to_repeat(keycode); *\/ */
/* } */
/* bool tap_hold(uint16_t keycode) { */
/*     switch (keycode) { */
/*     case KC_A ... KC_Z: */
/*         return true; */
/*     default: */
/*         return false; */
/*     } */
/* } */
/* void tap_hold_send_tap(uint16_t keycode) { */
/*     switch (keycode) { */
/*     default: */
/*         tap16_repeatable(keycode); */
/*     } */
/* } */
/* void tap_hold_send_hold(uint16_t keycode) { */
/*     switch (keycode) { */
/*     default: */
/*         tap16_repeatable(S(keycode)); */
/*     } */
/* } */
/* uint16_t tap_hold_timeout(uint16_t keycode) { */
/*     switch (keycode) { */
/*     default: */
/*         return 200; */
/*     } */
/* } */

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_num_word(keycode, record)) {
        return false;
    }
    /* if (!process_tap_hold(keycode, record)) { */
    /*     // Extra register here to allow fast rolls without waiting for tap hold, */
    /*     // (which will also overwrite this). */
    /*     if (record->event.pressed) { */
    /*         /\* register_key_to_repeat(keycode); *\/ */
    /*     } */
    /*     return false; */
    /* } */

    return true;
}

static bool swap_space_e_keys = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* if (!process_achordion(keycode, record)) { return false; } */
  /* qk_tap_dance_action_t *action; */
	 uint8_t mod_state = get_mods();
	 uint8_t oneshot_mod_state = get_oneshot_mods();

     /* bool res = process_num_word(keycode, record); */
     bool res = _process_record_user(keycode, record);

  switch (keycode) {
    /* case TD(COM_MIN): */
    /* case TD(DOT_UND): */
    /* case TD(SLS_EQL): */
    /* case TD(Z_GUI): */
        /* action = &tap_dance_actions[TD_INDEX(keycode)]; */
        /* if (!record->event.pressed && action->state.count && !action->state.finished) { */
        /*     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data; */
        /*     tap_code16(tap_hold->tap); */
        /* } */
        /* break; */
  case DT_EXLM: ;
	   static bool dot_registered = false;
	   if (record->event.pressed) {
			if (mod_state & MOD_MASK_SHIFT || oneshot_mod_state & MOD_MASK_SHIFT) {
				 register_code(KC_1); // shifted 1 is !
				 dot_registered = true;
			} else {
				 register_code(KC_DOT);
				 dot_registered = false;
			}
	   } else {
			if (dot_registered) {
				 unregister_code(KC_1);
				 dot_registered = false;
			} else {
				 unregister_code(KC_DOT);
			}
	   }
	   return false;
	   break;
  case WIN_ALT:
      if (record->event.pressed) {
          register_code(KC_LALT);
          tap_code16(KC_TAB);
          layer_on(_WIN_NAV);
      } else {
          layer_off(_WIN_NAV);
          unregister_code(KC_LALT);
      }
      return false;
      break;
  case TEST:
	   if (record->event.pressed) {
            default_layer_set(1 << _TEST);
	   }
	   return false;
	   break;
  case EX_TEST:
	   default_layer_set(1 << _QWERTY);
	   layer_move(_QWERTY);
	   return false;
	   break;
  case QWERTY:
	   if (record->event.pressed) {
			// print("mode just switched to qwerty and this is a huge string\n");
			// set_single_persistent_default_layer(_QWERTY);
			default_layer_set(1 << _QWERTY);
			// combo_enable();
	   }
	   return false;
	   break;
  /* case COLEMAK: */
  /*      if (record->event.pressed) { */
  /*   		// set_single_persistent_default_layer(_COLEMAK); */
  /*   		default_layer_set(1 << _COLEMAK); */
  /*   		// combo_disable(); */
  /*      } */
  /*      return false; */
  /*      break; */
  case DVORAK:
	   if (record->event.pressed) {
			// set_single_persistent_default_layer(_DVORAK);
			default_layer_set(1 << _DVORAK);
			// combo_disable();
	   }
	   return false;
	   break;
  /* case ONEPDCT: */
  /*      if (record->event.pressed) { */
  /*   		default_layer_set(1 << _ONEPRODUCT); */
  /*   		// combo_disable(); */
  /*      } */
  /*      return false; */
  /*      break; */
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
  case NUMWORD:
      /* static uint16_t num_word_timer; */
      if (record->event.pressed) {
          _num_word_enabled = true;
          layer_on(_TEST_NUM);
          /* num_word_timer = timer_read(); */
      } else {
        /*   if (timer_elapsed(num_word_timer) < TAPPING_TERM) { */
        /*       // Tapping enables NUMWORD */
        /*       _num_word_enabled = true; */
        /*   } else { */
        /*       // Holding turns off NUM when released */
        /*       layer_off(_TEST_NUM); */
        /* } */
      }
      return false;
      break;
  case SWP_S_E:
      if (record->event.pressed) {
          swap_space_e_keys = !swap_space_e_keys;
      }
      return false;
      break;
  case KC_SPC:
      if (swap_space_e_keys) {
          if (record->event.pressed) {
              register_code16(KC_E);
          } else {
              unregister_code16(KC_E);
          }
          return false;
      }
      break;
  case KC_E:
      if (swap_space_e_keys) {
          if (record->event.pressed) {
              register_code16(KC_SPC);
          } else {
              unregister_code16(KC_SPC);
          }
          return false;
      }
      break;
  }
  /* return true; */
  return res;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ENT_NAV:
        return TAPPING_TERM + 100;
    case SPC_MOD:
        return TAPPING_TERM + 100;
    default:
        return TAPPING_TERM;
    }
}

void matrix_scan_user(void) {
    /* tap_hold_matrix_scan(); */
   /* achordion_task(); */
}

/* bool achordion_chord(uint16_t tap_hold_keycode, */
/*                      keyrecord_t* tap_hold_record, */
/*                      uint16_t other_keycode, */
/*                      keyrecord_t* other_record) { */
/*     return achordion_opposite_hands(tap_hold_record, other_record); */
/* } */

/* void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data; */

/*     if (state->pressed) { */
/*         if (state->count == 1 */
/* #ifndef PERMISSIVE_HOLD */
/*             && !state->interrupted */
/* #endif */
/*         ) { */
/*             register_code16(tap_hold->hold); */
/*             tap_hold->held = tap_hold->hold; */
/*         } else { */
/*             register_code16(tap_hold->tap); */
/*             tap_hold->held = tap_hold->tap; */
/*         } */
/*     } */
/* } */

/* void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data; */

/*     if (tap_hold->held) { */
/*         unregister_code16(tap_hold->held); */
/*         tap_hold->held = 0; */
/*     } */
/* } */

/* #define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \ */
/*     { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), } */

/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*     [COM_MIN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMM, KC_MINS), */
/*     [DOT_UND] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_UNDS), */
/*     [SLS_EQL] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLSH, KC_EQL), */
/*     [Z_GUI] = ACTION_TAP_DANCE_TAP_HOLD(KC_Z, KC_LGUI), */
/* }; */
