//
// Created by daniel on 10/30/22.
//

#ifndef INCLUDE_LIBBITSET_SLOT_H
#define INCLUDE_LIBBITSET_SLOT_H

#include <libchar_array_list.h>

struct bitset_slot {
    int rank;
    struct char_array_list *table;
};

struct bitset_slot *bitset_slot_init(int rank);

void bitset_slot_append(struct bitset_slot *self, char *input);

void  bitset_slot_print(struct bitset_slot *self);

void bitset_slot_free(struct bitset_slot *self);

#endif //INCLUDE_LIBBITSET_SLOT_H