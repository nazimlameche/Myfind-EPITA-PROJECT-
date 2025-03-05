CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all: user_belong

user_belong: user_belong.o
	gcc ${CFLAGS} -o user_belong user_belong.o 

.PHONY: clean

clean:
	rm *.o
	rm user_belong
