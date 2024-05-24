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

#pragma once

#define COMBO_VARIABLE_LEN
#define COMBO_TERM 35
#define COMBO_STRICT_TIMER

#define TAPPING_TOGGLE 5
#define TAPPING_TERM 125
#define TAPPING_TERM_PER_KEY
#undef QUICK_TAP_TERM
// #define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
/* #define TAP_CODE_DELAY 100 */
#define TAP_CODE_DELAY 0
// #define TAPPING_FORCE_HOLD
// #undef TAPPING_FORCE_HOLD
/* #define IGNORE_MOD_TAP_INTERRUPT */
// #define REPORT_MODS_SEPARATELY

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 5000

#define AUTO_SHIFT_TIMEOUT 300
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC

#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 5000

#define MK_COMBINED
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 4
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_INTERVAL 120
#define MOUSEKEY_WHEEL_MAX_SPEED 5
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
