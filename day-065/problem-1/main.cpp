/*
 * Write a main() program that prints the odd integers 1 to N, five per line.
 * Write the integers to standard output.
 *
 */

#include <stdio.h>

int
main()
{
	int loopValue = 0;
	int count = 1;
	printf("Enter N: ");
	scanf("%d", &loopValue);

	for (int i = 1; i <= loopValue; i += 2)
	{
		printf("%d ", i);
		if ((count % 5) == 0)
		{
			printf("\n");
		}
		++count;
	}

	return 0;
}

