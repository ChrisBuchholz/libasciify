CC=g++
CFLAGS=-g -Wall -I ../src -L/usr/X11R6/lib -lm -lpthread -lX11

all: main

main: src/main.cc ../src/libasciify.o
	mkdir -p build/
	$(CC) $(CFLAGS) src/main.cc ../src/libasciify.o -o build/main

.PHONY: clean

clean:
	rm -rfv build/
