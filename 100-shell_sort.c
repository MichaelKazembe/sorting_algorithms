#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	int interval = 1;
	int i, j, temp;

	if (array == NULL || size < 2)
		return;

	while (interval < (int)size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (i = interval; i < (int)size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}

		interval = (interval - 1) / 3;

		print_array(array, size);
	}
}
