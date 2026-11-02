#include <stdint.h>
#include "check.h"
#include "clamp.h"

int main(void)
{
    CHECK_INT(clamp_i32(5, 0, 10), 5);
    CHECK_INT(clamp_i32(-3, 0, 10), 0);
    CHECK_INT(clamp_i32(99, 0, 10), 10);
    CHECK_INT(clamp_i32(0, 0, 10), 0);            /* exactly on the edges */
    CHECK_INT(clamp_i32(10, 0, 10), 10);
    CHECK_INT(clamp_i32(7, 7, 7), 7);             /* empty-width range */
    CHECK_INT(clamp_i32(-50, -40, -10), -40);     /* all-negative range */
    CHECK_INT(clamp_i32(INT32_MIN, -1, 1), -1);   /* extremes */
    CHECK_INT(clamp_i32(INT32_MAX, -1, 1), 1);
    CHECK_INT(clamp_i32(INT32_MIN, INT32_MIN, INT32_MAX), INT32_MIN);

    CHECK_UINT(clamp_to_u8(-5), 0);
    CHECK_UINT(clamp_to_u8(0), 0);
    CHECK_UINT(clamp_to_u8(128), 128);
    CHECK_UINT(clamp_to_u8(255), 255);
    CHECK_UINT(clamp_to_u8(256), 255);
    CHECK_UINT(clamp_to_u8(300), 255);
    CHECK_UINT(clamp_to_u8(INT32_MAX), 255);
    CHECK_UINT(clamp_to_u8(INT32_MIN), 0);
    return check_summary();
}
