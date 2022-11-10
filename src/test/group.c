//
// Created by daniel on 11/5/22.
//

#include <criterion/criterion.h>
#include <libgroup.h>
#include <libint_handler.h>

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
        group_add(input_list, int_to_char_array(input[i]));
    }
    cr_expect(input_list != NULL, "wrong list");
    cr_expect(input_list->size == 5, "wrong size");
    group_print(input_list);
    struct group *resolved = bitset_group_resolve(input_list);
    cr_expect(resolved != NULL, "wrong solution");
    //TODO: add cr_expect(resolved->size == 2, "wrong solution size of %d", resolved->size);
    group_print(resolved);

    group_free(input_list);
    group_free(resolved);
}