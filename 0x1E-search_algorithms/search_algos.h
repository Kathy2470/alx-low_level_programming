#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>

/* Function prototypes */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;

/* Jump search in a singly linked list */
listint_t *jump_list(listint_t *list, size_t size, int value);

/* Data structure for skip list node */
typedef struct skiplist_s
{
    int n;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/* Linear skip search in a skip list */
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
