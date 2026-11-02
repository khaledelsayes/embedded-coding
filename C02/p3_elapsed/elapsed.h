/* C02 p3 - time arithmetic that survives counter wrap-around
 *
 * A millisecond counter in uint32_t wraps from 4294967295 to 0 after about 49.7 days
 * (millis() on Arduino, xTaskGetTickCount() at 1 kHz). Code that does
 * "if (now > start + timeout)" breaks at the wrap. These three functions do not.
 *
 * elapsed_ms: milliseconds from start to now, correct across ONE wrap.
 *   elapsed_ms(1500, 1000) == 500      elapsed_ms(5, 4294967290u) == 11
 *
 * timeout_expired: 1 if at least timeout ms have passed since start, else 0.
 *   timeout_expired(1499, 1000, 500) == 0   timeout_expired(1500, 1000, 500) == 1
 *   timeout_expired(4, 4294967290u, 10) == 1
 *
 * time_diff: signed difference a - b, for two timestamps less than 2^31 ms apart:
 *   positive if a is later than b, negative if a is earlier. Use it to sort deadlines.
 *   time_diff(1000, 1500) == -500     time_diff(5, 4294967290u) == 11
 *   time_diff(4294967290u, 5) == -11
 *   Do NOT just cast (uint32_t) to (int32_t): converting a value above INT32_MAX to a
 *   signed type is implementation-defined in C. Write it so it is defined on every compiler.
 */
#ifndef ELAPSED_H
#define ELAPSED_H

#include <stdint.h>

uint32_t elapsed_ms(uint32_t now, uint32_t start);
int timeout_expired(uint32_t now, uint32_t start, uint32_t timeout);
int32_t time_diff(uint32_t a, uint32_t b);

#endif
