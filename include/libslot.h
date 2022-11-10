//
// Created by daniel on 10/30/22.
//

#ifndef INCLUDE_SLOT_H_
#define INCLUDE_SLOT_H_

#include "libcell_list.h"

struct slot {
    int rank;
    int size;
    struct cell_list *head;
    struct cell_list *tail;
};

struct slot *slot_init(int rank);

struct slot *slot_merge(struct slot *a, struct slot *b);

void slot_append(struct slot *self, struct cell *input);

void bitset_slot_add(struct slot *self, char *input);

void  slot_print(struct slot *self);

void slot_free(struct slot *self);

#endif //INCLUDE_SLOT_H_
