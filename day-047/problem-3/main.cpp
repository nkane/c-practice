/*
 * Write a function named findAbs() that accepts a double-percision number passed in 
 * it, computes its absolute value, and displays the absolute value. The absolute value of
 * a number is the number itself if the number is positive, and the negative of the number
 * if the number is negative.
 *
 */

#include <stdio.h>

inline double
findAbs(double);

int
main()
{
	double x = 0.0;

	printf("Enter in a double value:\n");
	scanf("%lf", &x);

	x = findAbs(x);
	printf("Abs value: %lf\n", x);

	return 0;
}

inline double
findAbs(double x)
{
	if (x < 0)
	{
		x *= -1.0;
	}

	return x;
}
