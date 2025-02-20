/* Copyright 2022 splitkb.com <support@splitkb.com>
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

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

// BEGIN tapping settings

#define COMBO_TERM 30
#define TAPPING_TERM 100
#define DYNAMIC_TAPPING_TERM_INCREMENT 5

// END tapping settings

#ifdef RGB_MATRIX_ENABLE
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_TRANSPORT_MIRROR
#    define SPLIT_LED_STATE_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#    define ENABLE_RGB_SOLID_COLOR
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#endif

#ifdef MOUSEKEY_ENABLE
    #define MK_3_SPEED

    #define MK_C_OFFSET_0   2
    #define MK_C_INTERVAL_0 16
    #define MK_C_OFFSET_1   8
    #define MK_C_INTERVAL_1 16
    #define MK_C_OFFSET_2   64
    #define MK_C_INTERVAL_2 16

    #define MK_W_OFFSET_0   1
    #define MK_W_INTERVAL_0 200
    #define MK_W_OFFSET_1   1
    #define MK_W_INTERVAL_1 120
    #define MK_W_OFFSET_2   1
    #define MK_W_INTERVAL_2 32
#endif

//   #ifdef MOUSEKEY_ENABLE
//       #define MK_KINETIC_SPEED
//       #define MOUSEKEY_BASE_SPEED 2000
//       #define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 1
//       #define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 32
//   #endif
