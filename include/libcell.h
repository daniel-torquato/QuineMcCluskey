//
// Created by daniel on 11/8/22.
//

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <stdbool.h>

struct cell {
    char *word;
    bool flag;
};


struct cell *cell_init(char *word, bool flag);

struct cell *cell_init_int(int input);

struct cell *cell_merge(struct cell *a, struct cell *b);

void cell_print(struct cell *self);

void cell_free(struct cell *self, bool free_word);

int cell_ones(struct cell *self);

int cell_compare(struct cell *a, struct cell *b);

#endif //INCLUDE_CELL_H_
