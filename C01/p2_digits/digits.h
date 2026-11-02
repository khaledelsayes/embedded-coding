/* C01 p2 - decimal digits of an unsigned number
 *
 * Write digits.c implementing all three. Use only integer arithmetic (/ and %).
 *
 * digit_count: how many decimal digits n has. 0 has one digit.
 *   digit_count(0) == 1, digit_count(9) == 1, digit_count(10) == 2, digit_count(4294967295u) == 10
 *
 * digit_sum: the sum of the decimal digits.
 *   digit_sum(0) == 0, digit_sum(1234) == 10, digit_sum(4294967295u) == 57
 *
 * digit_at: the digit at position pos, counting from the right; pos 0 is the units digit.
 *   A position beyond the number's length gives 0.
 *   digit_at(1234, 0) == 4, digit_at(1234, 3) == 1, digit_at(1234, 4) == 0, digit_at(7, 30) == 0
 */
#ifndef DIGITS_H
#define DIGITS_H

#include <stdint.h>

unsigned digit_count(uint32_t n);
unsigned digit_sum(uint32_t n);
unsigned digit_at(uint32_t n, unsigned pos);

#endif
