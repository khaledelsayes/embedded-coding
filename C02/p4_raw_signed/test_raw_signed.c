#include <stdint.h>
#include "check.h"
#include "raw_signed.h"

int main(void)
{
    CHECK_INT(raw_to_signed(0x7FF, 12), 2047);
    CHECK_INT(raw_to_signed(0x800, 12), -2048);
    CHECK_INT(raw_to_signed(0xFFF, 12), -1);
    CHECK_INT(raw_to_signed(0x8000, 16), -32768);
    CHECK_INT(raw_to_signed(1, 1), -1);
    CHECK_INT(raw_to_signed(0, 1), 0);
    CHECK_INT(raw_to_signed(0xFFFFFFFFu, 32), -1);
    CHECK_INT(raw_to_signed(0x80000000u, 32), INT32_MIN);
    CHECK_INT(raw_to_signed(0x7FFFFFFFu, 32), INT32_MAX);
    CHECK_INT(raw_to_signed(0x40000000u, 31), -1073741824);
    CHECK_INT(raw_to_signed(0x3FFFFFFFu, 31), 1073741823);

    for (long v = -2048; v <= 2047; v++) {
        uint32_t raw = (uint32_t)(v < 0 ? v + 4096 : v);
        CHECK_INT(raw_to_signed(raw, 12), v);
        CHECK_UINT(signed_to_raw((int32_t)v, 12), raw);
    }
    for (long v = -32768; v <= 32767; v++) {
        uint32_t raw = (uint32_t)(v < 0 ? v + 65536 : v);
        CHECK_INT(raw_to_signed(raw, 16), v);
        CHECK_UINT(signed_to_raw((int32_t)v, 16), raw);
    }
    CHECK_UINT(signed_to_raw(-1, 1), 1);
    CHECK_UINT(signed_to_raw(-1, 32), 0xFFFFFFFFu);
    CHECK_UINT(signed_to_raw(INT32_MIN, 32), 0x80000000u);
    CHECK_UINT(signed_to_raw(INT32_MAX, 32), 0x7FFFFFFFu);
    CHECK_UINT(signed_to_raw(-8388608, 24), 0x800000u);
    return check_summary();
}
