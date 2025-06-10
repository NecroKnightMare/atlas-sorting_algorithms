#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*use [gcc -Wall -Wextra -Werror -pedantic 100-main.c 100-shell_sort.c
print_array.c -o shell]
to compile and ./shell to test output*/
void print_array(const int *array, size_t size);

void shell_sort(int *array, size_t size)
{
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};  /*Ciura gap sequence*/
    size_t num_gaps = sizeof(gaps) / sizeof(gaps[0]);

    size_t g;
    for (g = 0; g < num_gaps; g++)
    {
        int gap = gaps[g];
        size_t i;
        for (i = gap; i < size; i++)
        {
            int temp = array[i];
            size_t j = i;

            while (j >= (size_t)gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
        print_array(array, size);
    }
}