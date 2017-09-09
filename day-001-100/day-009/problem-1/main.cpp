/*
 * Write a C program to calculate and display the average of the numbers
 * 32.6, 55.2, 67.9, and 48.6.
 */

#include <stdio.h>

inline float
Calculate_Average_F(float total, float numbers);

int
main(void)
{
	float a, b, c, d, average;

	a = 32.6f;
	b = 55.2f;
	c = 67.9f;
	d = 48.6f;

	average = Calculate_Average_F((a + b + c + d), 4);

	printf("Average of numbers: %.3f", average);

	return 0;
}

inline float
Calculate_Average_F(float total, float numbers)
{
	float result = (total / numbers); 
	return result;
}
