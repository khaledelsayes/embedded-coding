/* C04 p4 - day of the week (Gregorian calendar, years 1 to 9999)
 *
 * weekday: 0 = Sunday, 1 = Monday, ... 6 = Saturday. Return -1 for an invalid date
 *   (month outside 1..12, day outside the month's valid range; mind leap years).
 *   weekday(2024, 1, 1) == 1 (Monday)    weekday(2000, 2, 29) == 2 (Tuesday)
 *   weekday(1, 1, 1) == 1                weekday(2023, 2, 29) == -1
 *
 * Any correct method is fine. Two that work:
 *   - count days from a known date (slow but simple; it must still be fast enough for 2000 calls
 *     spread over 10 000 years: count whole years with arithmetic, not one day at a time);
 *   - Sakamoto's or Zeller's formula, with the month offsets in a switch (no arrays yet).
 * The tests compare against Python's datetime for 2000 random dates.
 * This is self-contained: do not include the C01 calendar files; write what you need here.
 */
#ifndef WEEKDAY_H
#define WEEKDAY_H

int weekday(int year, int month, int day);

#endif
