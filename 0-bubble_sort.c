#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * bubble_sort - algorithm swapping lowest to highest
 * @array: uses given array
 * @size: size of arrat
 * Return: ret printed array, void
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp, swapped;

    if (array == NULL || size < 2)
{
        return;
}
        for (i = 0; i < size - 1; i++)
{
            swapped = 0;
            for (j = 0; j < size - i - 1; j++)
{

                if (array[j] > array[j + 1])
{
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    swapped = 1;
                    print_array(array, size);
}
}
            if (!swapped)
            break;
}
}