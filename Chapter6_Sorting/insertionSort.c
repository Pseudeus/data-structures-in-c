#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int more(int* a, int* b)
{
    return *a > *b;
}

void insertion(int* arr, int size)
{
    int temp, j;

    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        for (j = i; j > 0 && more(&arr[j - 1], &temp); j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}

int main()
{
    int* arr = (int*)malloc(100000 * sizeof(int));

    for (int i = 0; i < 100000; i++)
        arr[i] = rand() % 128 + 1;

    clock_t t = clock();
    insertion(arr, 100000);
    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("Time taken by sorting method: %lf secs.\n", time_taken);

    free(arr);
}