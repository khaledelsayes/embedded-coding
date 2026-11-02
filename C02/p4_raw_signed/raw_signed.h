/* C02 p4 - signed values from raw sensor bits
 *
 * Sensors return signed readings as N-bit two's complement numbers in an unsigned field:
 * a 12-bit accelerometer gives 0x000..0xFFF, where 0x800..0xFFF are the negative values.
 *
 * raw_to_signed: interpret raw (0 .. 2^bits - 1) as a bits-wide two's complement number.
 *   bits is 1 .. 32. Bits above `bits` in raw are guaranteed to be 0.
 *   raw_to_signed(0x7FF, 12) == 2047    raw_to_signed(0x800, 12) == -2048
 *   raw_to_signed(0xFFF, 12) == -1      raw_to_signed(0x8000, 16) == -32768
 *   raw_to_signed(1, 1) == -1           raw_to_signed(0xFFFFFFFF, 32) == -1
 *
 * signed_to_raw: the inverse. v is guaranteed to fit in `bits` bits as a signed value.
 *   signed_to_raw(-1, 12) == 0xFFF      signed_to_raw(-2048, 12) == 0x800
 *
 * Rule: arithmetic only (+ - * / and comparisons). No bit operators (& | ^ ~ << >>): they are
 * week 4. Your result must be correct for every possible input; the test checks all 12-bit
 * and all 16-bit values, plus edges for other widths.
 */
#ifndef RAW_SIGNED_H
#define RAW_SIGNED_H

#include <stdint.h>

int32_t raw_to_signed(uint32_t raw, unsigned bits);
uint32_t signed_to_raw(int32_t v, unsigned bits);

#endif
