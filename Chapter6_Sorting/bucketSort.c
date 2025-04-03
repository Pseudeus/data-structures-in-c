#include <stdio.h>
#include <stdlib.h>

// Bucket sort is the simplest and most efficent type of sorting. Bucket sort has
// a strict requirement of a predefined range of data.

void bucketSort(int* arr, int size, int range)
{
    int* count = (int*)calloc(range, sizeof(int));

    for (int i = 0; i < range; i++)
        count[arr[i]]++;

    int feedbackCounter = 0;

    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            arr[feedbackCounter++] = i;
            count[i]--;
        }
    }
    free(count);
}

int main()
{
    int* arr = (int*)malloc(100000 * sizeof(int));

    for (int i = 0; i < 100000; i++)
        arr[i] = rand() % 130 + 1;

    bucketSort(arr, 100000, 130);

    printf("Done\n");
}