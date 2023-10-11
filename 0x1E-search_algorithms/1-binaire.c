#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
/**
  * binary_search - searches for a value in an array of integers using
  * the binary search algorithm
  * assumes that the array is sorted in asc order
  * also assumes that value won't appear twice in the array
  * prints the array being searched every time it changes.
  * @array: pointer to the first element of the array to search in
  * @size: number of elements in array
  * @value: value to search for
  * Return: return index of value, if value is not present in array or
  * if array is NULL, returns -1
  */
int binary_search(int *array, size_t size, int value)
{
	size_t index = 0, j = size - 1, m;

	if (array)
	{
		while (index <= j)
		{
			printf("Searching in array: ");
			for (m = index; m < j; m++)
				printf("%d, ", array[m]);
			printf("%d\n", array[m]);
			m = (index + j) / 2;
			if (array[m] < value)
				index = m + 1;
			else if (array[m] > value)
				j = m - 1;
			else
				return (m);
		}
	}
	return (-1);
}