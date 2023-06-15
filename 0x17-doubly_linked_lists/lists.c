#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/* Function to print all elements of a doubly linked list */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;
    
    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        count++;
    }
    
    return count;
}

/* Function to get the length of a doubly linked list */
size_t dlistint_len(const dlistint_t *h)
{
    size_t count = 0;
    
    while (h != NULL)
    {
        h = h->next;
        count++;
    }
    
    return count;
}

/* Function to add a new node at the beginning of a doubly linked list */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    
    if (new_node == NULL)
        return NULL;
    
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;
    
    if (*head != NULL)
        (*head)->prev = new_node;
    
    *head = new_node;
    
    return new_node;
}

/* Function to add a new node at the end of a doubly linked list */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    dlistint_t *temp = *head;
    
    if (new_node == NULL)
        return NULL;
    
    new_node->n = n;
    new_node->next = NULL;
    
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return new_node;
    }
    
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = new_node;
    new_node->prev = temp;
    
    return new_node;
}

/* Function to free a doubly linked list */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *temp;
    
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* Function to get the node at a specific index in a doubly linked list */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int count = 0;
    
    while (head != NULL)
    {
        if (count == index)
            return head;
        
        head = head->next;
        count++;
    }
    
    return NULL;
}

/* Function to calculate the sum of all elements in a doubly linked list */
int sum_dlistint(dlistint_t *head)
{
    int sum = 0;
    
    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }
    
    return sum;
}

/* Function to insert a new node at a specific index in a doubly linked list */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    if (idx == 0)
        return add_dnodeint(h, n);
    
    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    dlistint_t *current = *h;
    
    if (new_node == NULL)
        return NULL;
    
    new_node->n = n;
    
    while (idx > 1)
    {
        if (current == NULL)
        {
            free(new_node);
            return NULL;
        }
        
        current = current->next;
        idx--;
    }
    
    if (current == NULL)
    {
        free(new_node);
        return NULL;
    }
    
    new_node->next = current->next;
    new_node->prev = current;
    
    if (current->next != NULL)
        current->next->prev = new_node;
    
    current->next = new_node;
    
    return new_node;
}

/* Function to delete a node at a specific index in a doubly linked list */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL)
        return -1;
    
    dlistint_t *current = *head;
    
    if (index == 0)
    {
        *head = current->next;
        
        if (current->next != NULL)
            current->next->prev = NULL;
        
        free(current);
        return 1;
    }
    
    for (unsigned int i = 0; current != NULL && i < index - 1; i++)
        current = current->next;
    
    if (current == NULL || current->next == NULL)
        return -1;
    
    dlistint_t *next = current->next->next;
    
    free(current->next);
    current->next = next;
    
    if (next != NULL)
        next->prev = current;
    
    return 1;
}

