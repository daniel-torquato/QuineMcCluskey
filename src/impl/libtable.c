//
// Created by daniel on 11/14/22.
//
#include <malloc.h>
#include "libtable.h"

struct table *table_init() {
    struct table *output = (struct table *) malloc(sizeof(struct table));
    output->head = NULL;
    output->tail = NULL;
    output->size = 0;
    return output;
}

void table_append(struct table *self, struct cube *input) {
    if (self) {
        struct cube_list *new = (struct cube_list *) malloc (sizeof(struct cube_list));
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

void table_resolve(struct table *self) {
    if (self) {
        for (struct cube_list *walker = self->head; walker; walker = walker->next) {
            struct cube *resolved = cube_resolve(walker->val);
            if (resolved) {
                table_append(self, resolved);
            }
        }
    }
}

void table_print(struct table *self) {
    if (self) {
        cube_list_print(self->head);
    }
}

void table_free(struct table *self) {
    if (self) {
        cube_list_free(self->head);
    }
}