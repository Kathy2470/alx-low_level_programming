#include <stdio.h>
#include "search_algos.h"


/**
 * advanced_binary_recursive - Recursive helper function for advanced_binary
 * @array: Pointer to the first element of the array
 * @left: Index of the left boundary of the subarray
 * @right: Index of the right boundary of the subarray
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid, i;

	if (left > right)
	return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	mid = (left + right) / 2;

	if (array[mid] == value)
	{
	if (mid == 0 || array[mid - 1] != value)
		return (mid);
	else
		return (advanced_binary_recursive(array, left, mid, value));
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, right, value));
	else
		return (advanced_binary_recursive(array, left, mid, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers using
 *                   the Advanced Binary search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
