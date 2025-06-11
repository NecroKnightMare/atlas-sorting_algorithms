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
    if (!array || size < 2)
    {
        return;
    }
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    int *count = calloc(max + 1, sizeof(int));
    if (!count)
    {
        return;
    }
    for ( i = 0; i< size; i++)
    {
    count[array[i]]++;
    }

    print_array(count, max +1);

    for (i = 1; i <= (size_t)max; i++)
    {
        count[i] += count[i - 1];
    }
    int *sorted = malloc(size * sizeof(int));
    if (!sorted)
    {
        free(count);
        return;
    }
    
    for (int i = (int)size - 1; i >= 0; i--)
    {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (i = 0; i < size; i++)
    {
        array[i] = sorted[i];
    }

    free(sorted);
    free(count);
}