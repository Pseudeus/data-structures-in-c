#include <stdio.h>
#include <stdlib.h>

// Find median of an array

int compare(const void* ptr1, const void* ptr2)
{
    return *(int*)ptr1 - *(int*)ptr2;
}


// First approach: Sort the array and return the element in the middle.
// TC: O(n.log n) | SC: O(1)
void findMedian(int* arr, int size)
{
    qsort(arr, size, sizeof(int), compare);
    printf("The median is: %d", arr[size / 2]);
}

// TODO
// Second approach: Use QuickSelect algorithm. This algorithm we will look
// into the mext chapter. In QuiquSort algorithm just skip the recursive call
// that we do not need.
// The average Time Complexityof this algorithm will be O(1)
void findMedianQuickSelect(int* arr, int size)
{
    
}

int main()
{
    int arr[10] = { 11, 5, 3, 2, 64, 3, 4, 7, 9, 6 };
    findMedian(arr, 10);
}