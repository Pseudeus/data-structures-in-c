#include <stdio.h>


// 8 Given an array with value 0 or 1, write a program to segregate 0 on the
// left side and 1 on the right side.
void segregateArray(int* arr, int size)
{
    for (int i = 0, j = size -1; i < j; i++, j--)
    {
        if (arr[i] > arr[j])
            arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
    }
}

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i % 2;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("[%d]", arr[i]);
    }

    printf("\n");

    segregateArray(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("[%d]", arr[i]);
    }
}