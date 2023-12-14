#include "sort.h"

/**
 * swap_int - swaps two integers values
 * @array: integer array to sort
 * @size: size of the array
 * @a: address of first val
 * @b: address of second val
 * Retuen: nothing
 */
void swap_int(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lumoto_partition - partitions the array
 * @array: integer array to sort
 * @size: size of the array
 * @high: high indx of the sort range
 * @low: low indx of the sort range
 * Return: size_t
 */
size_t lumoto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int p, i, pivot = array[high];

	for (p = i = low; i < high; i++)
		if (array[i] < pivot)
			swap_int(array, size, &array[i], &array[p++]);
	swap_int(array, size, &array[p], &array[high]);
	return (p);
}

/**
 * fast_sort - sorts using lumoto partitioning scheme
 * @array: integer array to sort
 * @size: size of the array
 * @high: high indx of the sort range
 * @low: low indx of the sort range
 * Return: nothing
 */
void fast_sort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t pivot = lumoto_partition(array, size, low, high);

		fast_sort(array, size, low, pivot - 1);
		fast_sort(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - calls fast_sort function
 * @array: integer array to sort
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	fast_sort(array, size, 0, size - 1);
}
