#include <stdio.h>
#include <stdlib.h>

// Transform array
// How would you swap elements of an array like [a1 a2 a3 a4 b1 b2 b3 b4] to
// convert it into [a1 b1 a2 b2 a3 b3 a4 b4]?

void swap(int* a, int* b)
{
    if (*a == *b)
        return;

    *a ^= *b ^= *a ^= *b;
}

void transformArrayAB1(int* arr, int size)
{
    int n = size / 2;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int pos = n - i + 2 * j;
            swap(&arr[pos], &arr[pos + 1]);
        }
    }
}

int main()
{
    int arr[8] = { 11, 12, 13, 14, 21, 22, 23, 24 };

    for (int i = 0; i < 8; i++)
    {
        printf("[%d]", arr[i]);
    }
    printf("\n");

    transformArrayAB1(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        printf("[%d]", arr[i]);
    }
}