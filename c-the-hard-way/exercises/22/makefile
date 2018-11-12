CC=clang
CFLAGS=-Wall -g -DNDEBUG

all: ex22 main

main:
	$(CC) $(CFLAGS) ex22_main.c ex22.o -o ex22_main

ex22:
	$(CC) $(CFLAGS) -c -o ex22.o ex22.c

clean:
	rm ex22_main ex22.o
