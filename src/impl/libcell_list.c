/*
 * libcell_list.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include <libcell_list.h>

/*
 * Free char linked list
 */
void cell_list_free (struct cell_list *self) {
	struct cell_list *walker = self;
	while (walker) {
		struct cell_list *next = walker->next;
        if (walker->val) {
            free(walker->val);
            walker->val = NULL;
        }
        walker->next = NULL;
		free(walker);
		walker = next;
	}
}

void cell_list_print(struct cell_list *self) {
	for (struct cell_list *walker = self; walker; walker = walker->next) {
		printf("%s->", walker->val);
	}
	printf("NULL\n");
}
