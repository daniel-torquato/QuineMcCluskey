//
// Created by daniel on 10/30/22.
//

#ifndef INCLUDE_SLOT_H_
#define INCLUDE_SLOT_H_

#include "libcell_set.h"

struct slot {
    int rank;
    struct cell_set *val;
};

struct slot *slot_init(int rank);

struct slot *slot_merge(struct slot *a, struct slot *b);

void slot_append(struct slot *self, struct cell *input);

void slot_append_slot(struct slot *self, struct slot *input);

void  slot_print(struct slot *self);

void slot_free(struct slot *self);

#endif //INCLUDE_SLOT_H_
