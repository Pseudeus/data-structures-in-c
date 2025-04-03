#include <stdio.h>

// 7 Print alternate elements in an array.

void printAlternate(int* arr, int size)
{
    for (int i = 0; i < size; i+=2)
    {
        printf("%d\n", arr[i]);
    }
}