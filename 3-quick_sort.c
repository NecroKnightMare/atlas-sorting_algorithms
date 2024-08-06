#include "sort.h"
/**
 * swap - swap array
 * @a: point in array
 * @b: point in array
 * Return: void
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * divide_conquer - parse through array
 * @array: array
 * @low: low number
 * @high: high number
 * Return: index of parse
 */
int divide_conquer(int *array, int low, int high)
{
    int divide = array[high];
    int i = low -1;
    int j = low;

    while (j < high)
    {
        j++;
        if (array[j] <= divide)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, high + 1);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, high + 1);
    return (i + 1);
}
/**
 * catch_all_sort - use this function to condense recursion
 * @array: array
 * @size: size of array
 * Return: void
 */
void catch_all_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int k = divide_conquer(array, low, high);
        catch_all_sort(array, low, k - 1);
        catch_all_sort(array, k +1, high);
    }
}
/**
 * quick_sort - algorithm to sort through array using Lomuto
 * @array: array
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{ 
   if (array == NULL || size < 2)
    {
        return;
    }
    catch_all_sort(array, 0, size - 1);
}