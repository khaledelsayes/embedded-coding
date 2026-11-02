#include "collatz.h"

uint32_t collatz_steps(uint32_t n)
{
    uint64_t x = n;
    uint32_t steps = 0;
    while (x != 1) {
        x = (x % 2 == 0) ? x / 2 : 3 * x + 1;
        steps++;
    }
    return steps;
}

uint32_t collatz_longest_below(uint32_t limit)
{
    uint32_t best = 1;
    uint32_t best_steps = 0;
    for (uint32_t n = 1; n < limit; n++) {
        uint32_t s = collatz_steps(n);
        if (s > best_steps) {
            best = n;
            best_steps = s;
        }
    }
    return best;
}
