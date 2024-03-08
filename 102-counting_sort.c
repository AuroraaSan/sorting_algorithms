#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *sorted_array;
    int max = 0, i, j = 0;

    if (!array || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create and initialize the count array */
    count_array = malloc(sizeof(int) * (max + 1));
    if (!count_array)
        return;
    for (i = 0; i <= max; i++)
        count_array[i] = 0;

    /* Count occurrences of each element in the array */
    for (i = 0; i < (int)size; i++)
        count_array[array[i]]++;

    /* Update count_array to store the actual position of elements */
    for (i = 1; i <= max; i++)
        count_array[i] += count_array[i - 1];

    /* Create the sorted array */
    sorted_array = malloc(sizeof(int) * size);
    if (!sorted_array)
    {
        free(count_array);
        return;
    }

    /* Fill the sorted array using count_array */
    for (i = size - 1; i >= 0; i--)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    /* Copy the sorted array back to the original array */
    for (i = 0; i < (int)size; i++)
        array[i] = sorted_array[i];

    /* Print the count array */
    printf("%d", count_array[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", count_array[i]);
    printf("\n");

    /* Free memory */
    free(count_array);
    free(sorted_array);
}
