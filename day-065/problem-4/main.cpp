/*
 * Write a main() program that prints lines from k == 0 up to some limit,
 * say k == 11. On each line print those integers from 100 * k to 100 * k + 99
 * that are multiples of 23
 *
 */

#include <stdio.h>

int
main()
{
	int start = 0, end = 11, value = 0;

	for (int i = start; i <= end; ++i)
	{
		value = 0;
		for (int j = 0; j <= 99; ++j)
		{
			value = (((100 * i) + j));
			if ((value % 23) == 0)
			{
				printf("%d ", value);
			}
		}
		printf("\n");
	}

	return 0;
}

