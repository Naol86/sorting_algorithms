#include "sort.h"
/**
 * shell_sort - sorts array using shell sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
*/
void shell_sort(int *array, size_t size)
{
	unsigned long int gap, i, j;
	int  temp, testarr, hol;

	gap = 1;
	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	gap /= 3;
	while (gap > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (i + gap > size)
				continue;
			for (j = 0; j < size; j++)
			{
				if ((unsigned long int)(i + j * gap) < size)
				{
					testarr = array[i + j * gap];
					hol = j;
					while (array[i + (hol - 1) * gap] > testarr && hol > 0)
					{
						temp = array[i + (hol - 1) * gap];
						array[i + (hol - 1) * gap] = array[i + hol * gap];
						array[i + hol * gap] = temp;
						hol -= 1;
					}
				}

			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
