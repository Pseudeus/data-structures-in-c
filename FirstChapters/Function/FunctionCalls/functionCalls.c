#include <stdio.h>

int sum(int num1, int num2);

int main()
{
    /* local variable definition */
    int x = 10;
    int y = 20;
    int result;

    /* Calling the function to find sum */  
    result = sum(x, y);
    printf("Sum is: %d\n", result);
    return 0;
}

int sum(int num1, int num2)
{
    return num1 + num2;
}
