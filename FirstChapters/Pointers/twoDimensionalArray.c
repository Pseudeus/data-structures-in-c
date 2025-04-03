#include <stdio.h>


int main()
{
    int arr[4][2];
    int count = 0;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            arr[i][j] = count++;

    print2DArray((int**)arr, 4, 2);
    print2DArrayAddress((int**)arr, 4, 2);
}

void print2DArray(int* arr[], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            printf("[%d]\n", *(arr + i * col + j));
}

void print2DArrayAddress(int* arr[], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            printf("Value %d, Address %p.\n", *(arr + i * col + j), (arr + i * col + j));
}