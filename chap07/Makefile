SRCS = $(wildcard *.c)
PROGS = $(SRCS:.c=)

CC = cc
CFLAGS = -Wall -O2

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS) *.o

.PHONY: all clean
