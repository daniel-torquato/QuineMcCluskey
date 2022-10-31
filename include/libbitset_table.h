//
// Created by daniel on 10/31/22.
//

#ifndef INCLUDE_LIBBITSET_TABLE_H_
#define INCLUDE_LIBBITSET_TABLE_H_

#include "libbitset_group.h"

struct bitset_table {
    int level;
    struct bitset_group *column;
    struct bitset_table *next;
};

struct bitset_table *bitset_table_init() {
    struct bitset_table *output = (struct bitset_table *) malloc(sizeof(struct bitset_table));
    return output;
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

#endif /* INCLUDE_LIBBITSET_TABLE_H_ */