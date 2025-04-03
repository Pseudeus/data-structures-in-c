#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Given an array of n elements, write an algorithm to fond three elements in
    an array whose sum is a given value.
*/

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}

void findThreeElementsToValue(int* arr, int size, int value)
{
    qsort(arr, size, sizeof(int), compare);
    int top = size - 1;
    int bot = 0;

    for (int i = 0; i < size - 1; i++)
    {
        bot = i + 1;

        while (top > bot)
        {
            if (arr[i] + arr[bot] + arr[top] == value)
            {
                printf("[%d][%d][%d]", arr[i], arr[bot], arr[top]);
                return;
            }
            
            else if (arr[i] + arr[bot] + arr[top] < value)
                bot++;
            else
                top--;
        }
    }
    printf("\nThe values dont sum %d\n", value);
}

int main()
{
    int* arr = (int*)malloc(100 * sizeof(int));

    for (int i = 0; i < 100; i++)
        arr[i] = rand() % 128 +1;

    findThreeElementsToValue(arr, 100, 72);

    free(arr);
}