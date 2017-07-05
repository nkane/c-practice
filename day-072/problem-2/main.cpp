/*
 * The following algorithm, discovered by Euclid, provides a simple means
 * of determining the greatest common divisor (GCD) of two positive integers a and b
 * (the GCD is the largest number that divides evenly into both numbers with no remainder):
 * 	a) divide the larger number by the smaller and retain the remainder
 * 	b) divide the smaller number by the remainder, again retaining the remainder
 * 	c) continue dividing the prior remainder by the current remainder until the 
 * 	   remainder is 0, at which point the last non-0 remainder is the GCD.
 *
 * Write a recursive function named gcd() that implements this algorithm.
 *
 */

#include <stdio.h>

int
GCDRecursive(int larger, int smaller);

void
XorSwap(int *n1, int *n2);

int
main()
{
	int n1 = 0, n2 = 0;
	printf("Enter in value 1: \n");
	scanf("%d", &n1);

	printf("Enter in value 2: \n");
	scanf("%d", &n2);

	if (n2 > n1)
	{
		XorSwap(&n1, &n2);
	}

	GCDRecursive(n1, n2);

	return 0;
}

// larger: 468
// smaller: 24
// a) 468 % 24 = 12
// b) 24 % 12 = 0
// c) none ...
// return 12
// got close to solving this one, but needed some help from:
// http://www.cse.wustl.edu/~kjg/cse131/Notes/Recursion/recursion.html
int
GCDRecursive(int larger, int smaller)
{
	if ((larger % smaller) == 0)
	{
		return smaller;
	}
	return GCDRecursive(smaller, (larger % smaller));
}

void
XorSwap(int *n1, int *n2)
{
	// example
	// n1 = 0001
	// n2 - 0011
	
	// n1 ^= n2
	//  0001
	// ^0011
	// -----
	//  0010
	//  n1 = 0010
	
	// n2 ^= n1
	//  0011
	// ^0010
	// -----
	//  0001
	//  n2 = 0001

	// n1 ^= n2
	//  0010
	// ^0001
	// -----
	//  0011
	//  n1 = 0011

	*n1 ^= *n2;
	*n2 ^= *n1;
	*n1 ^= *n2;
}

