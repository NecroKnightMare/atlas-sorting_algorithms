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

	if (!array || size < 2)
	{
		return;
	}

	/* Find max value */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	/* Allocate count array */
	count = calloc(max + 1, sizeof(int));
	if (!count)
	{
		return;
	}

	/* Step 3: Count occurrences */
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	/* Compute sum */
	for (k = 1; k <= max; k++)
	{
		count[k] += count[k - 1];
	}

	print_array(count, max + 1);

	/*Allocate sorted array */
	sorted = malloc(size * sizeof(int));
	if (!sorted) 
	{
		free(count);
		return;
	}

	/* Build sorted array going backwards*/
	for (i = size; i > 0; i--)
	{
		sorted[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	/* Copy sorted values back */
	for (i = 0; i < size; i++)
	{
		array[i] = sorted[i];
	}

	free(sorted);
	free(count);
}
