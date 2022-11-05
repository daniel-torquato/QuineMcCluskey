//
// Created by daniel on 11/3/22.
//
#include <criterion/criterion.h>
#include "libbitset_array.h"

Test(bitset_array, init) {
    int sizes[] = {1, 2, 8, 11};
    int size = sizeof(sizes) / sizeof(int);
    for (int i=0; i<size; i++) {
        static struct bitset_array *output;
        output = bitset_array_init(sizes[i]);
        cr_expect(output != NULL, "wrong bit at %d", i);
        cr_expect(output->data != NULL, "wrong bit at %d", i);
        bitset_array_free(output);
    }
}

Test(bitset_array, set_and_get) {
    int sizes[] = {1, 2, 8, 11, 50};
    int index[] = {0, 1, 5, 8, 37};
    int size = sizeof(sizes) / sizeof(int);
    for (int i=0; i<size; i++) {
        static struct bitset_array *output;
        output = bitset_array_init(sizes[i]);
        bitset_array_set(output, index[i], true);
        for (int j=0; j<sizes[i]; j++) {
            cr_expect(bitset_array_get(output, j) == (j == index[i]), "wrong bit at (%d,%d)", i, j);
        }
        bitset_array_free(output);
    }
}

