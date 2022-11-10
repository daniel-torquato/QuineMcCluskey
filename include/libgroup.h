/*
 * libbitset_group.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_LIBBITSET_GROUP_H_
#define INCLUDE_LIBBITSET_GROUP_H_

#include <libslot.h>

struct group {
	int length;
    int size;
	struct slot **slots;
};

struct group *group_init(int length);

void group_add(struct group *self, char *input);

void group_free(struct group *self);

void group_print(struct group *self);

struct group *bitset_group_resolve(struct group *self);

struct group *bitset_group_create_rank(struct group *self, int rank);

#endif /* INCLUDE_LIBBITSET_GROUP_H_ */
