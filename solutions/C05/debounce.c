#include "debounce.h"

static int stable = 0;
static unsigned count = 0;
static unsigned presses = 0;

void debounce_reset(int level)
{
    stable = level;
    count = 0;
    presses = 0;
}

int debounce_update(int raw)
{
    if (raw == stable) {
        count = 0;
        return stable;
    }
    count++;
    if (count >= DEBOUNCE_COUNT) {
        if (stable == 0) {
            presses++;
        }
        stable = raw;
        count = 0;
    }
    return stable;
}

unsigned debounce_presses(void)
{
    return presses;
}
