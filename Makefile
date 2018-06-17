CC=gcc
SMUDGE_OPTIONS_PNG=--dot-fmt=Png
SMUDGE ?= smudge
CFLAGS=-Wall -Wextra -Wno-unused-parameter -ggdb3 -O0
LPATH=-L $(HOME)/smear
LFLAGS=-lsmear -pthread
IPATH=-I$(HOME)/smear/include

all: turnstile

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $(IPATH) $^

%_ext.h %.png %.c %.h: %.smudge
	$(SMUDGE) $(SMUDGE_OPTIONS_PNG) $^

turnstile: turnstile.o main.o turnstile_ext.o
	$(CC) $(CFLAGS) $(LPATH) -o $@ $^ $(LFLAGS)

.PHONY: all clean

clean:
	rm -f *.o turnstile_ext.h turnstile.c turnstile.h turnstile
