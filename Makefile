CC=g++
CFLAGS=-g -Wall -c

all: libasciify

libasciify: src/libasciify.cc
	$(CC) $(CFLAGS) src/libasciify.cc -o src/libasciify.o

.PHONY: clean

clean:
	rm -fv src/libasciify.o
