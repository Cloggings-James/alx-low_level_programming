#include <stddef.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: pointer to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
char *str;
struct list_s *next;
} list_t;

/**
 * list_len - returns the number of elements in a linked list_t list.
 * @h: head of the list.
 *
 * Return: The number of elements in the list.
 */
size_t list_len(const list_t *h)
{
size_t count = 0;

while (h != NULL)
{
count++;
h = h->next;
}

return (count);
}
}

