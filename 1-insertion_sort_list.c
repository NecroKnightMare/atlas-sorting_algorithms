#include "sort.h"
/**
 * insertion_sort_list - uses singly linked list to go through array
 * @list: SLL in header
 * Return: void,
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *now, *after, *temp;

    if (list == NULL || *list == NULL || (*list)->after == NULL)
    {
        return;
    }
    now = (*list)->after;
    while (now != NULL)
    {
        after = now->after;
        temp = now->prev;
        while ( temp != NULL && now->n < temp->n)
        {
            swap_list(list, temp, now);
            print_list(*list);
            temp = now->prev;
        }
        now = after;
    }
}