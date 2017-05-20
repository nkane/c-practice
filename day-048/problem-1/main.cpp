/*
 * Write a function called mult() that accepts two floating-point numbers as arguments,
 * multiplies these two numbers, and displays the result.
 *
 */

#include <stdio.h>

float
MultF(float ,float);

int
main()
{
	float x = 0.0f, y = 0.0f;

	printf("Enter a first value to multiply:\n");
	scanf("%f", &x);

	printf("Enter a second value to multiply:\n");
	scanf("%f",&y);

	printf("%.2f * %.2f = %.2f\n", x, y, MultF(x, y));

	return 0;
}

float
MultF(float x , float y)
{
	return (x * y);
}
