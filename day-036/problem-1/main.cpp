/*
 * Write a program that produces a table of numbers 0 through 20 in increments of 2
 * with their squares and cubes.
 *
 */

#include <stdio.h>

#define global_variable static

#define len(array)(sizeof(array)/sizeof(array[0]))

global_variable int Count = 20;

inline float Square(float);

inline float Cube(float);

int
main()
{
	printf("Number\tSquare\tCube\n");

	for (int i = 0; i <= Count; ++i)
	{
		printf("%.2f\t %.2f\t %2.f\n", (float)i, Square((float)i), Cube((float)i));
	}

	return 0;
}

inline float Square(float x)
{
	float result = x * x;
	return result;
}

inline float Cube(float x)
{
	float result = Square(x) * x;
	return result;
}
