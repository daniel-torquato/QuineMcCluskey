//
// Created by daniel on 11/1/22.
//
#include <stdio.h>
#include <libslot.h>
#include <string.h>
#include "libbitset_array.h"
#include "libcell.h"

struct slot *slot_init(int rank) {
    struct slot *output = (struct slot *) malloc(sizeof(struct slot));
    output->rank = rank;
    output->head = NULL;
    output->tail = NULL;
    return output;
}

void slot_append(struct slot *self, struct cell *input) {
    if (self) {
        struct cell_list *new = (struct cell_list *) malloc (sizeof(struct cell_list));
        self->size++;
        new->val = input;
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

void  slot_print(struct slot *self) {
    if (self) {
        printf("%d: ", self->rank);
        cell_list_print(self->head);
    }
}

struct slot *slot_merge(struct slot *a, struct slot *b) {
    struct slot *output = NULL;
    if (a && b) {
        struct cell_list *merged = cell_list_merge(a->head, b->head);
        if (merged) {
            output = slot_init(a->rank);
            output->head = merged;
            output->size = cell_list_size(output->head);
        }
    }
    return output;
}

void slot_free(struct slot *self) {
    if (self) {
        cell_list_free(self->head);
        free (self);
    }
}