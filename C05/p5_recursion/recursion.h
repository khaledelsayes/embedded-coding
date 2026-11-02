/* C05 p5 - recursion that is worth writing
 *
 * count_change: the number of different ways to pay `amount` piastres with coins of
 *   1, 5, 10, 25 and 50 (unlimited supply; order does not matter, so 5+1 and 1+5 are one way).
 *   amount 0 -> 1 way (pay nothing); negative -> 0 ways. Tests use amounts up to 500.
 *   count_change(10) == 4    (10 / 5+5 / 5+1x5 / 1x10)
 *   Write it RECURSIVELY with a helper  ways(amount, number_of_coin_kinds_allowed):
 *     ways(a, k) = ways(a, k - 1) + ways(a - largest_allowed_coin, k)
 *   with the coin values in a switch. (Tomorrow's week-2 arrays would make it shorter.)
 *
 * reverse_digits: 1234 -> 4321, 1200 -> 21, 0 -> 0. Input < 1000000000 (so the result fits).
 *   Write it RECURSIVELY with an accumulator: helper(n, acc) returns acc when n == 0.
 *
 * is_digit_palindrome: 1 if n reads the same reversed (0, 7, 121, 1221), else 0.
 *   Input < 1000000000.
 */
#ifndef RECURSION_H
#define RECURSION_H

#include <stdint.h>

uint32_t count_change(int amount);
uint32_t reverse_digits(uint32_t n);
int is_digit_palindrome(uint32_t n);

#endif
