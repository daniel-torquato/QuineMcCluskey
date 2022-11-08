/*
 * libbitset_group.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include <libbitset_group.h>
#include <libint_handler.h>
#include "libpair.h"

struct bitset_group *bitset_group_init(int length) {
	struct bitset_group *output = (struct bitset_group*) malloc(sizeof(struct bitset_group));
    output->length = length;
    output->slots = NULL;
    if (length) {
        output->slots = (struct bitset_slot **) calloc(sizeof(struct bitset_slot *) , length);
    }
	return output;
}

/*
 * Append new integer [input] to bitset_group
 */
void bitset_group_add(struct bitset_group *self, char *input) {
    if (self) {
        int rank = count_ones(input);
        if (self->slots[rank] == NULL) {
            self->slots[rank] = bitset_slot_init(rank);
        }
        bitset_slot_append(self->slots[rank], input);
    }
}

struct bitset_group *bitset_group_resolve(struct bitset_group *self) {
    struct bitset_group *output = NULL;
    if (self) {
        output = bitset_group_init(self->length);
        for (int i=self->length-1; i>=1; i--) {
            if (self->slots[i] && self->slots[i-1]) {
                static struct pair *merged = NULL;
                merged = bitset_slot_merge(self->slots[i-1], self->slots[i]);
                if (merged) {
                    output->slots[i-1] = (struct bitset_slot *) merged->first;
                    if (!output->slots[i] && merged->second) {
                        output->slots[i] = (struct bitset_slot *) merged->second;
                    }
                }
                pair_free(merged);
            }
        }
    }
    return output;
}

void bitset_group_free(struct bitset_group *self) {
	if (self) {
        for (int i=0; i<self->length; i++) {
            bitset_slot_free(self->slots[i]);
        }
    }
}

void bitset_group_print(struct bitset_group *self) {
    if (self) {
        for (int i = 0; i < self->length; i++) {
            bitset_slot_print(self->slots[i]);
        }
    }
}
