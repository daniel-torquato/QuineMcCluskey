/*
 * libchar_array_list.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <libchar_array_list.h>
#include <libint_handler.h>
#include <stdlib.h>
#include <string.h>
#include "libpair.h"
#include "libbitset_array.h"

struct char_array_list *char_array_list_init(void) {
	struct char_array_list *output = (struct char_array_list *) malloc(sizeof(struct char_array_list));
	output->size = 0;
	output->head = NULL;
	output->tail = NULL;
	return output;
}

/*
 * Append string to array list
 */
void char_array_list_append (struct char_array_list *self, char *input) {
	if (!self)
		return;
	struct char_list *new = (struct char_list *) malloc (sizeof(struct char_list));
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

void char_array_list_add (struct char_array_list *self, char *input) {
    char_array_list_append(self, strdup(input));
}

void char_array_list_free (struct char_array_list *self) {
	if (self) {
		char_list_free(self->head);
		self->head = NULL;
		self->tail = NULL;
		free(self);
	}
}

void char_array_list_print(struct char_array_list *self) {
	if (self) {
		char_list_print(self->head);
	}
}

struct pair *char_array_list_merge (struct char_array_list *a, struct char_array_list *b) {
	if (!a || !b)
		return NULL;
    struct char_array_list *first = char_array_list_init();
    struct char_array_list *second = char_array_list_init();
	struct pair *output = pair_init((void *) first, (void *) second);

    int rank_first = 0;
    if (a->head)
        rank_first = count_ones(a->head->val);

    struct bitset_array *check_a = bitset_array_init(a->size);
    struct bitset_array *check_b = bitset_array_init(b->size);

    int index_a = 0;
	for (struct char_list *walker_a = a->head; walker_a && index_a < a->size; walker_a = walker_a->next, index_a++) {
        int index_b = 0;
		for (struct char_list *walker_b = b->head; walker_b && index_b < b->size; walker_b = walker_b->next, index_b++) {
            char *merged = compare_bits(walker_a->val, walker_b->val);
            if (merged) {
                bitset_array_set(check_a, index_a, true);
                bitset_array_set(check_b, index_b, true);
                char_array_list_append(count_ones(merged) == rank_first ? first : second, merged);

            }
		}

	}
    static struct char_list *walker;
    walker = a->head;
    for (int i = 0; i < a->size && walker; i++, walker = walker->next) {
        if (!bitset_array_get(check_a, i)) {
            char_array_list_add((struct char_array_list*) output->first, walker->val);
        }
    }
    walker = b->head;
    for (int i = 0; i < b->size && walker; i++, walker = walker->next) {
        if (!bitset_array_get(check_b, i)) {
            char_array_list_add((struct char_array_list*) output->second, walker->val);
        }
    }

    bitset_array_free(check_a);
    bitset_array_free(check_b);
	return output;
}


