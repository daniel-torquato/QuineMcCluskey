/*
 * libCELL_LIST.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_CELL_LIST_H_
#define INCLUDE_CELL_LIST_H_

/*
 * test
 */
struct cell_list {
	struct cell *val;
	struct cell_list *next;
};

struct cell_list *cell_list_init();
struct cell_list *cell_list_init_array(int *array, int size);
struct cell_list *cell_list_merge(struct cell_list *a, struct cell_list *b);
void cell_list_free (struct cell_list *self);
void cell_list_print(struct cell_list *self);
int cell_list_size(struct cell_list *self);

#endif /* INCLUDE_CELL_LIST_H_ */
