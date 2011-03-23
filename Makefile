CC=g++
CFLAGS=-g -Wall

all: libasciify

libasciify: src/libasciify.cc
	mkdir -p build/
	$(CC) $(CFLAGS) -c src/libasciify.cc -o build/libasciify.o

.PHONY: clean

clean:
	rm -rfv build/
