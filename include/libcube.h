//
// Created by daniel on 11/13/22.
//

#ifndef QUINEMCCLUSKEY_LIBCUBE_H
#define QUINEMCCLUSKEY_LIBCUBE_H

#include "libslot_list.h"

struct cube {
    int level;
    int size;
    struct slot_list *head;
    struct slot_list *tail;
};

struct cube *cube_init(int level);

void cube_print(struct cube *self);

void cube_append(struct cube *self, struct slot_list *input);

struct cube *cube_resolve(struct cube *self);

void cube_free(struct cube *self);

#endif //QUINEMCCLUSKEY_LIBCUBE_H
