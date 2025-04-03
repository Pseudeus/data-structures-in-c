#include <stdio.h>
#include <stdlib.h>

// 17. Write a function to find the sum of every number in an int number.
// Examble: input = 1984, output shourd be 32 (1+9+8+4).

void sumDigits(int number)
{
    int sum = 0;

    while (number)
    {
        sum += number % 10;
        number /= 10;
    }

    printf("The sum result is: %d", sum);
}

int main()
{
    sumDigits(1984);

    return 0;
}