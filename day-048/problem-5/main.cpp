/*
 * Modify the previous program to accept the starting value of the table.
 * The number of values to be displayed, and the increment between values.
 *
 * function signature
 * functionName(int start, int end, int incrementBy)
 */

#include <stdio.h>

int
Square(int);

int
Cube(int);

void
DisplayTable(int, int, int);

int
main()
{
	int start = 0, end = 0, incrementBy = 0;

	printf("Enter in a starting value:\n");
	scanf("%d", &start);

	printf("Enter in a ending value:\n");
	scanf("%d", &end);

	printf("Enter in a increment value:\n");
	scanf("%d", &incrementBy);

	DisplayTable(start, end, incrementBy);

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

void
DisplayTable(int start, int end, int increment)
{
	for (int i = start; i <= end; i += increment)
	{
		printf("Value: %d\tSquare: %d\tCube: %d\n", i, Square(i), Cube(i));
	}
}
