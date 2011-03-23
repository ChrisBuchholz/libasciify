CC=g++
CFLAGS=-g -Wall -I ../src

all: main

main: src/main.cc ../src/libasciify.o
	mkdir -p build/
	$(CC) $(CFLAGS) src/main.cc ../src/libasciify.o -o build/main

.PHONY: clean

clean:
	rm -rfv build/
