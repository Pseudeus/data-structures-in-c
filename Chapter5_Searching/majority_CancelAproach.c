#include <stdio.h>
#include <stdlib.h>

int getMajority(int* arr, int size)
{
    int majorityIndex = 0, count = 1;
    int candidate;

    for (int i = 0; i < size; i++)
    {
        if (arr[majorityIndex] == arr[i])
            count++;
        else
            count--;
        
        if (count == 0)
        {
            majorityIndex = i;
            count = 1;
        }
    }
    candidate = arr[majorityIndex];
    printf("%d\n", candidate);
    count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == candidate)
            count++;
    }

    if (count > size / 2)
        return candidate;
    else 
        return 0;
}

int main()
{
    int* arr = (int*)calloc(sizeof(int), 50);

    for (int i = 0; i < 50; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    printf("Majority number is: %d\n", getMajority(arr, 50));

    free(arr);
    return 0;
}