#include "search_algos.h"
/**
 * linear_search - searches for int val in an array
 * @array: pointer to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first idnex where value is located
 */


int linear_search(int *array, size_t size, int value)
{
	size_t index;

	if (array == NULL)
		return (-1);
	for (index = 0; index < size; index++)
	{
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);
		if (array[index] == value)
			return (index);
	}
	return (-1);
}