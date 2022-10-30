#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libbitset_group.h>
#include <libint_handler.h>


int main (int argc, char **argv)
{
	struct bitset_group *minterms = bitset_group_init();

	int tmp;
	while (scanf("%d", &tmp) != 0) {
		bitset_group_add(minterms, tmp);
	}

	char *a = strdup("11");
	char *b = strdup("1001");
	char *ret = compare_bits(a, b);
	printf ("%s\n", ret);
	free(ret);

	bitset_group_print(minterms);

	bitset_group_free(minterms);

	return 0;
}
