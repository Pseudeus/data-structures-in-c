#include <stdio.h>


// Binary search Algorithm - Iterative way
int binarySearch(int *arr, int size, int value)
{
    int low = 0, mid;
    int high = size - 1;

    while (low <= high)
    {   //   offset     range    middle
        mid = low + (high - low) / 2; // To avoid the overflow
        if (*(arr + mid) == value)
            return mid;
        else if (*(arr + mid) < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
        *(arr + i) = i + 1;

    int search = binarySearch(arr, 8, 5);

    if (search < 0)
        printf("Value not found.");
    else
        printf("Vaue [%d] found at position [%d]", 5, search);
}