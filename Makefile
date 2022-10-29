CC=gcc
CFLAGS=-I include -Wall

includes := $(patsubst src/lib%.c,obj/lib%.o,$(wildcard src/lib*.c))

all: bin/main
	@echo "Building"

bin/main:  obj/main.o $(includes)
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^
	
tests: bin/main
	cat tests/test01.dat | $^

clean:
	@rm -rf bin/*
