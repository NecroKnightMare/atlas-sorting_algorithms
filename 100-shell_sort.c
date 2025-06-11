#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*
*use [gcc -Wall -Wextra -Werror -pedantic 100-main.c 100-shell_sort.c
*print_array.c -o shell]
*to compile and ./shell to test output
*/
void print_array(const int *array, size_t size);

void shell_sort(int *array, size_t size)
{
	/*Generate Knuth sequence dynamically*/
	int gap = 1;
	size_t i, j;

	/*Error handling*/
	if (!array || size < 2)
	{
		return;
	}

	while (gap < (int)size / 3)
	{
		gap = gap * 3 + 1; /*Knuth formula*/
	}

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			int temp = array[i];
			j = i;


			
			while (j >= (size_t)gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);

		gap /= 3; /*Reduce gap following Knuth sequence*/
	}
}
