#include <stdio.h>

/*
 * There is an inefficency in the solution, better solution in coming chapters.
 */
int fibonacci(int n)
{
    if (n <= 1) return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main ()
{
    int n = 35;

    int fibo = fibonacci(n);

    printf("%d", fibo);
}