//
// Created by daniel on 11/3/22.
//

#ifndef QUINEMCCLUSKEY_LIBBITSET_ARRAY_H
#define QUINEMCCLUSKEY_LIBBITSET_ARRAY_H

#include <malloc.h>
#include <stdbool.h>

struct bitset_array {
    int size;
    int *data;
};

struct bitset_array *bitset_array_init(int size);

void bitset_array_set(struct bitset_array *self, int index, bool state);

bool bitset_array_get(struct bitset_array *self, int index);

void bitset_array_print(struct bitset_array *self);

void bitset_array_free(struct bitset_array *self);

#endif //QUINEMCCLUSKEY_LIBBITSET_ARRAY_H
