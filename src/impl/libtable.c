//
// Created by daniel on 10/31/22.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libtable.h"

struct table *table_init(int base) {
    struct table *output = (struct table *) malloc(sizeof(struct table));
    output->base = base;
    output->column = NULL;
    if (base) {
        output->column = (struct group **) malloc(sizeof(struct group *) * base);
        for (int i=0; i<base; i++) {
            output->column[i] = group_init(base-i);
        }
    }
    return output;
}

void table_init_base(struct table *self, int base) {
    if (base && self->column == NULL) {
        self->column = (struct group **) malloc(sizeof(struct group *) * base);
        for (int i=0; i<base; i++) {
            self->column[i] = group_init(base-i);
        }
    }
}

void table_append(struct table *self, char *input) {
    if (self) {
        group_append(self->column[0], input);
    }
}

void table_resolve(struct table *self) {
    for(int i=0; i<self->base-1; i++) {
        self->column[i+1] = bitset_group_resolve(self->column[i]);
    }
}

void table_print(struct table *self) {
    for (int i=0; i<self->base; i++) {
        printf("level = [%d]\n", i);
        group_print(self->column[i]);
        printf("<>\n");
    }
}

void table_free(struct table *self) {
    if (self) {
        for (int i=0; i<self->base; i++) {
            group_free(self->column[i]);
            self->column[i] = NULL;
        }
        free(self->column);
        self->column = NULL;
        free(self);
    }
}