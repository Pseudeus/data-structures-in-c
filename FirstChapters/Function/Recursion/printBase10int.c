#include <stdio.h>

void printInt(unsigned int number)
{
    char digit = number % 10 + '0';
    if (number >= 10)
        printInt(number / 10);
    
    printf("%c", digit);
}

int main()
{
    unsigned int val = 60828735;

    printInt(val);

    return 0;
}