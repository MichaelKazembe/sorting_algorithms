#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @swap1: first int to swap with second
 * @swap2: second int to swap with first
 */
void swap(int *swap1, int *swap2)
{
	int temp = *swap1;
	*swap1 = *swap2;
	*swap2 = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size <= 1)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
