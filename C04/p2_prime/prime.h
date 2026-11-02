/* C04 p2 - primes over the whole uint32_t range
 *
 * is_prime_u32: 1 if n is prime, else 0. Correct for EVERY uint32_t (0 and 1 are not prime).
 *   Trial division up to sqrt(n) is fine. The classic loop "for (i = 2; i * i <= n; i++)"
 *   has an overflow bug for n near 2^32: find it and avoid it.
 *   is_prime_u32(4294967291u) == 1  (the largest 32-bit prime)
 *
 * next_prime_u32: the smallest prime >= n, or 0 if there is none that fits in uint32_t.
 *   next_prime_u32(0) == 2, next_prime_u32(14) == 17, next_prime_u32(4294967292u) == 0
 */
#ifndef PRIME_H
#define PRIME_H

#include <stdint.h>

int is_prime_u32(uint32_t n);
uint32_t next_prime_u32(uint32_t n);

#endif
