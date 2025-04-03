#include <stdio.h>

void increment(int var)
{
    var++;
}

void incrementPtr(int *ptr)
{
    (*ptr)++;
}

int main()
{
    int i = 10;
    printf("Value of i before increment is : %d\n", i);
    incrementPtr(&i);
    printf("Value of i after increment is %d\n", i);
}