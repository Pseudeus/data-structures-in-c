#include <stdio.h>

int GCD(int m, int n)
{
    if (m < n)
        return GCD(n, m);
    if (m % n == 0)
        return n;

    return(GCD(n, m % n));
    
}

int main()
{
    int a = 30;
    int b = 38;
    int gcd = GCD(a, b);

    printf("%d", gcd);
}