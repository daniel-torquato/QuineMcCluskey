/*
 * libchar_array_list.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <libchar_array_list.h>
#include <libint_handler.h>
#include <stdlib.h>

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

struct char_array_list *char_array_list_compare_bits (struct char_array_list *a, struct char_array_list *b) {
	if (!a || !b)
		return NULL;
	struct char_array_list *output = char_array_list_init();
	for (struct char_list *walker_a = a->head; walker_a; walker_a = walker_a->next) {
		for (struct char_list *walker_b = b->head; walker_b; walker_b = walker_b->next) {
            char *merged = compare_bits(walker_a->val, walker_b->val);
            if (merged) {
                char_array_list_append(output, merged);
            }
		}
	}
	return output;
}


