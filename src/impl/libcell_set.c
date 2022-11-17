//
// Created by daniel on 11/15/22.
//
#include <malloc.h>
#include "libcell_set.h"

struct cell_set *cell_set_init() {
    struct cell_set *output = (struct cell_set *) malloc(sizeof(struct cell_set));
    output->val = NULL;
    output->left = NULL;
    output->right = NULL;
    return output;
}

void cell_set_append(struct cell_set *self, struct cell *input) {
    if (self && input) {
        struct cell_set *walker = self ;
        int test;
        do {
            if (walker->val) {
                test = cell_compare(walker->val, input);
                if (test < 0) {
                    if (walker->right == NULL)
                        walker->right = cell_set_init();
                    walker = walker->right;
                } else if (test > 0) {
                    if (walker->left == NULL)
                        walker->left = cell_set_init();
                    walker = walker->left;
                }
            } else {
                walker->val = input;
                test = 0;
            }
        } while (test != 0 && walker);
    }
}

void cell_set_print(struct cell_set *self) {
    if (self) {
        cell_set_print_recursive(self);
        printf("\n");
    }
}

void cell_set_print_recursive(struct cell_set *self) {
    if (self) {
        cell_set_print_recursive(self->left);
        cell_print(self->val);
        printf(" ");
        cell_set_print_recursive(self->right);
    }
}

struct cell_set *cell_set_merge(struct cell_set *a, struct cell_set *b) {
    static struct cell_set *output = NULL;
    if (a && b) {
        output = cell_set_init();
        cell_set_merge_recursive(a, b, output);
        if (output->val == NULL) {
            cell_set_free(output);
        }
    }
    return output;
}

void cell_set_merge_recursive(struct cell_set *a, struct cell_set *b, struct cell_set *output) {
    if (a && b && output) {
        cell_set_merge_recursive(a, b->left, output);
        cell_set_merge_cell_recursive(a, b->val, output);
        cell_set_merge_recursive(a, b->right, output);
    }
}

void cell_set_append_cell_set(struct cell_set *self, struct cell_set *input) {
    if (self && input) {
        cell_set_append_cell_set(self, input->left);
        cell_set_append(self, input->val);
        cell_set_append_cell_set(self, input->right);
    }
}

struct cell_set *cell_set_merge_cell(struct cell_set *self, struct cell *input) {
    struct cell_set *output = cell_set_init();
    cell_set_merge_cell_recursive(self, input, output);
    if(output->val == NULL) {
        cell_set_free(output);
        output = NULL;
    }
    return output;
}

void cell_set_merge_cell_recursive(struct cell_set *self, struct cell *input, struct cell_set *output) {
    if (self && input && output) {
        struct cell *merged = cell_merge(self->val, input);
        if (merged) {
            cell_set_append(output, merged);
        }
        cell_set_merge_cell_recursive(self->left, input, output);
        cell_set_merge_cell_recursive(self->right, input, output);
    }
}

void cell_set_free(struct cell_set *self) {
    if(self) {
        cell_set_free(self->left);
        cell_set_free(self->right);
        if (self->val)
            cell_free(self->val, true);
        free(self);
    }
}