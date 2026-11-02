/* C05 p4 - debouncing a button, with state kept in static variables
 *
 * A mechanical button "bounces": for a few milliseconds after a press the input flickers
 * between 0 and 1. The fix: only accept a new level after it has been read
 * DEBOUNCE_COUNT times IN A ROW. Call debounce_update() once per millisecond with the raw pin.
 *
 * debounce_reset(level): the stable level becomes `level` (0 or 1), and any partial count is
 *   discarded.
 * debounce_update(raw): feed one raw sample (0 or 1). Returns the stable level after this sample.
 *   - if raw equals the current stable level, the count of "different" samples goes back to 0;
 *   - otherwise the count goes up by 1, and when it reaches DEBOUNCE_COUNT the stable level
 *     changes to raw and the count goes back to 0.
 * debounce_presses(): how many times the stable level has changed from 0 to 1 since the last
 *   debounce_reset() (a "press" counter).
 *
 * Before any debounce_reset call, the stable level is 0.
 * Example with DEBOUNCE_COUNT 4, starting stable 0:
 *   raw:    1 0 1 1 1 1 1 0 0 0 0
 *   stable: 0 0 0 0 0 1 1 1 1 1 0     (one press counted)
 */
#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#define DEBOUNCE_COUNT 4

void debounce_reset(int level);
int debounce_update(int raw);
unsigned debounce_presses(void);

#endif
