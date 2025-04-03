#include <stdio.h>

void towerOfHanoi(int num, char src, char dst, char temp)
{
    if (num < 1) return;

    towerOfHanoi(num - 1, src, temp, dst);
    printf("\n Move dis %d form peg %c to peg %c.", num, src, dst);
    towerOfHanoi(num - 1, temp, dst, src);
}

int main()
{
    int num = 4;
    printf("The sequence of moves involved in the Tower of Hanoi are: \n");
    towerOfHanoi(num, 'A', 'C', 'B');
    return 0;
}