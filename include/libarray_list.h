/*
 * libarray.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_LIBARRAY_LIST_H_
#define INCLUDE_LIBARRAY_LIST_H_

struct list {
	int val;
	struct list *next;
};

struct array_list {
	int size;
	struct list *head;
	struct list *tail;
};


void array_list_append (struct array_list *self, int val);
struct array_list *array_list_init (int size, int default_value);
void array_list_print (struct array_list *self);
void array_list_free (struct array_list *array);

#endif /* INCLUDE_LIBARRAY_LIST_H_ */
