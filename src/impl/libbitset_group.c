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

struct bitset_group *bitset_group_init() {
	struct bitset_group *output = (struct bitset_group*) malloc(sizeof(struct bitset_group));
    output->slot = NULL;
	return output;
}

/*
 * Append new integer [input] to bitset_group
 */
void bitset_group_add(struct bitset_group *self, int input) {
    if (self) {
        int rank = count_ones(input);
        char *val = int_to_char_array(input);
        struct bitset_group *group = bitset_group_create_rank(self, rank);
        bitset_slot_append(group->slot, val);
    }
}

struct bitset_group *bitset_group_create_rank(struct bitset_group *self, int rank) {
    struct bitset_group *walker = self, *prev = self;
    struct bitset_group *output = self;
    for (; walker; prev = walker, walker = walker->next) {
        if (walker->slot && walker->slot->rank >= rank) {
            output = walker;
            break;
        }
    }
    if (walker && !walker->slot) {
        walker->slot = bitset_slot_init(rank);
        output = walker;
    }
    if (prev && (!walker || (walker->slot && walker->slot->rank > rank))) {
        if (!prev->slot) {
            prev->slot = bitset_slot_init(rank);
            output = prev;
        } else if (prev->slot->rank < rank) {
            struct bitset_group *new_group = bitset_group_init();
            struct bitset_slot *new_slot = bitset_slot_init(rank);
            new_group->slot = new_slot;
            new_group->next = prev->next;
            prev->next = new_group;
            output = new_group;
        }
    }
    return output;
}

void bitset_group_free(struct bitset_group *self) {
	if (self) {
        struct bitset_group *walker = self;
        while (walker) {
            struct bitset_group *next  = walker->next;
            bitset_slot_free(walker->slot);
            free(walker);
            walker = next;
        }
    }
}

void bitset_group_print(struct bitset_group *self) {
	for (struct bitset_group *walker = self; walker; walker = walker->next) {
        bitset_slot_print(walker->slot);
	}
}
