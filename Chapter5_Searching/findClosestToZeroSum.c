#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Two elements whose sum is closest to zero
// Given an Array of integers, both +ve and -ve. You need to find the two
// elements such that their sum is closest to zero.

// First approach brute force. TC: O(n²) | SC: O(1)
void findSumClosestToZeroBruteForce(int* arr, int size)
{
    if (size < 2) return;

    int minSum, sum, minFirst, minSecond;

    minFirst = 0;
    minSecond = 1;
    minSum = abs(arr[0] + arr[2]);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            sum = abs(arr[i] + arr[j]);
            if (sum < minSum)
            {
                minSum = sum;
                minFirst = arr[i];
                minSecond = arr[j];
            }
        }
    }

    printf("The two elements with minium sum are %d and %d\n", minFirst, minSecond);
}

// Second approach sorting. TC: SC: 

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}

void findSumClosestToZeroSorting(int* arr, int size)
{
    if (size < 2) return;

    qsort(arr, size, sizeof(int), compare);

    int minFirst = 0;
    int minSecond = size - 1;
    int sum = 0;
    int minSum = abs(arr[minFirst] + arr[minSecond]);

    for (int i = 0, j = size - 1; i < j;)
    {
        sum = arr[i] + arr[j];
        if (abs(sum) < minSum)
        {
            minSum = abs(sum);
            minFirst = arr[i];
            minSecond = arr[j];
        }
        if (sum < 0)
            i++;
        else if (sum > 0)
            j--;
        else
            break;
    }
    printf("The two elements with minium sum are %d and %d\n", minFirst, minSecond);
}

int main()
{
    int* arr = (int*)calloc(20, sizeof(int));

    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 51 - 25;
    }

findSumClosestToZeroBruteForce(arr, 20);

findSumClosestToZeroSorting(arr, 20);
}