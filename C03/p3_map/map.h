/* C03 p3 - linear mapping between ranges (Arduino's map(), done properly)
 *
 * map_range: map x from [in_min, in_max] to [out_min, out_max] linearly:
 *     out_min + (x - in_min) * (out_max - out_min) / (in_max - in_min)
 *   with the division truncating toward zero, exactly like that formula in exact arithmetic.
 *   x may lie OUTSIDE the input range (then the result extrapolates; no clamping).
 *   Ranges may be reversed (in_min > in_max or out_min > out_max).
 *   in_min != in_max. All inputs are within -1000000 .. 1000000, and the tests only use
 *   inputs whose exact result fits in int32_t.
 *   map_range(512, 0, 1023, 0, 255) == 127     map_range(0, 0, 1023, 255, 0) == 255
 *   map_range(-5, 0, 10, 0, 100) == -50
 *   The intermediate product can reach about 4e12: choose your types.
 *
 * map_clamped: same, but the result is clamped into the output range (either order).
 *   map_clamped(2000, 0, 1023, 0, 255) == 255     map_clamped(-5, 0, 10, 100, 0) == 100
 */
#ifndef MAP_H
#define MAP_H

#include <stdint.h>

int32_t map_range(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
int32_t map_clamped(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);

#endif
