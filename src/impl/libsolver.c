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

void solver_free(struct solver *self) {
    if (self) {
        cube_list_free(self->head);
    }
}