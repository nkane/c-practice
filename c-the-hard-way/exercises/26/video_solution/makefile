CC=clang
CFLAGS=-Wall -g

all: logfind
		./logfind || true
		./logfind MAX_LINE
		./logfind error MAX LINE
		./logfind -o error MAX LINE

logfind:
	$(CC) $(CFLAGS) logfind.c -o logfind

clean:
	rm -rf logfind
