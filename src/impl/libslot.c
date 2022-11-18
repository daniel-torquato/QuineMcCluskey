//
// Created by daniel on 11/1/22.
//
#include <stdio.h>
#include <libslot.h>
#include <malloc.h>
#include "libcell.h"
#include "libcell_set.h"

struct slot *slot_init(int rank) {
    struct slot *output = (struct slot *) malloc(sizeof(struct slot));
    output->rank = rank;
    output->val = NULL;
    return output;
}

void slot_append(struct slot *self, struct cell *input) {
    if (self) {
        if (self->val == NULL)
            self->val = cell_set_init();
        cell_set_append(self->val, input);
    }
}

void slot_append_slot(struct slot *self, struct slot *input) {
    if (self && input) {
        cell_set_append_cell_set(self->val, input->val);
    }
}

void  slot_print(struct slot *self) {
    if (self) {
        printf("%d: ", self->rank);
        cell_set_print(self->val);
    }
}

struct slot *slot_merge(struct slot *a, struct slot *b) {
    struct slot *output = NULL;
    if (a && b) {
        struct cell_set *merged = cell_set_merge(a->val, b->val);
        if (merged) {
            output = slot_init(a->rank);
            output->val = merged;
        }
    }
    return output;
}

void slot_free(struct slot *self) {
    if (self) {
        cell_set_free(self->val);
        free (self);
    }
}