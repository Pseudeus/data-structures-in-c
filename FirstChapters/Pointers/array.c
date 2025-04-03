#include <stdio.h>

void printArray(int arr[], int count)
{
    printf("Values stored in array are:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Data [%d] has Address: %p.\n", arr[i], arr + i);
    }
}

void printArrayUsingPointer(int arr[], int count)
{
    printf("Values stored in array are:\n");
    int* ptr = arr;
    
    for (int i = 0; i < count; i++)
    {
        printf("Data [%d] has Address: %p.\n", *ptr, ptr);
        ptr++;
    }
}

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    printArray(arr, 10);
    printArrayUsingPointer(arr, 10);
}