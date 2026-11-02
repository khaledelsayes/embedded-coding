#include "lcg.h"

static uint32_t state = 1;

void lcg_seed(uint32_t seed)
{
    state = seed;
}

uint32_t lcg_next(void)
{
    state = state * 1664525u + 1013904223u;
    return state;
}

uint32_t lcg_range(uint32_t lo, uint32_t hi)
{
    uint32_t v = lcg_next();
    uint32_t span = hi - lo + 1u;       /* 0 means the full 2^32 range */
    if (span == 0) {
        return v;
    }
    return lo + v % span;
}
