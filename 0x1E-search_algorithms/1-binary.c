#include <stdio.h>

/**
 * binary_search - Search for a value in a sorted array using binary search
 * @array: A pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where the value is located, or -1 if not found or on error
 */
int binary_search(int *array, size_t size, int value)
{
    if (array == NULL)
        return (-1);

    size_t left = 0;
    size_t right = size - 1;

    while (left <= right)
    {
        size_t mid = (left + right) / 2;

        printf("Searching in array: ");
        for (size_t i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        if (array[mid] == value)
            return (mid);

        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);
}

