#include "sort.h"
/**
 * quick_sort - performs quick sort algoritm to sort the given array
 * @array: sequence of numbers to be sorted
 * @size: size of the array
 *
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_alg(array, 0, size - 1, size);
}
/**
 * quick_sort_alg - performs quick sort algorithm to the given array
 * @array: tha array to be sorted using the algorithm
 * @lo: lower bound of the array
 * @hi: higher bound of the array
 * @size: the size of the original array
 *
*/
void quick_sort_alg(int *array, int lo, int hi, int size)
{
	int pivot;

	if (lo >= hi || lo < 0)
		return;

	pivot = partition_alg(array, lo, hi, size);

	quick_sort_alg(array, lo, pivot - 1, size);

	quick_sort_alg(array, pivot + 1, hi, size);

}
/**
 * partition_alg - partitions given array using Lomuto partition scheme
 * @lo: lower bound of the array
 * @hi: higher bound of the array
 * @array: the array to be partioned
 * @size: the size of the original array
 *
 * Return: position of the pivot
*/
int partition_alg(int *array, int lo, int hi, int size)
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
			if (array[i] != temp)
				print_array(array, size);

		}
	}
	i = i + 1;
	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;
	if (array[i] != temp)
		print_array(array, size);

	return (i);
}
