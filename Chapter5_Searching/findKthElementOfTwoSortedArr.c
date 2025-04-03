#include <stdio.h>
#include <stdlib.h>

#define ERROR -999;

// Find kth smallest element in the union of two sorted arrays

int min(int a, int b)
{
    return a > b ? b : a;
}

int find_kth(int* first, int* second, int sizeFirst, int sizeSecond, int k)
{
    if (sizeFirst + sizeSecond < k)
        return ERROR;

    if (sizeFirst == 0)
        return first[k - 1];
    
    if (sizeSecond == 0)
        return second[k - 1];
    
    if (k == 1)
        return min(first[0], second[0]);

    int i = min(sizeFirst, k / 2);
    int j = min(sizeSecond, k / 2);

    if (first[i - 1] > second[j - 1])
        return find_kth(first, second + j, i, sizeSecond - j, k - j);
    else
        return find_kth(first + i, second, sizeFirst - i, j, k - i);
}

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}

int main()
{
    int* arr1 = (int*)calloc(20, sizeof(int));
    int* arr2 = (int*)calloc(20, sizeof(int));

    for (int i = 0; i < 20; i++)
    {
        arr1[i] = rand() % 16;
        arr2[i] = rand() % 16 + 3;
    }

    qsort(arr1, 20, sizeof(int), compare);
    qsort(arr2, 20, sizeof(int), compare);

    int kth = find_kth(arr1, arr2, 20, 20, 5);

    printf("%d", kth);
}