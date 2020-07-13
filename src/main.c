#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum errors {
	INSUFICIENT_ARGUMENTS,
	MISSING_PARAM
};

void usage(enum errors case_type)
{
	switch (case_type) {
	case 0:
		printf("Usage:  ./quine -s <size> <inputs>\n");
		break;
	case 1:
		printf("Missing param -s \n");
		printf("Usage:  ./quine -s <size> <inputs>\n");
		break;
	}
}

/* Receive a sequence of numbers and the word size to optimize
 */
int main (int argc, char **argv)
{
	int size;
	if (argc < 2) {
		usage(INSUFICIENT_ARGUMENTS);
		return -INSUFICIENT_ARGUMENTS;
	}
	if (argc > 2) 
	{
		if (strcmp(argv[1], "-s") ) {
			usage(MISSING_PARAM);
			return -MISSING_PARAM;
		}
		else {
			size = atoi(argv[2]);
		}
		/*
		   Allocate words vector
		 */
		for (int i=3; i<argc; i++) {

		}
	}

	return 0;
}
