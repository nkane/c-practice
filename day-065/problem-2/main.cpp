/*
 * Write a main() program that prints the odd integers from start
 * down to finish, seven per line. Make start and finish variables
 * that are initialized by assignment by the user.
 *
 */

#include <stdio.h>

int
main()
{
	int start = 0, finish = 0, count = 1;

	printf("Enter start: ");
	scanf("%d", &start);

	printf("Enter finish: ");
	scanf("%d", &finish);

	// adjust if start value is even
	if ((start % 2) == 0)
	{
		++start;
	}

	for (int i = start; i >= finish; i -= 2)
	{
		printf("%d ", i);
		if ((count % 7) == 0)
		{
			printf("\n");
		}
		++count;
	}

	return 0;
}

