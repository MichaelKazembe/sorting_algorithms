#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @swap1: First integer to swap with second
 * @swap2: Second integer to swap with first
 */
void swap(int *swap1, int *swap2)
{
	int temp = *swap1;
	*swap1 = *swap2;
	*swap2 = temp;
}

/**
 * partition - Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @size: Size of the array
 * @left: Starting index of the partition
 * @right: Ending index of the partition
 *
 * Return: Index of the pivot element
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot;
	int low_idx, high_idx;

	pivot = array + right;
	for (high_idx = low_idx = left; low_idx <= right; low_idx++)
	{
		if (array[low_idx] < *pivot)
		{
			if (high_idx < low_idx)
			{
				swap(array + low_idx, array + high_idx);
				print_array(array, size);
			}
			high_idx++;
		}
	}

	if (array[high_idx] > *pivot)
	{
		swap(array + high_idx, pivot);
		print_array(array, size);
	}

	return (high_idx);
}

/**
 * sort_helper - Recursive helper function for quicksort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the partition to order.
 * @right: The ending index of the partition to order.
 */
void sort_helper(int *array, size_t size, int left, int right)
{
	int pi;

	if (right - left > 0)
	{
		pi = partition(array, size, left, right);
		sort_helper(array, size, left, pi - 1);
		sort_helper(array, size, pi + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_helper(array, size, 0, size - 1);
}
