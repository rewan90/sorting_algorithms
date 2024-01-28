#include "sort.h"

/**
 * quick_sort - function sorts array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array size
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
  * quick_sort_rec - ...
  * @array: ...
  * @lower: ...
  * @higher: ...
  * @size: ...
  *
  * Return: Nothing!
  */
void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
	int l_p = 0;

	if (lower < higher)
	{
		l_p = lomuto_partition(array, lower, higher, size);
		quick_sort_rec(array, lower, l_p - 1, size);
		quick_sort_rec(array, l_p + 1, higher, size);
	}
}

/**
  * lomuto_partition - ...
  * @array: ...
  * @lower: ...
  * @higher: ...
  * @size: ...
  *
  * Return: Nothing!
  */
int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, n = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = lower;

	for (n = lower; n < higher; ++n)
	{
		if (array[n] < pivot)
		{
			aux = array[i];
			array[i] = array[n];
			array[n] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}

	aux = array[i];
	array[i] = array[higher];
	array[higher] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}