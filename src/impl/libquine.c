/*
 * libquine.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include "../include/libquine.h"

#include <stdbool.h>
#include <stdlib.h>

#include "../include/libint_handler.h"

struct bit_group init_group (int size, int base) {
	struct bit_group output = {
		.size = size,
		.base = base,
		.groups = (struct bitset **) malloc(sizeof(struct bitset *) * size)
	};
	return output;
}

struct bitset init_bitset(int base) {
	struct bitset output = {
			.size = base,
			.bits = (char*) malloc(sizeof(char) * (base + 1)),
	};
	output.bits[base] = '\0';
	return output;
}

struct bitset int2bitset (int input, int base) {
	struct bitset output = init_bitset(base);
	for (int i=0; i<base; i++) {
		output.bits[base-1-i] = input % 2;
		input >>= 1;
	}
	return output;
}

bool check_one_diff (struct bitset a, struct bitset b) {
	bool ret = false;
	if (a.size != b.size)
		return false;

	for (int i=0; i<a.size; i++) {
		if (a.bits[i] != b.bits[i]) {
			if (!ret)
				ret = true;
			else {
				ret = false;
				break;
			}
		}
	}
	return ret;
}

struct bitset merge_bitsets (struct bitset a, struct bitset b) {
	struct bitset output;
	if (a.size != b.size) {
		output.size = 0;
		output.bits = NULL;
		return output;
	}
	output = init_bitset(a.size);
	for (int i=0; i<a.size; i++) {
		if (b.bits[i] == a.bits[i]) {
			output.bits[i] = a.bits[i];
		}
		else
			output.bits[i] = 'X';
	}
	return output;
}

void add_int_to_group (struct bit_group group, int input) {
	//struct bitset input_bitset = int2bitset(input, group.base);
	//int ones = count_ones(input_bitset);
}

struct bit_group int_array_to_bit_group (int *input, int size, int base) {
	struct bit_group output = init_group (size, base);
	return output;
}
