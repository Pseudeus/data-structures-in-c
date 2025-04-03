#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int more(int* a, int* b)
{
    return *a > *b;
}

void swap(int* a, int* b)
{
    *a ^= *b ^= *a ^= *b;
}

void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (more(&arr[j], &arr[j + 1]))
                swap(&arr[j], &arr[j + 1]);
    
}

void bubbleSortImproved(int* arr, int size)
{
    int swapped = 1;
    for (int i = 0; i < (size - 1) && swapped; i++)
    {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
            if (more(&arr[j], &arr[j + 1]))
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
    }
}

int main()
{
    int* arr = (int*)malloc(100000 * sizeof(int));

    for (int i = 0; i < 100000; i++)
        arr[i] = rand() % 128 + 1;

    clock_t t = clock();
    //bubbleSort(arr, 100000);
    bubbleSortImproved(arr, 100000);
    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("Time taken by sorting method: %lf secs.\n", time_taken);

    free(arr);
}