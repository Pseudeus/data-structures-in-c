#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 13. Given an array of 0s, 1s and 2s. We need to sort it
// so that all the 0s are before all the 1s and all the 
// 1s are before 2s.

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[ %d ] ", arr[i]);
    }
    printf("\n");
}

void segregate(int* arr, int size, int valueToSort)
{
    if (size == 0) return;
    if (valueToSort == 0) return;

    int newSize;

    for (int i = 0, j = size - 1; i < j; i++)
    {
        while (arr[j] >= valueToSort)
        {
            j--;
        }
        if (arr[i] == valueToSort)
        {
            arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
            newSize = j;
            j--;

            printArr(arr, size);
        }
    }
    segregate(arr, newSize, valueToSort - 1);
}

int main()
{
    int arr[10];
    

    for (int i = 0; i < 9; i++)
    {
        arr[i] = (rand() / 5) % 4;
    }
    arr[9] = 0;
    printArr(arr, 10);

    segregate(arr, 10, 3);
    printArr(arr, 10);
}