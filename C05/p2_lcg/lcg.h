/* C05 p2 - a pseudo-random generator with private state
 *
 * A linear congruential generator: state = state * 1664525 + 1013904223, modulo 2^32.
 * (Constants from "Numerical Recipes". Fine for jitter and test data, useless for security.)
 *
 * lcg_seed: set the state.
 * lcg_next: advance the state once and return the NEW state.
 *   After lcg_seed(0): lcg_next() == 1013904223, then 1196435762, then 3519870697.
 *   The initial state before any lcg_seed call is 1.
 * lcg_range: advance once and return lo + (new state % (hi - lo + 1)). lo <= hi.
 *   Must work for lo = 0, hi = UINT32_MAX (where hi - lo + 1 overflows to 0: handle it).
 *
 * The state is a static variable in lcg.c.
 */
#ifndef LCG_H
#define LCG_H

#include <stdint.h>

void lcg_seed(uint32_t seed);
uint32_t lcg_next(void);
uint32_t lcg_range(uint32_t lo, uint32_t hi);

#endif
