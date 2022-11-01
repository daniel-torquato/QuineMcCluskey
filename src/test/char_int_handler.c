//
// Created by daniel on 11/1/22.
//
#include <criterion/criterion.h>
#include "libint_handler.h"

Test(char_int_handler, int_to_char_array) {
    int inputs[] = {2, 5, 7, 15};
    char *outputs[] = {"10", "101", "111", "1111"};
    for (int i=0; i<sizeof(inputs)/sizeof(int); i++) {
        cr_expect(strcmp(int_to_char_array(inputs[i]), outputs[i]) == 0, "wrong string at %d", i);
    }
}

Test(char_int_handler, count_ones) {
    int inputs[] = {2, 5, 7, 15};
    int outputs[] = {1, 2, 3, 4};
    for (int i=0; i<sizeof(inputs)/sizeof(int); i++) {
        cr_expect(count_ones(int_to_char_array(inputs[i])) == outputs[i], "wrong count ones at %d", i);
    }
}

Test(char_int_handler, compare_bits) {
    char *input_a[] = {"0","1","10", "100"};
    char *input_b[] = {"0","1","10", "100"};
    int size_a = sizeof(input_a)/sizeof(char*), size_b = sizeof(input_b)/sizeof(char*);
    char *outputs[] = {"0", "X", "X0", "X00", "X", "1", "X0", "10", "X00", "100"};
    int output_idx = 0;
    for (int i=0; i<size_a; i++) {
        for (int j=0; j<size_b; j++) {
            char *merged = compare_bits(input_a[i], input_b[j]);
            if (merged) {
                cr_expect(strcmp(merged, outputs[output_idx++]) == 0, "wrong merge at %d", output_idx);
            }
        }
    }
}