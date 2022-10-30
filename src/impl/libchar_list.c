/*
 * libchar_list.c
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include <libchar_list.h>

/*
 * Free char linked list
 */
void char_list_free (struct char_list *self) {
	struct char_list *walker = self;
	while (walker) {
		struct char_list *next = walker->next;
		free(walker);
		walker = next;
	}
}

void char_list_print(struct char_list *self) {
	for (struct char_list *walker = self; walker; walker = walker->next) {
		printf("%s->", walker->val);
	}
	printf("NULL\n");
}
