/*
 * libbitset_group.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libbitset_group.h>
#include <libchar_array_list.h>
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
        struct bitset_slot *buff = NULL;
        for (int i = 0; i < self->length-1; i++) {
            if (self->slots[i] && self->slots[i+1]) {
                static struct pair *merged = NULL;
                merged = bitset_slot_merge(self->slots[i], self->slots[i+1]);
                if (merged) {
                    if (buff) {
                        static struct pair *resolve_merge;
                        resolve_merge = bitset_slot_merge( (struct bitset_slot *) merged->first, buff);
                        if (resolve_merge) {
                            output->slots[i] = (struct bitset_slot *) resolve_merge->first;
                            bitset_slot_free(buff);
                            bitset_slot_free(merged->first);
                            bitset_slot_free(resolve_merge->second);
                            pair_free(resolve_merge);
                        }
                    } else {
                        output->slots[i] = (struct bitset_slot *) merged->first;
                    }
                    buff = (struct bitset_slot *) merged->second;
                }
                pair_free(merged);
            }
        }
        output->slots[output->length-1] = self->slots[self->length-1];
        if (buff) {
            if (buff->table) {
                output->slots[output->length - 1] = buff;
            } else
                bitset_slot_free(buff);
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
