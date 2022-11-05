//
// Created by daniel on 11/3/22.
//

#include "libbitset_array.h"

struct bitset_array *bitset_array_init(int size) {
    struct bitset_array *output = (struct bitset_array *) malloc(sizeof(struct bitset_array));
    output->size = size;
    output->data = (int *) calloc(size / sizeof (int) + 1, sizeof(int));
}

void bitset_array_set(struct bitset_array *self, int index, bool state) {
    self->data[index / sizeof(int)] |= (state << (index % sizeof(int)));
}

bool bitset_array_get(struct bitset_array *self, int index) {
    return (self->data[index / sizeof(int)] >> (index % sizeof(int))) % 2 == 1;
}

void bitset_array_print(struct bitset_array *self) {
    if (self) {
        int slot_size = sizeof(int);
        char slot[slot_size+1];
        slot[slot_size] = '\0';
        for (int i = self->size / slot_size; i >= 0; i--) {
            static int tmp;
            tmp = self->data[i];
            for (int j=0; j<slot_size; j++) {
                slot[slot_size - 1 - j] = tmp % 2 + '0';
                tmp >>= 1;
            }
            printf("%s", slot);
        }
        printf("\n");
    }
}

void bitset_array_free(struct bitset_array *self) {
    if (self) {
        if  (self->data) {
            free(self->data);
        }
        free(self);
    }
}