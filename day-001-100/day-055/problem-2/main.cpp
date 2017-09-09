/*
 * Write a C program named whole() the returns the integer part of any number passed to the function.
 * (Hint: assign thet passed argument to an integer variable.)
 *
 */

#include <stdio.h>

inline int
Whole(float);

int
main()
{
	float value = 0.0f;
	
	printf("Enter in a float value:\n");
	scanf("%f", &value);

	printf("Whole value: %d\n", Whole(value));

	return 0;
}

inline int
Whole(float value)
{
	return ((int)(value));
}

