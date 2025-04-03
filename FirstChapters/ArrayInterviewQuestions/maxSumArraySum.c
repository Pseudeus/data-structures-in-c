#include <stdio.h>

int maxSubArraySum(int a[], int size)
{
    int maxSoFar = 0, maxEndingHere = 0;
    for (int i = 0; i < size; i++)
    {
        maxEndingHere += a[i];
        if (maxEndingHere < 0)
        {
            maxEndingHere = 0;
            continue;
        }
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}

int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
        *(arr + i) = i - 4;

    int sum = maxSubArraySum(arr, 8);

    printf("The max contiguous sum is: %d.", sum);
}
