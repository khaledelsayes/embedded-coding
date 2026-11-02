#include <stdint.h>
#include "check.h"
#include "sequence.h"

int main(void)
{
    /* the counter starts at 0 without any reset */
    CHECK_UINT(next_seq(), 0);
    CHECK_UINT(next_seq(), 1);
    CHECK_UINT(next_seq(), 2);

    seq_reset(65534);
    CHECK_UINT(next_seq(), 65534);
    CHECK_UINT(next_seq(), 65535);
    CHECK_UINT(next_seq(), 0);
    CHECK_UINT(next_seq(), 1);

    seq_reset(100);
    for (uint32_t i = 0; i < 200000; i++) {
        CHECK_UINT(next_seq(), (100 + i) % 65536);
    }

    CHECK_INT(seq_is_newer(5, 3), 1);
    CHECK_INT(seq_is_newer(3, 5), 0);
    CHECK_INT(seq_is_newer(2, 65530), 1);
    CHECK_INT(seq_is_newer(65530, 2), 0);
    CHECK_INT(seq_is_newer(7, 7), 0);
    CHECK_INT(seq_is_newer(32767, 0), 1);
    CHECK_INT(seq_is_newer(32768, 0), 0);
    CHECK_INT(seq_is_newer(0, 32768), 0);
    CHECK_INT(seq_is_newer(0, 32769), 1);
    /* every distance from a fixed b */
    for (uint32_t d = 0; d < 65536; d++) {
        uint16_t b = 40000;
        uint16_t a = (uint16_t)((b + d) % 65536);
        CHECK_INT(seq_is_newer(a, b), d >= 1 && d <= 32767);
    }
    return check_summary();
}
