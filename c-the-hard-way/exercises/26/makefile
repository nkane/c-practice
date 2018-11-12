CC=clang
CFLAGS=-Wall -g3 -DNDEBUG

all: logfind main

main:
	$(CC) $(CFLAGS) main.c logfind.o -o logfind

logfind:
	$(CC) $(CFLAGS) -c -o logfind.o logfind.c 

clean:
	rm logfind logfind.o
