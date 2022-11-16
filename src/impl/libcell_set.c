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
                    if (walker->right)
                        walker = walker->right;
                    else {
                        walker->right = cell_set_init();
                        walker->right->val = input;
                        test = 0;
                    }
                } else if (test > 0) {
                    if (walker->left)
                        walker = walker->left;
                    else {
                        walker->left = cell_set_init();
                        walker->left->val = input;
                        test = 0;
                    }
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
        cell_set_print(self->left);
        cell_print(self->val);
        printf(" ");
        cell_set_print(self->right);
    }
}

void cell_set_free(struct cell_set *self) {
    if(self) {
        cell_set_free(self->left);
        cell_set_free(self->right);
        cell_free(self->val, true);
        free(self);
    }
}