//
// Created by daniel on 11/1/22.
//
#include <criterion/criterion.h>
#include <string.h>
#include "libslot.h"
#include "libcell.h"

Test(slot, init) {
    struct slot *slot = slot_init(-1);
    cr_expect(slot != NULL, "slot is wrong");
    cr_expect(slot->rank == -1, "rank is wrong for");
    cr_expect(slot->head == NULL, "cells is wrong");
    cr_expect(slot->tail == NULL, "cells is wrong");
    slot_free(slot);
}

Test(slot, append) {
    int test_input[] = {11, 8, 12, 1024, 2048};
    int test_output[] = {3, 1, 2, 1, 1};
    for (int i=0; i<sizeof(test_input)/sizeof(int); i++) {
        struct cell *input_cell = cell_init_int(test_input[i]);
        struct slot *slot = slot_init(cell_ones(input_cell));
        slot_append(slot, input_cell);
        cr_expect(slot != NULL, "slot is wrong");
        cr_expect(slot->rank == test_output[i], "rank is wrong for %d", i);
        cr_expect(slot->head != NULL, "cells is wrong");
        cr_expect(slot->size == 1, "size is wrong");
        cr_expect(slot->tail != NULL, "tail is wrong");
        cr_expect(slot->head == slot->tail, "head != tail in cells");
        struct cell *under_test_word = cell_init_int(test_input[i]);
        cr_expect(cell_compare(slot->head->val, under_test_word) == 0, "val is wrong");
        cell_free(under_test_word, false);
        slot_free(slot);
    }
}


Test(slot, merge) {
    int input_a[] = {1,2,4, 8, 64};
    int input_b[] = {3,5,6, 9, 48};
    char *output[] = {"X1", "X01", "X001", "1X", "X10", "10X", "1X0", "100X"};

    struct slot *slot_a = slot_init(0);
    struct slot *slot_b = slot_init(0);

    int size_a = sizeof(input_a)/sizeof(int);
    int size_b = sizeof(input_b)/sizeof(int);
    int size_output = sizeof(output)/sizeof(char *);

    for (int i=0; i<size_a; i++) {
        struct cell *input_cell = cell_init_int(input_a[i]);
        slot_append(slot_a, input_cell);
    }

    cr_expect(slot_a != NULL, "wrong slot_a");
    cr_expect(slot_a->head != NULL, "wrong slot_a cells head");
    slot_a->rank = cell_ones(slot_a->head->val);

    for (int i=0; i<size_b; i++) {
        struct cell *input_cell = cell_init_int(input_b[i]);
        slot_append(slot_b, input_cell);
    }

    cr_expect(slot_b != NULL, "wrong slot_a");
    cr_expect(slot_b->head != NULL, "wrong slot_a cells head");
    slot_b->rank = cell_ones(slot_b->head->val);

    struct slot *merged = slot_merge(slot_a, slot_b);
    cr_expect(merged != NULL, "wrong merge");
    struct cell_list *walker = merged->head;
    for (int i=0; i<size_output && walker; i++, walker = walker->next) {
        struct cell *tmp_cell = cell_init(output[i], false);

        cr_expect(cell_compare(walker->val, tmp_cell) == 0, "wrong output_a at %d", i);

        cell_free(tmp_cell, false);
    }

    slot_free(merged);
    slot_free(slot_a);
    slot_free(slot_b);
}
