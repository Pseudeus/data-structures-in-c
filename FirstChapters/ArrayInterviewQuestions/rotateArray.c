#include <stdio.h>

void rotateArray(int *a, int n, int k)
{
    reverseArray(a, k);
    reverseArray(&a[k], n - k);
    reverseArray(a, n);
}

void reverseArray(int *a, int n)
{
    for (int i = 0, j = n-1; i < j; i++, j--)
    {
        a[i] ^= a[j] ^= a[i] ^= a[j];
    }
}

void main()
{
    int arr[6];
    for (int i = 0; i < 6; i++)
        arr[i] = (i + 1) * 10;

    rotateArray(arr, 6, 2);

    for (int i = 0; i < 6; i++)
    {
        printf("[%d]", arr[i]);
    }
}