#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 1000

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}

int binarySearch(int* arr, int size, int value)
{
    int low = 0;
    int high = size - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value)
            return 1;
        else if (arr[mid] < value)
            low = mid + 1;
        else 
            high = mid - 1;
    }

    return -1;
}

void findPairsOneBinarySearch(int* arr1, int* arr2, int size, int value)
{
    qsort(arr2, size, sizeof(int), compare);

    for (int i = 0; i < size; i++)
    {
        if (binarySearch(arr2, size, value - arr1[i]))
        {
            printf("The pairs are: %d and %d\n", arr1[i], value - arr1[i]);
            break;
        }
    }

}

void findPairsSortingBothArrays(int* arr1, int* arr2, int size, int value)
{
    qsort(arr1, size, sizeof(int), compare);
    qsort(arr2, size, sizeof(int), compare);

    for (int i = 0, j = size - 1; i < j;)
    {
        if (arr1[i] + arr2[j] == value)
        {
            printf("The pairs are: %d and %d\n", arr1[i], arr2[j]);
            break;
        }
        else if (arr1[i] + arr2[j] < value)
            i++;
        else 
            j--;
    }
}

unsigned int hash(int key)
{
    return key % HASH_TABLE_SIZE;
}

void insert(int hash_table[], int value)
{
    unsigned int index = hash(value);
    hash_table[index] = value;
}

int contains(int hash_table[], int value)
{
    unsigned int index = hash(value);
    return hash_table[index] == value;
}

void findPairsWithHashTable(int* arr1, int* arr2, int size, int value)
{
    int hash_table[size];
    for (int i = 0; i < size; i++)
        insert(hash_table, arr2[i]);

    for (int i = 0; i < size; i++)
    {
        if (contains(hash_table, value - arr1[i]))
        {
            printf("The pairs are: %d and %d\n", arr1[i], value - arr1[i]);
            break;
        }
    }
}

void findPairsWithCounting(int* arr1, int* arr2, int size, int value, int max_value)
{
    int* counting_arr = (int*)calloc(sizeof(int), size + 1);

    for (int i = 0; i < size; i++)
    {
        counting_arr[arr2[i]]++;
    }

    for (int i = 0; i < size; i++)
    {
        if (counting_arr[value - arr1[i]])
        {
            printf("The pairs are: %d and %d\n", arr1[i], value - arr1[i]);
            break;
        }
    }

    free(counting_arr);
}

int main()
{
    int first_arr[20];
    int second_arr[20];

    for (int i = 0; i < 20; i++)
    {
        first_arr[i] = rand() % 10;
        second_arr[i] = rand() % 13;
    }

    // First approach was brute force, Time complexity O(n²) : Space complexity O(1)

    // Second approach, Time complexity O(m.log m) : Space complexity O(1)
    findPairsOneBinarySearch(first_arr, second_arr, 20, 20);

    // Third approach, Time complexity O(n.log n) : Space complexity O(1)
    findPairsSortingBothArrays(first_arr, second_arr, 20, 20);

    // Forth approach, Time complexity O(n) : Space complexity O(n)
    findPairsWithHashTable(first_arr, second_arr, 20, 18);

    // Fifth approach: Counting !! we MUST know the range of the stored data, Time complexity O(1) : Space complexity O(n)
    findPairsWithCounting(first_arr, second_arr, 20, 20, 12);
}