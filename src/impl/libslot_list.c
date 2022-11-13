//
// Created by daniel on 11/11/22.
//
#include <malloc.h>
#include "libslot_list.h"

struct slot_list *slot_list_init() {
    struct slot_list *output = (struct slot_list *) malloc(sizeof(struct slot_list));
    output->val = NULL;
    output->next = NULL;
    return output;
}

void slot_list_print(struct slot_list *self) {
    if (self) {
        for(struct slot_list *walker = self; walker; walker = walker->next) {
            slot_print(walker->val);
        }
    }
}

void slot_list_append(struct slot_list *self, struct slot *input) {
    if (self && input) {
        struct slot_list *appended = slot_list_create_rank(self, input->rank);
        if (appended) {
            if (appended->val) {
                slot_append_slot(appended->val, input);
            } else {
                appended->val = input;
            }
        }
    }
}

struct slot_list *slot_list_create_rank(struct slot_list *self, int rank) {
    struct slot_list *output = NULL;
    for (struct slot_list *walker = self, *prev = NULL;
         walker && output == NULL;
         prev = walker, walker = walker->next) {

        if (walker->val) {
            if (walker->val->rank < rank) {
                if (walker->next) {
                    continue;
                } else {
                    walker->next = slot_list_init();
                    output = walker->next;
                }
            } else if (walker->val->rank == rank) {
                output = walker;
            } else if (walker->val->rank > rank) {
                if (prev)
                    output = prev;
                else {
                    output = slot_list_init();
                    output->next = walker;
                }
            }
        } else
            output = walker;
    }

    return output;
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