#include "sort.h"

/**
 * max_number - Find the maximum number in an array.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum number in the array.
 */
int max_number(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * count_sort - Perform counting sort based on a specific digit.
 * @array: Array of integers.
 * @size: Size of the array.
 * @exp: The exponent of the current digit being considered.
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < (size_t)-1; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sort an array of integers in ascending order
 *              using the Radix sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int exp = 1;
	int max = max_number(array, size);

	if (size < 2)
		return;

	while (max / exp > 0)
	{
		count_sort(array, size, exp);
		print_array(array, size);
		exp *= 10;
	}
}
