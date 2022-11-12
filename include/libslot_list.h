//
// Created by daniel on 11/11/22.
//

#ifndef QUINEMCCLUSKEY_LIBSLOT_LIST_H
#define QUINEMCCLUSKEY_LIBSLOT_LIST_H

#include "libslot.h"

struct slot_list {
    int size;
    struct slot *val;
    struct slot_list *next;
};

struct slot_list *slot_list_init();

void slot_list_print(struct slot_list *self);

void slot_list_free(struct slot_list *self);

#endif //QUINEMCCLUSKEY_LIBSLOT_LIST_H
