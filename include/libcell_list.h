/*
 * libCELL_LIST.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_LIBCELL_LIST_H_
#define INCLUDE_LIBCELL_LIST_H_

/*
 * test
 */
struct cell_list {
	struct cell *val;
	struct cell_list *next;
};

struct cell_list *cell_list_init();
void cell_list_free (struct cell_list *self);
void cell_list_print(struct cell_list *self);

#endif /* INCLUDE_LIBCELL_LIST_H_ */
