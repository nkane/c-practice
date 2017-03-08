/*
 * Enter, compile, and execute a program on your computer
 * to determine where in memory your computer has stored
 * the variable num.
 */

#include <stdio.h>

void PrintNumber(int*);

int main(void)
{
	int num;

	PrintNumber(&num);

	num = 22;

	PrintNumber(&num);

	return 0;
}

void PrintNumber(int *n)
{
	printf("Address of number: %p\n", n);
	printf("Value of number: %d\n", *n);
}
