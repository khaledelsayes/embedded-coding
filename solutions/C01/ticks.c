#include "ticks.h"

uint32_t ms_to_ticks(uint32_t ms, uint32_t tick_hz)
{
    uint64_t t = ((uint64_t)ms * tick_hz + 999u) / 1000u;
    return t > UINT32_MAX ? UINT32_MAX : (uint32_t)t;
}

uint32_t ticks_to_ms(uint32_t ticks, uint32_t tick_hz)
{
    uint64_t ms = (uint64_t)ticks * 1000u / tick_hz;
    return ms > UINT32_MAX ? UINT32_MAX : (uint32_t)ms;
}
