#include "align.h"

uint32_t div_ceil_u32(uint32_t a, uint32_t b)
{
    return a / b + (a % b != 0);
}

uint32_t align_down(uint32_t x, uint32_t m)
{
    return x - x % m;
}

uint32_t align_up(uint32_t x, uint32_t m)
{
    uint32_t r = x % m;
    if (r == 0) {
        return x;
    }
    uint32_t add = m - r;
    if (x > UINT32_MAX - add) {
        return 0;
    }
    return x + add;
}

uint32_t blocks_needed(uint32_t len, uint32_t page_size)
{
    return div_ceil_u32(len, page_size);
}
