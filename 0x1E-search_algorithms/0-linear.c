/**
 * linear_search - Search for a value in an array using linear search
 * @array: The array to search in
 * @size: The size of the array
 * @value: The value to search for
 *
 * Return: The index of the value if found, otherwise -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (array[i] == value)
			return (i);
	}

	return (-1);
}

