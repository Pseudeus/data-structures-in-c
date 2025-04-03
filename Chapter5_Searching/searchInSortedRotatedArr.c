#include <stdlib.h>
#include <stdio.h>

// Given a sorted array of n integers which is rotated
// an unknown number o f times. Find an element in the
// array.

int binarySearchRotateArray(int* arr, int size, int key)
{
    int start = 0;
    int end = size -1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == key) 
            return mid;
        
        // if start -> mid is ascending
        if (arr[mid] > arr[start])
        {
            // if start is lesser than key and mid is greater than key
            if (arr[start] <= key && key < arr[mid])
                end = mid - 1;
            else 
                start = mid + 1;
        }
        // else start -> mid is descending
        else
        {
            // if mid is lessert than key and key is less or equal to end
            if (arr[mid] < key && key <= arr[end])
                start = mid + 1;
            else 
                end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = { 50, 60, 70, 80, 90, 100, 10, 20, 30, 40};

    int valIndex = binarySearchRotateArray(arr, 10, 50);

    printf("The value %d was found on index %d\n", arr[valIndex], valIndex);
}