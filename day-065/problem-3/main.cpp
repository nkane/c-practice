/*
 * Write a main() program that prints the integers from 1 up to 100
 * that are not multiples of 3 or 5. Print ten integers per line.
 *
 */

#include <stdio.h>

int
main()
{
	int start = 1, end = 100, count = 1; 

	for (int i = start; i <= end; ++i)
	{
		if ((i % 3) != 0 && (i % 5) != 0)
		{
			printf("%d ", i);
			if ((count % 10) == 0)
			{
				printf("\n");
			}
			++count;
		}
	}

	return 0;
}

