#include <stddef.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array by iteratively
 *  pushing the lowest items to the beginning
 *  to have them in ascending order.
 * @array: array to sort
 * @size: array size (required to know the loop limit)
 */
void selection_sort(int *array, size_t size)
{
	/* Algo summary. */
	/* We use a 2-level loop to parse each element and check if */
	/*   it is or not the lowest of "the remaining portion to sort". */
	/* If yes, we swap it with the "lowest found". */
	/* This kinda "splits" the array between "the sorted part" on left */
	/*   and the "needs to be sorted" part which is reduced in size with */
	/*   each iteration. */

	size_t i;          /* Idx of cell "in process of being sorted" (current) */
	size_t j;          /* Idx used to compare remaining cells (compared) */
	size_t idx_lowest; /* Idx of cell with lowest value in "unsorted" part */
	int temp;

	if (!array || size < 2)
	return;

	for (i = 0; i < size; i++)
	{
		idx_lowest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx_lowest])
				idx_lowest = j;
		}
		if (idx_lowest != i)
		{
			temp = array[i];
			array[i] = array[idx_lowest];
			array[idx_lowest] = temp;
			print_array(array, size);
		}
	}
}
