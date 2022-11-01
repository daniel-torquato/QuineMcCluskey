//
// Created by daniel on 11/1/22.
//

#include <criterion/criterion.h>
#include "libchar_array_list.h"

Test(char_array_list, init) {
    struct char_array_list *input = char_array_list_init();
    cr_expect(input != NULL, "input is wrong");
    cr_expect(input->size == 0, "size is wrong");
    cr_expect(input->head == NULL, "head is wrong");
    cr_expect(input->tail == NULL, "tail is wrong");
}

Test(char_array_list, free) {
    struct char_array_list *input = char_array_list_init();
    char_array_list_free(input);
    cr_expect(input == NULL, "input is wrong");
    char_array_list_free(input);
}

Test(char_array_list, append) {

    char *inputs[] = {"1", "11", "111", "1011"};
    char **outputs = inputs;
    int size = sizeof(inputs)/sizeof(char*);
    struct char_array_list *list = char_array_list_init();
    for (int i=0; i<size; i++) {
        char_array_list_append(list, inputs[i]);
    }

    cr_expect(list->size == size, "size is wrong");

    struct char_list *walker = list->head;
    for (int i=0; i<size && walker; i++) {
        cr_expect(walker->val == outputs[i], "val is wrong at %d", i);
        walker = walker->next;
    }
    char_array_list_free(list);

}

Test(char_array_list, compare_bits) {
    char *input_a[] = {"0","1","10", "100"};
    char *input_b[] = {"0","1","10", "100"};
    char *outputs[] = {"0", "X", "X0", "X00", "X", "1", "X0", "10", "X00", "100"};

    struct char_array_list *input_a_list = char_array_list_init();
    struct char_array_list *input_b_list = char_array_list_init();
    struct char_array_list *output_list = char_array_list_init();

    int size_a = sizeof(input_a)/sizeof(char*), size_b = sizeof(input_b)/sizeof(char*);
    int size_output = sizeof(outputs)/sizeof(char*);

    for (int i=0; i<size_a; i++) {
        char_array_list_append(input_a_list, input_a[i]);
    }

    for (int i=0; i<size_b; i++) {
        char_array_list_append(input_b_list, input_b[i]);
    }

    for (int i=0; i<sizeof(outputs)/sizeof(char*); i++) {
        char_array_list_append(output_list, outputs[i]);
    }

    struct char_array_list *merged = char_array_list_compare_bits(input_a_list, input_b_list);
    cr_expect(merged != NULL, "merge is wrong");
    cr_expect(merged->size == size_output, "size is wrong");
    int output_idx = 0;
    for (struct char_list *walker = merged->head, *walker_output = output_list->head;
         walker && walker_output; walker = walker->next, walker_output = walker_output->next) {
        cr_expect(strcmp(walker->val, walker_output->val) == 0, "wrong merge at %d", output_idx++);
    }
    char_array_list_free(input_a_list);
    char_array_list_free(input_b_list);
    char_array_list_free(output_list);
}