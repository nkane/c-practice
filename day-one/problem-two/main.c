/*
 * Write and execute a C program that calculates and display the area of a circle
 * with a radius of 2.57 inches. The relevant formula is circumference = pi * radius^2,
 * where pi is the value 3.1416. Use the variable names radius and circumference in 
 * your program.
 */

#include <stdio.h>

#define PI 3.1416

double CalculateArea(double);
inline double SquareMe(double);

int main(void)
{
	double radius = 2.57;
	double area = 0.0;

	area = CalculateArea(radius);

	printf("%f\n", area);

	return 0;
}

double CalculateArea(double radius)
{
	double result = (PI * (SquareMe(radius)));
	return result;
}


inline double SquareMe(double value)
{
	return (value * value);
}
