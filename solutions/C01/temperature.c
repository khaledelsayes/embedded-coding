#include "temperature.h"

/* num / den rounded to nearest, halves away from zero; den > 0 */
static int32_t div_round(int32_t num, int32_t den)
{
    if (num >= 0) {
        return (num + den / 2) / den;
    }
    return -((-num + den / 2) / den);
}

int32_t c10_to_f10(int32_t c10)
{
    return div_round(c10 * 9 + 1600, 5);
}

int32_t f10_to_c10(int32_t f10)
{
    return div_round((f10 - 320) * 5, 9);
}
