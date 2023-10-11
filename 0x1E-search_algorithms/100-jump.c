#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using Jump search.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where the value is located.
 *         -1 if the value is not present in the array or if the array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = (size_t)sqrt(size);
    size_t prev = 0;

    if (array == NULL || size == 0)
        return -1;

    printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
    while (array[prev] < value)
    {
        prev = step;
        if (prev >= size)
            break;
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);

    for (; prev >= (prev - step); prev--)
    {
        if (array[prev] == value)
        {
            printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
            return prev;
        }
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
    }

    return -1;
}

