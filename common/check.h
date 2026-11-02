/* check.h - a tiny test harness. Include it ONCE, in the test file only.
 *
 *   CHECK(cond)              passes if cond is true
 *   CHECK_INT(got, want)     compares as long long, prints both on failure
 *   CHECK_UINT(got, want)    compares as unsigned long long
 *   CHECK_STR(got, want)     compares two C strings (NULL-safe)
 *   return check_summary();  at the end of main: prints a summary, returns 0 or 1
 */
#ifndef CHECK_H
#define CHECK_H

#include <stdio.h>
#include <string.h>

static int check_total_ = 0;
static int check_failed_ = 0;

/* only the first CHECK_MAX_PRINT failures are printed */
#define CHECK_MAX_PRINT 20
#define CHECK_PRINT_ (check_failed_ <= CHECK_MAX_PRINT)

#define CHECK(cond)                                                            \
    do {                                                                       \
        check_total_++;                                                        \
        if (!(cond)) {                                                         \
            check_failed_++;                                                   \
            if (CHECK_PRINT_)                                                  \
                printf("  FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond);       \
        }                                                                      \
    } while (0)

#define CHECK_INT(got, want)                                                   \
    do {                                                                       \
        long long g_ = (long long)(got);                                       \
        long long w_ = (long long)(want);                                      \
        check_total_++;                                                        \
        if (g_ != w_) {                                                        \
            check_failed_++;                                                   \
            if (CHECK_PRINT_)                                                  \
            printf("  FAIL %s:%d: %s\n       got %lld, want %lld\n",           \
                   __FILE__, __LINE__, #got, g_, w_);                          \
        }                                                                      \
    } while (0)

#define CHECK_UINT(got, want)                                                  \
    do {                                                                       \
        unsigned long long g_ = (unsigned long long)(got);                     \
        unsigned long long w_ = (unsigned long long)(want);                    \
        check_total_++;                                                        \
        if (g_ != w_) {                                                        \
            check_failed_++;                                                   \
            if (CHECK_PRINT_)                                                  \
            printf("  FAIL %s:%d: %s\n       got %llu (0x%llX), want %llu (0x%llX)\n", \
                   __FILE__, __LINE__, #got, g_, g_, w_, w_);                  \
        }                                                                      \
    } while (0)

#define CHECK_STR(got, want)                                                   \
    do {                                                                       \
        const char *g_ = (got);                                                \
        const char *w_ = (want);                                               \
        check_total_++;                                                        \
        if (g_ == NULL || w_ == NULL ? g_ != w_ : strcmp(g_, w_) != 0) {       \
            check_failed_++;                                                   \
            if (CHECK_PRINT_)                                                  \
            printf("  FAIL %s:%d: %s\n       got \"%s\", want \"%s\"\n",       \
                   __FILE__, __LINE__, #got, g_ ? g_ : "(null)",               \
                   w_ ? w_ : "(null)");                                        \
        }                                                                      \
    } while (0)

static int check_summary(void)
{
    if (check_failed_ == 0) {
        printf("  PASS  %d/%d checks\n", check_total_, check_total_);
        return 0;
    }
    printf("  FAILED %d of %d checks\n", check_failed_, check_total_);
    return 1;
}

#endif
