#include "search_algos.h"

/**
 * jump_search - searches for value in a sorted array
 * @array: pointer to first element of array
 * @size: length of array
 * @value: value to search for
 * Return: first index where value is located
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t left = 0;
	size_t right = 0;

	if (!array || size == 0)
	{
		return (-1);
	}
	while (right < size && array[right] < value)
	{
		printf("Value checked array[%d] = [%d]\n", (int)right, array[right]);
		left = right;
		right += step;
		if (left >= size)
		{
			return (-1);
		}
	}
	printf("Value found between indexes [%d] and [%d]\n", (int)left, (int)right);
	right = (right >= size) ? size - 1 : right;
	for (; left <= right; left++)
	{
		printf("Value checked array[%d] = [%d]\n", (int)left, array[left]);
		if (array[left] == value)
		{
			return ((int)left);
		}
	}
	return (-1);
}