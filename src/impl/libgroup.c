/*
 * libbitset_group.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include <libgroup.h>
#include <libint_handler.h>

struct group *group_init(int length) {
	struct group *output = (struct group*) malloc(sizeof(struct group));
    output->length = length;
    output->size = 0;
    output->slots = NULL;
    if (length) {
        output->slots = (struct slot **) calloc(sizeof(struct slot *) , length);
    }
	return output;
}

/*
 * Append new integer [input] to group
 */
void group_append(struct group *self, struct slot *input) {
    if (self && input) {
        if (self->slots && input->head) {
            if (self->slots[input->rank] == NULL) {
                self->size++;
                self->slots[input->rank] = input;
            }
            else {
                self->size += input->size;
                self->slots[input->rank]->tail->next = input->head;
            }
        }
    }
}

struct group *bitset_group_resolve(struct group *self) {
    struct group *output = NULL;
    if (self) {
        output = group_init(self->length - 1);
        for (int i=0; i<self->length-1; i++) {
            if (self->slots[i] && self->slots[i+1]) {
                static struct slot *merged = NULL;
                merged = slot_merge(self->slots[i], self->slots[i + 1]);
                if (merged) {
                    output->size++;
                    output->slots[i] = merged;
                }
            }
        }
    }
    return output;
}

void group_free(struct group *self) {
	if (self) {
        for (int i=0; i<self->length; i++) {
            slot_free(self->slots[i]);
        }
        free(self);
    }
}

void group_print(struct group *self) {
    if (self) {
        for (int i = 0; i < self->length; i++) {
            slot_print(self->slots[i]);
        }
    }
}
