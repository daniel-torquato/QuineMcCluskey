/*
 * libint_handler.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdlib.h>
#include <libint_handler.h>

/*
 * Count number of ones in input (integer)
 */
int count_ones (int input) {
	int ret = 0;
	while (input) {
		ret += input % 2;
		input >>= 1;
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
		output[i] = input % 2 + '0';
		input >>= 1;
	}
	return output;
}
