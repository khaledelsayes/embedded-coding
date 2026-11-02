#include "temperature.h"
#include <stdint.h>

/* n / d rounded to the nearest integer, exact halves away from zero (d > 0). */
static int32_t div_round(int32_t n, int32_t d)
{
    if (n >= 0) {
        return (n + d / 2) / d;
    }
    return (n - d / 2) / d;
}

int32_t c10_to_f10(int32_t c10)
{
    /* F = C * 9 / 5 + 32; the 32 is 320 in tenths, added after rounding */
    return div_round(c10 * 9, 5) + 320;
}

int32_t f10_to_c10(int32_t f10)
{
    /* C = (F - 32) * 5 / 9 */
    return div_round((f10 - 320) * 5, 9);
}
