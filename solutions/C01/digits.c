#include "digits.h"

unsigned digit_count(uint32_t n)
{
    unsigned count = 1;
    while (n >= 10) {
        n /= 10;
        count++;
    }
    return count;
}

unsigned digit_sum(uint32_t n)
{
    unsigned sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

unsigned digit_at(uint32_t n, unsigned pos)
{
    for (unsigned i = 0; i < pos; i++) {
        if (n == 0) {
            return 0;
        }
        n /= 10;
    }
    return n % 10;
}
