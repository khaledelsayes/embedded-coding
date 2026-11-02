#include "percent.h"

uint16_t percent_x10(uint32_t part, uint32_t whole)
{
    if (whole == 0) {
        return 0;
    }
    uint64_t v = ((uint64_t)part * 2000u + whole) / (2u * (uint64_t)whole);
    return v > 65535u ? 65535u : (uint16_t)v;
}

uint8_t battery_percent(uint16_t mv, uint16_t empty_mv, uint16_t full_mv)
{
    if (mv <= empty_mv) {
        return 0;
    }
    if (mv >= full_mv) {
        return 100;
    }
    return (uint8_t)((uint32_t)(mv - empty_mv) * 100u / (uint32_t)(full_mv - empty_mv));
}
