#include "sort.h"
/**
 * insertion_sort_list - uses singly linked list to go through array
 * @list: SLL in header
 * Return: void,
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *now, *next, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
    {
        return;
    }
    now = (*list)->next;
    while (now != NULL)
    {
        next = now->next;
        temp = now->prev;
        while ( temp != NULL && now->n < temp->n)
        {
            swap_list(list, temp, now);
            print_list(*list);
            temp = now->prev;
        }
        now = next;
    }
}