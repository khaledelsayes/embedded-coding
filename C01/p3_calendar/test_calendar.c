#include "check.h"
#include "calendar.h"

int main(void)
{
    CHECK_INT(is_leap_year(1), 0);
    CHECK_INT(is_leap_year(4), 1);
    CHECK_INT(is_leap_year(100), 0);
    CHECK_INT(is_leap_year(200), 0);
    CHECK_INT(is_leap_year(300), 0);
    CHECK_INT(is_leap_year(400), 1);
    CHECK_INT(is_leap_year(1600), 1);
    CHECK_INT(is_leap_year(1700), 0);
    CHECK_INT(is_leap_year(1800), 0);
    CHECK_INT(is_leap_year(1900), 0);
    CHECK_INT(is_leap_year(2000), 1);
    CHECK_INT(is_leap_year(2023), 0);
    CHECK_INT(is_leap_year(2024), 1);
    CHECK_INT(is_leap_year(2100), 0);
    CHECK_INT(is_leap_year(2400), 1);
    CHECK_INT(is_leap_year(9996), 1);
    CHECK_INT(is_leap_year(9999), 0);

    CHECK_INT(days_in_month(2023, 1), 31);
    CHECK_INT(days_in_month(2023, 2), 28);
    CHECK_INT(days_in_month(2023, 3), 31);
    CHECK_INT(days_in_month(2023, 4), 30);
    CHECK_INT(days_in_month(2023, 5), 31);
    CHECK_INT(days_in_month(2023, 6), 30);
    CHECK_INT(days_in_month(2023, 7), 31);
    CHECK_INT(days_in_month(2023, 8), 31);
    CHECK_INT(days_in_month(2023, 9), 30);
    CHECK_INT(days_in_month(2023, 10), 31);
    CHECK_INT(days_in_month(2023, 11), 30);
    CHECK_INT(days_in_month(2023, 12), 31);
    CHECK_INT(days_in_month(2024, 1), 31);
    CHECK_INT(days_in_month(2024, 2), 29);
    CHECK_INT(days_in_month(2024, 3), 31);
    CHECK_INT(days_in_month(2024, 4), 30);
    CHECK_INT(days_in_month(2024, 5), 31);
    CHECK_INT(days_in_month(2024, 6), 30);
    CHECK_INT(days_in_month(2024, 7), 31);
    CHECK_INT(days_in_month(2024, 8), 31);
    CHECK_INT(days_in_month(2024, 9), 30);
    CHECK_INT(days_in_month(2024, 10), 31);
    CHECK_INT(days_in_month(2024, 11), 30);
    CHECK_INT(days_in_month(2024, 12), 31);
    CHECK_INT(days_in_month(1900, 1), 31);
    CHECK_INT(days_in_month(1900, 2), 28);
    CHECK_INT(days_in_month(1900, 3), 31);
    CHECK_INT(days_in_month(1900, 4), 30);
    CHECK_INT(days_in_month(1900, 5), 31);
    CHECK_INT(days_in_month(1900, 6), 30);
    CHECK_INT(days_in_month(1900, 7), 31);
    CHECK_INT(days_in_month(1900, 8), 31);
    CHECK_INT(days_in_month(1900, 9), 30);
    CHECK_INT(days_in_month(1900, 10), 31);
    CHECK_INT(days_in_month(1900, 11), 30);
    CHECK_INT(days_in_month(1900, 12), 31);
    CHECK_INT(days_in_month(2000, 1), 31);
    CHECK_INT(days_in_month(2000, 2), 29);
    CHECK_INT(days_in_month(2000, 3), 31);
    CHECK_INT(days_in_month(2000, 4), 30);
    CHECK_INT(days_in_month(2000, 5), 31);
    CHECK_INT(days_in_month(2000, 6), 30);
    CHECK_INT(days_in_month(2000, 7), 31);
    CHECK_INT(days_in_month(2000, 8), 31);
    CHECK_INT(days_in_month(2000, 9), 30);
    CHECK_INT(days_in_month(2000, 10), 31);
    CHECK_INT(days_in_month(2000, 11), 30);
    CHECK_INT(days_in_month(2000, 12), 31);
    CHECK_INT(days_in_month(2024, 0), -1);
    CHECK_INT(days_in_month(2024, 13), -1);

    /* {year, month, day, expected day_of_year}, generated with Python's datetime */
    static const int ok[][4] = {
        {1900, 5, 4, 124},
        {4, 8, 21, 234},
        {2100, 2, 16, 47},
        {1600, 7, 20, 202},
        {4, 5, 24, 145},
        {1900, 6, 1, 152},
        {366, 11, 18, 322},
        {1600, 11, 7, 312},
        {6916, 9, 8, 252},
        {4, 9, 8, 252},
        {2100, 11, 8, 312},
        {2024, 1, 14, 14},
        {1900, 3, 21, 80},
        {1900, 12, 11, 345},
        {1600, 9, 27, 271},
        {2024, 5, 19, 140},
        {1600, 10, 28, 302},
        {4, 4, 24, 115},
        {1600, 11, 6, 311},
        {2023, 2, 15, 46},
        {1900, 3, 17, 76},
        {2023, 8, 24, 236},
        {4, 1, 10, 10},
        {1600, 11, 6, 311},
        {2100, 1, 25, 25},
        {2100, 7, 17, 198},
        {2023, 8, 30, 242},
        {4412, 7, 26, 208},
        {2000, 9, 25, 269},
        {2100, 7, 31, 212},
        {4, 6, 19, 171},
        {2100, 9, 14, 257},
        {2023, 7, 12, 193},
        {2023, 8, 20, 232},
        {2100, 11, 6, 310},
        {2000, 2, 26, 57},
        {2024, 1, 27, 27},
        {1900, 1, 15, 15},
        {2024, 4, 9, 100},
        {2000, 6, 10, 162},
        {2000, 3, 9, 69},
        {2000, 11, 9, 314},
        {4, 12, 11, 346},
        {4, 2, 1, 32},
        {1600, 6, 14, 166},
        {2024, 2, 9, 40},
        {2100, 10, 14, 287},
        {2100, 1, 13, 13},
        {2400, 12, 31, 366},
        {4, 12, 17, 352},
        {2100, 11, 26, 330},
        {4, 4, 17, 108},
        {1600, 11, 19, 324},
        {1600, 1, 24, 24},
        {2000, 4, 29, 120},
        {2024, 2, 28, 59},
        {2024, 5, 24, 145},
        {1600, 10, 9, 283},
        {2137, 9, 29, 272},
        {2100, 10, 15, 288},
        {2023, 1, 1, 1},
        {2023, 12, 31, 365},
        {2024, 12, 31, 366},
        {2024, 2, 29, 60},
        {1900, 12, 31, 365},
        {2000, 12, 31, 366},
        {9999, 12, 31, 365},
        {1, 1, 1, 1},
    };
    static const int bad[][3] = {
        {2023, 2, 29},
        {1900, 2, 29},
        {2024, 2, 30},
        {2024, 4, 31},
        {2024, 0, 1},
        {2024, 13, 1},
        {2024, 1, 0},
        {2024, 1, 32},
        {2024, 6, -1},
    };
    for (unsigned i = 0; i < sizeof(ok) / sizeof(ok[0]); i++) {
        CHECK_INT(day_of_year(ok[i][0], ok[i][1], ok[i][2]), ok[i][3]);
    }
    for (unsigned i = 0; i < sizeof(bad) / sizeof(bad[0]); i++) {
        CHECK_INT(day_of_year(bad[i][0], bad[i][1], bad[i][2]), -1);
    }
    return check_summary();
}
