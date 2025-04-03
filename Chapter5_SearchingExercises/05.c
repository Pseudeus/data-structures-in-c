#include <stdio.h>
#include <stdlib.h>

/*
    Given an array of 0's, 1's and 2's, write a program to separate 0's, 1's
    and 2's.
*/

void swap(int* a, int* b)
{
    if (*a == *b) return;

    *a ^= *b ^= *a ^= *b;
}

void firstAppr(int* arr, int size, int orderFirst)
{
    if (orderFirst >= 2) return;

    int bot = 0;
    int top = size - 1;

    while (bot < top)
    {
        if (arr[top] != orderFirst)
            top--;
        else if (arr[bot] == orderFirst)
            bot++;

        else
        {
            swap(&arr[top], &arr[bot]);
            top--;
            bot++;
        }
    }

    firstAppr(&arr[bot] + 1, size - bot, ++orderFirst);
}

void countingAppr(int* arr, int size)
{
    int* countingArr = (int*)malloc(3 * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        countingArr[arr[i]]++;
    }

    for (int i = 0, j = 0; i < size;)
    {
        if (countingArr[j])
        {
            arr[i] = j;
            countingArr[j]--;
            i++;
        }
        else
            j++;
    }

    free(countingArr);
}

int main()
{
    int* arr = (int*)calloc(20, sizeof(int));

    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 3;
        printf("[%d]", arr[i]);
    }

    printf("\n");

    // separate0s1sFA(arr, 10);
    //firstAppr(arr, 20, 0);
    countingAppr(arr, 20);

    for (int i = 0; i < 20; i++)
        printf("[%d]", arr[i]);

    printf("\n");
    free(arr);
}