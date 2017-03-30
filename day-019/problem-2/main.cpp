/*
 * Write a C program that displays the reuslts of the expression
 * 15 / 4, 15 % 4, and 5 * 3 - (6 * 4). Calculate the value of these
 * expressions manually to verify that the displayed produced
 * by your program is correct!
 */

#include <stdio.h>

inline int
FirstEquation(int, int);

inline int
SecondEquation(int, int);

inline int
ThirdEquation(int, int, int, int);

int
main(void)
{
	int a, b, c, d, result;

	a = 15;
	b = 4;
	result = FirstEquation(a, b);
	printf("Result: %d\n", result);

	result = SecondEquation(a, b);
	printf("Result: %d\n", result);

	a = 5;
	b = 3;
	c = 6;
	d = 4;
	result = ThirdEquation(a, b, c, d);
	printf("Result: %d\n", result);

	return 0;
}

inline int
FirstEquation(int a, int b)
{
	int result = (a / b);
	return result;
}

inline int
SecondEquation(int a, int b)
{
	int result = (a % b);
	return result;
}

inline int
ThirdEquation(int a, int b, int c, int d)
{
	int result = (a * b - (c * d));
	return result;
}
