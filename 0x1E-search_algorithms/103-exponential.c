#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array using Exponential search
 * @array: A pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 * Return: The index where the value is located, or -1 if not found or if array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1, min;
    int result;

    if (array == NULL || size == 0)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    min = (bound < size - 1) ? bound : size - 1;
    printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, min);

    result = binary_search(array, bound / 2, min, value);
    return (result);
}

