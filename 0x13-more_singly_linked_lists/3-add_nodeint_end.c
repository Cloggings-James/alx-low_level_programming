#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
int n;
struct listint_s *next;
} listint_t;

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: pointer to pointer to first node of list
 * @n: integer to be included in the new node
 *
 * Return: Address of the new element or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *current_node;

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
}
else
{
current_node = *head;
while (current_node->next != NULL)
current_node = current_node->next;

current_node->next = new_node;
}

return (new_node);
}

