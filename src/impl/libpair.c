//
// Created by daniel on 11/1/22.
//

#include <stdlib.h>
#include <libpair.h>

struct pair *pair_init(void *first, void *second) {
    struct pair *output = (struct pair *) malloc(sizeof(struct pair));
    output->first = first;
    output->second = second;
    return output;
}

void *pair_get(struct pair *self, int idx) {
    void *output = NULL;
    switch (idx) {
        case 0:
            output = self->first;
            break;
        case 1:
            output = self->second;
            break;
        default:
            output = NULL;
    }
    return output;
}

void pair_free(struct pair *self) {
    if (self) {
        free(self);
    }
}