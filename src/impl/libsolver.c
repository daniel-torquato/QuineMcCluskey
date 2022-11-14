//
// Created by daniel on 11/14/22.
//
#include <malloc.h>
#include "libsolver.h"

struct solver *solver_init() {
    struct solver *output = (struct solver *) malloc(sizeof(struct solver));
    output->head = NULL;
    output->tail = NULL;
    output->size = 0;
    return output;
}

void solver_append(struct solver *self, struct cube *input) {
    if (self) {
        struct cube_list *new = (struct cube_list *) malloc (sizeof(struct cube_list));
        self->size++;
        new->val = input;
        new->next = NULL;
        if (self->tail) {
            self->tail->next = new;
            self->tail = new;
        } else {
            self->size = 1;
            self->head = new;
            self->tail = new;
        }
    }
}

void solver_print(struct solver *self) {
    if (self) {
        cube_list_print(self->head);
    }
}

void solver_free(struct solver *self) {
    if (self) {
        cube_list_free(self->head);
    }
}