/*
 * Euclid's method for finding the GCD of two positive integers consists of the following
 * steps:
 *
 * 	a) divide the larger number by the smaller and retain the remainder.
 * 	b) divide the smaller number by the remainder, again retaining the remainder.
 * 	c) continue dividing the prior remainder by the current remainder until the remainder
 * 	   is 0, at which point the last non-0 remainder is the GCD.
 *
 * 	- For example, assume the two positive integers are 84 and 49, we have:
 *
 * 	  step a) 84 / 49 yields a remainder of 35
 * 	  step b) 49 / 35 yields a remainder of 14
 * 	  step c) 35 / 15 yields a remainder of 7
 * 	  step d) 14 / 7  yields a remainder of 0
 *
 *	- Thus, the last non-0 remainder, which is 7, is the GCD of 84, and 49.
 *	  Using Euclid's algorithm, replace the stub function written for the previous exercise
 *	  with an actual function that determines and returns the GCD of its two integer parameters.
 *
 */

#include <stdio.h>

int
main()
{
	return 0;
}
