#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libbitset_table.h>
#include <libint_handler.h>


int main (int argc, char **argv)
{
	struct bitset_table *resolution_table = bitset_table_init();

	int tmp;
	while (scanf("%d", &tmp) != 0) {
        char *input = int_to_char_array(tmp);
		bitset_table_append(resolution_table, input);
	}

	bitset_table_print(resolution_table);

	bitset_table_free(resolution_table);

	return 0;
}
