/*
 * libarray_list.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <libarray_list.h>

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void array_list_append (struct array_list *self, int val) {
	if (!self)
		return;
	struct list *new = (struct list *) malloc (sizeof(struct list));
	self->size++;
	new->val = val;
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

struct array_list *array_list_init (int size, int default_value) {
	struct array_list *ret = (struct array_list*) malloc(sizeof(struct array_list));
	ret->size = size;
	ret->head = NULL;
	ret->tail = NULL;
	for (int i=0; i<size; i++) {
		array_list_append(ret, default_value);
	}
	return ret;
}

void array_list_print (struct array_list *self) {
	struct list *walker;
	walker = self->head;
	while (walker) {
		printf("%d->", walker->val);
		walker = walker->next;
	}
	printf("NULL");
}

void array_list_free (struct array_list *array) {
	if (!array)
		return;
	struct list *walker = array->head;
	while (walker) {
		struct list *next = walker->next;
		free(walker);
		walker = next;
	}
	free(array);
}
