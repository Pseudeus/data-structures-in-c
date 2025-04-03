#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Occurrence counts in sorted Array
// 

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}

// First approach: Brute force, TC: O(n) | SC: O(1)
int findKeyCountBruteForce(int* arr, int size, int key)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            count++;
    }
}

// Second approach: Some binary search, TC: | SC: 
int findLastIndex(int* arr, int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (key == arr[mid] && (mid == high || arr[mid + 1] != key))
            return mid;
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int findFirstIndex(int* arr, int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (key == arr[mid] && (mid == low || arr[mid - 1] != key))
            return mid;
        if (key > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


int findKeyCountBinarySearch(int* arr, int size, int key)
{
    int firstIndex, lastIndex;
    firstIndex = findFirstIndex(arr, 0, size - 1, key);
    lastIndex = findLastIndex(arr, 0, size - 1, key);
    return lastIndex - firstIndex + 1;
}

int main()
{
    int arr[20];

    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 5;
        printf("[%d]", arr[i]);
    }
    printf("\n");

    qsort(arr, 20, sizeof(int), compare);

    for (int i = 0; i < 20; i++)
    {
        printf("[%d]", arr[i]);
    }

    int key = findKeyCountBinarySearch(arr, 20, 1);



    printf("\n%d\n", key);
}