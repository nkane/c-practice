/*
 * NOTE(nick): problem not well defined in book ...
 * should have input / output - this is problem wrong ...
 *
 * Write a function that recursively determines the value
 * of the nth term of an arithmetic sequence defined by the
 * terms
 *
 * 	a, a + d, a + 2d, a + 3d, ..... a + (n - 1)d
 *
 * 	a = 3
 * 	n = 3
 * 	d = 2
 *
 * 	a + (n - 1) * d
 *
 *	3 + (3 - 1) * 2 = 
 *	3 + (2 * 2) =
 *	3 + 4 = 7 
 *
 *	3 + (2 - 1) * 2 = 
 *	3 + (1 * 2) =
 *	3 + 2 = 5
 *
 *	3 + (1 - 1) * 2 = 
 *	3 + (0 * 2) = 
 *	3 + 0 = 3
 *
 * The argument to the function should be the first term, a,
 * the common difference, d, and the value of n.
 *
 */

#include <stdio.h>

int
RecursiveFunc(int a, int n, int d);

int
main()
{
	int n = 0;

	printf("%d", RecursiveFunc(3, 3, 2));

	return 0;
}

int
RecursiveFunc(int a, int n, int d)
{
	if (n == 0)
	{
		return n;
	}
	return a + RecursiveFunc(a, (n - 1), d) * d;
}

