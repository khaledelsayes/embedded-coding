/* C02 p5 - absolute differences and averages without overflow
 *
 * abs_diff_u32: |a - b| for unsigned values.   abs_diff_u32(3, 10) == 7
 *
 * abs_i32_u32: |v| as an unsigned number. Must work for INT32_MIN, whose absolute value
 *   (2147483648) does not fit in int32_t, so "-v" is undefined behaviour there.
 *   abs_i32_u32(-5) == 5     abs_i32_u32(INT32_MIN) == 2147483648u
 *
 * avg_u32: floor((a + b) / 2) without overflow and WITHOUT a 64-bit type.
 *   avg_u32(4294967295u, 4294967293u) == 4294967294u     avg_u32(1, 2) == 1
 *   (This is the bug that hid in binary search implementations for decades:
 *    mid = (lo + hi) / 2 overflows.)
 *
 * avg_i32: (a + b) / 2 rounded toward zero (the way C's / rounds), without overflow.
 *   You MAY use int64_t here. avg_i32(-3, 0) == -1    avg_i32(INT32_MAX, INT32_MAX) == INT32_MAX
 */
#ifndef AVERAGE_H
#define AVERAGE_H

#include <stdint.h>

uint32_t abs_diff_u32(uint32_t a, uint32_t b);
uint32_t abs_i32_u32(int32_t v);
uint32_t avg_u32(uint32_t a, uint32_t b);
int32_t avg_i32(int32_t a, int32_t b);

#endif
