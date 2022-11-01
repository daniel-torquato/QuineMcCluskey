//
// Created by daniel on 10/31/22.
//

#include <stdlib.h>
#include "libbitset_table.h"

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