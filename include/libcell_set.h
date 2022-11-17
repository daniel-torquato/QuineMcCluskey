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

struct cell_set *cell_set_merge(struct cell_set *a, struct cell_set *b);

void cell_set_merge_recursive(struct cell_set *a, struct cell_set *b, struct cell_set *output);

struct cell_set *cell_set_merge_cell(struct cell_set *self, struct cell *input);

void cell_set_merge_cell_recursive(struct cell_set *self, struct cell *input, struct cell_set *output);

void cell_set_append(struct cell_set *self, struct cell *input);

void cell_set_append_cell_set(struct cell_set *self, struct cell_set *input);

void cell_set_print(struct cell_set *self);

void cell_set_print_recursive(struct cell_set *self);

void cell_set_free(struct cell_set *self);

#endif //QUINEMCCLUSKEY_LIBCELL_TREE_H
