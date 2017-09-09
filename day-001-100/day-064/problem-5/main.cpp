/*
 * Write a main() program that prints the integers 15 down to 0
 * one per line.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Loop = 15;

int
main()
{
	for (int i = Loop; i >= 0; --i)
	{
		printf("%d\n", i);
	}

	return 0;
}

