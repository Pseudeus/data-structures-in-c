#include <stdio.h>
#include <stdlib.h>

int findSecondLargest(int* arr, int size)
{
    int greatest = 0;
    int secondGreatest = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > greatest)
            greatest = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > secondGreatest && arr[i] < greatest)
            secondGreatest = arr[i];
    }

    return secondGreatest;
}

int main()
{
    int* arr = (int*)calloc(100, sizeof(int));

    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 128 + 1;
    }

    int sGreat = findSecondLargest(arr, 100);

    printf("%d\n", sGreat);
}

