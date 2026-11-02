/* C01 p1 - clamp
 *
 * Write clamp.c next to this file, implementing both functions.
 *
 * clamp_i32: return v limited to the range [lo, hi].
 *   v < lo  -> lo,   v > hi -> hi,   otherwise v.
 *   Precondition: lo <= hi (you do not have to handle lo > hi).
 *   clamp_i32(5, 0, 10) == 5,  clamp_i32(-3, 0, 10) == 0,  clamp_i32(99, 0, 10) == 10
 *
 * clamp_to_u8: convert any int32_t to a uint8_t by clamping to 0..255
 *   (the way you would turn a computed PWM duty into a register value).
 *   clamp_to_u8(-5) == 0,  clamp_to_u8(300) == 255,  clamp_to_u8(128) == 128
 */
#ifndef CLAMP_H
#define CLAMP_H

#include <stdint.h>

int32_t clamp_i32(int32_t v, int32_t lo, int32_t hi);
uint8_t clamp_to_u8(int32_t v);

#endif
