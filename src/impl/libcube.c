//
// Created by daniel on 11/13/22.
//
#include <malloc.h>
#include "libcube.h"

struct cube *cube_init(int level) {
    struct cube *output = (struct cube *) malloc(sizeof(struct cube));
    output->level = level;
    output->head = NULL;
    output->tail = NULL;
    return output;
}

void cube_append(struct cube *self, struct slot_list *input) {
    if (self) {
        if (self->head)
            slot_list_append_slot_list(self->head, input);
        else
            self->head = input;
    }
}

struct cube *cube_resolve(struct cube *self) {
    struct cube *output = NULL;
    if (self) {
        output = cube_init(self->level+1);
        struct slot_list *merged = slot_list_resolve(self->head);
        if (merged) {
            output->size = 0;
            output->head = merged;
            // TODO: create method in slot_list to get latest element
            for (struct slot_list *walker = output->head; walker; walker = walker->next) {
                output->tail = walker;
                output->size++;
            }
        } else {
            cube_free(output);
            output = NULL;
        }
    }
    return output;
}

void cube_print(struct cube *self) {
    if (self) {
        slot_list_print(self->head);
    }
}

void cube_free(struct cube *self) {
    if (self) {
        slot_list_free(self->head);
        free(self);
    }
}