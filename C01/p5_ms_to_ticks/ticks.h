/* C01 p5 - milliseconds to RTOS ticks
 *
 * An RTOS counts time in ticks; tick_hz ticks per second (FreeRTOS: configTICK_RATE_HZ).
 *
 * ms_to_ticks: the number of ticks needed to wait AT LEAST ms milliseconds,
 *   i.e. ceil(ms * tick_hz / 1000).
 *   If the true result does not fit in uint32_t, return UINT32_MAX (saturate).
 *   Valid inputs: any ms (0 .. UINT32_MAX), tick_hz 1 .. 1000000.
 *   ms_to_ticks(10, 1000) == 10,  ms_to_ticks(10, 100) == 1,  ms_to_ticks(1, 100) == 1  (rounds UP),
 *   ms_to_ticks(0, 100) == 0
 *
 * ticks_to_ms: the inverse, rounded DOWN: floor(ticks * 1000 / tick_hz), saturating at UINT32_MAX.
 *   ticks_to_ms(1, 100) == 10,  ticks_to_ms(3, 1024) == 2
 *
 * Watch the intermediate product: 4000000000 ms * 1000 Hz does not fit in 32 bits.
 * (FreeRTOS's own pdMS_TO_TICKS rounds DOWN, so pdMS_TO_TICKS(5) at 100 Hz is 0: a
 *  "wait 5 ms" that does not wait at all. That is the bug this function avoids.)
 */
#ifndef TICKS_H
#define TICKS_H

#include <stdint.h>

uint32_t ms_to_ticks(uint32_t ms, uint32_t tick_hz);
uint32_t ticks_to_ms(uint32_t ticks, uint32_t tick_hz);

#endif
