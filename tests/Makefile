CC=g++
CFLAGS=-g -Wall

all: main

main: src/main.cc ../build/libasciify.o
	mkdir -p build/
	$(CC) $(CFLAGS) src/main.cc ../build/libasciify.o -o build/main

.PHONY: clean

clean:
	rm -rfv build/
