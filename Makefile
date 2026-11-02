# make test P=C01/p1_clamp          one problem
# make day D=C01                    every problem of a day
# make rewrite P=C01/p5_ms_to_ticks fresh copy of the spec and test, for a cold rewrite
# make clean

.PHONY: test day rewrite clean help
help:
	@sed -n '1,4p' Makefile

test:
	@test -n "$(P)" || (echo "usage: make test P=C01/p1_clamp" && false)
	@tools/run.sh $(P)

day:
	@test -n "$(D)" || (echo "usage: make day D=C01" && false)
	@tools/run.sh $(sort $(dir $(wildcard $(D)/*/test_*.c)))

rewrite:
	@test -n "$(P)" || (echo "usage: make rewrite P=C01/p5_ms_to_ticks" && false)
	@n=1; base=rewrite/$$(echo $(P) | tr '/' '_'); \
	while [ -e $$base.$$n ]; do n=$$((n+1)); done; \
	mkdir -p $$base.$$n && cp $(P)/*.h $(P)/test_*.c $$base.$$n/ && \
	echo "Write your .c in $$base.$$n/ then: make test P=$$base.$$n"

clean:
	rm -rf build
