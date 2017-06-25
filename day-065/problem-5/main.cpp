/*
 * Write a main() program that computes and prints N sums: 1, 1 + 2, 1 + 2 + 3, ...,
 * 1 + 2 + 3 + .... + N. There is a smart way to do this with just one loop, and a
 * not-so-smart way that uses nested loops.
 *
 */

#include <stdio.h>

int
main()
{
	int n = 0;
	int sum = 0;
	printf("Enter in N: ");
	scanf("%d", &n);

	// sum = (1 + 2 + 3 +...+N)
	// sum += i = (0 + 1) = 1
	// sum += i = (1 + 2) = 3
	// sum += i = (3 + 3) = 6
	for (int i = 1; i <= n; i++)
	{
		sum += i; 
		printf("sum: %d\n", sum);
	}

	return 0;
}

