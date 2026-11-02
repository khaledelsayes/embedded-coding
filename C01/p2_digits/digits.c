#include "digits.h"
#include <stdint.h>





unsigned digit_count(uint32_t n)

{

    uint32_t count = 1;
    while ((n / 10) != 0)
    {
        count++;
        n = n / 10;
    }
    return count;

}




unsigned digit_sum(uint32_t n)
{
    uint32_t sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;

}


unsigned digit_at(uint32_t n, unsigned pos)
{
    unsigned digit = 0;
    for (unsigned i = 0; i <= pos; i++)
    {
        digit = n % 10;
        n = n / 10;
    }
    return digit;


}
