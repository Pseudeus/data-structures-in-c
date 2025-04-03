#include <stdio.h>
#include <stdlib.h>

char* intToStr(char* p, unsigned int number)
{
    unsigned char digit = number % 10 + '0';
    if (number /= 10)
        p = intToStr(p, number);
    *p++ = digit;
    return p;
}

int main()
{
    unsigned int value = 983099871;
    char *p = (char*)malloc(10 * sizeof(char));

    intToStr(p, value);

    for (int i = 0; i < 10; i++)
    {
        printf("%c", *(p + i));
    }

    free(p);
}