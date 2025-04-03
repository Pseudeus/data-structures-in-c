#include <stdio.h>
#include <stdlib.h>

// Remove duplicates in an integer array
// First approach: Sorting

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}

int removeDuplicates(int* arr, int size)
{
    if (size == 0)
        return 0;

    int tmpSize = 0;
    // int* tmpArr = (int*)malloc(sizeof(int));

    qsort(arr, size, sizeof(int), compare);

    // tmpArr[0] = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[tmpSize])
        {
            tmpSize++;
            arr[tmpSize] = arr[i];
            // tmpArr = (int*)realloc(tmpArr, tmpSize + 1);
            // tmpArr[tmpSize] = arr[i];
        }
    }

    return tmpSize + 1;
}

int main()
{
    int* arr = (int*)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 8 + 1;
        printf("[%d]", arr[i]);
    }

    printf("\n");

    int nrIndex = removeDuplicates(arr, 10);

    for (int i = 0; i < nrIndex; i++)
        printf("[%d]", arr[i]);
}