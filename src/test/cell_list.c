//
// Created by daniel on 11/8/22.
//
#include <criterion/criterion.h>
#include "libcell_list.h"
#include "libcell.h"

Test(cell_list, merge) {
    int input_a[] = {1,2,4, 8, 64};
    int input_b[] = {3,5,6, 9, 48};
    char *output[] = {"X1", "X01", "X001", "1X", "X10", "10X", "1X0", "100X"};
    int size_a = sizeof(input_a)/sizeof(int);
    int size_b = sizeof(input_b)/sizeof(int);
    int size_output = sizeof(output)/sizeof(int);

    struct cell_list *list_a = cell_list_init_array(input_a, size_a);
    struct cell_list *list_b = cell_list_init_array(input_b, size_b);
    struct cell_list *merged  = cell_list_merge(list_a, list_b);
    struct cell_list *walker = merged;
    for (int i=0; i<size_output && walker; i++) {
        cr_expect(strcmp(walker->val->word, output[i]) == 0, "wrong word at %d", i);
        walker = walker->next;
    }
    cell_list_free(merged);
    cell_list_free(list_a);
    cell_list_free(list_b);
}