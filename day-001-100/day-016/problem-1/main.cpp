/*
 * Write a C program that displays the following prompts:
 * "Enter the miles driven:"
 * "Enter the gallons of gas used:"
 * 
 * After each prompt is displayed, your program should use scanf()
 * function call to accept data from the keyboard for the displayed
 * prompt. After the gallons of gas used has been entered, your program
 * should calculate and display miles per gallon obtained. This value
 * should be included in an appropriate message and calculated using
 * the equation miles per gallon = miles / gallons used.
 */

#include <stdio.h>

struct MPG
{
	float Miles;
	float Gas;
};

inline MPG
CreateMPG();

inline float
ComputeMPGF(MPG *);

inline void
PrettyPrint(MPG *, float);

int
main(void)
{
	MPG M = CreateMPG();
	PrettyPrint(&M, ComputeMPGF(&M));

	return 0;
}


inline MPG
CreateMPG()
{
	float m = 0.0f, g = 0.0f;
	printf("Enter the miles driven:\n");
	scanf("%f", &m);
	printf("Enter the gallons of gas used:\n");
	scanf("%f", &g);

	return MPG
	{
		m,
		g,
	};
}

inline float
ComputeMPGF(MPG *mpg)
{
	float result = (mpg->Miles / mpg->Gas);
	return result;
}

inline void
PrettyPrint(MPG * mpg, float computeMPG)
{
	int x = 0;
	printf("Miles Driven: %.2f\n", mpg->Miles);
	printf("Gas Used: %.2f\n", mpg->Gas);
	printf("Miles Per Gallon: %.2f\n", computeMPG);
	scanf("%d", &x);
}
