#include <stdio.h>


/* Complexity O(n) */
int factorial(int i)
{
    if (i <= 1)
        return 1;

    return i * factorial(i - 1);
}

int main()
{
    int s = 8;

    printf("%d\n", factorial(s));
}