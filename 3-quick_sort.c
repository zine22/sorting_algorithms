#include "sort.h"

/**
* swap - swaps elements in array
* @a: first element
* @b: second element
*/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
* 
*
*
*/

int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != hi)
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 *
 *
 *
 */

void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int p = partition(array, lo, hi, size);

		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}

/**
*
*
*
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
