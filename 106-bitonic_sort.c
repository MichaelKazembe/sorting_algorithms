#include "sort.h"

/**
 * swap - Swaps two integers
 * @swap1: Pointer to the first integer
 * @swap2: Pointer to the second integer
 */
void swap(int *swap1, int *swap2)
{
	int temp = *swap1;
	*swap1 = *swap2;
	*swap2 = temp;
}
/**
 * bitonic_merge - sorts and merges a sequence in ascending or descending order
 * @array: array to sort
 * @low: index of the left-most element
 * @count: index of the right-most element
 * @dir: ascending or descending
 */
void bitonic_merge(int *array, int low, int count, int dir)
{
	int i, step = (low + count) / 2, mid = (count - low + 1) / 2;

	if (count - low >= 1)
	{
		for (i = low; i < low + mid; i++)
		{
			if (dir == (array[i] > array[i + mid]))
			{
				swap(&array[i + mid], &array[i]);
			}
		}
		bitonic_merge(array, low, step, dir);
		bitonic_merge(array, step + 1, count, dir);
	}
}

/**
 * bitonic_recursion - recursive function for bitonic sort
 * @array: array to sort
 * @low: index of the left-most element
 * @count: index of the right-most element
 * @dir: ascending or descending
 * @size: size of the array
 */
void bitonic_recursion(int *array, int low, int count, int dir, size_t size)
{
	int step;

	if (count - low >= 1)
	{
		step = (count + low) / 2;
		printf("Merging [%d/%lu] ", count - low + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count - low + 1);
		bitonic_recursion(array, low, step, 1, size);
		bitonic_recursion(array, step + 1, count, 0, size);
		bitonic_merge(array, low, count, dir);
		printf("Result [%d/%lu] ", count - low + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count - low + 1);
	}
}

/**
 * bitonic_sort - sorts an array following the Bitonic sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursion(array, 0, size - 1, 1, size);
}
