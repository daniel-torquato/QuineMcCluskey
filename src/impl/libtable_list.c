//
// Created by daniel on 10/31/22.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libtable_list.h"

struct table_list *table_list_init(int base) {
    struct table_list *output = (struct table_list *) malloc(sizeof(struct table_list));
    output->level = 0;
    output->base = base;
    output->column = group_init(base);
    output->next = NULL;
    return output;
}

void table_list_append(struct table_list *self, char *input) {
    if (self) {
        group_add(self->column, input);
    }
}

void bitset_table_resolve(struct table_list *self) {
    struct table_list *walker = self;
    for (;walker; ) {
        struct group *solved = bitset_group_resolve(walker->column);
        if (solved) {
            // TODO: remove base from table_list
            walker->next = table_list_init(walker->base);
            walker = walker->next;
            walker->column = solved;
        }
    }
}

void table_list_print(struct table_list *self) {
    for (struct table_list *walker = self; walker; walker = walker->next) {
        printf("level = [%d]\n", walker->level);
        group_print(walker->column);
        printf("<>\n");
    }
}

void table_list_free(struct table_list *self) {
    if (self) {
        struct table_list *walker = self, *next = self;
        while (walker) {
            if (walker->column)
                group_free(self->column);
            next = walker->next;
            free(walker);
            walker = next;
        }
    }
}