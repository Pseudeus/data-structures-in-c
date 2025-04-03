#include <stdio.h>

void fun2()
{
    printf("fun2 line1\n");
}

void fun1()
{
    printf("fun1 line1\n");
    fun2();
    printf("fun1 line2\n");
}

int main()
{
    printf("main line1\n");
    fun1();
    printf("main line2\n");
}