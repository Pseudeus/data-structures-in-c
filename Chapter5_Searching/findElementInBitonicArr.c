#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int FindMaxima(int* arr, int size)
{
    if (size < 3) return -1;

    int start = 0;
    int end = size - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid - 1])
            end = mid - 1;
        else if (arr[mid] < arr[mid + 1])
            start = mid + 1;
        else
            return mid;
    }

    return -1;
}

int BinarySearch(int* arr, int min, int max, int key, bool isAscending)
{
    int mid;

    
    while (min <= max)
    {
        mid = min + (max - min) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key && isAscending || arr[mid] > key && !isAscending)
            min = mid + 1;
        else if (arr[mid] > key && isAscending || arr[mid] < key && !isAscending)
            max = mid - 1;
    }
    return -1;
}

int SearchBitonicArray(int* arr, int size, int key)
{
    int maxima = FindMaxima(arr, size);

    if (!maxima) return maxima;

    int k = BinarySearch(arr, 0, maxima, key, true);

    if (k != -1)
        return k;
    else
        return BinarySearch(arr, maxima, size - 1, key, false);
}

int main()
{
    int bitonicArr[10] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2 };

    int valIndex = SearchBitonicArray(bitonicArr, 10, 3);

    printf("The value %d was found in the index [%d]\n", bitonicArr[valIndex], valIndex);
}