#include "sort.h"
/**
 * divide_conquer - parse through array
 * @array: array
 * @low: low number
 * @high: high number
 * @size: size of array
 * Return: index of parse
 */
int divide_conquer(int *array, int low, int high, size_t size)
{
    int divide = array[high];
    int i = low;
    int j = low;
    int temp;

    while (j < high)
    {
        j++;
        if (array[j] < divide)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (array[i] > array[j])
           print_array(array, size);
            i++;
        }
    }
    temp = array[i];
    array[i] = array[high];
    array[high] = temp;
    print_array(array, size);

    return (i);
}
/**
 * catch_all_sort - use this function to condense recursion
 * @array: array
 * @size: size of array
 * Return: void
 */
void catch_all_sort(int *array, int low, int high, size_t size)
{
    int k;
    
    if (low < high)
    {
        k = divide_conquer(array, low, high, size);
        catch_all_sort(array, low, k - 1, size);
        catch_all_sort(array, k + 1, high, size);
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
   if (!array || size < 2)
    {
        return;
    }
    catch_all_sort(array, 0, size - 1, size);
}