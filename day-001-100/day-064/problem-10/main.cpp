/*
 * Write a main() program that prints the integers from 0
 * to 24 (inclusive). Print five integers per line.
 *
 */

#include <stdio.h>

int
main() 
{
	for (int i = 0; i <= 24; ++i)
	{
		if (((i + 1) % 5) == 0)
		{
			printf("%d\n", i);
		}
		else
		{
			printf("%d ", i);
		}
	}

	return 0;
}
