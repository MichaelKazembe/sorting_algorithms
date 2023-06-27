#include "sort.h"

/**
 * print_part - prints part of the list
 * @array: input array
 * @L: start of array
 * @R: end of array
 */
void print_part(int *array, size_t L, size_t R)
{
	size_t i;

	i = L;
	while (i < R)
	{
		if (i > L)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * top_down - merge using top down method
 * @A: input left array
 * @B: input right array
 * @L: start of array
 * @mid: mid of the array
 * @R: end of array
 */
void top_down(int *A, int *B, size_t L, size_t mid, size_t R)
{
	size_t i = L, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_part(A, L, mid);
	printf("[right]: ");
	print_part(A, mid, R);
	for (k = L; k < R; k++)
	{
		if (i < mid && (j >= R || A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_part(B, L, R);
	for (k = L; k < R; k++)
		A[k] = B[k];
}

/**
 * top_down_split - split into 2
 * @A: input left array
 * @B: input right array
 * @L: start of array
 * @R: end of array
 */
void top_down_split(int *A, int *B, size_t L, size_t R)
{
	size_t mid;

	if (R - L < 2)
		return;
	mid = (L + R) / 2;
	top_down_split(A, B, L, mid);
	top_down_split(A, B, mid, R);
	top_down(A, B, L, mid, R);
}

/**
 * merge_sort - sort array using merge method
 * @array: input array
 * @size: input size of array
 */
void merge_sort(int *array, size_t size)
{
	int *new_list;

	if (size == 0 || size < 2)
		return;
	new_list = malloc(sizeof(int) * size);
	if (new_list == NULL)
		return;
	top_down_split(array, new_list, 0, size);
	free(new_list);
}
