/*
 * libchar_list.h
 *
 *  Created on: Oct 29, 2022
 *      Author: daniel
 */

#ifndef INCLUDE_LIBCHAR_LIST_H_
#define INCLUDE_LIBCHAR_LIST_H_

/*
 * test
 */
struct char_list {
	char *val;
	struct char_list *next;
};

void char_list_free (struct char_list *self);
void char_list_print(struct char_list *self);

#endif /* INCLUDE_LIBCHAR_LIST_H_ */
