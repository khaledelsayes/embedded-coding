#!/usr/bin/env bash
# run.sh <problem-dir>...   builds every .c in each dir with the strict flags and runs it
set -u
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
CC="${CC:-gcc}"
CFLAGS="-std=c11 -Wall -Wextra -Wshadow -Wconversion -Werror -g -O1 -fno-omit-frame-pointer -fsanitize=address,undefined -fno-sanitize-recover=all"
pass=0
fail=0
for dir in "$@"; do
    dir="${dir%/}"
    name="$dir"
    if ! ls "$dir"/test_*.c >/dev/null 2>&1; then
        echo "== $name: no test_*.c here, skipped"
        continue
    fi
    if [ "$(ls "$dir"/*.c | wc -l)" -lt 2 ]; then
        echo "== $name: NOT STARTED (write your .c file next to the .h)"
        fail=$((fail + 1))
        continue
    fi
    mkdir -p "$ROOT/build"
    exe="$ROOT/build/$(echo "$name" | tr '/' '_')"
    echo "== $name"
    if ! $CC $CFLAGS -I"$ROOT/common" -I"$dir" "$dir"/*.c -o "$exe" -lm; then
        echo "  BUILD FAILED"
        fail=$((fail + 1))
        continue
    fi
    if (cd "$dir" && timeout 10 "$exe"); then
        pass=$((pass + 1))
    else
        rc=$?
        if [ "$rc" -eq 124 ]; then
            echo "  TIMEOUT after 10 s: an endless loop, or an algorithm that is far too slow"
        else
            echo "  (exit code $rc)"
        fi
        fail=$((fail + 1))
    fi
done
echo "---- $pass passed, $fail not passing"
[ "$fail" -eq 0 ]
