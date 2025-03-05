CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all: is_newer

is_newer: is_newer.o
	gcc ${CFLAGS} -o is_newer is_newer.o 

.PHONY: clean

clean:
	rm *.o
	rm is_newer
