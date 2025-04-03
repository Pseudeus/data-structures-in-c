#include <stdio.h>
#include <stdlib.h>

// 4. Find the second lagest element in the array

int secondGreat(int* arr, int size)
{
    int first = 0;
    int second = 0;

    printf("Second greatest value is: ");

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
    }

    return second;
}


int main()
{
    int* arr = (int*)malloc(7 * sizeof(int));

    for (int i = 0; i < 7; i++)
    {
        arr[i] = 46 + i;
    }

    printf("%d\n", secondGreat(arr, 7));

    free(arr);
}