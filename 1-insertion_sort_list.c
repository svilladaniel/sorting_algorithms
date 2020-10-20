#include "sort.h"
/**
 * insertion_sort_list - Sort with insertion algorithm
 *
 * @list: double linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current;

    if (list == NULL || (*list)->next == NULL)
        return;
    current =  (*list)->next;
    while (current != NULL)
    {
        while (current->prev && current->n < current->prev->n)
        {
            if (current->next != NULL)
                current->next->prev = current->prev;
            current->prev->next = current->next;
            current->next = current->prev;
            current->prev = current->prev->prev;
            current->next->prev = current;
            if(current->prev == NULL)
                *list = current;
            else
            {
                    current->prev->next = current;
            }
            print_list(*list);
        }
        current = current->next;
    }
}
