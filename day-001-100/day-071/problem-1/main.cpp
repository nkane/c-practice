/*
 * The Fibonacci sequence is 0, 1, 1, 2, 3, 5, 8, 13 ...
 * where the first two terms are 0 and 1, and each term
 * thereafter is defined recursively as the sum of two
 * preceding terms; that is
 *
 * Fib(n) = n for n < 2
 * Fib(n) = Fib(n - 1) + Fib(n - 2) for n >= 2
 *
 * Write a recursive function that returns the nth number in
 * the Fibonacci sequence when n is passed to the function as
 * an argument. For example, when n = 8, the function returns
 * the 8th number in the sequence, which is 13.
 *
 */

#include <stdio.h>

int
FibRecursive(int n);

int
FibIterative(int n);

int
main()
{
	int n = 0;
	printf("Enter in n: ");
	scanf("%d", &n);

	printf("FibRecursive(n): %d\n", FibRecursive((n - 1)));
	printf("FibIterative(n): %d\n", FibIterative((n - 1)));

	return (0);
}

int
FibRecursive(int n)
{
	int x = 0;
	int y = 0;
	int result = 0;
	if (n >= 2)
	{
		x = FibRecursive(n - 1);
		y = FibRecursive(n - 2);
		result = x + y;
		printf("fib -> %d\n", result);
		return (x + y);
	}
	// return 1 or 0
	return n;
}

int
FibIterative(int n)
{
	int firstN = 0;
	int secondN = 1;
	int next = 0;

	/*
	 * 1 + 0 = 1
	 * 1 + 1 = 2
	 * 1 + 2 = 3
	 * 2 + 3 = 5
	 * 3 + 5 = 8
	 * 5 + 8 = 13
	 * . . .
	 */
	for (int i = 0; i <= n; ++i)
	{
		if (i > 1)
		{
			next = firstN + secondN;
			firstN = secondN;
			secondN = next;
		}
	}
	
	return (next);
}

