//
// Created by daniel on 11/1/22.
//

#include <criterion/criterion.h>
#include "libchar_array_list.h"
#include "libint_handler.h"

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

    int input_a[] = {0,1,2, 4};
    int input_b[] = {0,1,2, 4};
    char *outputs[] = {"0", "X", "X0", "X00", "X", "1", "X0", "10", "X00", "100"};

    struct char_array_list *input_a_list = char_array_list_init();
    struct char_array_list *input_b_list = char_array_list_init();

    int size_a = sizeof(input_a)/sizeof(int), size_b = sizeof(input_b)/sizeof(int);
    int size_output = sizeof(outputs)/sizeof(char*);

    for (int i=0; i<size_a; i++) {
        char_array_list_append(input_a_list, int_to_char_array(input_a[i]));
    }

    for (int i=0; i<size_b; i++) {
        char_array_list_append(input_b_list, int_to_char_array(input_b[i]));
    }


    struct char_array_list *merged = char_array_list_compare_bits(input_a_list, input_b_list);
    cr_expect(merged != NULL, "merge is wrong");
    cr_expect(merged->size == size_output, "size is wrong");
    int output_idx = 0;
    for (struct char_list *walker = merged->head; walker; walker = walker->next) {
        cr_expect(strcmp(walker->val, outputs[output_idx]) == 0, "wrong merge at %d", output_idx);
        output_idx++;
    }
    char_array_list_free(input_a_list);
    char_array_list_free(input_b_list);
}