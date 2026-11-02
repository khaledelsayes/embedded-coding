#include "prime.h"

int is_prime_u32(uint32_t n)
{
    if (n < 2) {
        return 0;
    }
    if (n % 2 == 0) {
        return n == 2;
    }
    for (uint32_t i = 3; i <= n / i; i += 2) {     /* i <= n / i cannot overflow */
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

uint32_t next_prime_u32(uint32_t n)
{
    for (;;) {
        if (is_prime_u32(n)) {
            return n;
        }
        if (n == UINT32_MAX) {
            return 0;
        }
        n++;
    }
}
