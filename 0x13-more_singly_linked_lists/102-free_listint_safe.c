#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */

size_t free__listint_safe(listint_t **head)
{
    size_t count = 0;
    listint_t *current = *head;
    listint_t *next;

    while (current)
    {
        count++;
        next = current->next;
        free(current);
        if (next >= current)
        {
            *head = NULL;
            return count;
        }
        current = next;
    }

    *head = NULL;
    return count;
}

