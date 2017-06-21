/*
 * A value that is sometimes useful is the greatest common divisor (GCD) of two integers
 * n1 and n2, which is the largest integer that can be evenly divided into the two integers.
 * A famous mathematician, Euclid, discovered an efficienet method to find the GCD of two
 * integers more than 2000 years ago. Right now, however, we'll settle for a stub. Write the
 * integer function stubgcd(n1, n2). Simply have it return a value that suggests it received
 * its parameters correctly. (Hint: n1 + n2 is a good choice of return values. Why isn't
 * n1 / n2 a good choice?).
 *
 */

#include <stdio.h>

int
FindGCD(int, int);

int
main()
{
	int nOne = 0, nTwo = 0;

	printf("Enter in value one:\n");
	scanf("%d", &nOne);

	printf("Enter in value two:\n");
	scanf("%d", &nTwo);

	printf("GDC function Test: %d\n", FindGCD(nOne, nTwo));

	return 0;
}

int
FindGCD(int valueOne, int valueTwo)
{
	int Result = 0;
	Result = (valueOne + valueTwo);
	return (Result);
}

