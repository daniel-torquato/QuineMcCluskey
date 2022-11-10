/*
 * libbitset_group.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <libslot.h>

struct group {
	int length;
    int size;
	struct slot **slots;
};

struct group *group_init(int length);

void group_append(struct group *self, struct slot *input);

void group_free(struct group *self);

void group_print(struct group *self);

struct group *bitset_group_resolve(struct group *self);

struct group *bitset_group_create_rank(struct group *self, int rank);

#endif /* INCLUDE_GROUP_H_ */
