#include "sort.h"

/**
 * merge_subarray - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @temp: A temp to store the sorted subarray.
 * @R: The front index of the subarray.
 * @mid: The middle index of the subarray.
 * @L: The back index of the subarray.
 */
void merge_subarray(int *subarray, int *temp, size_t R, size_t mid, size_t L)
{
	size_t i, j, k = 0;

	printf("Merging...\n[L]: ");
	print_array(subarray + R, mid - R);

	printf("[R]: ");
	print_array(subarray + mid, L - mid);

	for (i = R, j = mid; i < mid && j < L; k++)
		temp[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < mid; i++)
		temp[k++] = subarray[i];
	for (; j < L; j++)
		temp[k++] = subarray[j];
	for (i = R, k = 0; i < L; i++)
		subarray[i] = temp[k++];

	printf("[Done]: ");
	print_array(subarray + R, L - R);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @temp: A temp to store the sorted result.
 * @R: The front index of the subarray.
 * @L: The back index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *temp, size_t R, size_t L)
{
	size_t mid;

	if (L - R > 1)
	{
		mid = R + (L - R) / 2;
		merge_sort_recursive(subarray, temp, R, mid);
		merge_sort_recursive(subarray, temp, mid, L);
		merge_subarray(subarray, temp, R, mid, L);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}

