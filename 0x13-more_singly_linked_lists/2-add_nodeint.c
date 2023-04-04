#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list
 * @head: Pointer to the pointer of the head node
 * @n: Value of the new node to be added
 *
 * Return: Address of the new element or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

/* Allocate memory for the new node */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

/* Initialize the new node with the given value */
new_node->n = n;

/* Make the new node point to the current head */
new_node->next = *head;

/* Update the head to point to the new node */
*head = new_node;

/* Return the address of the new element */
return (new_node);
}

