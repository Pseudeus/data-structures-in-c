#include <stdio.h>
#include <stdlib.h>

int findMissingModify(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int value_to_add = size + 1;
        int index_to_modify = arr[i] % (size + 1);
        arr[index_to_modify] += value_to_add;
    }

    for (int i = 0; i < size; i++)
    {
        int val = arr[i];
        if (arr[i] < size + 1)
            return i;
    }

    return -1;
}

int findMissingSum(int* arr, int size)
{
    int sumCount = size;
    int expectedSum = 0;
    int actualSum = 0;

    while (sumCount)
        expectedSum += sumCount--;

    
    for (int i = 0; i < size; i++)
    {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

int findMissingXor(int* arr, int size)
{
    int xorSum = 0;

    for (int i = 1; i <= size; i++)
    {
        xorSum ^= i;
    }

    printf("Xor sum: %d.\n", xorSum);

    for (int i = 0; i < size; i++)
    {
        xorSum ^= arr[i];
    }
    return xorSum;
}

int main()
{
    int arr[10] = { 3, 2, 5, 6, 4, 1, 7, 9, 10, 0 };

    int value = findMissingXor(arr, 10);

    printf("Missing: %d.\n", value);
}