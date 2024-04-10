#include <stdio.h>
#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: the index where value is located, or -1 if value is not present
 *         in array or if array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    if (array[0] == value)
    {
        printf("Value checked array[0] = [%d]\n", array[0]);
        return 0;
    }

    size_t bound = 1;
    while (bound < size && array[bound] <= value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    size_t left = bound / 2;
    size_t right = bound < size - 1 ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", left, right);

    return binary_search(array, left, right, value);
}

/**
 * binary_search - searches for a value in a sorted array of integers
 *                 using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @left: left index of the array or subarray
 * @right: right index of the array or subarray
 * @value: value to search for
 *
 * Return: the index where value is located, or -1 if value is not present
 *         in array or if array is NULL
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
    if (array == NULL)
        return -1;

    while (left <= right)
    {
        size_t mid = left + (right - left) / 2;

        printf("Searching in array: ");
        for (size_t i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        if (array[mid] == value)
            return mid;
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
