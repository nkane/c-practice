/*
 * The roads of Kansae are laid out in a rectangular grid at exactly
 * 1-mile intervals. Lonesome farmer Pete drives his 1939 Ford pickup x
 * miles east and y miles north to get to widow Sally's farm. Both x and y
 * are integer numbers. Using this information, write, test, and run a C program
 * that prompts the user for the values of x and y and then uses the formula:
 * distance = sqr(x * x + y * y)
 *
 * to find the shorttest driving distance across the fields to Sally's farm.
 * Since Pete does not understand fractions or decimals very well, the answer
 * must be rounded to the nearest integer value before it is displayed.
 */

#include <stdio.h>
#include <math.h>

struct Vector2
{
	int X;
	int Y;
};

inline Vector2
CreateVector2();

inline int
ComputeShortestDistance(Vector2 *);

int
main(void)
{
	Vector2 V = CreateVector2();
	printf("Shortest Distance: %d\n", (int)round(ComputeShortestDistance(&V)));

	return 0;
}

inline Vector2
CreateVector2()
{
	Vector2 V = {};
	
	printf("Enter in X:\n");
	scanf("%d", &V.X);

	printf("Enter in Y:\n");
	scanf("%d", &V.Y);

	return V;
}

inline int
ComputeShortestDistance(Vector2 *v1)
{
	int result = ((v1->X * v1->X) + (v1->Y * v1->Y));
	result = sqrt(result);
	return result;
}
