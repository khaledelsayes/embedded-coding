#include "overflow.h"

int add_overflows_i32(int32_t a, int32_t b)
{
    if (b > 0) {
        return a > INT32_MAX - b;
    }
    return a < INT32_MIN - b;
}

int sub_overflows_i32(int32_t a, int32_t b)
{
    if (b < 0) {
        return a > INT32_MAX + b;
    }
    return a < INT32_MIN + b;
}

int mul_overflows_i32(int32_t a, int32_t b)
{
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a > 0) {
        if (b > 0) {
            return a > INT32_MAX / b;
        }
        return b < INT32_MIN / a;
    }
    if (b > 0) {
        return a < INT32_MIN / b;
    }
    /* both negative: result positive */
    return a < INT32_MAX / b;
}
