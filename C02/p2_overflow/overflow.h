/* C02 p2 - detect signed overflow BEFORE it happens
 *
 * Signed overflow is undefined behaviour in C: the compiler may assume it never happens,
 * so "compute it and check the result" is not allowed. Check the operands instead.
 *
 * Return 1 if a + b (or a * b) would not fit in int32_t, else 0.
 * Rule: no int64_t, no long long, no compiler builtins. Only int32_t comparisons and
 * operations that themselves cannot overflow. The tests run under -fsanitize=undefined,
 * which aborts the moment your check itself overflows.
 *
 *   add_overflows_i32(INT32_MAX, 1) == 1      add_overflows_i32(INT32_MAX, -1) == 0
 *   mul_overflows_i32(46341, 46341) == 1      mul_overflows_i32(46340, 46340) == 0
 *   mul_overflows_i32(-1, INT32_MIN) == 1     mul_overflows_i32(INT32_MIN, 1) == 0
 */
#ifndef OVERFLOW_H
#define OVERFLOW_H

#include <stdint.h>

int add_overflows_i32(int32_t a, int32_t b);
int sub_overflows_i32(int32_t a, int32_t b);
int mul_overflows_i32(int32_t a, int32_t b);

#endif
