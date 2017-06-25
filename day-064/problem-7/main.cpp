/*
 * Write a main() program that first ask the user for an integer,
 * N, and that prints the first N odd integers starting with 1,
 * one per line
 *
 */

#include <stdio.h>

int
main()
{
	int loopValue;
	int value = 1; 
	printf("Enter N: ");
	scanf("%d", &loopValue);

	for (int i = 0; i < loopValue; ++i)
	{
		printf("%d\n", value);
		value += 2;
	}

	return 0;
}
