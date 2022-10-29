/*
 * libbitset_group.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdlib.h>
#include <stdbool.h>
#include <libbitset_group.h>
#include <libchar_array_list.h>
#include <libint_handler.h>

struct bitset_group *bitset_group_init() {
	struct bitset_group *output = (struct bitset_group*) malloc(sizeof(struct bitset_group));
	output->table = NULL;
	return output;
}

/*
 * Append new integer [input] to bitset_group
 */
void bitset_group_append(struct bitset_group *self, int input) {
	int rank = count_ones(input);

	char *val = int_to_char_array(input);

	bool added = false;
	struct bitset_group *walker = self, *prev = self;
	while (walker) {
		if (walker->rank == rank) {
			char_array_list_append(walker->table, val);
			added = true;
			break;
		} else if (walker->rank > rank) {
			struct bitset_group *new = (struct bitset_group *) malloc(sizeof(struct bitset_group));
			new->rank = rank;
			char_array_list_append(new, val);
			if (prev) {
				new->next = prev->next;
				prev->next = new;
			}
			added = true;
			break;
		}
		prev = walker;
		walker = walker->next;
	}
	if (!added) {
		struct bitset_group *new = (struct bitset_group *) malloc(sizeof(struct bitset_group));

		if (prev) {

		}
	}
}

void bitset_group_free(struct bitset_group *self) {
	if (!self)
		return;

	struct bitset_group *walker = self;
	while (walker) {
		char_array_list_free(walker->table);
		struct bitset_group *tmp = walker->next;
		free(walker);
		walker = tmp;
	}
}

void bitset_group_print(struct bitset_group *self) {
	for (struct bitset_group *walker = self; walker; walker = walker->next) {
		char_array_list_print(walker->table);
	}
}
