//
// Created by daniel on 11/18/22.
//
#include <malloc.h>
#include "libcell_buffer.h"

struct cell_buffer *cell_buffer_init() {
    struct cell_buffer *output = (struct cell_buffer *) malloc(sizeof(struct cell_buffer));
    output->head = NULL;
    output->tail = NULL;
    return output;
}

void cell_buffer_append(struct cell_buffer *self, struct cell *input) {
    if (self && input) {
        if (self->tail) {
            struct cell_list *new = cell_list_init();
            new->val = input;
            self->tail->next = new;
            self->tail = new;
        } else {
            self->head = cell_list_init();
            self->tail = self->head;
            self->head->val = input;
        }
    }
}

void cell_buffer_print(struct cell_buffer *self) {
    if (self) {
        cell_list_print(self->head);
    }
}

void cell_buffer_free(struct cell_buffer *self) {
    if (self) {
        cell_list_free(self->head);
        free(self);
    }
}