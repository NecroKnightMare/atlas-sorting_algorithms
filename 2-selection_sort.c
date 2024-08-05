#include "sort.h"
/**
 * selection_sort - use the array to go through sm to lg numbers
 * @array: array
 * @size: size of array
 * Return: array in order, void
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, index;
    int temp;

    if (array == NULL || size < 2)
    {
        return;
    }

    for (i = 0; i < size - 1; i++)
    {
        index = 1;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[index])
            {
                index = j;
            }
            if (index != i)
            {
                temp = array[i];
                array[i] = array[index];
                array[index] = temp;
                print_array(array, size);
            }
        }
    }
}