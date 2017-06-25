/*
 * Write a main() program that prints integers from 1 to 15 one per
 * line.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Loop_Amount = 15;

int
main()
{
	for (int i = 1; i <= Loop_Amount; ++i)
	{
		printf("%d\n", i);
	}

	return 0;
}

