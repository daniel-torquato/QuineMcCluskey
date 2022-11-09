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

struct cell_list *cell_list_merge(struct cell_list *a, struct cell_list *b) {
    struct cell_list *output = NULL;
    if (a && b) {
        struct cell_list *output_walker = NULL;
        for (struct cell_list *walker_a = a; walker_a; walker_a = walker_a->next) {
            for (struct cell_list *walker_b = b; walker_b; walker_b = walker_b->next) {
                struct cell *merged = cell_merge(walker_a->val, walker_b->val);
                if (merged) {
                    walker_a->val->flag = true;
                    walker_b->val->flag = true;
                    struct cell_list *new = cell_list_init();
                    new->val = merged;
                    new->next = NULL;
                    if (!output_walker) {
                        output = new;
                        output_walker = output;
                    } else {
                        output_walker->next = new;
                        output_walker = output_walker->next;
                    }
                }
            }
        }
    }
    return output;
}

struct cell_list *cell_list_init_array(int *array, int size) {
    struct cell_list *output = NULL;
    if (size) {
        static struct cell_list *walker;
        walker = output;
        for (int i=0; i<size; i++) {
            if (walker) {
                walker->next = cell_list_init();
                walker = walker->next;
            } else {
                walker = cell_list_init();
                output = walker;
            }
            walker->val = cell_init_int(array[i]);
        }
    }
    return output;
}

void cell_list_print(struct cell_list *self) {
	for (struct cell_list *walker = self; walker; walker = walker->next) {
		cell_print(walker->val);
        printf("->");
	}
	printf("NULL\n");
}

int cell_list_size(struct cell_list *self) {
    int output = 0;
    for (struct cell_list *walker = self; walker; walker = walker->next) {
        output++;
    }
    return output;
}
