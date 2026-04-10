#include <stddef.h>
#include "sort.h"

/**
 * sort_subtree - Recursively call itself to
 *   split array in "sorted" (left) and "unsorted" (right)
 *   relative to a "pivot value" until array given
 *   is size 1.
 * @array: part of the tree to sort
 * @start: beginning point of tree
 * @size:  size of the subsection of the full array
 */
void sort_subtree(int *array, int start, int size)
{
	size_t idx_pivot;
	int temp;
	int i;
	size_t j;
	int end;

	if (!array || size < 2)
		return;

	/* Define the number used to separate in "lower than" and "higher than". */
	/* We pick the "last of array" by choice. */
	end = start + size - 1;
	idx_pivot = end;
	i = start - 1;

	for (j = start; j < (size_t)end; j++)
	{
		/* Whenever we find a lower or equal value we use swap */
		/* to put it at the "first available space of sorted section". */
		if (array[j] <= array[idx_pivot])
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
	/* We finished parsing so we put pivot at its place.*/
	temp = array[idx_pivot];
	array[idx_pivot] = array[i + 1];
	array[i + 1] = temp;

	idx_pivot = i + 1;

	/* Recursively call on left subtree to sort */
	sort_subtree(array, start, idx_pivot - start);

	/* Recursively call on left subtree to sort */
	sort_subtree(array, idx_pivot + 1, end - idx_pivot);
}

/**
 * quick_sort - Sorts an array by combining sub-partitioning
 *   and reordering recursively until each subpartition is size 1.
 * @array: array to sort
 * @size: array size (required to know the loop limit)
 */
void quick_sort(int *array, size_t size)
{
	sort_subtree(array, 0, (int)size);
}

