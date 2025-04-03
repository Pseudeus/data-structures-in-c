#include <stdio.h>
#include <stdlib.h>

// Given an array of 0's and 1's. All the 0's come bejore 1's. Write an algorithm
// to find the index of the first 1.

int binarySearch01(int* arr, int size)
{
    int start = 0;
    int end = size - 1;
    int mid;

    // Manage edge cases
    if (arr[0] == 1)
        return 0;
    if (arr[end] == 0)
        return size;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == 1 && arr[mid - 1] == 0)
            return mid;
        else if (arr[mid] == 0)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

int binarySearch01Wrapper(int* arr, int size)
{
    if (size == 1 && arr[0] == 1)
        return 0;
    
    return binarySearch01(arr, size);
}

void coun01(int firstOne, int totalSize)
{
    int totalOnes = totalSize - firstOne;
    int totalZeros = totalSize - totalOnes;

    printf("Zeros: %d | Ones: %d\n", totalZeros, totalOnes);
}

int main()
{
    int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

    int indexOne = binarySearch01Wrapper(arr, 10);

    printf("The index of the first one is: %d\n", indexOne);

    coun01(indexOne, 10);
}