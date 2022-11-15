//
// Created by daniel on 11/14/22.
//

#ifndef QUINEMCCLUSKEY_LIBSOLVER_H
#define QUINEMCCLUSKEY_LIBSOLVER_H

#include "libcube_list.h"

struct solver {
    int size;
    struct cube_list *head;
    struct cube_list *tail;
};

struct solver *solver_init();

void solver_append(struct solver *self, struct cube *input);

void solver_print(struct solver *self);

void solver_resolve(struct solver *self);

void solver_free(struct solver *self);

#endif //QUINEMCCLUSKEY_LIBSOLVER_H
