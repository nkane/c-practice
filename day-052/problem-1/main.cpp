/*
 * A useful function with an empty parameter list can be constructed to return a value for pi
 * that is accurate to the maximum number of decimal places allowed by your compute. This value
 * is obtained by taking the arcsine of 1.0 which is pi / 2, and multiplying the result by 2.
 * In C the required expression is 2.0 * asin(1.0), where asin() function is provided in the 
 * standard C mathematics library (make sure to include the math.h header file). Using this expression,
 * write a C function named Pi() that calculates and displays the value of pi.
 *
 */

#include <stdio.h>
#include <math.h>

inline long double
Pi();

int
main()
{
	printf("Pi value: %LF\n", Pi());
	return 0;
}

inline long double
Pi()
{
	long double result = 0.0L;
	result = (2.0L * (long double)asin(1.0L));
	return result;
}
