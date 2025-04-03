#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 1000

// First Repeated element in the array
// Given an unsorted array of n elements, find the first element, which is
// repeated.

// First approach: Exhaustive search or Brute force.

// TC: O(n²) | SC: O(1)
int firstRepeated(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] == arr[j])
                return arr[i];
    
    return -1;
}

// Second approach: Hash-Table
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

int findRepeatedHashT(int* arr, int size)
{
    int* hash_table = (int*)malloc(HASH_TABLE_SIZE * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        if (contains(hash_table, arr[i]))
        {
            free(hash_table);
            return arr[i];
        }
        else
            insert(hash_table, arr[i]);
    }

    free(hash_table);
    return -1;
}

int main()
{
    int* arr = (int*)calloc(100, sizeof(int));

    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 128 + 1;
    }

    int repeatedSqr = firstRepeated(arr, 100);
    int repeatedHash = findRepeatedHashT(arr, 100);

    printf("[%d] [%d]\n", repeatedSqr, repeatedHash);

    free(arr);
}