//
// Created by daniel on 11/11/22.
//

#ifndef QUINEMCCLUSKEY_LIBSLOT_LIST_H
#define QUINEMCCLUSKEY_LIBSLOT_LIST_H

#include "libslot.h"

struct slot_list {
    struct slot *val;
    struct slot_list *next;
};

struct slot_list *slot_list_init();

void slot_list_append(struct slot_list *self, struct slot *input);

struct slot_list *slot_list_create_rank(struct slot_list *self, int rank);

void slot_list_append_slot_list(struct slot_list *self, struct slot_list *input);

void slot_list_print(struct slot_list *self);

void slot_list_free(struct slot_list *self);

#endif //QUINEMCCLUSKEY_LIBSLOT_LIST_H
