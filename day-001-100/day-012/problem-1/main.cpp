/*
 * Write, compile, and execute a C program that calculates and returns
 * the fourth root of the number 81.0, which is 3. (Hint: The fourth root
 * of a number can be obtained by raising the number to the 1/4 or .25 power)
 */

#include <stdio.h>
#include <math.h>

int
main(void)
{
	float number = 81.0f;

	number = pow(number, 0.25f);

	printf("Result: %.2f\n", number);

	return 0;
}
