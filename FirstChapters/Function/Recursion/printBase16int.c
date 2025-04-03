#include <stdio.h>

void printInt(unsigned int number, const int base)
{
    char* conversion = "0123456789ABCDEF";
    unsigned char digit = number % base;
    if (number /= base)
        printInt(number, base);
    printf("%c", conversion[digit]);
}

int main()
{
    unsigned int value = 255;
    printInt(value, 2);

    return 0;
}