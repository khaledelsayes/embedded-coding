/* exp = 4294967295 (all 32 bits set): one call per bit for the odd step plus one per halving,
   about 64 calls in total. */
#include "powmod.h"

static uint32_t mulmod(uint32_t a, uint32_t b, uint32_t m)
{
    return (uint32_t)((uint64_t)a * b % m);
}

uint32_t pow_mod_rec(uint32_t base, uint32_t exp, uint32_t m)
{
    if (exp == 0) {
        return 1u % m;
    }
    if (exp % 2 == 0) {
        uint32_t half = pow_mod_rec(base, exp / 2, m);
        return mulmod(half, half, m);
    }
    return mulmod(base % m, pow_mod_rec(base, exp - 1, m), m);
}

uint32_t pow_mod_iter(uint32_t base, uint32_t exp, uint32_t m)
{
    uint32_t result = 1u % m;
    uint32_t b = base % m;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = mulmod(result, b, m);
        }
        b = mulmod(b, b, m);
        exp /= 2;
    }
    return result;
}
