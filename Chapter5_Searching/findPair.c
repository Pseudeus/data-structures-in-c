#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b) return *(int*)a;
    else return *(int*)b;
}

int findPairSort(int* arr, int size, int value)
{
    qsort(arr, size, sizeof(int), compare);

    int first = 0, second = size - 1;
    int current;

    while (first < second)
    {
        current = arr[first] + arr[second];

        if (current == value)
        {
            printf("The pair is %d, %d\n", arr[first], arr[second]);
            return 1;
        }
        else if (current < value)
        {
            first++;
        }
        else
            second--;
    }

    return 0;
}

int main()
{
    int arr[20];

    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 41;
    }
    findPairSort(arr, 20, 15);

}