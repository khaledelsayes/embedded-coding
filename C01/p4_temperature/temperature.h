/* C01 p4 - temperature conversion in integer tenths of a degree
 *
 * Firmware avoids float where it can. Temperatures here are in TENTHS of a degree:
 * 215 means 21.5 C.
 *
 * c10_to_f10: convert tenths of Celsius to tenths of Fahrenheit, F = C * 9 / 5 + 32,
 *   rounded to the NEAREST tenth; exact halves round AWAY from zero (2.5 -> 3, -2.5 -> -3).
 *   Valid input range: -100000 .. 100000 (that is -10000.0 C .. 10000.0 C).
 *   c10_to_f10(0) == 320,  c10_to_f10(1000) == 2120,  c10_to_f10(-400) == -400,
 *   c10_to_f10(1) == 322   (0.1 C = 32.18 F -> 32.2)
 *
 * f10_to_c10: the inverse, C = (F - 32) * 5 / 9, same rounding rule. Same input range.
 *   f10_to_c10(320) == 0,  f10_to_c10(2120) == 1000,  f10_to_c10(1000) == 378   (37.777.. -> 37.8)
 *
 * Hint: work out the exact fraction first, then round. Write a tiny helper.
 */
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdint.h>

int32_t c10_to_f10(int32_t c10);
int32_t f10_to_c10(int32_t f10);

#endif
