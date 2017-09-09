/*
 * NOTE(nick): problem one description
 * Write and execute a C program that calculates and displays the circumference of a
 * circle that has a radius 2.57 inches. The relevant formula is circumference = (2 pi) radius,
 * where pi is the value 3.1416. Use the variable names radius and circumference in your
 * program.
 */

#include <stdio.h>

#define PI 3.1416f

float CalculateCircumference(float);

int main(void)
{
	float circleRadius = 2.57f;
	float circumference = 0.0f;

	circumference = CalculateCircumference(circleRadius);

	printf("%f\n", circumference);

	return 0;
}

float CalculateCircumference(float radius)
{
	float result = ((2.0f * PI) * radius);
	return result;
}
