#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int count)
{
    printf("Values stored in the array are: ");
    for (int i = 0; i < count; i++)
    {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

void swap(int* arr, int x, int y)
{
    if (x == y)return;
    if (arr[x] == arr[y]) return;
    arr[x] ^= arr[y] ^= arr[x] ^= arr[y];
}

void permutation(int *arr, int i, int length)
{
    if (length == i)
    {
        printArray(arr, length);
        return;
    }

    for (int j = i; j < length; j++)
    {
        swap(arr, i, j);
        permutation(arr, i + 1, length);
        swap(arr, i, j);
    }
}

int main()
{
    int* arr = (int*)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }

    permutation(arr, 0, 5);
    free(arr);
}