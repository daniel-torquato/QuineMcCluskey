//
// Created by daniel on 11/15/22.
//

#ifndef QUINEMCCLUSKEY_LIBCELL_TREE_H
#define QUINEMCCLUSKEY_LIBCELL_TREE_H

#include "libcell.h"

struct cell_set {
    struct cell *val;
    struct cell_set *left;
    struct cell_set *right;
};

struct cell_set *cell_set_init();

void cell_set_append(struct cell_set *self, struct cell *input);

void cell_set_print(struct cell_set *self);

void cell_set_free();

#endif //QUINEMCCLUSKEY_LIBCELL_TREE_H
