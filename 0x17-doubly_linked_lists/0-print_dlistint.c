#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: Pointer to the head of the doubly linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;

    if (h == NULL)
        return count;

    while (h->next != NULL)
        h = h->next;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        count++;
        h = h->prev;
    }

    return count;
}
