//
// Created by daniel on 11/1/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <libbitset_slot.h>
#include <libchar_array_list.h>
#include "libint_handler.h"
#include "libpair.h"

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
        char_array_list_append(self->table, input);
    }
}

void  bitset_slot_print(struct bitset_slot *self) {
    if (self) {
        printf("%d: ", self->rank);
        char_array_list_print(self->table);
    }
}

struct pair *bitset_slot_merge(struct bitset_slot *a, struct bitset_slot *b) {
    struct pair *output = pair_init(NULL, NULL);
    if (a && b) {
        struct bitset_slot *first = bitset_slot_init(a->rank);
        struct bitset_slot *second = bitset_slot_init(b->rank);
        output->first = first;
        output->second = second;

        struct pair *merged = char_array_list_merge(a->table, b->table);

        first->table = (struct char_array_list *) merged->first;
        second->table = (struct char_array_list *) merged->second;

        pair_free(merged);
    } else if (a) {
        output->first = (struct bitset_slot *) a;
    } else if (b) {
        output->second = (struct bitset_slot *) b;
    }

    return output;
}

void bitset_slot_free(struct bitset_slot *self) {
    if (self) {
        char_array_list_free(self->table);
        free (self);
    }
}