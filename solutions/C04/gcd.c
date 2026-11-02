#include "gcd.h"

uint32_t gcd_u32(uint32_t a, uint32_t b)
{
    while (b != 0) {
        uint32_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}

uint32_t lcm_u32(uint32_t a, uint32_t b)
{
    if (a == 0 || b == 0) {
        return 0;
    }
    uint32_t q = a / gcd_u32(a, b);
    if (q > UINT32_MAX / b) {
        return 0;
    }
    return q * b;
}
