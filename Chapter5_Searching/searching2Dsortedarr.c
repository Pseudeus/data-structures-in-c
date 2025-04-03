#include <stdio.h>
#include <stdlib.h>

// Searching for an element in a 2-d sorted array
// Given a 2 dimensional array. Each row and column are sorted in ascending
// order.

int findElementIn2DArray(int* arr[], int r, int c, int value)
{
    int row = 0;
    int col = c - 1;

    while (row < r && col >= 0)
    {
        if (arr[row][col] == value)
            return 1;
        else if (arr[row][col] > value)
            col--;
        else
            row++;
    }
    return 0;
}