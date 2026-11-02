/* C03 p2 - ceiling division and alignment
 *
 * div_ceil_u32: ceil(a / b) for b > 0, WITHOUT overflow for any a.
 *   div_ceil_u32(10, 3) == 4, div_ceil_u32(9, 3) == 3, div_ceil_u32(0, 5) == 0,
 *   div_ceil_u32(4294967295u, 2) == 2147483648u
 *   ("(a + b - 1) / b" is the textbook version. Find the input where it is wrong.)
 *
 * align_down: the largest multiple of m that is <= x.   align_down(1000, 256) == 768
 * align_up:   the smallest multiple of m that is >= x.  align_up(1000, 256) == 1024,
 *   align_up(1024, 256) == 1024.  If that multiple does not fit in uint32_t, return 0
 *   (callers treat 0 as "cannot align").  align_up(4294967295u, 16) == 0
 *   m is any value >= 1 (not only powers of two; e.g. 3 or 100).
 *
 * blocks_needed: how many flash pages of page_size bytes are needed to store len bytes.
 *   blocks_needed(0, 4096) == 0, blocks_needed(1, 4096) == 1, blocks_needed(4097, 4096) == 2
 */
#ifndef ALIGN_H
#define ALIGN_H

#include <stdint.h>

uint32_t div_ceil_u32(uint32_t a, uint32_t b);
uint32_t align_down(uint32_t x, uint32_t m);
uint32_t align_up(uint32_t x, uint32_t m);
uint32_t blocks_needed(uint32_t len, uint32_t page_size);

#endif
