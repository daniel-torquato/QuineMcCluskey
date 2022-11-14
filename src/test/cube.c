//
// Created by daniel on 11/13/22.
//
#include <criterion/criterion.h>
#include "libcube.h"
#include "libcell.h"

Test(cube, append) {
    int input[] = {2, 3, 5, 8};
    int size = sizeof(input) / sizeof(int);

    struct cube *cube = cube_init(0);
    for (int i = 0; i < size; i++) {
        struct cell *cell = cell_init_int(input[i]);
        struct slot *slot = slot_init(cell_ones(cell));
        slot_append(slot, cell);

        struct slot_list *slot_list = slot_list_init();
        slot_list_append(slot_list, slot);

        cube_append(cube, slot_list);
    }
    struct cube *resolved = cube_resolve(cube);
    cube_print(cube);
    cube_print(resolved);
    cr_expect(resolved != NULL, "cube could not be resolved");
    cube_free(cube);
    cube_free(resolved);
}