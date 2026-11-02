#include <stdint.h>
#include "check.h"
#include "isqrt.h"

int main(void)
{
    CHECK_UINT(isqrt_u32(0), 0);
    CHECK_UINT(isqrt_u32(1), 1);
    CHECK_UINT(isqrt_u32(15), 3);
    CHECK_UINT(isqrt_u32(16), 4);
    CHECK_UINT(isqrt_u32(4294967295u), 65535);
    CHECK_UINT(isqrt_u32(4294836225u), 65535);    /* 65535^2 */
    CHECK_UINT(isqrt_u32(4294836224u), 65534);

    /* around every perfect square r*r: r*r - 1, r*r, r*r + 1 */
    for (uint32_t r = 1; r <= 65535; r++) {
        uint32_t sq = r * r;
        CHECK_UINT(isqrt_u32(sq), r);
        CHECK_UINT(isqrt_u32(sq - 1), r - 1);
        if (r < 65535) {
            CHECK_UINT(isqrt_u32(sq + 1), r);
        }
        CHECK_INT(is_square_u32(sq), 1);
        if (r > 1) {
            CHECK_INT(is_square_u32(sq - 1), 0);
        }
    }
    CHECK_INT(is_square_u32(0), 1);
    CHECK_INT(is_square_u32(2), 0);
    CHECK_INT(is_square_u32(4294967295u), 0);

    uint32_t p = 1;
    for (unsigned k = 0; k <= 9; k++) {
        CHECK_UINT(ilog10_u32(p), k);
        if (p > 1) {
            CHECK_UINT(ilog10_u32(p - 1), k - 1);
        }
        CHECK_UINT(ilog10_u32(p + 1), k);
        if (k < 9) {
            p *= 10;
        }
    }
    CHECK_UINT(ilog10_u32(4294967295u), 9);
    return check_summary();
}
