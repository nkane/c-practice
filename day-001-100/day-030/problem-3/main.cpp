/*
 * Write a program to print the numbers 2 to 10 in increments of two using a loop.
 * The output of your program should be:
 * 
 * 2 4 6 8 10
 * 
 */

#include <stdio.h>

int
main()
{
	int i = 10;
	int j = 0;

	while (i >= j)
	{
		if (!(j % 2))
		{
			printf("%d ", j);
		}
		++j;
	}

	return 0;
}
