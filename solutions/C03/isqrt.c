#include "isqrt.h"

uint32_t isqrt_u32(uint32_t n)
{
    uint32_t lo = 0;
    uint32_t hi = 65535;
    while (lo < hi) {
        uint32_t mid = lo + (hi - lo + 1) / 2;     /* upper middle: avoids an endless loop */
        if (mid * mid <= n) {                       /* mid <= 65535, so mid*mid fits */
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int is_square_u32(uint32_t n)
{
    uint32_t r = isqrt_u32(n);
    return r * r == n;
}

unsigned ilog10_u32(uint32_t n)
{
    unsigned k = 0;
    while (n >= 10) {
        n /= 10;
        k++;
    }
    return k;
}
