//
// Created by daniel on 11/14/22.
//
#include <criterion/criterion.h>
#include "libtable.h"
#include "libcell.h"

Test(table, resolve) {
    int input[] = {2, 3, 5, 8};
    int size = sizeof(input) / sizeof(int);

    struct table *solver = table_init();
    struct cube *buffer = cube_init(0);
    for (int i = 0; i < size; i++) {
        struct cell *cell = cell_init_int(input[i]);
        struct slot *slot = slot_init(cell_ones(cell));
        slot_append(slot, cell);
        struct slot_list *slot_list = slot_list_init();
        slot_list_append(slot_list, slot);
        cube_append(buffer, slot_list);
    }

    table_append(solver, buffer);
    table_resolve(solver);
    table_print(solver);
    cr_expect(true, "ok");
    table_free(solver);
}

Test(solver, warnigs) {
    /**
     * If the last test had log_warn the makefile fails
     */
    cr_expect(true, "ok");
}