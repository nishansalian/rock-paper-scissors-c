CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all clean

all: rps

rps: rps.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f rps
