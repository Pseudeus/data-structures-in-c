#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    if (*a == *b) return;

    *a ^= *b ^= *a ^= *b;
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("[%d]", arr[i]);
    printf("\n");
}

void quickSortUtil(int* arr, int lower, int upper)
{
    if (upper <= lower) return;

    int pivot = arr[lower];

    int start = lower;
    int stop = upper;

    while (lower < upper)
    {
        while (arr[lower] <= pivot)
            lower++;
        
        while (arr[upper] > pivot)
            upper--;
        
        if (lower < upper)
            swap(&arr[upper], &arr[lower]);
    }
    swap(&arr[upper], &arr[start]);
    quickSortUtil(arr, start, upper - 1);
    quickSortUtil(arr, upper + 1, stop);
}

void quickSort(int* arr, int size)
{
    quickSortUtil(arr, 0, size - 1);
}

int main()
{
    int arr[10] = { 4, 5, 3, 2, 6, 7, 1, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(int);

    printArr(arr, size);
    quickSort(arr, size);
    printArr(arr, size);
}