//
// Created by daniel on 11/1/22.
//

#ifndef QUINEMCCLUSKEY_LIBPAIR_H
#define QUINEMCCLUSKEY_LIBPAIR_H

struct pair {
    void *first;
    void *second;
};

struct pair *pair_init(void *first, void *second);

void *pair_get(struct pair *self, int idx);

void pair_free(struct pair *self);

#endif //QUINEMCCLUSKEY_LIBPAIR_H
