#include "map.h"

int32_t map_range(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
    int64_t num = ((int64_t)x - in_min) * ((int64_t)out_max - out_min);
    int64_t den = (int64_t)in_max - in_min;
    return (int32_t)(out_min + num / den);
}

int32_t map_clamped(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
    int32_t v = map_range(x, in_min, in_max, out_min, out_max);
    int32_t lo = out_min < out_max ? out_min : out_max;
    int32_t hi = out_min < out_max ? out_max : out_min;
    if (v < lo) {
        return lo;
    }
    if (v > hi) {
        return hi;
    }
    return v;
}
