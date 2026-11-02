#include <stdint.h>
#include "check.h"
#include "digits.h"

int main(void)
{
    CHECK_UINT(digit_count(0), 1);
    CHECK_UINT(digit_count(9), 1);
    CHECK_UINT(digit_count(10), 2);
    CHECK_UINT(digit_count(99), 2);
    CHECK_UINT(digit_count(100), 3);
    CHECK_UINT(digit_count(999999999u), 9);
    CHECK_UINT(digit_count(1000000000u), 10);
    CHECK_UINT(digit_count(4294967295u), 10);

    CHECK_UINT(digit_sum(0), 0);
    CHECK_UINT(digit_sum(7), 7);
    CHECK_UINT(digit_sum(1234), 10);
    CHECK_UINT(digit_sum(1000000000u), 1);
    CHECK_UINT(digit_sum(4294967295u), 57);
    CHECK_UINT(digit_sum(3999999999u), 84);

    CHECK_UINT(digit_at(1234, 0), 4);
    CHECK_UINT(digit_at(1234, 1), 3);
    CHECK_UINT(digit_at(1234, 3), 1);
    CHECK_UINT(digit_at(1234, 4), 0);
    CHECK_UINT(digit_at(0, 0), 0);
    CHECK_UINT(digit_at(7, 30), 0);
    CHECK_UINT(digit_at(4294967295u, 9), 4);
    CHECK_UINT(digit_at(4294967295u, 10), 0);
    return check_summary();
}
