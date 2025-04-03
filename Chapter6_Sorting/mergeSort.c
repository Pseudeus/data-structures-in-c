#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int* tempArr, int lowerIndex, int middleIndex, int upperIndex)
{
    int lowerStart = lowerIndex;
    int lowerStop = middleIndex;
    int upperStart = middleIndex + 1;
    int upperStop = upperIndex;

    int count = lowerIndex;

    while (lowerStart <= lowerStop && upperStart <= upperStop)
    {
        if (arr[lowerStart] < arr[upperStart])
            tempArr[count++] = arr[lowerStart++];
        else
            tempArr[count++] = arr[upperStart++];
    }

    while (lowerStart <= lowerStop)
        tempArr[count++] = arr[lowerStart++];
    
    while (upperStart <= upperStop)
        tempArr[count++] = arr[upperStart++];

    for (int i = lowerIndex; i <= upperIndex; i++)
        arr[i] = tempArr[i];
}

void mergeStr(int* arr, int* tempArr, int lowerIndex, int upperIndex)
{
    if (lowerIndex >= upperIndex) return;

    int middleIndex = (lowerIndex + upperIndex) / 2;
    mergeStr(arr, tempArr, lowerIndex, middleIndex);
    mergeStr(arr, tempArr, middleIndex + 1, upperIndex);
    merge(arr, tempArr, lowerIndex, middleIndex, upperIndex);
}

void mergeSort(int* arr, int size)
{
    int* tempArray = (int*)malloc(size * sizeof(int));
    mergeStr(arr, tempArray, 0, size - 1);
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("[%d]", arr[i]);
}

int main()
{
    int arr[10] = { 3, 4, 2, 1, 6, 5, 7, 8, 1, 1 };

    mergeSort(arr, 10);
    printArray(arr, 10);
}