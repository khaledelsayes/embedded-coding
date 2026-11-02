#include "hysteresis.h"

int heater_step(int state, int32_t temp, int32_t on_at, int32_t off_at)
{
    if (state == 0 && temp <= on_at) {
        return 1;
    }
    if (state == 1 && temp >= off_at) {
        return 0;
    }
    return state;
}

unsigned count_switches(int32_t start, int32_t step, unsigned n, int32_t on_at, int32_t off_at)
{
    int state = 0;
    unsigned switches = 0;
    int32_t temp = start;
    for (unsigned i = 0; i < n; i++) {
        int next = heater_step(state, temp, on_at, off_at);
        if (next != state) {
            switches++;
        }
        state = next;
        temp += step;
    }
    return switches;
}
