CC=gcc
CFLAGS=-I lib

bin/main: src/main.c
	$(CC) $(CFLAGS) -o $@ $^

test: bin/main
	cat tests/test01.dat | $^

clean:
	@rm -rf bin/*
