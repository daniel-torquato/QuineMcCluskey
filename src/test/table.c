//
// Created by daniel on 11/10/22.
//
#include <criterion/criterion.h>
#include "libtable.h"
#include "libint_handler.h"
#include "libcell.h"

Test(table_list, resolve) {
    int input[] = {2, 3, 5, 11, 23, 47, 61};
    int size_input = sizeof(input)/sizeof(int);
    int max_value = 0;
    for (int i=0; i<size_input; i++) {
        if (input[i] > max_value) {
            max_value = input[i];
        }
    }
    int base = 1;
    for (; max_value/2; max_value >>= 1) {
        base++;
    }

    struct table *input_table = table_init(base);
    for(int i=0; i<size_input; i++) {
        struct cell *cell = cell_init_int(input[i]);
        struct slot *slot = slot_init(cell_ones(cell));
        slot_append(slot, cell);
        group_append(input_table->column[0], slot);
    }
    table_resolve(input_table);
    table_print(input_table);

    table_free(input_table);

    cr_expect(true, "ok");
}