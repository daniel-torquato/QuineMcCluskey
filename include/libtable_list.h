//
// Created by daniel on 10/31/22.
//

#ifndef INCLUDE_LIBBITSET_TABLE_H_
#define INCLUDE_LIBBITSET_TABLE_H_

#include <libgroup.h>

struct table_list {
    int level;
    int base;
    struct group *column;
    struct table_list *next;
};

struct table_list *table_list_init(int base);

void table_list_append(struct table_list *self, char *input);

void table_list_print(struct table_list *self);

void table_list_free(struct table_list *self);

#endif /* INCLUDE_LIBBITSET_TABLE_H_ */