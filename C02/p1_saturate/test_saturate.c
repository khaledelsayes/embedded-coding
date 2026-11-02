#include <stdint.h>
#include "check.h"
#include "saturate.h"

static long clampl(long v, long lo, long hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

int main(void)
{
    /* every pair of 8-bit values */
    for (long a = 0; a <= 255; a++) {
        for (long b = 0; b <= 255; b++) {
            CHECK_UINT(sat_add_u8((uint8_t)a, (uint8_t)b), clampl(a + b, 0, 255));
            CHECK_UINT(sat_sub_u8((uint8_t)a, (uint8_t)b), clampl(a - b, 0, 255));
        }
    }
    /* every 16-bit a against a set of b values that includes the edges */
    static const long bs[] = {-32768, -32767, -30000, -256, -2, -1, 0, 1, 2, 255, 30000, 32766, 32767};
    for (long a = -32768; a <= 32767; a++) {
        for (unsigned i = 0; i < sizeof(bs) / sizeof(bs[0]); i++) {
            long b = bs[i];
            CHECK_INT(sat_add_i16((int16_t)a, (int16_t)b), clampl(a + b, -32768, 32767));
            CHECK_INT(sat_sub_i16((int16_t)a, (int16_t)b), clampl(a - b, -32768, 32767));
        }
    }
    return check_summary();
}
