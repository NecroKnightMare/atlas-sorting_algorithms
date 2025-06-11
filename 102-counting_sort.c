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
    int max, k;
    int *count, *sorted;
    size_t i, j;

    if (!array || size < 2)
    {
        return;
    }

    max = array[0];

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    count = calloc(max + 1, sizeof(int));
    if (!count)
    {
        free(count);
        return;
    }

    for (i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    print_array(count, max + 1);

    for (k = 1; k <= max; k++)
    {
        count[k] += count[k - 1];
    }
    
    sorted = malloc(size * sizeof(int));
    if (!sorted)
    {
        free(count);
        return;
    }
  
    for (j = size; j > 0; j--)
    {
        sorted[count[array[j - 1]] - 1] = array[j - 1];
        count[array[j - 1]]--;
    }
    for (i = 0; i < size; i++)
    {
        array[i] = sorted[i];
    }

    free(sorted);
    free(count);
}