#ifndef _SORT_H_
#define _SORT_H_
#include <stddef.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void swap_list(listint_t **list, listint_t *N1, listint_t *N2);

/*ADVANCED*/
void shell_sort(int *array, size_t size);/*task 0*/
void counting_sort(int *array, size_t size);/*task 1*/
void merge_sort(int *array, size_t size);/*task 2*/

#endif /*_SORT_H_*/
