#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers using
 *                 the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: the index where value is located, or -1 if value is not present
 *         in array or if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid;

	if (array == NULL)
	return (-1);

	while (left <= right)
	{
	mid = (left + right) / 2;

	printf("Searching in array: ");
	for (size_t i = left; i <= right; i++)
	{
	    printf("%d", array[i]);
	    if (i < right)
	        printf(", ");
	}
	printf("\n");

	if (array[mid] == value)
	    return (mid);
	else if (array[mid] < value)
	    left = mid + 1;
	else
	    right = mid - 1;
	}

	return (-1);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t size = sizeof(array) / sizeof(array[0]);
	int value = 5;
	int index = binary_search(array, size, value);

	if (index != -1)
	printf("Found %d at index %d\n", value, index);
	else
        printf("%d not found in the array\n", value);

	return (0);
}
