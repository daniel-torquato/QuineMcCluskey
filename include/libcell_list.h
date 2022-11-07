/*
 * libcell_list.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_LIBCELL_LIST_H_
#define INCLUDE_LIBCELL_LIST_H_

#include <libchar_list.h>

struct cell_list {
	int size;
	struct char_list *head;
	struct char_list *tail;
};

struct cell_list *cell_list_init(void);
struct pair *cell_list_merge (struct cell_list *a, struct cell_list *b);
void cell_list_append (struct cell_list *self, char *input) ;
void cell_list_add (struct cell_list *self, char *input) ;
void cell_list_free (struct cell_list *self);
void cell_list_print(struct cell_list *self);

#endif /* INCLUDE_LIBCELL_LIST_H_ */
