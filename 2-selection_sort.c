#include "sort.h"

/**
* selection_sort - func to do selection sort to array
* @array: arg
* @size: arg
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (size >= 2)
	{
		for (i = 0; i < (size - 1); i++)
		{
			min = i;

			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min])
				{
					/* update min */
					min = j;
				}
			}
			if (min != i)
			{
				temp = array[i];
				array[i] = array[min];
				array[min] = temp;
				print_array(array, size);
			}
		}
	}
}
