/*
 * libint_handler.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdlib.h>
#include <string.h>
#include <libint_handler.h>

/*
 * Count number of ones in input (integer)
 */
int count_ones (char *input) {
	int ret = 0;
	for (int i=0; input[i]; i++) {
		ret += input[i] == '1';
	}
	return ret;
}

/*
 * Convert integer to array of char
 */
char *int_to_char_array (int input) {
	int size  = 1;
	for (int tmp = input/2; tmp; tmp >>= 1) {size++;}

	char *output = (char *) malloc(sizeof(char) * (size+1));
	output[size] = '\0';
	for (int i = 0; i<size; i++) {
		output[size-1-i] = input % 2 + '0';
		input >>= 1;
	}
	return output;
}

char *compare_bits (char *a, char *b) {
	int size_a = strlen(a), size_b = strlen(b);
	int size_min = size_a >= size_b ? size_b : size_a;
	int size_max = size_a >= size_b ? size_a : size_b;
	char *output =  strdup(size_a >= size_b ? a : b);

	for (int i=0; i<size_min; i++) {
		if (a[size_a-1-i] != b[size_b-1-i]) {
			output[size_max-1-i] = 'X';
		}
	}
	for (int i=size_min; i<size_max; i++) {
		if (output[size_max-1-i] == '1') {
			output[size_max-1-i] = 'X';
		}
	}
	return output;
}
