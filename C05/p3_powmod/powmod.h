/* C05 p3 - fast exponentiation, recursive and iterative
 *
 * pow_mod_rec:  (base ^ exp) mod m, RECURSIVE, using
 *      x^0 = 1;  x^(2k) = (x^k)^2;  x^(2k+1) = x * x^(2k)
 *   so the recursion depth is about log2(exp) (at most ~64 calls), not exp.
 * pow_mod_iter: the same result with a loop and no recursion (what firmware would use).
 *
 * m >= 1 (with m == 1 every result is 0). Any base and exp. Intermediates: the product of two
 * values below m can reach (2^32 - 1)^2; choose types that hold it.
 *   pow_mod_rec(2, 10, 1000) == 24     pow_mod_iter(3, 0, 7) == 1    pow_mod_iter(5, 3, 1) == 0
 *
 * Also note how many times your recursive version calls itself for exp = 4294967295:
 * write the answer in a comment at the top of powmod.c.
 */
#ifndef POWMOD_H
#define POWMOD_H

#include <stdint.h>

uint32_t pow_mod_rec(uint32_t base, uint32_t exp, uint32_t m);
uint32_t pow_mod_iter(uint32_t base, uint32_t exp, uint32_t m);

#endif
