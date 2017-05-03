/*
 * Create a program that produces a table of numbers from 10 to 1
 * of the square and cubes.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable int EndPoint = 1;

inline float 
Square(float);

inline float
Cube(float);

int
main()
{
	printf("Number\tSquare\tCube\n");

	for (int i = 10; i >= EndPoint; --i)
	{
		printf("%.2f\t %.2f\t %.2f\n", (float)i, Square((float)i), Cube((float)i));
	}

	return 0;
}

inline float 
Square(float x)
{
	float result = x * x;
	return result;
}

inline float
Cube(float x)
{
	float result = Square(x) * x;
	return result;
}
