/* C05 p1 - packet sequence numbers: private state with static
 *
 * next_seq: returns 0, 1, 2, ... 65535, 0, 1, ... on successive calls (16-bit wrap).
 *   The counter lives INSIDE sequence.c as a static variable: no global visible to other files.
 * seq_reset: the next call to next_seq returns `start`.
 *
 * seq_is_newer: 1 if sequence number a was sent AFTER b, using "serial number arithmetic":
 *   a is newer than b when the forward distance from b to a, (a - b) mod 65536, is 1 .. 32767.
 *   Distance 0 (same number) or 32768 .. 65535 means "not newer".
 *   seq_is_newer(5, 3) == 1    seq_is_newer(3, 5) == 0    seq_is_newer(2, 65530) == 1 (wrapped)
 *   seq_is_newer(32768, 0) == 0
 *   Used to drop duplicate or late packets on a link where the counter wraps.
 */
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdint.h>

uint16_t next_seq(void);
void seq_reset(uint16_t start);
int seq_is_newer(uint16_t a, uint16_t b);

#endif
