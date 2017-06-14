/*
 * Write a C function named root4() that returns the fourth root of the argument passed to it.
 * 
 */

#include <stdio.h>
#include <math.h>

inline float
FourthRoot(float);

int
main()
{
	float value = 0.0f;
	printf("Enter in a value:\n");
	scanf("%f", &value);

	printf("Fourth Root: %.2f\n", FourthRoot(value));

	return 0;
}

inline float
FourthRoot(float value)
{
	float result = 0.0f;
	result = sqrt(sqrt(value));
	return result;
}

