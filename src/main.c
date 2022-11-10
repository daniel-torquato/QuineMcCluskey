#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libtable_list.h>
#include <libint_handler.h>


int main (int argc, char **argv)
{
	struct table_list *resolution_table = table_list_init();

	int tmp;
	while (scanf("%d", &tmp) != 0) {
        char *input = int_to_char_array(tmp);
        table_list_append(resolution_table, input);
	}

    table_list_print(resolution_table);

	table_list_free(resolution_table);

	return 0;
}
