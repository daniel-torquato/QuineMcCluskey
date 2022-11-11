//
// Created by daniel on 10/31/22.
//

#ifndef INCLUDE_TABLE_LIST_H_
#define INCLUDE_TABLE_LIST_H_

#include <libgroup.h>

struct table {
    int base;
    struct group **column;
};

struct table *table_init(int base);

void table_init_base(struct table *self, int base);

void table_append(struct table *self, struct group *input);

void table_resolve(struct table *self);

void table_print(struct table *self);

void table_free(struct table *self);

#endif /* INCLUDE_TABLE_LIST_H_ */