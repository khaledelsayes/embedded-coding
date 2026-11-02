/* C04 p1 - a thermostat with hysteresis
 *
 * A heater controlled by "on below 20.0 C, off above 20.0 C" switches on and off many times a
 * second when the temperature hovers around 20.0 (relay chatter). Hysteresis uses two thresholds.
 *
 * heater_step: given the current heater state (0 = off, 1 = on) and a new temperature reading,
 *   return the new state:
 *     - if the heater is off and temp <= on_at,  turn it on
 *     - if the heater is on  and temp >= off_at, turn it off
 *     - otherwise keep the current state
 *   Temperatures are in tenths of a degree. on_at < off_at always. state is 0 or 1.
 *   heater_step(0, 195, 195, 205) == 1     heater_step(1, 200, 195, 205) == 1
 *   heater_step(1, 205, 195, 205) == 0     heater_step(0, 200, 195, 205) == 0
 *
 * count_switches: simulate a heater that starts OFF, fed the temperatures
 *   start, start + step, start + 2*step, ... (n readings in total), and return how many times
 *   the state changed. step may be negative. n may be 0.
 *   count_switches(180, 1, 50, 195, 205) == 2   (on at the first reading, off at 205)
 */
#ifndef HYSTERESIS_H
#define HYSTERESIS_H

#include <stdint.h>

int heater_step(int state, int32_t temp, int32_t on_at, int32_t off_at);
unsigned count_switches(int32_t start, int32_t step, unsigned n, int32_t on_at, int32_t off_at);

#endif
