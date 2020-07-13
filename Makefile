CC=gcc
CFLAGS=-I lib

bin/main: src/main.c
	$(CC) $(CFLAGS) -o $@ $^
clean:
	@rm -rf bin/*
