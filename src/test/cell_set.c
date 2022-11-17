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

Test(cell_set, append_cell_set) {
    int input_a[] = {1,2,4, 8, 64};
    int input_b[] = {3,5,6, 9, 48};
    int size_a = sizeof(input_a)/sizeof(int);
    int size_b = sizeof(input_b)/sizeof(int);

    struct cell_set *cell_set_a = cell_set_init();
    for (int i=0; i<size_a; i++) {
        struct cell *cell = cell_init_int(input_a[i]);
        cell_set_append(cell_set_a, cell);
    }

    struct cell_set *cell_set_b = cell_set_init();
    for (int i=0; i<size_b; i++) {
        struct cell *cell = cell_init_int(input_b[i]);
        cell_set_append(cell_set_b, cell);
    }

    struct cell_set *combined = cell_set_init();

    cell_set_print(cell_set_a);
    cell_set_print(cell_set_b);
    cell_set_append_cell_set(combined, cell_set_a);
    cell_set_append_cell_set(combined, cell_set_b);
    cell_set_print(combined);

    cell_set_free(cell_set_a);
    cell_set_free(cell_set_b);
    cr_expect(true, "ok");
}

Test(cell_set, merge) {
    int input_a[] = {1,2,4, 8, 64};
    int input_b[] = {3,5,6, 9, 48};
    int size_a = sizeof(input_a)/sizeof(int);
    int size_b = sizeof(input_b)/sizeof(int);

    struct cell_set *cell_set_a = cell_set_init();
    for (int i=0; i<size_a; i++) {
        struct cell *cell = cell_init_int(input_a[i]);
        cell_set_append(cell_set_a, cell);
    }

    struct cell_set *cell_set_b = cell_set_init();
    for (int i=0; i<size_b; i++) {
        struct cell *cell = cell_init_int(input_b[i]);
        cell_set_append(cell_set_b, cell);
    }

    struct cell_set *merged = cell_set_merge(cell_set_a, cell_set_b);

    cr_log_warn("cell_set_merge");
    cell_set_print(cell_set_a);
    cell_set_print(cell_set_b);
    cell_set_print(merged);

    cell_set_free(merged);
    cell_set_free(cell_set_a);
    cell_set_free(cell_set_b);
    cr_expect(true, "ok");
}