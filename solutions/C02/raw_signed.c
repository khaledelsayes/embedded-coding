#include "raw_signed.h"

int32_t raw_to_signed(uint32_t raw, unsigned bits)
{
    int64_t range = 1;
    for (unsigned i = 0; i < bits; i++) {
        range *= 2;
    }
    if ((int64_t)raw >= range / 2) {
        return (int32_t)((int64_t)raw - range);
    }
    return (int32_t)raw;
}

uint32_t signed_to_raw(int32_t v, unsigned bits)
{
    int64_t range = 1;
    for (unsigned i = 0; i < bits; i++) {
        range *= 2;
    }
    return (uint32_t)(v < 0 ? (int64_t)v + range : (int64_t)v);
}
