//
// Created by daniel on 11/13/22.
//
#include <criterion/criterion.h>
#include "libslot_list.h"
#include "libcell.h"

Test(slot_list, append) {
    int input[] = {2, 3, 5, 8};
    int size = sizeof(input)/sizeof(int);

    struct slot_list *input_slot_list = slot_list_init();
    for (int i=0; i<size; i++) {
        struct cell *cell = cell_init_int(input[i]);
        struct slot *slot = slot_init(cell_ones(cell));
        slot_append(slot, cell);
        slot_list_append(input_slot_list, slot);
    }
    slot_list_print(input_slot_list);
    cr_expect(true, "ok");
    slot_list_free(input_slot_list);
}

Test(slot_list, resolve) {
    int input[] = {2, 3, 5, 11, 23, 47, 61};
    int size = sizeof(input)/sizeof(int);

    struct slot_list *input_slot_list = slot_list_init();
    for (int i=0; i<size; i++) {
        struct cell *cell = cell_init_int(input[i]);
        struct slot *slot = slot_init(cell_ones(cell));
        slot_append(slot, cell);
        slot_list_append(input_slot_list, slot);
    }
    struct slot_list *resolved = slot_list_resolve(input_slot_list);

    cr_log_warn("slot_list_resolve");
    slot_list_print(input_slot_list);
    slot_list_print(resolved);

    cr_expect(true, "ok");
    slot_list_free(input_slot_list);
    slot_list_free(resolved);
}