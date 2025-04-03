#include <stdio.h>
#include <stdlib.h>

int gratest(int* arr, int size)
{
    int sum = 0;

    printf("Greatest value is: ");

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > sum)
        {
            sum = arr[i];
        }
    }

    return sum;
}


int main()
{
    int* arr = (int*)malloc(7 * sizeof(int));

    for (int i = 0; i < 7; i++)
    {
        arr[i] = 46 + i;
    }

    printf("%d\n", gratest(arr, 7));

    free(arr);
}