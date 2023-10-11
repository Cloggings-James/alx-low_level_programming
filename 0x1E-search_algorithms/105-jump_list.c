#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list using Jump search
 * @list: A pointer to the head of the list to search in
 * @size: The number of nodes in the list
 * @value: The value to search for
 * Return: A pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    listint_t *current, *next;
    size_t jump = sqrt(size), prev = 0;

    if (list == NULL || size == 0)
        return (NULL);

    current = list;
    while (current->index < size && current->n < value)
    {
        prev = current->index;
        while (current->next && current->index < jump)
            current = current->next;
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, current->index);
    current = list;
    while (current->index < prev)
        current = current->next;

    while (current && current->index <= size && current->n <= value)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->n == value)
            return (current);
        current = current->next;
    }

    return (NULL);
}

