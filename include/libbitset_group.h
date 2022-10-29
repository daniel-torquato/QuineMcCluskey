/*
 * libbitset_group.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_LIBBITSET_GROUP_H_
#define INCLUDE_LIBBITSET_GROUP_H_

#include <libint_handler.h>

struct bitset_group {
	int rank;
	struct char_array_list *table;
	struct bitset_group *next;
};

struct bitset_group *bitset_group_init();

void bitset_group_append(struct bitset_group *self, int input);

void bitset_group_free(struct bitset_group *self);

void bitset_group_print(struct bitset_group *self);

#endif /* INCLUDE_LIBBITSET_GROUP_H_ */