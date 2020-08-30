#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void convert_set (int *input, int size, char **output, int base)
{
	int tmp;
	for (int i=0; i<size; i++) {
		tmp = input[i];
		for (int j=0; j<base; j++) {
			output[i][(base-1)-j] = tmp % 2 + '0';
			printf ("%c", tmp % 2 + '0');
			tmp /= 2;
		}
		printf ("\n");
	}
}

void group_set (char **output, int size, char ***groups, int length_of_word, int *size_of_group)
{
	int sum_of_bits;
	int *group_idx = (int*) malloc((length_of_word+1)*sizeof(int));

	for (int i=0; i<size; i++)
		size_of_group[i] = 0;

	for (int i=0; i<size; i++) {
		sum_of_bits = 0;
		for (int j=0; j<length_of_word; j++) {
			sum_of_bits += output[i][j] - '0';
		}
		size_of_group[sum_of_bits]++;
	}

	for (int i=0; i<=length_of_word; i++) {
		group_idx[i] = 0;
		groups[i] = (char**) malloc(size_of_group[i]*sizeof(char*));
	}

	for (int i=0; i<size; i++) {
		sum_of_bits = 0;
		for (int j=0; j<length_of_word; j++) {
			sum_of_bits += output[i][j] - '0';
		}
		groups[sum_of_bits][group_idx[sum_of_bits]++] = output[i];
	}
	free (group_idx);
}

bool merge_words (char *A, char *B, int length_of_word, char *merged)
{
	int diff_size = 0;
	for (int i=0; i<length_of_word; i++) {
		if (A[i] != B[i]) {
			diff_size++;
		}
	}
	return diff_size == 1;
}

int main (int argc, char **argv)
{
	int size;
	int *input;
	int maximum_value = 0, length_of_word = 0;
	int i;
	char **output;
	char ***groups;
	char *merged;
	int *size_of_group;

	
	scanf ("%d", &size);
	input = (int*) malloc (size*sizeof(int));

	for (i=0; i<size; i++) {
		scanf ("%d", &input[i]);
		if (maximum_value < input[i])
			maximum_value = input[i];
	}
	printf ("Maximum value: %d\n", maximum_value);

	while (maximum_value) {
		length_of_word++;
		maximum_value /= 2;
	}

	printf ("Base: %d\n", length_of_word);

	output = (char **) malloc (size*sizeof(char*));
	for (int i=0; i<size; i++) {
		output[i] = (char*) malloc((length_of_word+1)*sizeof(char));
		output[i][length_of_word] = '\0';
	}

	convert_set (input, size, output, length_of_word);

	for (i=0; i<size; i++)
		printf ("[%d %s]", input[i], output[i]);
	printf ("\n");

	size_of_group = (int*) malloc ((length_of_word+1)*sizeof(int));
	groups = (char***) malloc ((length_of_word+1)*sizeof(char**));
	group_set (output, size, groups, length_of_word, size_of_group);

	char **test_group[length_of_word];
	int idx = 0;
	printf ("-------------------------------------\n");
	for (int i=0; i<length_of_word; i++) {
		for (int j=0; j<size_of_group[i]; j++) {
			for (int k=0; k<size_of_group[i+1]; k++) {
				if (merge_words (groups[i][j], groups[i+1][k], length_of_word, merged)) {
					test_group[i][idx++] = merged;
				}
			}
		}
		printf ("-------------------------------------\n");
	}

	printf ("Freeing resources\n");
	free (input);
	for (int i=0; i<length_of_word; i++) {
		free (groups[i]);
	}
	free (groups);
	free (size_of_group);
	for (int i=0; i<size; i++)
		free (output[i]);
	free (output);

	return 0;
}
