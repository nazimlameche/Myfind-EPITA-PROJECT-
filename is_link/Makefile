CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all: is_link

is_link: is_link.o
	gcc ${CFLAGS} -o is_link is_link.o 

.PHONY: clean

clean:
	rm *.o
	rm is_link
