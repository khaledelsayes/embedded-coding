#include "average.h"

uint32_t abs_diff_u32(uint32_t a, uint32_t b)
{
    return a > b ? a - b : b - a;
}

uint32_t abs_i32_u32(int32_t v)
{
    if (v >= 0) {
        return (uint32_t)v;
    }
    return 0u - (uint32_t)v;     /* (uint32_t)v is well defined: v + 2^32 */
}

uint32_t avg_u32(uint32_t a, uint32_t b)
{
    return a / 2 + b / 2 + (a % 2 + b % 2) / 2;
}

int32_t avg_i32(int32_t a, int32_t b)
{
    return (int32_t)(((int64_t)a + b) / 2);
}
