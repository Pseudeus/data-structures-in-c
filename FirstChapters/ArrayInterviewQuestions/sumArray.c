#include <stdio.h>

int sumArray(int* arr, int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}

int main()
{
    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = i + 1;
    }

    int sum = sumArray(arr, 4);

    printf("Total : %d\n", sum);
}