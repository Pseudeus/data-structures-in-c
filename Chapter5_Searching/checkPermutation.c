#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 1000

// Chech if two arrays are permutation of each other
// Given two integer arrays. You have to check whether they are permutation of
// each other.

// First approach: Sorting.
// TC: O(n.log n) | SC: O(1)

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}

int checkPermutationSorting(int* arr1, int* arr2, int size1, int size2)
{
    if (size1 != size2)
        return -1;

    qsort(arr1, size1, sizeof(int), compare);
    qsort(arr2, size2, sizeof(int), compare);

    for (int i = 0; i < size1; i++)
    {
        if (arr1[i] != arr2[i])
            return 0;
    }

    return 1;
}

// Second approach: Hash-Table (Assumption: No duplicates)
// TC: O(n) | SC: O(n)

unsigned int hash(int key)
{
    return key % HASH_TABLE_SIZE;
}

bool contains(int* hash_table, int value)
{
    unsigned int index = hash(value);
    return hash_table[index] == value;
}

void insert(int* hash_table, int value)
{
    unsigned int index = hash(value);
    hash_table[index] = value;
}

bool checkPermutationHashTable(int* arr1, int* arr2, int size1, int size2)
{
    if (size1 != size2)
        return -1;

    int* hash_table = (int*)malloc(HASH_TABLE_SIZE * sizeof(int));

    for (int i = 0; i < size1; i++)
        insert(hash_table, arr1[i]);

    for (int i = 0; i < size2; i++)
        if (!contains(hash_table, arr2[i]))
            return false;
    
    return true;
}

int main()
{
    int arr1[10] = { 10, 20, 40, 30, 60, 50, 100, 80, 70, 90 };
    int arr2[10] = { 90, 50, 40, 10, 80, 20, 60, 70, 100, 30 };

    int perm = checkPermutationSorting(arr1, arr2, 10, 10);
    int permHs = checkPermutationHashTable(arr1, arr2, 10, 10);

    printf("[%d][%d]\n", perm, permHs);
}