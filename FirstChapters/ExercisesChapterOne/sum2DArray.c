#include <stdio.h>
#include <stdlib.h>

int sum2DArray(int* arr, int row, int column)
{
    int sum;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            sum += *(arr + i * row + j);
        }
    }
    return sum;
}

int main()
{
    int arr[5][4];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = i * j;
        }
    }

    printf("%d\n", sum2DArray(arr, 5, 4));
}