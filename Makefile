## This file is part of libasciify.
##
## libasciify is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## libasciify is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with libasciify. If not, see <http://www.gnu.org/licenses/>.

## authors:
##      ChrisBuchholz <http://chrisbuchholz.dk>

CC=g++
CFLAGS=-g -Wall -c

all: libasciify

libasciify: src/libasciify.cc
	$(CC) $(CFLAGS) src/libasciify.cc -o src/libasciify.o

.PHONY: clean

clean:
	rm -fv src/libasciify.o
