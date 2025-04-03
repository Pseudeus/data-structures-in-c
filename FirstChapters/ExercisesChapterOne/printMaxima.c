#include <stdio.h>

// 5 Print all the maxima's in an array.

void printMaxima(int* arr, int size)
{
    int max = 0;

    for (int i = 1; i < size - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            printf("Maxima at %d is: %d\d", i, arr[i]);
        }
    }
}