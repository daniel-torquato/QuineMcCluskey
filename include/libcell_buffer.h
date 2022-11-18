//
// Created by daniel on 11/18/22.
//

#ifndef QUINEMCCLUSKEY_LIBCELL_BUFFER_H
#define QUINEMCCLUSKEY_LIBCELL_BUFFER_H

#include "libcell_list.h"

struct cell_buffer {
    struct cell_list *head;
    struct cell_list *tail;
};

struct cell_buffer *cell_buffer_init();

void cell_buffer_append(struct cell_buffer *self, struct cell *input);

void cell_buffer_print(struct cell_buffer *self);

void cell_buffer_free(struct cell_buffer *self);

#endif //QUINEMCCLUSKEY_LIBCELL_BUFFER_H
