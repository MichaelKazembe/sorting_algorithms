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
 * @low_idx: Starting index of the partition
 * @high_idx: Ending index of the partition
 *
 * Return: Index of the pivot element
 */
int partition(int array[], int low_idx, int high_idx)
{
	int pivot = array[high_idx];
	int i = low_idx - 1;
	int j;
    
	for (j = low_idx; j <= high_idx; j++)  
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high_idx + 1);
		}
	}
	swap(&array[i + 1], &array[high_idx]);
	print_array(array, high_idx + 1);
	return (i + 1);
}
/**
 * quick_sort_helper - Recursive helper function for Quick sort
 *
 * @array: The array to be sorted
 * @low_idx: Starting index of the partition
 * @high_idx: Ending index of the partition
 */
void quick_sort_helper(int *array, int low_idx, int high_idx)
{
	if (low_idx < high_idx)
	{
		int pi = partition(array, low_idx, high_idx);

		quick_sort_helper(array, low_idx, pi - 1);
		quick_sort_helper(array, pi + 1, high_idx);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1);
}
