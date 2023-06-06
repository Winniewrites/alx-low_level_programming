#include <stdlib.h>
#include "lists.h"  // Assuming you have a header file named "lists.h" that defines the listint_t structure

size_t free_listint_safe(listint_t **head)
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

