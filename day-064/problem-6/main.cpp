/*
 * Write a main() program that prints the odd integers 1
 * to 99, one per line.
 */

#include <stdio.h>

int
main()
{
	for (int i = 1; i <= 99;  i += 2)
	{
		printf("%d\n", i);
	}

	return 0;
}
