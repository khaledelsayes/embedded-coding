# embedded-coding

Daily problems for the Embedded C and C++ plan (see "00 Plan" in the Obsidian vault).

    make day D=C01                       # every problem of day C01
    make test P=C01/p1_clamp             # one problem
    make rewrite P=C01/p5_ms_to_ticks    # fresh spec + tests for a cold rewrite, in rewrite/

Each problem folder holds a header (the spec) and a test file. You write the .c file with the
same name as the header. Builds use -Wall -Wextra -Wshadow -Wconversion -Werror and the address
and undefined-behaviour sanitizers; a warning is a failure.

common/check.h   the test macros
tools/run.sh     the build-and-run script behind make
solutions/       reference solutions: open only after you pass
