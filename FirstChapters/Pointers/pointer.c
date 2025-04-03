#include <stdio.h>

int main()
{
    int var;
    int* ptr;
    var = 10;
    ptr = &var;

    printf("Value stored at variable var id %d \n", var);
    printf("Value stored at variable var is %d \n", *ptr);

    printf("The address of variable var is %p \n", &var);
    printf("The address of variable var is %p \n", ptr);
    return 0;
}