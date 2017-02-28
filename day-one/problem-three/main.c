/*
 * Write and execute a C program that calculates and display that area of
 * a rectangle that has a width of 3.5 inches and a length of 5.48 inches.
 * The relevant formula is area = length * width. Use the variable names
 * length, width, and area in your program.
 * 
 * Additional! 
 * The program must also compute and display the perimeter of the rectangle.
 * The relevant formula is perimeter = 2(length + width).
 */

#include <stdio.h>

float CalculateRectangleArea(float, float);
float CalculateRectanglePerimeter(float, float);

int main(void)
{
	float width = 3.5f;
	float length = 5.48f;
	float rectangleArea = 0.0f;
	float rectanglePerimeter = 0.0f;

	rectangleArea = CalculateRectangleArea(length, width);
	rectanglePerimeter = CalculateRectanglePerimeter(length, width);

	printf("Rectangle Area: %f\n", rectangleArea);
	printf("Rectangle Perimeter: %f\n", rectanglePerimeter);

	return 0;
}

float CalculateRectangleArea(float length, float width)
{
	float result = length * width;
	return result;
}

float CalculateRectanglePerimeter(float length, float width)
{
	float result = (2.0f * (length * width));
	return result;
}
