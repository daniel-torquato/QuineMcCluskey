/*
 * libchar_array_list.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_LIBCHAR_ARRAY_LIST_H_
#define INCLUDE_LIBCHAR_ARRAY_LIST_H_

#include <libchar_list.h>

struct char_array_list {
	int size;
	struct char_list *head;
	struct char_list *tail;
};

void char_array_list_append (struct char_array_list *self, char *input) ;
void char_array_list_free (struct char_array_list *self);
void char_array_list_print(struct char_array_list *self);

#endif /* INCLUDE_LIBCHAR_ARRAY_LIST_H_ */
