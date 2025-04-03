#include <stdio.h>
#include <stdlib.h>

/*
    Given an array of 1's, write a program to separate 0's from 1's.
*/

void swap(int* a, int* b)
{
    if (*a == *b) return;

    *a ^= *b ^= *a ^= *b;
}

void separate0s1sFA(int* arr, int size)
{
    int top = size - 1;
    int bot = 0;

    while (top > bot)
    {
        if (arr[bot] == 0)
            bot++;
        
        else if (arr[top] == 1)
            top--;
        
        else 
        {
            swap(&arr[bot], &arr[top]);
            top--;
            bot++;
        }
    }
}

void separate0s1sCounting(int* arr, int size)
{
    int* countArr = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < size; i++)
    {
        countArr[arr[i]]++;
    }

    for (int i = 0, j = 0; i < size;)
    {
        if (countArr[j])
        {
            arr[i] = j;
            countArr[j]--;
            i++;
        }
        else
            j++;
    }
    free(countArr);
}

int main()
{
    int* arr = (int*)calloc(10, sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 2;
        printf("[%d]", arr[i]);
    }

    printf("\n");

    // separate0s1sFA(arr, 10);
    separate0s1sCounting(arr, 10);

    for (int i = 0; i < 10; i++)
        printf("[%d]", arr[i]);

    printf("\n");
    free(arr);
}