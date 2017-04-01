/*
 * Write, compile, and execute a program that calculates and displays
 * the fourth root of a number entered by a user. Recall from elementary algebra
 * that the fourth root of a number can be found by raising the number to the 1/4
 * power. (Hint: Do not use integer divison, can you see why?)
 */

#include <stdio.h>
#include <math.h>

#define compute_fourth_root(value) (pow(value, 0.25f))

int 
main(void)
{
	float value = 0.0f, result = 0.0f;
	printf("Enter a number:\n");
	scanf("%f", &value);

	result = compute_fourth_root(value);
	printf("Number: %.2f\n", value);
	printf("Fourth Root: %.2f\n", result);

	return 0;
}
