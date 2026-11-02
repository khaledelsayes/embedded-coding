#include "clamp.h"
#include <stdint.h>

int32_t clamp_i32(int32_t v, int32_t lo, int32_t hi) {

  if (v < lo)
   {
    return lo;
   }

  if (v > hi)
   {
    return hi;
   }

    return v;
}


uint8_t clamp_to_u8(int32_t v) {

return (uint8_t)clamp_i32(v, 0, 255);

}