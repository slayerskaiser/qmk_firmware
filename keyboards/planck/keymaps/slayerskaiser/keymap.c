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
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  /* COLEMAK, */
  DVORAK,
  /* ONEPDCT, */
  TEST,
  TEST_FN,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  EX_TEST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOVE MO(_MOVEMENT)
#define C_ESC LCTL_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENTER)

/* test layout config */
/* #define SPC_MOD LT(_TEST_MOD, KC_SPC) */
#define SPC_MOD LT(0, KC_SPC)
#define BSP_MOD LT(_TEST_MOD, KC_BSPC)
#define LSFT_OS OSM(MOD_LSFT)
#define RSFT_OS OSM(MOD_RSFT)
/* #define ENT_NAV LT(_TEST_NAV, KC_ENT) */
#define ENT_NAV LT(0, KC_ENT)
/* #define SFT_BSP LSFT_T(KC_BSPC) */
/* #define SFT_QUO RSFT_T(KC_QUOT) */
/* #define ALT_Z LALT_T(KC_Z) */
/* #define ALT_SSH RALT_T(KC_SLSH) */
/* #define CTL_TAB LCTL_T(KC_TAB) */
#define SFT_BSP LT(0, KC_BSPC)
#define SFT_QUO LT(0, KC_QUOT)
/* #define ALT_Z LT(0, KC_Z) */
/* #define ALT_SSH LT(0, KC_SLSH) */
#define CTL_TAB LT(0, KC_TAB)
#define ESC_EQL LT(0, KC_EQL)
#define GUI_Z LT(0, KC_Z)
#define ALT_X LT(0, KC_X)
#define CTL_C LT(0, KC_C)
#define GUI_SSH LT(0, KC_SLSH)
#define ALT_DOT LT(0, KC_DOT)
#define CTL_COM LT(0, KC_COMM)

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

