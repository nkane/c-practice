/*
 * The sum of a series of consecutive numbers from 1 to n
 * can be defined recursively as:
 * sum(1) = 1;
 * sum(n) = n + sum(n - 1)
 *
 * Write a recursive C function that accepts n as an argument
 * and calculates the sum of the numbers from 1 to n.
 *
 */
#include <stdio.h>

int 
SumRecursive(int n);

int
InterfaceSumTailRecursive(int n);

int
SumTailRecursive(int n, int result);

int
main()
{
	int n = 0;
	printf("Enter in n: ");
	scanf("%d", &n);

	printf("Normal Recursion: %d\n", SumRecursive(n));
	printf("Tail Recursion: %d\n", InterfaceSumTailRecursive(n));

	return 0;
}

int 
SumRecursive(int n)
{
	if (n != 0)
	{
		return n + SumRecursive(n - 1);
	}
	return n;
}

int
InterfaceSumTailRecursive(int n)
{
	return SumTailRecursive(n, 0);
}

int
SumTailRecursive(int n, int result)
{
	if (n == 0) 
	{
		return result;
	}
	return SumTailRecursive((n - 1), (result + n));
}

