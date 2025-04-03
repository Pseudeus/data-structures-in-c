#include <stdio.h>
#include <stdlib.h>

// 12. Given an array of 0s and 1s. We need to sort it so that all the 0s
// are before all the 1s.

void printArr(int* arr)
{
    for (int i = 0; i < 10; i++)
    {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

// Reverse an array in-place.
void segregate(int* arr, int size)
{
    if (size == 0) return;
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        if (arr[i] == arr[j] && arr[i] == 0) 
        {
            for (int k = i; k < j; k++)
            {
                if (arr[k] > arr[j])
                {
                     arr[j] ^= arr[k] ^= arr[j] ^= arr[k];
                     break;
                }
            }
            printArr(arr);
            continue;
        }
        if (arr[i] == arr[j] && arr[i] == 1) 
        {
            for (int k = j; k > i; k--)
            {
                if (arr[k] < arr[i])
                {
                     arr[i] ^= arr[k] ^= arr[i] ^= arr[k];
                     break;
                }
            }
            printArr(arr);
            continue;
        }
        if (arr[i] > arr[j])
        {
            arr[i] ^= arr[j] ^= arr[i] ^= arr[j];

            printArr(arr);
        }
    }
}



int main()
{
    int arr[10];

    for (int i = 0; i < 9; i++)
    {
        arr[i] = (i * 5 - 2) % 2;
        printf("[%d] ", arr[i]);
    }
    arr[9] = 0;
    printf("[%d]", arr[9]);
    printf("\n");

    segregate(arr, 10);
}