#include <stdio.h>
#include <stdlib.h>

// First approach: allocate a separate array, then scan through the given array,
// and fill even number from the start and odd numbers from the end.
int* separateEvenOdd(int* arr, int size)
{
    int* temp = (int*)calloc(size, sizeof(int));

    int tempBotIndex = 0;
    int tempTopIndex = size - 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            temp[tempBotIndex] = arr[i];
            tempBotIndex++;
        }
        else
        {
            temp[tempTopIndex] = arr[i];
            tempTopIndex--;
        }
    }
    free(arr);
    return temp;
}

void separateEvenOddSecAp(int* arr, int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        if (arr[left] % 2 == 0)
            left++;
        else if (arr[right] % 2 != 0)
            right--;
        else
        {
            arr[left] ^= arr[right] ^= arr[left] ^= arr[right];
            left++;
            right--;
        }
    }
}

int main()
{
    int* arr = (int*)calloc(20, sizeof(int));

    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 5;
    }

    // arr = separateEvenOdd(arr, 20);
    separateEvenOddSecAp(arr, 20);

    for (int i = 0; i < 20; i++)
    {
        printf("[%d]", arr[i]);
    }
}