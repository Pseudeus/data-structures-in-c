#include <stdio.h>
#include <stdlib.h>

float average(int* arr, int size)
{
    int sum;

    printf("Array values are:\n");

    for (int i = 0; i < size; i++)
    {
        printf("[%d]\n", arr[i]);
        sum += arr[i];
    }

    return (float)sum / size;
}


int main()
{
    int* arr = (int*)malloc(7 * sizeof(int));

    for (int i = 0; i < 7; i++)
    {
        arr[i] = 46 + i;
    }

    printf("The averate is: %.2f\n", average(arr, 7));

    free(arr);
}