CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all: myexecvp

myexecvp: myexecvp.o
	gcc ${CFLAGS} -o myexecvp myexecvp.o 

.PHONY: clean

clean:
	rm *.o
	rm myexecvp
