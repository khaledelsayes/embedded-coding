#include "calendar.h"
#include <stdint.h>



int is_leap_year(int year)

{
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return 1;

return 0;

}

int days_in_month(int year, int month)

{

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (is_leap_year(year))
            return 29;
        else
            return 28;
    }

    return -1;

}


int day_of_year(int year, int month, int day)

{
    
    if (month < 1 || month > 12)
        return -1;

    int days_in_current_month = days_in_month(year, month);
    if (day < 1 || day > days_in_current_month)
        return -1;

    int total_days = 0;
    for (int m = 1; m < month; m++)
    {
        total_days += days_in_month(year, m);
    }
    total_days += day;

    return total_days;

}

