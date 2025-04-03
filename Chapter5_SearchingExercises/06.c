#include <stdio.h>
#include <stdlib.h>

/*
    Given an array whose elements is monotonically increasing with both
    negative and positive numbers. Write an algorithm to find the point at
    which list becomes positive.
*/

int searchPositivePoint(int* arr, int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = start + (end - start) /  2;

        if (arr[mid] < 0)
            start = mid + 1;

        else if (arr[mid] >= 0 && arr[mid - 1] < 0)
            return mid;
        
        else if (arr[mid] > 0)
            end = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        int val = (i + 1) * 10 - 40;
        arr[i] = val;
        printf("[%d]", arr[i]);
    }

    int point = searchPositivePoint(arr, 10);

    printf("\nThe inflection point is at index %d with value %d\n", point, arr[point]);
}