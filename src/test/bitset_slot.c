//
// Created by daniel on 11/1/22.
//
#include <criterion/criterion.h>
#include <string.h>
#include "libbitset_slot.h"
#include "libint_handler.h"
#include "libpair.h"

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
        cr_expect(strcmp(slot->head->val, input) == 0, "val is wrong");
        bitset_slot_free(slot);
    }
}


Test(bitset_slot, merge) {
    int input_a[] = {1,2,4, 8, 64};
    int input_b[] = {3,5,6, 9, 48};
    char *output_a[] = {"X1", "X01", "X001", "1X", "X10", "10X", "1X0", "100X","1000000"};
    char *output_b[] = {"110000"};

    struct bitset_slot *bitset_a = bitset_slot_init(0);
    struct bitset_slot *bitset_b = bitset_slot_init(0);

    int size_a = sizeof(input_a)/sizeof(int);
    int size_output_a = sizeof(output_a)/sizeof(char *);
    int size_b = sizeof(input_b)/sizeof(int);
    int size_output_b = sizeof(output_b)/sizeof(char *);

    for (int i=0; i<size_a; i++)
        bitset_slot_append(bitset_a, int_to_char_array(input_a[i]));
    cr_expect(bitset_a != NULL, "wrong bitset_a");
    cr_expect(bitset_a->head != NULL, "wrong bitset_a cells head");
    bitset_a->rank = count_ones( bitset_a->head->val);

    for (int i=0; i<size_b; i++)
        bitset_slot_append(bitset_b, int_to_char_array(input_b[i]));
    cr_expect(bitset_b != NULL, "wrong bitset_b");
    cr_expect(bitset_b->head != NULL, "wrong bitset_b cells head");
    bitset_b->rank = count_ones(bitset_b->head->val);

    struct pair *merged_pair = bitset_slot_merge(bitset_a, bitset_b);
    cr_expect(merged_pair != NULL, "wrong merge");
    cr_expect(merged_pair->first != NULL, "wrong first pair");
    cr_expect(merged_pair->second != NULL, "wrong second pair");
    struct bitset_slot *merged_a = (struct bitset_slot *) merged_pair->first;
    struct bitset_slot *merged_b = (struct bitset_slot *) merged_pair->second;

    struct char_list *walker = merged_a->head;
    for (int i=0; i<size_output_a && walker; i++, walker = walker->next) {
        cr_expect(strcmp(walker->val, output_a[i]) == 0, "wrong output_a at %d", i);
    }
    walker = merged_b->head;
    for (int i=0; i<size_output_b && walker; i++, walker = walker->next) {
        cr_expect(strcmp(walker->val, output_b[i]) == 0, "wrong output_b at %d", i);
    }

    pair_free(merged_pair);
    bitset_slot_free(merged_a);
    bitset_slot_free(merged_b);
    bitset_slot_free(bitset_a);
    bitset_slot_free(bitset_b);
}
