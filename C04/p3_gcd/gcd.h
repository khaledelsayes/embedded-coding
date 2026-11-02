/* C04 p3 - greatest common divisor and least common multiple
 *
 * gcd_u32: greatest common divisor, Euclid's algorithm (iterative). gcd(0, 0) == 0,
 *   gcd(a, 0) == a.   gcd_u32(48, 18) == 6
 *
 * lcm_u32: least common multiple. 0 if either input is 0, and 0 if the result does not fit
 *   in uint32_t.   lcm_u32(4, 6) == 12,  lcm_u32(65536, 65537) == 0
 *   Compute it so the intermediate cannot overflow (hint: divide before you multiply).
 *
 * Use case: the period after which two periodic tasks (every 40 ms and every 60 ms) line up
 * again is their LCM (120 ms); a sample-rate converter reduces 48000/44100 by their GCD.
 */
#ifndef GCD_H
#define GCD_H

#include <stdint.h>

uint32_t gcd_u32(uint32_t a, uint32_t b);
uint32_t lcm_u32(uint32_t a, uint32_t b);

#endif
