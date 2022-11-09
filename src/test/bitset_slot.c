//
// Created by daniel on 11/1/22.
//
#include <criterion/criterion.h>
#include <string.h>
#include "libbitset_slot.h"
#include "libint_handler.h"
#include "libcell.h"

Test(bitset_slot, init) {
    struct bitset_slot *slot = bitset_slot_init(-1);
    cr_expect(slot != NULL, "slot is wrong");
    cr_expect(slot->rank == -1, "rank is wrong for");
    cr_expect(slot->head == NULL, "cells is wrong");
    cr_expect(slot->tail == NULL, "cells is wrong");
    bitset_slot_free(slot);
}

Test(bitset_slot, append) {
    int test_input[] = {11, 8, 12, 1024, 2048};
    int test_output[] = {3, 1, 2, 1, 1};
    for (int i=0; i<sizeof(test_input)/sizeof(int); i++) {
        int test = test_input[i];
        char *input = int_to_char_array(test);
        int rank = count_ones(input);
        struct bitset_slot *slot = bitset_slot_init(rank);
        bitset_slot_append(slot, input);
        cr_expect(slot != NULL, "slot is wrong");
        cr_expect(slot->rank == test_output[i], "rank is wrong for %d", i);
        cr_expect(slot->head != NULL, "cells is wrong");
        cr_expect(slot->size == 1, "size is wrong");
        cr_expect(slot->head != NULL, "head is wrong");
        cr_expect(slot->tail != NULL, "tail is wrong");
        cr_expect(slot->head == slot->tail, "head != tail in cells");
        struct cell *under_test_word = cell_init(input, false);
        cr_expect(cell_compare(slot->head->val, under_test_word) == 0, "val is wrong");
        cell_free(under_test_word, false);
        bitset_slot_free(slot);
    }
}


Test(bitset_slot, merge) {
    int input_a[] = {1,2,4, 8, 64};
    int input_b[] = {3,5,6, 9, 48};
    char *output[] = {"X1", "X01", "X001", "1X", "X10", "10X", "1X0", "100X"};

    struct bitset_slot *bitset_a = bitset_slot_init(0);
    struct bitset_slot *bitset_b = bitset_slot_init(0);

    int size_a = sizeof(input_a)/sizeof(int);
    int size_b = sizeof(input_b)/sizeof(int);
    int size_output = sizeof(output)/sizeof(char *);

    for (int i=0; i<size_a; i++)
        bitset_slot_append(bitset_a, int_to_char_array(input_a[i]));
    cr_expect(bitset_a != NULL, "wrong bitset_a");
    cr_expect(bitset_a->head != NULL, "wrong bitset_a cells head");
    bitset_a->rank = cell_ones( bitset_a->head->val);

    for (int i=0; i<size_b; i++)
        bitset_slot_append(bitset_b, int_to_char_array(input_b[i]));
    cr_expect(bitset_b != NULL, "wrong bitset_a");
    cr_expect(bitset_b->head != NULL, "wrong bitset_a cells head");
    bitset_b->rank = cell_ones( bitset_b->head->val);

    struct bitset_slot *merged = bitset_slot_merge(bitset_a, bitset_b);
    cr_expect(merged != NULL, "wrong merge");
    struct cell_list *walker = merged->head;
    for (int i=0; i<size_output && walker; i++, walker = walker->next) {
        struct cell *tmp_cell = cell_init(output[i], false);

        cr_expect(cell_compare(walker->val, tmp_cell) == 0, "wrong output_a at %d", i);

        cell_free(tmp_cell, false);
    }

    bitset_slot_free(merged);
    bitset_slot_free(bitset_a);
    bitset_slot_free(bitset_b);
}
