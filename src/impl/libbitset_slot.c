//
// Created by daniel on 11/1/22.
//
#include <stdio.h>
#include <libbitset_slot.h>
#include <string.h>
#include "libpair.h"
#include "libbitset_array.h"
#include "libcell.h"

struct bitset_slot *bitset_slot_init(int rank) {
    struct bitset_slot *output = (struct bitset_slot *) malloc(sizeof(struct bitset_slot));
    output->rank = rank;
    output->head = NULL;
    output->tail = NULL;
    return output;
}

void bitset_slot_append(struct bitset_slot *self, char *input) {
    if (self) {
        struct cell_list *new = (struct cell_list *) malloc (sizeof(struct cell_list));
        self->size++;
        new->val = cell_init(input, false);
        new->next = NULL;
        if (self->tail) {
            self->tail->next = new;
            self->tail = new;
        } else {
            self->size = 1;
            self->head = new;
            self->tail = new;
        }
    }
}

void bitset_slot_add(struct bitset_slot *self, char *input) {
    bitset_slot_append(self, strdup(input));
}

void  bitset_slot_print(struct bitset_slot *self) {
    if (self) {
        printf("%d: ", self->rank);
        cell_list_print(self->head);
    }
}

struct bitset_slot *bitset_slot_merge(struct bitset_slot *a, struct bitset_slot *b) {
    struct bitset_slot *output = NULL;
    if (a && b) {
        output = bitset_slot_init(a->rank);
        output->head = cell_list_merge(a->head, b->head);
        output->size = cell_list_size(output->head);
    }
    return output;
}

void bitset_slot_free(struct bitset_slot *self) {
    if (self) {
        cell_list_free(self->head);
        free (self);
    }
}