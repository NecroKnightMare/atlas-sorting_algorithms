#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/*use [gcc -Wall -Wextra -Werror -pedantic 103-main.c 103-merge_sort.c
print_array.c -o merge] to compile  and ./merge to test output*/

void print_array(const int *array, size_t size);

/* Merge function */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right) {
	size_t i = left, j = mid, k = left;
	size_t l;

	printf("Merging...\n[left]: ");
	for (l = left; l < mid; l++) printf("%d ", array[l]);
	printf("\n[right]: ");
	for (l = mid; l < right; l++) printf("%d ", array[l]);
	printf("\n");

	/* Merge process */
	while (i < mid && j < right) 
	{
		if (array[i] <= array[j]) temp[k++] = array[i++];
		else {
			temp[k++] = array[j++];
		}
	}
	while (i < mid) temp[k++] = array[i++];
	while (j < right) temp[k++] = array[j++];

	/* Copy sorted values back */
	for (i = left; i < right; i++)
	{
		array[i] = temp[i];
	}

    /* Print final merged array */
    printf("[Done]: ");
	for (l = left; l < right; l++) printf("%d ", array[l]);
	printf("\n");
}

/* Recursive Merge Sort */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
	{
		return;
	}

	mid = left + (right - left) / 2;
	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/* Merge Sort Wrapper */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	int *temp = malloc(size * sizeof(int));
	if (!temp)
	{
		return;
	}

	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}
