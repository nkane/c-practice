/*
 * The Fibonacci sequence is 0, 1, 1, 2, 3, 5, 8, 13 ... where the first two terms
 * are 0 and 1, and each term thereafter is defined recursively at the sum of the
 * two preceding terms:
 *
 * 	Fib(n) = n 	for n < 2
 * 	Fib(n) = Fib(n - 1) + Fib(n - 2) for n >= 2
 *
 * Write a recursive function that returns the nth number in a Fibonacci sequence when n
 * is passed to the function as an argument. For example, when n = 8, the function returns
 * the 8th number in the sequence, which is 13.
 *
 * Alternatively write a function that uses repetition to calculate the nth term of a Fibonacci
 * sequence.
 *
 */

#include <stdio.h>

int 
FibRecursive(int n);

int
FibLoop(int n);

int
main()
{
	int n = 0;
	printf("Enter n for Fib sequence: ");
	scanf("%d", &n);

	printf("Fib Recursive: %d\n", FibRecursive(n - 1));
	printf("Fib Loop: %d\n", FibLoop(n));
	return (0);
}

int 
FibRecursive(int n)
{
	if (n >= 2)
	{
		return (FibRecursive(n - 1) + FibRecursive(n - 2));
	}
	return (n);
}

int
FibLoop(int n)
{
	int first = 0;
	int second = 1;
	int next = 0;

	for (int i = 2; i < n; ++i)
	{
		next = first + second;
		first = second;;
		second = next;
	}

	return (next);
}

