/* C03 p5 - integer square root and logarithm, no floating point
 *
 * isqrt_u32: floor(sqrt(n)) for any uint32_t n.
 *   isqrt_u32(0) == 0, isqrt_u32(15) == 3, isqrt_u32(16) == 4, isqrt_u32(4294967295u) == 65535
 *   Must be fast: the test calls it about 200 000 times. A loop of up to 65536 steps per call
 *   is too slow; use binary search or Newton's method. Watch for overflow in mid * mid.
 *
 * is_square_u32: 1 if n is a perfect square, else 0.
 *
 * ilog10_u32: floor(log10(n)) for n >= 1.  ilog10_u32(1) == 0, ilog10_u32(999) == 2,
 *   ilog10_u32(1000) == 3, ilog10_u32(4294967295u) == 9
 *
 * Use case: RMS of a signal = isqrt(mean of squares), computed on a chip with no FPU.
 */
#ifndef ISQRT_H
#define ISQRT_H

#include <stdint.h>

uint32_t isqrt_u32(uint32_t n);
int is_square_u32(uint32_t n);
unsigned ilog10_u32(uint32_t n);

#endif
