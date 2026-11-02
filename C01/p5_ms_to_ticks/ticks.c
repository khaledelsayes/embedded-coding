#include "ticks.h"
#include <stdint.h>

uint32_t ms_to_ticks(uint32_t ms, uint32_t tick_hz)
{
    uint64_t product = (uint64_t)ms * tick_hz;
    uint64_t result = (product + 999) / 1000; /* round up */
    if (result > UINT32_MAX) {
        return UINT32_MAX;
    }
    return (uint32_t)result;
}

uint32_t ticks_to_ms(uint32_t ticks, uint32_t tick_hz)
{
    if (tick_hz == 0) {
        return UINT32_MAX; /* avoid division by zero */
    }
    uint64_t product = (uint64_t)ticks * 1000;
    uint64_t result = product / tick_hz; /* rounds down */
    if (result > UINT32_MAX) {
        return UINT32_MAX;
    }
    return (uint32_t)result;
}
