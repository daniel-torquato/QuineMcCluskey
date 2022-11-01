//
// Created by daniel on 10/31/22.
//

#ifndef INCLUDE_LIBBITSET_TABLE_H_
#define INCLUDE_LIBBITSET_TABLE_H_

#include <libbitset_group.h>

struct bitset_table {
    int level;
    struct bitset_group *column;
    struct bitset_table *next;
};

struct bitset_table *bitset_table_init();

void bitset_table_append(struct bitset_table *self, char *input);

void bitset_table_print(struct bitset_table *self);

void bitset_table_free(struct bitset_table *self);

#endif /* INCLUDE_LIBBITSET_TABLE_H_ */