#include <stdio.h>
#include <stdlib.h>
#include "lists.h"  


/**
 * print_listint_safe - prints a linked list, safely
 * @head: list of type listint_t to print
 *
 * Return: number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head;
    const listint_t *fast = head;
    size_t count = 0;

    if (head == NULL) {
        return 0;
    }

    while (fast != NULL && fast->next != NULL)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        count++;

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            printf("[%p] %d\n", (void *)slow, slow->n);
            printf("-> [%p] %d\n", (void *)fast->next, fast->next->n);
            count++;
            break;
        }
    }

    if (fast == NULL || fast->next == NULL)
    {
        while (slow != NULL)
        {
            printf("[%p] %d\n", (void *)slow, slow->n);
            count++;
            slow = slow->next;
        }
    }

    return count;
}

