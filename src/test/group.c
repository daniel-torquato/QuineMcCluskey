//
// Created by daniel on 11/5/22.
//

#include <criterion/criterion.h>
#include <libgroup.h>
#include <libint_handler.h>
#include "libcell.h"

Test(group, resolve) {
    int input[] = {2, 3, 5, 11, 23, 47, 61};
    char *output[]={"1X", "X011", "101", "1011", "10111", "101111", "111101"};
    int input_size = sizeof(input)/sizeof(int);
    int base = 0;
    static int tmp = 1;
    for (int i=0; i<input_size; i++) {
        while (input[i] > tmp) {
            tmp <<= 1;
            base++;
        }
    }
    struct group *input_list = group_init(base);
    for (int i=0; i<input_size; i++) {
        struct cell *cell = cell_init_int(input[i]);
        struct slot *slot = slot_init(cell_ones(cell));
        slot_append(slot, cell);
        group_append(input_list, slot);
    }
    cr_expect(input_list != NULL, "wrong list");
    cr_expect(input_list->size == 7, "wrong size for %d", input_list->size);
    group_print(input_list);
    struct group *resolved = bitset_group_resolve(input_list);
    cr_expect(resolved != NULL, "wrong solution");
    //TODO: add cr_expect(resolved->size == 2, "wrong solution size of %d", resolved->size);
    group_print(resolved);

    group_free(input_list);
    group_free(resolved);
}