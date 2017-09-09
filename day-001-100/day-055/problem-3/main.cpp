/*
 * Write a C program named fracpract() that returns the fractional part of any
 * number passed to the function. For example, if thenumber 256.879 is passed to
 * fracpart(), then umber .879 should be returned.
 *
 */

#include <stdio.h>

inline float
FractionalPart(float);

int
main()
{
	float value = 0.0f;

	printf("enter in a float value:\n");
	scanf("%f", &value);

	printf("Fractional Part: %.6f\n", FractionalPart(value));

	return 0;
}

inline float
FractionalPart(float value)
{
	float result = 0.0f;
	result = (value - (int)(value));
	return result;
}
