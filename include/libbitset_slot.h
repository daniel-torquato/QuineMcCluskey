//
// Created by daniel on 10/30/22.
//

#ifndef INCLUDE_LIBBITSET_SLOT_H
#define INCLUDE_LIBBITSET_SLOT_H

#include "libcell_list.h"

struct bitset_slot {
    int rank;
    struct cell_list *cells;
};

struct bitset_slot *bitset_slot_init(int rank);

struct pair *bitset_slot_merge(struct bitset_slot *a, struct bitset_slot *b);

void bitset_slot_append(struct bitset_slot *self, char *input);

void  bitset_slot_print(struct bitset_slot *self);

void bitset_slot_free(struct bitset_slot *self);

#endif //INCLUDE_LIBBITSET_SLOT_H
