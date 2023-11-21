#include "sort.h"
/**
 * quick_sort - performs quick sort algoritm to sort the given array
 * @array: sequence of numbers to be sorted
 * @size: size of the array
 *
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_alg(array, 0, size-1);
}

void quick_sort_alg(int *array, int lo, int hi)
{
	int pivot;

	if (lo >= hi || lo < 0)
		return;
	
	pivot = partition_alg(array, lo, hi);

	quick_sort_alg(array, lo, pivot -1);
	quick_sort_alg(array, pivot + 1, hi);

}

int partition_alg(int *array, int lo, int hi)
{
	int pivot;
	int temp;
	int i, j;

	pivot = array[hi];
	i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	i = i + 1;
	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;
	return (i);
}