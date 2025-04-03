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

void quickSelectUtil(int* arr, int lower, int upper, int k)
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
    swap(&arr[upper], &arr[lower]);
    if (k < upper)
        quickSelectUtil(arr, start, upper - 1, k);
    
    if (k > upper)
        quickSelectUtil(arr, upper + 1, stop, k);
}

int quickSelect(int* a, int count, int index)
{
    quickSelectUtil(a, 0, count - 1, index - 1);
    return a[index - 1];
}

int main()
{
    int arr[10] = { 4, 5, 3, 2, 6, 7, 1, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(int);

    printArr(arr, size);
    quickSelect(arr, size, 0);
    printArr(arr, size);
}