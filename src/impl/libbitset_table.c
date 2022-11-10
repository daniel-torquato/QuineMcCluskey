//
// Created by daniel on 10/31/22.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libbitset_table.h"

struct bitset_table *bitset_table_init(int base) {
    struct bitset_table *output = (struct bitset_table *) malloc(sizeof(struct bitset_table));
    output->level = 0;
    output->base = base;
    output->column = bitset_group_init(base);
    output->next = NULL;
    return output;
}

void bitset_table_append(struct bitset_table *self, char *input) {
    if (self) {
        bitset_group_add(self->column, input);
    }
}

void bitset_table_resolve(struct bitset_table *self) {
    struct bitset_table *walker = self;
    for (;walker; ) {
        struct bitset_group *solved = bitset_group_resolve(walker->column);
        if (solved) {
            // TODO: remove base from bitset_table
            walker->next = bitset_table_init(walker->base);
            walker = walker->next;
            walker->column = solved;
        }
    }
}

void bitset_table_print(struct bitset_table *self) {
    for (struct bitset_table *walker = self; walker; walker = walker->next) {
        printf("level = [%d]\n", walker->level);
        bitset_group_print(walker->column);
        printf("<>\n");
    }
}

void bitset_table_free(struct bitset_table *self) {
    if (self) {
        struct bitset_table *walker = self, *next = self;
        while (walker) {
            if (walker->column)
                bitset_group_free(self->column);
            next = walker->next;
            free(walker);
            walker = next;
        }
    }
}