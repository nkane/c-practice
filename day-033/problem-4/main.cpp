/*
 * Write a C program to compute the average of 10 numbers requested from the user.
 */

#include <stdio.h>

#define global_variable static

global_variable const int Iterations = 10;

struct UserInput
{
	float X;
	float Sum;
};

inline UserInput
CreateUserInput();

int
main()
{
	UserInput UI = CreateUserInput();

	for (int i = 0; i < Iterations; ++i)
	{
		printf("Enter in a value:\n");
		scanf("%f", &UI.X);
		UI.Sum += UI.X;
	}

	printf("Sum is: %.2f\n", UI.Sum);

	return 0;
}

inline UserInput
CreateUserInput()
{
	UserInput UI = {};
	return UI;
}
