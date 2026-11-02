/* C04 p5 - the Collatz sequence, and an overflow that hides in it
 *
 * From n: if n is even, n = n / 2; if odd, n = 3n + 1; repeat until n == 1.
 *
 * collatz_steps: how many steps from n to 1. n >= 1. collatz_steps(1) == 0, collatz_steps(6) == 8
 *   n is a uint32_t, but the sequence can climb above 2^32 even for small starting values
 *   (n = 159487 is one of them). Pick the type of your working variable accordingly.
 *   Inputs in the tests are below 10 000 000.
 *
 * collatz_longest_below: the n in 1 .. limit-1 with the most steps; on a tie, the smallest n.
 *   limit >= 2.  collatz_longest_below(10) == 9   (19 steps)
 *   The test calls it with limit = 1000000: keep your loop simple and tight.
 */
#ifndef COLLATZ_H
#define COLLATZ_H

#include <stdint.h>

uint32_t collatz_steps(uint32_t n);
uint32_t collatz_longest_below(uint32_t limit);

#endif
