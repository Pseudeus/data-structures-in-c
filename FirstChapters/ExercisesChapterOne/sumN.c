#include <stdio.h>
#include <stdlib.h>

// Write a function to compute Sum(N) = 1+2+3+...+N.

void sumN(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    printf("The sum is: %d\n", sum);
}

int main()
{
    sumN(11);
    sumN(4);
    sumN(50);
    return 0;
}