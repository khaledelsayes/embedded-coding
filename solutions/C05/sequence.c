#include "sequence.h"

static uint16_t counter = 0;

uint16_t next_seq(void)
{
    uint16_t v = counter;
    counter = (uint16_t)(counter + 1u);
    return v;
}

void seq_reset(uint16_t start)
{
    counter = start;
}

int seq_is_newer(uint16_t a, uint16_t b)
{
    uint16_t d = (uint16_t)(a - b);
    return d >= 1 && d <= 32767;
}
