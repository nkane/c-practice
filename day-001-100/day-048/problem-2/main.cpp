/*
 * Write a function named squareIt() that computes the square of the value passed
 * to it and displays the result. The function should be capable of squaring numbers
 * with decimal points.
 *
 */

#include <stdio.h>

float 
SquareItF(float);

int
main()
{
	float x = 0.0f;

	printf("Enter a value to square:\n");
	scanf("%f", &x);

	printf("%.2f squared = %.2f\n", x, SquareItF(x));

	return 0;
}


float 
SquareItF(float x)
{
	return (x * x);
}
