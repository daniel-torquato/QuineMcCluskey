//
// Created by daniel on 11/13/22.
//

#ifndef QUINEMCCLUSKEY_LIBCUBE_LIST_H
#define QUINEMCCLUSKEY_LIBCUBE_LIST_H

#include "libcube.h"

struct cube_list {
    struct cube *val;
    struct cube_list *next;
};

struct cube_list *cube_list_init();

void cube_list_print(struct cube_list *self);

void cube_list_free(struct cube_list *self);

#endif //QUINEMCCLUSKEY_LIBCUBE_LIST_H
