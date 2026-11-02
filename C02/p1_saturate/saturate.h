/* C02 p1 - saturating arithmetic
 *
 * DSP code and control loops prefer "stick at the limit" to "wrap around": a PWM duty
 * that overflows from 255 to 4 is a motor that jumps from full power to off.
 *
 * Return the mathematically correct result, clamped to the range of the return type.
 *   sat_add_u8(200, 100) == 255     sat_sub_u8(10, 20) == 0
 *   sat_add_i16(30000, 10000) == 32767     sat_sub_i16(-30000, 10000) == -32768
 *
 * Rule for this problem: do it WITHOUT computing in a wider type for the i16 versions
 * (no int32_t/int arithmetic on the sum): decide whether it would overflow first.
 * (The u8 versions may use int; C promotes them anyway. Ask yourself why that is safe.)
 */
#ifndef SATURATE_H
#define SATURATE_H

#include <stdint.h>

uint8_t sat_add_u8(uint8_t a, uint8_t b);
uint8_t sat_sub_u8(uint8_t a, uint8_t b);
int16_t sat_add_i16(int16_t a, int16_t b);
int16_t sat_sub_i16(int16_t a, int16_t b);

#endif
