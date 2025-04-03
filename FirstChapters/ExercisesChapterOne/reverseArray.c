#include <stdio.h>
#include <stdlib.h>

// 11 Reverse an array in-place.
void reverseArray(int* arr, int size)
{
    if (size == 0) return;
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        if (arr[i] == arr[j]) continue;
        arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
    }
}

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i * 5 - 2;
        printf("[%2d] ", arr[i]);
    }
    printf("\n");

    reverseArray(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("[%2d] ", arr[i]);
    }
}