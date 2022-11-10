#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libtable.h>
#include <libint_handler.h>


int main (int argc, char **argv)
{
	struct table *resolution_table = table_init(0);
    struct slot *buffer = slot_init(0);

	int tmp;
	while (scanf("%d", &tmp) != 0) {
        char *input = int_to_char_array(tmp);
        slot_append(buffer, input);
	}

    table_print(resolution_table);

    table_free(resolution_table);
    slot_free(buffer);

	return 0;
}
