#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/*
use [gcc -Wall -Wextra -Werror -pedantic 102-main.c 102-counting_sort.c 
print_array.c -o counting] to compile
and ./counting to test
*/

void print_array(const int *array, size_t size);

void counting_sort(int *array, size_t size)
{
	int max, *count, *sorted;
	size_t i;
	int k;

	if (!array || size < 2) return;

	/* Step 1: Find max value */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max) max = array[i];
	}

	/* Step 2: Allocate count array */
	count = calloc(max + 1, sizeof(int));
	if (!count) return;

	/* Step 3: Count occurrences */
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	/* Step 4: Compute cumulative sum */
	for (k = 1; k <= max; k++)
	{
		count[k] += count[k - 1];
	}

	/* Step 5: Allocate sorted array */
	sorted = malloc(size * sizeof(int));
	if (!sorted) {
		free(count);
		return;
	}

	/* Step 6: Build sorted array (traverse backwards for stability) */
	for (i = size; i > 0; i--)
	{
		sorted[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	/* Step 7: Copy sorted values back */
	for (i = 0; i < size; i++)
	{
		array[i] = sorted[i];
	}

	/* Step 8: Free allocated memory */
	free(sorted);
	free(count);
}
