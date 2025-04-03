#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int more(int* a, int* b)
{
    return *a > *b;
}

void selectionSort(int* arr, int size)
{
    int max, temp;

    for (int i = 0; i < size - 1; i++)
    {
        max = 0;
        for (int j = 1; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[max])
                max = j;
        }
        temp = arr[size - 1 - i];
        arr[size - 1 - i] = arr[max];
        arr[max] = temp;
    }
}

void selectionSortFront(int* arr, int size)
{
    int min, temp;

    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int* arr = (int*)malloc(100000 * sizeof(int));

    for (int i = 0; i < 100000; i++)
        arr[i] = rand() % 128 + 1;

    clock_t t = clock();
    // insertion(arr, 100000);
    selectionSort(arr, 100000);
    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("Time taken by sorting method: %lf secs.\n", time_taken);

    free(arr);
}