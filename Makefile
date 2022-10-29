CC=gcc
CFLAGS=-I include -Wall

includes := $(patsubst src/impl/lib%.c,obj/lib%.o,$(wildcard src/impl/lib*.c))

all: bin/main
	@mkdir -p obj bin
	@echo "Building"

bin/main:  obj/main.o $(includes)
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^
	
	
obj/lib%.o: src/impl/lib%.c
	$(CC) $(CFLAGS) -o $@ -c $^
	
test_all: bin/main
	cat tests/test01.dat | $^

clean:
	@rm -rf bin/*
