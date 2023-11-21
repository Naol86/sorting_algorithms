#include "sort.h"

/**
 * selection_sort - performs selection sort algoritm to sort the given array
 * @array: sequence of numbers to be sorted
 * @size: size of the array
 *
*/
void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, pos;
	int min;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = size - 1; j > i; j--)
		{
			if (min > array[j])
			{
				min = array[j];
				pos = j;
			}
		}
		if (array[i] != min)
		{
			array[pos] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
