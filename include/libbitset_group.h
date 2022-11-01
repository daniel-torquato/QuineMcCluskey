/*
 * libbitset_group.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_LIBBITSET_GROUP_H_
#define INCLUDE_LIBBITSET_GROUP_H_

#include <libbitset_slot.h>

struct bitset_group {
	struct bitset_slot *slot;
	struct bitset_group *next;
};

struct bitset_group *bitset_group_init();

void bitset_group_add(struct bitset_group *self, char *input);

void bitset_group_free(struct bitset_group *self);

void bitset_group_print(struct bitset_group *self);

struct bitset_group *bitset_group_create_rank(struct bitset_group *self, int rank);

#endif /* INCLUDE_LIBBITSET_GROUP_H_ */
