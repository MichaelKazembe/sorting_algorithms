#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	size_t max = array[0];
	size_t i, j;
	int *count, *output;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		return;
	}

	for (i = 0; i <= max; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	for (i = 0; i <= max; i++)
	{
		print_array(array, size);
	}


	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	j = 0;
	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			output[j] = i;
			count[i]--;
			j++;
		}
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(count);
	free(output);
}
