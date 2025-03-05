CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all: display_perm

display_perm: display_perm.o
	gcc ${CFLAGS} -o display_perm display_perm.o 

.PHONY: clean

clean:
	rm *.o
	rm display_perm
