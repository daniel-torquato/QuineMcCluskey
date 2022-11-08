//
// Created by daniel on 11/1/22.
//
#include <stdio.h>
#include <libbitset_slot.h>
#include <string.h>
#include "libpair.h"
#include "libbitset_array.h"
#include "libcell.h"

struct bitset_slot *bitset_slot_init(int rank) {
    struct bitset_slot *output = (struct bitset_slot *) malloc(sizeof(struct bitset_slot));
    output->rank = rank;
    output->head = NULL;
    output->tail = NULL;
    return output;
}

void bitset_slot_append(struct bitset_slot *self, char *input) {
    if (self) {
        struct cell_list *new = (struct cell_list *) malloc (sizeof(struct cell_list));
        self->size++;
        new->val = cell_init(input, false);
        new->next = NULL;
        if (self->tail) {
            self->tail->next = new;
            self->tail = new;
        } else {
            self->size = 1;
            self->head = new;
            self->tail = new;
        }
    }
}

void bitset_slot_add(struct bitset_slot *self, char *input) {
    bitset_slot_append(self, strdup(input));
}

void  bitset_slot_print(struct bitset_slot *self) {
    if (self) {
        printf("%d: ", self->rank);
        cell_list_print(self->head);
    }
}

struct pair *bitset_slot_merge(struct bitset_slot *a, struct bitset_slot *b) {
    if (!a || !b)
        return NULL;
    struct bitset_slot *first = bitset_slot_init(a->rank);
    struct bitset_slot *second = bitset_slot_init(b->rank);
    struct pair *output = pair_init((void *) first, (void *) second);

    struct bitset_array *check_a = bitset_array_init(a->size);
    struct bitset_array *check_b = bitset_array_init(b->size);

    int index_a = 0;
    for (struct cell_list *walker_a = a->head; walker_a && index_a < a->size; walker_a = walker_a->next, index_a++) {
        int index_b = 0;
        for (struct cell_list *walker_b = b->head;
             walker_b && index_b < b->size; walker_b = walker_b->next, index_b++) {
            struct cell *merged = cell_merge(walker_a->val, walker_b->val);
            if (merged) {
                bitset_array_set(check_a, index_a, true);
                bitset_array_set(check_b, index_b, true);
                bitset_slot_append(cell_ones(merged) == a->rank ? first : second, merged->word);
                cell_free(merged, false);
            }
        }

    }
    static struct cell_list *walker;
    walker = a->head;
    for (int i = 0; i < a->size && walker; i++, walker = walker->next) {
        if (!bitset_array_get(check_a, i)) {
            bitset_slot_add((struct bitset_slot *) output->first, walker->val->word);
        }
    }
    walker = b->head;
    for (int i = 0; i < b->size && walker; i++, walker = walker->next) {
        if (!bitset_array_get(check_b, i)) {
            bitset_slot_add((struct bitset_slot *) output->second, walker->val->word);
        }
    }

    bitset_array_free(check_a);
    bitset_array_free(check_b);

    return output;
}

void bitset_slot_free(struct bitset_slot *self) {
    if (self) {
        cell_list_free(self->head);
        free (self);
    }
}