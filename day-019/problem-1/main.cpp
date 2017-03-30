/*
 * Write a C program that displays the results of the expression
 * 3.0 * 5.0, 7.1 * 8.3 - 2.2, and 3.2 / (6.1 * 5). Calculate the value
 * of these expressions manually to verify that the displayed values
 * are correct.
 */

#include <stdio.h> 

inline float
FirstEquation(float, float);

inline float
SecondEquation(float, float, float);

inline float 
ThirdEquation(float, float, int);

int
main(void)
{
	float x, y, z, result;
	int a;

	x = 3.0f;
	y = 5.0f;
	result = FirstEquation(x, y);
	printf("Result: %f\n", result);

	x = 7.1f;
	y = 8.3f;
	z = 2.2f;
	result = SecondEquation(x, y, z);
	printf("Result: %f\n", result);
	
	x = 3.2f;
	y = 6.1f;
	a = 5;
	result = ThirdEquation(x, y, a);
	printf("Result: %f\n", result);

	return 0;
}

inline float
FirstEquation(float x, float y)
{
	float result = (x * y);
	return result;
}

inline float
SecondEquation(float x, float y, float z)
{
	float result = (x  * y);
	result -= z;
	return result;
}

inline float 
ThirdEquation(float x, float y, int a)
{
	float result = (x / (y * a));
	return result;
}

