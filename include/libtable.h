//
// Created by daniel on 11/14/22.
//

#ifndef INCLUDE_TABLE_H
#define INCLUDE_TABLE_H

#include "libcube_list.h"

struct table {
    int size;
    struct cube_list *head;
    struct cube_list *tail;
};

struct table *table_init();

void table_append(struct table *self, struct cube *input);

void table_print(struct table *self);

void table_resolve(struct table *self);

void table_free(struct table *self);

#endif //INCLUDE_TABLE_H
