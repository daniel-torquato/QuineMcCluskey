//
// Created by daniel on 11/13/22.
//
#include <malloc.h>
#include "libcube_list.h"

struct cube_list *cube_list_init() {
    struct cube_list *output = (struct cube_list *) malloc(sizeof(struct cube));
    output->val = NULL;
    output->next = NULL;
    return output;
}

void cube_list_print(struct cube_list *self) {
    if(self) {
        for(struct cube_list *walker = self; walker; walker = walker->next) {
            if (walker->val) {
                printf("level = [%d]", walker->val->level);
                cube_print(walker->val);
            }
        }
    }
}

void cube_list_free(struct cube_list *self) {
    if (self) {
        cube_free(self->val);
        self->val = NULL;
        free(self);
    }
}