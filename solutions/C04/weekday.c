#include "weekday.h"

static int is_leap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

static int dim(int y, int m)
{
    switch (m) {
    case 2:
        return is_leap(y) ? 29 : 28;
    case 4: case 6: case 9: case 11:
        return 30;
    default:
        return 31;
    }
}

/* Sakamoto's method; month offsets in a switch */
static int month_offset(int m)
{
    switch (m) {
    case 1: return 0;
    case 2: return 3;
    case 3: return 2;
    case 4: return 5;
    case 5: return 0;
    case 6: return 3;
    case 7: return 5;
    case 8: return 1;
    case 9: return 4;
    case 10: return 6;
    case 11: return 2;
    default: return 4;
    }
}

int weekday(int year, int month, int day)
{
    if (month < 1 || month > 12 || day < 1 || day > dim(year, month)) {
        return -1;
    }
    int y = month < 3 ? year - 1 : year;
    return (y + y / 4 - y / 100 + y / 400 + month_offset(month) + day) % 7;
}
