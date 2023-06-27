#include "sort.h"

/**
 * merge - Merge two subarrays into one sorted array.
 * @array: The original array.
 * @left: The left subarray.
 * @left_size: The size of the left subarray.
 * @right: The right subarray.
 * @right_size: The size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i, j, k;
	int *temp;

	temp = malloc(sizeof(int) * (left_size + right_size));
	if (temp == NULL)
		return;

	i = j = k = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}

	while (i < left_size)
		temp[k++] = left[i++];
	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0; i < (left_size + right_size); i++)
		array[i] = temp[i];

	free(temp);
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	if (size > 1)
	{
		size_t i;
		size_t mid = size / 2;
		size_t left_size = mid;
		size_t right_size = size - mid;
		int *left = array;
		int *right = array + mid;

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		printf("Merging...\n[left]: ");
		for (i = 0; i < left_size; i++)
			printf("%d ", left[i]);
		printf("\n[right]: ");
		for (i = 0; i < right_size; i++)
			printf("%d ", right[i]);
		printf("\n");

		merge(array, left, left_size, right, right_size);

		printf("[Done]: ");
		for (i = 0; i < size; i++)
			printf("%d ", array[i]);
		printf("\n");
	}
}
