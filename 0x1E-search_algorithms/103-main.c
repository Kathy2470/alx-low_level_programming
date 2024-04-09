#include <stdio.h>
#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers
 *                       using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: the index where value is located, or -1 if value is not present
 *         in array or if array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;

    if (array == NULL || size == 0)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, (bound < size ? bound : size) - 1);

    return binary_search(array, bound < size ? bound : size, value);
}
