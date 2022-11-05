//
// Created by daniel on 11/1/22.
//

#include <criterion/criterion.h>
#include "libchar_array_list.h"
#include "libint_handler.h"
#include "libpair.h"

Test(char_array_list, init) {
    struct char_array_list *input = char_array_list_init();
    cr_expect(input != NULL, "input is wrong");
    cr_expect(input->size == 0, "size is wrong");
    cr_expect(input->head == NULL, "head is wrong");
    cr_expect(input->tail == NULL, "tail is wrong");
}


Test(char_array_list, append) {
    int inputs[] = {1, 3, 7, 11};
    int size = sizeof(inputs)/sizeof(int);
    struct char_array_list *list = char_array_list_init();
    for (int i=0; i<size; i++) {
        char *tmp = int_to_char_array(inputs[i]);
        char_array_list_append(list, tmp);
    }

    cr_expect(list->size == size, "size is wrong");
    struct char_list *walker = list->head;
    for (int i=0; i<size && walker; i++) {
        cr_expect(strcmp(walker->val,int_to_char_array(inputs[i])) == 0, "val is wrong at %d", i);
        walker = walker->next;
    }
    char_array_list_free(list);
}

Test(char_array_list, compare_bits) {

    int input_a[] = {1,2,4, 8, 64};
    int input_b[] = {3,5,6, 9, 48};
    char *output_a[] = {"X1", "X01", "X001", "1X", "X10", "10X", "1X0", "100X","1000000"};
    char *output_b[] = {"110000"};

    struct char_array_list *input_a_list = char_array_list_init();
    struct char_array_list *input_b_list = char_array_list_init();

    int size_a = sizeof(input_a)/sizeof(int), size_b = sizeof(input_b)/sizeof(int);
    int size_output_a = sizeof(output_a)/sizeof(char*);
    int size_output_b = sizeof(output_a)/sizeof(char*);

    for (int i=0; i<size_a; i++) {
        char_array_list_append(input_a_list, int_to_char_array(input_a[i]));
    }

    for (int i=0; i<size_b; i++) {
        char_array_list_append(input_b_list, int_to_char_array(input_b[i]));
    }

    struct pair *merged_pair = char_array_list_merge(input_a_list, input_b_list);

    cr_expect(merged_pair != NULL, "merge is wrong");
    cr_expect(merged_pair->first != NULL, "merge is wrong");
    cr_expect(merged_pair->second != NULL, "merge is wrong");
    struct char_array_list *merged_first = (struct char_array_list *) merged_pair->first;
    struct char_array_list *merged_second = (struct char_array_list *) merged_pair->second;
    cr_expect(merged_first->size == size_output_a, "size is wrong");

    int output_idx = 0;
    for (struct char_list *walker = merged_first->head; walker; walker = walker->next, output_idx++) {
        cr_expect(strcmp(walker->val, output_a[output_idx]) == 0, "wrong merge at %d", output_idx);
    }
    output_idx = 0;
    for (struct char_list *walker = merged_second->head; walker && output_idx < size_output_b; walker = walker->next, output_idx++) {
        cr_expect(strcmp(walker->val, output_b[output_idx]) == 0, "wrong merge at %d", output_idx);
    }
    pair_free(merged_pair);
    char_array_list_free(merged_first);
    char_array_list_free(merged_second);
    char_array_list_free(input_a_list);
    char_array_list_free(input_b_list);
}