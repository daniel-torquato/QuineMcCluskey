//
// Created by daniel on 11/1/22.
//
#include <criterion/criterion.h>
#include <string.h>
#include "libbitset_slot.h"
#include "libint_handler.h"

Test(bitset_slot, append) {
    struct bitset_slot *slot = bitset_slot_init(0);
    char *num = int_to_char_array(11);
    bitset_slot_append(slot, num);
    cr_expect(slot != NULL, "slot is wrong");
    cr_expect(slot->rank == 3, "rank is wrong");
    cr_expect(slot->table != NULL, "table is wrong");
    cr_expect(slot->table->size == 1, "size is wrong");
    cr_expect(slot->table->head != NULL, "head is wrong");
    cr_expect(slot->table->tail != NULL, "tail is wrong");
    cr_expect(slot->table->head == slot->table->tail, "head != tail in table");
    cr_expect(strcmp(slot->table->head->val, num) == 0, "val is wrong");
    bitset_slot_free(slot);
}

