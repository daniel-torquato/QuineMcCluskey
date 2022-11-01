//
// Created by daniel on 11/1/22.
//
#include <criterion/criterion.h>
#include <string.h>
#include "libbitset_slot.h"
#include "libint_handler.h"

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
        cr_expect(slot->table != NULL, "table is wrong");
        cr_expect(slot->table->size == 1, "size is wrong");
        cr_expect(slot->table->head != NULL, "head is wrong");
        cr_expect(slot->table->tail != NULL, "tail is wrong");
        cr_expect(slot->table->head == slot->table->tail, "head != tail in table");
        cr_expect(strcmp(slot->table->head->val, input) == 0, "val is wrong");
        bitset_slot_free(slot);
    }
}

