#include <stdio.h>
#include <libarray_list.h>
#include <libbitset_group.h>


int main (int argc, char **argv)
{
	struct bitset_group *minterms = bitset_group_init();

	int tmp;
	while (scanf("%d", &tmp) != 0) {
		bitset_group_append(minterms, tmp);
	}


	bitset_group_print(minterms);

	bitset_group_free(minterms);

	return 0;
}
