#include "calendar.h"

int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int days_in_month(int year, int month)
{
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return is_leap_year(year) ? 29 : 28;
    default:
        return -1;
    }
}

int day_of_year(int year, int month, int day)
{
    int dim = days_in_month(year, month);
    if (dim < 0 || day < 1 || day > dim) {
        return -1;
    }
    int total = day;
    for (int m = 1; m < month; m++) {
        total += days_in_month(year, m);
    }
    return total;
}
