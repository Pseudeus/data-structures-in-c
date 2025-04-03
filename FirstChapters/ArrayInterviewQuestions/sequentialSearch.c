#include <stdio.h>

int sequentialSearch(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
        if (*(arr + i) == value) return i;
    
    return -1;
}

int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
        *(arr + i) = i + 1;

    int search = sequentialSearch(arr, 8, 5);

    if (search < 0)
        printf("Value not found.");
    else
        printf("Vaue [%d] found at position [%d]", 5, search);
}