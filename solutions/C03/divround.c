#include "divround.h"

int32_t div_round(int32_t num, int32_t den)
{
    int32_t q = num / den;
    int32_t r = num % den;           /* same sign as num */
    int32_t ar = r < 0 ? -r : r;
    int32_t ad = den < 0 ? -den : den;
    /* round away from zero if 2*|r| >= |den|, written without overflow */
    if (ar >= ad - ar) {
        q += ((num < 0) == (den < 0)) ? 1 : -1;
    }
    return q;
}

int32_t div_floor(int32_t num, int32_t den)
{
    int32_t q = num / den;
    if (num % den != 0 && ((num < 0) != (den < 0))) {
        q--;
    }
    return q;
}

int32_t mod_floor(int32_t num, int32_t den)
{
    int32_t r = num % den;
    if (r != 0 && ((r < 0) != (den < 0))) {
        r += den;
    }
    return r;
}
