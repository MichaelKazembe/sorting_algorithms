#include "sort.h"

/**
 * swap - Swaps two integers
 * @swap1: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *swap1, int *b)
{
	int temp = *swap1;
	*swap1 = *swap2;
	*swap2 = temp;
}

/**
 * bitonic_merge - Merges two subarrays in a bitonic manner
 * @array: Array of integers.
 * @low: Starting index of the first subarray.
 * @count: Number of elements to be merged.
 * @dir: Sorting direction (0 for ascending, 1 for descending)
 */
void bitonic_merge(int *array, int low, int count, int dir)
{
	if (count > 1)
	{
		int k = count / 2;
		int i;

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
				swap(&array[i], &array[i + k]);
		}

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * @array: Array of integers
 * @low: Starting index of the sequence.
 * @count: Number of elements in the sequence.
 * @dir: Sorting direction (0 for ascending, 1 for descending)
 */
void bitonic_sort_recursive(int *array, int low, int count, int dir)
{
	if (count > 1)
	{
		int k = count / 2;

		bitonic_sort_recursive(array, low, k, 0);
		bitonic_sort_recursive(array, low + k, k, 1);

		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending
 * @array: Array of integers
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 0);
}
