#include "lists.h"
#include <stdio.h>
/**
 *print_listint - Prints all the elements of a listint_t list.
 *@h: Pointer to the head node of the list.
 *Return: The number of nodes in the list.
*/

size_t print_listint(const listint_t *h)
{
	size_t counter;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		counter++;
	}
	return (counter);
}
