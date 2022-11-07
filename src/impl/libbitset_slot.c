//
// Created by daniel on 11/1/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <libbitset_slot.h>
#include "libcell_list.h"
#include "libint_handler.h"
#include "libpair.h"

struct bitset_slot *bitset_slot_init(int rank) {
    struct bitset_slot *output = (struct bitset_slot *) malloc(sizeof(struct bitset_slot));
    output->rank = rank;
    output->cells = NULL;
    return output;
}

void bitset_slot_append(struct bitset_slot *self, char *input) {
    if (self) {
        if (!self->cells)
            self->cells = cell_list_init();
        cell_list_append(self->cells, input);
    }
}

void  bitset_slot_print(struct bitset_slot *self) {
    if (self) {
        printf("%d: ", self->rank);
        cell_list_print(self->cells);
    }
}

struct pair *bitset_slot_merge(struct bitset_slot *a, struct bitset_slot *b) {

    struct bitset_slot *first = bitset_slot_init(a->rank);
    struct bitset_slot *second = bitset_slot_init(b->rank);
    struct pair *output = pair_init(first, second);

    struct pair *merged = cell_list_merge(a->cells, b->cells);

    first->cells = (struct cell_list *) merged->first;
    second->cells = (struct cell_list *) merged->second;

    pair_free(merged);

    return output;
}

void bitset_slot_free(struct bitset_slot *self) {
    if (self) {
        cell_list_free(self->cells);
        free (self);
    }
}