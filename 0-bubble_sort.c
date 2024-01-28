#include "sort.h"

/**
  * bubble_sort - A function for bubble sorting.
  * @array: The array.
  * @size: THe length aray.
  * Return: Nothing.
  */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, n = 0;
	int aux = 0;

	if (array == NULL || size == 0)
		return;
	for (; i < size - 1; i++)
	{
		for (n = 0; n < size - i - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				aux = array[n + 1];
				array[n + 1] = array[n];
				array[n] = aux;
				print_array(array, size);
			}
		}
	}
}