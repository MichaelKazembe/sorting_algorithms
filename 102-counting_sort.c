#include "sort.h"

/**
 * get_maximum - Get the max value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The max integer in the array.
 */
int get_maximum(int *array, int size)
{
	int max;
	int i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm
 * @array: an array of integers.
 * @size: size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *output, max;
	int i;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);

	if (output == NULL)
		return;

	max = get_maximum(array, size);
	count = malloc(sizeof(int) * (max + 1));

	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
