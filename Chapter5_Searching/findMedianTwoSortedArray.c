#include <stdio.h>
#include <stdlib.h>

// Find median of two sorted arrays.

int findMedian(int* arr1, int size1, int* arr2, int size2)
{
    int medianIndex = ((size1 + size2) + (size1 + size2) % 2) / 2;

    int i = 0, j = 0;
    int count = 0;

    int current, prev = -1;

    while (count < medianIndex - 1)
    {  
        prev = current;

        if (i < size1 - 1 && (j >= size2 || arr1[i] <= arr2[j]))
        {
            current = arr1[i];
            i++;
        }
        else
        {
            current = arr2[j];
            j++;
        }
        
        count++;
    }


    if ((size1 + size2) % 2 == 0)
    {
        return (prev + current) / 2;
    }
    else 
        return current;
}

int main()
{
    int* farr = (int*)calloc(100, sizeof(int));
    int* sarr = (int*)malloc(sizeof(int));

    for (int i = 0; i < 100; i++)
    {
        farr[i] = i + 1;
    }

    int median = findMedian(sarr, 1, farr, 100);

    printf("The median is %d\n", median);

    free(farr);
    free(sarr);
}