CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all: group_belong

group_belong: group_belong.o
	gcc ${CFLAGS} -o group_belong group_belong.o 

.PHONY: clean

clean:
	rm *.o
	rm group_belong
