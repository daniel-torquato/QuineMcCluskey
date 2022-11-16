//
// Created by daniel on 11/15/22.
//
#include <criterion/criterion.h>
#include "libcell_set.h"

Test(cell_set, append) {

    int input[] = {2, 3, 5, 11, 23, 47, 61};
    int size = sizeof(input)/sizeof(int);

    struct cell_set *cell_set = cell_set_init();
    for (int i=0; i<size; i++) {
        struct cell *cell = cell_init_int(input[i]);
        cell_set_append(cell_set, cell);
    }
    cell_set_print(cell_set);
    cell_set_free(cell_set);
    cr_expect(true, "ok");
}