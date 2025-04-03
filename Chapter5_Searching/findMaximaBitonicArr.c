#include <stdio.h>
#include <stdlib.h>

// 12/08/2024
// Find maxima in a bitonic array
int findMaximaFromBitonic(int* arr, int size)
{
    if (size < 3) return 0;

    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid - 1])
            high = mid - 1;

        else if (arr[mid] < arr[mid + 1])
            low = mid + 1; 
        
        else
            return arr[mid];
    }

    return -1;
}

int main()
{
    int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    int maxima = findMaximaFromBitonic(arr, 10);

    printf("The maxima is: %d\n", maxima);
}