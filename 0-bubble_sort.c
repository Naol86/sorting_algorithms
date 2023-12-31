#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending
 * order using the bubble sort algorithm.
 * @array: a pointer to the array of integers to be sorted.
 * @size: the number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	unsigned int i, j, count = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				count++;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		if (count == 0)
			break;
	}
}
