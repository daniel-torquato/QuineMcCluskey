//
// Created by daniel on 11/11/22.
//
#include <malloc.h>
#include "libslot_list.h"

struct slot_list *slot_list_init() {
    struct slot_list *output = (struct slot_list *) malloc(sizeof(struct slot_list));
    output->val = NULL;
    return output;
}

void slot_list_print(struct slot_list *self) {
    if (self) {
        for(struct slot_list *walker = self; walker; walker = walker->next) {
            printf("%d:");
            slot_print(walker->val);
            printf("\n");
        }
    }
}

void slot_list_free(struct slot_list *self) {
    if (self) {
        for (struct slot_list *walker = self, *next = self; walker; walker = next) {
            next = walker->next;
            slot_free(walker->val);
            free(walker);
        }
    }
}