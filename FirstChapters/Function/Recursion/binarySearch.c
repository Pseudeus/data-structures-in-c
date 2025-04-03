#include <stdio.h>
#include <stdlib.h>

int BinarySearchRecursive(int* arr, int low, int high, int value)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;

    if (arr[mid] == value) return mid;

    else if (arr[mid] < value)
        return BinarySearchRecursive(arr, mid + 1, high, value);
    else
        return BinarySearchRecursive(arr, low, mid - 1, value);
}

int main()
{
    int* arr = (int*)malloc(50 * sizeof(int));

    for (int i = 0; i < 50; i++)
    {
        *(arr + i) = i + 5;
    }

    int index = BinarySearchRecursive(arr, 0, 50, 39);

    printf("%d", index);

    free(arr);
}