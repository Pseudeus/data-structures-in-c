#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 1000

/*
    Given an array of n elements, find the first repeated element. Which of the
    following methods will work for us (and which of the method will not
    work for us). If a method work, then implements it.

    -   Brute force exhaustive search.
    -   Use Hash-Table to keep an index of the elements an use the second 
        scan to find the element.
    -   Sorting the elements.
    -   If whe know the range of the element then we can use counting
        technique.
    
    Hint: When order in which elements appear in input is important, we 
    cannot use sorting.
*/


int findRepeatedBruteForce(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
            if (arr[i] == arr[j])
                return i;
    
    return -1;
}

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

int findRepeatedHashTable(int* arr, int size)
{
    int* hash_table = (int*)malloc(HASH_TABLE_SIZE * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        if (contains(hash_table, arr[i]))
        {
            free(hash_table);
            return i;
        }
        
        else
            insert(hash_table, arr[i]);
    }

    return -1;
}

int main()
{
    int* arr = (int*)calloc(100, sizeof(int));

    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 128 + 1;
    }

    int bfIndex = findRepeatedBruteForce(arr, 100);
    int htIndex = findRepeatedHashTable(arr, 100);

    printf("[%d][%d]\n", arr[bfIndex], arr[htIndex]);

    free(arr);
}