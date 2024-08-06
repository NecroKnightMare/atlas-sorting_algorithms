#include "sort.h"
void swap_list( listint_t **list, listint_t *N1, listint_t *N2)
{
    if (N1->prev)
{
        N1->prev->next = N2;
}
    else
{
        *list = N2;
}
    if (N2->next)
{
            N2->next->prev = N1;
}
    N1->next = N2->next;
    N2->prev = N1->prev;
    N1->prev = N2;
    N2->next = N1;
}
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