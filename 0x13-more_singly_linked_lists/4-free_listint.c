#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 */
void free_listint(listint_t *head)
{
listint_t *temp;

while (head)
{
temp = head->next;
free(head);
head = temp;
}
}
#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list
 * @h: A pointer to the head node of the linked list
 *
 * Return: The number of nodes in the linked list
 */
size_t listint_len(const listint_t *h)
size_t count = 0;

while (h != NULL)
{
count++;
h = h->next;
}

return (count);
}
dgg

