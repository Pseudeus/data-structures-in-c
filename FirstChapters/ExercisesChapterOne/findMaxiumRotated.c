#include <stdio.h>
#include <stdlib.h>

// 15. Find the maxium element in a sorted and rotated array.
// Complexity: O(log n)

int findMaxRotated(int* arr, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid - 1])
        {
            high = mid - 1;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            return arr[mid];
        }
    }
    
    return -1;
}

int main()
{
    int arr[10] = {4, 5, 6, 7, 8, 9, 10, 1, 2, 3};

    int max = findMaxRotated(arr, 10);

    printf("The max value is: %d\n", max);
}