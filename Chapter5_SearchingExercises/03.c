#include <stdio.h>
#include <stdlib.h>

/*
    Given an array of -ve and +ve numbers, write a program to separate -ve
    numbers from the +ve numbers.
*/

void swap(int* a, int* b)
{
    if (*a == *b) return;

    *a ^= *b ^= *a ^= *b;
}

void separatNegFromPosNums(int* arr, int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        if (arr[start] < 0)
            start++;
        else if (arr[end] > 0)
            end--;
        else
        {
            swap(&arr[start], &arr[end]);
            start++;
            end--;
        }
    }

    for (int i = 0; i < size; i++)
        printf("[%d]",arr[i]);
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
        arr[i] = rand() % 64 - 32;
        printf("[%d]",arr[i]);
    }
    printf("\n");
    // qsort(arr, 10, sizeof(int), compare);
    // for (int i = 0; i < 10; i++)
    //     printf("[%d]", arr[i]);

    separatNegFromPosNums(arr, 10);

    free(arr);
}