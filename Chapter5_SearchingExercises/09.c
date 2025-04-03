#include <stdio.h>
#include <stdlib.h>

/*
    Find max in sorted rotated array.
*/

int findMin(int* arr, int size)
{
    int start = 0;
    int end = size - 1;
    int mid;

    if (arr[start] < arr[end]) return start;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
            return mid;
        else if (arr[mid] < arr[end])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}

void reverse(int* arr, int size)
{
    if (size == 0) return;

    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        if (arr[i] == arr[j]) continue;
        arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
    }
}

void rotate(int* arr, int size, int k)
{
    if (size <= 1) return;

    reverse(arr, k % size);
    reverse(&arr[k % size], size - k % size);
    reverse(arr, size);
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("[ %02d ]", arr[i]);
    printf("\n");
}

int main()
{
    int* arr = (int*)calloc(10, sizeof(int));

    for (int i = 0; i < 10; i++)
        arr[i] = rand() % 16 + 1;
    
    printArr(arr, 10);
    qsort(arr, 10, sizeof(int), compare);
    printArr(arr, 10);
    rotate(arr, 10, 4);
    printf("\n");
    printArr(arr, 10);
    int maxIndex = findMin(arr, 10);

    printf("[%d][ %d ]", maxIndex, arr[maxIndex]);
    printf("\n");
    free(arr);
}