/* #include "g/keymap_combo.h" */

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
 * | TEST |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |Brght-|Brght+|      |
 * `-----------------------------------------------------------------------------------'
 */
/* TEST,    _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  PLOVER,  ONEPDCT, */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    TEST,    _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  XXXXXXX,  DVORAK,  PLOVER,  XXXXXXX,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
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

[_TEST] = LAYOUT_planck_grid(
	/* KC_TAB,  KC_J,    KC_C,    KC_Y,    KC_F,    KC_K,    KC_Z,    KC_L,    KC_COMM, KC_U,    KC_Q,    KC_EQL , */
	/* KC_ESC,  KC_R,    KC_S,    KC_T,    KC_H,    KC_P,    KC_M,    KC_N,    KC_A,    KC_I,    KC_O,    KC_QUOT, */
	/* T_SHIFT, KC_SLSH, KC_V,    KC_G,    KC_D,    KC_B,    KC_X,    KC_W,    DT_EXLM, KC_SCLN, KC_MINS, T_RSHFT, */
    /* EX_TEST, XXXXXXX, T_NUM,   ENT_NAV, KC_SPC,  XXXXXXX, XXXXXXX, KC_E,    BSP_MOD, T_FUN,   XXXXXXX, XXXXXXX */
    ESC_EQL, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LSFT_OS, GUI_Z,   ALT_X,   CTL_C,   KC_V,    KC_B,    KC_N,    KC_M,    CTL_COM, ALT_DOT, GUI_SSH, RSFT_OS,
    /* SFT_BSP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, SFT_QUO, */
    /* KC_LGUI, ALT_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ALT_SSH, KC_RCTL, */
    /* EX_TEST, XXXXXXX, XXXXXXX, ENT_NAV, CTL_TAB, XXXXXXX, BSP_MOD, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
    EX_TEST, XXXXXXX, XXXXXXX, ENT_NAV, CTL_TAB, XXXXXXX, SFT_BSP, SPC_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    /* EX_TEST, XXXXXXX, XXXXXXX, XXXXXXX, SFT_OSM, CTL_TAB, CTL_TAB, SPC_MOD, ENT_NAV, XXXXXXX, XXXXXXX, XXXXXXX */
),

[_TEST_MOD] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX,
    KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
),

[_TEST_NAV] = LAYOUT_planck_grid(
    /* KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, KC_7,    KC_8,    KC_9, KC_GRV,  KC_BSLS, */
    /* KC_LSFT, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, KC_4,    KC_5,    KC_6, KC_DEL,  KC_BSPC, */
    /* _______, KC_LALT, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX, KC_1,    KC_2,    KC_3, KC_DOT,  KC_ENT, */
    KC_ESC,  KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_CIRC, XXXXXXX, KC_7,    KC_8,    KC_9, KC_GRV,  KC_BSLS,
    KC_LCTL, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_AMPR, XXXXXXX, KC_4,    KC_5,    KC_6, KC_DEL,  KC_BSPC,
    KC_LALT, KC_LGUI, KC_PERC, KC_LCBR, KC_RCBR, KC_ASTR, XXXXXXX, KC_1,    KC_2,    KC_3, KC_DOT,  KC_ENT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TEST_FN, XXXXXXX, KC_BSPC, KC_0,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    /* XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TEST_FN, XXXXXXX, XXXXXXX, KC_0,    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX */
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  // return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWER, _MOVEMENT, _NUMPAD);
  /* state = update_tri_layer_state(state, _TEST_NUM, _TEST_MOUSE, _TEST_FUN); */
  return state;
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
    /* if (!process_num_word(keycode, record)) { */
    /*     return false; */
    /* } */
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* if (!process_achordion(keycode, record)) { return false; } */
  /* qk_tap_dance_action_t *action; */
	 /* uint8_t mod_state = get_mods(); */
	 /* uint8_t oneshot_mod_state = get_oneshot_mods(); */

     /* bool res = process_num_word(keycode, record); */
     bool res = _process_record_user(keycode, record);

     static bool test_fn_is_held = false;
     static uint8_t num_to_fn_keycode = KC_F1 - KC_1;

  switch (keycode) {
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
  case ESC_EQL:
      if (!record->tap.count && record->event.pressed) {
          tap_code(KC_ESC);
          return false;
      }
      return true;
      break;
  case ENT_NAV:
      if (!record->tap.count) {
          if (record->event.pressed) {
              layer_on(_TEST_NAV);
          } else {
              layer_off(_TEST_NAV);
          }
          return false;
      }
      return true;
      break;
  case SPC_MOD:
      if (!record->tap.count) {
          if (record->event.pressed) {
              layer_on(_TEST_MOD);
          } else {
              layer_off(_TEST_MOD);
          }
          return false;
      }
      return true;
      break;
  case SFT_BSP:
      if (!record->tap.count) {
          if (record->event.pressed) {
              register_code(KC_LSFT);
          } else {
              unregister_code(KC_LSFT);
          }
          return false;
      }
      return true;
      break;
  case SFT_QUO:
      if (!record->tap.count) {
          if (record->event.pressed) {
              register_code(KC_RSFT);
          } else {
              unregister_code(KC_RSFT);
          }
          return false;
      }
      return true;
      break;
  case GUI_Z:
      if (!record->tap.count) {
          if (record->event.pressed) {
              register_code(KC_LGUI);
          } else {
              unregister_code(KC_LGUI);
          }
          return false;
      }
      return true;
      break;
  case ALT_X:
      if (!record->tap.count) {
          if (record->event.pressed) {
              register_code(KC_LALT);
          } else {
              unregister_code(KC_LALT);
          }
          return false;
      }
      return true;
      break;
  case CTL_C:
      if (!record->tap.count) {
          if (record->event.pressed) {
              register_code(KC_LCTL);
          } else {
              unregister_code(KC_LCTL);
          }
          return false;
      }
      return true;
      break;
  case GUI_SSH:
      if (!record->tap.count) {
          if (record->event.pressed) {
              register_code(KC_RGUI);
          } else {
              unregister_code(KC_RGUI);
          }
          return false;
      }
      return true;
      break;
  case ALT_DOT:
      if (!record->tap.count) {
          if (record->event.pressed) {
              register_code(KC_RALT);
          } else {
              unregister_code(KC_RALT);
          }
          return false;
      }
      return true;
      break;
  case CTL_COM:
      if (!record->tap.count) {
          if (record->event.pressed) {
              register_code(KC_RCTL);
          } else {
              unregister_code(KC_RCTL);
          }
          return false;
      }
      return true;
      break;
  case CTL_TAB:
      if (!record->tap.count) {
          if (record->event.pressed) {
              register_code(KC_LCTL);
          } else {
              unregister_code(KC_LCTL);
          }
          return false;
      }
      return true;
      break;
  case TEST_FN:
      test_fn_is_held = record->event.pressed;
      return false;
      break;
  case KC_1 ... KC_0:
      {
          static uint16_t registered_key = KC_NO;
          if (record->event.pressed) {
              registered_key = (test_fn_is_held) ? keycode + num_to_fn_keycode : keycode;
              register_code(registered_key);
          } else {
              unregister_code(registered_key);
          }
      }
      return false;
      break;
  case KC_GRV:
      {
          static uint16_t registered_key = KC_NO;
          if (record->event.pressed) {
              registered_key = (test_fn_is_held) ? KC_F11 : keycode;
              register_code(registered_key);
          } else {
              unregister_code(registered_key);
          }
      }
      return false;
      break;
  case KC_BSLS:
      {
          static uint16_t registered_key = KC_NO;
          if (record->event.pressed) {
              registered_key = (test_fn_is_held) ? KC_F12 : keycode;
              register_code(registered_key);
          } else {
              unregister_code(registered_key);
          }
      }
      return false;
      break;
  }
  /* return true; */
  return res;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ENT_NAV:
    case CTL_TAB:
    case BSP_MOD:
        return TAPPING_TERM + 100;
    case SPC_MOD:
        return TAPPING_TERM + 200;
    case SFT_BSP:
    case SFT_QUO:
    case GUI_Z:
    case ALT_X:
    case CTL_C:
    case GUI_SSH:
    case ALT_DOT:
    case CTL_COM:
        return TAPPING_TERM + 200;
    case ESC_EQL:
        return TAPPING_TERM + 100;
    default:
        return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    /* case SFT_BSP: */
    /* case SFT_QUO: */
    /* case ALT_Z: */
    /* case ALT_SSH: */
    /*     // Immediately select the hold action when another key is tapped. */
    /*     return true; */
    default:
        // Do not select the hold action when another key is tapped.
        return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    /* case SFT_BSP: */
    /* case SFT_QUO: */
    /*     // Immediately select the hold action when another key is pressed. */
    /*     return true; */
    default:
        // Do not select the hold action when another key is pressed.
        return false;
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
