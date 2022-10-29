#ifndef __QUINE__
#define __QUINE__

struct bitset {
	int size;
	char *bits;
};

struct bit_group {
	int size;
	int base;
	struct bitset **groups;
};


#endif
