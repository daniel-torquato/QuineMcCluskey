//
// Created by daniel on 11/1/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <libbitset_slot.h>
#include <libchar_array_list.h>
#include "libint_handler.h"

struct bitset_slot *bitset_slot_init(int rank) {
    struct bitset_slot *output = (struct bitset_slot *) malloc(sizeof(struct bitset_slot));
    output->rank = rank;
    output->table = NULL;
    return output;
}

void bitset_slot_append(struct bitset_slot *self, char *input) {
    if (self) {
        if (!self->table)
            self->table = char_array_list_init();
        self->rank = count_ones(input);
        char_array_list_append(self->table, input);
    }
}

void  bitset_slot_print(struct bitset_slot *self) {
    printf ("%d: ", self->rank);
    char_array_list_print(self->table);
}


void bitset_slot_free(struct bitset_slot *self) {
    if (self) {
        char_array_list_free(self->table);
        free (self);
    }
}