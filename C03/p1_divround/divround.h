/* C03 p1 - the three ways to divide integers
 *
 * C's / truncates toward zero: -7 / 2 == -3, and -7 % 2 == -1.
 * Firmware often needs the other two roundings.
 *
 * div_round: num / den rounded to NEAREST, exact halves AWAY from zero.
 *   div_round(7, 2) == 4,  div_round(-7, 2) == -4,  div_round(5, 3) == 2,  div_round(-5, 3) == -2
 *
 * div_floor: num / den rounded toward MINUS INFINITY (Python's //).
 *   div_floor(-7, 2) == -4,  div_floor(7, -2) == -4,  div_floor(-6, 2) == -3
 *
 * mod_floor: the remainder that goes with div_floor; it has the sign of den (Python's %).
 *   mod_floor(-7, 2) == 1,  mod_floor(7, -2) == -1.  Always num == div_floor*den + mod_floor.
 *   Use: wrapping an index or an angle into 0..n-1 even when it went negative.
 *
 * den is never 0. num and den are never INT32_MIN (so no overflow in -num or in the quotient).
 * You may use int64_t if you need it, but you should not need it.
 */
#ifndef DIVROUND_H
#define DIVROUND_H

#include <stdint.h>

int32_t div_round(int32_t num, int32_t den);
int32_t div_floor(int32_t num, int32_t den);
int32_t mod_floor(int32_t num, int32_t den);

#endif
