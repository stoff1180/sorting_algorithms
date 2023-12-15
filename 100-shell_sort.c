#include "sort.h"

/**
 * max_gap - that gets the largest knuth sequence gap of the size
 * @size: size of the array
 * Return: size of gap
 */
ssize_t max_gap(size_t size)
{
	size_t n;

	for (n = 1; n < size;)
	{
		n = n * 3 + 1;
	}
	return ((n - 1) / 3);
}

/**
 * shell_sort - that sorts an array of integers using the Shell sort
 * @array: the integers array to sort
 * @size: size of the array
 * return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t i, k, gap;

	if (!array || !size)
		return;
	gap = max_gap(size);
	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (k = i; k >= gap && array[k - gap] > tmp; k -= gap)
			{
				array[k] = array[k - gap];
			}
			array[k] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
