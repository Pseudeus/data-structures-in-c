#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Given a sorted array, find a given number. If found return the index if not,
    find the index of that number if it is inserted into the array.
*/

int findNumber(int* arr, int size, int value, bool* found)
{
    int start = 0;
    int end = size - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == value)
        {
            *found = true;
            return mid;
        }
        else if (arr[mid] < value)
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    if (arr[mid] < value)
        return mid + 1;
    else
        return mid;
}

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}

int main()
{
    int* arr = (int*)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 16 + 1;
        printf("[%d]", arr[i]);
    }

    qsort(arr, 10, sizeof(int), compare);

    printf("\n");

    for (int i = 0; i < 10; i++)    
        printf("[%d]", arr[i]);

    bool found = false;
    int index = findNumber(arr, 10, 9, &found);

    printf("\n[%d][ %d ]\n", found, index);

    free(arr);
}