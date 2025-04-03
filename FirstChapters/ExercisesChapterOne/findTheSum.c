#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 1000

// 16. Given an array with 'n' elements & a value 'x',
// find two elements in the array that sums to 'x'.

// Hash function
unsigned int hash(int key)
{
    return key % HASH_TABLE_SIZE;
}

// Insert into hash table
void insert(int hash_table[], int value)
{
    unsigned int index = hash(value);
    hash_table[index] = value;
}

// Check if a value exists in the hash table
int contains(int hash_table[], int value)
{
    unsigned int index = hash(value);
    return hash_table[index] == value;
}

void findTwoElementsSum(int arr[], int n, int x)
{
    int hash_table[HASH_TABLE_SIZE] = {0};

    for (int i = 0; i < n; i++)
    {
        int complement = x - arr[i];

        if (contains(hash_table, complement))
        {
            printf("Pair found: [%d, %d]\n", complement, arr[i]);
            return;
        }
        insert(hash_table, arr[i]);
    }
    printf("No pair found.\n");
}

int main()
{
    int arr[] = { 3, 5, 1, 7, 9, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    findTwoElementsSum(arr, n, x);
    return 0;
}