/*
 * libcell_list.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include <libcell_list.h>
#include <libcell.h>

struct cell_list *cell_list_init() {
    struct cell_list *output = (struct cell_list *) malloc(sizeof(struct cell_list));
    output->val = NULL;
    output->next = NULL;
    return output;
}

/*
 * Free char linked list
 */
void cell_list_free (struct cell_list *self) {
	struct cell_list *walker = self;
	while (walker) {
		struct cell_list *next = walker->next;
        if (walker->val) {
            cell_free(walker->val, true);
            walker->val = NULL;
        }
        walker->next = NULL;
		free(walker);
		walker = next;
	}
}

void cell_list_print(struct cell_list *self) {
	for (struct cell_list *walker = self; walker; walker = walker->next) {
		cell_print(walker->val);
        printf("->");
	}
	printf("NULL\n");
}
