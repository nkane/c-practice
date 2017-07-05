/*
 * The value of x^n can be defined recursively as:
 * 	x^0 = 1
 * 	x^n = x * x^n-1
 *
 * Write a function that returns the computes and returns the value of
 * x^n.
 *
 * Write the iterative version of this function as well.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int
PowerRecursive(int x, int n);

int
PowerIterative(int x, int n);

int
main()
{
	int x = 0, n = 0;

	printf("Enter in x: ");
	scanf("%d", &x);

	printf("Enter in n: ");
	scanf("%d", &n);

	printf("Recursive: %d\n", PowerRecursive(x, n)); 
	printf("Iterative: %d\n", PowerIterative(x, n));

	system("pause");

	return (0);
}

int
PowerRecursive(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	return x * PowerRecursive(x, (n - 1));
}

int
PowerIterative(int x, int n)
{
	int result = 0;
	if (n == 0) 
	{
		result = 1;
	}
	else 
	{
		result = x;
	}

	for (int i = 1; i < n; ++i) 
	{
		result *= x;
	}
	return (result);
}

