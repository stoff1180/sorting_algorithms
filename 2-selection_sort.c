#include "sort.h"

/**
 * selection_sort - That sorts an array of integers in ascending order
 * @array: array to be sort
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, key;
	int tmp;

	if (!array || !size)
		return;
	while (i < size - 1)
	{
		for (j = size - 1, key = i + 1; j > i; j--)
		{
			if (array[j] < array[key])
			{
				key = j;
			}
		}
		if (array[i] > array[key])
		{
			tmp = array[i];
			array[i] = array[key];
			array[key] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
