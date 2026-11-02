/* C03 p4 - percentages for a display, in integers
 *
 * percent_x10: part / whole as a percentage in TENTHS of a percent, rounded to nearest
 *   (halves up). part may exceed whole (result above 1000). whole == 0 -> return 0.
 *   If the result would exceed 65535, return 65535.
 *   percent_x10(1, 3) == 333  (33.3 %)    percent_x10(2, 3) == 667    percent_x10(1, 8) == 125
 *   percent_x10(1, 2000) == 1  (0.05 % rounds up to 0.1 %)    percent_x10(5, 0) == 0
 *   Any uint32_t inputs: part * 1000 overflows 32 bits.
 *
 * battery_percent: battery level 0..100 from a voltage in millivolts, linear between
 *   empty_mv (0 %) and full_mv (100 %), rounded DOWN, clamped to 0..100.
 *   empty_mv < full_mv always.
 *   battery_percent(3700, 3300, 4200) == 44    battery_percent(3000, 3300, 4200) == 0
 *   battery_percent(4300, 3300, 4200) == 100
 */
#ifndef PERCENT_H
#define PERCENT_H

#include <stdint.h>

uint16_t percent_x10(uint32_t part, uint32_t whole);
uint8_t battery_percent(uint16_t mv, uint16_t empty_mv, uint16_t full_mv);

#endif
