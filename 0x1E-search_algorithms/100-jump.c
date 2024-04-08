#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers using
 *               the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: the index where value is located, or -1 if value is not present
 *         in array or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size);
    size_t prev = 0;

    if (array == NULL)
        return (-1);

    printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
    while (array[(step < size ? step : size) - 1] < value)
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return (-1);
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, step);

    while (array[prev] < value)
    {
        if (++prev == (step < size ? step : size))
            return (-1);
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
    }

    if (array[prev] == value)
        return (prev);

    return (-1);
}
