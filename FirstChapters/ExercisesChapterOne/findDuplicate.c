#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 14. Find the duplicate elements in an array of size n where each element
// is itn the range 0 to n-1.

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

void printDuplicated(int* arrTable, int* arr, int size)
{
    printf("Duplicated members: \n");

    for (int i = 0; i < size; i++)
    {
        if (arrTable[i] > 1)
        {
            printf("[%d] ", i);
        }
    }
    printf("\n");
}

void findDuplicate(int* arr, int size)
{
    int* dupArr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        dupArr[arr[i]]++;
    }

    printDuplicated(dupArr, arr, size);

    free(dupArr);
}

int main()
{
    int arr[20];
    

    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 20;
    }

    printArr(arr, 20);
    findDuplicate(arr, 20);
}