/*
 * Write a function that produces a table of numbers from 1 to 10, their squares, and
 * cubes.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Start = 1;
global_variable const int End = 10;

int 
Square(int);

int
Cube(int);

int
main()
{
	for (int i = Start; i <= End; ++i)
	{
		printf("Value: %d\tSquare: %d\tCube:%d\n", i, Square(i), Cube(i));
	}

	return 0;
}


int 
Square(int x)
{
	return (x * x);
}

int
Cube(int x)
{
	return (Square(x) * x);
}

