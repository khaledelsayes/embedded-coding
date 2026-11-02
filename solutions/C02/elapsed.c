#include "elapsed.h"

uint32_t elapsed_ms(uint32_t now, uint32_t start)
{
    return now - start;
}

int timeout_expired(uint32_t now, uint32_t start, uint32_t timeout)
{
    return elapsed_ms(now, start) >= timeout;
}

int32_t time_diff(uint32_t a, uint32_t b)
{
    uint32_t d = a - b;
    if (d <= (uint32_t)INT32_MAX) {
        return (int32_t)d;
    }
    /* d is in (2^31, 2^32): the true value is d - 2^32 */
    return -(int32_t)(UINT32_MAX - d) - 1;
}
