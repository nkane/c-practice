/*
 * Write a C program that asks the user to input two numbers. After your program
 * accepts these numbers using one or more scanf() function calls, have your program
 * check the numbers. If the first number entered is greater than the second number,
 * print the message:
 * - "The first number is greater than the second"
 *
 * else print the message:
 * - "The first number is not greater than the second"
 */

#include <stdio.h>

struct Numbers
{
	float X;
	float Y;
};

inline bool
IsGreaterThan(float, float);

int
main(void)
{
	Numbers N = {};

	printf("Enter in a first number:\n");
	scanf("%f", &N.X);

	printf("Enter in a second number:\n");
	scanf("%f", &N.Y);

	if (IsGreaterThan(N.X, N.Y))
	{
		printf("The first number is greater than the second!\n");
	}
	else
	{
		printf("The first number is not greater than the second!\n");
	}

	return 0;
}

inline bool
IsGreaterThan(float firstNumber, float secondNumber)
{
	return (firstNumber > secondNumber) ? true : false;
}
