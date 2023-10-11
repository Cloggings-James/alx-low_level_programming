#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array using advanced binary search
 * @array: A pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 * Return: The index where the value is located, or -1 if not found or if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (binary_search(array, 0, size - 1, value));
}

