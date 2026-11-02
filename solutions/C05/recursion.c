#include "recursion.h"

static int coin(int k)
{
    switch (k) {
    case 1: return 1;
    case 2: return 5;
    case 3: return 10;
    case 4: return 25;
    default: return 50;
    }
}

static uint32_t ways(int amount, int kinds)
{
    if (amount == 0) {
        return 1;
    }
    if (amount < 0 || kinds == 0) {
        return 0;
    }
    return ways(amount, kinds - 1) + ways(amount - coin(kinds), kinds);
}

uint32_t count_change(int amount)
{
    return ways(amount, 5);
}

static uint32_t rev(uint32_t n, uint32_t acc)
{
    if (n == 0) {
        return acc;
    }
    return rev(n / 10, acc * 10 + n % 10);
}

uint32_t reverse_digits(uint32_t n)
{
    return rev(n, 0);
}

int is_digit_palindrome(uint32_t n)
{
    return reverse_digits(n) == n;
}
