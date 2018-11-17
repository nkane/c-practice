/*
 * Write a main() program that prints the odd integers 1 to N, five per line.
 * Write the integers to standard output. On a Windows machine, this means the
 * integers are written to the DOS window. Make N a variable in the program
 * and initialize it in an assignment statment (or read it from user input,
 * if you want.) When N==53, the output of the program is:
 *
 *      1  3  5  7  9
 *      11 13 15 17 19
 *      21 23 25 27 29
 *      31 33 35 37 39
 *      41 43 45 47 49
 *      51 53
 *
 */

#include <stdio.h>

int
findN(int num);

int
main()
{
    int n = 0;

    printf("Enter in n: ");
    scanf("%d", &n);

    int i;
    int j;
    int spaces = findN(n) + 1;
    for (i = 0, j = 0; i <= n; ++i)
    {
        if ((i % 2) > 0)
        {
            printf("%*d", spaces, i);
            ++j;
            if ((j % 5) == 0)
            {
                printf("\n");
            }
        }
    }

    return 0;
}

int
findN(int num)
{
    int n = 0;
    while (num > 0)
    {
        num /= 10;
        ++n;
    }
    return n;
}
