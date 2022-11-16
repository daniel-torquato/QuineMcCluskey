//
// Created by daniel on 11/8/22.
//
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "libcell.h"

struct cell *cell_init(char *word, bool flag) {
    struct cell *output = (struct cell *) malloc(sizeof(struct cell));
    output->word = word;
    output->flag = flag;
    return output;
}

struct cell *cell_init_int(int input) {
    struct cell *output  = cell_init(NULL, false);
    int size  = 1;
    for (int tmp = input/2; tmp; tmp >>= 1) {size++;}

    output->word = (char *) malloc(sizeof(char) * (size+1));
    output->word[size] = '\0';

    for (int i = 0; i<size; i++) {
        output->word[size-1-i] = input % 2 + '0';
        input >>= 1;
    }

    return output;
}

struct cell *cell_merge(struct cell *a, struct cell *b) {
    struct cell *output = NULL;
    if (a && b) {
        output = cell_init(NULL, false);
        size_t size_a = strlen(a->word), size_b = strlen(b->word);
        size_t size_min = size_a >= size_b ? size_b : size_a;
        size_t size_max = size_a >= size_b ? size_a : size_b;
        output->word =  strdup(size_a >= size_b ? a->word : b->word);
        int diff = 0;
        for (int i=0; i<size_min && diff < 2; i++) {
            if (a->word[size_a-1-i] != b->word[size_b-1-i]) {
                output->word[size_max-1-i] = 'X';
                diff++;
            }
        }
        for (size_t i=size_min; i<size_max && diff < 2; i++) {
            if (output->word[size_max-1-i] == '1') {
                output->word[size_max-1-i] = 'X';
                diff++;
            }
        }
        if (diff > 1) {
            cell_free(output, true);
            output = NULL;
        }
    }
    return output;
}

int cell_ones(struct cell *self) {
    int ret = 0;
    for (int i=0; self->word[i]; i++) {
        ret += self->word[i] == '1';
    }
    return ret;
}

int cell_compare(struct cell *a, struct cell *b) {
    int output = -1;
    if (a && b) {
        output = strcmp(a->word, b->word);
    }
    return output;
}

void cell_print(struct cell *self) {
    if (self) {
        printf("{%s:%d}", self->word, self->flag);
    }
}

void cell_free(struct cell *self, bool free_word) {
    if (self) {
        if (free_word) {
            free(self->word);
            self->word = NULL;
        }
        free(self);
    }
}