/* C01 p3 - calendar arithmetic (Gregorian calendar, years 1 to 9999)
 *
 * Write calendar.c. No arrays needed (a switch is fine); arrays come in week 2.
 *
 * is_leap_year: 1 if leap, else 0. Divisible by 4, except centuries, except every 400 years.
 *   is_leap_year(2024) == 1, is_leap_year(1900) == 0, is_leap_year(2000) == 1
 *
 * days_in_month: number of days in month (1..12) of year; -1 if month is out of range.
 *
 * day_of_year: 1 for 1 January, 365 or 366 for 31 December.
 *   Return -1 for an invalid date (month outside 1..12, day outside 1..days_in_month).
 *   day_of_year(2023, 3, 1) == 60,  day_of_year(2024, 3, 1) == 61,  day_of_year(2023, 2, 29) == -1
 */
#ifndef CALENDAR_H
#define CALENDAR_H

int is_leap_year(int year);
int days_in_month(int year, int month);
int day_of_year(int year, int month, int day);

#endif
