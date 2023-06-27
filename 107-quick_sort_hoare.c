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
 * partition - this partitions the array and swaps
 * @array: input array
 * @low: input low index
 * @high: input high index
 * @size: input size of array
 * Return: return the partioned index
 */
int partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i > j)
			return (j);
		if (i == j)
			return (j - 1);

		swap(&array[j], &array[i]);
		print_array(array, size);
	}
}
/**
 * quicksort - sorts array using quick sort method
 * @array: input array
 * @low: minimum point
 * @high: maximum point
 * @size: input size of array
 */
void quicksort(int *array, int low, int high, size_t size)
{

	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quicksort(array, low, pi, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array using quick sort method
 * @array: input array
 * @size: input size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	unsigned int low = 0;
	unsigned int high = size - 1;

	if (size == 0 || size < 2)
		return;

	quicksort(array, low, high, size);
}
