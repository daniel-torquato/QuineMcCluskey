/*
 * libbitset_group.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libbitset_group.h>
#include <libchar_array_list.h>
#include <libint_handler.h>

struct bitset_group *bitset_group_init() {
	struct bitset_group *output = (struct bitset_group*) malloc(sizeof(struct bitset_group));
	output->rank = -1;
	output->table = NULL;
	return output;
}

/*
 * Append new integer [input] to bitset_group
 */
void bitset_group_add(struct bitset_group *self, int input) {

	if (!self)
		return;
	int rank = count_ones(input);
	char *val = int_to_char_array(input);

	bool added = false;
	struct bitset_group *walker = self, *prev = self;
	while (walker) {
		if (walker->rank == rank) {
			if (!walker->table)
				walker->table = char_array_list_init();
			char_array_list_append(walker->table, val);
			added = true;
			break;
		}
		if (walker->rank > rank) {
			break;
		}
		prev = walker;
		walker = walker->next;
	}
	if (!added) {
		if (prev) {
			if (prev->rank == -1) {
				prev->rank = rank;
				if (!prev->table)
					prev->table = char_array_list_init();
				char_array_list_append(prev->table, val);
			} else {
				struct bitset_group *new = (struct bitset_group*) malloc(sizeof(struct bitset_group));
				new->rank = rank;
				new->table = char_array_list_init();
				char_array_list_append(new->table, val);

				new->next = prev->next;
				prev->next = new;
			}
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
		printf ("%d: ", walker->rank);
		char_array_list_print(walker->table);
		printf ("\n");
	}
}
