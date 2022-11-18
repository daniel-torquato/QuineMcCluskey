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
    slot_free(slot);
}

Test(slot, append) {
    int input[] = {2, 3, 5, 11, 23, 47, 61};
    int size = sizeof(input)/sizeof(int);

    struct slot *input_slot = slot_init(0);
    cr_expect(input_slot != NULL, "wrong init");
    cr_expect(input_slot->rank == 0, "wrong rank");
    for (int i=0; i<size; i++) {
        struct cell *cell = cell_init_int(input[i]);
        slot_append(input_slot, cell);
    }
    cr_expect(input_slot->val != NULL, "wrong val");
    cr_log_warn("slot_append");

    slot_print(input_slot);
    cr_expect(true, "ok");
   slot_free(input_slot);
}
