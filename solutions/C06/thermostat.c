#include "thermostat.h"

static int32_t g_on_at;
static int32_t g_off_at;
static uint32_t g_min_on;
static uint32_t g_min_off;
static int g_state;
static uint32_t g_since;
static unsigned g_switches;

void thermo_init(int32_t on_at, int32_t off_at, uint32_t min_on_ms, uint32_t min_off_ms,
                 uint32_t now_ms)
{
    g_on_at = on_at;
    g_off_at = off_at;
    g_min_on = min_on_ms;
    g_min_off = min_off_ms;
    g_state = 0;
    g_since = now_ms;
    g_switches = 0;
}

static void set_state(int s, uint32_t now_ms)
{
    g_state = s;
    g_since = now_ms;
    g_switches++;
}

int thermo_update(int32_t temp, uint32_t now_ms)
{
    if (temp < -400 || temp > 1250) {
        if (g_state == 1) {
            set_state(0, now_ms);
        }
        return g_state;
    }
    int want = g_state;
    if (g_state == 0 && temp <= g_on_at) {
        want = 1;
    } else if (g_state == 1 && temp >= g_off_at) {
        want = 0;
    }
    if (want != g_state) {
        uint32_t held = now_ms - g_since;
        uint32_t need = g_state == 0 ? g_min_off : g_min_on;
        if (held >= need) {
            set_state(want, now_ms);
        }
    }
    return g_state;
}

unsigned thermo_switches(void)
{
    return g_switches;
}
