/* C06 project - a thermostat controller (uses all of week 1)
 *
 * The controller is called with each new temperature reading and the current time from a
 * millisecond counter that WRAPS at 2^32. It returns whether the heater should be on.
 * All state lives in static variables inside thermostat.c.
 *
 * thermo_init(on_at, off_at, min_on_ms, min_off_ms, now_ms)
 *   Heater OFF. It counts as having been off since now_ms. Switch counter = 0.
 *   Temperatures are tenths of a degree C; on_at < off_at.
 *
 * thermo_update(temp, now_ms) -> new heater state (0 or 1). Rules, in this order:
 *   1. SENSOR FAULT: temp < -400 or temp > 1250 (outside -40.0 .. 125.0 C) means the sensor is
 *      broken. The heater goes OFF immediately, ignoring the minimum on-time (safety first).
 *      If that turns it off, it is a switch, and the off-period starts at now_ms.
 *   2. Otherwise decide what hysteresis WANTS (same rule as C04 p1):
 *        off and temp <= on_at  -> wants on;   on and temp >= off_at -> wants off;
 *        otherwise wants to stay.
 *   3. A wanted change only happens if the heater has been in its current state for at least
 *      min_off_ms (to turn on) or min_on_ms (to turn off), measured wrap-safely from the moment
 *      it entered that state. Otherwise it stays, and the request is simply re-evaluated at the
 *      next update (nothing is remembered).
 *   4. When the state changes, the switch counter goes up by 1 and the new state's start time is
 *      now_ms.
 *   now_ms never goes backwards, and two consecutive calls are less than 2^31 ms apart.
 *
 * thermo_switches() -> number of state changes since thermo_init.
 *
 * Why the minimum times: a compressor or a relay that is cycled every few seconds wears out.
 */
#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <stdint.h>

void thermo_init(int32_t on_at, int32_t off_at, uint32_t min_on_ms, uint32_t min_off_ms,
                 uint32_t now_ms);
int thermo_update(int32_t temp, uint32_t now_ms);
unsigned thermo_switches(void);

#endif
