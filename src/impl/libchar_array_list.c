/*
 * libchar_array_list.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <libchar_array_list.h>
#include <stdlib.h>

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
	if (!self)
		return;
	char_list_free(self->head);
	self->head = NULL;
	self->tail = NULL;
	free(self);
}

void char_array_list_print(struct char_array_list *self) {
	if (!self)
		return;
	char_list_print(self->head);
}


