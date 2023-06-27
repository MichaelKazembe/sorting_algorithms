#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @swap1: First integer to swap
 * @bswap2 Second integer to swap
 */
void swap(int *swap1, int *swap2)
{
	int temp = *swap1;
	*swap1 = *swap2;
	*swap2 = temp;
}
/**
 * heapify - puts array in a heap.
 * @array: array of ints.
 * @min: min in array
 * @max: max int in array
 * @size: size of array
 */
void heapify(int *array, int min, int max, size_t size)
{
	int root = min;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (right < max && array[right] > array[root])
		root = right;

	if (left < max && array[left] > array[root])
		root = left;

	if (min != root)
	{
		swap(&array[min], &array[root]);
		print_array(array, size);
		heapify(array, root, max, size);
	}
}
/**
 * heap_sort - heap sort algorithm.
 * @array: array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, i, size, size);

	i = size - 1;
	while (i > 0)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, 0, i, size);
		i--;
	}
}
