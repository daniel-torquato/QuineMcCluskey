CC=gcc
CFLAGS=-I include -Wall
CFLAGS_TEST=$(CFLAGS) -lcriterion

includes := $(patsubst src/impl/lib%.c,obj/lib%.o,$(wildcard src/impl/lib*.c))
tests := $(patsubst src/test/%.c,bin/test/%,$(wildcard src/test/*.c))

all: folders test_all tests
	@echo "Building"

folders:
	@mkdir -p obj bin bin/test obj/test

bin/main: obj/main.o $(includes)
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

obj/lib%.o: src/impl/lib%.c
	$(CC) $(CFLAGS) -o $@ -c $^

obj/test/%.o: src/test/%.c
	$(CC) $(CFLAGS) -o $@ -c $^
	
test_all: bin/main
	cat tests/test01.dat | $^

bin/test/%: obj/test/%.o $(includes)
	$(CC) $(CFLAGS_TEST) -o $@ $^

check: folders tests
	@echo "Tested" $^

tests: $(tests)
	@for test in $^; do \
	 	$$test ; \
	done

clean:
	@rm -rf bin/* obj/*
